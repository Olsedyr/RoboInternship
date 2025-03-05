/****************************************************************************
* Copyright (C) 2006 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <sys/times.h>
#include <unistd.h>
#include "Bx.h"
#include "formUploadProg.h"
#include "rs.h"
#include "cmd.h"
#include "stm.h"
#include "modbus_tcp.h"
#include "genscript.h"


//mc.c
extern int RunPath(tmpnPathDef *pathdef);
extern int CancelMc(int v);
float SetVR(int number, float val);
float GetVR(int number);
extern float SetSpeedFactor(float ns);
extern float GetSpeedFactor(void);
extern float GetSpeedFactor(void);
extern float GetArg(void);

extern volatile int trio_sdf;
extern int defpathsamprate;
//TODO move these to tmpnRobot struct
//volatile int ctrlNumOfUploads[MAXLOADGROUP];

extern volatile int trioUpAndRunning;
extern volatile int stmUpAndRunning;
volatile int seqnum=0;

static int ioerrorstm;
static int dummyerror;
int *trioerror=NULL;

clock_t gstart;
static tmpnPathTable pathTable;

tmpnPathHandle *stmpathitemlist[MAXSTMPATHS];
int stmPathItemMaxidx=0;

static int GetNumOfPath(int sfp, int loadgroup)
{
  short *ptr;
  float buffer;
  int val=0;
  if(rs_param.simulateMC==1) return 0;
  ptr = (short*)&buffer;
  trio_read_holding_registers_tcp( 1, 1 + NUM_OF_PATH_INDEX(loadgroup), 2, ptr, 4, sfp );
  val = (int)buffer;
  return val;
}

static int pathdatasize(int numberofaxis, int numofposhints, int numberofsamples)
{
  /* Structure of pathdata uploaded into tablespace in TRIO */

  //numberofaxis
  //maxTime
  //pathtype
  //unused
  //numofsamples
  //numofposhints
  //poshint[0].time
  //...
  //poshint[last].time
  //axisA data first
  //...
  //axisA data last
  //axisB data first
  //...
  //axisB data last
  //axisC data first
  //...
  //axisC data last
  //axisD data first
  //...
  //axisD data last
  //axisE data first
  //...
  //axisE data last
  //axisF data first
  //...
  //axisF data last
  //axisVT data first
  //...
  //axisVT data last
  return 1+5+numofposhints+numberofsamples*numberofaxis;
}

static int GetNewPathIndex(int sfp, int currentnumofpath,int loadgroup)
{
  int numberofaxis,numberofsamples,addresseofaxisdata,numberofposhints;
  float buffer=0.0;
  short *ptr;

  ptr = (short*)&buffer;
    
  if(currentnumofpath==0)
    return FIRST_PATH_INDEX(loadgroup);

  if(rs_param.simulateMC==1) return 0;
  //read addresseofaxisdata
  trio_read_holding_registers_tcp( 1, PATH_INDEX(loadgroup)+currentnumofpath, 2, ptr, 4, sfp );
  usleep(1);
  addresseofaxisdata = (int)buffer;

  //read number of axis
  trio_read_holding_registers_tcp( 1, 1+addresseofaxisdata, 2, ptr, 4, sfp );
  usleep(1);
  numberofaxis = (int)buffer;

  //read numberofposhints
  trio_read_holding_registers_tcp( 1, 1+addresseofaxisdata+5, 2, ptr, 4, sfp );
  usleep(1);
  numberofposhints = (int)buffer;

  //read numberofsamples
  trio_read_holding_registers_tcp( 1, 1+addresseofaxisdata+4, 2, ptr, 4, sfp );
  usleep(1);
  numberofsamples = (int)buffer;
  
/*  printf("***** axisdata=%d pathdatasize(%d,%d,%d)=%d\n"
        ,addresseofaxisdata,numberofaxis,numberofposhints,numberofsamples
        ,pathdatasize(numberofaxis,numberofposhints,numberofsamples));*/
  return addresseofaxisdata + pathdatasize(numberofaxis,numberofposhints,numberofsamples);
}

static int newSetPathTables(int sfp, tmpnPath *pPath, tmpnPathDef *pathdef)
{
  int loadgroup;
  int psize,i, s, index, sidx;
  int numofpath;
  int numSamples;
  float newpathaddr;
  float newnumofpath=0.0;
  float endaddr;
  float xbuffer[60000];
  clock_t start;
  short *pnewnumofpath=(short*)&newnumofpath;
  short *pnewpathaddr=(short*)&newpathaddr;
  short *xptr=(short*)&xbuffer;
    
  loadgroup=pathdef->loadgroup;
  
//  if(ctrlNumOfUploads[loadgroup] >= MAX_PATH_UPLOAD) return -1;
 
 //******************************************
 //* find the new addr for this path        *
 //******************************************
  if(rs_param.mc_task_debug>2) start = times(NULL);
  numofpath = GetNumOfPath(sfp,loadgroup);
  newpathaddr = GetNewPathIndex(sfp, numofpath,loadgroup);
  endaddr=newpathaddr+pathdatasize(NUMBER_OF_AXIS,pathdef->maxpidx,pPath->maxidx);
  if(rs_param.mc_task_debug==3)
    printf("numofpath=%d,newpathaddr=%f,endaddr=%f\n",numofpath,newpathaddr,endaddr);
  //is maximum number of preloaded path's reached
 //is maximum index number reached
  if(numofpath > MAX_PATH_INDEX-1)
  {
    numofpath = 0;
    newpathaddr = FIRST_PATH_INDEX(loadgroup);
  }
  if(endaddr>NUM_OF_PATH_INDEX(loadgroup)+UPLOADGROUP_SIZE-1) 
  {
    newpathaddr = FIRST_PATH_INDEX(loadgroup);
    numofpath = 0;
  }
  index = PATH_INDEX(loadgroup) + numofpath;
  newnumofpath = numofpath+1;
  numSamples = 0;
  /******************************************
  * fill local table with data              *
  ******************************************/
  sidx=0;
  xbuffer[sidx++] = NUMBER_OF_AXIS;      //Number of axis in path a,b,c,d,e,vt
  xbuffer[sidx++] = pathdef->maxTime;    //maxTime
  xbuffer[sidx++] = pathdef->pathtype;   //pathtype
  xbuffer[sidx++] = 0;                   //disp
  xbuffer[sidx++] = pPath->maxidx;       //number of samples in axisdata common for all axis
  xbuffer[sidx++] = pathdef->maxpidx;    //numofposhints
  for(s=0;s<pathdef->maxpidx;s++) xbuffer[sidx++] = pathdef->poshint[s].time;
  for(i=0; i<NUMBER_OF_AXIS; i++)
  {
    if(i<6)
      for(s=0;s<pPath->maxidx;s++) xbuffer[sidx++] = pPath->position[s].actuatorSpace.array[i];
    else
      for(s=0;s<pPath->maxidx;s++) xbuffer[sidx++] = pPath->position[s].t;
  }
  /******************************************
  * send local table to mc                  *
  ******************************************/
  psize=pathdatasize(NUMBER_OF_AXIS,pathdef->maxpidx,pPath->maxidx);
  for(i=0; i<psize; i+=10)
  {
    trio_preset_multiple_registers_tcp( 1,1+newpathaddr+i, 20, &xptr[i*2], sfp);
    usleep(1);
  }
  /******************************************
  * update mc path index                    *
  ******************************************/
  trio_preset_multiple_registers_tcp( 1, 1+NUM_OF_PATH_INDEX(loadgroup), 2, pnewnumofpath, sfp);
  usleep(1);
  trio_preset_multiple_registers_tcp( 1, 1+PATH_INDEX(loadgroup) + numofpath, 2, pnewpathaddr, sfp);
  usleep(1);
  tspace.path_index[numofpath] = newpathaddr;
  tspace.num_of_path_index = newnumofpath;
//  ctrlNumOfUploads[loadgroup]++;
  if(rs_param.mc_task_debug>2) printf("upload %s %f for %d regs float, bane %d i buffer %f loadgroup=%d\n"
  ,pathdef->name
  ,(float)(times(NULL)-start)/(float)sysconf(_SC_CLK_TCK)
  ,psize, index, newpathaddr, loadgroup);
  return index;
}



tmpnPathItem *findPathInTable(tmpnPathTable *pathTable, tmpnPathHandle *ph)
{
  int i;

  //TODO hash
  for(i=0;i<pathTable->maxidx;i++)
  {
		tmpnPathKey *pk=&pathTable->item[i].handle.key;
    if(pk->mode==ph->key.mode
			 &&pk->type==ph->key.type
			 &&pk->from.frame.y==ph->key.from.frame.y
			 &&pk->to.frame.y==ph->key.to.frame.y
			 &&pk->from.frame.x==ph->key.from.frame.x
			 &&pk->from.frame.z==ph->key.from.frame.z
			 &&pk->to.frame.x==ph->key.to.frame.x
			 &&pk->to.frame.z==ph->key.to.frame.z
			 &&pk->from.frame.v==ph->key.from.frame.v
			 &&pk->from.frame.w==ph->key.from.frame.w
			 &&pk->to.frame.v==ph->key.to.frame.v
			 &&pk->to.frame.w==ph->key.to.frame.w
			 //&&strcmp(pk->from.frame.name,ph->key.from.frame.name)==0
			 //&&strcmp(pk->to.frame.name,ph->key.to.frame.name)==0
			 )
    { 
      return &pathTable->item[i];
    } 
  }
  return NULL;
}

tmpnPathItem *addPathToTable(tmpnPathTable *pathTable, tmpnPathHandle *ph)
{
  tmpnPathItem *pathtableitem;
	if (pathTable->newidx<0||pathTable->newidx>=MAXPATHTABLEITEMS)
		pathTable->newidx=0;
	int tempidx=pathTable->newidx;
	int startidx=pathTable->newidx;
	while(pathTable->item[tempidx].handle.state != ST_IDLE && pathTable->item[tempidx].handle.state != ST_FINISHED)
	{
		tempidx++;
		if(tempidx>=MAXPATHTABLEITEMS)
		{
			tempidx=0;
		}
		if (tempidx == startidx)
		{
			printf("addPathTable(): No more paths in state ST_IDLE or ST_FINISHED");
			mpnexit(1);
		}
	}
	pathTable->newidx=tempidx;
  pathtableitem=&pathTable->item[pathTable->newidx++];
  memcpy(&pathtableitem->handle,ph,sizeof(*ph));
  pathtableitem->bopted=0;
  pathtableitem->path=ph;
  if(pathTable->newidx<=MAXPATHTABLEITEMS&&pathTable->newidx>pathTable->maxidx) 
		pathTable->maxidx=pathTable->newidx;
  return pathtableitem;
}

void makePathItemList(tmpnStateMachines *statemachines)
{
  int m,i;
  for(m=0;m<statemachines->maxidx;m++)
  {
    tmpnStateMachine *stm=&statemachines->statemachine[m];
    for(i=0;i<stm->numvalue;i++)
    {
      if (stm->value[i].type==PATHHANDLE)
      {
				stmpathitemlist[stmPathItemMaxidx++] = stm->value[i].path;
      }
    }
  }
}

tmpnPathHandle *findPathItemInStatemachine(tmpnStateMachines *statemachines, int state)
{
  int i;
  for(i=0;i<stmPathItemMaxidx;i++)
  {
		if(stmpathitemlist[i]->state==state)
		{
			return stmpathitemlist[i];
		}
  }
  return NULL;
}

int ResetPathHandleInStatemachine(tmpnStateMachines *statemachines)
{
  int m,i,j=0;
  
  for(m=0;m<statemachines->maxidx;m++)
  {
    tmpnStateMachine *stm=&statemachines->statemachine[m];
    for(i=0;i<stm->numvalue;i++)
    {
      if(stm->value[i].type==PATHHANDLE)
      {
        j++;
        stm->value[i].path->state=ST_IDLE;
      }
    }
  }
  return j;
}

static void ResetLoadBuffer(tmpnPathTable *pathTable)
{
  int i;
  short *ptr;
  float buffer = 0.0;

  for(i=0;i<MAXPATHTABLEITEMS;i++)
  {
    pathTable->item[i].pathdef.idx=-1;
    pathTable->item[i].handle.state = ST_IDLE; 
  }
  ptr = (short*)&buffer;
  for(i=0;i<MAXLOADGROUP;i++)
  {
    if(rs_param.simulateMC==1) 
    {
      usleep(1);
    }
    else
    {
      usleep(1);
      trio_preset_multiple_registers_tcp( 1, 1+NUM_OF_PATH_INDEX(i), 2, ptr, trio_sdf);
    }
  }
}

static void ResetBoptBuffer(tmpnPathTable *pathTable)
{
  int i;
  pathTable->newidx=MAXPATHTABLEITEMS;
  pathTable->maxidx=0;
  for(i=0;i<MAXPATHTABLEITEMS;i++)
  {
    pathTable->item[i].bopted = 0; 
    pathTable->item[i].path=NULL;
  }
  ResetLoadBuffer(pathTable);
}

static void FinishOldPaths(tmpnPathTable *pathTable, int sectors, int seqnum)
{
	int i;
	static int section=0;
	if (section >= sectors) section = 0;
	int interval = MAXPATHTABLEITEMS / sectors;
	int seci = section*interval;
	int secip1 = (section+1)*interval;
	for(i=seci;i<secip1;i++)
  {
		tmpnPathItem *pi = &pathTable->item[i];
		if ((pi->handle.state == ST_LOADED)&&(pi->pathdef.seqnum<seqnum-MAX_PATH_AGE))
		{
			pi->handle.state = ST_FINISHED;
		}
	}
	section++;
}

void *loaderTask(void * argument )
{
	int expandret=FALSE;
  int pnum=0;
  tmpnPathHandle *pathhandle; 
  tmpnPathItem *pathtableitem; 
  volatile int *resetpreload=NULL;  
  volatile int *ticksSensorTest0=NULL;  //vr250 50000.00
  volatile int *ticksSensorTest1=NULL;  //vr251 100000.00
  volatile int *ticksSensorTest2=NULL;  //vr252 300000.00
  volatile int *crashDetect=NULL;       //vr296 1.00
  volatile int *doubleCaseTest=NULL;    //vr297 0.00
  volatile int *toolUsePressostat=NULL; //vr298 3.00
  volatile int *toolSensorSelect=NULL;  //vr299 1.00

	while(!trioUpAndRunning&&!stmUpAndRunning) usleep(100000);
  printf("loaderTask\n");
	int toolstm = getMachineIdx("Tool");

	resetpreload = getMachineValuePtr(getMachineIdx("Loader"),"resetpreload");
	ticksSensorTest0  = getMachineValuePtr(toolstm,"ticksSensorTest0");
	ticksSensorTest1  = getMachineValuePtr(toolstm,"ticksSensorTest1");
	ticksSensorTest2  = getMachineValuePtr(toolstm,"ticksSensorTest2");
	crashDetect       = getMachineValuePtr(toolstm,"crashDetect");
	doubleCaseTest    = getMachineValuePtr(toolstm,"doubleCaseTest");
	toolUsePressostat = getMachineValuePtr(toolstm,"toolUsePressostat");
	toolSensorSelect  = getMachineValuePtr(toolstm,"toolSensorSelect");
	
	ResetBoptBuffer(&pathTable);
	for(;;)
	{		
		if(*resetpreload==2)
		{
			if(rs_param.mc_task_debug==3) printf("loader *resetpreload==2\n");
			ResetPathHandleInStatemachine((tmpnStateMachines*)&tworkcell->statemachines);
			CancelMc(1);
			SetVR(250,*ticksSensorTest0);
			SetVR(251,*ticksSensorTest1);
			SetVR(252,*ticksSensorTest2);
			SetVR(296,*crashDetect);
			SetVR(297,*doubleCaseTest);
			SetVR(298,*toolUsePressostat);
			SetVR(299,*toolSensorSelect);
			SetSpeedFactor(GetSpeedFactor());
      if(rs_param.workcellid==319
       ||rs_param.workcellid==320
       ||rs_param.workcellid==321)
      {
        SetSpeed(axis_a, 100.0);
		  	SetAccel(axis_a, 50.0);
			  SetDecel(axis_a, 50.0);
      }
			else
      {
        SetSpeed(axis_a, 200.0);
		  	SetAccel(axis_a, 400.0);
			  SetDecel(axis_a, 400.0);
			}
      *resetpreload=3;
      if(rs_param.mc_task_debug==3) printf("loader *resetpreload=3\n");
    }
    if(*resetpreload==0)
    {
      pathhandle = findPathItemInStatemachine((tmpnStateMachines*)&tworkcell->statemachines,ST_LOAD);
      if(pathhandle!=NULL)
      {
        if(rs_param.mc_task_debug==3) printf("loader *resetpreload=0\n");
        pathtableitem = findPathInTable(&pathTable,pathhandle);
        if(pathtableitem==NULL)
        {
          pathtableitem=addPathToTable(&pathTable,pathhandle);
          if(rs_param.mc_task_debug==3) printf("loader add path to table\n");
        }
        pathtableitem->path->state=ST_BOPTING;
        pathtableitem->handle.state=ST_BOPTING;
        if(pathtableitem->bopted==0)
        {
//          if(pathtableitem->pathdef.runbopt) 
          if(strcmp(pathtableitem->handle.script,"")==0)
          {
            //304 send parameter til expand via PScounter
            //printf("expandBoptLoader\n");
            expandret = expandBoptLoader((tmpnRobot*)trobot,pathtableitem); 
  	        pathtableitem->pathdef.samplesBetweenKeypoints=defpathsamprate;
            pathtableitem->bopted=1;
          }
          else 
          {
            pathtableitem->handle.firstpoint = LoadCommandScript(pathtableitem->handle.script,0);
            printf("refreshPath\n");
  	        refreshPath(pathtableitem->handle.firstpoint);
						expandret = TRUE;
          }
        }
				if (expandret==FALSE)
				{
					printf("expandBoptLoader failed  Possible cause: Couldn't find boptitem mode=%d type=%d!\n",pathtableitem->handle.key.mode,pathtableitem->handle.key.type);
          mpnexit(1);
				}
        generatePath((tmpnRobot*)trobot, &pathtableitem->pathdef, (tmpnPath*)&pathTable.pathdata);
        if(rs_param.simulateMC==0)
        {
          pnum = newSetPathTables(trio_sdf, (tmpnPath*)&pathTable.pathdata,&pathtableitem->pathdef);
        }
        else
        {
          pnum++;
          usleep(200000);
        }
        if(pnum >= 0) //upload completed without errors
        {
          pathtableitem->pathdef.idx = pnum;
          pathtableitem->pathdef.seqnum = seqnum++;
          pathtableitem->path->state=ST_LOADED;
          pathtableitem->handle.state=ST_LOADED;
          if(rs_param.mc_task_debug==3) printf("loader: path loaded, seqnum=%d\n",seqnum);
        }
        else
        {
          pathtableitem->path->state=ST_ERROR;
          pathtableitem->handle.state=ST_ERROR;
          printf("sequence error in loader. Fatal error in statemachine code!\n");
          mpnexit(1);
        }
      }
      else
      {
        usleep(100000);
      }
    }
    else
    {
      usleep(100000);
    }
  }

  close( trio_sdf );

  return NULL;
}
/***************************************************************************/
/* executerTask                                                            */
/***************************************************************************/
void *executerTask(void * argument )
{
  tmpnPathHandle *pathhandle; 
  tmpnPathItem *pathtableitem; 
	volatile int *resetpreload = NULL;
  volatile int *roboError=NULL;
  volatile int *roboMessage=NULL;
  volatile int *delaystop=NULL;
  volatile int *moving=NULL;
  char s[256];
	while(!trioUpAndRunning&&!stmUpAndRunning) usleep(100000);
	
	int robotstm=-1;
	int roboerrorstm=-1;
	int wstm = -1;
	int statew_running = -1;
	int statew_pausing = -1;

	robotstm = getMachineIdx("Robot");
	roboerrorstm = getMachineIdx("RoboError");
	wstm = getMachineIdx("WorkCell");
	statew_running = getStateIdx(wstm, "ST_RUNNING");
	statew_pausing = getStateIdx(wstm, "ST_PAUSING");

	resetpreload = getMachineValuePtr(getMachineIdx("Loader"),"resetpreload");
	roboError = getMachineValuePtr(roboerrorstm,"roboError");
	roboMessage = getMachineValuePtr(roboerrorstm,"roboMessage");
	delaystop = getMachineValuePtr(robotstm,"delaystop");
	moving = getMachineValuePtr(robotstm,"moving");

  printf("executerTask\n");
  for(;;)
  {
    if(*resetpreload==1)
    {
      if(rs_param.mc_task_debug==3) printf("executer *resetpreload==1\n");
      *resetpreload=2;
      if(rs_param.mc_task_debug==3) printf("executer *resetpreload=2\n");
    }
    if(*resetpreload==0&&*roboError==0&&((testState(wstm,statew_pausing)&&*delaystop==1)||testState(wstm,statew_running)))
    {
      pathhandle = findPathItemInStatemachine((tmpnStateMachines*)&tworkcell->statemachines,ST_EXEC);
      if(pathhandle!=NULL)
      {
        if(rs_param.mc_task_debug==3) printf("executer *resetpreload=0\n");
        pathtableitem = findPathInTable(&pathTable,pathhandle);
        if(pathtableitem==NULL)
        {
          //error
          if(rs_param.mc_task_debug==3) printf("executer path not found\n");
          pathhandle->state=ST_ERROR;
          //TODO new roboError = xx to indicate upload failure
          sprintf(s,"sequence error in executer(a). Fatal error in statemachine code!");
          printf("%s\n",s);
          logMsg(s);
          mpnexit(1);
        }
        else
        {
          if(rs_param.mc_task_debug==3) printf("pathtableitem->pathdef.seqnum=%d %d\n",pathtableitem->pathdef.seqnum,seqnum);
          pathtableitem->path->state=ST_EXECUTING;
          pathtableitem->handle.state=ST_EXECUTING;
//          if(rs_param.simulateMC==0)
          {
            if(seqnum-pathtableitem->pathdef.seqnum>MAX_PATH_AGE)
            {
              pathtableitem->path->state=ST_ERROR;
              pathtableitem->handle.state=ST_ERROR;
              //TODO new roboError = xx to indicate upload failure
              sprintf(s,"sequence error in executer(b). Fatal error in statemachine code!");
              printf("%s\n",s);
              logMsg(s);
              mpnexit(1);
            }
            else
            { 
              if(rs_param.mc_task_debug==3) printf("executer path running\n");
              *moving=1;
              if(rs_param.simulateMC==0)
              {
                *roboError = RunPath(&pathtableitem->pathdef);
                if(rs_param.workcellid!=310)
                  *roboMessage = GetArg();  
              }
              else
              { 
                *roboError = 0;
                *roboMessage = 0;  
              }
              *moving=0;
							// In a tenth of pathtable: 
							//Set LOADED paths with seqnum < current - MAX_PATH_AGE -> ST_FINISHED
							FinishOldPaths(&pathTable, 10, seqnum);
            }
            if(*roboError==0)
            {
              pathtableitem->path->state=ST_FINISHED;
              pathtableitem->handle.state=ST_FINISHED;
            }
            else
            {
              pathtableitem->path->state=ST_ERROR;
              pathtableitem->handle.state=ST_ERROR;
            }
          }
          //else
          //{
          //  //TODO sleep 
          //  pathtableitem->path->state=ST_FINISHED;
          //  pathtableitem->handle.state=ST_FINISHED;
          //}
          if(*roboError==0&&*delaystop!=1&&testState(wstm,statew_pausing))
          {
            *roboError=15; 
          }
        }
      }
      else
      {
        //TODO signal from STM to shorten responsetime
        usleep(100000);
      }
    }
    else
    {
      //TODO signal from STM to shorten responsetime
      usleep(100000);
    }
  }
  close( trio_sdf );

  return NULL;
}
/***************************************************************************/
/* InitializeLoader                                                        */
/***************************************************************************/
void InitializeLoader(void)
{
  short *ptr, i,j;
  float buffer = 0.0;

  
  gstart = times(NULL);
  
  if(rs_param.simulateMC!=1)
  {
		ioerrorstm = getMachineIdx("IOError");
		if (ioerrorstm!=-1)
		{
			trioerror = getMachineValuePtr(ioerrorstm,"trioerror");
			if (trioerror==NULL)
				trioerror=&dummyerror;
		}
		j=0;
    while((trio_sdf = set_up_tcp( rs_param.mcIPaddr )) < 0)
    {
      if(j++>10)
      {
        printf("Cannot connect to controller at %s!\n",rs_param.mcIPaddr);
        printf("Defaulting to simulation mode!\n");
        rs_param.simulateMC = 1;
        *trioerror=1;
        return;
      }
      else
        usleep(1000000); //WAIT UNTIL TRIO-CONTROLLER HAS STARTED
    }
  }
  pathTable.maxidx=0;
  
  pathTable.pathdata.maxidx=0;
  ptr = (short*)&buffer;
  if(rs_param.simulateMC!=1)
  {
		usleep(3000000);
    //
    ptr = (short*)&buffer;

//    buffer=12345678;
//    trio_preset_multiple_registers_tcp( 1, 32000, 2, ptr, trio_sdf);
//    buffer=9876.5432;
//    trio_preset_multiple_registers_tcp( 1, 64000, 2, ptr, trio_sdf);
//		usleep(2000000000);
    for(i=0;i<MAXLOADGROUP;i++)
    {
      buffer=0;
			trio_preset_multiple_registers_tcp( 1, 1+NUM_OF_PATH_INDEX(i), 2, ptr, trio_sdf);
    }
  }
  makePathItemList((tmpnStateMachines*)&tworkcell->statemachines);
  trioUpAndRunning++;
}

