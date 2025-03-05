/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/

//TODO lib has to updatecmdPoints when it is needed(not user)
//TODO let dynamic model calculate best maxTime or learn from experience
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/times.h>
#include <unistd.h>
#include <ctype.h>
#include "cmd.h"
#include "logger.h"

tmpnRSSystem rs_param=
{
	"plantname"
  ,"workcellname"
	,"location"
  ,"robotname"
  ,"192.168.0.150" //pcIPaddr
  ,"192.168.0.250" //mcIPaddr
  ,"eth0"          //useNic
  ,"scriptname"    //script
  ,305             //workcellid
  ,0               //lag
  ,{
   0							 //initialized
  ,0							 //offx
  ,0							 //offy
  ,0							 //calx
  ,0							 //caly
  ,0               //ctlrtype
  ,"/dev/ttyS0"    //port
  }
  ,""              //scriptname 
  ,0               //simulateMC
  ,0               //mc_task_debug
  ,0               //path_debug
  ,0               //statemachine_debug
	,0               //io_debug
  ,10              //startSpeed
  ,""              //user
  ,""              //password
  ,0               //checkWeigher
  ,1               //roboStacker
  ,"formStdRun"    //mainDialog
  ,1               //scriptExec
  ,0               //new_trio_addr
  ,1299            //stmServerPort
  ,1               //stmServerPort
};

//mc.c 
extern int getFotoFriMM(void);
int demo=0;

char rs_systempath[256]="";
char rs_systemini[256]="";
static char databasePath[256];
long defpathspeed = 100000;
int defpathsamprate = 10;


TABLESPACE tspace=
{
  {{{0,0,0,0,0,0,1,30000,100000000,100000000,1,10,1},{},{},{}}}
}; //TODO init , not static any more
volatile int roboState = ROBOSTATE_WDOGOFF;
float speedFactor = 0.5;

tmpnJoints m_actuator;
pthread_mutex_t actuator_mutex = PTHREAD_MUTEX_INITIALIZER;
volatile int jogikscreen=0;
volatile unsigned int mposupdatecount=0;

pthread_cond_t script_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t script_mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t upload_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t upload_mtx = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t uploaddone_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t uploaddone_mtx = PTHREAD_MUTEX_INITIALIZER;

int getMachineStateIdx(const char *machinename, const char *statename);
int getMachineTypeIdx(const char *name);

static POINTSTRUCT pdummy = {{0.0,0.0,0.0,0.0,0.0}
                            ,{0.0,0.0,0.0,0.0,0.0}
                            ,{0.0,0.0,0.0,0.0,0.0},0,NULL};
//TRIO motion controller macro's
tmpnMacro mpnmacro[]={	
	{"testpallet",TESTPALLET}
	,{"getpallet",GETPALLET}
	,{"savenextpath",SAVENEXTPATH}
	,{"runsavedpath",RUNSAVEDPATH}
	,{"clearsavedpath",CLEARSAVEDPATH}
	,{"setio",SETIO}
	,{"getio",GETIO}
};

tmpnVector *bagendpoint=NULL;
//atic COMMANDSTRUCT *firstcmd=NULL;
//atic COMMANDSTRUCT *ptrcmd=NULL;


static void freeCommandData(COMMANDSTRUCT *dcmd)
{
  switch(dcmd->type)
  {
    case ELSE: free((ELSESTRUCT*)dcmd->data); break;
    case SADS: free((SADSSTRUCT*)dcmd->data); break;
    case MOVEABS: free((MOVEABSSTRUCT*)dcmd->data); break;
    case GOTO: free((GOTOSTRUCT*)dcmd->data); break;
    case PPSCRIPT: free((PPSCRIPTSTRUCT*)dcmd->data); break;
    case WSP: free((WSPSTRUCT*)dcmd->data); break;
    case OUT: free((OUTPUTSTRUCT*)dcmd->data); break;
    case IN: free((INPUTSTRUCT*)dcmd->data); break;
    case ENDSUB: free((NAMESTRUCT*)dcmd->data); break;
    case MOVEAXIS: free((MOVEAXISSTRUCT*)dcmd->data); break;
    case CANCELAXIS: free((CANCELAXISSTRUCT*)dcmd->data); break;

    case SPLINEHINT: free((SPLINEHINTSTRUCT*)dcmd->data); break;
    case STATEHINT: free((STATEHINTSTRUCT*)dcmd->data); break;
    case POSITIONHINT: free((POSITIONHINTSTRUCT*)dcmd->data); break;
    case PATH:
			//free(((PATHSTRUCT*)dcmd->data)->tpathdef.hpoint);
			//free(((PATHSTRUCT*)dcmd->data)->tpathdef.keypoint);
			//free(((PATHSTRUCT*)dcmd->data)->tpathdef.poshint);
         free((PATHSTRUCT*)dcmd->data);
        break;
    case STARTSUB: free((NAMESTRUCT*)dcmd->data); break;
    case MACRO: free((MACROSTRUCT*)dcmd->data); break;
    case CALL: free((CALLSTRUCT*)dcmd->data); break;
    case RESETPRELOAD: free((RESETPRELOADSTRUCT*)dcmd->data); break;
    case LABEL: free((LABELSTRUCT*)dcmd->data); break;
    case JUMPLAYER: free((JUMPLAYERSTRUCT*)dcmd->data); break;
    case SCOPE: free((SCOPESTRUCT*)dcmd->data); break;
    case POINT: free((POINTSTRUCT*)dcmd->data); break;
    case RPOINT: free((POINTSTRUCT*)dcmd->data); break;
    case EPOINT: free((POINTSTRUCT*)dcmd->data); break;
    case HPOINT: free((POINTSTRUCT*)dcmd->data); break;
    case HRPOINT: free((POINTSTRUCT*)dcmd->data); break;
    case SLEEP: free((SLEEPSTRUCT*)dcmd->data); break;
    case WAITEVENT: free((EVENTSTRUCT*)dcmd->data); break;
    case TESTEVENT: free((EVENTSTRUCT*)dcmd->data); break;
    case SIGNALEVENT: free((EVENTSTRUCT*)dcmd->data); break;
    case COUNTER: free((COUNTERSTRUCT*)dcmd->data); break;
    case TUNING: free((TUNINGSTRUCT*)dcmd->data); break;
    case SETSPEED: free((SETSPEEDSTRUCT*)dcmd->data); break;
    case STOP: free((NAMESTRUCT*)dcmd->data); break;
    case ERROR: free((ERRORSTRUCT*)dcmd->data); break;
    case TEST: free((TESTSTRUCT*)dcmd->data); break;
    case OR: free((TESTSTRUCT*)dcmd->data); break;
    case AND: free((TESTSTRUCT*)dcmd->data); break;
	  case ELSETEST: free((TESTSTRUCT*)dcmd->data); break;
    case SET: free((SETSTRUCT*)dcmd->data); break;
    case SETSTATE: free((SETSTATESTRUCT*)dcmd->data); break;
    case TIMEOUT: free((TIMEOUTSTRUCT*)dcmd->data); break;
    case SUBT: free((SUBTSTRUCT*)dcmd->data); break;
    case ADD: free((ADDSTRUCT*)dcmd->data); break;
    case MUL: free((MULSTRUCT*)dcmd->data); break;
    case DIV: free((DIVSTRUCT*)dcmd->data); break;
    case CALC: free((CALCSTRUCT*)dcmd->data); break;
    case LOAD: free((LOADSTRUCT*)dcmd->data); break;
    case EXEC: free((EXECSTRUCT*)dcmd->data); break;
	  case SETFRAME: free((SETFRAMESTRUCT*)dcmd->data); break;
	  case SETITEM: free((SETITEMSTRUCT*)dcmd->data); break;
	  case ROBOTSPEED: free((ROBOTSPEEDSTRUCT*)dcmd->data); break;
  }
}

static COMMANDSTRUCT *__localAddCommand(int type)
{
  COMMANDSTRUCT *cmd=NULL;
  ROOTSTRUCT *root=NULL;
  ELSESTRUCT *elses=NULL;
  SPLINEHINTSTRUCT *splinehint=NULL;
  MOVEAXISSTRUCT *moveaxis=NULL;
  CANCELAXISSTRUCT *cancelaxis=NULL;
  STATEHINTSTRUCT *statehint=NULL;
  POSITIONHINTSTRUCT *positionhint=NULL;
  SADSSTRUCT *dps=NULL;
  MOVEABSSTRUCT *mas=NULL;
  PATHSTRUCT *path=NULL;
  WSPSTRUCT *wsp=NULL;
  OUTPUTSTRUCT *out=NULL;
  INPUTSTRUCT *in=NULL;
  POINTSTRUCT *point=NULL;
  NAMESTRUCT *sub=NULL;
  MACROSTRUCT *macro=NULL;
  CALLSTRUCT *call=NULL;
  RESETPRELOADSTRUCT *resetpreload=NULL;
  LABELSTRUCT *label=NULL;
  JUMPLAYERSTRUCT *jumplayer=NULL;
  EVENTSTRUCT *event=NULL;
  SLEEPSTRUCT *sleep=NULL;
  COUNTERSTRUCT *counter=NULL;
  TUNINGSTRUCT *tuning=NULL;
  SETSPEEDSTRUCT *setspeed=NULL;
  SCOPESTRUCT *scope=NULL;
  GOTOSTRUCT *go=NULL;
  PPSCRIPTSTRUCT *ppscript=NULL;
  TESTSTRUCT *test=NULL;
	SETSTRUCT *set=NULL;
  SETSTATESTRUCT *setstate=NULL;
  TIMEOUTSTRUCT *timeout=NULL;
  SUBTSTRUCT *subt=NULL;
  ADDSTRUCT *add=NULL;
  MULSTRUCT *mul=NULL;
  CALCSTRUCT *calg=NULL;
  DIVSTRUCT *div=NULL;
  ERRORSTRUCT *error=NULL;
  LOADSTRUCT *load=NULL;
  EXECSTRUCT *exec=NULL;
  SETFRAMESTRUCT *setframe=NULL;
	SETITEMSTRUCT *setitem=NULL;
	ROBOTSPEEDSTRUCT *robotspeed=NULL;
 

  cmd = (COMMANDSTRUCT*)malloc(sizeof(COMMANDSTRUCT));
  if(cmd==NULL)
    return NULL;

  cmd->type = type;
  cmd->next = NULL;
  cmd->prev = NULL;
  cmd->flag = 0;
  cmd->listitem = NULL;
  cmd->include = 0;

  switch(type)
  {
    case ROOT:
      root = (ROOTSTRUCT*)malloc(sizeof(ROOTSTRUCT));
      if(root==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)root;
      break;
    case ELSE:
      elses = (ELSESTRUCT*)malloc(sizeof(ELSESTRUCT));
      if(elses==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)elses;
      break;
    case SADS:
      dps = (SADSSTRUCT*)malloc(sizeof(SADSSTRUCT));
      if(dps==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)dps;
      break;
    case SPLINEHINT:
      splinehint = (SPLINEHINTSTRUCT*)malloc(sizeof(SPLINEHINTSTRUCT));
      if(splinehint==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)splinehint;
      break;
    case MOVEAXIS:
      moveaxis = (MOVEAXISSTRUCT*)malloc(sizeof(MOVEAXISSTRUCT));
      if(moveaxis==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)moveaxis;
      break;
    case CANCELAXIS:
      cancelaxis = (CANCELAXISSTRUCT*)malloc(sizeof(CANCELAXISSTRUCT));
      if(cancelaxis==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)cancelaxis;
      break;
    case STATEHINT:
      statehint = (STATEHINTSTRUCT*)malloc(sizeof(STATEHINTSTRUCT));
      if(statehint==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)statehint;
      break;
    case POSITIONHINT:
      positionhint = (POSITIONHINTSTRUCT*)malloc(sizeof(POSITIONHINTSTRUCT));
      if(positionhint==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)positionhint;
      break;
    case MOVEABS:
      mas = (MOVEABSSTRUCT*)malloc(sizeof(MOVEABSSTRUCT));
      if(mas==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)mas;
      break;
    case PATH:
      path = (PATHSTRUCT*)malloc(sizeof(PATHSTRUCT));
      if(path==NULL)
      {
        free (cmd);
        return NULL;
      }
      path->tpathdef.maxidx=0;
      path->tpathdef.maxhidx=0;
      path->tpathdef.maxpidx=0;
      path->tpathdef.id = 0;
      path->tpathdef.idx = -1;
      path->firstpoint=cmd;
      cmd->data = (void*)path;
      break;
    case MACRO:
      macro = (MACROSTRUCT*)malloc(sizeof(MACROSTRUCT));
      if(macro==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(macro, 0, sizeof(MACROSTRUCT));
      cmd->data = (void*)macro;
      break;
    case RESETPRELOAD:
      resetpreload = (RESETPRELOADSTRUCT*)malloc(sizeof(RESETPRELOADSTRUCT));
      if(resetpreload==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(resetpreload, 0, sizeof(RESETPRELOADSTRUCT));
      cmd->data = (void*)resetpreload;
      break;
    case CALL:
      call = (CALLSTRUCT*)malloc(sizeof(CALLSTRUCT));
      if(call==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(call, 0, sizeof(CALLSTRUCT));
      cmd->data = (void*)call;
      break;
    case LABEL:
      label = (LABELSTRUCT*)malloc(sizeof(LABELSTRUCT));
      if(label==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(label, 0, sizeof(LABELSTRUCT));
      cmd->data = (void*)label;
      break;
    case JUMPLAYER:
      jumplayer = (JUMPLAYERSTRUCT*)malloc(sizeof(JUMPLAYERSTRUCT));
      if(jumplayer==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(jumplayer, 0, sizeof(JUMPLAYERSTRUCT));
      cmd->data = (void*)jumplayer;
      break;
    case SCOPE:
      scope = (SCOPESTRUCT*)malloc(sizeof(SCOPESTRUCT));
      if(scope==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(scope, 0, sizeof(SCOPESTRUCT));
      cmd->data = (void*)scope;
      break;
    case GOTO:
      go = (GOTOSTRUCT*)malloc(sizeof(GOTOSTRUCT));
      if(go==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(go, 0, sizeof(GOTOSTRUCT));
      cmd->data = (void*)go;
      break;
    case PPSCRIPT:
      ppscript = (PPSCRIPTSTRUCT*)malloc(sizeof(PPSCRIPTSTRUCT));
      if(ppscript==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(ppscript, 0, sizeof(PPSCRIPTSTRUCT));
      cmd->data = (void*)ppscript;
      break;
    case WSP:
      wsp = (WSPSTRUCT*)malloc(sizeof(WSPSTRUCT));
      if(wsp==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)wsp;
      break;
    case OUT:
      out = (OUTPUTSTRUCT*)malloc(sizeof(OUTPUTSTRUCT));
      if(out==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)out;
      break;
    case IN:
      in = (INPUTSTRUCT*)malloc(sizeof(INPUTSTRUCT));
      if(in==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)in;
      break;
    case STARTSUB:
      sub = (NAMESTRUCT*)malloc(sizeof(NAMESTRUCT));
      if(sub==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)sub;
      break;
    case ENDSUB:
      sub = (NAMESTRUCT*)malloc(sizeof(NAMESTRUCT));
      if(sub==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)sub;
      break;
    case POINT:
    case RPOINT:
    case EPOINT:
    case HPOINT:
    case HRPOINT:
      point = (POINTSTRUCT*)malloc(sizeof(POINTSTRUCT));
      if(point==NULL)
      {
        free (cmd);
        return NULL;
      }
      memset(point, 0, sizeof(POINTSTRUCT));
      cmd->data = (void*)point;
      break;
    case TESTEVENT:
      event = (EVENTSTRUCT*)malloc(sizeof(EVENTSTRUCT));
      if(event==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)event;
      break;
    case SLEEP:
      sleep = (SLEEPSTRUCT*)malloc(sizeof(SLEEPSTRUCT));
      if(sleep==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)sleep;
      break;
    case WAITEVENT:
      event = (EVENTSTRUCT*)malloc(sizeof(EVENTSTRUCT));
      if(event==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)event;
      break;
    case COUNTER:
      counter = (COUNTERSTRUCT*)malloc(sizeof(COUNTERSTRUCT));
      if(counter==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)counter;
      break;
    case TUNING:
      tuning = (TUNINGSTRUCT*)malloc(sizeof(TUNINGSTRUCT));
      if(tuning==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)tuning;
      break;
    case SETSPEED:
      setspeed = (SETSPEEDSTRUCT*)malloc(sizeof(SETSPEEDSTRUCT));
      if(setspeed==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)setspeed;
      break;
    case SIGNALEVENT:
      event = (EVENTSTRUCT*)malloc(sizeof(EVENTSTRUCT));
      if(event==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)event;
      break;
    case STOP:
      sub = (NAMESTRUCT*)malloc(sizeof(NAMESTRUCT));
      if(sub==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)sub;
      break;
    case ERROR:
      error = (ERRORSTRUCT*)malloc(sizeof(ERRORSTRUCT));
      if(error==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)error;
      break;
    case SETFRAME:
      setframe = (SETFRAMESTRUCT*)malloc(sizeof(SETFRAMESTRUCT));
      if(setframe==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)setframe;
      break;
	  case SETITEM:
      setitem = (SETITEMSTRUCT*)malloc(sizeof(SETITEMSTRUCT));
      if(setitem==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)setitem;
      break;
	  case ROBOTSPEED:
      robotspeed = (ROBOTSPEEDSTRUCT*)malloc(sizeof(ROBOTSPEEDSTRUCT));
      if(robotspeed==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)robotspeed;
      break;
    case EXEC:
      exec = (EXECSTRUCT*)malloc(sizeof(LOADSTRUCT));
      if(exec==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)exec;
      break;
    case LOAD:
      load = (LOADSTRUCT*)malloc(sizeof(LOADSTRUCT));
      if(load==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)load;
      break;
    case TEST:
	  case ELSETEST:
    case OR:
    case AND:
      test = (TESTSTRUCT*)malloc(sizeof(TESTSTRUCT));
      if(test==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)test;
      break;
    case SET:
      set = (SETSTRUCT*)malloc(sizeof(SETSTRUCT));
      if(set==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)set;
      break;
    case SETSTATE:
      setstate = (SETSTATESTRUCT*)malloc(sizeof(SETSTATESTRUCT));
      if(setstate==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)setstate;
      break;
    case TIMEOUT:
      timeout = (TIMEOUTSTRUCT*)malloc(sizeof(TIMEOUTSTRUCT));
      if(timeout==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)timeout;
      break;
    case SUBT:
      subt = (SUBTSTRUCT*)malloc(sizeof(SUBTSTRUCT));
      if(subt==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)subt;
      break;
   case CALC:
      calg = (CALCSTRUCT*)malloc(sizeof(CALCSTRUCT));
      if(calg==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)calg;
      break;
   case MUL:
      mul = (MULSTRUCT*)malloc(sizeof(MULSTRUCT));
      if(mul==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)mul;
      break;
   case DIV:
      div = (DIVSTRUCT*)malloc(sizeof(DIVSTRUCT));
      if(div==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)div;
      break;
   case ADD:
      add = (ADDSTRUCT*)malloc(sizeof(ADDSTRUCT));
      if(add==NULL)
      {
        free (cmd);
        return NULL;
      }
      cmd->data = (void*)add;
      break;
 }
  return cmd;
}
//*******************************************************
//* TODO pointer til firstcmd("root")
//********************************************************
void RemoveAllCommands(COMMANDSTRUCT **root)
{
  COMMANDSTRUCT *cmd, *dcmd;

  if(root==NULL) return;
  cmd=*root;
  while(cmd)
  {
    dcmd = cmd;
    cmd = cmd->next;
    freeCommandData(dcmd);
    free(dcmd);
  }
  *root = NULL;
}

//*******************************************************
//* delete command - can not be used to remove root
//********************************************************
static void __deleteCommand(COMMANDSTRUCT *currentcmd)
{
  COMMANDSTRUCT *dcmd = currentcmd;

  if(dcmd == NULL)
    return;


  freeCommandData(dcmd);
  if(dcmd->prev)
    dcmd->prev->next = dcmd->next;
  if(dcmd->next)
    dcmd->next->prev = dcmd->prev;
  
/*if(dcmd==ptrcmd) //added by THN 13.01.2005
  {
    ptrcmd = ptrcmd->next;
  }
  if(dcmd==firstcmd)
  {
    firstcmd = dcmd->next;
  }*/
  free(dcmd);
}

void deleteCommand(COMMANDSTRUCT *levelcmd)
{
  COMMANDSTRUCT *cmd = levelcmd->next, *dcmd;
  //delete child's (sub's)
  while(cmd && cmd->flag > levelcmd->flag)
  {
    dcmd = cmd;
    cmd = cmd->next;
    __deleteCommand(dcmd);
  }
  __deleteCommand(levelcmd);
}

/*
COMMANDSTRUCT *AddCommand(int type)
{
  COMMANDSTRUCT *cmd;

  cmd = __localAddCommand(type);

  if(firstcmd==NULL)
    firstcmd = ptrcmd = cmd;
  else
  {
    cmd->prev = ptrcmd;
    ptrcmd->next = cmd;
    ptrcmd = cmd;
  }
  return cmd;
}*/

//*************************************
//* 
//*************************************
COMMANDSTRUCT *InsertCommand(COMMANDSTRUCT *ptrcmd, int type)
{
  COMMANDSTRUCT *cmd;

  cmd = __localAddCommand(type);
  if(ptrcmd==NULL) return cmd;
  
  cmd->prev = ptrcmd;
  cmd->next = ptrcmd->next;
  ptrcmd->next = cmd;
  if(cmd->next!=NULL)
    cmd->next->prev=cmd;
  return cmd;
}

COMMANDSTRUCT *getParentCommand(COMMANDSTRUCT *cmd)
{
  COMMANDSTRUCT *parent;
  //find parent
  for(parent=cmd->prev;parent!=NULL&&parent->flag>=cmd->flag;parent=parent->prev);
  return parent;
}

COMMANDSTRUCT *getPreviusCommand(COMMANDSTRUCT *cmd)
{
  COMMANDSTRUCT *previus;
  //find previus command at same level
  previus=cmd->prev;
  if(previus!=NULL&&previus->flag<cmd->flag)
  {
    previus=NULL;
  }
  else
  {
    for(previus=cmd->prev;previus!=NULL&&previus->flag!=cmd->flag;previus=previus->prev);
  }
  return previus;
}

int SaveCommandScript(COMMANDSTRUCT *root, const char *filename)
{
  FILE *fp;
  COMMANDSTRUCT *cmd;
  char str[256];
  int prevlevel=0,l;

  if(root==NULL) return FALSE;
  fp = fopen(filename,"w");
  if(fp==NULL)
    return FALSE;

  fprintf(fp,"VERSION %d\n", SCRIPTVERSION);
  cmd=root->next; //do not write ROOT
  while(cmd)
  {
    getCommandString(str,cmd);
    for(l=prevlevel;l>cmd->flag;l--)
    {
        fprintf(fp,"END\n");
    }
    fprintf(fp,"%s\n",str);
    prevlevel=cmd->flag;
    cmd = cmd->next;
  }
  for(l=prevlevel;l>0;l--)
  {
      fprintf(fp,"END\n");
  }
  fclose(fp);
  return TRUE;
}

int tmpnPatternLoad(const char *filename, tmpnPattern *pattern)
{
  FILE *fp;
  int version;
  char buffer[256];
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  fscanf(fp,"PATTERNVERSION %d\n",&version);
  if(version!=PATTERNVERSION) return FALSE;
  fscanf(fp,"%s\n",pattern->name);
  pattern->maxidx=0;
  strcpy(pattern->filename,filename);
  pattern->width=800.0;
  pattern->length=1200.0;
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
    if(strncmp(buffer,"width=",6)==0)
    {
      sscanf(buffer,"width=%f\n",&pattern->width);
    }
    else if(strncmp(buffer,"length=",7)==0)
    {
      sscanf(buffer,"length=%f\n",&pattern->length);
    }
    else if(strncmp(buffer,"layer=",6)==0)
    {
      int layer; float x,y,z,v,w,u;
      sscanf(buffer,"layer=%d,wcp=%f,%f,%f,%f,%f,%f\n",&layer,&x,&y,&z,&v,&w,&u);
      pattern->item[pattern->maxidx].layer = layer;
      pattern->item[pattern->maxidx].wcp.x = x;
      pattern->item[pattern->maxidx].wcp.y = y;
      pattern->item[pattern->maxidx].wcp.z = z;
      pattern->item[pattern->maxidx].wcp.v = v;
      pattern->item[pattern->maxidx].wcp.w = w;
      pattern->item[pattern->maxidx].wcp.u = u;
      pattern->maxidx++;
    }
  }
  fclose(fp);
	printf("Loaded pattern %s %s\n",pattern->name,pattern->filename);
  return TRUE;
}

int tmpnPatternSave(tmpnPattern *pattern)
{
  FILE *fp;
  int i;
  fp = fopen(pattern->filename,"w");
  if(fp==NULL) return FALSE;
	fprintf(fp,"PATTERNVERSION %d\n",PATTERNVERSION);
	fprintf(fp,"%s\n",pattern->name);
	fprintf(fp,"width=%0.0f\n",pattern->width);
	fprintf(fp,"length=%0.0f\n",pattern->length);
	for(i=0;i<pattern->maxidx;i++)
	{
    fprintf(fp,"layer=%d,wcp=%0.0f,%0.0f,%0.0f,%0.0f,%0.0f,%0.0f\n"
        ,pattern->item[i].layer
        ,pattern->item[i].wcp.x
        ,pattern->item[i].wcp.y
        ,pattern->item[i].wcp.z
        ,pattern->item[i].wcp.v
        ,pattern->item[i].wcp.w
        ,pattern->item[i].wcp.u);
  }
  fclose(fp);
  return TRUE;
}

int tmpnCPPatternLoad(const char *filename, tmpnCPPatterns *cppatterns)
{  
  FILE *fp;
  int version;
  char buffer[256];
  tmpnCPPattern *cppattern;
  fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("Couldn't open CP pattern file: %s\n",filename);
    return FALSE;
  }
  fscanf(fp,"VERSION %d\n",&version);
  if(version>CPPATTERNVERSION)
  {
    printf("CP Pattern version mismatch. Detected version %d. Supports up to version %d\n",version,CPPATTERNVERSION);
    fclose(fp);
    exit(99);
  }
  if(cppatterns->maxidx==0)
    cppatterns->cppattern = (tmpnCPPattern*)malloc(sizeof(tmpnCPPattern));
  else
    cppatterns->cppattern = (tmpnCPPattern*)realloc(cppatterns->cppattern,sizeof(tmpnCPPattern)*(cppatterns->maxidx + 1));
  cppattern = &cppatterns->cppattern[cppatterns->maxidx++];
  fscanf(fp,"%s user=%d\n",cppattern->name,&cppattern->user);
  strcpy(cppattern->filename,filename);
  cppattern->selectedItem=0;
  cppattern->selectedPPP=0;
  cppattern->maxidx=0;
  
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
    if(strncmp(buffer,"layer=",6)==0)
    {
      int layer=0, maxpush=0, gettime=0, i;
      sscanf(buffer,"layer=%d maxpush=%d gettime=%d\n",&layer,&maxpush,&gettime);
      if(cppattern->maxidx==0)
        cppattern->items = (tmpnCPPatternItem*)malloc(sizeof(tmpnCPPatternItem));
      else
        cppattern->items = (tmpnCPPatternItem*)realloc(cppattern->items,sizeof(tmpnCPPatternItem)*(cppattern->maxidx + 1));
      tmpnCPPatternItem *item = &cppattern->items[cppattern->maxidx++];
      item->layer = layer;
      item->maxpush = maxpush;
      item->gettime = gettime;
      item->ppps = (int*)malloc(sizeof(int)*maxpush);
      item->paccs = (int*)malloc(sizeof(int)*maxpush);
      item->pspeeds = (int*)malloc(sizeof(int)*maxpush);
      for(i=0;i<maxpush;i++)
      {
        if(fgets(buffer, sizeof(buffer), fp)!=NULL)
        {
          if(strncmp(buffer,"ppp=",4)==0)
          {
            int ppp = 0, pacc=100, pspeed=100;
            sscanf(buffer,"ppp=%d pacc=%d pspeed=%d\n",&ppp,&pacc,&pspeed);
            item->ppps[i] = ppp;
            item->paccs[i] = pacc;
            item->pspeeds[i] = pspeed;
          }
          else
          {
            char str[256];
            int j;
            sscanf(buffer,"%s",str);
            printf("Error loading CP Pattern '%s' Got '%s', expected ppp.\n",cppattern->name,str);
            //item->ppps[i] = 0;
            //abort loading and free
            for(j=0;j<cppattern->maxidx;j++)
            {
              free(cppattern->items[j].ppps);
              free(cppattern->items[j].paccs);
              free(cppattern->items[j].pspeeds);
            }
            free(cppattern->items);
            cppatterns->maxidx--;
            cppatterns->cppattern = (tmpnCPPattern*)realloc(cppatterns->cppattern,sizeof(tmpnCPPattern)*(cppatterns->maxidx));
            fclose(fp);
            return FALSE;
          }
        }
        else
        {
          int j;
          printf("Error loading CP Pattern '%s' Got EOF, expected ppp\n",cppattern->name);
          for(j=0;j<cppattern->maxidx;j++)
          {
              free(cppattern->items[j].ppps);
              free(cppattern->items[j].paccs);
              free(cppattern->items[j].pspeeds);
          }
          free(cppattern->items);
          cppatterns->maxidx--;
          cppatterns->cppattern = (tmpnCPPattern*)realloc(cppatterns->cppattern,sizeof(tmpnCPPattern)*(cppatterns->maxidx));
          fclose(fp);
          return FALSE;
        }
      }
    }
    else
    {
      char str[256];
      int j;
      sscanf(buffer,"%s",str);
      printf("Error loading CP Pattern '%s' Got '%s', expected layer\n",cppattern->name,str);
      for(j=0;j<cppattern->maxidx;j++)
      {
          free(cppattern->items[j].ppps);
          free(cppattern->items[j].paccs);
          free(cppattern->items[j].pspeeds);
      }
      free(cppattern->items);
      cppatterns->maxidx--;
      cppatterns->cppattern = (tmpnCPPattern*)realloc(cppatterns->cppattern,sizeof(tmpnCPPattern)*(cppatterns->maxidx));
      fclose(fp);
      return FALSE;
    }
  }
  fclose(fp);
  printf("Loaded CP pattern %s %s\n",cppattern->name,cppattern->filename);
  return TRUE;
}

int tmpnCPPatternSave(tmpnCPPattern *cppattern)
{
  FILE *fp;
  int i;
  if(cppattern->user == 0)
  {
    printf("Couldn't save CP Pattern file: %s, user=0\n",cppattern->filename);
    return FALSE;
  }
  fp = fopen(cppattern->filename,"w");
  if(fp==NULL)
  {
    printf("Couldn't open CP pattern file: %s\n",cppattern->filename);
    return FALSE;
  }
	fprintf(fp,"VERSION %d\n",CPPATTERNVERSION);
	fprintf(fp,"%s user=%d\n",cppattern->name,cppattern->user);
  int j;
  for(i=0;i<cppattern->maxidx;i++){
    fprintf(fp,"layer=%d maxpush=%d gettime=%d\n",cppattern->items[i].layer,cppattern->items[i].maxpush,cppattern->items[i].gettime);
    for(j=0;j<cppattern->items[i].maxpush;j++){
      fprintf(fp,"ppp=%d pacc=%d pspeed=%d\n",cppattern->items[i].ppps[j],cppattern->items[i].paccs[j],cppattern->items[i].pspeeds[j]);
    }
  }
  fclose(fp);
  return TRUE;
}

void *getValueFunction(char *n)
{
  return NULL;
}
void copyFramesFromSTMtoRobot(void)
{
  int i,idx;
	tmpnStateMachineValue *stmval;
  trobot->m_frames.maxidx=0;
  if ((idx=getMachineIdx("Frames")) != -1)
  {
    for(i=0;i<tworkcell->statemachines.statemachine[idx].numvalue;i++)
    {
    	stmval=&tworkcell->statemachines.statemachine[idx].value[i];
    	{
  	  	if (stmval->type==FRAME)
  		  {
           strcpy(((tmpnRobot*)trobot)->m_frames.frame[trobot->m_frames.maxidx].name,stmval->frame->name);
           trobot->m_frames.frame[trobot->m_frames.maxidx].x=stmval->frame->x;
           trobot->m_frames.frame[trobot->m_frames.maxidx].y=stmval->frame->y;
           trobot->m_frames.frame[trobot->m_frames.maxidx].z=stmval->frame->z;
           trobot->m_frames.frame[trobot->m_frames.maxidx].v=stmval->frame->v;
           trobot->m_frames.frame[trobot->m_frames.maxidx].w=stmval->frame->w;
           trobot->m_frames.frame[trobot->m_frames.maxidx].u=stmval->frame->u;
           trobot->m_frames.maxidx++;
        }
      }
  	}
  }
}

void  tmpnStateMachineReset(void)
{
  int i;
  
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    tworkcell->statemachines.statemachine[i].type = -1;
    strcpy(tworkcell->statemachines.statemachine[i].name, "");
    tworkcell->statemachines.statemachine[i].istate = -1;
    tworkcell->statemachines.statemachine[i].next_istate = -1;
    tworkcell->statemachines.statemachine[i].new_istate = -1;
		tworkcell->statemachines.statemachine[i].timerstate = -1;
		tworkcell->statemachines.statemachine[i].debugvalue = NULL;
    tworkcell->statemachines.statemachine[i].stop = 0;
    tworkcell->statemachines.statemachine[i].mcSignal = 0;
    pthread_cond_init(&tworkcell->statemachines.statemachine[i].change, NULL);
    pthread_mutex_init(&tworkcell->statemachines.statemachine[i].change_mtx, NULL);
		
    tworkcell->statemachines.statemachine[i].numstate=0;
    tworkcell->statemachines.statemachine[i].numvalue=0;
    tworkcell->statemachines.statemachine[i].numtimeout=0;
    tworkcell->statemachines.statemachine[i].numinput=0;
    tworkcell->statemachines.statemachine[i].numoutput=0;
    tworkcell->statemachines.statemachine[i].numlink=0;
	}
}

void dumpStatemachinePrg(tmpnStateMachine *stm, int stateidx);

void  tmpnStateMachineDump(tmpnStateMachine *stm)
{
  int j;
  if(rs_param.statemachine_debug<=2) return;
  printf("=======================================\n");
  printf("STM=%s state=%d\n", stm->name, stm->istate);
  for(j=0;j<stm->numstate;j++)
  {
    printf("STM state %d: %s %d\n", j, stm->state[j].name, stm->state[j].statenum);
    if(rs_param.statemachine_debug>2)
      dumpStatemachinePrg(stm,j);
  }
  for(j=0;j<stm->numtimeout;j++)
  {
    printf("STM timeout %d: %s %d\n", j, stm->timeout[j].name, stm->timeout[j].timeout);
  }
  for(j=0;j<stm->numlink;j++)
  {
    printf("STM link %d: %s(%s) %d\n", j, stm->link[j].localname,stm->link[j].name, stm->link[j].stmidx);
  }
  for(j=0;j<stm->numvalue;j++)
  {
    if(stm->value[j].type==LINKVALUE)
		{
			if (stm->value[j].linkvalue!=NULL)
				printf("STM linkvalue %d: %s %s %s %d\n", j, stm->value[j].name,stm->value[j].linkname,stm->value[j].link, stm->value[j].linkvalue->data);
			else
				printf("STM linkvalue %d: %s %s %s (REMOTE = Not found yet)\n", j, stm->value[j].name,stm->value[j].linkname,stm->value[j].link);
		}
    else
      printf("STM value %d: %s %d\n", j, stm->value[j].name, stm->value[j].data);
  }
}

void error(int ln, char *e)
{
  printf("Error: line %d %s\n", ln, e);
  exit(1);
}

int getInputIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numinput;i++)
  {
    if(strcmp(stm->input[i].name, s)==0)
      return i;
  }

  return -1;
}

int getTimeoutIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numtimeout;i++)
  {
    if(strcmp(stm->timeout[i].name, s)==0)
      return i;
  }
  return -1;
}


int getOutputIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numoutput;i++)
  {
    if(strcmp(stm->output[i].name, s)==0)
      return i;
  }

  return -1;
}

tmpnFrame *getStmFrame(char *framename)
{
	int idx;
	tmpnStateMachineValue *stmval;
	if ((idx=getMachineIdx("Frames")) != -1)
	{
		if ((stmval=getMachineValue(idx,framename)) != NULL)
		{
			if (stmval->type==FRAME)
			{
				return stmval->frame;
			}
		}
	}
	return NULL;
}

tmpnStateMachineValue *getStmValue(tmpnStateMachine *stm, char *valuename)
{
  int i;
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, valuename)==0)
      return &stm->value[i];
  }
  return NULL;
}

tmpnStateMachineValue *getMachineValue(int machine, char *valuename)
{
  int i;
  if(machine<0||machine>=tworkcell->statemachines.maxidx) return NULL;
  tmpnStateMachine *stm=&tworkcell->statemachines.statemachine[machine];
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, valuename)==0)
      return &stm->value[i];
  }
  return NULL;
}

int *getMachineValuePtr(int machine, char *valuename)
{
  int i;
  if(machine<0||machine>=tworkcell->statemachines.maxidx) return NULL;
  tmpnStateMachine *stm=&tworkcell->statemachines.statemachine[machine];
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, valuename)==0)
      return &stm->value[i].data;
  }
  return NULL;
}
  
int getMachineVersion(int machine)
{
  int i;
  if(machine<0||machine>=tworkcell->statemachines.maxidx) return 0;
  tmpnStateMachine *stm=&tworkcell->statemachines.statemachine[machine];
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, "VERSION")==0)
      return stm->value[i].data;
  }
  return 0;
}

int getValueIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, s)==0)
      return i;
  }

  return -1;
}

int getLinkIdx(tmpnStateMachine *stm, char *s)
{
  int i;

  for(i=0;i<stm->numlink;i++)
  {
    if(strcmp(stm->link[i].localname, s)==0)
      return i;
  }
  return -1;
}

int findSTMIdx(tmpnStateMachine *stm, char *s)
{
	int sidx=-1,i;
	//local on this host ?
	for(i=0;i<stm->numlink;i++)
	{
		if (!strcmp(stm->link[i].localname,s))
		{
			sidx = getMachineIdx(stm->link[i].name);
			break;
		}
	}
	return sidx;
}

tmpnStateMachineValue *getLinkValue(tmpnStateMachine *stm, tmpnStateMachineValue *value)
{
	static int depth=0;
  tmpnStateMachineValue *linkvalue; 
	tmpnStateMachineValue *tempvalue; 
  int sidx,vidx;
	linkvalue=NULL;
  //find value
  //local on this host ?
  if(strlen(value->link)>0)
  {
    sidx =  findSTMIdx(stm, value->link);
	  if(sidx==-1)
		  sidx = getMachineIdx(value->link);
		if(sidx!=-1)
    {
      vidx = getValueIdx(&tworkcell->statemachines.statemachine[sidx], value->linkname);
      if(vidx!=-1)
      {
   	    linkvalue = &tworkcell->statemachines.statemachine[sidx].value[vidx];
      }
    }
  }
  if(linkvalue!=NULL)
  {
    if(linkvalue->type==LINKVALUE)
    {
			if (linkvalue==value)
			{
				printf("linkValue \"%s\" in statemachine \"%s\" referered to one self which is Not Good (tm). Quitting\n",value->linkname,stm->name);
				exit(1);
			}
			if (depth>=MAXLINKVALUE_DEPTH)
			{
				printf("linkValue (%s,%s) recursion depth==%i reached. You should probably check linkvalues for circular references. Quitting\n",stm->name,value->name,MAXLINKVALUE_DEPTH);
				exit(1);
			}
			else
			{
				depth++;
			}
      tempvalue=getLinkValue(stm,linkvalue);
			if(tempvalue!=NULL)
				linkvalue=tempvalue;
    }
  }
	depth=0;
  return linkvalue;
}

      
void SetupSTMLink1(tmpnStateMachine *stm)
{
  int j, l;

  //look for local link to local statemachines  
  for(j=0;j<stm->numlink;j++)
  {
    stm->link[j].stmidx=-1;
    for(l=0;l<tworkcell->statemachines.maxidx;l++)
    {
      if(strcmp(stm->link[j].name, tworkcell->statemachines.statemachine[l].name)==0)
   		{
				stm->link[j].stmidx = l;
	  	}
    }      
  }
}


tmpnFrame *getPatternItem(tmpnPattern *p, int idx)
{
  return &p->item[idx].wcp;
}

void SetupSTMLink2(tmpnStateMachine *stm)
{
  int j, s,p;
	int tmpsubtype;
	ARGSTRUCT *arg;
	tmpnBoptCoeff* BoptCoeffs;
	
	BoptCoeffs = getBoptCoeff((tmpnWorkcell*)tworkcell);
  //do we want to read a value from an other statemachine located on this host
  for(j=0;j<stm->numvalue;j++)
  {
    stm->value[j].linkvalue = NULL;
    if(stm->value[j].type==LINKVALUE)
    {
      stm->value[j].linkvalue=getLinkValue(stm,&stm->value[j]);
      if(stm->value[j].linkvalue!=NULL)
	      stm->value[j].subtype=stm->value[j].linkvalue->subtype;
		  else
        printf("linkValue=%s in %s from %s is located on a remote host ?\n", stm->value[j].name,stm->name,stm->value[j].link);
    }      
    else if(stm->value[j].type==PATHHANDLE)
    {
			//   tmpnPathHandle *path=stm->value[j].path; 
			//   path->key.boptcoeff=getBoptCoeffItem(BoptCoeffs, path->key.mode, path->key.type);
			//   path->key.from.item = getItem(path->key.from.itemName,(tmpnWorkcell*)tworkcell);
			//   path->key.to.item = getItem(path->key.to.itemName,(tmpnWorkcell*)tworkcell);
			//   path->key.from.pattern = getPattern(path->key.from.patternName,(tmpnWorkcell*)tworkcell);
			//   path->key.to.pattern = getPattern(path->key.to.patternName,(tmpnWorkcell*)tworkcell);
    }
    else if(stm->value[j].type==PATTERN)
    {
      if ((stm->value[j].pattern = getPattern(stm->value[j].link,(tmpnWorkcell*)tworkcell)) != NULL)
        stm->value[j].frame = &stm->value[j].pattern->item[0].wcp;
      else
        printf("unknown pattern: %s, machine=%s\n", stm->value[j].link, stm->name);
    }
    else if(stm->value[j].type==CPPATTERN)
    {
      if ((stm->value[j].cppattern = getCPPattern(stm->value[j].link,(tmpnWorkcell*)tworkcell)) == NULL)
      {
        printf("Load of unknown CP Pattern: '%s' in statemachine=%s\n", stm->value[j].link, stm->name);
      }
    }
    else if(stm->value[j].type==ITEM)
		{
      stm->value[j].item = getItem(stm->value[j].link,(tmpnWorkcell*)tworkcell);
			if (stm->value[j].item==NULL) 
			{
				printf("Load of unknown item \"%s\" in statemachine=%s\n",stm->value[j].link, stm->name);
				exit(1);
			}
		}
  }
  for(s=0;s<stm->numstate;s++)
  {
    for(p=0;p<stm->state[s].maxprgidx;p++)
    {
      if(stm->state[s].prg[p].type == SETSTATE)
      {
        ((SETSTATESTRUCT*)stm->state[s].prg[p].data)->number = getMachineStateIdx(stm->name,((SETSTATESTRUCT*)stm->state[s].prg[p].data)->name);
        if(((SETSTATESTRUCT*)stm->state[s].prg[p].data)->number==-1)
        {
          printf("unknown setstate=%s, machine=%s\n",((SETSTATESTRUCT*)stm->state[s].prg[p].data)->name,stm->name);
          //exit(1);
        }
      }
      else if(stm->state[s].prg[p].type == LOAD)
      {
        LOADSTRUCT *load=(LOADSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,load->dest);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==PATHHANDLE) load->path = value->path;
        else
          printf("load of unknown path%s in statemachine=%s\n",load->dest, stm->name);
        
        for(value=getStmValue(stm,load->src1);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==FRAME) load->fromFrame = value->frame;
        else
          printf("unknown fromFrame %s, machine=%s\n",load->src1, stm->name);
        
        for(value=getStmValue(stm,load->src2);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==FRAME) load->toFrame = value->frame;
        else
          printf("unknown toFrame %s, machine=%s\n",load->src2, stm->name);
      }
      else if(stm->state[s].prg[p].type == EXEC)
      {
        EXECSTRUCT *exec=(EXECSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;
        
        for(value=getStmValue(stm,exec->dest);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==PATHHANDLE) 
          exec->path = value->path;
        else
          printf("exec of unknown path %s in statemachine=%s\n",exec->dest, stm->name);
      }
      else if(stm->state[s].prg[p].type == SETFRAME)
      {
        SETFRAMESTRUCT *setframe=(SETFRAMESTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,setframe->dest);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==FRAME)
          setframe->destFrame = value->frame;
        else
          printf("unknown destination frame: %s, machine=%s\n", setframe->dest, stm->name);
        
        for(value=getStmValue(stm,setframe->src);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==FRAME)
          setframe->srcFrame = value->frame;
        else if(value!=NULL&&value->type==PATTERN)
          setframe->srcFrame = value->frame;
        else
          printf("unknown source frame: %s, machine=%s\n", setframe->src, stm->name);
      }
			else if(stm->state[s].prg[p].type == SETITEM)
      {
        SETITEMSTRUCT *setitem=(SETITEMSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,setitem->dest);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==ITEM)
          setitem->destItem = &value->item;
        else
          printf("unknown destination item: %s, machine=%s\n", setitem->dest, stm->name);

        for(value=getStmValue(stm,setitem->src);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==ITEM)
          setitem->srcItem = value->item;
        else
          printf("unknown source item: %s, machine=%s\n", setitem->src, stm->name);
      }
			else if(stm->state[s].prg[p].type == SETPATTERN)
      {
        SETPATTERNSTRUCT *setpattern=(SETPATTERNSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,setpattern->dest);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==PATTERN)
          setpattern->destPattern = &value->pattern;
        else
          printf("unknown destination pattern: %s, machine=%s\n", setpattern->dest, stm->name);
        
        for(value=getStmValue(stm,setpattern->src);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==PATTERN)
          setpattern->srcPattern = value->pattern;
        else
          printf("unknown source pattern: %s, machine=%s\n", setpattern->src, stm->name);

      }
      else if(stm->state[s].prg[p].type == SETCPPATTERN)
      {
        SETCPPATTERNSTRUCT *setcppattern=(SETCPPATTERNSTRUCT*)stm->state[s].prg[p].data;
        tmpnStateMachineValue *value;

        for(value=getStmValue(stm,setcppattern->dest);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==CPPATTERN)
          setcppattern->destCPPattern = &value->cppattern;
        else
          printf("unknown destination CP pattern: %s, machine=%s\n", setcppattern->dest, stm->name);
        
        for(value=getStmValue(stm,setcppattern->src);value!=NULL&&value->type==LINKVALUE;value=value->linkvalue);
        if(value!=NULL&&value->type==CPPATTERN)
          setcppattern->srcCPPattern = value->cppattern;
        else
          printf("unknown source CP pattern: %s, machine=%s\n", setcppattern->src, stm->name);
      }
      else if(stm->state[s].prg[p].type == TIMEOUT)
      {
        if(strlen(((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->statename)>0)
        {
          ((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->number = getMachineStateIdx(stm->name,((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->statename);
          if(((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->number==-1)
          {
            printf("unknown timeout state=%s, machine=%s\n",((TIMEOUTSTRUCT*)stm->state[s].prg[p].data)->statename,stm->name);
          //exit(1);
          }
        }
      }
      else if((stm->state[s].prg[p].type == TEST&&((TESTSTRUCT*)stm->state[s].prg[p].data)->test.type == LINK)
              ||(stm->state[s].prg[p].type == OR&&((TESTSTRUCT*)stm->state[s].prg[p].data)->test.type == LINK)
              ||(stm->state[s].prg[p].type == ELSETEST&&((TESTSTRUCT*)stm->state[s].prg[p].data)->test.type == LINK)
              ||(stm->state[s].prg[p].type == AND&&((TESTSTRUCT*)stm->state[s].prg[p].data)->test.type == LINK))
      {
				int stmidx;
				stmidx = findSTMIdx(stm, ((TESTSTRUCT*)stm->state[s].prg[p].data)->test.valstring);
				if (stmidx!=-1) ((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp.number = getStateIdx(stmidx, ((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp.valstring);
        if ((((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp.number==-1)||stmidx==-1)
        {
          printf("stm->name %s unknown TEST state=%s, machine=%s\n"
								 ,stm->name
								 ,((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp.valstring
								 ,((TESTSTRUCT*)stm->state[s].prg[p].data)->test.valstring);
        }
      }
			else if(stm->state[s].prg[p].type == TEST
              ||stm->state[s].prg[p].type == OR
              ||stm->state[s].prg[p].type == ELSETEST
              ||stm->state[s].prg[p].type == AND)
			{
				arg=&((TESTSTRUCT*)stm->state[s].prg[p].data)->test;
				tmpsubtype=getArgSubType(stm, arg);
				if (tmpsubtype!=-1)
				{
					arg->subtype=tmpsubtype;
				}
				arg=&((TESTSTRUCT*)stm->state[s].prg[p].data)->cmp;
				tmpsubtype=getArgSubType(stm, arg);
				if (tmpsubtype!=-1)
				{
					arg->subtype=tmpsubtype;
				}
			}
			else if(stm->state[s].prg[p].type == ROBOTSPEED)
			{
				arg=&((ROBOTSPEEDSTRUCT*)stm->state[s].prg[p].data)->src;
				tmpsubtype=getArgSubType(stm, arg);
				if (tmpsubtype!=-1)
				{
					arg->subtype=tmpsubtype;
				}
			}
			else if(stm->state[s].prg[p].type == SET)
			{
				arg=&((SETSTRUCT*)stm->state[s].prg[p].data)->src;
				tmpsubtype=getArgSubType(stm, arg);
				if (tmpsubtype!=-1)
				{
					arg->subtype=tmpsubtype;
				}
				arg=&((SETSTRUCT*)stm->state[s].prg[p].data)->dest;
				tmpsubtype=getArgSubType(stm, arg);
				if (tmpsubtype!=-1)
				{
					arg->subtype=tmpsubtype;
				}
			}
			else if(stm->state[s].prg[p].type == CALC)
			{
				arg=&((CALCSTRUCT*)stm->state[s].prg[p].data)->dest;
				tmpsubtype=getArgSubType(stm, arg);
				if (tmpsubtype!=-1)
				{
					arg->subtype=tmpsubtype;
				}
				arg=&((CALCSTRUCT*)stm->state[s].prg[p].data)->src1;
				tmpsubtype=getArgSubType(stm, arg);
				if (tmpsubtype!=-1)
				{
					arg->subtype=tmpsubtype;
				}
				arg=&((CALCSTRUCT*)stm->state[s].prg[p].data)->src2;
				tmpsubtype=getArgSubType(stm, arg);
				if (tmpsubtype!=-1)
				{
					arg->subtype=tmpsubtype;
				}
			}
      //TODO PATHHANDLE
      else if (stm->state[s].prg[p].type == ELSE || stm->state[s].prg[p].type == ENDTEST || stm->state[s].prg[p].type == PRINT)
      {
      }
      else
      {
        printf("Unknown STM command (type %d) in %s -> %s\n", stm->state[s].prg[p].type, stm->name, stm->state[s].name);
      }
    }
  }
}

void freeState(tmpnStateMachineState *state)
{
  int l;
	for(l=0;l<state->maxprgidx;l++)
  {
    free(state->prg[l].data);
  }
	free(state->prg);
}

void deleteSTMPrg(tmpnStateMachine *statemachine)
{
  int i;
  for(i=0;i<statemachine->numstate;i++)
  {
    freeState(&statemachine->state[i]);
  }
	free(statemachine->state);
	free(statemachine->value);
	free(statemachine->timeout);
	free(statemachine->input);
	free(statemachine->output);
	free(statemachine->link);
	
  statemachine->type = -1;
  strcpy(statemachine->name, "");
  statemachine->istate = -1;
  statemachine->next_istate = -1;
  statemachine->new_istate = -1;
  statemachine->stop = 0;
  statemachine->mcSignal = 0;
  statemachine->delaystop = 0;
}

void printfIndex(int level )
{
  int i;

  for(i=0;i<level*2;i++)
    printf(" ");
}

void dumpStatemachinePrg(tmpnStateMachine *stm, int stateidx)
{
  int i, level=0;

  printf("State=%s\n", stm->state[stateidx].name);
  for(i=0;i<=stm->state[stateidx].maxprgidx;i++)
  {
    printf("%3d ", i);
    switch(stm->state[stateidx].prg[i].type)
    {
      case TEST :
        printfIndex(level);
        printf("TEST level %d type %d vali %d idx %d cmpidx %d val %d true %d false %d done %d\n"
							 ,stm->state[stateidx].prg[i].level
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.type
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->validation
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.idx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.idx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.number
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->trueIdx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->falseIdx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
							 );
				level++;
      break;
		  case ELSETEST :
        printfIndex(level - 1);
        printf("ELSETEST level %d type %d vali %d idx %d cmpidx %d val %d true %d false %d done %d\n"
							 ,stm->state[stateidx].prg[i].level
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.type
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->validation
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.idx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.idx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.number
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->trueIdx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->falseIdx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
							 );
				break;
      case OR :
        printfIndex(level - 1);
        printf("OR level %d type %d vali %d idx %d cmpidx %d val %d true %d false %d done %d\n"
							 ,stm->state[stateidx].prg[i].level
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.type
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->validation
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.idx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.idx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.number
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->trueIdx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->falseIdx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
							 );
				break;
      case AND :
        printfIndex(level - 1);
        printf("AND level %d type %d vali %d idx %d cmpidx %d val %d true %d false %d done %d\n"
							 ,stm->state[stateidx].prg[i].level
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.type
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->validation
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.idx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->cmp.idx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->test.number
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->trueIdx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->falseIdx
							 ,((TESTSTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
							 );
      break;
      case SETSTATE :
        printfIndex(level);
        printf("SETSTATE %s\n", 
          ((SETSTATESTRUCT*)stm->state[stateidx].prg[i].data)->name
          );
      break;
      case LOAD:
        printfIndex(level);
        printf("LOAD %s %s %s\n", 
          ((LOADSTRUCT*)stm->state[stateidx].prg[i].data)->dest
         ,((LOADSTRUCT*)stm->state[stateidx].prg[i].data)->src1
         ,((LOADSTRUCT*)stm->state[stateidx].prg[i].data)->src2
          );
      break;
      case EXEC:
        printfIndex(level);
        printf("EXEC %s\n", 
          ((LOADSTRUCT*)stm->state[stateidx].prg[i].data)->dest
          );
      break;
      case SETFRAME :
        printfIndex(level);
        printf("SETFRAME %s %s\n", 
          ((SETFRAMESTRUCT*)stm->state[stateidx].prg[i].data)->dest
         ,((SETFRAMESTRUCT*)stm->state[stateidx].prg[i].data)->src
          );
      break;
      case SETITEM :
        printfIndex(level);
        printf("SETITEM %s %s\n", 
          ((SETITEMSTRUCT*)stm->state[stateidx].prg[i].data)->dest
         ,((SETITEMSTRUCT*)stm->state[stateidx].prg[i].data)->src
          );
      break;
  		case ROBOTSPEED :
        printfIndex(level);
        printf("ROBOTSPEED %d %d\n" 
							 ,((ROBOTSPEEDSTRUCT*)stm->state[stateidx].prg[i].data)->src.type
							 ,((ROBOTSPEEDSTRUCT*)stm->state[stateidx].prg[i].data)->src.idx
							 );
				break;
      case PRINT :
        printfIndex(level);
        printf("PRINT %s (%d,%d,%d)\n" 
          ,((PRINTSTRUCT*)stm->state[stateidx].prg[i].data)->arg.valstring
          ,((PRINTSTRUCT*)stm->state[stateidx].prg[i].data)->arg.type
          ,((PRINTSTRUCT*)stm->state[stateidx].prg[i].data)->arg.idx
          ,((PRINTSTRUCT*)stm->state[stateidx].prg[i].data)->arg.number
          );
      break;
      case TIMEOUT :
        printfIndex(level);
        printf("TIMEOUT %d %d\n", 
          ((TIMEOUTSTRUCT*)stm->state[stateidx].prg[i].data)->idx
          ,((TIMEOUTSTRUCT*)stm->state[stateidx].prg[i].data)->number
          );
      break;
      case SET :
        printfIndex(level);
        printf("SET %d %d %d %d %d\n", 
          ((SETSTRUCT*)stm->state[stateidx].prg[i].data)->dest.type

          ,((SETSTRUCT*)stm->state[stateidx].prg[i].data)->dest.idx
          ,((SETSTRUCT*)stm->state[stateidx].prg[i].data)->src.type
          ,((SETSTRUCT*)stm->state[stateidx].prg[i].data)->src.idx
          ,((SETSTRUCT*)stm->state[stateidx].prg[i].data)->dest.number
          );
      break;
	  	case CALC:
				printfIndex(level);
				printf("CALC %d %d %d %d %d %d %d %d\n", 
							 ((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->dest.type							 
							 ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->dest.idx
							 ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->optype
							 ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->src1.type
							 ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->src1.idx
							 ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->src2.type
							 ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->src2.idx
							 ,((CALCSTRUCT*)stm->state[stateidx].prg[i].data)->dest.number
							 );
				break;
      case ELSE :
        printfIndex(level - 1);
        printf("ELSE level %d %d\n"
							 ,stm->state[stateidx].prg[i].level 
							 ,((ELSESTRUCT*)stm->state[stateidx].prg[i].data)->doneIdx
							 );
      break;
      case ENDTEST :
        level--;
        printfIndex(level);
        printf("ENDTEST level %d \n",stm->state[stateidx].prg[i].level);
      break;
      case END :
        printfIndex(level);
        printf("END \n");
      break;
      default:
        printf("type=%d unknown in stm=%s state=%s prg=%d\n",stm->state[stateidx].prg[i].type,stm->name,stm->state[stateidx].name,i);
        break;
    }
  }
}

static int ln=0;

void SetLevelJmp(tmpnStateMachineState * stm, int idx)
{
  int i;
  int level = stm->prg[idx].level;
  int firstnontestidx=-1;
  int elseidx = -1;
	int oridx=-1;
	int elsetestidx=-1;
  for(i=idx;i>=0;i--)
  {
    if(level == stm->prg[i].level)
    {
      switch(stm->prg[i].type)
      {
			case ELSE :
				((ELSESTRUCT*)stm->prg[i].data)->doneIdx = idx + 1;
				elseidx = i;
				break;
			case ELSETEST :
			case TEST :
			case OR :
			case AND :
				((TESTSTRUCT*)stm->prg[i].data)->doneIdx = idx + 1;
				if (firstnontestidx==-1) firstnontestidx=i+1;
				if (stm->prg[i + 1].type == OR)
				{
					((TESTSTRUCT*)stm->prg[i].data)->trueIdx = firstnontestidx;
					((TESTSTRUCT*)stm->prg[i].data)->falseIdx = i + 1;
				}
				else
				{
					((TESTSTRUCT*)stm->prg[i].data)->trueIdx = i + 1;
					if (oridx > -1)
					{
						((TESTSTRUCT*)stm->prg[i].data)->falseIdx = oridx;
					}
					else if (elsetestidx > -1)
					{
						((TESTSTRUCT*)stm->prg[i].data)->falseIdx = elsetestidx;
					}
					else if(elseidx > -1)
						((TESTSTRUCT*)stm->prg[i].data)->falseIdx = elseidx + 1;
					else
						((TESTSTRUCT*)stm->prg[i].data)->falseIdx = idx + 1;
				}
			  if (stm->prg[i].type == OR) oridx = i;
				else if (stm->prg[i].type == ELSETEST) {
					elsetestidx = i;
					firstnontestidx=-1;
					oridx=-1;
				}
				else if (stm->prg[i].type == TEST) return;
        break;
      }
    }
  }
}


void setConnectValue(tmpnConnect *connect, unsigned short value)
{
  if(connect==NULL) return;
  *connect->udata &= ~(connect->mask<<connect->shift);
  *connect->udata |= ((value&connect->mask)<<connect->shift);
}

void setConnectValueSigned(tmpnConnect *connect, short value)
{
  if(connect==NULL) return;
  *connect->sdata = value;
}

void setConnectValueUnSigned(tmpnConnect *connect, unsigned short value)
{
  if(connect==NULL) return;
  *connect->udata = value;
}

unsigned short getConnectValue(tmpnConnect *connect)
{
  unsigned short ret=0;
  if(connect==NULL) return FALSE;
  if(connect->shift==0) 
  {
    ret=((*connect->udata)&connect->mask);
  }
  else
  {
    ret=(((*connect->udata)>>connect->shift)&connect->mask);
  }
  return ret;
}

short getConnectValueSigned(tmpnConnect *connect)
{
  short ret=0;
  if(connect==NULL) return FALSE;
  if(connect->shift==0) 
  {
    ret=*connect->sdata;
  }
  else
  {
    printf("error: shift != 0 in getConnectValueSigned\n");
    exit(99);
  }
  return ret;
}
unsigned short getConnectValueUnSigned(tmpnConnect *connect)
{
  unsigned short ret=0;
  if(connect==NULL) return FALSE;
  if(connect->shift==0) 
  {
    ret=*connect->udata;
  }
  else
  {
    printf("error: shift != 0 in getConnectValueUnSigned\n");
    exit(99);
  }
  return ret;
}

void setConnectValueInt(tmpnConnect *connect, int value)
{
  if(connect->connectType==OSHORTDATA)
    setConnectValueSigned(connect,value);
  else if(connect->connectType==OWORDDATA)
    setConnectValueUnSigned(connect,value);
  else
    setConnectValue(connect,value);
}

int getConnectValueInt(tmpnConnect *connect)
{
  if(connect->connectType==ISHORTDATA||connect->connectType==OSHORTDATA)
    return getConnectValueSigned(connect);
  else if(connect->connectType==IWORDDATA||connect->connectType==OWORDDATA)
    return getConnectValueUnSigned(connect);
  else
    return getConnectValue(connect);
}

void printArgValue(tmpnStateMachineValue * val)
{
  if(val->type==VALUE||val->type==CONSTANT)
  {
    if(val->subtype==0)
      printf("PRINT VALUE: %s=%d",val->name,val->data);
    else
      printf("PRINT VALUE: %s=%0.4f",val->name,val->fdata);
  }
  else if(val->type==LINKVALUE)
  {
		if (val->linkvalue!=NULL)
		{
			printArgValue(val->linkvalue);
		}
		else
		{
			if (val->remote!=NULL&&val->remote->remotehost!=NULL)
			{
				if(val->remote->subtype==0)
					printf("PRINT VALUE: %s=%d",val->remote->name,val->remote->data);
				else
					printf("PRINT VALUE: %s=%0.4f",val->remote->name,val->remote->fdata);
			}
		}
  }
  else if(val->type==TABLE)
  {
    if(val->subtype==0)
    {
      printf("PRINT TABLE: %s=%d curtablesize=%d sum=%d sumcnt=%d maxidx=%d min=%d max=%d topidx=%d topsearchwidth=%d topval=%f"
        ,val->name
        ,val->data
        ,val->table->curtablesize
        ,val->table->sum
        ,val->table->sumcnt
        ,val->table->maxidx
        ,val->table->min
        ,val->table->max
        ,val->table->topidx
        ,val->table->topsearchwidth
        ,val->table->topval
        );
    }
    else
    {
      printf("PRINT TABLE: %s=%f curtablesize=%d sum=%f sumcnt=%d maxidx=%d min=%f max=%f topidx=%d topsearchwidth=%d topval=%f"
        ,val->name
        ,val->fdata
        ,val->table->curtablesize
        ,val->table->fsum
        ,val->table->sumcnt
        ,val->table->maxidx
        ,val->table->fmin
        ,val->table->fmax
        ,val->table->topidx
        ,val->table->topsearchwidth
        ,val->table->topval
        );
    }
  }
  else if(val->type==PATTERN)
  {
    printf("PRINT PATTERN: %s %s layer=%d wcp.x=%3.2f y=%3.2f z=%3.2f v=%3.2f w=%3.2f u=%3.2f",val->name,val->link
                        ,val->pattern->item[0].layer
                        ,val->pattern->item[0].wcp.x
                        ,val->pattern->item[0].wcp.y
                        ,val->pattern->item[0].wcp.z
                        ,val->pattern->item[0].wcp.v
                        ,val->pattern->item[0].wcp.w
                        ,val->pattern->item[0].wcp.u
                        );
  }
  else if(val->type==CPPATTERN)
  {
    int i,j;
    printf("PRINT CPPATTERN: %s %s\n",val->name,val->link);
    for(i=0;i<val->cppattern->maxidx;i++)
    {
      printf("layer=%d maxpush=%d gettime=%d ",val->cppattern->items[i].layer,val->cppattern->items[i].maxpush,val->cppattern->items[i].gettime);
      for(j=0;j<val->cppattern->items[i].maxpush;j++)
      {
        printf("ppp=%d pacc=%d pspeed=%d",val->cppattern->items[i].ppps[j], val->cppattern->items[i].paccs[j], val->cppattern->items[i].pspeeds[j]);
      }
      printf("\n");
    }
  }
  else if(val->type==ITEM)
  {
    printf("PRINT ITEM: %s %s type=%s name=%s dim.x=%3.2f y=%3.2f z=%3.2f sy=%3.2f gy=%3.2f my=%3.2f gx=%3.2f weight=%3.2f",val->name,val->link
                        ,val->item->type
                        ,val->item->name
                        ,val->item->dim.x
                        ,val->item->dim.y
                        ,val->item->dim.z
                        ,val->item->sy
                        ,val->item->gy
                        ,val->item->my
                        ,val->item->gx
                        ,val->item->weight
                        );
  }
  else if(val->type==FRAME)
  {
    printf("PRINT FRAME: %s %s  x=%3.2f y=%3.2f z=%3.2f v=%3.2f w=%3.2f"
    ,val->name,val->frame->name,val->frame->x,val->frame->y,val->frame->z,val->frame->v,val->frame->w);
  }
  else if(val->type==PATHHANDLE)
  {
    printf("PRINT PATHHANDLE: %s state=%d mode=%d type=%d\n",val->name,val->path->state,val->path->key.mode,val->path->key.type);
    printf("PRINT ----''----: from=%s(%d,%d) x=%3.2f y=%3.2f z=%3.2f v=%3.2f w=%3.2f\n"
          ,val->path->key.from.frame.name
          ,val->path->key.from.cItem
          ,val->path->key.from.cLayer
          ,val->path->key.from.frame.x
          ,val->path->key.from.frame.y
          ,val->path->key.from.frame.z
          ,val->path->key.from.frame.v
          ,val->path->key.from.frame.w);
    printf("PRINT ----''----: to=%s(%d,%d) x=%3.2f y=%3.2f z=%3.2f v=%3.2f w=%3.2f"
          ,val->path->key.to.frame.name
          ,val->path->key.to.cItem
          ,val->path->key.to.cLayer
          ,val->path->key.to.frame.x
          ,val->path->key.to.frame.y
          ,val->path->key.to.frame.z
          ,val->path->key.to.frame.v
          ,val->path->key.to.frame.w);
  }
}

void printArg(tmpnStateMachine * stm, ARGSTRUCT *arg, int newline)
{
  static struct timeval currentTime;
  static struct timeval startTime;
  static int firsttime = 1;
  if(firsttime==1)
  {
    firsttime=0;
    gettimeofday(&startTime, NULL);
  }
  gettimeofday(&currentTime, NULL);
  printf("%05ld:%03ld ",currentTime.tv_sec-startTime.tv_sec, currentTime.tv_usec/1000);
  
  switch(arg->type)
	{
	case NUMBER:
		printf("PRINT NUMBER: %d",arg->number);
		break;
	case VALUE:
		printArgValue(&stm->value[arg->idx]);
		break;
	case IBITDATA:
	case IWORDDATA:
	case ISHORTDATA:
		printf("PRINT INPUT: %s=%d (\"%s\",\"%s\",\"%s\")"
					 ,stm->input[arg->idx].name
					 ,getConnectValueInt(stm->input[arg->idx].connect)
					 ,stm->input[arg->idx].connect->name
					 ,stm->input[arg->idx].connect->key
					 ,stm->input[arg->idx].connect->text);
		break;
	case OBITDATA:
	case OWORDDATA:
	case OSHORTDATA:
		printf("PRINT OUTPUT: %s=%d (\"%s\",\"%s\",\"%s\")"
					 ,stm->output[arg->idx].name
					 ,getConnectValueInt(stm->output[arg->idx].connect)
					 ,stm->output[arg->idx].connect->name
					 ,stm->output[arg->idx].connect->key
					 ,stm->output[arg->idx].connect->text);
		break;
	case TIMEOUT:
		printf("PRINT TIMEOUT: %s=%d",stm->timeout[arg->idx].name,stm->timeout[arg->idx].timeout);
		break;
	default:
		break;
	}
  if(newline) printf("\n");
}

int findDot(char *s)
{
  int i=0;
  while(s[i]!=0)
  {
    if(s[i]=='.') return i;
    i++;
  }
  return -1;
}

int splitArg(char *s, char *s1, char *s2)
{
  int i,j,x;

  strcpy(s1,s); 
  s2[0]=0;
  x=findDot(s);
  if(x>=0)
  {
    s1[x]=0;
    i=x+1;
    j=0;
    while(s[i]!=0)
    {
      s2[j++]=s[i++];
    }
    s2[j]=0;
  }
  return x;
}

char *getStateString(int idx)
{
  switch(idx)
  {
    case 1: return "ST_IDLE";
    case 2: return "ST_LOADED";
    case 3: return "ST_FINISHED";
    case 4: return "ST_ERROR";
    case 5: return "ST_INACTIVE";
    case 6: return "ST_LOAD";
    case 7: return "ST_EXEC";
    case 8: return "ST_BOPTING";
    case 9: return "ST_LOADING";
    case 10: return "ST_EXECUTING";
  }
  return "";
}

int getStateStringIdx(char *s)
{
  if(strcmp(s,"ST_IDLE")==0) return 1;
  if(strcmp(s,"ST_LOADED")==0) return 2;
  if(strcmp(s,"ST_FINISHED")==0) return 3;
  if(strcmp(s,"ST_ERROR")==0) return 4;
  if(strcmp(s,"ST_INACTIVE")==0) return 5;
  if(strcmp(s,"ST_LOAD")==0) return 6;
  if(strcmp(s,"ST_EXEC")==0) return 7;
  if(strcmp(s,"ST_BOPTING")==0) return 8;
  if(strcmp(s,"ST_LOADING")==0) return 9;
  if(strcmp(s,"ST_EXECUTING")==0) return 10;
  return 0;
}

int getCmpType(tmpnStateMachine *stm, char *s, int ln)
{
  int i,x;
  char s1[256]; 
  char s2[256];
  
  x = splitArg(s,s1,s2); 
 
  for(i=0;i<stm->numinput;i++)
	{ 
		if (stm->input[i].iotype==INPUT)
		{
			if(strcmp(stm->input[i].name, s1)==0)
				return stm->input[i].connect->connectType;
		}
		else if (stm->input[i].iotype==INLC)
		{
			if(strcmp(stm->input[i].name, s1)==0)
				return INLC;
		}
		else if (stm->input[i].iotype==INCOMSK)
		{
			if(strcmp(stm->input[i].name, s1)==0)
				return INCOMSK;
		}
		else if (stm->input[i].iotype==INMAC)
		{
			if(strcmp(stm->input[i].name, s1)==0)
				return INMAC;
		}
		else if (stm->input[i].iotype==INICPCON)
		{
			if(strcmp(stm->input[i].name, s1)==0)
				return INICPCON;
		}
  }
  for(i=0;i<stm->numvalue;i++)
  {
    if(strcmp(stm->value[i].name, s1)==0) 
    {
      return VALUE;
    }
  }
  for(i=0;i<stm->numoutput;i++)
  {
		if (stm->output[i].iotype==OUTPUT)
		{
			if(strcmp(stm->output[i].name, s1)==0) 
				return stm->output[i].connect->connectType;
		}
		else if (stm->output[i].iotype==OUTCOMSK)
		{
			if(strcmp(stm->output[i].name, s1)==0) 
				return OUTCOMSK;
		}
		else if (stm->output[i].iotype==OUTMAC)
		{
			if(strcmp(stm->output[i].name, s1)==0) 
				return OUTMAC;
		}
		else if (stm->output[i].iotype==OUTICPCON)
		{
			if(strcmp(stm->output[i].name, s1)==0) 
				return OUTICPCON;
		}
	}
  for(i=0;i<stm->numlink;i++)
  {
    if(strcmp(stm->link[i].localname, s1)==0) return LINK;
  }
  for(i=0;i<stm->numtimeout;i++)
  {
    if(strcmp(stm->timeout[i].name, s1)==0) return TIMEOUT;
  }
  if(x>=0)
  {
    if(atof(s)==0.0&&s[0]!='0')
    {
      char str1[255];
      sprintf(str1,"type not found (%s)",s);
      error(ln,str1);
    }
  }
  else
  {
    if(atoi(s)==0&&s[0]!='0')
    {
      if(getStateStringIdx(s)==0)
      {
        char str1[255];
        sprintf(str1,"type not found (%s)",s);
        error(ln,str1);
      }
    }
  }  
  return NUMBER;
}

int getValidationType(char *s)
{
  if(strcmp(s, "=")==0) return EQUAL;
  if(strcmp(s, "!=")==0) return NOT_EQUAL;
  if(strcmp(s, "<")==0) return LESS;
  if(strcmp(s, "<=")==0) return LESS_EQUAL;
  if(strcmp(s, ">")==0) return MORE;
  if(strcmp(s, ">=")==0) return MORE_EQUAL;
  return -1;

}

void getArgBody(tmpnStateMachine * stm, ARGSTRUCT *data, char arg[]) 
{
  int x;
  x=splitArg(arg,data->valstring,data->valstring2);
  data->subtype=0;
  if(data->type==NUMBER)
	{
    if(x>0)
    {
      data->idx = -1;
      data->subtype=1;
		  data->fnumber = atof(arg);
    }
    else
    {
      data->idx = -1;
      data->subtype=0;
      data->number=getStateStringIdx(arg);
		  if(data->number==0)
        data->number = atoi(arg);
    }
	}
	else if(data->type==VALUE)
	{
		if((data->idx=getValueIdx(stm,data->valstring))==-1) error(ln, "Value Does not exist");
    data->subtype=stm->value[data->idx].subtype;
	}
	else if(data->type==IBITDATA||data->type==IWORDDATA||data->type==ISHORTDATA||data->type==INCOMSK)
	{
		if((data->idx = getInputIdx(stm,arg))==-1) error(ln, "Input Does not exist");
	}
	else if (data->type==INLC)
	{
		if((data->idx = getInputIdx(stm,arg))==-1) error(ln, "Input Does not exist");
		data->subtype=1;
	}
	else if (data->type==INMAC)
	{
		if((data->idx = getInputIdx(stm,arg))==-1) error(ln, "Input Does not exist");
		if (stm->input[data->idx].macconnect->type==MAC_LONGINT||stm->input[data->idx].macconnect->type==MAC_SHORTINT||stm->input[data->idx].macconnect->type==MAC_SHORTUINT)
			data->subtype=0;
		else
			data->subtype=1;
	}
	else if (data->type==INICPCON)
	{
		if((data->idx = getInputIdx(stm,arg))==-1) error(ln, "Input Does not exist");
		data->subtype=0;
	}
	else if(data->type==OBITDATA||data->type==OWORDDATA||data->type==OSHORTDATA)
	{
		if((data->idx = getOutputIdx(stm,arg))==-1) error(ln, "Output Does not exist");
	}
	else if (data->type==OUTCOMSK)
	{
		if((data->idx = getOutputIdx(stm,arg))==-1) error(ln, "Output Does not exist");
		data->subtype=1;
	}
	else if (data->type==OUTMAC)
	{
		if((data->idx = getOutputIdx(stm,arg))==-1) error(ln, "Output Does not exist");
		if (stm->output[data->idx].macconnect->type==MAC_LONGINT||stm->output[data->idx].macconnect->type==MAC_SHORTINT||stm->output[data->idx].macconnect->type==MAC_SHORTUINT)
			data->subtype=0;
		else
			data->subtype=1;
	}
	else if (data->type==OUTICPCON)
	{
		if((data->idx = getOutputIdx(stm,arg))==-1) error(ln, "Output Does not exist");
		data->subtype=0;
	}
	else if (data->type == LINK)
	{
		//TODO is this not already done by splitArg
    strcpy(data->valstring,arg);
		data->number = atoi(arg);
	}
	else if (data->type == TIMEOUT)
	{
		data->idx = getTimeoutIdx(stm,arg);
	}                        
	else
		error(ln,"testtype does not exist");
}

void setArgValueFloat(tmpnStateMachineValue *val, char *valstring2, float value)
{
 	switch (val->type)
	{
  case VALUE:
	case CONSTANT:
		val->fdata=value;
		break;
	case LINKVALUE:
    if(val->linkvalue==NULL)
    {
      val->fdata=value;
    }
    else
    {
      setArgValueFloat(val->linkvalue,valstring2,value);
    }
		break;
  case TABLE:
		{
			int i,maxf;
			tmpnStateMachineTable *tab;
			tab = val->table;
			if(!strcmp(valstring2,"newtablesize"))  
			{
				tab->newtablesize=value; 
				return;
			}
			if(!strcmp(valstring2,"topsearchwidth")){
				tab->topsearchwidth = value;
				return; 
			}
			maxf=tab->newtablesize;
			//if tablesize has changed
			if(tab->curtablesize!=maxf)
			{
				tab->curtablesize=maxf;
				tab->maxidx=0; 
				tab->sum=0;
				tab->fsum=0.0;
				for(i=0;i<tab->maxsize;i++)
				{
					tab->item[i]=0;
					tab->fitem[i]=0.0;
				}
				tab->item[0]=0;
				tab->fitem[0]=0;
				tab->sumcnt=0;
				tab->topidx=0;
				tab->topval=0.0;
				tab->min=999999999;
				tab->max=-999999999;
				tab->fmin=999999999.0;
				tab->fmax=-999999999.0;
			}
			if(tab->maxidx>=maxf) tab->maxidx=0; 
			if(tab->filter==1)
			{
				tab->fsum-=tab->fitem[tab->maxidx];
				tab->fitem[tab->maxidx++]=value;
				tab->fsum+=value;
				tab->sumcnt++;
				if(tab->sumcnt>maxf) tab->sumcnt=maxf;
				val->fdata = tab->fsum/tab->sumcnt;
				//      tab->fmin*=0.9999;
				//      tab->fmax*=0.9999;
				if(value<tab->fmin) tab->fmin=value;
				if(value>tab->fmax) tab->fmax=value;
			}
			else
			{
				tab->fitem[tab->maxidx++]=value;
				val->fdata=value;
				//      tab->fmin*=0.9999;
				//      tab->fmax*=0.9999;
				if(value<tab->fmin) tab->fmin=value;
				if(value>tab->fmax) tab->fmax=value;
			}
		}
		break;
  case PATHHANDLE:
		if(!strcmp(valstring2,"mode"))  
		{ 
			val->path->key.mode=value; 
		}
		else if(!strcmp(valstring2,"type"))
		{
			val->path->key.type=value; 
		}
		else if(!strcmp(valstring2,"state"))
		{
			val->path->state=value; 
		}
		break;
  case FRAME:
		if(!strcmp(valstring2,"x"))  
    { 
      val->frame->x=value; 
    }
    else if(!strcmp(valstring2,"y"))
    {
      val->frame->y=value; 
    }
    else if(!strcmp(valstring2,"z"))
    {
      val->frame->z=value; 
    }
    else if(!strcmp(valstring2,"v"))
    {
      val->frame->v=value; 
    }
    else if(!strcmp(valstring2,"w"))
    {
      val->frame->w=value; 
    }
    else if(!strcmp(valstring2,"u"))
    {
      val->frame->u=value; 
    }
		break;
	case PATTERN:
		if(!strcmp(valstring2,"idx"))
    {
      val->data=value;
      val->frame=&val->pattern->item[val->data].wcp;
    }
		break;
	case CPPATTERN:
		if(val->cppattern != NULL)
    {
      if(!strcmp(valstring2,"layeridx"))
      {
        val->data=value;
        val->cppattern->selectedItem = val->data;
      }
      else if(!strcmp(valstring2,"pppidx"))
      {
        val->data=value;
        val->cppattern->selectedPPP = val->data;
      }
      else
        printf("Unknown CPPattern subcommand: '%s'\n", valstring2);
    }
    else
    {
      char logstr[256];
      sprintf(logstr,"CP Pattern '%s' does not exist.", val->name);
      printf("%s\n",logstr);
      logMsg(logstr);
      exit(1);
    }
		break;
  }
}

void setArgFloat(tmpnStateMachine * stm, ARGSTRUCT *arg, float value)
{
  switch(arg->type)
	{
	case NUMBER:
		arg->number=value;
		break;
	case VALUE:
		setArgValueFloat(&stm->value[arg->idx],arg->valstring2,value);
		break;
	case IBITDATA:
	case IWORDDATA:
	case ISHORTDATA:
		setConnectValueInt(stm->input[arg->idx].connect,value);
		break;
	case OBITDATA:
	case OWORDDATA:
	case OSHORTDATA:
		setConnectValueInt(stm->output[arg->idx].connect,value);
		break;
	case TIMEOUT:
		stm->timeout[arg->idx].timeout=value;
		break;
	case OUTCOMSK:
		stm->output[arg->idx].comskconnect->fdata=value;
		break;
	case OUTMAC:
		if (!stm->output[arg->idx].macconnect->userchange)
		{
			stm->output[arg->idx].macconnect->data=value;
			stm->output[arg->idx].macconnect->fdata=value;
			stm->output[arg->idx].macconnect->userchange=1;
		}
		break;
	case OUTICPCON:
		{
			unsigned int tmpudata;
			tmpudata=*(stm->output[arg->idx].icpconnect->udata);
			tmpudata&=~(1<<stm->output[arg->idx].icpconnect->bitpos);
			tmpudata|=(((int)value)<<stm->output[arg->idx].icpconnect->bitpos);
			*(stm->output[arg->idx].icpconnect->udata)=tmpudata;
			break;
		}
	default:
		break;
	}
}

void setArgValueInt(tmpnStateMachineValue *val, char *valstring2, int value)
{
 	switch (val->type)
	{
	case VALUE:
	case CONSTANT:
		val->data=value;
		break;
	case LINKVALUE:
		if(val->linkvalue==NULL)
    {
      val->data=value;
    }
    else
    {
      setArgValueInt(val->linkvalue,valstring2,value);
    }
		break;
  case TABLE:
		{
			float fdata;
			int i,maxf;
			tmpnStateMachineTable *tab;
			tab = val->table;      
			if(!strcmp(valstring2,"newtablesize"))  
			{ 
				tab->newtablesize=value; 
				return; 
			}
			if(!strcmp(valstring2,"topsearchwidth")){
				tab->topsearchwidth = value;
				return; 
			}
			maxf=tab->newtablesize;
			//if tablesize has changed
			if(tab->curtablesize!=maxf)
			{
				tab->curtablesize=maxf;
				tab->maxidx=0; 
				tab->sum=0;
				tab->fsum=0.0;
				for(i=0;i<tab->maxsize;i++)
				{
					tab->item[i]=0;
					tab->fitem[i]=0.0;
				}
				tab->item[0]=0;
				tab->fitem[0]=0;
				tab->sumcnt=0;
				tab->topidx=0;
				tab->topval=0.0;
				tab->min=999999999;
				tab->max=-999999999;
				tab->fmin=999999999.0;
				tab->fmax=-999999999.0;
			}
			if(tab->maxidx>=maxf) tab->maxidx=0; 
			if(tab->filter==1)
			{
				tab->sum-=tab->item[tab->maxidx];
				tab->item[tab->maxidx++]=value;
				tab->sum+=value;
				tab->sumcnt++;
				if(tab->sumcnt>maxf) tab->sumcnt=maxf;
				fdata = tab->sum/tab->sumcnt;
				if(fdata>=0) 
					val->data = (int)(fdata+0.5);
				else
					val->data = (int)(fdata-0.5);
				//      tab->min=tab->min*9999/10000;
				//      tab->max=tab->max*9999/10000;
				if(value<tab->min) tab->min=value;
				if(value>tab->max) tab->max=value;
			}
			else
			{
				tab->item[tab->maxidx++]=value;
				val->data=value;
				//      tab->min=tab->min*9999/10000;
				//      tab->max=tab->max*9999/10000;
				if(value<tab->min) tab->min=value;
				if(value>tab->max) tab->max=value;
			}
		}
		break;
  case PATHHANDLE:
		if(!strcmp(valstring2,"mode"))  
    { 
      val->path->key.mode=value; 
    }
    else if(!strcmp(valstring2,"type"))
    {
      val->path->key.type=value; 
    }
    else if(!strcmp(valstring2,"state"))
    {
      val->path->state=value; 
    }
		break;
  case FRAME:
		if(!strcmp(valstring2,"x"))  
    { 
      val->frame->x=value; 
    }
    else if(!strcmp(valstring2,"y"))
    {
      val->frame->y=value; 
    }
    else if(!strcmp(valstring2,"z"))
    {
      val->frame->z=value; 
    }
    else if(!strcmp(valstring2,"v"))
    {
      val->frame->v=value; 
    }
    else if(!strcmp(valstring2,"w"))
    {
      val->frame->w=value; 
    }
    else if(!strcmp(valstring2,"u"))
    {
      val->frame->u=value; 
    }
		break;
  case PATTERN:
		if(!strcmp(valstring2,"idx"))
    {
      val->data=value;
      val->frame=&val->pattern->item[val->data].wcp;
    }
		break;
  case CPPATTERN:
		if(val->cppattern != NULL)
    {
      if(!strcmp(valstring2,"layeridx"))
      {
        val->data=value;
        val->cppattern->selectedItem = val->data;
      }
      else if(!strcmp(valstring2,"pppidx"))
      {
        val->data=value;
        val->cppattern->selectedPPP = val->data;
      }
      else
        printf("Unknown CPPattern subcommand: '%s'\n", valstring2);
    }
    else
    {
      char logstr[256];
      sprintf(logstr,"CP Pattern '%s' does not exist.", val->name);
      printf("%s\n",logstr);
      logMsg(logstr);
      exit(1);
    }
		break;
  }
}

void setArgInt(tmpnStateMachine * stm, ARGSTRUCT *arg, int value)
{
  switch(arg->type)
	{
	case NUMBER:
		arg->number=value;
		break;
	case VALUE:
		setArgValueInt(&stm->value[arg->idx],arg->valstring2,value);
		break;
	case IBITDATA:
	case IWORDDATA:
	case ISHORTDATA:
		setConnectValueInt(stm->input[arg->idx].connect,value);
		break;
	case OBITDATA:
	case OWORDDATA:
	case OSHORTDATA:
		setConnectValueInt(stm->output[arg->idx].connect,value);
		break;
	case TIMEOUT:
		stm->timeout[arg->idx].timeout=value;
		break;
	case OUTCOMSK:
		stm->output[arg->idx].comskconnect->fdata=value;
		break;
	case OUTMAC:
		if (!stm->output[arg->idx].macconnect->userchange)
		{
			stm->output[arg->idx].macconnect->data=value;
			stm->output[arg->idx].macconnect->fdata=value;
			stm->output[arg->idx].macconnect->userchange=1;
		}
		break;
	case OUTICPCON:
		{
			unsigned int tmpudata;
			tmpudata=*(stm->output[arg->idx].icpconnect->udata);
			tmpudata&=~(1<<stm->output[arg->idx].icpconnect->bitpos);
			tmpudata|=(((int)value)<<stm->output[arg->idx].icpconnect->bitpos);
			*(stm->output[arg->idx].icpconnect->udata)=tmpudata;
			break;
		}
	default:
		break;
	}
}

float getArgValueFloat(tmpnStateMachineValue *val, char *val2, int *argSubType)
{
  float ret=0;
	switch(val->type)
	{
	case VALUE:
	case CONSTANT:
		if(val->subtype==0)
      ret = val->data;
    else
      ret = val->fdata;
		break;
  case LINKVALUE:
    if(val->linkvalue==NULL)
    {
			if (val->remote!=NULL&&val->remote->remotehost!=NULL)
			{
				//TODO nonredundant subtype
				val->subtype=val->remote->subtype;
				*argSubType=val->subtype;
				if(val->subtype==0)
					ret = val->remote->data;
				else
					ret = val->remote->fdata;
			}
			else 
			{
				if(val->subtype==0)
					ret = val->data;
				else
					ret = val->fdata;
			}
    }
    else
    {
      ret = getArgValueFloat(val->linkvalue,val2,argSubType);
    }
		break;
  case TABLE:
    if(!strcmp(val2,"maxidx"))
    {
      ret = val->table->maxidx;
    }
    else if(!strcmp(val2,"size"))
    {
      ret = val->table->curtablesize;
    }
    else if (!strcmp(val2,"topidx"))
    {
      findTopInTable(val);
      ret = val->table->topidx;
    }
    else if(!strcmp(val2,"topval"))
    {
      ret = val->table->topval;
    }
    else
    {
      if(val->subtype==0)
        ret = val->data;
      else
        ret = val->fdata;
    }
		break;
  case PATHHANDLE:
		if(!strcmp(val2,"mode"))
    {
      ret = val->path->key.mode;
    }
    else if(!strcmp(val2,"type"))
    {
      ret = val->path->key.type;
    }
    else if(!strcmp(val2,"state"))
    {
      ret = val->path->state;
    }
		break;
  case FRAME:
		if(!strcmp(val2,"x"))
    {
      ret = val->frame->x;
    }
    else if(!strcmp(val2,"y"))
    {
      ret = val->frame->y;
    }
    else if(!strcmp(val2,"z"))
    {
      ret = val->frame->z;
    }
    else if(!strcmp(val2,"v"))
    {
      ret = val->frame->v;
    }
    else if(!strcmp(val2,"w"))
    {
      ret = val->frame->w;
    }
    else if(!strcmp(val2,"u"))
    {
      ret = val->frame->u;
    }
		break;
  case ITEM:
		if(!strcmp(val2,"sy"))
    {
      ret = val->item->sy;
    }
    else if(!strcmp(val2,"gy"))
    {
      ret = val->item->gy;
    }
    else if(!strcmp(val2,"my"))
    {
      ret = val->item->my;
    }
		else if(!strcmp(val2,"gx"))
    {
      ret = val->item->gx;
    }
		else if(!strcmp(val2,"dy"))
    {
      ret = val->item->dim.y;
    }
		else if(!strcmp(val2,"dx"))
    {
      ret = val->item->dim.x;
    }
		else if(!strcmp(val2,"dz"))
    {
      ret = val->item->dim.z;
    }
    else if(!strcmp(val2,"weight"))
    {
      ret = val->item->weight;
    }
		break;
  case PATTERN:
		if(!strcmp(val2,"layer"))
    {
      ret = val->pattern->item[val->data].layer;
    }
    else if(!strcmp(val2,"wcp.x"))
    {
      ret = val->pattern->item[val->data].wcp.x;
    }
    else if(!strcmp(val2,"wcp.y"))
    {
      ret = val->pattern->item[val->data].wcp.y;
    }
    else if(!strcmp(val2,"wcp.z"))
    {
      ret = val->pattern->item[val->data].wcp.z;
    }
    else if(!strcmp(val2,"wcp.v"))
    {
      ret = val->pattern->item[val->data].wcp.v;
    }
    else if(!strcmp(val2,"wcp.w"))
    {
      ret = val->pattern->item[val->data].wcp.w;
    }
    else if(!strcmp(val2,"wcp.u"))
    {
      ret = val->pattern->item[val->data].wcp.u;
    }
		break;
  case CPPATTERN:
    if(val->cppattern == NULL)
    {
      char logstr[256];
      sprintf(logstr,"CP Pattern '%s' does not exist.", val->name);
      printf("%s\n",logstr);
      logMsg(logstr);
      exit(1);
    }
    if(!strcmp(val2,"maxlayers"))
    {
      ret = val->cppattern->maxidx;
    }
    else if(!strcmp(val2,"maxpush"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
        ret = val->cppattern->items[val->cppattern->selectedItem].maxpush;
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"gettime"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
        ret = val->cppattern->items[val->cppattern->selectedItem].gettime;
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.gettime: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"ppp"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].ppps[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.ppp: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush  - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"pacc"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].paccs[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.pacc: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush  - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"pspeed"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].pspeeds[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.pspeed: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush  - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else
      printf("Unknown CPPattern subcommand: '%s'\n", val2);
		break;
  }
  return ret;
}

//return *((int*)arg->data);
float getArgFloat(tmpnStateMachine * stm, ARGSTRUCT *arg)
{
  float ret=0;
  switch(arg->type)
	{
	case NUMBER:
		if (arg->subtype==0)
			ret = arg->number;
		else
			ret = arg->fnumber;
		break;
	case VALUE:
		ret = getArgValueFloat(&stm->value[arg->idx],arg->valstring2,&arg->subtype);
		break;
	case IBITDATA:
		case IWORDDATA:
	case ISHORTDATA:
		ret = getConnectValueInt(stm->input[arg->idx].connect);
		break;
	case OBITDATA:
	case OWORDDATA:
	case OSHORTDATA:
		ret = getConnectValueInt(stm->output[arg->idx].connect);
		break;
	case TIMEOUT:
		ret = stm->timeout[arg->idx].timeout;
		break;
	case INLC:
		ret = stm->input[arg->idx].loadcellconnect->fdata;
		break;
	case OUTCOMSK:
		ret = stm->output[arg->idx].comskconnect->fdata;
		break;
	case INCOMSK:
		ret = stm->input[arg->idx].comskconnect->fdata;
		break;
	case OUTMAC:
		{
			macConnect *mccon;
			mccon=stm->output[arg->idx].macconnect;
			if (mccon->type==MAC_LONGINT||mccon->type==MAC_SHORTINT||mccon->type==MAC_SHORTUINT)
				ret = (float)mccon->data;
			else
				ret = mccon->fdata;
		}
		break;
	case INMAC:
		{
			macConnect *mccon;
			mccon=stm->input[arg->idx].macconnect;
			if (mccon->type==MAC_LONGINT||mccon->type==MAC_SHORTINT||mccon->type==MAC_SHORTUINT)
				ret = (float)mccon->data;
			else
				ret = mccon->fdata;
		}
		break;
	case INICPCON:
		ret = 1&((*stm->input[arg->idx].icpconnect->udata)>>stm->input[arg->idx].icpconnect->bitpos);
		break;
	case OUTICPCON:
		ret = 1&((*stm->output[arg->idx].icpconnect->udata)>>stm->output[arg->idx].icpconnect->bitpos);
		break;
	default:
		break;
	}
  return ret;
}

int getArgSubType(tmpnStateMachine * stm, ARGSTRUCT *arg)
{
  int ret=-1; //subtype 0=int, 1=float
  if (arg->type==VALUE)
	{
		switch (stm->value[arg->idx].type)
		{
		case LINKVALUE:
			if(stm->value[arg->idx].linkvalue!=NULL)
	    {
				int sidx=-1,vidx=-1;
				ARGSTRUCT temp;
				temp.type=stm->value[arg->idx].linkvalue->type;
				strncpy(temp.valstring,arg->valstring,255);
				strncpy(temp.valstring2,arg->valstring2,255);
				sidx =  findSTMIdx(stm, stm->value[arg->idx].link);
				if(sidx==-1)
					sidx = getMachineIdx(stm->value[arg->idx].link);
				if(sidx!=-1)
				{
					vidx = getValueIdx(&tworkcell->statemachines.statemachine[sidx], stm->value[arg->idx].linkname);
					temp.idx=vidx;
					ret=getArgSubType(&tworkcell->statemachines.statemachine[sidx],&temp);
				}
				if (ret==-1)
				{
					ret = stm->value[arg->idx].subtype;
				}
			}
			break;
		case TABLE:
			if(!strcmp(arg->valstring2,"maxidx"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"size"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"topidx"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"topval"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"newtablesize"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"topsearchwidth"))
				ret = 0;
			break;
		case PATHHANDLE:
			if(!strcmp(arg->valstring2,"mode"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"type"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"state"))
				ret = 0;
			break;
		case FRAME:
			if(!strcmp(arg->valstring2,"x"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"y"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"z"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"v"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"w"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"u"))
				ret = 1;
			break;
		case ITEM:
			if(!strcmp(arg->valstring2,"sy"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"gy"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"my"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"gx"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"dy"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"dx"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"dz"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"weight"))
				ret = 1;
			break;
		case PATTERN:
			if(!strcmp(arg->valstring2,"layer"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"idx"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"wcp.x"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"wcp.y"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"wcp.z"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"wcp.v"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"wcp.w"))
				ret = 1;
			else if(!strcmp(arg->valstring2,"wcp.u"))
				ret = 1;
			break;
		case CPPATTERN:
			if(!strcmp(arg->valstring2,"maxlayers"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"maxpush"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"gettime"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"ppp"))
				ret = 0;
      else if(!strcmp(arg->valstring2,"pacc"))
				ret = 0;
      else if(!strcmp(arg->valstring2,"pspeed"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"layeridx"))
				ret = 0;
			else if(!strcmp(arg->valstring2,"pppidx"))
				ret = 0;
			break;
		}
	}
	return ret;
}

int getArgValueInt(tmpnStateMachineValue *val, char *val2, int *argSubType)
{
  int ret=0;
	switch(val->type)
	{
  case VALUE:
	case CONSTANT:
		if(val->subtype==0)
      ret = val->data;
    else
      ret = val->fdata;
		break;
  case LINKVALUE:
    if(val->linkvalue==NULL)
    {
			if (val->remote!=NULL&&val->remote->remotehost!=NULL)
			{
				//TODO nonredundant subtype
				val->subtype=val->remote->subtype;
				*argSubType=val->subtype;
				if(val->subtype==0)
					ret = val->remote->data;
				else
					ret = val->remote->fdata;
			}
			else 
			{
				if(val->subtype==0)
					ret = val->data;
				else
					ret = val->fdata;
			}
    }
    else
    {
      ret = getArgValueInt(val->linkvalue,val2,argSubType);
    }
		break;
  case TABLE:
		if(!strcmp(val2,"maxidx"))
    {
      ret = val->table->maxidx;
    }
    else if(!strcmp(val2,"size"))
    {
      ret = val->table->curtablesize;
    }
    else if(!strcmp(val2,"topidx"))
    {
      findTopInTable(val);
      ret = val->table->topidx;
    }
    else if(!strcmp(val2,"topval"))
    {
      ret = val->table->topval;
    }
    else
    {
      if(val->subtype==0)
        ret = val->data;
      else
        ret = val->fdata;
    }
		break;
	case PATHHANDLE:
		if(!strcmp(val2,"mode"))
    {
      ret = val->path->key.mode;
    }
    else if(!strcmp(val2,"type"))
    {
      ret = val->path->key.type;
    }
    else if(!strcmp(val2,"state"))
    {
      ret = val->path->state;
    }
		break;
  case FRAME:
    if(!strcmp(val2,"x"))
    {
      ret = val->frame->x;
    }
    else if(!strcmp(val2,"y"))
    {
      ret = val->frame->y;
    }
    else if(!strcmp(val2,"z"))
    {
      ret = val->frame->z;
    }
    else if(!strcmp(val2,"v"))
    {
      ret = val->frame->v;
    }
    else if(!strcmp(val2,"w"))
    {
      ret = val->frame->w;
    }
    else if(!strcmp(val2,"u"))
    {
      ret = val->frame->u;
    }
		break;
  case ITEM:
    if(!strcmp(val2,"sy"))
    {
      ret = val->item->sy;
    }
    else if(!strcmp(val2,"gy"))
    {
      ret = val->item->gy;
    }
    else if(!strcmp(val2,"my"))
    {
      ret = val->item->my;
    }
		else if(!strcmp(val2,"gx"))
    {
      ret = val->item->gx;
    }
		else if(!strcmp(val2,"dy"))
    {
      ret = val->item->dim.y;
    }
		else if(!strcmp(val2,"dx"))
    {
      ret = val->item->dim.x;
    }
		else if(!strcmp(val2,"dz"))
    {
      ret = val->item->dim.z;
    }
    else if(!strcmp(val2,"weight"))
    {
      ret = val->item->weight;
    }
		break;
  case PATTERN:
		if(!strcmp(val2,"layer"))
    {
      ret = val->pattern->item[val->data].layer;
    }
    else if(!strcmp(val2,"wcp.x"))
    {
      ret = val->pattern->item[val->data].wcp.x;
    }
    else if(!strcmp(val2,"wcp.y"))
    {
      ret = val->pattern->item[val->data].wcp.y;
    }
    else if(!strcmp(val2,"wcp.z"))
    {
      ret = val->pattern->item[val->data].wcp.z;
    }
    else if(!strcmp(val2,"wcp.v"))
    {
      ret = val->pattern->item[val->data].wcp.v;
    }
    else if(!strcmp(val2,"wcp.w"))
    {
      ret = val->pattern->item[val->data].wcp.w;
    }
    else if(!strcmp(val2,"wcp.u"))
    {
      ret = val->pattern->item[val->data].wcp.u;
    }
		break;
  case CPPATTERN:
		if(val->cppattern == NULL)
    {
      char logstr[256];
      sprintf(logstr,"CP Pattern '%s' does not exist.", val->name);
      printf("%s\n",logstr);
      logMsg(logstr);
      exit(1);
    }
    if(!strcmp(val2,"maxlayers"))
    {
      ret = val->cppattern->maxidx;
    }
    else if(!strcmp(val2,"maxpush"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
        ret = val->cppattern->items[val->cppattern->selectedItem].maxpush;
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"gettime"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
        ret = val->cppattern->items[val->cppattern->selectedItem].gettime;
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.gettime: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"ppp"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].ppps[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.ppp: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush  - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"pacc"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].paccs[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.pacc: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush  - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else if(!strcmp(val2,"pspeed"))
    {
      if(val->cppattern->selectedItem >= 0 && val->cppattern->selectedItem < val->cppattern->maxidx)
      {
        if(val->cppattern->selectedPPP >= 0 && val->cppattern->selectedPPP < val->cppattern->items[val->cppattern->selectedItem].maxpush)
          ret = val->cppattern->items[val->cppattern->selectedItem].pspeeds[val->cppattern->selectedPPP];
        else
        {
          char logstr[256];
          sprintf(logstr,"Unable to read %s.pspeed: CPPattern '%s' pppidx (%d) out of bound [0;%d]",
                  val->name, val->cppattern->name, val->cppattern->selectedPPP,
                  val->cppattern->items[val->cppattern->selectedItem].maxpush  - 1);
          printf("%s\n",logstr);
          logMsg(logstr);
          exit(1);
        }
      }
      else
      {
        char logstr[256];
        sprintf(logstr,"Unable to read %s.maxpush: CPPattern '%s' layeridx (%d) out of bound [0;%d]",
                val->name, val->cppattern->name, val->cppattern->selectedItem, val->cppattern->maxidx - 1);
        printf("%s\n",logstr);
        logMsg(logstr);
        exit(1);
      }
    }
    else
      printf("Unknown CPPattern subcommand: '%s'\n", val2);
		break;
  }
  return ret;
}

int getArgInt(tmpnStateMachine * stm, ARGSTRUCT *arg)
{
  int ret=0;
  switch(arg->type)
	{
	case NUMBER:
		if (arg->subtype==0)
			ret = arg->number;
		else
			ret = arg->fnumber;
		break;
	case VALUE:
		ret = getArgValueInt(&stm->value[arg->idx],arg->valstring2,&arg->subtype);
		break;
	case TIMEOUT:
		ret = stm->timeout[arg->idx].timeout;
		break;
	case IBITDATA:
	case IWORDDATA:
	case ISHORTDATA:
		ret = getConnectValueInt(stm->input[arg->idx].connect);
		break;
	case OBITDATA:
	case OWORDDATA:
	case OSHORTDATA:
		ret = getConnectValueInt(stm->output[arg->idx].connect);
		break;
	case INLC:
		ret = (int)stm->input[arg->idx].loadcellconnect->fdata;
		break;
	case OUTCOMSK:
 		ret = (int)stm->output[arg->idx].comskconnect->fdata;
		break;
	case INCOMSK:
		ret = (int)stm->input[arg->idx].comskconnect->fdata;
		break;
	case OUTMAC:
		{
			macConnect *mccon;
			mccon=stm->output[arg->idx].macconnect;
			if (mccon->type==MAC_LONGINT||mccon->type==MAC_SHORTINT||mccon->type==MAC_SHORTUINT)
				ret = mccon->data;
			else
				ret = (int)mccon->fdata;
		}
		break;
	case INMAC:
		{
			macConnect *mccon;
			mccon= stm->input[arg->idx].macconnect;
			if (mccon->type==MAC_LONGINT||mccon->type==MAC_SHORTINT||mccon->type==MAC_SHORTUINT)
				ret = mccon->data;
			else
				ret = (int)mccon->fdata;
		}
		break;
	case INICPCON:
		ret = 1&((*stm->input[arg->idx].icpconnect->udata)>>stm->input[arg->idx].icpconnect->bitpos);
		break;
	case OUTICPCON:
		ret = 1&((*stm->output[arg->idx].icpconnect->udata)>>stm->output[arg->idx].icpconnect->bitpos);
		break;
	default:
		break;
	}
  return ret;
}

int findTopInTable(tmpnStateMachineValue *val)
{
  tmpnStateMachineTable *table=val->table;
  if(table->topsearchwidth <= 0)
  {
    printf("Remember to set topsearchwidth before calling topidx and topval\n");
    return 0;
  }
  else
  {
    int searchCount = table->topsearchwidth;
//    printf("1. searchCount = %d\n",searchCount);
    if(searchCount > table->curtablesize)
      searchCount = table->curtablesize;
//    printf("2. searchCount = %d\n",searchCount);
    int curIdx = table->maxidx, maxIdx=0;
    float curVal, maxVal = -999999999.0;
    while(searchCount >= 0)
    {
      curIdx--;
      if(curIdx < 0) 
      {
//        printf("5.wrap %d\n",table->curtablesize);
        curIdx = table->curtablesize-1; 
      }
      if(val->subtype==0)
        curVal = table->item[curIdx];
      else
        curVal = table->fitem[curIdx];
//      printf("3.%d.%d curVal = %f\n",searchCount,curIdx,curVal);
      if(maxVal < curVal)
      {
        maxVal = curVal;
        maxIdx = curIdx;
//        printf("4. maxVal = %f, maxIdx = %d\n",maxVal,maxIdx);
      }
      searchCount--;
    }
    table->topidx = maxIdx;
    //TODO if integer is needed -> duplicate topval
    table->topval = maxVal;
//    printf("6.idx = %d top = %f\n",table->topidx,table->topval);
  }
  return 1;
}

int getFunctionBody(FILE *fp, int state, tmpnStateMachine * stm)
{
  int val, index=0;
  //int idx;
  char s[256];
  char func[256], arg1[256], arg2[128], arg3[128], arg4[128];
  int level = 0;
	int inlinelevel = 0;
	FILE *fpold[10];
	int lnold[10];
	char* fret;
  PRINTSTRUCT* print;
  SETSTRUCT* set;
  TESTSTRUCT* test;
  CALCSTRUCT* calc;
	ROBOTSPEEDSTRUCT *robotspeed;
  index = stm->state[state].maxprgidx;
  while(inlinelevel>=0)
  {
    strcpy(func, "");
    strcpy(arg1, "");
    strcpy(arg2, "");
    strcpy(arg3, "");
		ln++;
    fret=fgets(s, 256, fp);
		if (fret==NULL)
		{
			inlinelevel--;
			if (inlinelevel>=0)
			{
				fp=fpold[inlinelevel];
				ln=lnold[inlinelevel];
			}
			continue;
		}
    if(strlen(s)>=255)
      error(ln, "length exceed max = 256");

    sscanf(s," %s", func);

    if(strncmp(func, ";", 1)==0)
    {
      //comment
    }
    else if(strncmp(func, "TEST", 4)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4) error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = TEST;
      stm->state[state].prg[index].data = malloc(sizeof(TESTSTRUCT));
      level++;
      stm->state[state].prg[index].level = level;
      
      test = (TESTSTRUCT*)stm->state[state].prg[index].data;
      test->test.type = getCmpType(stm, arg1,ln);
      test->validation = getValidationType(arg2);
			if (test->validation == -1) error(ln, "unknown test.\n");
			if(test->test.type==LINK) test->cmp.type = LINK;
			else test->cmp.type = getCmpType(stm, arg3,ln);
      getArgBody(stm,&test->test,arg1); 
      getArgBody(stm,&test->cmp,arg3);
      if(test->test.type==LINK)
      {
				if((test->test.idx=getLinkIdx(stm,arg1))==-1) error(ln, "Link Does not exist");
      }
      index++;
    }
    else if(strncmp(func, "OR", 2)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4) error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = OR;
      stm->state[state].prg[index].data = malloc(sizeof(TESTSTRUCT));
      stm->state[state].prg[index].level = level;
      
      test = (TESTSTRUCT*)stm->state[state].prg[index].data;
      test->test.type = getCmpType(stm, arg1,ln);
      test->validation = getValidationType(arg2);
			if (test->validation == -1) error(ln, "unknown test.\n");
			if(test->test.type==LINK) test->cmp.type = LINK;
			else test->cmp.type = getCmpType(stm, arg3,ln);
      getArgBody(stm,&test->test,arg1); 
      getArgBody(stm,&test->cmp,arg3); 
      if(test->test.type==LINK)
      {
   		  if((test->test.idx=getLinkIdx(stm,arg1))==-1) error(ln, "Link Does not exist");
      }
      index++;
    }
    else if(strncmp(func, "AND", 3)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4) error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = AND;
      stm->state[state].prg[index].data = malloc(sizeof(TESTSTRUCT));
      stm->state[state].prg[index].level = level;
      
      test = (TESTSTRUCT*)stm->state[state].prg[index].data;
      test->test.type = getCmpType(stm, arg1,ln);
      test->validation = getValidationType(arg2);
			if (test->validation == -1) error(ln, "unknown test.\n");
			if(test->test.type==LINK) test->cmp.type = LINK;
			else test->cmp.type = getCmpType(stm, arg3,ln);
      getArgBody(stm,&test->test,arg1); 
      getArgBody(stm,&test->cmp,arg3); 
      if(test->test.type==LINK)
      {
   		  if((test->test.idx=getLinkIdx(stm,arg1))==-1) error(ln, "Link Does not exist");
      }
      index++;
    }
		else if(strncmp(func, "ELSETEST", 8)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4) error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = ELSETEST;
      stm->state[state].prg[index].data = malloc(sizeof(TESTSTRUCT));
      stm->state[state].prg[index].level = level;
      
      test = (TESTSTRUCT*)stm->state[state].prg[index].data;
      test->test.type = getCmpType(stm, arg1,ln);
      test->validation = getValidationType(arg2);
			if (test->validation == -1) error(ln, "unknown test.\n");
			if(test->test.type==LINK) test->cmp.type = LINK;
			else test->cmp.type = getCmpType(stm, arg3,ln);
      getArgBody(stm,&test->test,arg1);
      getArgBody(stm,&test->cmp,arg3);
      if(test->test.type==LINK)
      {
				if((test->test.idx=getLinkIdx(stm,arg1))==-1) error(ln, "Link Does not exist");
      }
      index++;
    }
    else if(strncmp(func, "EXEC", 4)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s", func, arg1);
      if(val != 2)
        error(ln, "EXEC wrong number of arguments.\n");
      stm->state[state].prg[index].type = EXEC;
      stm->state[state].prg[index].data = malloc(sizeof(EXECSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((EXECSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      index++;
    }
    else if(strncmp(func, "LOAD", 4)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg1, arg2, arg3);
      if(val != 4)
        error(ln, "LOAD wrong number of arguments.\n");
      stm->state[state].prg[index].type = LOAD;
      stm->state[state].prg[index].data = malloc(sizeof(LOADSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((LOADSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((LOADSTRUCT*)stm->state[state].prg[index].data)->src1, arg2);
      strcpy(((LOADSTRUCT*)stm->state[state].prg[index].data)->src2, arg3);
      index++;
    }
    else if(strncmp(func, "SETFRAME", 8)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SETFRAME wrong number of arguments.\n");
      stm->state[state].prg[index].type = SETFRAME;
      stm->state[state].prg[index].data = malloc(sizeof(SETFRAMESTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETFRAMESTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((SETFRAMESTRUCT*)stm->state[state].prg[index].data)->src, arg2);
      index++;
    }
		else if(strncmp(func, "SETITEM", 7)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SETITEM wrong number of arguments.\n");
      stm->state[state].prg[index].type = SETITEM;
      stm->state[state].prg[index].data = malloc(sizeof(SETITEMSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETITEMSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((SETITEMSTRUCT*)stm->state[state].prg[index].data)->src, arg2);
      index++;
    }
		else if(strncmp(func, "ROBOTSPEED", 10)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s", func, arg1);
      if(val != 2)
        error(ln, "ROBOTSPEED wrong number of arguments.\n");
      stm->state[state].prg[index].type = ROBOTSPEED;
      stm->state[state].prg[index].data = malloc(sizeof(ROBOTSPEEDSTRUCT));
      stm->state[state].prg[index].level = level;
			robotspeed = (ROBOTSPEEDSTRUCT*)stm->state[state].prg[index].data;
			
      robotspeed->src.type = getCmpType(stm, arg1,ln);
      getArgBody(stm,&robotspeed->src,arg1);
   
			if(robotspeed->src.type!=NUMBER
				 &&robotspeed->src.type!=IBITDATA
				 &&robotspeed->src.type!=IWORDDATA
				 &&robotspeed->src.type!=ISHORTDATA
				 &&robotspeed->src.type!=OBITDATA
				 &&robotspeed->src.type!=OWORDDATA
				 &&robotspeed->src.type!=OSHORTDATA
				 &&robotspeed->src.type!=INCOMSK
				 &&robotspeed->src.type!=INMAC
				 &&robotspeed->src.type!=INLC
				 &&robotspeed->src.type!=INICPCON
				 &&robotspeed->src.type!=OUTCOMSK
				 &&robotspeed->src.type!=OUTMAC
				 &&robotspeed->src.type!=OUTICPCON
				 &&robotspeed->src.type!=TIMEOUT
				 &&robotspeed->src.type!=VALUE)
				error(ln, "srctype not found");
			
			index++;
    }
		else if(strncmp(func, "SETPATTERN", 10)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SETPATTERN wrong number of arguments.\n");
      stm->state[state].prg[index].type = SETPATTERN;
      stm->state[state].prg[index].data = malloc(sizeof(SETPATTERNSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETPATTERNSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((SETPATTERNSTRUCT*)stm->state[state].prg[index].data)->src, arg2);
      index++;
    }
		else if(strncmp(func, "SETCPPATTERN", 12)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SETCPPATTERN wrong number of arguments.\n");
      stm->state[state].prg[index].type = SETCPPATTERN;
      stm->state[state].prg[index].data = malloc(sizeof(SETCPPATTERNSTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETCPPATTERNSTRUCT*)stm->state[state].prg[index].data)->dest, arg1);
      strcpy(((SETCPPATTERNSTRUCT*)stm->state[state].prg[index].data)->src, arg2);
      index++;
    }
    else if(strncmp(func, "SETSTATE", 8)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s", func, arg1);
      if(val != 2)
        error(ln, "SETSTATE wrong number of arguments.\n");
      stm->state[state].prg[index].type = SETSTATE;
      stm->state[state].prg[index].data = malloc(sizeof(SETSTATESTRUCT));
      stm->state[state].prg[index].level = level;
      strcpy(((SETSTATESTRUCT*)stm->state[state].prg[index].data)->name, arg1);
      index++;
    }
    else if(strncmp(func, "PRINT", 5)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val < 2 || val > 3)
        error(ln, "PRINT wrong number of arguments.\n");
      stm->state[state].prg[index].type = PRINT;
      stm->state[state].prg[index].data = malloc(sizeof(PRINTSTRUCT));
      stm->state[state].prg[index].level = level;

      print = (PRINTSTRUCT*)stm->state[state].prg[index].data;

      print->arg.type = getCmpType(stm, arg1,ln);
      getArgBody(stm,&print->arg,arg1);
      if(val==2) print->newline=TRUE; 
      else print->newline=FALSE; 
      index++;
    }
    else if(strncmp(func, "SET", 3)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val != 3)
        error(ln, "SET wrong number of arguments.\n");
			
      stm->state[state].prg[index].type = SET;
      stm->state[state].prg[index].data = malloc(sizeof(SETSTRUCT));
      stm->state[state].prg[index].level = level;

      set = (SETSTRUCT*)stm->state[state].prg[index].data;

      set->dest.type = getCmpType(stm, arg1,ln);
      set->src.type = getCmpType(stm, arg2,ln);

      getArgBody(stm,&set->dest,arg1); 
        
 
      if(set->dest.type!=OBITDATA
				 &&set->dest.type!=OWORDDATA
				 &&set->dest.type!=OSHORTDATA
				 &&set->dest.type!=OUTCOMSK
				 &&set->dest.type!=OUTMAC
				 &&set->dest.type!=OUTICPCON
				 &&set->dest.type!=TIMEOUT
				 &&set->dest.type!=VALUE)
				error(ln, "desttype not found");

      getArgBody(stm,&set->src,arg2); 
      
      if(set->src.type!=NUMBER
				 &&set->src.type!=IBITDATA
				 &&set->src.type!=IWORDDATA
				 &&set->src.type!=ISHORTDATA
				 &&set->src.type!=OBITDATA
				 &&set->src.type!=OWORDDATA
				 &&set->src.type!=OSHORTDATA
				 &&set->src.type!=INCOMSK
				 &&set->src.type!=INMAC
				 &&set->src.type!=INLC
				 &&set->src.type!=INICPCON
				 &&set->src.type!=OUTCOMSK
				 &&set->src.type!=OUTMAC
				 &&set->src.type!=OUTICPCON
				 &&set->src.type!=TIMEOUT
				 &&set->src.type!=VALUE)
				error(ln, "srctype not found");
      
      index++;
    }
    else if(strncmp(func, "TIMEOUT", 7)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
//      val = sscanf(s,"%d %s %s %s", &idx, func, arg1, arg2);
//      if(val != 4)
      val = sscanf(s,"%s %s %s", func, arg1, arg2);
      if(val<2||val>3)
        error(ln, "TIMEOUT wrong number of arguments.\n");
//      if(idx != index)
//        error(ln, "index error.\n");

      stm->state[state].prg[index].type = TIMEOUT;
      stm->state[state].prg[index].data = malloc(sizeof(TIMEOUTSTRUCT));
      stm->state[state].prg[index].level = level;

      ((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->idx = getTimeoutIdx(stm, arg1);
	      if(((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Timeout Does not exist");


      if(val==3)
      {
        strcpy(((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->statename,arg2);
//        ((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->number = getMachineStateIdx(stm->name,arg2);
//	      if(((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->number==-1) error(ln, "TIMEOUT State does not exist");
      }
      else
      {
        strcpy(((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->statename,"");
        ((TIMEOUTSTRUCT*)stm->state[state].prg[index].data)->number = -1;
      }

      index++;

    }
    else if(strncmp(func, "CALC", 4)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s = %s %s %s", func, arg1, arg2, arg3, arg4);
      if(val != 5)
        error(ln, "DIV wrong number of arguments.\n");
      stm->state[state].prg[index].type = CALC;
      stm->state[state].prg[index].data = malloc(sizeof(CALCSTRUCT));
      calc = (CALCSTRUCT*)stm->state[state].prg[index].data;
      calc->dest.type = getCmpType(stm, arg1,ln);
      calc->src1.type = getCmpType(stm, arg2,ln);
      calc->src2.type = getCmpType(stm, arg4,ln);
      if(!strcmp(arg3,"+"))
        calc->optype = ADD;
      else if(!strcmp(arg3,"-"))
        calc->optype = SUBT;
      else if(!strcmp(arg3,"/"))
        calc->optype = DIV;
      else if(!strcmp(arg3,"*"))
        calc->optype = MUL;
      else if(!strcmp(arg3,"%"))
        calc->optype = MODULO;
      else   
       error(ln, "unknown optype\n");
		
      if(calc->dest.type!=OBITDATA
				 &&calc->dest.type!=OWORDDATA
				 &&calc->dest.type!=OSHORTDATA
				 &&calc->dest.type!=OUTCOMSK
				 &&calc->dest.type!=OUTMAC
				 &&calc->dest.type!=OUTICPCON
				 &&calc->dest.type!=VALUE)
      	error(ln, "CALC desttype not found");
      
      if(calc->src1.type!=NUMBER
				 &&calc->src1.type!=VALUE
				 &&calc->src1.type!=IBITDATA
				 &&calc->src1.type!=IWORDDATA
				 &&calc->src1.type!=ISHORTDATA
				 &&calc->src1.type!=OBITDATA
				 &&calc->src1.type!=OWORDDATA
				 &&calc->src1.type!=OSHORTDATA
				 &&calc->src1.type!=INCOMSK
				 &&calc->src1.type!=INMAC
				 &&calc->src1.type!=INLC
				 &&calc->src1.type!=INICPCON
				 &&calc->src1.type!=OUTCOMSK
				 &&calc->src1.type!=OUTMAC
				 &&calc->src1.type!=OUTICPCON
				 &&calc->src1.type!=TIMEOUT)
				error(ln, "CALC src1 type not found");

      if(calc->src2.type!=NUMBER
				 &&calc->src2.type!=VALUE
				 &&calc->src2.type!=IBITDATA
				 &&calc->src2.type!=IWORDDATA
				 &&calc->src2.type!=ISHORTDATA
				 &&calc->src2.type!=OBITDATA
				 &&calc->src2.type!=OWORDDATA
				 &&calc->src2.type!=OSHORTDATA
				 &&calc->src2.type!=INCOMSK
				 &&calc->src2.type!=INMAC
				 &&calc->src2.type!=INLC
				 &&calc->src2.type!=INICPCON
				 &&calc->src2.type!=OUTCOMSK
				 &&calc->src2.type!=OUTMAC
				 &&calc->src2.type!=OUTICPCON
				 &&calc->src2.type!=TIMEOUT)
				error(ln, "CALC src2 type not found");

      getArgBody(stm,&calc->dest,arg1); 
      getArgBody(stm,&calc->src1,arg2); 
      getArgBody(stm,&calc->src2,arg4); 
      


      stm->state[state].prg[index].level = level;
      index++;
    }
    else if(strncmp(func, "DIV", 3)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg3, arg1, arg2);
      if(val != 4)
        error(ln, "DIV wrong number of arguments.\n");
    //  if(idx != index)
    //    error(ln, "index error.\n");

      stm->state[state].prg[index].type = DIV;
      stm->state[state].prg[index].data = malloc(sizeof(DIVSTRUCT));
      ((DIVSTRUCT*)stm->state[state].prg[index].data)->arg1idx = getValueIdx(stm, arg1);
      if(((DIVSTRUCT*)stm->state[state].prg[index].data)->arg1idx==-1)
          error(ln, "Value Does not exist");
      ((DIVSTRUCT*)stm->state[state].prg[index].data)->arg2idx = getValueIdx(stm, arg2);
      if(((DIVSTRUCT*)stm->state[state].prg[index].data)->arg2idx==-1) 
      {
      //= atoi(arg2);
          error(ln, "Value Does not exist");  
      }
      ((DIVSTRUCT*)stm->state[state].prg[index].data)->idx = getValueIdx(stm, arg3);
      if(((DIVSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Value Does not exist");	  
      stm->state[state].prg[index].level = level;

      index++;

    }
    else if(strncmp(func, "MUL", 3)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg3, arg1, arg2);
      if(val != 4)
        error(ln, "MUL wrong number of arguments.\n");
    //  if(idx != index)
    //    error(ln, "index error.\n");

      stm->state[state].prg[index].type = MUL;
      stm->state[state].prg[index].data = malloc(sizeof(MULSTRUCT));
      ((MULSTRUCT*)stm->state[state].prg[index].data)->arg1idx = getValueIdx(stm, arg1);
      if(((MULSTRUCT*)stm->state[state].prg[index].data)->arg1idx==-1)
          error(ln, "Value Does not exist");
      ((MULSTRUCT*)stm->state[state].prg[index].data)->arg2idx = getValueIdx(stm, arg2);
      if(((MULSTRUCT*)stm->state[state].prg[index].data)->arg2idx==-1) 
      {
      //= atoi(arg2);
          error(ln, "Value Does not exist");  
      }
      ((MULSTRUCT*)stm->state[state].prg[index].data)->idx = getValueIdx(stm, arg3);
      if(((MULSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Value Does not exist");	  
      stm->state[state].prg[index].level = level;

      index++;

    }
    else if(strncmp(func, "ADD", 3)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg3, arg2, arg1);
      if(val != 4)
        error(ln, "ADD wrong number of arguments.\n");
    //  if(idx != index)
    //    error(ln, "index error.\n");

      stm->state[state].prg[index].type = ADD;
      stm->state[state].prg[index].data = malloc(sizeof(ADDSTRUCT));
      ((ADDSTRUCT*)stm->state[state].prg[index].data)->arg1idx = getValueIdx(stm, arg1);
      if(((ADDSTRUCT*)stm->state[state].prg[index].data)->arg1idx==-1)
          error(ln, "Value Does not exist");
      ((ADDSTRUCT*)stm->state[state].prg[index].data)->arg2idx = getValueIdx(stm, arg2);
      if(((ADDSTRUCT*)stm->state[state].prg[index].data)->arg2idx==-1) 
      {
      //= atoi(arg2);
          error(ln, "Value Does not exist");  
      }
      ((ADDSTRUCT*)stm->state[state].prg[index].data)->idx = getValueIdx(stm, arg3);
      if(((ADDSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Value Does not exist");	  
      stm->state[state].prg[index].level = level;

      index++;

    }
    else if(strncmp(func, "SUBT", 4)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s %s %s %s", func, arg3, arg1, arg2);
      if(val != 4)
        error(ln, "SUBT wrong number of arguments.\n");
    //  if(idx != index)
    //    error(ln, "index error.\n");

      stm->state[state].prg[index].type = SUBT;
      stm->state[state].prg[index].data = malloc(sizeof(SUBTSTRUCT));
      ((SUBTSTRUCT*)stm->state[state].prg[index].data)->arg1idx = getValueIdx(stm, arg1);
      if(((SUBTSTRUCT*)stm->state[state].prg[index].data)->arg1idx==-1)
          error(ln, "Value Does not exist");
      ((SUBTSTRUCT*)stm->state[state].prg[index].data)->arg2idx = getValueIdx(stm, arg2);
      if(((SUBTSTRUCT*)stm->state[state].prg[index].data)->arg2idx==-1) 
      {
      //= atoi(arg2);
          error(ln, "Value Does not exist");  
      }
      ((SUBTSTRUCT*)stm->state[state].prg[index].data)->idx = getValueIdx(stm, arg3);
      if(((SUBTSTRUCT*)stm->state[state].prg[index].data)->idx==-1)
          error(ln, "Value Does not exist");	  
      stm->state[state].prg[index].level = level;

      index++;

    }
    else if(strncmp(func, "ELSE", 4)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      val = sscanf(s,"%s", func);
      if(val != 1)
        error(ln, "wrong number of arguments.\n");
      stm->state[state].prg[index].type = ELSE;
      stm->state[state].prg[index].data = malloc(sizeof(ELSESTRUCT));
      stm->state[state].prg[index].level = level;
      index++;
    }
    else if(strncmp(func, "ENDTEST", 7)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      stm->state[state].prg[index].type = ENDTEST;
      stm->state[state].prg[index].level = level;
      SetLevelJmp(&stm->state[state], index);
      level--;
      if(level < 0)
        error(ln, "TEST ENDTEST out of order.");
      index++;
    }
    else if(strncmp(func, "END", 3)==0)
    {
			stm->state[state].prg=(STMCOMMANDSTRUCT *)realloc(stm->state[state].prg,(index+1)*sizeof(STMCOMMANDSTRUCT));
      stm->state[state].prg[index].type = END;
      stm->state[state].prg[index].level = level;
      if(level != 0)
        error(ln, "TEST ENDTEST out of order.");

      stm->state[state].maxprgidx=index;
			return index;
    }
		else if(strncmp(func,"INLINE",7)==0)
		{
			FILE *fpinline;
			char name[128];
			char inlinename[128];
			sscanf(s," INLINE %s ",name);
			sprintf(inlinename,"%s/statemachine/%s",databasePath,name);
			printf("'->Inlining at level %i: %s\n",inlinelevel,inlinename);
			fpinline = fopen(inlinename,"r");
			if(fpinline==NULL){
				printf("ERROR: Load inline stm-code: cannot open file: '%s'\n", inlinename);
				exit(99);
			}
			lnold[inlinelevel] = ln;
			fpold[inlinelevel++] = fp;
			fp = fpinline;
			ln=0;
			if (inlinelevel>9)
			{
				printf("ERROR: More than 10 levels of Inline-nesting is not supported.\n");
				exit(99);
			}
		}
    else
		{
			printf("func: %s\n",func);
      error(ln, "syntax error unknown command");
		}
  }
  stm->state[state].maxprgidx=index;
  return index;
}

int connectSimulated(tmpnConnect *connect)
{
  int i,j,d;

  for(d=0;d<tworkcell->dios.maxidx;d++)
  {
    for(i=0;i<tworkcell->dios.dio[d].numOfModules;i++)
    {
      for(j=0;j<tworkcell->dios.dio[d].iotab[i].maxidx;j++)
      {
        if(connect==&tworkcell->dios.dio[d].iotab[i].connect[j])
          return tworkcell->dios.dio[d].simulate;
      }
    }
  }
  return FALSE;
}

int comskconnectSimulated(comskConnect *comskconnect)
{
  int i,j,d;	
  for(d=0;d<tworkcell->comsks.maxidx;d++)
  {
    for(i=0;i<tworkcell->comsks.comsk[d].numOfModules;i++)
    {
			for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfOutWords;j++)
      {
        if(comskconnect==&tworkcell->comsks.comsk[d].iotab[i].odata[j])
          return tworkcell->comsks.comsk[d].simulate;
      }
			for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfInWords;j++)
      {
        if(comskconnect==&tworkcell->comsks.comsk[d].iotab[i].idata[j])
          return tworkcell->comsks.comsk[d].simulate;
      }
      for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfInitWords;j++)
      {
        if(comskconnect==&tworkcell->comsks.comsk[d].iotab[i].initdata[j])
          return tworkcell->comsks.comsk[d].simulate;
      }
    }
  }
  return FALSE;
}

//*********************************************************************************
//* 
//* LEGACY 
//* 
//* if iotype=INPUT 
//* Connect1 = bit 0 input word 0
//* Connect2 = bit 1 input word 0
//* Connect3 = bit 2 input word 0
//* Connect4 = bit 3 input word 0
//* Connect5 = bit 4 input word 0
//* Connect6 = bit 5 input word 0
//* Connect7 = bit 6 input word 0
//* Connect8 = bit 7 input word 0
//* Word1 = input word 0
//* Word2 = input word 1
//* Word3 = input word 2
//* Word4 = input word 3
//* Word5 = input word 4
//* Word6 = input word 5
//* Ready1 = 
//* Tripped1 = 
//* Energized1 = 
//* if iotype=OUTPUT 
//* Connect1 = bit 0 output word 0
//* Connect2 = bit 1 output word 0
//* Connect3 = bit 2 output word 0
//* Connect4 = bit 3 output word 0
//* Connect5 = bit 4 output word 0
//* Connect6 = bit 5 output word 0
//* Connect7 = bit 6 output word 0
//* Connect8 = bit 7 output word 0
//* Word1 = output word 0
//* Word2 = output word 1
//* Word3 = output word 2
//* Word4 = output word 3
//* Word5 = output word 4
//* Word6 = output word 5
//*
//*
//* FUTURE
//* in seperate file
//* Connect(BIT,wordindex,shift,mask)
//* Connect(BIT,wordindex,shift,mask)
//* Connect(WORD,wordindex,shift,mask)
//* Connect(WORD,wordindex,shift,mask)
//*
//*********************************************************************************
static tmpnConnect dummyConnectOn = {IBITDATA,0,0,0,0xFFFF,{0},"dummyOn","dummyOn","dummyOn"};
static tmpnConnect dummyConnectOff = {IBITDATA,0,0,0,0xFFFF,{0},"dummyOff","dummyOff","dummyOff"};
static tmpnConnect dummyConnectOut = {OBITDATA,0,0,0,0xFFFF,{0},"dummyOut","dummyOut","dummyOut"};
static unsigned short dummyidataon=1;
static unsigned short dummyidataoff=0;
static unsigned short dummyodataout=0;

static int connectStatemachineAndIO(tmpnStateMachineIO *io, char *name, char *key)
{
  int i,j,d;

  strcpy(io->name,name);

  if(strcmp(key,"dummyOn")==0)
  {
    io->connect=&dummyConnectOn;
    io->connect->udata=&dummyidataon;
    return TRUE;
  }
  if(strcmp(key,"dummyOff")==0)
  {
    io->connect=&dummyConnectOff;
    io->connect->udata=&dummyidataoff;
    return TRUE;
  }
  if(strcmp(key,"dummyOut")==0)
  {
    io->connect=&dummyConnectOut;
    io->connect->udata=&dummyodataout;
    return TRUE;
  }

  for(d=0;d<tworkcell->dios.maxidx;d++)
  {
    for(i=0;i<tworkcell->dios.dio[d].numOfModules;i++)
    {
      for(j=0;j<tworkcell->dios.dio[d].iotab[i].maxidx;j++)
      {
        if(strcmp(tworkcell->dios.dio[d].iotab[i].connect[j].key,key)==0)
        {
          io->connect=&tworkcell->dios.dio[d].iotab[i].connect[j];
          if(io->iotype==INPUT)
            io->connect->udata=&tworkcell->dios.dio[d].iotab[i].idata[io->connect->wordidx];
          else
            io->connect->udata=&tworkcell->dios.dio[d].iotab[i].odata[io->connect->wordidx];
          return TRUE;
        }
      }
    }
  }
	if(io->iotype==INPUT)
		io->iotype=INCOMSK;
	else if (io->iotype==OUTPUT)
		io->iotype=OUTCOMSK;
	for(d=0;d<tworkcell->comsks.maxidx;d++)
  {
    for(i=0;i<tworkcell->comsks.comsk[d].numOfModules;i++)
    {
			if(io->iotype==INCOMSK)
			{
				for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfInWords;j++)
				{
					if(strcmp(tworkcell->comsks.comsk[d].iotab[i].idata[j].key,key)==0)
					{
						io->comskconnect=&tworkcell->comsks.comsk[d].iotab[i].idata[j];
						return TRUE;
					}
				}
			}
			else if (io->iotype==OUTCOMSK)
			{
				
				for(j=0;j<tworkcell->comsks.comsk[d].iotab[i].numOfOutWords;j++)
				{
					if(strcmp(tworkcell->comsks.comsk[d].iotab[i].odata[j].key,key)==0)
					{
						io->comskconnect=&tworkcell->comsks.comsk[d].iotab[i].odata[j];
						return TRUE;
					}
				}
      }
    }
  }
	if(io->iotype==INCOMSK)
		io->iotype=INLC;
	for(d=0;d<tworkcell->loadcells.maxidx;d++)
  {
    for(i=0;i<tworkcell->loadcells.loadcell[d].numOfModules;i++)
    {
			if(io->iotype==INLC)
			{
				if(strcmp((char *)tworkcell->loadcells.loadcell[d].iotab[i].key,key)==0)
				{

					io->loadcellconnect=(loadcellConnect *)&tworkcell->loadcells.loadcell[d].iotab[i];
					return TRUE;
				}
			}
		}
	}
	if(io->iotype==INLC)
		io->iotype=INMAC;
	else if (io->iotype==OUTCOMSK)
		io->iotype=OUTMAC;
	for(d=0;d<tworkcell->macs.maxidx;d++)
  {
    for(i=0;i<tworkcell->macs.mac[d].numOfMotors;i++)
    {
			if(io->iotype==INMAC)
			{
				for(j=0;j<tworkcell->macs.mac[d].iotab[i].numOfInWords;j++)
				{
					if(strcmp(tworkcell->macs.mac[d].iotab[i].idata[j].key,key)==0)
					{
						io->macconnect=&tworkcell->macs.mac[d].iotab[i].idata[j];
						return TRUE;
					}
				}
			}
			else if (io->iotype==OUTMAC)
			{				
				for(j=0;j<tworkcell->macs.mac[d].iotab[i].numOfOutWords;j++)
				{
					if(strcmp(tworkcell->macs.mac[d].iotab[i].odata[j].key,key)==0)
					{
						io->macconnect=&tworkcell->macs.mac[d].iotab[i].odata[j];
						return TRUE;
					}
				}
      }
    }
  }
	if(io->iotype==INMAC)
		io->iotype=INICPCON;
	else if (io->iotype==OUTMAC)
		io->iotype=OUTICPCON;
	for(d=0;d<tworkcell->icpcons.maxidx;d++)
  {
    for(i=0;i<tworkcell->icpcons.icpcon[d].numOfModules;i++)
    {
			if (io->iotype==INICPCON)
			{ 
				for(j=0;j<tworkcell->icpcons.icpcon[d].iotab[i].numOfInBits;j++)
				{
					if(!strcmp((char *)tworkcell->icpcons.icpcon[d].iotab[i].inconnect[j].key,key))
					{				
						io->icpconnect=(tmpnICPConnect *)&tworkcell->icpcons.icpcon[d].iotab[i].inconnect[j];
						return TRUE;
					}
				}
			}
			else if (io->iotype==OUTICPCON)
			{
				for(j=0;j<tworkcell->icpcons.icpcon[d].iotab[i].numOfOutBits;j++)
				{
					if(!strcmp((char *)tworkcell->icpcons.icpcon[d].iotab[i].outconnect[j].key,key))
					{				
						io->icpconnect=(tmpnICPConnect *)&tworkcell->icpcons.icpcon[d].iotab[i].outconnect[j];
						return TRUE;
					}
				}
			}
		}
	}
  printf("%s not found\n",key);
  exit(1);
}

void getComment(char *buffer, char *n)
{
  int i,j0=0,j1=0;

  for(i=0;i<strlen(buffer);i++)
  {
    if(j0==0&&buffer[i]=='"')
    {
      j0=i;
      i++;
    }
    if(j1==0&&buffer[i]=='"') j1=i;
  }
  strncpy(n,&buffer[j0+1],j1-j0-1);
  n[j1-j0-1]=0;
}

int getMachinePtrStateIdx(tmpnStateMachine *statemachine, const char *statename)
{
  int i;
  for(i=0;i<statemachine->numstate;i++)
  {
    if(strcmp(statemachine->state[i].name,statename)==0) return i;
  }
  return -1;
}


char *getProgramName(char *stmname)
{
 // load all program names into the scroll box from database
  int p;
	char *name;
	p = getMachineIdx(stmname);
	if (p==-1)
	{
		return "";
	}
	else
	{
	  name=tworkcell->statemachines.statemachine[p].state[tworkcell->statemachines.statemachine[p].istate].name;
		if(!strncmp(name,"ST_RUNNING_",11))
			return &name[11];
		else 
			return "";
	}
  return "";
}

int tmpnStateMachineLoad(const char *filename, tmpnStateMachine *statemachine, int level)
{
  FILE *fp;
  int version;
  int idx,timeout, v, delaystop;
  char name[256], s[256], key[256], n[256],l[256],includename[256],a1[256],a2[256],a3[256];
  char buffer[256];
  tmpnStateMachineTable* tab;
  int i,x;
	
  fp = fopen(filename,"r");
  if(fp==NULL){
    printf("ERROR: Load Statemachine: cannot open file: '%s'\n", filename);
    exit(99);
  }
  ln = 0;
  fscanf(fp,"STATEMACHINEVERSION %d\n",&version);
  printf("Open statemachine %s VERSION %d\n", filename,version);
  ln++;
	if(version!=2&&version!=STATEMACHINEVERSION)
  {
    fclose(fp);
    printf(" FAILED version mismatch\n");
    exit(99);
  }
	statemachine->version=version;
  if(level==0)
    strcpy(statemachine->filename,filename);
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
    ln++;
    if(strncmp(buffer, ";", 1)==0)
    {
    }
    else if(strncmp(buffer,"Name=",5)==0)
    {
      sscanf(buffer,"Name=%s",statemachine->name);
    }
    else if(strncmp(buffer,"Include=",8)==0)
    {
			int oldln=ln;
      printf("'->");
      sscanf(buffer,"Include=%s",name);
      sprintf(includename,"%s/statemachine/%s",databasePath,name);
      tmpnStateMachineLoad(includename, statemachine,level+1);
			ln = oldln;
    }
		else if(strncmp(buffer,"Value=",6)==0)
    {
      if(version==2)
        sscanf(buffer,"Value=%d,%s %s\n",&idx,s,n);
      else
        sscanf(buffer,"Value=%s %s\n",s,n);
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
			}
      strcpy(statemachine->value[idx].name,s);
      statemachine->value[idx].type=VALUE;
			if (!strcmp(s,"DEBUG")) 
      {
       printf("DEBUG %s\n",statemachine->name); 
       statemachine->debugvalue = &statemachine->value[idx];
      }
      x = splitArg(n,a2,a3);
      if(x>=0)
      {
        statemachine->value[idx].subtype=1;
        statemachine->value[idx].data=atof(n);
        statemachine->value[idx].fdata=atof(n);
      }
      else
      {
        statemachine->value[idx].data=atoi(n);
        statemachine->value[idx].fdata=atoi(n);
        statemachine->value[idx].subtype=0;
      }
    }
    else if(strncmp(buffer,"Table=",6)==0)
    {
			int new;
			new=0;
      v = sscanf(buffer,"Table=%s %s %s\n",s,n,a1);
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
				new=1;
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
			}
      strcpy(statemachine->value[idx].name,s);
      statemachine->value[idx].type=TABLE;
      statemachine->value[idx].subtype=0;
      x = splitArg(n,a2,a3);
      if(x>=0)
        statemachine->value[idx].subtype=1;
      else
        statemachine->value[idx].subtype=0;
      statemachine->value[idx].data=0;
      statemachine->value[idx].fdata=0;
			if (new)
			{
				tab = (tmpnStateMachineTable*)malloc(sizeof(tmpnStateMachineTable));
				statemachine->value[idx].table = tab;
			}
			else
			{
				tab = statemachine->value[idx].table;				
			}
      tab->maxsize=atoi(a2)*2;
			if (new)
			{
				tab->item = (int*)malloc(sizeof(int)*tab->maxsize);
				tab->fitem = (float*)malloc(sizeof(float)*tab->maxsize);
			}
			else
			{
				tab->item = (int*)realloc(tab->item,sizeof(int)*tab->maxsize);
				tab->fitem = (float*)realloc(tab->fitem,sizeof(float)*tab->maxsize);
			}
      tab->topsearchwidth = -1;
      tab->topidx = -1;
      tab->topval = 0.0;
      tab->sum=0;
      tab->fsum=0.0;
      tab->sumcnt=0;
      tab->maxidx=0;
      tab->min=0;
      tab->max=0;
      tab->fmin=999999999.0;
      tab->fmax=-999999999.0;
      tab->newtablesize=atoi(a2);
      tab->curtablesize=tab->newtablesize;
      tab->item[0]=0;
      tab->fitem[0]=0.0;
      for(i=0;i<tab->maxsize;i++)
      {
        tab->item[i]=0;
        tab->fitem[i]=0.0;
      }
      if((v==3&&!strcmp(a1,"AVG")))
        tab->filter=1;
      else
        tab->filter=0;
    }
    else if(strncmp(buffer,"Const=",6)==0)
    {
      if(version==2)
        sscanf(buffer,"Const=%d,%s %s\n",&idx,s,n);
      else
        sscanf(buffer,"Const=%s %s\n",s,n);
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      strcpy(statemachine->value[idx].name,s);
      statemachine->value[idx].type=CONSTANT;
			if (!strcmp(s,"DEBUG")) statemachine->debugvalue = &statemachine->value[idx];
      x = splitArg(n,a2,a3);
      if(x>=0)
      {
        statemachine->value[idx].subtype=1;
        statemachine->value[idx].data=atof(n);
        statemachine->value[idx].fdata=atof(n);
      }
      else
      {
        statemachine->value[idx].data=atoi(n);
        statemachine->value[idx].fdata=atoi(n);
        statemachine->value[idx].subtype=0;
      }
    }
    else if(strncmp(buffer,"linkValue=",10)==0)
    {
      v = sscanf(buffer,"linkValue=%s %s %s\n",s,n,l);
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      if(v==2)
      {
        strcpy(statemachine->value[idx].name,s);
        strcpy(statemachine->value[idx].linkname,s);
        strcpy(statemachine->value[idx].link,n);
      }
      else if(v==3)
      {
        strcpy(statemachine->value[idx].name,s);
        strcpy(statemachine->value[idx].linkname,n);
        strcpy(statemachine->value[idx].link,l);
      }
      else 
        error(ln, "wrong number of arguments");
      
      statemachine->value[idx].type=LINKVALUE;
      statemachine->value[idx].data=0;
      statemachine->value[idx].linkvalue=NULL;
			statemachine->value[idx].remote=NULL;
    }
    else if(strncmp(buffer,"Timeout=",8)==0)
    {
      if(version==2)
        sscanf(buffer,"Timeout=%d,%s %d\n",&idx,s,&timeout);
      else
        sscanf(buffer,"Timeout=%s %d\n",s,&timeout);
      idx=getTimeoutIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numtimeout++;
				statemachine->timeout=(tmpnStateMachineTimeout *)realloc(statemachine->timeout,statemachine->numtimeout*sizeof(tmpnStateMachineTimeout));
      }
      strcpy(statemachine->timeout[idx].name,s);
      statemachine->timeout[idx].timeout=timeout;
    }
    else if(strncmp(buffer,"Input=",6)==0)
    {
      if(version==2)
        v = sscanf(buffer,"Input=%d,%s",&idx,name);
      else
        v = sscanf(buffer,"Input=%s",name) + 1;
        
      idx=getInputIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numinput++;
				statemachine->input=(tmpnStateMachineIO *)realloc(statemachine->input,statemachine->numinput*sizeof(tmpnStateMachineIO));
      }
      if(v!=2) error(ln, "wrong number of arguments");
			statemachine->input[idx].iotype=INPUT;
      getComment(buffer,key);
      connectStatemachineAndIO(&statemachine->input[idx],name,key);
    }
    else if(strncmp(buffer,"Output=",7)==0)
    {
      if(version==2)
        v = sscanf(buffer,"Output=%d,%s",&idx,name);
      else
        v = sscanf(buffer,"Output=%s",name) + 1;
       
      idx=getOutputIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numoutput++;
				statemachine->output=(tmpnStateMachineIO *)realloc(statemachine->output,statemachine->numoutput*sizeof(tmpnStateMachineIO));
      }
      if(v!=2) error(ln, "wrong number of arguments");
			statemachine->output[idx].iotype=OUTPUT;
      getComment(buffer,key);
      connectStatemachineAndIO(&statemachine->output[idx],name,key);
    }
    else if(strncmp(buffer,"Link=",5)==0)
    {
      key[0]=0;
      if(version==2)
        v = sscanf(buffer,"Link=%d,%s %s\n",&idx,s,key);
      else
        v = sscanf(buffer,"Link=%s %s\n",s,key) + 1;
      idx=getLinkIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numlink++;
				statemachine->link=(tmpnStateMachineLink *)realloc(statemachine->link,statemachine->numlink*sizeof(tmpnStateMachineLink));
      }
      if(v==2)
      {
        strcpy(statemachine->link[idx].localname,s);
        strcpy(statemachine->link[idx].name,s);
      }
      else
      {
        strcpy(statemachine->link[idx].localname,s);
        strcpy(statemachine->link[idx].name,key);
      }
    }
    else if(strncmp(buffer,"Delaystop=",10)==0) {
      sscanf(buffer,"Delaystop=%d\n",&delaystop);
      statemachine->delaystop=delaystop;
      printf(" delaystop!");
    }
    else if(strncmp(buffer,"Path=",5)==0)
    {
			int new;
      int mode;
      int type;
      tmpnPathHandle* path;
      
      v = sscanf(buffer,"Path=%s %s %s\n",s,a1,a2);
      if(v==3)
        v = sscanf(buffer,"Path=%s %d %d\n",s,&mode,&type);
			new=0;
      idx=getValueIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
				new=1;
      }
      strcpy(statemachine->value[idx].name,s);
      statemachine->value[idx].type=PATHHANDLE;
      statemachine->value[idx].subtype=0;
      statemachine->value[idx].data=0;
      statemachine->value[idx].fdata=0;
			if (new)
			{
				path = (tmpnPathHandle*)malloc(sizeof(tmpnPathHandle));
				statemachine->value[idx].path = path;
			}
			else
			{
				path = statemachine->value[idx].path;
			}
      path->state=ST_IDLE;
      if(v==3)
      {
        strcpy(path->script,"");
        path->firstpoint=NULL;
        path->key.mode=mode;
        path->key.type=type;
      }
      else
      {
        strcpy(path->script,a1);
        path->firstpoint=NULL;
        path->key.mode=0;
        path->key.type=0;
      }
      //init from
      strcpy(path->key.from.frame.name,"");
      path->key.from.frame.x=0.0;
      path->key.from.frame.y=0.0;
      path->key.from.frame.z=0.0;
      path->key.from.frame.v=0.0;
      path->key.from.frame.w=0.0;
      path->key.from.frame.u=0.0;
      path->key.from.cItem=0;
      path->key.from.cLayer=0;
      strcpy(path->key.from.itemName,"");
      strcpy(path->key.from.patternName,"");
      path->key.from.item=NULL;
      path->key.from.pattern=NULL;
      //init to
      strcpy(path->key.to.frame.name,"");
      path->key.to.frame.x=0.0;
      path->key.to.frame.y=0.0;
      path->key.to.frame.z=0.0;
      path->key.to.frame.v=0.0;
      path->key.to.frame.w=0.0;
      path->key.to.frame.u=0.0;
      path->key.to.cItem=0;
      path->key.to.cLayer=0;
      strcpy(path->key.to.itemName,"");
      strcpy(path->key.to.patternName,"");
      path->key.to.item=NULL;
      path->key.to.pattern=NULL;
    }
    else if(strncmp(buffer,"Frame=",6)==0)
    {
			int new;
      tmpnFrame frame;
      tmpnFrame *pframe;
      float x,y,z,vv,w,u;     
      v = sscanf(buffer,"Frame=%s x=%f y=%f z=%f v=%f w=%f u=%f\n",frame.name,&x,&y,&z,&vv,&w,&u);
      frame.x = x; 
      frame.y = y; 
      frame.z = z; 
      frame.v = vv; 
      frame.w = w; 
      frame.u = u; 
      //= sscanf(buffer,"Frame=%s x=%f y=%f z=%f v=%f w=%f u=%f\n",frame.name,&frame.x,&frame.y,&frame.z,&frame.v,&frame.w,&frame.u);
			if (v != 7) error(ln, "Wrong syntax in Frame");
			new=0;
      idx=getValueIdx(statemachine,frame.name);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
				new=1;
      }
      strcpy(statemachine->value[idx].name,frame.name);
      statemachine->value[idx].type=FRAME;
      statemachine->value[idx].subtype=1;
      statemachine->value[idx].data=0;
			if (new)
			{
				pframe = (tmpnFrame*)malloc(sizeof(tmpnFrame));
				statemachine->value[idx].frame = pframe;
			}
			else
			{
				pframe = statemachine->value[idx].frame;
			}
      strcpy(pframe->name,frame.name);
      pframe->x=frame.x;
      pframe->y=frame.y;
      pframe->z=frame.z;
      pframe->v=frame.v;
      pframe->w=frame.w;
      pframe->u=frame.u;
    }
    else if(strncmp(buffer,"Item=",5)==0)
    {
      char itemName[256];
      v = sscanf(buffer,"Item=%s %s\n",name,itemName);
      idx=getValueIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      strcpy(statemachine->value[idx].name,name);
      strcpy(statemachine->value[idx].link,itemName);
      statemachine->value[idx].type=ITEM;
      statemachine->value[idx].subtype=1;
      statemachine->value[idx].data=0;
    }
    else if(strncmp(buffer,"Pattern=",8)==0)
    {
      char patternName[256];
      v = sscanf(buffer,"Pattern=%s %s\n",name,patternName);
      idx=getValueIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      strcpy(statemachine->value[idx].name,name);
      strcpy(statemachine->value[idx].link,patternName);
      statemachine->value[idx].type=PATTERN;
      statemachine->value[idx].subtype=0;
      statemachine->value[idx].data=0;
    }
    else if(strncmp(buffer,"CPPattern=",10)==0)
    {
      char cppatternName[256];
      v = sscanf(buffer,"CPPattern=%s %s\n",name,cppatternName);
      idx=getValueIdx(statemachine,name);
      if(idx==-1)
      {
        idx=statemachine->numvalue++;
				statemachine->value=(tmpnStateMachineValue *)realloc(statemachine->value,statemachine->numvalue*sizeof(tmpnStateMachineValue));
      }
      strcpy(statemachine->value[idx].name,name);
      strcpy(statemachine->value[idx].link,cppatternName);
      statemachine->value[idx].type=CPPATTERN;
      statemachine->value[idx].subtype=0;
      statemachine->value[idx].data=0;
    }
  }
  fclose(fp);
	return TRUE;
} 

int tmpnStateLoad(const char *filename, tmpnStateMachine *statemachine, int level)
{
  FILE *fp;
	char name[256], s[256],includename[256];
  char buffer[256];
	int version=0,idx;
	ln=0;
	fp = fopen(filename,"r");
  fscanf(fp,"STATEMACHINEVERSION %d\n",&version);
  ln++;
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
    ln++;
    if(strncmp(buffer, ";", 1)==0)
    {
    }
    else if(strncmp(buffer,"Include=",8)==0)
    {
			int oldln=ln;
			sscanf(buffer,"Include=%s",name);
      sprintf(includename,"%s/statemachine/%s",databasePath,name);
      tmpnStateLoad(includename, statemachine,level+1);
			ln=oldln;
    }
    else if(strncmp(buffer,"State=",6)==0)
    {
      if(version==2)
        sscanf(buffer,"State=%d,%s\n",&idx,s);
      else
        sscanf(buffer,"State=%s\n",s);
			
      idx = getMachinePtrStateIdx(statemachine,s);
      if(idx==-1)
      {
        idx=statemachine->numstate++;
				statemachine->state=(tmpnStateMachineState *)realloc(statemachine->state,statemachine->numstate*sizeof(tmpnStateMachineState));
        statemachine->state[idx].maxprgidx=0;
				statemachine->state[idx].prg=NULL;
        statemachine->state[idx].statenum = idx;
        strcpy(statemachine->state[idx].name,s);
      }
      else
      {
        free(statemachine->state[idx].prg);
        statemachine->state[idx].maxprgidx=0;
				statemachine->state[idx].prg=NULL;
      }
			if (!strcmp(s,"ST_TIMER")) statemachine->timerstate=idx;
      getFunctionBody(fp, idx, statemachine);
    }
	}
  fclose(fp);
	return TRUE;
}

void setStateTekst(char *tekst, int kode, int line)
{
  int i,j;
  tmpnWorkcell *workcell=(tmpnWorkcell*)tworkcell;
	tmpnStateTeksts *stptr;
  sprintf(tekst,"%s","");
  j=0;
	stptr=&workcell->statetekstlist.stateteksts[workcell->statetekstlist.currentStateTekst];
  for(i=0;i<stptr->maxidx;i++)
  {
    if(stptr->item[i].idx==kode)
    {
      if(j==line)
      {
        sprintf(tekst,stptr->item[i].tekst);
        return;
      }
      if(j>0) return;
      j++;
    }
  }
}

int tmpnStateTekstsLoad(const char *filename, tmpnStateTekstList *statetekstlist)
{
  FILE *fp;
  int version,l;
  char buffer[256];
	tmpnStateTeksts *sts;
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  fscanf(fp,"STATETEKSTVERSION %d\n",&version);
  if(version!=STATETEKSTVERSION) return FALSE;
	sts = &statetekstlist->stateteksts[statetekstlist->numofStateTeksts];
  fscanf(fp,"%s\n",sts->name);
  sts->maxidx=0;
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {    sscanf(buffer,"%d",&sts->item[sts->maxidx].idx);
    strcpy(&sts->item[sts->maxidx].tekst[0],&buffer[6]);
    l=strlen(sts->item[sts->maxidx].tekst);
    sts->item[sts->maxidx].tekst[l-1]=0x0;
    sts->maxidx++;
  }
	statetekstlist->numofStateTeksts++;
  fclose(fp);
	
  return TRUE;
}

int tmpnLanguageLoad(const char *filename, tmpnLanguages *languages)
{
	int i,j;
  FILE *fp;
  int version;
  char buffer[256];
	int line;
	tmpnLanguage *lang;
  fp = fopen(filename,"r");
  if(fp==NULL) 
	{
		printf("Couldn't open languagefile: %s\n",filename);
		return FALSE;
	}
  fscanf(fp,"LANGUAGEVERSION %d\n",&version);
  if(version!=LANGUAGEVERSION) return FALSE;
	lang=&languages->language[languages->numoflanguages++];
	lang->maxidx=0;	
  fscanf(fp,"%s\n",lang->name);
	line=3;
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
		if (buffer[0]!=';')
		{
			sscanf(buffer,"%d",&lang->item[lang->maxidx].key);
			int dplace[4]={0,0,0,0};
			int success=0;
			int dotplace=0;
			for (j=0;j<4;j++)
			{
				for (i=dotplace+1;i<strlen(buffer);i++)
				{
					if (buffer[i]=='"') 
					{
						dplace[success++]=i;
						dotplace=i;
					}
				}
			}
			if (success!=4)
			{
				printf("Unknown languageline-type '%s' in .language file line %d\n",buffer,line);
				exit(99);
			}
			int tekstlen=dplace[1]-dplace[0]-1;
			int englishlen=dplace[3]-dplace[2]-1;
			strncpy(lang->item[lang->maxidx].tekst,&buffer[dplace[0]+1],tekstlen);
			strncpy(lang->item[lang->maxidx].english,&buffer[dplace[2]+1],englishlen);
			lang->maxidx++;
		}
		line++;
  }
  fclose(fp);
  return TRUE;
}

int tmpnPPScriptLoad(const char *filename, tmpnPPScript *ppscript)
{
  //  extern FILE *ppin;
  FILE *fp;
  int version;
  char buffer[256];
  char fromstr[256];
  char tostr[256];
  char *bracket;
  int retval;
 
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  fscanf(fp,"PPSCRIPTVERSION %d\n",&version);
  if(version!=1&&version!=2) return FALSE;
  if(version==1) ppscript->layers=0;
  fscanf(fp,"%s\n",ppscript->name);
  ppscript->maxidx=0;
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
    if(strncmp(buffer,"itemsPrLayer=",13)==0)
    {
      sscanf(buffer,"itemsPrLayer=%d\n",&ppscript->itemsPrLayer);
    }
    else if(strncmp(buffer,"layers=",7)==0)
    {
      sscanf(buffer,"layers=%d\n",&ppscript->layers);
    }
    else if(strncmp(buffer,"type=",5)==0)
    {
      sscanf(buffer,"type=%d\n",&ppscript->type);
    }
    else if(strncmp(buffer,"move",4)==0)
    {
      sscanf(buffer,"%s %s from %s to %s\n"
						 ,ppscript->item[ppscript->maxidx].cmd
						 ,ppscript->item[ppscript->maxidx].item
						 ,fromstr
						 ,tostr);
      bracket = strchr(fromstr, '(');
      if (bracket != 0)
      {
        *bracket = ' ';
        float x,y,z,v,w,u;
        retval=sscanf(fromstr,"%s idx=%d,%d,wcp=%f,%f,%f,%f,%f,%f"
											,ppscript->item[ppscript->maxidx].from
											,&ppscript->item[ppscript->maxidx].layer
											,&ppscript->item[ppscript->maxidx].idx
											,&x
											,&y
											,&z
											,&v
											,&w
											,&u);
				ppscript->item[ppscript->maxidx].wcp.x = x;
      	ppscript->item[ppscript->maxidx].wcp.y = y;
				ppscript->item[ppscript->maxidx].wcp.z = z;
				ppscript->item[ppscript->maxidx].wcp.v = v;
				ppscript->item[ppscript->maxidx].wcp.w = w;
				ppscript->item[ppscript->maxidx].wcp.u = u;
/*        retval=sscanf(fromstr,"%s idx=%d,%d,wcp=%f,%f,%f,%f,%f,%f"
											,ppscript->item[ppscript->maxidx].from
											,&ppscript->item[ppscript->maxidx].layer
											,&ppscript->item[ppscript->maxidx].idx
											,&ppscript->item[ppscript->maxidx].wcp.x
											,&ppscript->item[ppscript->maxidx].wcp.y
											,&ppscript->item[ppscript->maxidx].wcp.z
											,&ppscript->item[ppscript->maxidx].wcp.v
											,&ppscript->item[ppscript->maxidx].wcp.w
											,&ppscript->item[ppscript->maxidx].wcp.u);*/
				if (retval==3) 
				{
					ppscript->item[ppscript->maxidx].wcp.x = 0.0;
					ppscript->item[ppscript->maxidx].wcp.y = 0.0;
					ppscript->item[ppscript->maxidx].wcp.z = 0.0;
					ppscript->item[ppscript->maxidx].wcp.v = 0.0;
					ppscript->item[ppscript->maxidx].wcp.w = 0.0;
					ppscript->item[ppscript->maxidx].wcp.u = 0.0;
				}
      }
      else
      {
        strcpy(ppscript->item[ppscript->maxidx].from,fromstr);
      }
      bracket = strchr(tostr, '(');
      if (bracket != 0)
      {
        *bracket = ' ';
        float x,y,z,v,w,u;
        retval=sscanf(tostr,"%s idx=%d,%d,wcp=%f,%f,%f,%f,%f,%f"
											,ppscript->item[ppscript->maxidx].to
											,&ppscript->item[ppscript->maxidx].layer
											,&ppscript->item[ppscript->maxidx].idx
											,&x
											,&y
											,&z
											,&v
											,&w
											,&u);
				ppscript->item[ppscript->maxidx].wcp.x = x;
      	ppscript->item[ppscript->maxidx].wcp.y = y;
				ppscript->item[ppscript->maxidx].wcp.z = z;
				ppscript->item[ppscript->maxidx].wcp.v = v;
				ppscript->item[ppscript->maxidx].wcp.w = w;
				ppscript->item[ppscript->maxidx].wcp.u = u;
        /*retval=sscanf(tostr,"%s idx=%d,%d,wcp=%f,%f,%f,%f,%f,%f"
											,ppscript->item[ppscript->maxidx].to
											,&ppscript->item[ppscript->maxidx].layer
											,&ppscript->item[ppscript->maxidx].idx
											,&ppscript->item[ppscript->maxidx].wcp.x
											,&ppscript->item[ppscript->maxidx].wcp.y
											,&ppscript->item[ppscript->maxidx].wcp.z
											,&ppscript->item[ppscript->maxidx].wcp.v
											,&ppscript->item[ppscript->maxidx].wcp.w
											,&ppscript->item[ppscript->maxidx].wcp.u);*/
				if (retval==3) 
				{
					ppscript->item[ppscript->maxidx].wcp.x = 0.0;
					ppscript->item[ppscript->maxidx].wcp.y = 0.0;
					ppscript->item[ppscript->maxidx].wcp.z = 0.0;
					ppscript->item[ppscript->maxidx].wcp.v = 0.0;
					ppscript->item[ppscript->maxidx].wcp.w = 0.0;
					ppscript->item[ppscript->maxidx].wcp.u = 0.0;
				}
      }
      else
      {
        strcpy(ppscript->item[ppscript->maxidx].to,tostr);
      }
      ppscript->maxidx++;
    }
  }
  fclose(fp);
  return TRUE;
}

int tmpnBoptCoeffLoad(const char *filename, tmpnBoptCoeff *boptcoeff)
{
  FILE *fp;
  int version;
  char buffer[1024];
	char string[256];
  char str[16][256];
	char *pstr;
	float val[16];
  int retval; 
	int i,j;
 
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  strcpy(boptcoeff->filename,filename);
  fscanf(fp,"BOPTCOEFFVERSION %d\n",&version);
  if(version!=1) return FALSE;
  fscanf(fp,"%127s\n",boptcoeff->name);
  boptcoeff->maxidx=0;
	/* default values */
	for (i=0;i<MAXBOPTCOEFFITEMS;i++)
	{
		boptcoeff->item[i].pathName[0]=0x0;
		boptcoeff->item[i].pathtype=0;
		boptcoeff->item[i].viatype=0;
		for (j=0;j<16;j++)
		{
			boptcoeff->item[i].viapos[0].x[j].value=0.0;
			boptcoeff->item[i].viapos[1].x[j].value=0.0;
			boptcoeff->item[i].viavel[0].x[j].value=0.0;
			boptcoeff->item[i].viavel[1].x[j].value=0.0;
			boptcoeff->item[i].viapos[0].y[j].value=0.0;
			boptcoeff->item[i].viapos[1].y[j].value=0.0;
			boptcoeff->item[i].viavel[0].y[j].value=0.0;
			boptcoeff->item[i].viavel[1].y[j].value=0.0;
			boptcoeff->item[i].viapos[0].z[j].value=0.0;
			boptcoeff->item[i].viapos[1].z[j].value=0.0;
			boptcoeff->item[i].viavel[0].z[j].value=0.0;
			boptcoeff->item[i].viavel[1].z[j].value=0.0;
			boptcoeff->item[i].viapos[0].v[j].value=0.0;
			boptcoeff->item[i].viapos[1].v[j].value=0.0;
			boptcoeff->item[i].viavel[0].v[j].value=0.0;
			boptcoeff->item[i].viavel[1].v[j].value=0.0;
			boptcoeff->item[i].viapos[0].w[j].value=0.0;
			boptcoeff->item[i].viapos[1].w[j].value=0.0;
			boptcoeff->item[i].viavel[0].w[j].value=0.0;
			boptcoeff->item[i].viavel[1].w[j].value=0.0;
			boptcoeff->item[i].viapos[0].x[j].ABS=0;
			boptcoeff->item[i].viapos[1].x[j].ABS=0;
			boptcoeff->item[i].viapos[0].y[j].ABS=0;
			boptcoeff->item[i].viapos[1].y[j].ABS=0;
			boptcoeff->item[i].viapos[0].z[j].ABS=0;
			boptcoeff->item[i].viapos[1].z[j].ABS=0;
			boptcoeff->item[i].viapos[0].v[j].ABS=0;
			boptcoeff->item[i].viapos[1].v[j].ABS=0;
			boptcoeff->item[i].viapos[0].w[j].ABS=0;
			boptcoeff->item[i].viapos[1].w[j].ABS=0;
		}
		boptcoeff->item[i].macro[0].integer[0]=0;
		boptcoeff->item[i].macro[0].integer[1]=0;
		boptcoeff->item[i].macro[0].floating[0]=200.0;
		boptcoeff->item[i].macro[0].floating[1]=0.3;
		boptcoeff->item[i].macro[0].floating[2]=0.0;
		boptcoeff->item[i].macro[0].floating[3]=0.0;
		boptcoeff->item[i].macro[0].floating[4]=0.0;
		boptcoeff->item[i].macro[0].floating[5]=0.0;
		boptcoeff->item[i].macro[1].integer[0]=0;
		boptcoeff->item[i].macro[1].integer[1]=0;
		boptcoeff->item[i].macro[1].floating[0]=200.0;
		boptcoeff->item[i].macro[1].floating[1]=0.3;
		boptcoeff->item[i].macro[1].floating[2]=0.0;
		boptcoeff->item[i].macro[1].floating[3]=0.0;
		boptcoeff->item[i].macro[1].floating[4]=0.0;
		boptcoeff->item[i].macro[1].floating[5]=0.0;
		boptcoeff->item[i].params.integer[0]=0;
		boptcoeff->item[i].params.integer[1]=0;
		boptcoeff->item[i].params.floating[0]=2100.0;
		boptcoeff->item[i].params.floating[1]=250.0;
		boptcoeff->item[i].params.floating[2]=25.0;
		boptcoeff->item[i].params.floating[3]=1.0;
		boptcoeff->item[i].params.floating[4]=3500.0;
		boptcoeff->item[i].params.floating[5]=1000.0;
		boptcoeff->item[i].mv[0]=1.7;
		boptcoeff->item[i].mv[1]=3.11;
		boptcoeff->item[i].mv[2]=3.24;
		boptcoeff->item[i].mv[3]=2.62;
		boptcoeff->item[i].mv[4]=5.23;
		boptcoeff->item[i].ma[0]=4.2;
		boptcoeff->item[i].ma[1]=2.2;
		boptcoeff->item[i].ma[2]=5;
		boptcoeff->item[i].ma[3]=6;
		boptcoeff->item[i].ma[4]=6;
	}
  while (fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
		if (!strncmp(buffer,"mode",4))
    {
      retval=sscanf(buffer,"mode %d pathtype %d :\n",&boptcoeff->item[boptcoeff->maxidx].mode,&boptcoeff->item[boptcoeff->maxidx].pathtype);
			if (retval==2)
			{
				boptcoeff->maxidx++;
				if (boptcoeff->maxidx > MAXBOPTCOEFFITEMS)
				{
					printf("BoptCoeff: Number of boptcoeff items exeeds MAXBOPTCOEFFITEMS\n");
					exit(99);
				}
			}
			else
				return FALSE;
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].pathName,"(%d,%d)"
							,boptcoeff->item[boptcoeff->maxidx-1].mode
							,boptcoeff->item[boptcoeff->maxidx-1].pathtype);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromFrame,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toFrame,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromItem,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toItem,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromPattern,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toPattern,"%s","NULL");
		}
		else if (!strncmp(buffer,"ppscripttype",12)) //old name for mode
    {
      retval=sscanf(buffer,"ppscripttype %d pathtype %d :\n",&boptcoeff->item[boptcoeff->maxidx].mode,&boptcoeff->item[boptcoeff->maxidx].pathtype);
			if (retval==2)
			{
				boptcoeff->maxidx++;
				if (boptcoeff->maxidx > MAXBOPTCOEFFITEMS)
				{
					printf("BoptCoeff: Number of boptcoeff items exeeds MAXBOPTCOEFFITEMS\n");
					exit(99);
				}
			}
			else
				return FALSE;
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].pathName,"(%d,%d)"
							,boptcoeff->item[boptcoeff->maxidx-1].mode
							,boptcoeff->item[boptcoeff->maxidx-1].pathtype);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromFrame,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toFrame,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromItem,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toItem,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromPattern,"%s","NULL");
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toPattern,"%s","NULL");
		}
	  else if (strncmp(buffer,"pathName",8)==0)
		{
			sscanf(buffer,"pathName %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].pathName,"%s (%d,%d)"
							,string
							,boptcoeff->item[boptcoeff->maxidx-1].mode
							,boptcoeff->item[boptcoeff->maxidx-1].pathtype);
    }
	  else if (strncmp(buffer,"def.fromFrame",13)==0)
		{
			sscanf(buffer,"def.fromFrame %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromFrame,"%s"
							,string);
    }
	  else if (strncmp(buffer,"def.toFrame",11)==0)
		{
			sscanf(buffer,"def.toFrame %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toFrame,"%s"
							,string);
    }
	  else if (strncmp(buffer,"def.fromItem",12)==0)
		{
			sscanf(buffer,"def.fromItem %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromItem,"%s"
							,string);
    }
	  else if (strncmp(buffer,"def.toItem",10)==0)
		{
			sscanf(buffer,"def.toItem %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toItem,"%s"
							,string);
    }
	  else if (strncmp(buffer,"def.fromPattern",15)==0)
		{
			sscanf(buffer,"def.fromPattern %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.fromPattern,"%s"
							,string);
    }
	  else if (strncmp(buffer,"def.toPattern",13)==0)
		{
			sscanf(buffer,"def.toPattern %255s\n",string);
      sprintf(boptcoeff->item[boptcoeff->maxidx-1].def.toPattern,"%s"
							,string);
    }
		else if (boptcoeff->maxidx>0)
		{
      if (strncmp(buffer,"viatype",7)==0)
			{
				retval=sscanf(buffer,"viatype %255s\n",string);
				if (retval==1)
				{
					if(strncmp(string,"NONE",4)==0)
					{
						boptcoeff->item[boptcoeff->maxidx-1].viatype=0; //was pathtype=0
					}
					else if(strncmp(string,"START",5)==0)
					{
						boptcoeff->item[boptcoeff->maxidx-1].viatype=1;
					}
					else if(strncmp(string,"END",3)==0)
					{
						boptcoeff->item[boptcoeff->maxidx-1].viatype=2;
					}
					else if(strncmp(string,"BOTH",4)==0)
					{
						boptcoeff->item[boptcoeff->maxidx-1].viatype=3;
					}
				}
				else
				{
					return FALSE;
				}
			}
			else if (!strncmp(buffer,"via1pos.x",9)||!strncmp(buffer,"via1pos.y",9)||!strncmp(buffer,"via1pos.z",9)||!strncmp(buffer,"via1pos.v",9)||!strncmp(buffer,"via1pos.w",9)||!strncmp(buffer,"via2pos.x",9)||!strncmp(buffer,"via2pos.y",9)||!strncmp(buffer,"via2pos.z",9)||!strncmp(buffer,"via2pos.v",9)||!strncmp(buffer,"via2pos.w",9)||!strncmp(buffer,"via1abs.x",9)||!strncmp(buffer,"via1abs.y",9)||!strncmp(buffer,"via1abs.z",9)||!strncmp(buffer,"via1abs.v",9)||!strncmp(buffer,"via1abs.w",9)||!strncmp(buffer,"via2abs.x",9)||!strncmp(buffer,"via2abs.y",9)||!strncmp(buffer,"via2abs.z",9)||!strncmp(buffer,"via2abs.v",9)||!strncmp(buffer,"via2abs.w",9)||!strncmp(buffer,"via1vel.x",9)||!strncmp(buffer,"via1vel.y",9)||!strncmp(buffer,"via1vel.z",9)||!strncmp(buffer,"via1vel.v",9)||!strncmp(buffer,"via1vel.w",9)||!strncmp(buffer,"via2vel.x",9)||!strncmp(buffer,"via2vel.y",9)||!strncmp(buffer,"via2vel.z",9)||!strncmp(buffer,"via2vel.v",9)||!strncmp(buffer,"via2vel.w",9))
			{
				tmpnBoptParamStruct* fbuf=NULL;
				if (!strncmp(&buffer[4],"pos",3)||!strncmp(&buffer[4],"abs",3))
				{
					if (buffer[3]=='1') {
						if (buffer[8]=='x') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].x;
						else if (buffer[8]=='y') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].y;
						else if (buffer[8]=='z') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].z;
						else if (buffer[8]=='v') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].v;
						else if (buffer[8]=='w') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[0].w;
						else return FALSE;
					}
					else if (buffer[3]=='2') {
						if (buffer[8]=='x') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].x;
						else if (buffer[8]=='y') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].y;
						else if (buffer[8]=='z') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].z;
						else if (buffer[8]=='v') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].v;
						else if (buffer[8]=='w') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viapos[1].w;
						else return FALSE;
					}
				}
				else if (!strncmp(&buffer[4],"vel",3))
				{
					if (buffer[3]=='1') {
						if (buffer[8]=='x') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].x;
						else if (buffer[8]=='y') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].y;
						else if (buffer[8]=='z') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].z;
						else if (buffer[8]=='v') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].v;
						else if (buffer[8]=='w') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[0].w;	
						else return FALSE;
					}
					else if (buffer[3]=='2') {
						if (buffer[8]=='x') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].x;
						else if (buffer[8]=='y') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].y;
						else if (buffer[8]=='z') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].z;
						else if (buffer[8]=='v') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].v;
						else if (buffer[8]=='w') fbuf=boptcoeff->item[boptcoeff->maxidx-1].viavel[1].w;
						else return FALSE;
					}
				}
				if (!strncmp(&buffer[4],"abs",3)) 
				{
					for (i=0;i<16;i++)
					{
						fbuf[i].ABS=1;
					}
				}
				else if (!strncmp(&buffer[4],"pos",3)) 
				{
					for (i=0;i<16;i++)
					{
						fbuf[i].ABS=0;
					}		
				}
				retval=sscanf(buffer,"%s %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f\n",string,&str[0][0],&val[0],&str[1][0],&val[1],&str[2][0],&val[2],&str[3][0],&val[3],&str[4][0],&val[4],&str[5][0],&val[5],&str[6][0],&val[6],&str[7][0],&val[7],&str[8][0],&val[8],&str[9][0],&val[9],&str[10][0],&val[10],&str[11][0],&val[11],&str[12][0],&val[12],&str[13][0],&val[13],&str[14][0],&val[14],&str[15][0],&val[15]);
				if ((retval>=3)&&(retval%1==0))
				{
					int slen;
					int maxi=(retval-1)/2;
					for (i=0;i<maxi;i++)
					{
						pstr=&str[i][0];
						slen = strlen(pstr);
						if (slen>16) return FALSE;
						fbuf[i].numofparams=slen;
						fbuf[i].value=val[i];
						for (j=0;j<slen;j++) 
						{
							if ((pstr[j]=='c')||(pstr[j]=='f')||(pstr[j]=='b')||(pstr[j]=='p')||(pstr[j]=='g')||(pstr[j]=='l')||(pstr[j]=='h')||(pstr[j]=='t')||(pstr[j]=='r'))
							{
								fbuf[i].table[j]=pstr[j];
							}
							else return FALSE;
						}
					}
				}
				else
				{
					return FALSE;
				}
			}
			else if (!strncmp(buffer,"macro1",6)||!strncmp(buffer,"macro2",6))
			{
				tmpnBoptMacroItem* pmac=NULL;
				if (buffer[5]=='1')
				{
					pmac = &boptcoeff->item[boptcoeff->maxidx-1].macro[0];
				}
				else if (buffer[5]=='2')
				{
					pmac = &boptcoeff->item[boptcoeff->maxidx-1].macro[1];
				}
				retval=sscanf(buffer,"%s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s\n",string,&str[0][0],&str[1][0],&str[2][0],&str[3][0],&str[4][0],&str[5][0],&str[6][0],&str[7][0],&str[8][0],&str[9][0],&str[10][0],&str[11][0],&str[12][0],&str[13][0],&str[14][0],&str[15][0]);
				if ((retval>=3)&&(retval%1==0))
				{
					int maxi=(retval-1);
					pstr=&str[0][0];
					for (i=0;i<maxi;i+=2)
					{
						pstr=&str[i][0];
						if (!strncmp(pstr,"type",4))
						{
							if (!strncmp(&str[i+1][0],"NOMACRO",7))
								pmac->integer[0]=0;
							else 	if (!strncmp(&str[i+1][0],"SPIRAL",6))
								pmac->integer[0]=1;
							else 	if (!strncmp(&str[i+1][0],"UPLINE",6))
								pmac->integer[0]=2;
							else 	if (!strncmp(&str[i+1][0],"DOWNLINE",8))
								pmac->integer[0]=3;
							else 	if (!strncmp(&str[i+1][0],"FASTUPLINE",10))
								pmac->integer[0]=4;
							else 	if (!strncmp(&str[i+1][0],"FASTDOWNLINE",12))
								pmac->integer[0]=5;
						}
						else if (!strncmp(pstr,"positionhint",12))
						{
							int phint;
							retval=sscanf(&str[i+1][0],"%d",&phint);
							if (retval==1)
								pmac->integer[1]=phint;
						}
						else if (!strncmp(pstr,"length",6))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pmac->floating[0]=fval;
						}
						else if (!strncmp(pstr,"time",4))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pmac->floating[1]=fval;
						}
						else if (!strncmp(pstr,"amplitude",9))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pmac->floating[2]=fval;
						}
						else if (!strncmp(pstr,"offsx",5))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pmac->floating[3]=fval;
						}
						else if (!strncmp(pstr,"offsz",5))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pmac->floating[4]=fval;
						}
						else if (!strncmp(pstr,"frequency",9))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pmac->floating[5]=fval;
						}
					}
				}
			}
			else if (!strncmp(buffer,"params",6))
			{
				tmpnBoptParamItem* pparam;
				pparam = &boptcoeff->item[boptcoeff->maxidx-1].params;
				retval=sscanf(buffer,"%s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s %255[^=]=%255s\n",string,&str[0][0],&str[1][0],&str[2][0],&str[3][0],&str[4][0],&str[5][0],&str[6][0],&str[7][0],&str[8][0],&str[9][0],&str[10][0],&str[11][0],&str[12][0],&str[13][0],&str[14][0],&str[15][0]);
				if ((retval>=3)&&(retval%1==0))
				{
					int maxi=(retval-1);
					for (i=0;i<maxi;i+=2)
					{
						pstr=&str[i][0];
						if (!strncmp(pstr,"tcpidx",6))
						{
							int tcp;
							retval=sscanf(&str[i+1][0],"%d",&tcp);
							if (retval==1)
								pparam->integer[0]=tcp;
						}
						else if (!strncmp(pstr,"blendtype",9))
						{
							int bt;
							retval=sscanf(&str[i+1][0],"%d",&bt);
							if (retval==1)
								pparam->integer[1]=bt;
						}
						else if (!strncmp(pstr,"maxheight",9))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pparam->floating[0]=fval;
						}
						else if (!strncmp(pstr,"minheight",9))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pparam->floating[1]=fval;
						}
						else if (!strncmp(pstr,"samplerate",10))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pparam->floating[2]=fval;
						}
						else if (!strncmp(pstr,"timefactor",10))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pparam->floating[3]=fval;
						}
						else if (!strncmp(pstr,"maxlength",9))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pparam->floating[4]=fval;
						}
						else if (!strncmp(pstr,"lockv",5))
						{
							float fval;
							retval=sscanf(&str[i+1][0],"%f",&fval);
							if (retval==1)
								pparam->floating[5]=fval;
						}
					}
				}
			}
			else if (!strncmp(buffer,"mv",2))
			{
				retval=sscanf(buffer,"mv %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f\n",&str[0][0],&val[0],&str[1][0],&val[1],&str[2][0],&val[2],&str[3][0],&val[3],&str[4][0],&val[4]);
				if ((retval>=2)&&(retval%2==0))
				{
					int maxi=retval/2;
					for (i=0;i<maxi;i++)
					{
						pstr=&str[i][0];
						if (!strncmp(pstr,"a",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].mv[0]=val[i];
						}
						else if (!strncmp(pstr,"b",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].mv[1]=val[i];
						}
						else if (!strncmp(pstr,"c",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].mv[2]=val[i];
						}
						else if (!strncmp(pstr,"d",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].mv[3]=val[i];
						}
						else if (!strncmp(pstr,"e",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].mv[4]=val[i];
						}
					}			
				}		
			}
			else if (!strncmp(buffer,"ma",2))
			{
				retval=sscanf(buffer,"ma %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f %255[^=]=%f\n",&str[0][0],&val[0],&str[1][0],&val[1],&str[2][0],&val[2],&str[3][0],&val[3],&str[4][0],&val[4]);
				if ((retval>=2)&&(retval%2==0))
				{
					int maxi=retval/2;
					for (i=0;i<maxi;i++)
					{
						pstr=&str[i][0];
						if (!strncmp(pstr,"a",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].ma[0]=val[i];
						}
						else if (!strncmp(pstr,"b",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].ma[1]=val[i];
						}
						else if (!strncmp(pstr,"c",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].ma[2]=val[i];
						}
						else if (!strncmp(pstr,"d",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].ma[3]=val[i];
						}
						else if (!strncmp(pstr,"e",1))
						{
							boptcoeff->item[boptcoeff->maxidx-1].ma[4]=val[i];
						}
					}			
				}		
			}
		}
		else
		{
			return FALSE;
		}
  }
  fclose(fp);
  return TRUE;
}

int tmpnBoptCoeffSave(tmpnBoptCoeff *boptcoeff)
{
	FILE *fp;
	char string[1024];
	int i,j;
	
  fp = fopen(boptcoeff->filename,"w");
  if(fp==NULL)
	{
    printf("Couldn't open %s for writing!\n",boptcoeff->filename);
		return FALSE;
	}
	fprintf(fp,"BOPTCOEFFVERSION %d\n",BOPTCOEFFVERSION);
	fprintf(fp,"%s\n",boptcoeff->name);
	for (i=0;i<boptcoeff->maxidx;i++)
	{
		fprintf(fp,"\n");
		fprintf(fp,"mode %d pathtype %d :\n",boptcoeff->item[i].mode,boptcoeff->item[i].pathtype);
		fprintf(fp,"pathName %s\n",boptcoeff->item[i].pathName);
		switch (boptcoeff->item[i].viatype)
		{
		case 0:
			fprintf(fp,"viatype NONE\n");
			break;
		case 1:
			fprintf(fp,"viatype START\n");
			break;
		case 2:
			fprintf(fp,"viatype END\n");
			break;
		case 3:
			fprintf(fp,"viatype BOTH\n");
			break;
		}
		int notempty;
		int stl;
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].x[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);	
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f",val);
			}
		}
		if (notempty) fprintf(fp,"via1pos.x %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].y[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f",val);
			}
		}
		if (notempty) fprintf(fp,"via1pos.y %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].z[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f",val);
			}
		}
		if (notempty) fprintf(fp,"via1pos.z %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].v[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f",val);
			}
		}
		if (notempty) fprintf(fp,"via1pos.v %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[0].w[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f",val);
			}
		}
		if (notempty) fprintf(fp,"via1pos.w %s\n",string);

		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].x[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via1vel.x %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].y[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via1vel.y %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].z[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via1vel.z %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].v[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via1vel.v %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[0].w[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via1vel.w %s\n",string);
		
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].x[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2pos.x %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].y[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2pos.y %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].z[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2pos.z %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].v[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2pos.v %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viapos[1].w[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2pos.w %s\n",string);

		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].x[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2vel.x %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].y[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2vel.y %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].z[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2vel.z %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].v[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2vel.v %s\n",string);
		stl=0;
		notempty=0;
		string[0]='\0';
		for (j=0;j<16;j++)
		{
			tmpnBoptParamStruct *fbuf=&boptcoeff->item[i].viavel[1].w[j];
			float val = fbuf->value;
			if (val!=0.0000)
			{
				notempty=1;
				stl=strlen(string);
				for (i=0;i<fbuf->numofparams;i++)
				{
					string[stl+i]=fbuf->table[i];
				}
				string[stl+i+1]='\0';
				stl=strlen(string);
				sprintf(&string[stl],"=%0.4f ",val);
			}
		}
		if (notempty) fprintf(fp,"via2vel.w %s\n",string);

		for (j=0;j<2;j++)
		{
			int macrotype;
			macrotype=boptcoeff->item[i].macro[j].integer[0];
			switch (macrotype)
			{
			case 0:
				sprintf(string,"macro%d type=NOMACRO",j+1);
				break;
			case 1:
				sprintf(string,"macro%d type=SPIRAL",j+1);
				break;
			case 2:
				sprintf(string,"macro%d type=UPLINE",j+1);
				break;
			case 3:
				sprintf(string,"macro%d type=DOWNLINE",j+1);
				break;
			case 4:
				sprintf(string,"macro%d type=FASTUPLINE",j+1);
				break;
			case 5:
				sprintf(string,"macro%d type=FASTDOWNLINE",j+1);
				break;
			default:
				sprintf(string,"macro%d type=UNKNOWN!!!!",j+1);
			}
			if (macrotype!=0)
			{
				int m;
				float f;
				m=boptcoeff->item[i].macro[j].integer[1];
				if (m!=0)
				{
					stl=strlen(string);
					sprintf(&string[stl]," positionhint=%i",m);
				}
				f=boptcoeff->item[i].macro[j].floating[0];
				if (f!=0.00)
				{
					stl=strlen(string);
					sprintf(&string[stl]," length=%0.4f",f);
				}
				f=boptcoeff->item[i].macro[j].floating[1];
				if (f!=0.00)
				{
					stl=strlen(string);
					sprintf(&string[stl]," time=%0.4f",f);
				}
				f=boptcoeff->item[i].macro[j].floating[2];
				if (f!=0.00)
				{
					stl=strlen(string);
					sprintf(&string[stl]," amplitude=%0.4f",f);
				}
				f=boptcoeff->item[i].macro[j].floating[3];
				if (f!=0.00)
				{
					stl=strlen(string);
					sprintf(&string[stl]," offsx=%0.4f",f);
				}
				f=boptcoeff->item[i].macro[j].floating[4];
				if (f!=0.00)
				{
					stl=strlen(string);
					sprintf(&string[stl]," offsy=%0.4f",f);
				}
				f=boptcoeff->item[i].macro[j].floating[5];
				if (f!=0.00)
				{
					stl=strlen(string);
					sprintf(&string[stl]," frequency=%0.4f",f);
				}
			}
			fprintf(fp,"%s\n",string);
		}

		float f;
		int m;
		char *jnames[5]={"a","b","c","d","e"};

		sprintf(string,"mv");
		notempty=0;
		for (j=0;j<5;j++)
		{
			f=boptcoeff->item[i].mv[j]; 
			if (f!=0.00)
			{
				notempty=1;
				stl=strlen(string);
				sprintf(&string[stl]," %s=%0.4f",jnames[j],f);
			}
		}
		if (notempty) fprintf(fp,"%s\n",string);
		sprintf(string,"ma");
		notempty=0;
		for (j=0;j<5;j++)
		{
			f=boptcoeff->item[i].ma[j]; 
			if (f!=0.00)
			{
				notempty=1;
				stl=strlen(string);
				sprintf(&string[stl]," %s=%0.4f",jnames[j],f);
			}
		}
		if (notempty) fprintf(fp,"%s\n",string);

		sprintf(string,"params");
		m=boptcoeff->item[i].params.integer[0];
		stl=strlen(string);
		sprintf(&string[stl]," tcpidx=%i",m);
		m=boptcoeff->item[i].params.integer[1];
		stl=strlen(string);
		sprintf(&string[stl]," blendtype=%i",m);
		f=boptcoeff->item[i].params.floating[0];
		if (f!=0.00)
		{
			stl=strlen(string);
			sprintf(&string[stl]," maxheight=%0.4f",f);
		}
		f=boptcoeff->item[i].params.floating[1];
		if (f!=0.00)
		{
			stl=strlen(string);
			sprintf(&string[stl]," minheight=%0.4f",f);
		}
		f=boptcoeff->item[i].params.floating[2];
		if (f!=0.00)
		{
			stl=strlen(string);
			sprintf(&string[stl]," samplerate=%0.4f",f);
		}
		f=boptcoeff->item[i].params.floating[3];
		if (f!=0.00)
		{
			stl=strlen(string);
			sprintf(&string[stl]," timefactor=%0.4f",f);
		}
		f=boptcoeff->item[i].params.floating[4];
		if (f!=0.00)
		{
			stl=strlen(string);
			sprintf(&string[stl]," maxlength=%0.4f",f);
		}
		f=boptcoeff->item[i].params.floating[5];
		if (f!=1000.0)
		{
			stl=strlen(string);
			sprintf(&string[stl]," lockv=%0.4f",f);
		}
		fprintf(fp,"%s\n",string);
	}
	fclose(fp);
	return TRUE;
}

int tmpnItemLoad(const char *filename, tmpnItem *item)
{
  FILE *fp;
  int version,user;
  float x,y,z,sy,gy,my,gx,weight;
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  strcpy(item->filename,filename);
  fscanf(fp,"VERSION %d\n",&version);
	if (version==2)
	{
		fscanf(fp,"%s %s dx=%f,dy=%f,dz=%f,sy=%f,gy=%f,my=%f,weight=%f\n"
					 ,item->type
					 ,item->name
					 ,&x
					 ,&y
					 ,&z
					 ,&sy
					 ,&gy
					 ,&my
					 ,&weight
					 );
	  item->dim.x = x;
	  item->dim.y = y;
		item->dim.z = z;
		item->sy    = sy;
		item->gy    = gy;
		item->my    = my;
		item->weight=weight;
		item->gx=item->dim.x;
    item->user  = 0;
		return TRUE;
	}
  else if (version==3)
  {
    fscanf(fp,"%s %s dx=%f,dy=%f,dz=%f,sy=%f,gy=%f,my=%f,gx=%f,weight=%f\n"
           ,item->type
           ,item->name
           ,&x
           ,&y
           ,&z
           ,&sy
           ,&gy
           ,&my
           ,&gx
           ,&weight
           );
	  item->dim.x = x;
	  item->dim.y = y;
		item->dim.z = z;
		item->sy    = sy;
		item->gy    = gy;
		item->my    = my;
		item->gx    = gx;
		item->weight=weight;
    item->user  = 0;
  }
  else if(version!=ITEMVERSION) return FALSE;
  fscanf(fp,"%s %s dx=%f,dy=%f,dz=%f,sy=%f,gy=%f,my=%f,gx=%f,weight=%f,user=%d\n"
				 ,item->type
				 ,item->name
				 ,&x
				 ,&y
				 ,&z
				 ,&sy
				 ,&gy
				 ,&my
				 ,&gx
				 ,&weight
         ,&user
				 );
  item->dim.x = x;
  item->dim.y = y;
  item->dim.z = z;
  item->sy    = sy;
  item->gy    = gy;
  item->my    = my;
  item->gx    = gx;
  item->weight=weight;
  item->user  = user;
  
  return TRUE;
}

int tmpnItemSave(tmpnItem *item)
{
  FILE *fp;
  if(item->user == 0)
  {
    printf("Couldn't save Item file: %s, user=0\n",item->filename);
    return FALSE;
  }
  
  fp = fopen(item->filename,"w");
  if(fp==NULL)
  {
    printf("Couldn't open Item file: %s\n",item->filename);
    return FALSE;
  }
	fprintf(fp,"VERSION %d\n",ITEMVERSION);
  
  fprintf(fp,"%s %s dx=%.2f,dy=%.2f,dz=%.2f,sy=%.2f,gy=%.2f,my=%.2f,gx=%.2f,weight=%.2f,user=%d\n"
          ,item->type
          ,item->name
          ,item->dim.x
          ,item->dim.y
          ,item->dim.z
          ,item->sy
          ,item->gy
          ,item->my
          ,item->gx
          ,item->weight
          ,item->user);
  fclose(fp);
  return TRUE;
}

int tmpnToolLoad(const char *filename, tmpnTool *tool)
{
  FILE *fp;
  int version;
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  fscanf(fp,"VERSION %d\n",&version);
  if(version!=TOOLVERSION) return FALSE;
  float x,y,z,weight;
	int ipl;
  fscanf(fp,"%s dx=%f,dy=%f,dz=%f,weight=%f,itemsperlift=%d\n"
				 ,tool->name
				 ,&x
				 ,&y
				 ,&z
				 ,&weight
				 ,&ipl
				 );
  tool->dim.x = x;
	tool->dim.y = y;
  tool->dim.z = z;
  tool->weight = weight;
	tool->itemsperlift=ipl;
  return TRUE;
}

int tmpnScopeLoad(const char *filename, tmpnPath *path)
{
  FILE *fp;
  char ax;
  int  idx,z;
  int  lastidx;
  int  axisidx;
  float dat;
  char buffer[256];
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  lastidx=0;
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
    sscanf(buffer,"%4d%c %f\n"
					 ,&idx
					 ,&ax
					 ,&dat);
    idx=idx*path->maxidx/MAXSCOPE;
    axisidx=0;
    if(ax=='A')
    {
      axisidx=0;
      dat=dat*0.19*1.6;
    }
    if(ax=='B')
    {
      axisidx=1;
      dat=dat*0.30*1.6;
    }
    if(ax=='C')
    {
      axisidx=2;
      dat=dat*0.19*1.6;
    }
    if(ax=='D')
    {
      axisidx=3;
      dat=dat*0.05*1.6;
    }
    if(ax=='E')
    {
      axisidx=4;
      dat=dat*0.05*1.6;
    }
    path->position[idx].scope.array[axisidx]=trobot->m_sign.array[axisidx]
                                            *trobot->m_gearing.array[axisidx]*dat;

    for(z=lastidx+1;z<idx;z++)
    {
      path->position[z].scope.array[axisidx]=path->position[idx].scope.array[axisidx];
    }
    lastidx=idx;
  }
  fclose(fp);
  return TRUE;
}

int tmpnAccessoryLoad(const char *filename, tmpnAccessory *accessory)
{
  FILE *fp;
  float x,y,z;
  int version;
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  fscanf(fp,"VERSION %d\n",&version);
  if(version!=ACCESSORYVERSION) return FALSE;
  fscanf(fp,"%s\n",accessory->name);
  fscanf(fp,"dimention x=%f,y=%f,z=%f\n"
    ,&x
    ,&y
    ,&z
    );
    accessory->dimention.x = x;
    accessory->dimention.y = y;
    accessory->dimention.z = z;
 
  fscanf(fp,"transformation x=%f,y=%f,z=%f\n"
    ,&accessory->transformation.x
    ,&accessory->transformation.y
    ,&accessory->transformation.z
    );
  fscanf(fp,"material diffuse r=%f,g=%f,b=%f,a=%f\n"
    ,&accessory->material.diffuse[0]
    ,&accessory->material.diffuse[1]
    ,&accessory->material.diffuse[2]
    ,&accessory->material.diffuse[3]
    );
  fscanf(fp,"material ambient r=%f,g=%f,b=%f,a=%f\n"
    ,&accessory->material.ambient[0]
    ,&accessory->material.ambient[1]
    ,&accessory->material.ambient[2]
    ,&accessory->material.ambient[3]
    );
  fscanf(fp,"material specular r=%f,g=%f,b=%f,a=%f\n"
    ,&accessory->material.specular[0]
    ,&accessory->material.specular[1]
    ,&accessory->material.specular[2]
    ,&accessory->material.specular[3]
    );
  fscanf(fp,"shininess=%f\n",&accessory->material.shininess);
  return TRUE;
}

tmpnItem *getItem(const char *name, tmpnWorkcell *workcell)
{
  int i;
  if(workcell==NULL) return NULL;
	if(name==NULL) return NULL;
  for(i=0;i<workcell->items.maxidx;i++)
  {
    if(strcmp(workcell->items.item[i].name,name)==0)
    {
      return &workcell->items.item[i];
    }
  }
  if(strcmp(name,"default")==0) return &workcell->items.item[0];
  return NULL;
}

tmpnTool *getTool(const char *name, tmpnWorkcell *workcell)
{
  int i;
  if(workcell==NULL) return NULL;
  for(i=0;i<workcell->tools.maxidx;i++)
  {
    if(strcmp(workcell->tools.tool[i].name,name)==0)
    {
      return &workcell->tools.tool[i];
    }
  }
  if(strcmp(name,"default")==0) return &workcell->tools.tool[0];
  return NULL;
}

tmpnPattern *getPattern(const char *name, tmpnWorkcell *workcell)
{
  int i;
  for(i=0;i<workcell->patterns.maxidx;i++)
  {
    if(strcmp(workcell->patterns.pattern[i].name,name)==0)
    {
      return &workcell->patterns.pattern[i];
    }
  }
  return NULL;
}

tmpnCPPattern *getCPPattern(const char *name, tmpnWorkcell *workcell)
{
  int i;
  for(i=0;i<workcell->cppatterns.maxidx;i++)
  {
    if(strcmp(workcell->cppatterns.cppattern[i].name,name)==0)
    {
      return &workcell->cppatterns.cppattern[i];
    }
  }
  return NULL;
}

tmpnPPScript *getPPScript(const char *name, tmpnWorkcell *workcell)
{
  int i;
  for(i=0;i<workcell->ppscripts.maxidx;i++)
  {
    if(strcmp(workcell->ppscripts.ppscript[i].name,name)==0)
    {
      return &workcell->ppscripts.ppscript[i];
    }
  }
  return NULL;
}

tmpnBoptCoeff *getBoptCoeff(tmpnWorkcell *workcell)
{
	if (workcell->boptcoeff.maxidx>0)
		return &workcell->boptcoeff;
  return NULL;
}

tmpnBoptCoeffItem *getBoptCoeffItem(tmpnBoptCoeff *boptcoeff, int mode, int pathtype)
{
	int i;
	for (i=0;i<boptcoeff->maxidx;i++)
	{
		if (mode==boptcoeff->item[i].mode&&pathtype==boptcoeff->item[i].pathtype)
		{
			return &boptcoeff->item[i];
		}
	}
	return NULL;
}

char *getLanguageLineFromIdx(tmpnLanguage *lang, int idx, char *defaultstring)
{
	if (idx<lang->maxidx&&idx>=0)
		return lang->item[idx].tekst;
	return defaultstring;
}

char *getLanguageLineFromKey(tmpnLanguage *lang, int key, char *defaultstring)
{
	int i;
	for (i=0;i<lang->maxidx;i++)
	{
		if (lang->item[i].key==key)
		{
			return lang->item[i].tekst;
		}
	}
	return defaultstring;
}

char *getLanguageLineFromEnglish(tmpnLanguage *lang, char *englishline, char *defaultstring)
{
	int i;
	for (i=0;i<lang->maxidx;i++)
	{
		if (!strcmp(lang->item[i].english,englishline))
		{
			return lang->item[i].tekst;
		}
	}
	return defaultstring;
}

int selectLanguage(tmpnLanguages *langs, char *languagename)
{
	int i;
	for (i=0;i<langs->numoflanguages;i++)
	{
		if (!strcmp(langs->language[i].name,languagename))
		{
			langs->currentLanguage=i;
			return i;
		}
	}
	return 0;
}

int getWorkcellIdx(const char *name, tmpnPlant *plant)
{
  int i;
  for(i=0;i<plant->workcells.maxidx;i++)
  {
    if(strcmp(plant->workcells.workcell[i].name,name)==0)
    {
      return i;
    }
  }
  return 0;
}

int getRobotIdx(const char *name, tmpnWorkcell *workcell)
{
  int i;
  for(i=0;i<workcell->robots.maxidx;i++)
  {
    if(strcmp(workcell->robots.robot[i].m_name,name)==0)
    {
      return i;
    }
  }
  return 0;
}

int AddProgram(int PrgStmIdx, char *newName, int copyfromidx)
{
	FILE *fp;
	int idx,i,j,h,newidx;
  char line[256];
  char temp[256];
	char *lines[MAXSTATEMACHINELINES]; //max accepted no. of lines i stmprgs
	int curstateidx;
	int copystartidx=0,copyendidx=0,insertidx=-1;
	int resetidx=-1;
	int num;
  i=0;
	newidx=0;
  idx = PrgStmIdx;
  if(idx==-1)
  {
    return FALSE;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
	curstateidx=-1;
	while (fgets(line,sizeof(line),fp)!=NULL)
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
		num = sscanf(line," State=%s ",temp);
		if (num==1)
		{
			curstateidx++;
			if (curstateidx==copyfromidx)
			{
				copystartidx=i;
			}
			if (curstateidx==(copyfromidx+1))
			{
				copyendidx=i-1;
			}
			if (strncmp(temp,"PROGRAM_",8)&&insertidx==-1)
			{
				insertidx=i;
				newidx=curstateidx;
			}
			if (!strcmp(temp,"ST_RESET")&&resetidx==-1)
			{
				resetidx=i+1;
			}
		}
		i++;
	}
  fclose(fp);
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==NULL) 
  { 
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  for (j=0;j<i;j++) 
   {
		if (j==insertidx)
		{
			 for (h=copystartidx;h<copyendidx;h++) 
			 {
				 if (sscanf(lines[h]," State=PROGRAM_%s",temp)==1)
				 {
					 fprintf(fp,"State=PROGRAM_%s\n",newName);
				 }
				 else if (sscanf(lines[h]," SETSTATE ST_RUNNING_%s" ,temp)==1)
				 {
					 fprintf(fp,"  SETSTATE ST_RUNNING_%s\n",newName);
				 }
				 else 
				 {
					 fprintf(fp,"%s",lines[h]);
				 }
			 }
			 fprintf(fp,"\n");
		}
		if (j==resetidx)
		{
			fprintf(fp,"  TEST programidx = %i\n",newidx);
			fprintf(fp,"    SETSTATE PROGRAM_%s\n",newName);
			fprintf(fp,"  ENDTEST\n");
		}
    fprintf(fp,"%s",lines[j]);
	}
	fprintf(fp,"\nState=ST_RUNNING_%s\n",newName);
	fprintf(fp,"  SET newprogram 0\n");
	fprintf(fp,"  TEST workcell = ST_IDLE\n");
	fprintf(fp,"  OR workcell = ST_PAUSED\n");
	fprintf(fp,"    TEST programidx != %i\n",newidx);
	fprintf(fp,"      SETSTATE ST_RESET\n");
	fprintf(fp,"    ENDTEST\n");
	fprintf(fp,"  ENDTEST\n");
	fprintf(fp,"END\n");
  fclose(fp);
  for (j=0;j<i;j++) 
  {
    free(lines[j]);
  }
	return TRUE;
}

int DeleteProgram(int PrgStmIdx,char *PrgName)
{
  FILE *fp;
	int idx,i;
	//	char *lines[MAXSTATEMACHINELINES]; //max accepted no. of lines i stmprgs
  i=0;
  idx = PrgStmIdx;
  if(idx==-1)
  {
    return FALSE;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
	return TRUE;
}

int SaveProgramVal(int PrgStmIdx,STMCOMMANDSTRUCT *stmcmd,char *prgname)
{
  int i,j,num,idx;
  FILE *fp;
  char line[256];
	char cname[256];
  char temp[256];
  int retval; 
	int correctstate=0;
  char *lines[MAXSTATEMACHINELINES]; //max accepted no. of lines i stmprgs
	int level;
  retval = FALSE;
  i=0;
  idx = PrgStmIdx;
  if(idx==-1)
  {
    return FALSE;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
	correctstate=0;
	level=0;
  while (fgets(line,sizeof(line),fp)!=NULL)
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
		num = sscanf(line," State=%s ",temp);
		if (num==1&&(!strcmp(temp,prgname)))
			correctstate=1;
		else if (num==1&&(strcmp(temp,prgname)))
			correctstate=0;
		if (correctstate)
		{
			num = sscanf(line," %s ",temp);
			if (num==1&&!strcmp(temp,"TEST")) level++;
			else if (num==1&&!strcmp(temp,"ENDTEST")) level--;
			else 
			{
        if (stmcmd->type == SET)
        {
          num = sscanf(line," SET %s %s ",cname,temp);
          if (!level&&num==2)
          {
            SETSTRUCT *set = (SETSTRUCT*)stmcmd->data;
            if(!strcmp(cname,set->dest.valstring))
            {
              int j;
              int slen=strlen(line);
              char ws[256];
              ws[0]='\0';
              for (j=0;j<slen;j++)
              {
                if (line[j]=='S') 
                {
                  strncpy(ws,line,j+4);
                  ws[j+4]='\0';
                  break;
                }				
              }
              free(lines[i]);
              if (set->src.subtype==0)
                sprintf(line,"%s%s %d\n",ws,cname,set->src.number);
              if (set->src.subtype==1)
                sprintf(line,"%s%s %0.4f\n",ws,cname,set->src.fnumber);
              lines[i] = (char*)malloc(1+strlen(line));
              strcpy(lines[i],line);
              retval = TRUE;
            }
          }
        }
        else if (stmcmd->type == SETITEM)
        {
          num = sscanf(line," SETITEM %s %s ",cname,temp);
          if (!level&&num==2)
          {
            SETITEMSTRUCT *setitem = (SETITEMSTRUCT*)stmcmd->data;
            if(!strcmp(cname,setitem->dest))
            {
              int j;
              int slen=strlen(line);
              char ws[256];
              ws[0]='\0';
              for (j=0;j<slen;j++)
              {
                if (line[j]=='S') 
                {
                  strncpy(ws,line,j+8);
                  ws[j+8]='\0';
                  break;
                }				
              }
              free(lines[i]);
              sprintf(line,"%s%s %s\n",ws,cname,setitem->src);
              lines[i] = (char*)malloc(1+strlen(line));
              strcpy(lines[i],line);
              retval = TRUE;
            }
          }
        }
        else if (stmcmd->type == SETCPPATTERN)
        {
          num = sscanf(line," SETCPPATTERN %s %s ",cname,temp);
          if (!level&&num==2)
          {
            SETCPPATTERNSTRUCT *setcpp = (SETCPPATTERNSTRUCT*)stmcmd->data;
            if(!strcmp(cname,setcpp->dest))
            {
              int j;
              int slen=strlen(line);
              char ws[256];
              ws[0]='\0';
              for (j=0;j<slen;j++)
              {
                if (line[j]=='S') 
                {
                  strncpy(ws,line,j+13);
                  ws[j+13]='\0';
                  break;
                }				
              }
              free(lines[i]);
              sprintf(line,"%s%s %s\n",ws,cname,setcpp->src);
              lines[i] = (char*)malloc(1+strlen(line));
              strcpy(lines[i],line);
              retval = TRUE;
            }
          }
        }
			}
		}
		i++;			
  }
  fclose(fp);
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==NULL) 
  { 
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  for (j=0;j<i;j++) 
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);

  if(rs_param.statemachine_debug>2)
  {
    if (stmcmd->type == SET){
      SETSTRUCT *set = (SETSTRUCT*)stmcmd->data;
      if (set->src.subtype==0)
        printf("Edited Program SET statement %s=%d and saved to file %s.\n",set->dest.valstring,set->src.number, tworkcell->statemachines.statemachine[idx].filename);
      else
        printf("Edited Program SET statement %s=%0.4f and saved to file %s.\n",set->dest.valstring,set->src.fnumber, tworkcell->statemachines.statemachine[idx].filename);
    }else if (stmcmd->type == SETITEM){
      SETITEMSTRUCT *setitem = (SETITEMSTRUCT*)stmcmd->data;
      printf("Edited Program SETITEM statement %s=%s and saved to file %s.\n",setitem->dest,setitem->src, tworkcell->statemachines.statemachine[idx].filename);
    }
	}
  return TRUE;
}

int SaveConstVal(const char *stmname, const char *cname, tmpnStateMachineValue* val)
{
  int f,i,j,num,idx;
  FILE *fp;
  char line[256];
  char name[256];
  int retval;  
	float fnum;
  char *lines[MAXSTATEMACHINELINES]; //max accepted no. of lines i stmprgs
  retval = FALSE;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return FALSE;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  while (fgets(line,sizeof(line),fp)!=NULL)
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==FALSE)&&(!strncmp(line,"Const=",6)))
    {
			if (tworkcell->statemachines.statemachine[idx].version==2)
			{
				if (val->subtype==0)
				{
					if (sscanf(line,"Const=%d,%s %d",&f,name,&num)==3)
					{
						if ((!strcmp(name,cname)))
						{
							free(lines[i]);
							sprintf(line,"Const=%d,%s %d\n",f,name,val->data);
							lines[i] = (char*)malloc(1+strlen(line));
							strcpy(lines[i],line);
							retval = TRUE;
						}
					}
				}
				else
				{
					if (sscanf(line,"Const=%d,%s %f",&f,name,&fnum)==3)
					{
						if ((!strcmp(name,cname)))
						{
							free(lines[i]);
							sprintf(line,"Const=%d,%s %0.4f\n",f,name,val->fdata);
							lines[i] = (char*)malloc(1+strlen(line));
							strcpy(lines[i],line);
							retval = TRUE;
						}
					}
				}
			}
			else if (tworkcell->statemachines.statemachine[idx].version==STATEMACHINEVERSION)
			{
				if (val->subtype==0)
				{
					if (sscanf(line,"Const=%s %d",name,&num)==2)
					{
						if ((!strcmp(name,cname)))
						{
							free(lines[i]);
							sprintf(line,"Const=%s %d\n",name,val->data);
							lines[i] = (char*)malloc(1+strlen(line));
							strcpy(lines[i],line);
							retval = TRUE;
						}
					}
				}
				else
				{
					if (sscanf(line,"Const=%s %f",name,&fnum)==2)
					{
						if ((!strcmp(name,cname)))
						{
							free(lines[i]);
							sprintf(line,"Const=%s %0.4f\n",name,val->fdata);
							lines[i] = (char*)malloc(1+strlen(line));
							strcpy(lines[i],line);
							retval = TRUE;
						}
					}
				}  
			}
		}
    i++;
  }
  fclose(fp);
  if (!retval&&tworkcell->statemachines.statemachine[idx].version==2)
  {
    for (j=0;j<i;j++) 
    { 
      free(lines[j]);
    }
    printf("Couldn't find Const %s\n",cname);
    return FALSE;
  }
  if(!retval)
  {
    lines[i] = (char*)malloc(256);
  	if (val->subtype==0)
    { 
      sprintf(lines[i],"Const=%s %d\n",cname,val->data);
    }
    else
    { 
      sprintf(lines[i],"Const=%s %0.4f\n",cname,val->fdata);
    }
    printf("Couldn't find Const %s added to end of file\n",cname);
    retval=TRUE;
    i++;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==NULL) 
  { 
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  for (j=0;j<i;j++) 
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
		if (val->subtype==0)
			printf("Edited Const %s=%d (formerly = %d) and saved to file %s.\n",cname,val->data,num,tworkcell->statemachines.statemachine[idx].filename);
		else
			printf("Edited Const %s=%f (formerly = %f) and saved to file %s.\n",cname,val->fdata,fnum,tworkcell->statemachines.statemachine[idx].filename);
  }
  return TRUE;
}

int SaveTimeVal(const char *stmname, const char *timename,int val)
{
  int f,i,j,num,idx;
  FILE *fp;
  char line[256];
  char name[256];
  int retval;  
  char *lines[MAXSTATEMACHINELINES]; //max accepted no. of lines i stmprgs
  retval = FALSE;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return FALSE;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  while (fgets(line,sizeof(line),fp)!=NULL)
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==FALSE)&&(!strncmp(line,"Timeout=",8)))
    {
			if (tworkcell->statemachines.statemachine[idx].version==2)
			{
				if (sscanf(line,"Timeout=%d,%s %d",&f,name,&num)==3)
				{
					if ((!strcmp(name,timename)))
					{
						free(lines[i]);
						sprintf(line,"Timeout=%d,%s %d\n",f,name,val);
						lines[i] = (char*)malloc(1+strlen(line));
						strcpy(lines[i],line);
						retval = TRUE;
					}
				}    
			}
			else if (tworkcell->statemachines.statemachine[idx].version==STATEMACHINEVERSION)
			{
				if (sscanf(line,"Timeout=%s %d",name,&num)==2)
				{
					if ((!strcmp(name,timename)))
					{
						free(lines[i]);
						sprintf(line,"Timeout=%s %d\n",name,val);
						lines[i] = (char*)malloc(1+strlen(line));
					strcpy(lines[i],line);
					retval = TRUE;
					}
				}    
			}
		}
    i++;
  }
  fclose(fp);
  if (!retval&&tworkcell->statemachines.statemachine[idx].version==2)
  {
    for (j=0;j<i;j++) 
    { 
      free(lines[j]);
    }
    printf("Couldn't find timeout value %s\n",timename);
    return FALSE;
  }
  if(!retval)
  {
    lines[i] = (char*)malloc(256);
  	sprintf(lines[i],"Timeout=%s %d\n",timename,val);
    printf("Couldn't find Timeout %s added to end of file\n",timename);
    retval=TRUE;
    i++;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==NULL) 
  { 
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  for (j=0;j<i;j++) 
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
    printf("Edited timeoutval %s=%d (formerly = %d) and saved to file %s.\n",timename,val,num,tworkcell->statemachines.statemachine[idx].filename);
  }
  return TRUE;
}

int SaveItemVal(const char *stmname, const char *name, const char *itemName)
{
  int i,j,idx;
  FILE *fp;
  char line[256];
  char cname[256];
  char citemName[256];
  int retval;  
  char *lines[MAXSTATEMACHINELINES]; //max accepted no. of lines i stmprgs
  retval = FALSE;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return FALSE;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  while (fgets(line,sizeof(line),fp)!=NULL)
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==FALSE)&&(!strncmp(line,"Item=",5)))
    {
      if (tworkcell->statemachines.statemachine[idx].version==STATEMACHINEVERSION)
			{
				if (sscanf(line,"Item=%s %s",cname,citemName)==2)
				{
					if ((!strcmp(cname,name)))
					{
						free(lines[i]);
						sprintf(line,"Item=%s %s\n",name,itemName);
						lines[i] = (char*)malloc(1+strlen(line));
            strcpy(lines[i],line);
            retval = TRUE;
					}
				}    
			}
		}
    i++;
  }
  fclose(fp);
  if(!retval)
  {
    lines[i] = (char*)malloc(256);
  	sprintf(lines[i],"Item=%s %s\n",name,itemName);
    printf("Couldn't find Item %s added to end of file\n",name);
    retval=TRUE;
    i++;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==NULL) 
  { 
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  for (j=0;j<i;j++) 
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
    printf("Edited Item=%s %s (formerly = %s) and saved to file %s.\n",name,itemName,citemName,tworkcell->statemachines.statemachine[idx].filename);
  }
  return TRUE;
}

int SaveCPPatternVal(const char *stmname, const char *name, const char *cppName)
{
  int i,j,idx;
  FILE *fp;
  char line[256];
  char cname[256];
  char ccppName[256];
  int retval;  
  char *lines[MAXSTATEMACHINELINES]; //max accepted no. of lines i stmprgs
  retval = FALSE;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return FALSE;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  while (fgets(line,sizeof(line),fp)!=NULL)
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==FALSE)&&(!strncmp(line,"CPPattern=",10)))
    {
      if (tworkcell->statemachines.statemachine[idx].version==STATEMACHINEVERSION)
			{
				if (sscanf(line,"CPPattern=%s %s",cname,ccppName)==2)
				{
					if ((!strcmp(cname,name)))
					{
						free(lines[i]);
						sprintf(line,"CPPattern=%s %s\n",name,cppName);
						lines[i] = (char*)malloc(1+strlen(line));
            strcpy(lines[i],line);
            retval = TRUE;
					}
				}    
			}
		}
    i++;
  }
  fclose(fp);
  if(!retval)
  {
    lines[i] = (char*)malloc(256);
  	sprintf(lines[i],"CPPattern=%s %s\n",name,cppName);
    printf("Couldn't find CP Pattern %s added to end of file\n",name);
    retval=TRUE;
    i++;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
  if(fp==NULL) 
  { 
    printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  for (j=0;j<i;j++) 
  {
    fprintf(fp,"%s",lines[j]);
    free(lines[j]);
  }
  fclose(fp);
  if(rs_param.statemachine_debug>2)
  {
    printf("Edited CPPattern=%s %s (formerly = %s) and saved to file %s.\n",name,cppName,ccppName,tworkcell->statemachines.statemachine[idx].filename);
  }
  return TRUE;
}

int SaveFrameVal(const char *stmname, tmpnFrame *newfr)
{
	tmpnFrame oldfr;
  int i,j,idx;
  FILE *fp;
  char line[256];
  char name[256];
  int retval;  
  char *lines[MAXSTATEMACHINELINES]; //max accepted no. of lines i stmprgs
  retval = FALSE;
  i=0;
  idx = getMachineIdx(stmname);
  if(idx==-1)
  {
    return FALSE;
  }
  fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",tworkcell->statemachines.statemachine[idx].filename);
    return FALSE;
  }
  while (fgets(line,sizeof(line),fp)!=NULL)
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==FALSE)&&(!strncmp(line,"Frame=",6)))
    {
			if (tworkcell->statemachines.statemachine[idx].version==STATEMACHINEVERSION)
			{
				if (sscanf(line,"Frame=%s x=%f y=%f z=%f v=%f w=%f u=%f",name,&oldfr.x,&oldfr.y,&oldfr.z,&oldfr.v,&oldfr.w,&oldfr.u)==7)
				{
					if ((!strcmp(name,newfr->name)))
					{
						free(lines[i]);
						sprintf(line,"Frame=%s x=%0.4f y=%0.4f z=%0.4f v=%0.4f w=%0.4f u=%0.4f\n",name,newfr->x,newfr->y,newfr->z,newfr->v,newfr->w,oldfr.u);
						lines[i] = (char*)malloc(1+strlen(line));
						strcpy(lines[i],line);
						retval = TRUE;
					}
				}    
			}
		}
    i++;
  }
  fclose(fp);
	if (retval)
	{
		fp = fopen(tworkcell->statemachines.statemachine[idx].filename,"w");
		if(fp==NULL) 
		{ 
			printf("Couldn't open %s for writing!\n",tworkcell->statemachines.statemachine[idx].filename);
			return FALSE;
		}
		for (j=0;j<i;j++) 
		{
			fprintf(fp,"%s",lines[j]);
			free(lines[j]);
		}
		fclose(fp);
		if(rs_param.statemachine_debug>2)
		{
			printf("Edited framevalue %s and saved to file %s.\n",newfr->name,tworkcell->statemachines.statemachine[idx].filename);
		}
		return TRUE;
	}
	return FALSE;
}

int SaveMacInitVal(tmpnMac* mac, int modidx, int initidx)
{
  int i,j;
  FILE *fp;
	char cmpline[256];
	int cmplen;
  char line[256];
  int retval;
  char *lines[1000]; //max accepted no. of initlines i Mac-file
  retval = FALSE;
	i=0;
  fp = fopen(mac->filename,"r");
  if(fp==NULL) 
  {
    printf("Couldn't open %s for reading!\n",mac->filename);
    return FALSE;
  }	
	sprintf(cmpline,"Init%i=",mac->iotab[modidx].initdata[initidx].reg);
	cmplen=strlen(cmpline);
	printf("\"%s\" %i\n",cmpline,cmplen);
  while (fgets(line,sizeof(line),fp)!=NULL)
  {
    lines[i] = (char*)malloc(1+strlen(line));
    strcpy(lines[i],line);
    if ((retval==FALSE)&&(!strncmp(line,cmpline,cmplen)))
    {
			free(lines[i]);
			if (mac->iotab[modidx].initdata[initidx].type==MAC_LONGINT||mac->iotab[modidx].initdata[initidx].type==MAC_SHORTINT||mac->iotab[modidx].initdata[initidx].type==MAC_SHORTUINT)
			{
				if (!strncmp(&line[cmplen],"0x",2))
					sprintf(line,"%s0x%x \"%s\" \"%s\"",cmpline,mac->iotab[modidx].initdata[initidx].data, mac->iotab[modidx].initdata[initidx].key,mac->iotab[modidx].initdata[initidx].comment);
				else
					sprintf(line,"%s%i \"%s\" \"%s\"",cmpline,mac->iotab[modidx].initdata[initidx].data, mac->iotab[modidx].initdata[initidx].key,mac->iotab[modidx].initdata[initidx].comment);
				int tmplen;
				tmplen=strlen(line);
				switch (mac->iotab[modidx].initdata[initidx].type)
				{				
				case MAC_LONGINT:
					sprintf(&line[tmplen]," longint\n");
					break;
				case MAC_SHORTINT:
					sprintf(&line[tmplen]," shortint\n");
					break;
				case MAC_SHORTUINT:
					sprintf(&line[tmplen]," shortuint\n");
					break;
				}
			}
			else
			{
				sprintf(line,"%s%0.4f \"%s\" \"%s\"",cmpline,mac->iotab[modidx].initdata[initidx].fdata, mac->iotab[modidx].initdata[initidx].key,mac->iotab[modidx].initdata[initidx].comment);
				int tmplen;
				tmplen=strlen(line);
				switch (mac->iotab[modidx].initdata[initidx].type)
				{				
				case MAC_LONGINT_ASFLOAT:
					sprintf(&line[tmplen]," longint factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
					break;
				case MAC_SHORTINT_ASFLOAT:
					sprintf(&line[tmplen]," shortint factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
					break;
				case MAC_SHORTUINT_ASFLOAT:
					sprintf(&line[tmplen]," shortuint factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
					break;
				case MAC_FIXED4:
					if (mac->iotab[modidx].initdata[initidx].factor!=1.0)
						sprintf(&line[tmplen]," fixed4 factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
					else
						sprintf(&line[tmplen]," fixed4\n");
					break;
				case MAC_FIXED8:
					if (mac->iotab[modidx].initdata[initidx].factor!=1.0)
						sprintf(&line[tmplen]," fixed8 factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
					else
						sprintf(&line[tmplen]," fixed8\n");
					break;
				case MAC_FIXED16:
					if (mac->iotab[modidx].initdata[initidx].factor!=1.0)
						sprintf(&line[tmplen]," fixed16 factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
					else
						sprintf(&line[tmplen]," fixed16\n");
					break;
				case MAC_FIXED24:
					if (mac->iotab[modidx].initdata[initidx].factor!=1.0)
						sprintf(&line[tmplen]," fixed24 factor=%0.6f\n",mac->iotab[modidx].initdata[initidx].factor);
					else
						sprintf(&line[tmplen]," fixed24\n");
					break;
				}
			}
			lines[i] = (char*)malloc(1+strlen(line));
			strcpy(lines[i],line);
			retval = TRUE;
		}
		i++;
	}
  fclose(fp);
	if (retval)
	{
		fp = fopen(mac->filename,"w");
		if(fp==NULL) 
		{ 
			printf("Couldn't open %s for writing!\n",mac->filename);
			return FALSE;
		}
		for (j=0;j<i;j++) 
		{
			fprintf(fp,"%s",lines[j]);
			free(lines[j]);
		}
		fclose(fp);
		if(rs_param.io_debug>0)
		{
			printf("Edited mac initvalue %s and saved to file %s.\n",mac->iotab[modidx].initdata[initidx].key,mac->filename);
		}
		return TRUE;
	}
	return FALSE;
}

int tmpnRobotSave(const char *fn, tmpnRobot *robot)
{
  int f,i;
  FILE *fp;
  char filename[256];

  sprintf(filename,"%s/robot/%s.robot",databasePath,fn);
  
  fp = fopen(filename,"w");
  if(fp==NULL) return FALSE;
  fprintf(fp,"VERSION %d\n",ROBOTVERSION);
  fprintf(fp,"m_name=%s\n",robot->m_name);
  fprintf(fp,"m_gantryLength=%3.2f,m_legHeight=%3.2f,m_shoulderGearB=%f\n"
   ,robot->m_gantryLength
   ,robot->m_legHeight
   ,robot->m_shoulderGearB );
  for(i=0;i<MAXLINK;i++)
  {
    fprintf(fp,"m_Link[%d]=%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f\n"
     ,i
     ,robot->m_Link[i].length
     ,robot->m_Link[i].mass
     ,robot->m_Link[i].massDisplacement[0]
     ,robot->m_Link[i].massDisplacement[1]
     ,robot->m_Link[i].massDisplacement[2]
     ,robot->m_Link[i].inertia[0][0]
     ,robot->m_Link[i].inertia[0][1]
     ,robot->m_Link[i].inertia[0][2]
     ,robot->m_Link[i].inertia[1][0]
     ,robot->m_Link[i].inertia[1][1]
     ,robot->m_Link[i].inertia[1][2]
     ,robot->m_Link[i].inertia[2][0]
     ,robot->m_Link[i].inertia[2][1]
     ,robot->m_Link[i].inertia[2][2]);
  }
  for(i=0;i<MAXSTATE;i++)
  {
    fprintf(fp,"m_State[%d]=%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f\n"
     ,i
     ,robot->m_State[i].length
     ,robot->m_State[i].mass
     ,robot->m_State[i].massDisplacement[0]
     ,robot->m_State[i].massDisplacement[1]
     ,robot->m_State[i].massDisplacement[2]
     ,robot->m_State[i].inertia[0][0]
     ,robot->m_State[i].inertia[0][1]
     ,robot->m_State[i].inertia[0][2]
     ,robot->m_State[i].inertia[1][0]
     ,robot->m_State[i].inertia[1][1]
     ,robot->m_State[i].inertia[1][2]
     ,robot->m_State[i].inertia[2][0]
     ,robot->m_State[i].inertia[2][1]
     ,robot->m_State[i].inertia[2][2]);
  }
  fprintf(fp,"m_sign.a=%1.0f,b=%1.0f,c=%1.0f,d=%1.0f,e=%1.0f,f=%1.0f\n"
   ,robot->m_sign.name.a
   ,robot->m_sign.name.b
   ,robot->m_sign.name.c
   ,robot->m_sign.name.d
   ,robot->m_sign.name.e
   ,robot->m_sign.name.f);
  fprintf(fp,"m_ratedNmGear.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_ratedNmGear.name.a
   ,robot->m_ratedNmGear.name.b
   ,robot->m_ratedNmGear.name.c
   ,robot->m_ratedNmGear.name.d
   ,robot->m_ratedNmGear.name.e
   ,robot->m_ratedNmGear.name.f);
  fprintf(fp,"m_ratedRpmGear.a=%1.0f,b=%1.0f,c=%1.0f,d=%1.0f,e=%1.0f,f=%1.0f\n"
   ,robot->m_ratedRpmGear.name.a
   ,robot->m_ratedRpmGear.name.b
   ,robot->m_ratedRpmGear.name.c
   ,robot->m_ratedRpmGear.name.d
   ,robot->m_ratedRpmGear.name.e
   ,robot->m_ratedRpmGear.name.f);
  fprintf(fp,"m_ratedRPM.a=%1.0f,b=%1.0f,c=%1.0f,d=%1.0f,e=%1.0f,f=%1.0f\n"
   ,robot->m_ratedRPM.name.a
   ,robot->m_ratedRPM.name.b
   ,robot->m_ratedRPM.name.c
   ,robot->m_ratedRPM.name.d
   ,robot->m_ratedRPM.name.e
   ,robot->m_ratedRPM.name.f);
  fprintf(fp,"m_ratedNm.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_ratedNm.name.a
   ,robot->m_ratedNm.name.b
   ,robot->m_ratedNm.name.c
   ,robot->m_ratedNm.name.d
   ,robot->m_ratedNm.name.e
   ,robot->m_ratedNm.name.f);
  fprintf(fp,"m_maxForceNm.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_maxForceNm.name.a
   ,robot->m_maxForceNm.name.b
   ,robot->m_maxForceNm.name.c
   ,robot->m_maxForceNm.name.d
   ,robot->m_maxForceNm.name.e
   ,robot->m_maxForceNm.name.f);
  fprintf(fp,"m_pulses.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_pulses.name.a
   ,robot->m_pulses.name.b
   ,robot->m_pulses.name.c
   ,robot->m_pulses.name.d
   ,robot->m_pulses.name.e
   ,robot->m_pulses.name.f);
  fprintf(fp,"m_gearing.a=%1.0f,b=%1.0f,c=%1.0f,d=%1.0f,e=%1.0f,f=%1.0f\n"
   ,robot->m_gearing.name.a
   ,robot->m_gearing.name.b
   ,robot->m_gearing.name.c
   ,robot->m_gearing.name.d
   ,robot->m_gearing.name.e
   ,robot->m_gearing.name.f);
  fprintf(fp,"m_unit.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_unit.name.a
   ,robot->m_unit.name.b
   ,robot->m_unit.name.c
   ,robot->m_unit.name.d
   ,robot->m_unit.name.e
   ,robot->m_unit.name.f);
/************************************************************************/
/* units=gearing*pulses/unit                                            */
/************************************************************************/
  fprintf(fp,"m_units.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_units.name.a
   ,robot->m_units.name.b
   ,robot->m_units.name.c
   ,robot->m_units.name.d
   ,robot->m_units.name.e
   ,robot->m_units.name.f);
  fprintf(fp,"m_p_gain.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_p_gain.name.a
   ,robot->m_p_gain.name.b
   ,robot->m_p_gain.name.c
   ,robot->m_p_gain.name.d
   ,robot->m_p_gain.name.e
   ,robot->m_p_gain.name.f);
  fprintf(fp,"m_i_gain.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_i_gain.name.a
   ,robot->m_i_gain.name.b
   ,robot->m_i_gain.name.c
   ,robot->m_i_gain.name.d
   ,robot->m_i_gain.name.e
   ,robot->m_i_gain.name.f);
  fprintf(fp,"m_d_gain.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_d_gain.name.a
   ,robot->m_d_gain.name.b
   ,robot->m_d_gain.name.c
   ,robot->m_d_gain.name.d
   ,robot->m_d_gain.name.e
   ,robot->m_d_gain.name.f);
  fprintf(fp,"m_vff_gain.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_vff_gain.name.a
   ,robot->m_vff_gain.name.b
   ,robot->m_vff_gain.name.c
   ,robot->m_vff_gain.name.d
   ,robot->m_vff_gain.name.e
   ,robot->m_vff_gain.name.f);
  fprintf(fp,"m_speed.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_speed.name.a
   ,robot->m_speed.name.b
   ,robot->m_speed.name.c
   ,robot->m_speed.name.d
   ,robot->m_speed.name.e
   ,robot->m_speed.name.f);
  fprintf(fp,"m_accel.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_accel.name.a
   ,robot->m_accel.name.b
   ,robot->m_accel.name.c
   ,robot->m_accel.name.d
   ,robot->m_accel.name.e
   ,robot->m_accel.name.f);
  fprintf(fp,"m_decel.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_decel.name.a
   ,robot->m_decel.name.b
   ,robot->m_decel.name.c
   ,robot->m_decel.name.d
   ,robot->m_decel.name.e
   ,robot->m_decel.name.f);
  fprintf(fp,"m_creep.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_creep.name.a
   ,robot->m_creep.name.b
   ,robot->m_creep.name.c
   ,robot->m_creep.name.d
   ,robot->m_creep.name.e
   ,robot->m_creep.name.f);
  fprintf(fp,"m_jogspeed.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_jogspeed.name.a
   ,robot->m_jogspeed.name.b
   ,robot->m_jogspeed.name.c
   ,robot->m_jogspeed.name.d
   ,robot->m_jogspeed.name.e
   ,robot->m_jogspeed.name.f);
  fprintf(fp,"m_felimit.a=%3.4f,b=%3.4f,c=%3.4f,d=%3.4f,e=%3.4f,f=%3.4f\n"
   ,robot->m_felimit.name.a
   ,robot->m_felimit.name.b
   ,robot->m_felimit.name.c
   ,robot->m_felimit.name.d
   ,robot->m_felimit.name.e
   ,robot->m_felimit.name.f);


  fprintf(fp,"m_min.x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_min.x
   ,robot->m_min.y
   ,robot->m_min.z
   ,robot->m_min.v
   ,robot->m_min.w
   ,robot->m_min.u);
  fprintf(fp,"m_max.x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_max.x
   ,robot->m_max.y
   ,robot->m_max.z
   ,robot->m_max.v
   ,robot->m_max.w
   ,robot->m_max.u);
  fprintf(fp,"m_localTrans.x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_localTrans.x
   ,robot->m_localTrans.y
   ,robot->m_localTrans.z
   ,robot->m_localTrans.v
   ,robot->m_localTrans.w
   ,robot->m_localTrans.u);
  fprintf(fp,"m_jointCalib.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_jointCalib.a
   ,robot->m_jointCalib.b
   ,robot->m_jointCalib.c
   ,robot->m_jointCalib.d
   ,robot->m_jointCalib.e
   ,robot->m_jointCalib.f);
  fprintf(fp,"m_mpnhome.a=%3.2f,b=%3.2f,c=%3.2f,d=%3.2f,e=%3.2f,f=%3.2f\n"
   ,robot->m_mpnhome.a
   ,robot->m_mpnhome.b
   ,robot->m_mpnhome.c
   ,robot->m_mpnhome.d
   ,robot->m_mpnhome.e
   ,robot->m_mpnhome.f);
  fprintf(fp,"m_tcpTrans[case].x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_tcp[0].x
   ,robot->m_tcp[0].y
   ,robot->m_tcp[0].z
   ,robot->m_tcp[0].v
   ,robot->m_tcp[0].w
   ,robot->m_tcp[0].u);
  fprintf(fp,"m_tcpTrans[bag].x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_tcp[1].x
   ,robot->m_tcp[1].y
   ,robot->m_tcp[1].z
   ,robot->m_tcp[1].v
   ,robot->m_tcp[1].w
   ,robot->m_tcp[1].u);
  fprintf(fp,"m_tcpTrans[zero].x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
   ,robot->m_tcp[2].x
   ,robot->m_tcp[2].y
   ,robot->m_tcp[2].z
   ,robot->m_tcp[2].v
   ,robot->m_tcp[2].w
   ,robot->m_tcp[2].u);
  for(f=0;f<robot->m_frames.maxidx;f++)
  {
    fprintf(fp,"FRAME %s x=%3.2f,y=%3.2f,z=%3.2f,v=%3.2f,w=%3.2f,u=%3.2f\n"
     ,robot->m_frames.frame[f].name
     ,robot->m_frames.frame[f].x
     ,robot->m_frames.frame[f].y
     ,robot->m_frames.frame[f].z
     ,robot->m_frames.frame[f].v
     ,robot->m_frames.frame[f].w
     ,robot->m_frames.frame[f].u
      );
  }
  for(f=0;f<robot->timing.maxidx;f++)
  {
    fprintf(fp,"TIMING %s %3.2f\n"
     ,robot->timing.item[f].name
     ,robot->timing.item[f].value
      );
  }
  fclose(fp);
  return TRUE;
}

static void updateRobot(char *s, tmpnRobot *robot, int version)
{
  int i,j;
  if(strncmp(s,"m_name=",7)==0)
  {
    sscanf(s,"m_name=%s\n",robot->m_name);
  }
  else if(strncmp(s,"m_gantryLength=",15)==0)
  {
    sscanf(s,"m_gantryLength=%f,m_legHeight=%f,m_shoulderGearB=%f\n"
     ,&robot->m_gantryLength
     ,&robot->m_legHeight
     ,&robot->m_shoulderGearB);
  }
  else if(strncmp(s,"m_Link[",7)==0)
  {
    sscanf(s,"m_Link[%d]",&i);
    sscanf(s,"m_Link[%d]=%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n"
     ,&j
     ,&robot->m_Link[i].length
     ,&robot->m_Link[i].mass
     ,&robot->m_Link[i].massDisplacement[0]
     ,&robot->m_Link[i].massDisplacement[1]
     ,&robot->m_Link[i].massDisplacement[2]
     ,&robot->m_Link[i].inertia[0][0]
     ,&robot->m_Link[i].inertia[0][1]
     ,&robot->m_Link[i].inertia[0][2]
     ,&robot->m_Link[i].inertia[1][0]
     ,&robot->m_Link[i].inertia[1][1]
     ,&robot->m_Link[i].inertia[1][2]
     ,&robot->m_Link[i].inertia[2][0]
     ,&robot->m_Link[i].inertia[2][1]
     ,&robot->m_Link[i].inertia[2][2]);
  }
  else if(strncmp(s,"m_State[",8)==0)
  {
    sscanf(s,"m_State[%d]",&i);
    sscanf(s,"m_State[%d]=%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n"
     ,&j
     ,&robot->m_State[i].length
     ,&robot->m_State[i].mass
     ,&robot->m_State[i].massDisplacement[0]
     ,&robot->m_State[i].massDisplacement[1]
     ,&robot->m_State[i].massDisplacement[2]
     ,&robot->m_State[i].inertia[0][0]
     ,&robot->m_State[i].inertia[0][1]
     ,&robot->m_State[i].inertia[0][2]
     ,&robot->m_State[i].inertia[1][0]
     ,&robot->m_State[i].inertia[1][1]
     ,&robot->m_State[i].inertia[1][2]
     ,&robot->m_State[i].inertia[2][0]
     ,&robot->m_State[i].inertia[2][1]
     ,&robot->m_State[i].inertia[2][2]);
  }
  else if(strncmp(s,"m_sign.a=",9)==0)
  {
    sscanf(s,"m_sign.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_sign.name.a
     ,&robot->m_sign.name.b
     ,&robot->m_sign.name.c
     ,&robot->m_sign.name.d
     ,&robot->m_sign.name.e
     ,&robot->m_sign.name.f);
  }
  else if(strncmp(s,"m_ratedRpmGear.a=",13)==0)
  {
    sscanf(s,"m_ratedRpmGear.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_ratedRpmGear.name.a
     ,&robot->m_ratedRpmGear.name.b
     ,&robot->m_ratedRpmGear.name.c
     ,&robot->m_ratedRpmGear.name.d
     ,&robot->m_ratedRpmGear.name.e
     ,&robot->m_ratedRpmGear.name.f);
  }
  else if(strncmp(s,"m_ratedNmGear.a=",13)==0)
  {
    sscanf(s,"m_ratedNmGear.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_ratedNmGear.name.a
     ,&robot->m_ratedNmGear.name.b
     ,&robot->m_ratedNmGear.name.c
     ,&robot->m_ratedNmGear.name.d
     ,&robot->m_ratedNmGear.name.e
     ,&robot->m_ratedNmGear.name.f);
  }
  else if(strncmp(s,"m_ratedRPM.a=",13)==0)
  {
    sscanf(s,"m_ratedRPM.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_ratedRPM.name.a
     ,&robot->m_ratedRPM.name.b
     ,&robot->m_ratedRPM.name.c
     ,&robot->m_ratedRPM.name.d
     ,&robot->m_ratedRPM.name.e
     ,&robot->m_ratedRPM.name.f);
  }
  else if(strncmp(s,"m_ratedNm.a=",12)==0)
  {
    sscanf(s,"m_ratedNm.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_ratedNm.name.a
     ,&robot->m_ratedNm.name.b
     ,&robot->m_ratedNm.name.c
     ,&robot->m_ratedNm.name.d
     ,&robot->m_ratedNm.name.e
     ,&robot->m_ratedNm.name.f);
  }
  else if(strncmp(s,"m_maxForceNm.a=",15)==0)
  {
    sscanf(s,"m_maxForceNm.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_maxForceNm.name.a
     ,&robot->m_maxForceNm.name.b
     ,&robot->m_maxForceNm.name.c
     ,&robot->m_maxForceNm.name.d
     ,&robot->m_maxForceNm.name.e
     ,&robot->m_maxForceNm.name.f);
  }
  else if(strncmp(s,"m_pulses.a=",11)==0)
  {
    sscanf(s,"m_pulses.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_pulses.name.a
     ,&robot->m_pulses.name.b
     ,&robot->m_pulses.name.c
     ,&robot->m_pulses.name.d
     ,&robot->m_pulses.name.e
     ,&robot->m_pulses.name.f);
  }
  else if(strncmp(s,"m_gearing.a=",12)==0)
  {
    sscanf(s,"m_gearing.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_gearing.name.a
     ,&robot->m_gearing.name.b
     ,&robot->m_gearing.name.c
     ,&robot->m_gearing.name.d
     ,&robot->m_gearing.name.e
     ,&robot->m_gearing.name.f);
  }
  else if(strncmp(s,"m_unit.a=",9)==0)
  {
    sscanf(s,"m_unit.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_unit.name.a
     ,&robot->m_unit.name.b
     ,&robot->m_unit.name.c
     ,&robot->m_unit.name.d
     ,&robot->m_unit.name.e
     ,&robot->m_unit.name.f);
  }
/************************************************************************/
/* units=gearing*pulses/unit                                            */
/************************************************************************/
  else if(strncmp(s,"m_p_gain.a=",11)==0)
  {
    sscanf(s,"m_p_gain.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_p_gain.name.a
   ,&robot->m_p_gain.name.b
   ,&robot->m_p_gain.name.c
   ,&robot->m_p_gain.name.d
   ,&robot->m_p_gain.name.e
   ,&robot->m_p_gain.name.f);
  }
  else if(strncmp(s,"m_i_gain.a=",11)==0)
  {
    sscanf(s,"m_i_gain.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_i_gain.name.a
   ,&robot->m_i_gain.name.b
   ,&robot->m_i_gain.name.c
   ,&robot->m_i_gain.name.d
   ,&robot->m_i_gain.name.e
   ,&robot->m_i_gain.name.f);
  }
  else if(strncmp(s,"m_d_gain.a=",11)==0)
  {
    sscanf(s,"m_d_gain.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_d_gain.name.a
   ,&robot->m_d_gain.name.b
   ,&robot->m_d_gain.name.c
   ,&robot->m_d_gain.name.d
   ,&robot->m_d_gain.name.e
   ,&robot->m_d_gain.name.f);
  }
  else if(strncmp(s,"m_vff_gain.a=",13)==0)
  {
    sscanf(s,"m_vff_gain.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_vff_gain.name.a
   ,&robot->m_vff_gain.name.b
   ,&robot->m_vff_gain.name.c
   ,&robot->m_vff_gain.name.d
   ,&robot->m_vff_gain.name.e
   ,&robot->m_vff_gain.name.f);
  }
  else if(strncmp(s,"m_speed.a=",10)==0)
  {
    sscanf(s,"m_speed.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_speed.name.a
   ,&robot->m_speed.name.b
   ,&robot->m_speed.name.c
   ,&robot->m_speed.name.d
   ,&robot->m_speed.name.e
   ,&robot->m_speed.name.f);
  }
  else if(strncmp(s,"m_accel.a=",10)==0)
  {
    sscanf(s,"m_accel.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_accel.name.a
   ,&robot->m_accel.name.b
   ,&robot->m_accel.name.c
   ,&robot->m_accel.name.d
   ,&robot->m_accel.name.e
   ,&robot->m_accel.name.f);
  }
  else if(strncmp(s,"m_decel.a=",10)==0)
  {
    sscanf(s,"m_decel.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_decel.name.a
   ,&robot->m_decel.name.b
   ,&robot->m_decel.name.c
   ,&robot->m_decel.name.d
   ,&robot->m_decel.name.e
   ,&robot->m_decel.name.f);
  }
  else if(strncmp(s,"m_creep.a=",10)==0)
  {
    sscanf(s,"m_creep.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_creep.name.a
   ,&robot->m_creep.name.b
   ,&robot->m_creep.name.c
   ,&robot->m_creep.name.d
   ,&robot->m_creep.name.e
   ,&robot->m_creep.name.f);
  }
  else if(strncmp(s,"m_jogspeed.a=",13)==0)
  {
    sscanf(s,"m_jogspeed.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_jogspeed.name.a
   ,&robot->m_jogspeed.name.b
   ,&robot->m_jogspeed.name.c
   ,&robot->m_jogspeed.name.d
   ,&robot->m_jogspeed.name.e
   ,&robot->m_jogspeed.name.f);
  }
  else if(strncmp(s,"m_felimit.a=",12)==0)
  {
    sscanf(s,"m_felimit.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
   ,&robot->m_felimit.name.a
   ,&robot->m_felimit.name.b
   ,&robot->m_felimit.name.c
   ,&robot->m_felimit.name.d
   ,&robot->m_felimit.name.e
   ,&robot->m_felimit.name.f);
  }
  else if(strncmp(s,"m_min.x=",8)==0)
  {
    sscanf(s,"m_min.x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_min.x
     ,&robot->m_min.y
     ,&robot->m_min.z
     ,&robot->m_min.v
     ,&robot->m_min.w
     ,&robot->m_min.u);
  }
  else if(strncmp(s,"m_max.x=",8)==0)
  {
    sscanf(s,"m_max.x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_max.x
     ,&robot->m_max.y
     ,&robot->m_max.z
     ,&robot->m_max.v
     ,&robot->m_max.w
     ,&robot->m_max.u);
  }
  else if(strncmp(s,"m_localTrans.x=",15)==0)
  {
    sscanf(s,"m_localTrans.x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_localTrans.x
     ,&robot->m_localTrans.y
     ,&robot->m_localTrans.z
     ,&robot->m_localTrans.v
     ,&robot->m_localTrans.w
     ,&robot->m_localTrans.u);
  }
  else if(strncmp(s,"m_jointCalib.a=",15)==0)
  {
    sscanf(s,"m_jointCalib.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_jointCalib.a
     ,&robot->m_jointCalib.b
     ,&robot->m_jointCalib.c
     ,&robot->m_jointCalib.d
     ,&robot->m_jointCalib.e
     ,&robot->m_jointCalib.f);
  }
  else if(strncmp(s,"m_mpnhome.a=",12)==0)
  {
    sscanf(s,"m_mpnhome.a=%f,b=%f,c=%f,d=%f,e=%f,f=%f\n"
     ,&robot->m_mpnhome.a
     ,&robot->m_mpnhome.b
     ,&robot->m_mpnhome.c
     ,&robot->m_mpnhome.d
     ,&robot->m_mpnhome.e
     ,&robot->m_mpnhome.f);
  }
  else if(strncmp(s,"m_tcpTrans[case].x=",19)==0)
  {
    strcpy(robot->m_tcp[0].name,"case");
    sscanf(s,"m_tcpTrans[case].x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_tcp[0].x
     ,&robot->m_tcp[0].y
     ,&robot->m_tcp[0].z
     ,&robot->m_tcp[0].v
     ,&robot->m_tcp[0].w
     ,&robot->m_tcp[0].u);
  }
  else if(strncmp(s,"m_tcpTrans[bag].x=",18)==0)
  {
    strcpy(robot->m_tcp[1].name,"bag");
    sscanf(s,"m_tcpTrans[bag].x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_tcp[1].x
     ,&robot->m_tcp[1].y
     ,&robot->m_tcp[1].z
     ,&robot->m_tcp[1].v
     ,&robot->m_tcp[1].w
     ,&robot->m_tcp[1].u);
  }
  else if(strncmp(s,"m_tcpTrans[zero].x=",19)==0)
  {
    strcpy(robot->m_tcp[2].name,"zero");
    sscanf(s,"m_tcpTrans[zero].x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
     ,&robot->m_tcp[2].x
     ,&robot->m_tcp[2].y
     ,&robot->m_tcp[2].z
     ,&robot->m_tcp[2].v
     ,&robot->m_tcp[2].w
     ,&robot->m_tcp[2].u);
  }
  else if(strncmp(s,"FRAME",5)==0)
  {
    sscanf(s,"FRAME %s x=%f,y=%f,z=%f,v=%f,w=%f,u=%f\n"
      ,robot->m_frames.frame[robot->m_frames.maxidx].name
      ,&robot->m_frames.frame[robot->m_frames.maxidx].x
      ,&robot->m_frames.frame[robot->m_frames.maxidx].y
      ,&robot->m_frames.frame[robot->m_frames.maxidx].z
      ,&robot->m_frames.frame[robot->m_frames.maxidx].v
      ,&robot->m_frames.frame[robot->m_frames.maxidx].w
      ,&robot->m_frames.frame[robot->m_frames.maxidx].u);
    robot->m_frames.maxidx++;
  }
  else if(strncmp(s,"SCRIPT",6)==0)
  {
    printf("this is an old type workcell. Please move SCRIPT statements to workcell\n");
  }
  else if(strncmp(s,"TIMING",6)==0)
  {
    sscanf(s,"TIMING %s %f\n"
      ,robot->timing.item[robot->timing.maxidx].name
      ,&robot->timing.item[robot->timing.maxidx].value);
    robot->timing.maxidx++;
  }
}

void copyAxisToRobotFile(tmpnRobot *robot)
{
 int i;
  for(i=0;i<6;i++) 
  {
    robot->m_p_gain.array[i]   = tspace.axis.array[i+1].p_gain;
    robot->m_i_gain.array[i]   = tspace.axis.array[i+1].i_gain;
    robot->m_d_gain.array[i]   = tspace.axis.array[i+1].d_gain;
    robot->m_ov_gain.array[i]  = tspace.axis.array[i+1].ov_gain;
    robot->m_vff_gain.array[i] = tspace.axis.array[i+1].vff_gain;
    robot->m_units.array[i]    = tspace.axis.array[i+1].units;
    robot->m_speed.array[i]    = tspace.axis.array[i+1].speed;
    robot->m_accel.array[i]  = tspace.axis.array[i+1].accel;
    robot->m_decel.array[i]  = tspace.axis.array[i+1].decel;
    robot->m_creep.array[i]  = tspace.axis.array[i+1].creep;
    robot->m_jogspeed.array[i] = tspace.axis.array[i+1].jogspeed;
    robot->m_felimit.array[i]  = tspace.axis.array[i+1].felimit;
  }
}

void copyAxisToTableSpace(tmpnRobot *robot)
{
 int i;
  for(i=0;i<6;i++) 
  {
    tspace.axis.array[i+1].p_gain   = robot->m_p_gain.array[i];
    tspace.axis.array[i+1].i_gain   = robot->m_i_gain.array[i];
    tspace.axis.array[i+1].d_gain   = robot->m_d_gain.array[i];
    tspace.axis.array[i+1].ov_gain  = robot->m_ov_gain.array[i];
    tspace.axis.array[i+1].vff_gain = robot->m_vff_gain.array[i];
    tspace.axis.array[i+1].units    = robot->m_units.array[i];
    tspace.axis.array[i+1].speed    = robot->m_speed.array[i];
    tspace.axis.array[i+1].accel    = robot->m_accel.array[i];
    tspace.axis.array[i+1].decel    = robot->m_decel.array[i];
    tspace.axis.array[i+1].creep    = robot->m_creep.array[i];
    tspace.axis.array[i+1].jogspeed = robot->m_jogspeed.array[i];
    tspace.axis.array[i+1].felimit  = robot->m_felimit.array[i];
  }
}

int tmpnRobotLoad(const char *filename, tmpnRobot *robot)
{
  FILE *fp;
  char buffer[256];
  int version;
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  fscanf(fp,"VERSION %d\n",&version);
  if(version==1||version==2||version==ROBOTVERSION)
  {
  }
  else
    return FALSE;
  robot->m_frames.maxidx=0;
  robot->timing.maxidx=0;
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
    updateRobot(buffer,robot,version);
  }
  fclose(fp);
  robot->m_simulateTRIO = 0;
  robot->splineorder = 4;
  robot->splinehint = 8;
  robot->m_localTrans.y=-(robot->m_shoulderGearB+robot->m_legHeight);
/************************************************************************/
/* units=gearing*pulses/unit                                            */
/************************************************************************/
  robot->m_units.name.a=robot->m_pulses.name.a*robot->m_gearing.name.a/robot->m_unit.name.a;
  robot->m_units.name.b=robot->m_pulses.name.b*robot->m_gearing.name.b/robot->m_unit.name.b;
  robot->m_units.name.c=robot->m_pulses.name.c*robot->m_gearing.name.c/robot->m_unit.name.c;
  robot->m_units.name.d=robot->m_pulses.name.d*robot->m_gearing.name.d/robot->m_unit.name.d;
  robot->m_units.name.e=robot->m_pulses.name.e*robot->m_gearing.name.e/robot->m_unit.name.e;
  robot->m_units.name.f=robot->m_pulses.name.f*robot->m_gearing.name.f/robot->m_unit.name.f;
  copyAxisToTableSpace(robot);
	// robot->m_localTrans.y=-(robot->m_shoulderGearB+robot->m_legHeight+FOOT_HEIGHT+GANTRY_HEIGHT);
//  robot->m_legHeight=-robot->m_localTrans.y-FOOT_HEIGHT-GANTRY_HEIGHT-robot->m_shoulderGearB;

  return TRUE;
}

void selectRobot(int i)
{
  trobot = &tworkcell->robots.robot[i];
//  printf("robot %s\n",trobot->m_name);
}

void selectWorkcell(int i)
{
  tworkcell = &tplant->workcells.workcell[i];
//  printf("workcell %s\n",tworkcell->name);
}

tmpnConnect *getConnectPtr(stbstruct *stb, char *name)
{
  int i;
  for(i=0;i<stb->maxidx;i++)
  {
    if(strcmp(stb->connect[i].name,name)==0) return &stb->connect[i];
  }
  return NULL;
} 

macConnect *getMacConnectPtr(tmpnStateMachine *stm, char *name)
{
  int i;

  i = getInputIdx(stm, name);
  if(i==-1)
  {
    i = getOutputIdx(stm, name);
    if(i==-1)
      return NULL;
    else
      if (stm->output[i].iotype == OUTMAC)
        return stm->output[i].macconnect;
      else 
        return NULL;
  }
  else
    if (stm->input[i].iotype == INMAC)
      return stm->input[i].macconnect;
    else 
      return NULL;
  
  return NULL;
}

void getConnectData(char *buffer, stbstruct *stb)
{
  int starti,i,j0=0;
  int idx;
  tmpnConnect *connect = &stb->connect[stb->maxidx];
  stb->maxidx++;
  starti=0;  
  if(strncmp(buffer,"Connect",7)==0&&(buffer[8]=='='||buffer[9]=='='))
  {
    idx=(buffer[7]-'0');
    if(buffer[8]!='=')
    {
      idx=idx*10+(buffer[8]-'0');
    }
    connect->bitidx=1<<(idx-1); 
    connect->wordidx=0;
    connect->shift=(idx-1);
    connect->mask=1;
    //Old style 
	  if(stb->type==STBDDI3420
	   ||stb->type==STBDDI3610)
    {
      connect->connectType=IBITDATA;
      connect->udata=&stb->odata[connect->wordidx];
    }
    else
    {
      connect->connectType=OBITDATA;
      connect->udata=&stb->odata[connect->wordidx];
    }
    sprintf(connect->name,"Connect%d",idx);
  }
  else if(strncmp(buffer,"OutConnect",10)==0&&(buffer[11]=='='||buffer[12]=='='))
  {
    connect->connectType=OBITDATA;
    idx=(buffer[10]-'0');

    if(buffer[11]!='=')
    {
      idx=idx*10+(buffer[11]-'0');
    }


    connect->bitidx=1<<(idx-1); 
    connect->wordidx=0;
    connect->shift=(idx-1);
    connect->mask=1;
    connect->udata=&stb->odata[connect->wordidx];
    sprintf(connect->name,"OutConnect%d",idx);
  }
  else if(strncmp(buffer,"InConnect",9)==0&&(buffer[10]=='='||buffer[11]=='='))
  {
    connect->connectType=IBITDATA;
    idx=(buffer[9]-'0');
    if(buffer[10]!='=')
    {
      idx=idx*10+(buffer[10]-'0');
    }
    connect->bitidx=1<<(idx-1); 
    connect->wordidx=0;
    connect->shift=(idx-1);
    connect->mask=1;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"InConnect%d",idx);
  }
  else if(strncmp(buffer,"Ready",5)==0)
  {
    connect->connectType=IBITDATA;
    idx=(buffer[5]-'0');
    if(idx==1) { connect->wordidx=0; connect->shift=0; }
    if(idx==2) { connect->wordidx=0; connect->shift=3; }
    if(idx==3) { connect->wordidx=0; connect->shift=6; }
    if(idx==4) { connect->wordidx=2; connect->shift=1; }
    connect->mask=1;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"Ready%d",idx);
  }    
  else if(strncmp(buffer,"Energized",9)==0)
  {
    connect->connectType=IBITDATA;
    idx=(buffer[9]-'0');
    if(idx==1) { connect->wordidx=0; connect->shift=1; }
    if(idx==2) { connect->wordidx=0; connect->shift=4; }
    if(idx==3) { connect->wordidx=0; connect->shift=7; }
    if(idx==4) { connect->wordidx=2; connect->shift=2; }
    connect->mask=1;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"Energized%d",idx);
  }    
  else if(strncmp(buffer,"Tripped",7)==0)
  {
    connect->connectType=IBITDATA;
    idx=(buffer[7]-'0');
    if(idx==1) { connect->wordidx=0; connect->shift=2; }
    if(idx==2) { connect->wordidx=0; connect->shift=5; }
    if(idx==3) { connect->wordidx=2; connect->shift=0; }
    if(idx==4) { connect->wordidx=2; connect->shift=3; }
    connect->mask=1;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"Tripped%d",idx);
  }    
  else if(strncmp(buffer,"InWord",6)==0)
  {
    connect->connectType=IWORDDATA;
    connect->wordidx=(buffer[6]-'0')-1;
    connect->shift=0;
    connect->mask=0xFFFF;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"InWord%d",connect->wordidx+1);
  }   
  else if(strncmp(buffer,"InShort",7)==0)
  {
    connect->connectType=ISHORTDATA;
    connect->wordidx=(buffer[7]-'0')-1;
    connect->shift=0;
    connect->mask=0xFFFF;
    connect->udata=&stb->idata[connect->wordidx];
    sprintf(connect->name,"InWord%d",connect->wordidx+1);
  }   
  else if(strncmp(buffer,"OutWord",7)==0)
  {
    connect->connectType=OWORDDATA;
    connect->wordidx=(buffer[7]-'0')-1;
    connect->shift=0;
    connect->mask=0xFFFF;
    connect->udata=&stb->odata[connect->wordidx];
    sprintf(connect->name,"OutWord%d",connect->wordidx+1);
  }   
  else if(strncmp(buffer,"OutShort",8)==0)
  {
    connect->connectType=OSHORTDATA;
    connect->wordidx=(buffer[8]-'0')-1;
    connect->shift=0;
    connect->mask=0xFFFF;
    connect->udata=&stb->odata[connect->wordidx];
    sprintf(connect->name,"OutWord%d",connect->wordidx+1);
  }   
  else
  {
    printf("Unknown connecttype '%s' in .io file\n",buffer);
    exit(99);
  }
  if(rs_param.statemachine_debug>2)
    printf("type=%d idx=%d shift=%d mask=%d\n",connect->connectType,connect->wordidx,connect->shift,connect->mask);
  for(i=0;i<strlen(buffer)-1;i++)
  {
    if(buffer[i]=='=') 
    {
      starti=i;
      break;
    }
  }
  starti+=2;
  for(i=starti;i<strlen(buffer)-1;i++)
  {
    if(buffer[i]=='"'&&buffer[i+1]==' '&&buffer[i+2]=='"')
    {
      j0=i;
			break;
    }
  }
	if (j0==0)
	{
		strcpy(connect->key, &buffer[starti]);
		connect->key[strlen(connect->key)-2]=0;
		sprintf(connect->text,"%s","");
	}
	else
	{
		strncpy(connect->key, &buffer[starti],j0-starti);
		connect->key[j0-starti]=0;
		strncpy(connect->text, &buffer[j0+3], strlen(&buffer[j0+3])-1);
		connect->text[strlen(&buffer[j0+3])-2]=0;
	}
}

int tmpnDIOLoad(const char *filename, tmpnDIO *dio)
{
  FILE *fp;
  char buffer[256];
  char sType[256];
  int io_version, i;
  stbstruct *stb=NULL;
  unsigned short *tmpiptr;
  unsigned short *tmpoptr;

  dio->numOfInWords = 0;
  dio->numOfOutWords = 0;
  dio->simulate = 0;
  dio->cleardioerror = FALSE;
  sprintf(dio->ipaddr,"%s","");
  dio->numOfModules = 0;
	tmpiptr = dio->idata;
	tmpoptr = dio->odata;
	
  fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("LoadDioConf: Unknown file %s\n",filename);
    return FALSE;
  }
  fscanf(fp,"IOVERSION %d\n",&io_version);
  if(io_version!=DIOVERSION)
  {
//    if(io_version==1) 
//      printf("LoadDioConf: IOVERSION is no longer valid\n");
//    else  
      printf("LoadDioConf: Unknown version %d\n", io_version);
    exit(99);
  }
  i=0;	
  while(fgets(buffer,sizeof(buffer), fp)!=NULL)
  {
    if(strncmp(buffer,"NumOfModules=",13)==0)
    {
      sscanf(buffer,"NumOfModules=%d\n",&dio->numOfModules);
      dio->iotab = malloc(sizeof(stbstruct)*dio->numOfModules);
      i=-1;
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&dio->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",dio->ipaddr);
    }
    else if(strncmp(buffer,"Type=",5)==0)
    {
      i++;
      if(i+1 > dio->numOfModules)
      {
        printf("Error: '%s' contains more dios than numOfModules (%d)\n", filename, dio->numOfModules);
        exit(99);
      }
      
//      dio->iotab[i].data =  malloc(sizeof(stbstruct));
    	stb = (stbstruct *)&dio->iotab[i];
      stb->maxidx=0;
      stb->numOfInWords=0;
      stb->numOfOutWords=0;
      sscanf(buffer,"Type=%s\n",sType);
  		strcpy(stb->typeStr,sType); 
      if(strcmp(sType, "EHC3020")==0) 
			{ 
				stb->type=STBEHC3020; 
				stb->numOfInWords=6; 
				stb->numOfOutWords=5; 
			}
      else if(strcmp(sType, "STB3420DDI")==0||strcmp(sType, "DDI3420")==0)
                        {
				stb->type=STBDDI3420;
	      stb->numOfInWords=2; 
				stb->numOfOutWords=0; 
			}
    	else if(strcmp(sType, "STB3610DDI")==0||strcmp(sType, "DDI3610")==0)
			{
				stb->type=STBDDI3610;
	      stb->numOfInWords=2; 
				stb->numOfOutWords=0; 
			}
    	else if(strcmp(sType, "STB3725DDI")==0||strcmp(sType, "DDI3725")==0)
			{
				stb->type=STBDDI3725;
	      stb->numOfInWords=1; 
				stb->numOfOutWords=0; 
			}
      else if(strcmp(sType, "STB3705DDO")==0||strcmp(sType, "DDO3705")==0)
			{
				stb->type=STBDDO3600;
	      stb->numOfInWords=0; 
				stb->numOfOutWords=1; 
	 		}
      else if(strcmp(sType, "STB3600DDO")==0||strcmp(sType, "DDO3600")==0)
			{
				stb->type=STBDDO3600;
	      stb->numOfInWords=2; 
				stb->numOfOutWords=1; 
	 		}
      else if(strcmp(sType, "EPI2145")==0)
			{
				stb->type=STBEPI2145;
	      stb->numOfInWords=6; 
				stb->numOfOutWords=1; 
			}
      else if(strcmp(sType, "AVI1270")==0)
			{
				stb->type=STBAVI1270;
	      stb->numOfInWords=4; 
				stb->numOfOutWords=0; 
			}
      else if(strcmp(sType, "AVO1250")==0)
			{
				stb->type=STBAVO1250;
	      stb->numOfInWords=2; 
				stb->numOfOutWords=2; 
			}
      stb->idata = tmpiptr;
      stb->odata = tmpoptr;
      tmpiptr += stb->numOfInWords;
      tmpoptr += stb->numOfOutWords;
    }
    else if(strncmp(buffer,"Name=",5)==0)
    {  
      strncpy(stb->module_name, &buffer[5], strlen(&buffer[5])-1);
    }
    else 
		{
      getConnectData(buffer,stb); 
    }
  }
  fclose(fp);
  if(i+1 != dio->numOfModules)
  {
    printf("Error: numOfModules (%d) given in '%s' does not match number of dios detected (%d)\n",dio->numOfModules, filename, i+1);
    exit(99);
  }
  for(i=0;i<dio->numOfModules;i++)
  {
    dio->numOfInWords += dio->iotab[i].numOfInWords;
    dio->numOfOutWords += dio->iotab[i].numOfOutWords;
  }
  return TRUE;
}

int tmpnICPconLoad(const char *filename, tmpnICPcon *icpcon)
{
  FILE *fp;
  char buffer[256];
	int icp_version, i;
  icpconstruct *icp=NULL;
	icpcon->simulate = 0;
	sprintf(icpcon->ipaddr,"%s","");
  icpcon->numOfModules = 0;
	
  fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("LoadICPconConf: Unknown file %s\n",filename);
    return FALSE;
  }
  fscanf(fp,"ICPCONVERSION %d\n",&icp_version);
  if(icp_version!=ICPCONVERSION)
  {
		printf("LoadICPconConf: Unknown version %d\n", icp_version);
    exit(99);
  }
  i=0;	
  while(fgets(buffer,sizeof(buffer), fp)!=NULL)
  {
    if(strncmp(buffer,"NumOfModules=",13)==0)
    {
      sscanf(buffer,"NumOfModules=%d\n",&icpcon->numOfModules);
      icpcon->iotab = malloc(sizeof(icpconstruct)*icpcon->numOfModules);
      i=-1;
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&icpcon->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",icpcon->ipaddr);
    }
		else if(strncmp(buffer,"port=",5)==0)
    {
      sscanf(buffer,"port=%d\n",&icpcon->port);
    }
    else if(strncmp(buffer,"Type=",5)==0)
    {
      i++;
      if(i+1 > icpcon->numOfModules)
      {
        printf("Error: '%s' contains more icpcons than numOfModules (%d)\n", filename, icpcon->numOfModules);
        exit(99);
      }      
			icp = (icpconstruct *)&icpcon->iotab[i];
      icp->dosetup=0;
      icp->numOfInBits=0;
      icp->numOfOutBits=0;
			icp->address=0;
			icp->idata=0;
			icp->odata=0;
      sscanf(buffer,"Type=%s\n",icp->typeStr);
      if(strcmp(icp->typeStr, "7063BD")==0) 
			{
				icp->type=ICP_7063BD;
				icp->numOfInBits=8;
				icp->numOfOutBits=3;
			}
			else
			{
				printf("ICPcon: No other modules than 7063BD implemented at the time\n");
				exit(99);
			}
    }
    else if(strncmp(buffer,"Name=",5)==0)
    {  
			if (icp!=NULL)
			{
				strncpy(icp->module_name, &buffer[5], strlen(&buffer[5])-1);
			}
			else
			{
				printf("No module selected before line '%s' in .icpcon file\n",buffer);
				exit(99);
			}
    }
    else if(strncmp(buffer,"Address=",8)==0)
    {  
			if (icp!=NULL)
			{
				sscanf(buffer,"Address=%d\n",&icp->address);
			}
			else
			{
				printf("No module selected before line '%s' in .icpcon file\n",buffer);
				exit(99);
			}
    }
		else if(strncmp(buffer,"DoSetup=",8)==0)
    {
			if (icp!=NULL)
			{
				sscanf(buffer,"DoSetup=%d\n",&icp->dosetup);
			}
			else
			{
				printf("No module selected before line '%s' in .icpcon file\n",buffer);
				exit(99);
			}
		}
		else if (strncmp(buffer,"In",2)==0)
		{
			if (icp!=NULL)
			{
				int num=0;
				int dotplace;
				if (buffer[3]=='=')
				{
					num=buffer[2]-'0';
					dotplace=3;
				}
				else if (buffer[4]=='=')
				{
					num=(buffer[2]-'0')*10+(buffer[3]-'0');
					dotplace=4;
				}
				else
				{
					printf("ICPcon: The line '%s' can't be parsed!\n",buffer);
					exit(99);
				}
				if (num > icp->numOfInBits)
				{
					printf("ICPcon: index-range for line '%s' in .icpcon file is too high\n",buffer);
					exit(99);
				}
				icp->inconnect[num-1].bitpos=num-1;
				int dplace[2]={0,0};
				int success=0;
				int i,j;
				for (j=0;j<2;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=2)
				{
					printf("Unknown connecttype '%s' in .icpcon file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				strncpy(icp->inconnect[num-1].key,&buffer[dplace[0]+1],keylen);
				icp->inconnect[num-1].key[keylen]='\0';
				icp->inconnect[num-1].udata=&(icp->idata);
			}
			else
			{
				printf("No module selected before line '%s' in .icpcon file\n",buffer);
				exit(99);
			}
		}
		else if (strncmp(buffer,"Out",3)==0)
		{
			if (icp!=NULL)
			{
				int num=0;
				int dotplace;
				if (buffer[4]=='=')
				{
					num=buffer[3]-'0';
					dotplace=4;
				}
				else if (buffer[5]=='=')
				{
					num=(buffer[3]-'0')*10+(buffer[4]-'0');
					dotplace=5;
				}
				else
				{
					printf("ICPcon: The line '%s' can't be parsed!\n",buffer);
					exit(99);
				}
				if (num > icp->numOfOutBits)
				{
					printf("ICPcon: index-range for line '%s' in .icpcon file is too high\n",buffer);
					exit(99);
				}
				icp->outconnect[num-1].bitpos=num-1;
				int dplace[2]={0,0};
				int success=0;
				int i,j;
				for (j=0;j<2;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=2)
				{
					printf("Unknown connecttype '%s' in .icpcon file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				strncpy(icp->outconnect[num-1].key,&buffer[dplace[0]+1],keylen);
				icp->outconnect[num-1].key[keylen]='\0';
				icp->outconnect[num-1].udata=&(icp->odata);
			}
			else
			{
				printf("No module selected before line '%s' in .icpcon file\n",buffer);
				exit(99);
			}
		}
  }
  fclose(fp);
  if(i+1 != icpcon->numOfModules)
  {
    printf("Error: numOfModules (%d) given in '%s' does not match number of icpcon detected (%d)\n",icpcon->numOfModules, filename, i+1);
    exit(99);
  }
  return TRUE;
}

int tmpnUdpAgentLoad(const char *filename, tmpnUdpAgents *udpagents,int type)
{
  FILE *fp;
  char buffer[512];
	int version,fileversion=-1, i;
  tmpnUdpAgentStruct *udpagent=NULL;
  fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("Couldn't open udpagent file: %s\n",filename);
    return FALSE;
  }
	if (type==UDPSERVER)
	{
		fscanf(fp,"UDPSERVERVERSION %d\n",&fileversion);
		version=UDPSERVERVERSION;
	}
	else
	{
		fscanf(fp,"UDPCLIENTVERSION %d\n",&fileversion);
		version=UDPCLIENTVERSION;
	}
  if(fileversion!=version)
  {
    printf("UDP version mismatch. Detected version %d. Only supports %d\n",fileversion,version);
    fclose(fp);
    exit(99);
  }
	if (type==UDPSERVER)
	{
		if(udpagents->servers_maxidx==0)
			udpagents->server = (tmpnUdpAgentStruct *)malloc(sizeof(tmpnUdpAgentStruct));
		else
			udpagents->server = (tmpnUdpAgentStruct *)realloc(udpagents->server,sizeof(tmpnUdpAgentStruct)*(udpagents->servers_maxidx + 1));
		udpagent = &udpagents->server[udpagents->servers_maxidx++];
	}
	else
	{
		if(udpagents->clients_maxidx==0)
			udpagents->client = (tmpnUdpAgentStruct *)malloc(sizeof(tmpnUdpAgentStruct));
		else
			udpagents->client = (tmpnUdpAgentStruct *)realloc(udpagents->client,sizeof(tmpnUdpAgentStruct)*(udpagents->clients_maxidx + 1));
		udpagent = &udpagents->client[udpagents->clients_maxidx++];
	}
  udpagent->type=type;
	udpagent->simulate = 0;
	sprintf(udpagent->ipaddr,"%s","");
 	udpagent->maxqlines = 0;
  i=-1;	
  while(fgets(buffer,sizeof(buffer), fp)!=NULL)
  {
		if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&udpagent->simulate);
    }
    else if(strncmp(buffer,"serverip=",9)==0)
    {
      sscanf(buffer,"serverip=%s\n",udpagent->ipaddr);
    }
		else if(strncmp(buffer,"port=",5)==0)
    {
      sscanf(buffer,"port=%d\n",&udpagent->port);
    }
    else if(strncmp(buffer,"QUESTION",8)==0)
    {
      i++;
      if(i >= UDP_MAXQUESTIONS)
      {
        printf("Error: '%s' contains more QUESTION-lines than allowed (%d)\n", filename, UDP_MAXQUESTIONS);
        exit(99);
      }
			
			int dotplace=7;
			int i,j;
			int dplace[4]={0,0,0,0};
			int success=0;
			int vcount=0;
			int vtype[UDP_MAXFORMATVALUES]={0,0,0,0,0,0,0,0,0,0};
			for (j=0;j<4;j++)
			{
				for (i=dotplace+1;i<strlen(buffer);i++)
				{
					if (buffer[i]=='"') 
					{
						dplace[success++]=i;
							dotplace=i;
					}
					else if (success==2)
					{
						if (buffer[i]=='%')
						{
							// Find %f,%i and get the correct number of int and float pointers.
							if (buffer[i+1]=='f'||buffer[i+1]=='d')
								vtype[vcount]=1; //float
							else if (buffer[i+1]=='i'||buffer[i+1]=='d')
								vtype[vcount]=0; //integer
							else
							{
								printf("1. Unknown format in line '%s' in .udp file\n",buffer);
								exit(99);
							}
							vcount++;
						}
					}
				}
			}
			if (success!=4)
			{
				printf("2. Unknown QUESTION type '%s' in .udp file\n",buffer);
				exit(99);
			}
			if (strncmp(&buffer[dplace[1]+2],"RESPONSE",8))
			{
				printf("3. Unknown RESPONSE type '%s' in .udp file\n",buffer);
				exit(99);
			}
			// Save question and response format
			int questionlen=dplace[1]-dplace[0];
			int responselen=dplace[3]-dplace[2];
			tmpnUdpQuestionStruct *udpqstruct=&udpagent->qlines[udpagent->maxqlines];
			strncpy(udpqstruct->questionformat,&buffer[dplace[0]],questionlen);
			strncpy(udpqstruct->responseformat,&buffer[dplace[2]],responselen);
			udpqstruct->maxresponseval=0;
			dotplace=dplace[3]+1;
			for (i=dplace[3]+1;i<strlen(buffer);i++)
			{
				if (buffer[i]==':')
				{
					char stmname[128];
					char valname[128];
					if (sscanf(&buffer[i+1]," STMVAL(%127[^,],%127[^)]) ",stmname,valname)==2)
					{
						int stmidx;
						stmidx=getMachineIdx(stmname);
						if (stmidx==-1)
						{
							printf("4. Unknown Statemachine in RESPONSE-format '%s' in .udp file\n",buffer);
							exit(99);
						}
						udpqstruct->responseval[udpqstruct->maxresponseval]=(tmpnStateMachineValue *)getMachineValuePtr(stmidx, valname);
						if (udpqstruct->responseval[udpqstruct->maxresponseval]==NULL)
						{
							printf("5. Unknown Statemachine-value in RESPONSE-format '%s' in .udp file\n",buffer);
							exit(99);
						}
						if (udpqstruct->responseval[udpqstruct->maxresponseval]->subtype!=vtype[udpqstruct->maxresponseval])
						{
							printf("6. Mismatch between Statemachine-value type and format type in RESPONSE-format '%s' in .udp file\n",buffer);
							exit(99);
						}
						udpqstruct->maxresponseval++;
						if (udpqstruct->maxresponseval>vcount||udpqstruct->maxresponseval>UDP_MAXFORMATVALUES) 
						{
							printf("7. Too many STMVAL's for RESPONSE-format '%s' in .udp file\n",buffer);
							exit(99);
						}
						if (udpqstruct->maxresponseval==vcount&&type==UDPCLIENT)
						{
							float freq=1;
							if (sscanf(&buffer[i+1]," freq=%f ",&freq)==1)
							{
								udpqstruct->freq=freq;
							}
						}
					}
				}
			}
			if (udpqstruct->maxresponseval!=vcount)
			{
				printf("8. Mismatch beween format and STMVAL parameters for RESPONSE-format '%s' in .udp file\n",buffer);
				exit(99);
			}
			udpagent->maxqlines++; 
		}
  }
  fclose(fp);
  return TRUE;
}

int tmpnComSKLoad(const char *filename, tmpnComSK *comsk)
{
  FILE *fp;
  char buffer[256];
	char type[64];
  int comsk_version, i;
  comskstruct *freq=NULL;

	comsk->sfd=-1;
  comsk->simulate = 0;
  sprintf(comsk->ipaddr,"%s","");
  comsk->numOfModules = 0;
	comsk->type = -1;
	
  fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("LoadComskConf: Unknown file %s\n",filename);
    return FALSE;
  }
  fscanf(fp,"COMSKVERSION %d\n",&comsk_version);
  if(comsk_version!=COMSKVERSION)
  {
//    if(io_version==1) 
//      printf("LoadComskConf: IOVERSION is no longer valid\n");
//    else  
		printf("LoadComskConf: Unknown version %d\n", comsk_version);
    exit(99);
  }
  i=0;	
  while(fgets(buffer,sizeof(buffer), fp)!=NULL)
  {
    if(strncmp(buffer,"NumOfModules=",13)==0)
    {
      sscanf(buffer,"NumOfModules=%d\n",&comsk->numOfModules);
      comsk->iotab = malloc(sizeof(comskstruct)*comsk->numOfModules);
      i=-1;
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&comsk->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",comsk->ipaddr);
    }
    else if(strncmp(buffer,"Type=",5)==0)
    {
			type[63]='\0';
			sscanf(buffer,"Type=%63s",type);
			if (!strncmp(type,"WONLY",5)) comsk->type=0;
			else if (!strncmp(type,"RW",2)) comsk->type=1;
		}
		else if(strncmp(buffer,"Name=",5)==0)
    {
      i++;
    	freq = (comskstruct *)&comsk->iotab[i];
			freq->numOfInitWords=0;
      freq->numOfInWords=0;
      freq->numOfOutWords=0;
      sscanf(buffer,"Name=%255s\n",freq->module_name);
		}
		else if(strncmp(buffer,"Address=",8)==0)
		{  
			if (freq!=NULL)
			{
				sscanf(buffer,"Address=%d\n",&freq->address);
			}
    }
    else if (strncmp(buffer,"Init",4)==0)
		{
			if (freq!=NULL)
			{
				int dotplace=0;
				if (buffer[5]=='.')
				{
					freq->initdata[freq->numOfInitWords].major=buffer[4]-'0';
					dotplace=5;
				}
				else if (buffer[6]=='.')
				{
					freq->initdata[freq->numOfInitWords].major=10*(buffer[4]-'0')+(buffer[5]-'0');
					dotplace=6;
				}
				else
				{
					printf("1. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				if (buffer[dotplace+2]=='=')
				{
					freq->initdata[freq->numOfInitWords].minor=buffer[dotplace+1]-'0';
					dotplace+=2;
				}
				else if (buffer[dotplace+3]=='=')
				{
					freq->initdata[freq->numOfInitWords].minor=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
					dotplace+=3;
				}
				else
				{
					printf("2. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				float temp;
				if (sscanf(&buffer[dotplace+1],"%f",&temp)!=1)
				{	
					printf("3. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				freq->initdata[freq->numOfInitWords].fdata=temp;
				int i,j;
				int dplace[4]={0,0,0,0};
				int success=0;
				for (j=0;j<4;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=4)
				{
					printf("4. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				int commentlen=dplace[3]-dplace[2]-1;
				strncpy(freq->initdata[freq->numOfInitWords].key,&buffer[dplace[0]+1],keylen);
				freq->initdata[freq->numOfInitWords].key[keylen]='\0';
				strncpy(freq->initdata[freq->numOfInitWords].comment,&buffer[dplace[2]+1],commentlen);
				freq->initdata[freq->numOfInitWords].comment[commentlen]='\0';
				if (sscanf(&buffer[dplace[3]+1]," fixdec=%d",&freq->initdata[freq->numOfInitWords].fixdec)!=1)
				{	
					printf("5. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				freq->initdata[freq->numOfInitWords].factor=pow(10.0,(float)freq->initdata[freq->numOfInitWords].fixdec);
				freq->numOfInitWords++;
			}
		}
		else if (strncmp(buffer,"Output",6)==0)
		{
			if (freq!=NULL)
			{
				int dotplace=0;
				if (buffer[7]=='.')
				{
					freq->odata[freq->numOfOutWords].major=buffer[6]-'0';
					dotplace=7;
				}
				else if (buffer[8]=='.')
				{
					freq->odata[freq->numOfOutWords].major=10*(buffer[6]-'0')+(buffer[7]-'0');
					dotplace=8;
				}
				else
				{
					printf("1. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				if (buffer[dotplace+2]=='=')
				{
					freq->odata[freq->numOfOutWords].minor=buffer[dotplace+1]-'0';
					dotplace+=2;
				}
				else if (buffer[dotplace+3]=='=')
				{
					freq->odata[freq->numOfOutWords].minor=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
					dotplace+=3;
				}
				else
				{
					printf("2. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				int i,j;
				int dplace[4]={0,0,0,0};
				int success=0;
				for (j=0;j<4;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=4)
				{
					printf("3. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				int commentlen=dplace[3]-dplace[2]-1;
				strncpy(freq->odata[freq->numOfOutWords].key,&buffer[dplace[0]+1],keylen);
				freq->odata[freq->numOfOutWords].key[keylen]='\0';
				strncpy(freq->odata[freq->numOfOutWords].comment,&buffer[dplace[2]+1],commentlen);
				freq->odata[freq->numOfOutWords].comment[commentlen]='\0';
				if (sscanf(&buffer[dplace[3]+1]," fixdec=%d",&freq->odata[freq->numOfOutWords].fixdec)!=1)
				{	
					printf("4. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				freq->odata[freq->numOfOutWords].factor=pow(10.0,(float)freq->odata[freq->numOfOutWords].fixdec);
				freq->numOfOutWords++;
				if (freq->numOfOutWords>=COMSK_MAXVALS)
				{
					printf("Too many outputs specified for module %s\n",freq->module_name);
					exit(99);
				}
			}
		}
		else if (strncmp(buffer,"Input",5)==0)
		{
			if (freq!=NULL)
			{
				int dotplace=0;
				if (buffer[6]=='.')
				{
					freq->idata[freq->numOfInWords].major=buffer[5]-'0';
					dotplace=6;
				}
				else if (buffer[7]=='.')
				{
					freq->idata[freq->numOfInWords].major=10*(buffer[5]-'0')+(buffer[6]-'0');
					dotplace=7;
				}
				else
				{
					printf("1. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				if (buffer[dotplace+2]=='=')
				{
					freq->idata[freq->numOfInWords].minor=buffer[dotplace+1]-'0';
					dotplace+=2;
				}
				else if (buffer[dotplace+3]=='=')
				{
					freq->idata[freq->numOfInWords].minor=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
					dotplace+=3;
				}
				else
				{
					printf("2. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				int i,j;
				int dplace[4]={0,0,0,0};
				int success=0;
				for (j=0;j<4;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=4)
				{
					printf("3. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				int commentlen=dplace[3]-dplace[2]-1;
				strncpy(freq->idata[freq->numOfInWords].key,&buffer[dplace[0]+1],keylen);
				freq->idata[freq->numOfInWords].key[keylen]='\0';
				strncpy(freq->idata[freq->numOfInWords].comment,&buffer[dplace[2]+1],commentlen);
				freq->idata[freq->numOfInWords].comment[commentlen]='\0';
				if (sscanf(&buffer[dplace[3]+1]," fixdec=%d",&freq->idata[freq->numOfInWords].fixdec)!=1)
				{	
					printf("4. Unknown connecttype '%s' in .comsk file\n",buffer);
					exit(99);
				}
				freq->idata[freq->numOfInWords].factor=pow(10.0,(float)freq->idata[freq->numOfInWords].fixdec);
				freq->numOfInWords++;
				if (freq->numOfInWords>=COMSK_MAXVALS)
				{
					printf("Too many inputs specified for module %s\n",freq->module_name);
					exit(99);
				}
			}
		}
  }
  fclose(fp);
	if (comsk->type==0) //WONLY 
	{
		int i,j;
		// This mode uses broadcast so all modbus registers queried must lie aligned without gaps.
		int low=65556;
		int high=0;
		int tot=0;
		for (i=0;i<comsk->numOfModules;i++)
		{
			freq = (comskstruct *)&comsk->iotab[i];
			tot+=freq->numOfOutWords;
			for (j=0;j<freq->numOfOutWords;j++)
			{
				int adr = 100*freq->odata[j].major + freq->odata[j].minor;
				if (adr < low ) low=adr;
				if (adr > high ) high=adr;
			}
		}
		if (high-low != tot-1)
		{
			printf("COMSK: non-sequential output addresses not allowed when type=WONLY\n");
			exit(99);
		}
		comsk->highadr=high;
		comsk->lowadr=low;
		comsk->adrcount=tot;
		for (i=0;i<comsk->numOfModules;i++)
		{
			freq = (comskstruct *)&comsk->iotab[i];
			for (j=0;j<freq->numOfOutWords;j++)
			{
				// setup output-array
				int adr = 100*freq->odata[j].major + freq->odata[j].minor;
				freq->odata[j].data = &comsk->oarray[adr-comsk->lowadr];
			}
		}
	}
  return TRUE;
}

int tmpnMacLoad(const char *filename, tmpnMac *mac)
{
  FILE *fp;
  char buffer[256];
	char tempbuf[64];
  int mac_version, i;
  macstruct *motor=NULL;
	int initmode=1;
	int inoutbitmode=0;
	macConnect* bitparent=NULL;

	mac->sfd=-1;
  mac->simulate = 0;
  sprintf(mac->ipaddr,"%s","");
  mac->numOfMotors = 0;
	mac->port=0;
  fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("LoadMacConf: Unknown file %s\n",filename);
    return FALSE;
  }
	strcpy(mac->filename,filename);
  fscanf(fp,"MACVERSION %d\n",&mac_version);
  if(mac_version!=MACVERSION)
  {
		printf("LoadMacConf: Unknown version %d\n", mac_version);
    exit(99);
  }
  i=0;	
  while(fgets(buffer,sizeof(buffer), fp)!=NULL)
  {
    if(strncmp(buffer,"NumOfMotors=",12)==0)
    {
      sscanf(buffer,"NumOfMotors=%d\n",&mac->numOfMotors);
      mac->iotab = malloc(sizeof(macstruct)*mac->numOfMotors);
      i=-1;
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&mac->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",mac->ipaddr);
    }
    else if(strncmp(buffer,"port=",5)==0)
    {
			sscanf(buffer,"port=%i",&mac->port);
		}
		else if(strncmp(buffer,"Name=",5)==0)
    {
      i++;
    	motor = (macstruct *)&mac->iotab[i];
			motor->numOfInitWords=0;
      motor->numOfInWords=0;
      motor->numOfOutWords=0;
      sscanf(buffer,"Name=%255s\n",motor->module_name);
		}
		else if(strncmp(buffer,"Address=",8)==0)
		{  
			if (motor!=NULL)
			{
				sscanf(buffer,"Address=%d\n",&motor->address);
			}
    }
		else if (strncmp(buffer,"SaveToFlash",11)==0&&initmode==1)
		{
			motor->initdata[motor->numOfInitWords].type=MAC_CMD;
			motor->initdata[motor->numOfInitWords].reg=0x56;	
			motor->numOfInitWords++;
		}
		else if (strncmp(buffer,"SoftWareReset",13)==0&&initmode==1)
		{
			motor->initdata[motor->numOfInitWords].type=MAC_CMD;
			motor->initdata[motor->numOfInitWords].reg=0x57;			
			motor->numOfInitWords++;
		}
		else if (strncmp(buffer,"EnterSafeMode",13)==0&&initmode==1)
		{
			motor->initdata[motor->numOfInitWords].type=MAC_CMD;
			motor->initdata[motor->numOfInitWords].reg=0x54;			
			motor->numOfInitWords++;
		}
		else if (strncmp(buffer,"ExitSafeMode",12)==0&&initmode==1)
		{
			motor->initdata[motor->numOfInitWords].type=MAC_CMD;
			motor->initdata[motor->numOfInitWords].reg=0x55;			
			motor->numOfInitWords++;
		}
		else if (strncmp(buffer,"EndBits",7)==0&&initmode==0)
		{			
			inoutbitmode=0;
			bitparent=NULL;
		}
    else if (strncmp(buffer,"Init",4)==0&&initmode==1)
		{
			if (motor!=NULL)
			{
				motor->initdata[motor->numOfInitWords].userchange=0;
				int dotplace=0;
				if (buffer[5]=='=')
				{
					motor->initdata[motor->numOfInitWords].reg=buffer[4]-'0';
					dotplace=5;
				}
				else if (buffer[6]=='=')
				{
					motor->initdata[motor->numOfInitWords].reg=10*(buffer[4]-'0')+(buffer[5]-'0');
					dotplace=6;
				}
				else if (buffer[7]=='=')
				{
					motor->initdata[motor->numOfInitWords].reg=100*(buffer[4]-'0')+10*(buffer[5]-'0')+(buffer[6]-'0');
					dotplace=7;
				}
				else
				{
					printf("1. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				int temp;
				float ftemp;
				if (sscanf(&buffer[dotplace+1],"%f",&ftemp)==1)
				{	
					motor->initdata[motor->numOfInitWords].fdata=ftemp;
				}
				if (sscanf(&buffer[dotplace+1],"%i",&temp)==1)
				{	
					motor->initdata[motor->numOfInitWords].data=temp;
				}
				else if (!strncmp(&buffer[dotplace+1],"0x",2))
				{
					if (sscanf(&buffer[dotplace+1],"%x",&temp)!=1)
					{	
						printf("3.1 Unknown connecttype '%s' in .mac file\n",buffer);
						exit(99);
					}
					motor->initdata[motor->numOfInitWords].data=temp;
				}
				int i,j;
				int dplace[4]={0,0,0,0};
				int success=0;
				for (j=0;j<4;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=4)
				{
					printf("4. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				int commentlen=dplace[3]-dplace[2]-1;
				strncpy(motor->initdata[motor->numOfInitWords].key,&buffer[dplace[0]+1],keylen);
				motor->initdata[motor->numOfInitWords].key[keylen]='\0';
				strncpy(motor->initdata[motor->numOfInitWords].comment,&buffer[dplace[2]+1],commentlen);
				motor->initdata[motor->numOfInitWords].comment[commentlen]='\0';
				int tempdot;
				if (sscanf(&buffer[dplace[3]+1]," %64s%n",tempbuf,&tempdot)!=1)
				{	
					printf("5. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				tempbuf[63]='\0';
				if (!strcmp(tempbuf,"longint"))
				{
					motor->initdata[motor->numOfInitWords].type=MAC_LONGINT;
				}
				else if (!strcmp(tempbuf,"shortint")||!strcmp(tempbuf,"integer"))
				{ 
					motor->initdata[motor->numOfInitWords].type=MAC_SHORTINT;
				}
				else if (!strcmp(tempbuf,"shortuint")||!strcmp(tempbuf,"word"))
				{ 
					motor->initdata[motor->numOfInitWords].type=MAC_SHORTUINT;
				}
				else if (!strcmp(tempbuf,"fixed24"))
				{
					motor->initdata[motor->numOfInitWords].type=MAC_FIXED24;
				}
				else if (!strcmp(tempbuf,"fixed16"))
				{ 
					motor->initdata[motor->numOfInitWords].type=MAC_FIXED16;
				}
				else if (!strcmp(tempbuf,"fixed8"))
				{ 
					motor->initdata[motor->numOfInitWords].type=MAC_FIXED8;
				}
				else if (!strcmp(tempbuf,"fixed4"))
				{ 
					motor->initdata[motor->numOfInitWords].type=MAC_FIXED4;
				}
				else
				{
					printf("6. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				if (sscanf(&buffer[dplace[3]+tempdot+1]," factor=%f",&motor->initdata[motor->numOfInitWords].factor)!=1)
				{
					motor->initdata[motor->numOfInitWords].factor=1.0;
				}
				else
				{
					if (motor->initdata[motor->numOfInitWords].type==MAC_LONGINT)
						motor->initdata[motor->numOfInitWords].type=MAC_LONGINT_ASFLOAT;
					else if (motor->initdata[motor->numOfInitWords].type==MAC_SHORTINT)
						motor->initdata[motor->numOfInitWords].type=MAC_SHORTINT_ASFLOAT;
					else if (motor->initdata[motor->numOfInitWords].type==MAC_SHORTUINT)
						motor->initdata[motor->numOfInitWords].type=MAC_SHORTUINT_ASFLOAT;
				}
				motor->numOfInitWords++;
				if (motor->numOfInitWords>=MAC_MAXINITS)
				{
					printf("Too many inits specified for module %s\n",motor->module_name);
					exit(99);
				}
			}
		}
		else if (strncmp(buffer,"Out",3)==0)
		{
			if (inoutbitmode!=0)
			{
				printf("Illegal bitmode %s in %s\n",buffer,motor->module_name);
				exit(99);
			}
			initmode=0;
			if (motor!=NULL)
			{
				motor->odata[motor->numOfOutWords].userchange=0;
				int dotplace=2;
				if (buffer[dotplace+2]=='=')
				{
					motor->odata[motor->numOfOutWords].reg=buffer[dotplace+1]-'0';
					dotplace+=2;
				}
				else if (buffer[dotplace+3]=='=')
				{
					motor->odata[motor->numOfOutWords].reg=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
					dotplace+=3;
				}
				else if (buffer[dotplace+4]=='=')
				{
					motor->odata[motor->numOfOutWords].reg=100*(buffer[dotplace+1]-'0')+10*(buffer[dotplace+2]-'0')+(buffer[dotplace+3]-'0');
					dotplace+=4;
				}
				else
				{
					printf("2. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				int i,j;
				int dplace[4]={0,0,0,0};
				int success=0;
				for (j=0;j<4;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=4)
				{
					printf("3. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				int commentlen=dplace[3]-dplace[2]-1;
				strncpy(motor->odata[motor->numOfOutWords].key,&buffer[dplace[0]+1],keylen);
				motor->odata[motor->numOfOutWords].key[keylen]='\0';
				strncpy(motor->odata[motor->numOfOutWords].comment,&buffer[dplace[2]+1],commentlen);
				motor->odata[motor->numOfOutWords].comment[commentlen]='\0';
				int tempdot;
				if (sscanf(&buffer[dplace[3]+1]," %64s%n",tempbuf,&tempdot)!=1)
				{	
					printf("5. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				tempbuf[63]='\0';
				if (!strcmp(tempbuf,"longint"))
				{
					motor->odata[motor->numOfOutWords].type=MAC_LONGINT;
				}
				else if (!strcmp(tempbuf,"shortint")||!strcmp(tempbuf,"integer"))
				{
					motor->odata[motor->numOfOutWords].type=MAC_SHORTINT;
				}
				else if (!strcmp(tempbuf,"shortuint")||!strcmp(tempbuf,"word"))
				{
					motor->odata[motor->numOfOutWords].type=MAC_SHORTUINT;
				}
				else if (!strcmp(tempbuf,"fixed24"))
				{
					motor->odata[motor->numOfOutWords].type=MAC_FIXED24;
				}
				else if (!strcmp(tempbuf,"fixed16"))
				{ 
					motor->odata[motor->numOfOutWords].type=MAC_FIXED16;
				}
				else if (!strcmp(tempbuf,"fixed8"))
				{ 
					motor->odata[motor->numOfOutWords].type=MAC_FIXED8;
				}
				else if (!strcmp(tempbuf,"fixed4"))
				{ 
					motor->odata[motor->numOfOutWords].type=MAC_FIXED4;
				}
				else
				{
					printf("6. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				if (sscanf(&buffer[dplace[3]+tempdot+1]," factor=%f",&motor->odata[motor->numOfOutWords].factor)!=1)
				{
					motor->odata[motor->numOfOutWords].factor=1.0;
				}
				else
				{
					if (motor->odata[motor->numOfOutWords].type==MAC_LONGINT)
						motor->odata[motor->numOfOutWords].type=MAC_LONGINT_ASFLOAT;
					else if (motor->odata[motor->numOfOutWords].type==MAC_SHORTINT)
						motor->odata[motor->numOfOutWords].type=MAC_SHORTINT_ASFLOAT;
					else if (motor->odata[motor->numOfOutWords].type==MAC_SHORTUINT)
						motor->odata[motor->numOfOutWords].type=MAC_SHORTUINT_ASFLOAT;
				}
				motor->numOfOutWords++;
				if (motor->numOfOutWords>=MAC_MAXOUTVALS)
				{
					printf("Too many outputs specified for module %s\n",motor->module_name);
					exit(99);
				}
			}
		}
		else if (strncmp(buffer,"Bit",3)==0)
		{
			if (inoutbitmode!=2)
			{
				printf("Illegal bitmode %s in %s\n",buffer,motor->module_name);
				exit(99);
			}
			if (motor!=NULL&&bitparent!=NULL)
			{
				motor->idata[motor->numOfInWords].userchange=0;
				motor->idata[motor->numOfInWords].bitparent=bitparent;
				motor->idata[motor->numOfInWords].type=MAC_LONGINT;
				int dotplace=2;
				if (buffer[dotplace+2]=='=')
				{
					motor->idata[motor->numOfInWords].bitmode=buffer[dotplace+1]-'0';
					dotplace+=2;
				}
				else if (buffer[dotplace+3]=='=')
				{
					motor->idata[motor->numOfInWords].bitmode=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
					dotplace+=3;		
				}
				else
				{
					printf("2. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				int i,j;
				int dplace[4]={0,0,0,0};
				int success=0;
				for (j=0;j<4;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=4)
				{
					printf("3. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				int commentlen=dplace[3]-dplace[2]-1;
				strncpy(motor->idata[motor->numOfInWords].key,&buffer[dplace[0]+1],keylen);
				motor->idata[motor->numOfInWords].key[keylen]='\0';
				strncpy(motor->idata[motor->numOfInWords].comment,&buffer[dplace[2]+1],commentlen);
				motor->idata[motor->numOfInWords].comment[commentlen]='\0';
				motor->numOfInWords++;
				if (motor->numOfInWords>=MAC_MAXINVALS)
				{
					printf("Too many inputs specified for module %s\n",motor->module_name);
					exit(99);
				}
			}
		}
		else if (strncmp(buffer,"In",2)==0)
		{
			if (inoutbitmode!=0)
			{
				printf("Illegal bitmode %s in %s\n",buffer,motor->module_name);
				exit(99);
			}
			initmode=0;
			if (motor!=NULL)
			{
				motor->idata[motor->numOfInWords].userchange=0;
				int dotplace=1;
				if (!strncmp(&buffer[2],"Out",3))
				{
					dotplace+=3;
					inoutbitmode=1;
				}
				if (!strncmp(&buffer[2],"Bits",4))
				{
					dotplace+=4;
					inoutbitmode=2;
					bitparent=&motor->idata[motor->numOfInWords];
				}
				motor->idata[motor->numOfInWords].bitmode=-1;
				if (buffer[dotplace+2]=='=')
				{
					motor->idata[motor->numOfInWords].reg=buffer[dotplace+1]-'0';
					dotplace+=2;
				}
				else if (buffer[dotplace+3]=='=')
				{
					motor->idata[motor->numOfInWords].reg=10*(buffer[dotplace+1]-'0')+(buffer[dotplace+2]-'0');
					dotplace+=3;
				}
				else if (buffer[dotplace+4]=='=')
				{
					motor->idata[motor->numOfInWords].reg=100*(buffer[dotplace+1]-'0')+10*(buffer[dotplace+2]-'0')+(buffer[dotplace+3]-'0');
					dotplace+=4;
				}
				else
				{
					printf("2. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				int i,j;
				int dplace[4]={0,0,0,0};
				int success=0;
				for (j=0;j<4;j++)
				{
					for (i=dotplace+1;i<strlen(buffer);i++)
					{
						if (buffer[i]=='"') 
						{
							dplace[success++]=i;
							dotplace=i;
						}
					}
				}
				if (success!=4)
				{
					printf("3. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}				
				int keylen=dplace[1]-dplace[0]-1;
				int commentlen=dplace[3]-dplace[2]-1;
				strncpy(motor->idata[motor->numOfInWords].key,&buffer[dplace[0]+1],keylen);
				motor->idata[motor->numOfInWords].key[keylen]='\0';
				strncpy(motor->idata[motor->numOfInWords].comment,&buffer[dplace[2]+1],commentlen);
				motor->idata[motor->numOfInWords].comment[commentlen]='\0';
				int tempdot;
				if (sscanf(&buffer[dplace[3]+1]," %64s%n",tempbuf,&tempdot)!=1)
				{	
					printf("5. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				tempbuf[63]='\0';
				if (!strcmp(tempbuf,"longint"))
				{
					motor->idata[motor->numOfInWords].type=MAC_LONGINT;
				}
				else if (!strcmp(tempbuf,"shortint")||!strcmp(tempbuf,"integer"))
				{
					motor->idata[motor->numOfInWords].type=MAC_SHORTINT;
				}
				else if (!strcmp(tempbuf,"shortuint")||!strcmp(tempbuf,"word"))
				{
					motor->idata[motor->numOfInWords].type=MAC_SHORTUINT;
				}
				else if (!strcmp(tempbuf,"fixed24"))
				{
					motor->idata[motor->numOfInWords].type=MAC_FIXED24;
				}
				else if (!strcmp(tempbuf,"fixed16"))
				{ 
					motor->idata[motor->numOfInWords].type=MAC_FIXED16;
				}
				else if (!strcmp(tempbuf,"fixed8"))
				{ 
					motor->idata[motor->numOfInWords].type=MAC_FIXED8;
				}
				else if (!strcmp(tempbuf,"fixed4"))
				{ 
					motor->idata[motor->numOfInWords].type=MAC_FIXED4;
				}
				else
				{
					printf("6. Unknown connecttype '%s' in .mac file\n",buffer);
					exit(99);
				}
				if (sscanf(&buffer[dplace[3]+tempdot+1]," factor=%f",&motor->idata[motor->numOfInWords].factor)!=1)
				{
					motor->idata[motor->numOfInWords].factor=1.0;
				}
				else
				{
					if (motor->idata[motor->numOfInWords].type==MAC_LONGINT)
						motor->idata[motor->numOfInWords].type=MAC_LONGINT_ASFLOAT;
					else if (motor->idata[motor->numOfInWords].type==MAC_SHORTINT)
						motor->idata[motor->numOfInWords].type=MAC_SHORTINT_ASFLOAT;
					else if (motor->idata[motor->numOfInWords].type==MAC_SHORTUINT)
						motor->idata[motor->numOfInWords].type=MAC_SHORTUINT_ASFLOAT;
				}
				if (inoutbitmode==1)
				{
					inoutbitmode=0;
					motor->odata[motor->numOfOutWords].userchange=0;
					motor->odata[motor->numOfOutWords].factor=motor->idata[motor->numOfInWords].factor;
					motor->odata[motor->numOfOutWords].type=motor->idata[motor->numOfInWords].type;
					strcpy(motor->odata[motor->numOfOutWords].key,motor->idata[motor->numOfInWords].key);
					strcpy(motor->odata[motor->numOfOutWords].comment,motor->idata[motor->numOfInWords].comment);	
					motor->odata[motor->numOfOutWords].reg=motor->idata[motor->numOfInWords].reg;
					motor->numOfOutWords++;
					if (motor->numOfOutWords>=MAC_MAXOUTVALS)
					{
						printf("Too many outputs specified for module %s\n",motor->module_name);
						exit(99);
					}
				}
				motor->numOfInWords++;
				if (motor->numOfInWords>=MAC_MAXINVALS)
				{
					printf("Too many inputs specified for module %s\n",motor->module_name);
					exit(99);
				}
			}
		}
  }
  fclose(fp);
	return TRUE;
}

int tmpnLoadCellLoad(const char *filename, tmpnLoadCell *loadcell)
{
  FILE *fp;
  char buffer[256];
  int loadcell_version;
  loadcellConnect *lcc=NULL;
	
	loadcell->sfd=-1;
  loadcell->simulate = 0;
  sprintf(loadcell->ipaddr,"%s","");
  loadcell->numOfModules = 0;
	loadcell->port=0;
	loadcell->fastmoxa=0;
  fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("LoadLoadCellConf: Unknown file %s\n",filename);
    return FALSE;
  }
  fscanf(fp,"LOADCELLVERSION %d\n",&loadcell_version);
  if(loadcell_version!=LOADCELLVERSION)
  {
		printf("LoadLoadCellConf: Unknown version %d\n", loadcell_version);
    exit(99);
  }
  while(fgets(buffer,sizeof(buffer), fp)!=NULL)
  {
    if(strncmp(buffer,"NumOfModules=",13)==0)
    {
      sscanf(buffer,"NumOfModules=%d\n",&loadcell->numOfModules);
			if ((loadcell->numOfModules <= 0) || (loadcell->numOfModules > 8))
			{				
				printf("1. numOfModules out of range '%s' (%d) in .loadcell file\n",buffer,loadcell->numOfModules);
				exit(99);
			}
    }
    else if(strncmp(buffer,"simulate=",9)==0)
    {
      sscanf(buffer,"simulate=%d\n",&loadcell->simulate);
    }
    else if(strncmp(buffer,"ipaddr=",7)==0)
    {
      sscanf(buffer,"ipaddr=%s\n",loadcell->ipaddr);
    }
		else if(strncmp(buffer,"port=",5)==0)
    {
      sscanf(buffer,"port=%d\n",&loadcell->port);
    }
		else if(strncmp(buffer,"fastmoxa=",9)==0)
    {
      sscanf(buffer,"fastmoxa=%d\n",&loadcell->fastmoxa);
    }
    else if (strncmp(buffer,"LoadCell",8)==0)
		{
			int address=-1;
			if (buffer[9]=='=')
			{
				address=buffer[8]-'0';
				if ((address >= 0) && (address < loadcell->numOfModules))
				{
					lcc=&loadcell->iotab[address];
				}
				else
				{
					printf("1. Address out of range '%s' (%d) in .loadcell file\n",buffer,address);
					exit(99);
				}
			}
			else
			{
				printf("2. Unknown connecttype '%s' in .loadcell file\n",buffer);
				exit(99);
			}
			int dotplace;
			int i,j;
			int dplace[4]={0,0,0,0};
			int success=0;
			dotplace=9;
			for (j=0;j<4;j++)
			{
				for (i=dotplace+1;i<strlen(buffer);i++)
				{
					if (buffer[i]=='"') 
					{
						dplace[success++]=i;
						dotplace=i;
					}
				}
			}
			if (success!=4)
			{
				printf("3. Unknown connecttype '%s' in .loadcell file\n",buffer);
				exit(99);
			}				
			int keylen=dplace[1]-dplace[0]-1;
			int commentlen=dplace[3]-dplace[2]-1;
			strncpy(lcc->key,&buffer[dplace[0]+1],keylen);
			lcc->key[keylen]='\0';
			strncpy(lcc->comment,&buffer[dplace[2]+1],commentlen);
			lcc->comment[commentlen]='\0';
			char str[64];
			if ((sscanf(&buffer[dplace[3]+1]," %63s",str)==1)&&(!strncmp(str,"ignoreError",11)))
			{
				lcc->ignoreError=1;
			}
			else
			{
				lcc->ignoreError=0;
			}
		}
  }
  fclose(fp);
  return TRUE;
}


int tmpnWorkcellLoad(const char *fn, tmpnWorkcell *workcell)
{
  FILE *fp;
  char buffer[256];
  char s[256];
  char filename[256];
  int i,version;
	struct udpsave
	{
		char filename[256];
		int type;
	};
	struct udpsave us[MAXUDPAGENTS];
	int udpagentcount=0;

  fp = fopen(fn,"r");
  if(fp==NULL) return FALSE;
  fscanf(fp,"VERSION %d\n",&version);
  if(version>WORKCELLVERSION)
  {
    printf("Workcell version mismatch. Detected version %d. Supports up to version %d\n",version,WORKCELLVERSION);
    fclose(fp);
    exit(99);
  }
  strcpy(workcell->filename, fn);
  fscanf(fp,"%s\n",workcell->name);
  
  if(version == 1)
  {
    fscanf(fp,"%s %d\n",s,&workcell->robots.maxidx);
    for(i=0;i<workcell->robots.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/robot/%s",databasePath,s);
      workcell->robots.robot[i]=*initrobot;
      tmpnRobotLoad(filename, &workcell->robots.robot[i]);
    }
    selectRobot(0);
    fscanf(fp,"%s %d\n",s,&workcell->tools.maxidx);
    for(i=0;i<workcell->tools.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/tool/%s",databasePath,s);
      if (tmpnToolLoad(filename, &workcell->tools.tool[i]) == FALSE)
      {
        printf("couldn't find tool \"%s\"\n",filename);
        exit(1);
      }
    }
    fscanf(fp,"%s %d\n",s,&workcell->items.maxidx);
    for(i=0;i<workcell->items.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/item/%s",databasePath,s);
      tmpnItemLoad(filename, &workcell->items.item[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->patterns.maxidx);
    for(i=0;i<workcell->patterns.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/pattern/%s",databasePath,s);
      tmpnPatternLoad(filename, &workcell->patterns.pattern[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->accessories.maxidx);
    for(i=0;i<workcell->accessories.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/accessory/%s",databasePath,s);
      tmpnAccessoryLoad(filename, &workcell->accessories.accessory[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->ppscripts.maxidx);
    for(i=0;i<workcell->ppscripts.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/ppscript/%s",databasePath,s);
      tmpnPPScriptLoad(filename, &workcell->ppscripts.ppscript[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->dios.maxidx);
    for(i=0;i<workcell->dios.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/dio/%s",databasePath,s);
      tmpnDIOLoad(filename, &workcell->dios.dio[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->comsks.maxidx);
    for(i=0;i<workcell->comsks.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/comsk/%s",databasePath,s);
      tmpnComSKLoad(filename, &workcell->comsks.comsk[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->loadcells.maxidx);
    for(i=0;i<workcell->loadcells.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/loadcell/%s",databasePath,s);
      tmpnLoadCellLoad(filename, &workcell->loadcells.loadcell[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->macs.maxidx);
    for(i=0;i<workcell->macs.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/mac/%s",databasePath,s);
      tmpnMacLoad(filename, &workcell->macs.mac[i]);
    }
    fscanf(fp,"%s %d\n",s,&workcell->statemachines.maxidx);
    if(workcell->statemachines.maxidx>0)
    {
      //todo seperat function to free malloc data
      //if(workcell->statemachines.statemachine!=NULL)
      //  free(workcell->statemachines.statemachine);
      workcell->statemachines.statemachine = (tmpnStateMachine*)malloc(sizeof(tmpnStateMachine)*workcell->statemachines.maxidx);
      tmpnStateMachineReset();
    }  
    for(i=0;i<workcell->statemachines.maxidx;i++)
    {
      fscanf(fp,"%s\n",s);
      sprintf(filename,"%s/statemachine/%s",databasePath,s);
      workcell->statemachines.statemachine[i].numstate = 0;
      workcell->statemachines.statemachine[i].delaystop = 0;
      workcell->statemachines.statemachine[i].state = NULL;
      workcell->statemachines.statemachine[i].value = NULL;
      workcell->statemachines.statemachine[i].timeout = NULL;
      workcell->statemachines.statemachine[i].input = NULL;
      workcell->statemachines.statemachine[i].output = NULL;
      workcell->statemachines.statemachine[i].link = NULL;
      tmpnStateMachineLoad(filename, &workcell->statemachines.statemachine[i],0);
			tmpnStateLoad(filename, &workcell->statemachines.statemachine[i], 0);
		}

    workcell->boptcoeff.maxidx=0;
    workcell->languages.numoflanguages=0;
    workcell->languages.currentLanguage=0;
    workcell->statetekstlist.numofStateTeksts=0;
    workcell->statetekstlist.currentStateTekst=0;
    while(fgets(buffer, sizeof(buffer), fp)!=NULL)
    {
      if(strncmp(buffer,"SCRIPT",6)==0)
      {
        sscanf(buffer,"SCRIPT %s\n",workcell->scripts.item[workcell->scripts.maxidx++].name);
      }
      else if(strncmp(buffer,"STATETEKST",10)==0)
      {
        char name[128];
        sscanf(buffer,"STATETEKST %127s\n",name);
        sprintf(s,"%s/statetekst/%s",databasePath,name);
        tmpnStateTekstsLoad(s,&workcell->statetekstlist);
      }
      else if(!strncmp(buffer,"REMOTEHOST",10))
      {      
        if (workcell->remotehosts.maxidx < MAXREMOTEHOSTS) 
        {
          int idx = workcell->remotehosts.maxidx++;
          int a,b,c,d;
          workcell->remotehosts.remotehost[idx].port = STMPORT;
          sscanf(buffer,"REMOTEHOST %d.%d.%d.%d:%d\n",&a,&b,&c,&d,&workcell->remotehosts.remotehost[idx].port);
          sprintf(workcell->remotehosts.remotehost[idx].name,"%d.%d.%d.%d",a,b,c,d);
          workcell->remotehosts.remotehost[idx].sockfd = -1;
          workcell->remotehosts.remotehost[idx].sndbuf_idx = 0;
          workcell->remotehosts.remotehost[idx].repeat = 0;
          workcell->remotehosts.remotehost[idx].alive = 0;
          printf("REMOTEHOST=%s:%d declared\n",workcell->remotehosts.remotehost[idx].name,workcell->remotehosts.remotehost[idx].port);
        }
        else
        {
          printf("MAXREMOTEHOSTS\n");
          exit(99);
        }
      }
      else if(!strncmp(buffer,"BOPTCOEFF",9))
      { 
        char name[128];
        sscanf(buffer,"BOPTCOEFF %127s\n",name);
        sprintf(filename,"%s/boptcoeff/%s",databasePath,name);
        tmpnBoptCoeffLoad(filename, &workcell->boptcoeff);
      }
      else if(!strncmp(buffer,"LANGUAGE",8))
      { 
        char name[128];
        sscanf(buffer,"LANGUAGE %127s\n",name);
        sprintf(filename,"%s/language/%s",databasePath,name);
        tmpnLanguageLoad(filename, &workcell->languages);
      }
      else{
        char str[256];
        sscanf(buffer, "%s\n", str);
        printf("ERROR: Load WorkCell: Cannot recognize line: '%s' Number of statemachines given might be wrong.\n",str);
        exit(99);
      }
    }
  }
  else if(version == 2)
  {
    workcell->robots.maxidx = 0;
    workcell->tools.maxidx = 0;
    workcell->items.maxidx = 0;
    workcell->patterns.maxidx = 0;
    workcell->cppatterns.maxidx = 0;
    workcell->accessories.maxidx = 0;
    workcell->ppscripts.maxidx = 0;
    workcell->dios.maxidx = 0;
    workcell->comsks.maxidx = 0;
    workcell->loadcells.maxidx = 0;
    workcell->macs.maxidx = 0;
		workcell->icpcons.maxidx = 0;
    workcell->statemachines.maxidx = 0;
    workcell->boptcoeff.maxidx=0;
    workcell->languages.numoflanguages=0;
    workcell->languages.currentLanguage=0;
    workcell->statetekstlist.numofStateTeksts=0;
    workcell->statetekstlist.currentStateTekst=0;
    while(fgets(buffer, sizeof(buffer), fp)!=NULL)
    {
      if(strncmp(buffer, ";", 1)==0)
      {
      }
      else if(strncmp(buffer,"ROBOT",5)==0)
      {
        if(workcell->robots.maxidx < MAXROBOTS)
        {
          char name[128];
          sscanf(buffer,"ROBOT %127s\n",name);
          sprintf(filename,"%s/robot/%s",databasePath,name);
          workcell->robots.robot[workcell->robots.maxidx]=*initrobot;
          tmpnRobotLoad(filename, &workcell->robots.robot[workcell->robots.maxidx]);
          workcell->robots.maxidx++;
          selectRobot(0);
        }
        else
        {
          printf("MAXROBOTS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"TOOL",4)==0)
      {
        if(workcell->tools.maxidx < MAXTOOLS)
        {
          char name[128];
          sscanf(buffer,"TOOL %127s\n",name);
          sprintf(filename,"%s/tool/%s",databasePath,name);
          if (tmpnToolLoad(filename, &workcell->tools.tool[workcell->tools.maxidx]) == FALSE)
          {
            printf("couldn't find tool \"%s\"\n",filename);
            exit(1);
          }
          workcell->tools.maxidx++;
        }
        else
        {
          printf("MAXTOOLS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"ITEM",4)==0)
      {
        if(workcell->items.maxidx < MAXITEMS)
        {
          char name[128];
          sscanf(buffer,"ITEM %127s\n",name);
          sprintf(filename,"%s/item/%s",databasePath,name);
          tmpnItemLoad(filename, &workcell->items.item[workcell->items.maxidx]);
          workcell->items.maxidx++;
        }
        else
        {
          printf("MAXITEMS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"PATTERN",7)==0)
      {
        if(workcell->patterns.maxidx < MAXPATTERNS)
        {
          char name[128];
          sscanf(buffer,"PATTERN %127s\n",name);
          sprintf(filename,"%s/pattern/%s",databasePath,name);
          tmpnPatternLoad(filename, &workcell->patterns.pattern[workcell->patterns.maxidx]);
          workcell->patterns.maxidx++;
        }
        else
        {
          printf("MAXPATTERNS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"CPPATTERN",9)==0)
      {
        char name[128];
        sscanf(buffer,"CPPATTERN %127s\n",name);
        sprintf(filename,"%s/cppattern/%s",databasePath,name);
        tmpnCPPatternLoad(filename, &workcell->cppatterns);
      }
      else if(strncmp(buffer,"ACCESSORY",9)==0)
      {
        if(workcell->accessories.maxidx < MAXACCESSORIES)
        {
          char name[128];
          sscanf(buffer,"ACCESSORY %127s\n",name);
          sprintf(filename,"%s/accessory/%s",databasePath,name);
          tmpnAccessoryLoad(filename, &workcell->accessories.accessory[workcell->accessories.maxidx]);
          workcell->accessories.maxidx++;
        }
        else
        {
          printf("MAXACCESSORIES\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"PPSCRIPT",8)==0)
      {
        if(workcell->ppscripts.maxidx < MAXPPSCRIPTS)
        {
          char name[128];
          sscanf(buffer,"PPSCRIPT %127s\n",name);
          sprintf(filename,"%s/ppscript/%s",databasePath,name);
          tmpnPPScriptLoad(filename, &workcell->ppscripts.ppscript[workcell->ppscripts.maxidx]);
          workcell->ppscripts.maxidx++;
        }
        else
        {
          printf("MAXPPSCRIPTS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"DIO",3)==0)
      {
        if(workcell->dios.maxidx < MAXDIO)
        {
          char name[128];
          sscanf(buffer,"DIO %127s\n",name);
          sprintf(filename,"%s/dio/%s",databasePath,name);
          tmpnDIOLoad(filename, &workcell->dios.dio[workcell->dios.maxidx]);
          workcell->dios.maxidx++;
        }
        else
        {
          printf("MAXDIO\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"COMSK",5)==0)
      {
        if(workcell->comsks.maxidx < MAXCOMSKS)
        {
          char name[128];
          sscanf(buffer,"COMSK %127s\n",name);
          sprintf(filename,"%s/comsk/%s",databasePath,name);
          tmpnComSKLoad(filename, &workcell->comsks.comsk[workcell->comsks.maxidx]);
          workcell->comsks.maxidx++;
        }
        else
        {
          printf("MAXCOMSKS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"LOADCELL",8)==0)
      {
        if(workcell->loadcells.maxidx < MAXLOADCELLS)
        {
          char name[128];
          sscanf(buffer,"LOADCELL %127s\n",name);
          sprintf(filename,"%s/loadcell/%s",databasePath,name);
          tmpnLoadCellLoad(filename, &workcell->loadcells.loadcell[workcell->loadcells.maxidx]);
          workcell->loadcells.maxidx++;
        }
        else
        {
          printf("MAXLOADCELLS\n");
          exit(99);
        }
      }
      else if(strncmp(buffer,"MAC",3)==0)
      {
        if(workcell->macs.maxidx < MAXMACS)
        {
          char name[128];
          sscanf(buffer,"MAC %127s\n",name);
          sprintf(filename,"%s/mac/%s",databasePath,name);
          tmpnMacLoad(filename, &workcell->macs.mac[workcell->macs.maxidx]);
          workcell->macs.maxidx++;
        }
        else
        {
          printf("MAXMACS\n");
          exit(99);
        }
      }
			else if(strncmp(buffer,"ICPCON",6)==0)
      {
        if(workcell->icpcons.maxidx < MAXICPCONS)
        {
          char name[128];
          sscanf(buffer,"ICPCON %127s\n",name);
          sprintf(filename,"%s/icpcon/%s",databasePath,name);
          tmpnICPconLoad(filename, &workcell->icpcons.icpcon[workcell->icpcons.maxidx]);
          workcell->icpcons.maxidx++;
        }
        else
        {
          printf("MAXICPCONS\n");
          exit(99);
        }
      }
			else if(strncmp(buffer,"UDPSERVER",9)==0)
      {
				char name[128];
				sscanf(buffer,"UDPSERVER %127s\n",name);
				sprintf(filename,"%s/udpagents/%s",databasePath,name);
				strcpy(us[udpagentcount].filename,filename);
				us[udpagentcount].type=UDPSERVER;
				udpagentcount++;
				if (udpagentcount>MAXUDPAGENTS)
				{
					printf("MAXUDPAGENTS\n");
					exit(99);
				}
			}
			else if(strncmp(buffer,"UDPCLIENT",9)==0)
      {
        char name[128];
				sscanf(buffer,"UDPCLIENT %127s\n",name);
				sprintf(filename,"%s/udpagents/%s",databasePath,name);
				strcpy(us[udpagentcount].filename,filename);
				us[udpagentcount].type=UDPCLIENT;
				udpagentcount++;
				if (udpagentcount>MAXUDPAGENTS)
				{
					printf("MAXUDPAGENTS\n");
					exit(99);
				}
			}
      else if(strncmp(buffer,"STM",3)==0)
      { 
				if(workcell->statemachines.maxidx==0)
        {
          //todo seperat function to free malloc data
          //if(workcell->statemachines.statemachine!=NULL)
          //  free(workcell->statemachines.statemachine);
          workcell->statemachines.statemachine = (tmpnStateMachine*)malloc(sizeof(tmpnStateMachine));
        }
        else
        {
          workcell->statemachines.statemachine = (tmpnStateMachine*)realloc(workcell->statemachines.statemachine, sizeof(tmpnStateMachine)*(workcell->statemachines.maxidx + 1));
        }
        //Reset statemachine (tmpnStateMachineReset()):
        int idx = workcell->statemachines.maxidx;
        workcell->statemachines.statemachine[idx].type = -1;
        strcpy(workcell->statemachines.statemachine[idx].name, "");
        workcell->statemachines.statemachine[idx].istate = -1;
        workcell->statemachines.statemachine[idx].next_istate = -1;
        workcell->statemachines.statemachine[idx].new_istate = -1;
        workcell->statemachines.statemachine[idx].timerstate = -1;
				workcell->statemachines.statemachine[idx].debugvalue = NULL;
        workcell->statemachines.statemachine[idx].stop = 0;
        workcell->statemachines.statemachine[idx].mcSignal = 0;
        pthread_cond_init(&workcell->statemachines.statemachine[idx].change, NULL);
        pthread_mutex_init(&workcell->statemachines.statemachine[idx].change_mtx, NULL);
        workcell->statemachines.statemachine[idx].numstate=0;
        workcell->statemachines.statemachine[idx].numvalue=0;
        workcell->statemachines.statemachine[idx].numtimeout=0;
        workcell->statemachines.statemachine[idx].numinput=0;
        workcell->statemachines.statemachine[idx].numoutput=0;
        workcell->statemachines.statemachine[idx].numlink=0;
        
        char name[128];
        sscanf(buffer,"STM %127s\n",name);
        sprintf(filename,"%s/statemachine/%s",databasePath,name);
        
        workcell->statemachines.statemachine[idx].numstate = 0;
        workcell->statemachines.statemachine[idx].delaystop = 0;
        workcell->statemachines.statemachine[idx].state = NULL;
        workcell->statemachines.statemachine[idx].value = NULL;
        workcell->statemachines.statemachine[idx].timeout = NULL;
        workcell->statemachines.statemachine[idx].input = NULL;
        workcell->statemachines.statemachine[idx].output = NULL;
        workcell->statemachines.statemachine[idx].link = NULL;
        tmpnStateMachineLoad(filename, &workcell->statemachines.statemachine[idx],0);
				tmpnStateLoad(filename, &workcell->statemachines.statemachine[idx], 0);
        workcell->statemachines.maxidx++;
      }
      else if(strncmp(buffer,"SCRIPT",6)==0)
      {
        sscanf(buffer,"SCRIPT %s\n",workcell->scripts.item[workcell->scripts.maxidx++].name);
      }
      else if(strncmp(buffer,"STATETEKST",10)==0)
      {
        char name[128];
        sscanf(buffer,"STATETEKST %127s\n",name);
        sprintf(s,"%s/statetekst/%s",databasePath,name);
        tmpnStateTekstsLoad(s,&workcell->statetekstlist);
      }
      else if(!strncmp(buffer,"REMOTEHOST",10))
      {      
        if (workcell->remotehosts.maxidx < MAXREMOTEHOSTS) 
        {
          int idx = workcell->remotehosts.maxidx++;
          int a,b,c,d;
          workcell->remotehosts.remotehost[idx].port = STMPORT;
          sscanf(buffer,"REMOTEHOST %d.%d.%d.%d:%d\n",&a,&b,&c,&d,&workcell->remotehosts.remotehost[idx].port);
          sprintf(workcell->remotehosts.remotehost[idx].name,"%d.%d.%d.%d",a,b,c,d);
          workcell->remotehosts.remotehost[idx].sockfd = -1;
          workcell->remotehosts.remotehost[idx].sndbuf_idx = 0;
          workcell->remotehosts.remotehost[idx].repeat = 0;
          workcell->remotehosts.remotehost[idx].alive = 0;
          printf("REMOTEHOST=%s:%d declared\n",workcell->remotehosts.remotehost[idx].name,workcell->remotehosts.remotehost[idx].port);
        }
        else
        {
          printf("MAXREMOTEHOSTS\n");
          exit(99);
        }
      }
      else if(!strncmp(buffer,"BOPTCOEFF",9))
      { 
        char name[128];
        sscanf(buffer,"BOPTCOEFF %127s\n",name);
        sprintf(filename,"%s/boptcoeff/%s",databasePath,name);
        tmpnBoptCoeffLoad(filename, &workcell->boptcoeff);
      }
      else if(!strncmp(buffer,"LANGUAGE",8))
      { 
        char name[128];
        sscanf(buffer,"LANGUAGE %127s\n",name);
        sprintf(filename,"%s/language/%s",databasePath,name);
        tmpnLanguageLoad(filename, &workcell->languages);
      }
      else
			{
        char str[256];
        sscanf(buffer, "%255s\n", str);
        printf("ERROR: Load WorkCell: Cannot recognize line: '%s'\n",str);
        exit(99);
      }
    }
  }

  workcell->m_root = NULL;
  
  for(i=0;i<workcell->statemachines.maxidx;i++)
  {
    SetupSTMLink1(&workcell->statemachines.statemachine[i]);
  }
  for(i=0;i<workcell->statemachines.maxidx;i++)
  {
    SetupSTMLink2(&workcell->statemachines.statemachine[i]);
  }
	for (i=0;i<udpagentcount;i++)
	{
		tmpnUdpAgentLoad(us[i].filename, &workcell->udpagents, us[i].type);
	}
  if(rs_param.statemachine_debug>2)
    for(i=0;i<workcell->statemachines.maxidx;i++)
    {
      tmpnStateMachineDump(&workcell->statemachines.statemachine[i]);
    }
  if(workcell->robots.maxidx > 0)
    copyFramesFromSTMtoRobot();
	
  fclose(fp);
  return TRUE;
}

const char *tmpnGetDatabase(void)
{
  return &databasePath[0];
}

void tmpnSetDatabase(const char *database)
{
  strcpy(databasePath,database);
}

int tmpnPlantLoad(const char *fn, tmpnPlant *plant)
{
  FILE *fp;
  char s[256];
  char filename[256];
  int w,version;
  
  sprintf(filename,"%s/plant/%s.plant",databasePath,fn);
  fp = fopen(filename,"r");
  if(fp==NULL) return FALSE;
  fscanf(fp,"VERSION %d\n",&version);
  if(version!=PLANTVERSION) return FALSE;

  fscanf(fp,"%s\n",plant->name);
  fscanf(fp,"%s %d\n",s,&plant->workcells.maxidx);
  if(plant->workcells.maxidx > MAXWORKCELLS)
  {
    printf("MAXWORKCELLS");
    exit(99);
  }
  for(w=0;w<plant->workcells.maxidx;w++)
  {
    fscanf(fp,"%s\n",s);
    sprintf(filename,"%s/workcell/%s",databasePath,s);
    selectWorkcell(w);
    tmpnWorkcellLoad(filename, &plant->workcells.workcell[w]);
  }
  fclose(fp);
  return TRUE;
}
//firstcmd
void updatecmdPoints(COMMANDSTRUCT *cmd)
{
  POINTSTRUCT *prevpoint = &pdummy;
  POINTSTRUCT* point;
  int level;
  
  //if(cmd==NULL) cmd=firstcmd;
  if(cmd==NULL) return;
  level=cmd->flag;
  while(cmd&&cmd->flag>=level)
  {
    if(cmd->type == POINT)
    {
      point = (POINTSTRUCT*)cmd->data;
      refreshPoint(cmd);
      prevpoint = (POINTSTRUCT*)cmd->data;
    }
    else if(cmd->type == HPOINT)
    {
      point = (POINTSTRUCT*)cmd->data;
      refreshPoint(cmd);
    }
    else if(cmd->type == EPOINT)
    {
    }
    else if(cmd->type == RPOINT)
    {
      point = (POINTSTRUCT*)cmd->data;
      point->pp.x=prevpoint->fp.x;
      point->pp.y=prevpoint->fp.y;
      point->pp.z=prevpoint->fp.z;
      point->pp.v=prevpoint->fp.v;
      point->pp.w=prevpoint->fp.w;
      point->pp.u=prevpoint->fp.u;
      refreshPoint(cmd);
    }
    else if(cmd->type == HRPOINT)
    {
      point = (POINTSTRUCT*)cmd->data;
      point->pp.x=prevpoint->fp.x;
      point->pp.y=prevpoint->fp.y;
      point->pp.z=prevpoint->fp.z;
      point->pp.v=prevpoint->fp.v;
      point->pp.w=prevpoint->fp.w;
      point->pp.u=prevpoint->fp.u;
      refreshPoint(cmd);
    }
    cmd = cmd->next;
  }
}

int getTCPidx(char *name, tmpnRobot *robot)
{
  int i;
  for(i=0;i<MAXTCP;i++)
  {
    if(strcmp(name,robot->m_tcp[i].name)==0) return i;
  }
  return -1;
}

int getFrameIdx(const char *name, tmpnRobot *robot)
{
  int i;
  for(i=0;i<robot->m_frames.maxidx;i++)
  {
    if(strcmp(name,robot->m_frames.frame[i].name)==0)
      return i;
  }
  return -1;
}

tmpnFloat getTimingValue(const char *name, tmpnRobot *robot)
{
  int i;
  for(i=0;i<robot->timing.maxidx;i++)
  {
    if(strcmp(name,robot->timing.item[i].name)==0)
    {
      return robot->timing.item[i].value;
    }
  }
  return 0.0;
}

int getMachineIdx(const char *name)
{
  int i;
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    if(strcmp(tworkcell->statemachines.statemachine[i].name,name)==0) return i;
  }
  if(rs_param.statemachine_debug>2)
    printf("statemachine %s not found\n",name);
  return -1;
}

int getStateIdx(int machine, const char *statename)
{
  int i;
	tmpnStateMachine *stm;
	stm=&tworkcell->statemachines.statemachine[machine];
  for(i=0;i<stm->numstate;i++)
  {
    if(strcmp(stm->state[i].name,statename)==0) return i;
  }
  if(rs_param.statemachine_debug>2)
    printf("stateIdx %s for machine (%s)%d not found\n",statename,stm->name,machine);
  return -1;
}

int getMachineStateIdx(const char *machinename, const char *statename)
{
  int machine;
  machine=getMachineIdx(machinename);  
  if(machine==-1) return -1;
  return getStateIdx(machine,statename);  
}


int getRemoteStatemachineIdx(tmpnWorkcell *workcell,char *str)
{
  int i;
  for(i=0;i<workcell->remotestatemachines.maxidx;i++)
  {
    if (!strcmp(workcell->remotestatemachines.remotestatemachine[i].name,str))
    {
      return i;
    }
  }
  return -1;
}

int getRemoteValueIdx(tmpnWorkcell *workcell,char *str1,char *str2)
{
  int i;
  for(i=0;i<workcell->remotevalues.maxidx;i++)
  {
    if (!strcmp(workcell->remotevalues.remotevalue[i].name,str1)&&!strcmp(workcell->remotevalues.remotevalue[i].link,str2))
    {
      return i;
    }
  }
  return -1;
}


//*******************************************************
//* TODO pointer til firstcmd("root") og ptrcmd("current")
//********************************************************
COMMANDSTRUCT *addCommandString(COMMANDSTRUCT *ptrcmd, const char *t, int* level)
{
  COMMANDSTRUCT *cmd=NULL;
  tmpnRobot *robot=(tmpnRobot*)trobot;
//char sdummy[256];
  char t1[256];
  char t2[256];
  char t3[256];
  int i,forceItem,loadgroup;
  POINTSTRUCT *point;
  if(strncmp(t,"ROOT",4)==0)
  {
    cmd = InsertCommand(ptrcmd,ROOT);
    cmd->flag = *level;
    sscanf(t,"%s",t2);
  }
  else if(strncmp(t,"MOVEABS",7)==0)
  {
    cmd = InsertCommand(ptrcmd,MOVEABS);
    cmd->flag = *level;
    sscanf(t,"%s%f,%f,%f,%f,%f",t2,
      &((MOVEABSSTRUCT*)cmd->data)->dest_a,
      &((MOVEABSSTRUCT*)cmd->data)->dest_b,
      &((MOVEABSSTRUCT*)cmd->data)->dest_c,
      &((MOVEABSSTRUCT*)cmd->data)->dest_d,
      &((MOVEABSSTRUCT*)cmd->data)->dest_e
      );
  }
  else if(strncmp(t,"WSP",3)==0)
  {
    cmd = InsertCommand(ptrcmd,WSP);
    cmd->flag = *level;
    sscanf(t,"%s%f,%f,%f,%f,%f,%f",t2,
      &((WSPSTRUCT*)cmd->data)->x,
      &((WSPSTRUCT*)cmd->data)->y,
      &((WSPSTRUCT*)cmd->data)->z,
      &((WSPSTRUCT*)cmd->data)->v,
      &((WSPSTRUCT*)cmd->data)->w,
      &((WSPSTRUCT*)cmd->data)->u
      );
  }
  else if(strncmp(t,"SADS",4)==0)
  {
    cmd = InsertCommand(ptrcmd,SADS);
    cmd->flag = *level;
    sscanf(t,"%s%f,%f,%f,%d",t2,
      &((SADSSTRUCT*)cmd->data)->speed,
      &((SADSSTRUCT*)cmd->data)->accel,
      &((SADSSTRUCT*)cmd->data)->decel,
      &((SADSSTRUCT*)cmd->data)->sramp
      );
  }
  else if(strncmp(t,"SPLINEHINT",10)==0)
  {
    cmd = InsertCommand(ptrcmd,SPLINEHINT);
    cmd->flag = *level;
    sscanf(t,"%s%d%d",t2,
      &((SPLINEHINTSTRUCT*)cmd->data)->splinehint
      ,&((SPLINEHINTSTRUCT*)cmd->data)->splineorder
      );
  }
  //all mpncommands wait until they have finished
  //this command has the option to return early when parameter wait=0
  else if(strncmp(t,"MOVEAXIS",8)==0)
  {
    cmd = InsertCommand(ptrcmd,MOVEAXIS);
    cmd->flag = *level;
    sscanf(t,"%s axis=%d,speed=%f,accel=%f,decel=%f,distance=%f,wait=%d",t2
     ,&((MOVEAXISSTRUCT*)cmd->data)->axis
     ,&((MOVEAXISSTRUCT*)cmd->data)->speed
     ,&((MOVEAXISSTRUCT*)cmd->data)->accel
     ,&((MOVEAXISSTRUCT*)cmd->data)->decel
     ,&((MOVEAXISSTRUCT*)cmd->data)->distance
     ,&((MOVEAXISSTRUCT*)cmd->data)->wait
      );
  }
  //all mpncommands wait until they have finished
  //this command hasd the option to return early when parameter wait=0
  else if(strncmp(t,"CANCELAXIS",10)==0)
  {
    cmd = InsertCommand(ptrcmd,CANCELAXIS);
    cmd->flag = *level;
    sscanf(t,"%s axis=%d,wait=%d",t2
     ,&((CANCELAXISSTRUCT*)cmd->data)->axis
     ,&((CANCELAXISSTRUCT*)cmd->data)->wait
      );
  }
  else if(strncmp(t,"STATEHINT",9)==0)
  {
    cmd = InsertCommand(ptrcmd,STATEHINT);
    cmd->flag = *level;
    sscanf(t,"%s%d",t2,
      &((STATEHINTSTRUCT*)cmd->data)->statehint
      );
  }
  else if(strncmp(t,"POSITIONHINT",12)==0)
  {
    cmd = InsertCommand(ptrcmd,POSITIONHINT);
    cmd->flag = *level;
    sscanf(t,"%s%d",t2,
      &((POSITIONHINTSTRUCT*)cmd->data)->positionhint
      );
  }
  else if(strncmp(t,"OUT",3)==0)
  {
    cmd = InsertCommand(ptrcmd,OUT);
    cmd->flag = *level;
    sscanf(t,"%s%d %d",t2,
      &((OUTPUTSTRUCT*)cmd->data)->p,
      &((OUTPUTSTRUCT*)cmd->data)->state
      );
  }
  else if(strncmp(t,"IN",2)==0)
  {
    cmd = InsertCommand(ptrcmd,IN);
    cmd->flag = *level;
    sscanf(t,"%s %d\n",t2,&((INPUTSTRUCT*)cmd->data)->p);
  }
  else if(strncmp(t,"SUB",3)==0)
  {
    cmd = InsertCommand(ptrcmd,STARTSUB);
    cmd->flag = (*level)++;
    sscanf(t,"%s%s",t2,t3);
    strcpy(((NAMESTRUCT*)cmd->data)->name,t3);
  }
  else if(strncmp(t,"PATH",4)==0)
  {
    cmd = InsertCommand(ptrcmd,PATH);
    cmd->flag = (*level)++;
    ((PATHSTRUCT*)cmd->data)->tpathdef.runbopt = 0;
    sscanf(t,"%s%s id=%d,type=%d,time=%f,loadgroup=%d,runbopt=%d",t2,t3
	   //sscanf(t,"%s%s id=%d,type=%d,time=%f,loadgroup=%d",t2,t3
	   ,&((PATHSTRUCT*)cmd->data)->tpathdef.id
	   ,&((PATHSTRUCT*)cmd->data)->tpathdef.pathtype
	   ,&((PATHSTRUCT*)cmd->data)->tpathdef.maxTime
	   ,&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup
	   ,&((PATHSTRUCT*)cmd->data)->tpathdef.runbopt
	   );
    strcpy(((PATHSTRUCT*)cmd->data)->tpathdef.name,t3); 
  }
  else if(strncmp(t,"MACRO",5)==0)
  {
    cmd = InsertCommand(ptrcmd,MACRO);
    cmd->flag = *level;
    sscanf(t,"%s%s%d%d%d",t2,t3
            ,&((MACROSTRUCT*)cmd->data)->parameter0
            ,&((MACROSTRUCT*)cmd->data)->parameter1
            ,&((MACROSTRUCT*)cmd->data)->parameter2);
    strcpy(((MACROSTRUCT*)cmd->data)->name,t3);
    for(i=0;i<MAXMACRONAMES;i++)
    {
      if(strcmp(((MACROSTRUCT*)cmd->data)->name, mpnmacro[i].name)==0)
      {
        ((MACROSTRUCT*)cmd->data)->idx = mpnmacro[i].idx;
        i=MAXMACRONAMES;
      }
    }
  }
  else if(strncmp(t,"RESETPRELOAD",12)==0)
  {
    cmd = InsertCommand(ptrcmd,RESETPRELOAD);
    cmd->flag = *level;
    sscanf(t,"%s%d",t2,&((RESETPRELOADSTRUCT*)cmd->data)->loadgroup);
  }
  else if(strncmp(t,"CALL",4)==0)
  {
    cmd = InsertCommand(ptrcmd,CALL);
    cmd->flag = *level;
    sscanf(t,"%s%s%d",t2,t3
            ,&((CALLSTRUCT*)cmd->data)->lag);
    strcpy(((CALLSTRUCT*)cmd->data)->script,t3);
  }
  else if(strncmp(t,"LABEL",5)==0)
  {
    cmd = InsertCommand(ptrcmd,LABEL);
    cmd->flag = *level;
    sscanf(t,"%s%s",t2,((LABELSTRUCT*)cmd->data)->label);
  }
  else if(strncmp(t,"JUMPLAYER",9)==0)
  {
    cmd = InsertCommand(ptrcmd,JUMPLAYER);
    cmd->flag = *level;
    sscanf(t,"%s%s%d",t2,t3
            ,&((JUMPLAYERSTRUCT*)cmd->data)->layer);
    strcpy(((JUMPLAYERSTRUCT*)cmd->data)->function,t3);
  }
  else if(strncmp(t,"SCOPE",5)==0)
  {
    cmd = InsertCommand(ptrcmd,SCOPE);
    cmd->flag = *level;
    sscanf(t,"%s%d%d%d",t2
            ,&((SCOPESTRUCT*)cmd->data)->parameter0
            ,&((SCOPESTRUCT*)cmd->data)->parameter1
            ,&((SCOPESTRUCT*)cmd->data)->parameter2);
  }
  else if(strncmp(t,"GOTO",4)==0)
  {
    cmd = InsertCommand(ptrcmd,GOTO);
    cmd->flag = *level;
    sscanf(t,"%s %s",t2,((GOTOSTRUCT*)cmd->data)->label);
  }
  else if(strncmp(t,"PPSCRIPT",8)==0)
  {
    //if !expand
    cmd = InsertCommand(ptrcmd,PPSCRIPT);
    cmd->flag = *level;
    sscanf(t,"%s %s idx=%d,loadgroup=%d",t2,t3,&forceItem,&loadgroup);
    strcpy(((PPSCRIPTSTRUCT*)cmd->data)->name,t3);
    ((PPSCRIPTSTRUCT*)cmd->data)->idx=forceItem;
    ((PPSCRIPTSTRUCT*)cmd->data)->loadgroup=loadgroup;
    cmd = expandPath(cmd,level,forceItem,t3,loadgroup);
  }
  else if(strncmp(t,"END",3)==0)
  {
    (*level)--;
    cmd=ptrcmd;
  }
  else if(strncmp(t,"POINT",5)==0)
  {
    cmd = InsertCommand(ptrcmd,POINT);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
     ,t2
     ,t3
     ,&point->fp.x
     ,&point->fp.y
     ,&point->fp.z
     ,&point->fp.v
     ,&point->fp.w
     ,&point->fp.u
     ,&point->p.dt
     ,t1
      );
    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"HPOINT",6)==0)
  {
    cmd = InsertCommand(ptrcmd,HPOINT);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
      ,t2
      ,t3
      ,&point->fp.x
      ,&point->fp.y
      ,&point->fp.z
      ,&point->fp.v
      ,&point->fp.w
      ,&point->fp.u
      ,&point->p.dt
      ,t1
      );
    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"RPOINT",6)==0)
  {
    cmd = InsertCommand(ptrcmd,RPOINT);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
      ,t2
      ,t3
      ,&point->fp.x
      ,&point->fp.y
      ,&point->fp.z
      ,&point->fp.v
      ,&point->fp.w
      ,&point->fp.u
      ,&point->p.dt
      ,t1
      );
    //next line was left out why ?
    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"HRPOINT",7)==0)
  {
    cmd = InsertCommand(ptrcmd,HRPOINT);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
      ,t2
      ,t3
      ,&point->fp.x
      ,&point->fp.y
      ,&point->fp.z
      ,&point->fp.v
      ,&point->fp.w
      ,&point->fp.u
      ,&point->p.dt
      ,t1
      );
    //next line was left out why ?
    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"EPOINT",6)==0)
  {
    cmd = InsertCommand(ptrcmd,EPOINT);
    cmd->flag = *level;
    point = (POINTSTRUCT*)cmd->data;
    sscanf(t,"%s%s%f,%f,%f,%f,%f,%f,%f%s"
      ,t2
      ,t3
      ,&point->pp.x
      ,&point->pp.y
      ,&point->pp.z
      ,&point->pp.v
      ,&point->pp.w
      ,&point->pp.u
      ,&point->p.dt
      ,t1
      );
    //next line was left out why ?
    point->p.tcpidx = getTCPidx(t1,robot);
    point->frameidx = getFrameIdx(t3,robot);
  }
  else if(strncmp(t,"TESTEVENT",9)==0)
  {
    cmd = InsertCommand(ptrcmd,TESTEVENT);
    cmd->flag = *level;
    sscanf(t,"%s%s%s",t1,t2,t3);
    ((EVENTSTRUCT*)cmd->data)->type=1;
    strcpy(((EVENTSTRUCT*)cmd->data)->machineName,t2);
    strcpy(((EVENTSTRUCT*)cmd->data)->stateName,t3);
    ((EVENTSTRUCT*)cmd->data)->machine=getMachineIdx(t2);
    if(((EVENTSTRUCT*)cmd->data)->machine==-1) {printf("%s\n",t);exit(99);}
    ((EVENTSTRUCT*)cmd->data)->state=getMachineStateIdx(t2,t3);
    if(((EVENTSTRUCT*)cmd->data)->state==-1) {printf("%s\n",t);exit(99);}

  }
  else if(strncmp(t,"SLEEP",5)==0)
  {
    cmd = InsertCommand(ptrcmd,SLEEP);
    cmd->flag = *level;
    sscanf(t,"%s%d",t1,&((SLEEPSTRUCT*)cmd->data)->ms);
  }
  else if(strncmp(t,"WAITEVENT",9)==0)
  {
    cmd = InsertCommand(ptrcmd,WAITEVENT);
    cmd->flag = *level;
    sscanf(t,"%s%d%s%s",t1,&((EVENTSTRUCT*)cmd->data)->type,t2,t3);
    strcpy(((EVENTSTRUCT*)cmd->data)->machineName,t2);
    strcpy(((EVENTSTRUCT*)cmd->data)->stateName,t3);
    ((EVENTSTRUCT*)cmd->data)->machine=getMachineIdx(t2);
    if(((EVENTSTRUCT*)cmd->data)->machine==-1) {printf("%s\n",t);exit(99);}
    ((EVENTSTRUCT*)cmd->data)->state=getMachineStateIdx(t2,t3);
    if(((EVENTSTRUCT*)cmd->data)->state==-1) {printf("%s\n",t);exit(99);}
  }
  else if(strncmp(t,"SIGNALEVENT",11)==0)
  {
    cmd = InsertCommand(ptrcmd,SIGNALEVENT);
    cmd->flag = *level;
    sscanf(t,"%s%d%s%s",t1,&((EVENTSTRUCT*)cmd->data)->type,t2,t3);
    strcpy(((EVENTSTRUCT*)cmd->data)->machineName,t2);
    strcpy(((EVENTSTRUCT*)cmd->data)->stateName,t3);
    ((EVENTSTRUCT*)cmd->data)->machine=getMachineIdx(t2);
    if(((EVENTSTRUCT*)cmd->data)->machine==-1) {printf("%s\n",t);exit(99);}
    ((EVENTSTRUCT*)cmd->data)->state=getMachineStateIdx(t2,t3);
    if(((EVENTSTRUCT*)cmd->data)->state==-1) {printf("%s\n",t);exit(99);}

  }

  else if(strncmp(t,"COUNTER",7)==0)
  {
    cmd = InsertCommand(ptrcmd,COUNTER);
    cmd->flag = *level;
    sscanf(t,"%s%s%s%s",t1
    ,((COUNTERSTRUCT*)cmd->data)->name
    ,((COUNTERSTRUCT*)cmd->data)->function
    ,((COUNTERSTRUCT*)cmd->data)->value);
  }
  else if(strncmp(t,"TUNING",6)==0)
  {
    cmd = InsertCommand(ptrcmd,TUNING);
    cmd->flag = *level;
    sscanf(t,"%s%s%d%f",t1
    ,((TUNINGSTRUCT*)cmd->data)->name
    ,&((TUNINGSTRUCT*)cmd->data)->vr
    ,&((TUNINGSTRUCT*)cmd->data)->value);
  }
  else if(strncmp(t,"SETSPEED",8)==0)
  {
    cmd = InsertCommand(ptrcmd,SETSPEED);
    cmd->flag = *level;
    sscanf(t,"%s%f",t1
    ,&((SETSPEEDSTRUCT*)cmd->data)->factor);
    ((SETSPEEDSTRUCT*)cmd->data)->factor *= 0.01;
  }
  else if(strncmp(t,"STOP",4)==0)
  {
    cmd = InsertCommand(ptrcmd,STOP);
    cmd->flag = *level;
  }
  else if(strncmp(t,"ERROR",5)==0)
  {
    cmd = InsertCommand(ptrcmd,ERROR);
    cmd->flag = *level;
    sscanf(t,"%s%d%s",t1,&((ERRORSTRUCT*)cmd->data)->number,((ERRORSTRUCT*)cmd->data)->text);
  }
  else
  {
    cmd = ptrcmd;
  }
  return cmd;
}

void refreshPoint(COMMANDSTRUCT *cmd)
{
  POINTSTRUCT *point;
  if(cmd->type==POINT||cmd->type==RPOINT||cmd->type==EPOINT||cmd->type==HPOINT||cmd->type==HRPOINT)
  {
    point = (POINTSTRUCT*)cmd->data;
    {
      point->p.x = point->fp.x + trobot->m_frames.frame[point->frameidx].x + point->pp.x;
      point->p.y = point->fp.y + trobot->m_frames.frame[point->frameidx].y + point->pp.y;
      point->p.z = point->fp.z + trobot->m_frames.frame[point->frameidx].z + point->pp.z;
      point->p.v = point->fp.v + trobot->m_frames.frame[point->frameidx].v + point->pp.v;
      point->p.w = point->fp.w + trobot->m_frames.frame[point->frameidx].w + point->pp.w;
      point->p.u = point->fp.u + trobot->m_frames.frame[point->frameidx].u + point->pp.u;
    }
  }
}


//common for both cmd and runcmd
void getCommandString(char *t, COMMANDSTRUCT *cmd)
{
  POINTSTRUCT *point;
  tmpnRobot *robot=(tmpnRobot*)trobot;
  if(cmd==NULL||cmd->data==NULL)
  {
    strcpy(t,"");
  }
  else if(cmd->type==ROOT)
  {
    sprintf(t,"ROOT");
  }
  else if(cmd->type==MOVEABS)
  {
    sprintf(t,"MOVEABS %f,%f,%f,%f,%f",
      ((MOVEABSSTRUCT*)cmd->data)->dest_a,
      ((MOVEABSSTRUCT*)cmd->data)->dest_b,
      ((MOVEABSSTRUCT*)cmd->data)->dest_c,
      ((MOVEABSSTRUCT*)cmd->data)->dest_d,
      ((MOVEABSSTRUCT*)cmd->data)->dest_e
      );
  }
  else if(cmd->type==MOVEAXIS)
  {
    sprintf(t,"MOVEAXIS axis=%d,speed=%3.2f,accel=%3.2f,decel=%3.2f,distance=%3.2f,wait=%d"
     ,((MOVEAXISSTRUCT*)cmd->data)->axis
     ,((MOVEAXISSTRUCT*)cmd->data)->speed
     ,((MOVEAXISSTRUCT*)cmd->data)->accel
     ,((MOVEAXISSTRUCT*)cmd->data)->decel
     ,((MOVEAXISSTRUCT*)cmd->data)->distance
     ,((MOVEAXISSTRUCT*)cmd->data)->wait
      );
  }
  else if(cmd->type==CANCELAXIS)
  {
    sprintf(t,"CANCELAXIS axis=%d,wait=%d"
     ,((CANCELAXISSTRUCT*)cmd->data)->axis
     ,((CANCELAXISSTRUCT*)cmd->data)->wait
      );
  }
  else if(cmd->type==WSP)
  {
    sprintf(t,"WSP %f,%f,%f,%f,%f,%f",
      ((WSPSTRUCT*)cmd->data)->x,
      ((WSPSTRUCT*)cmd->data)->y,
      ((WSPSTRUCT*)cmd->data)->z,
      ((WSPSTRUCT*)cmd->data)->v,
      ((WSPSTRUCT*)cmd->data)->w,
      ((WSPSTRUCT*)cmd->data)->u
      );
  }
  else if(cmd->type==SADS)
  {
    sprintf(t,"SADS %f,%f,%f,%d",
      ((SADSSTRUCT*)cmd->data)->speed,
      ((SADSSTRUCT*)cmd->data)->accel,
      ((SADSSTRUCT*)cmd->data)->decel,
      ((SADSSTRUCT*)cmd->data)->sramp
      );
  }
  else if(cmd->type==SPLINEHINT)
  {
    sprintf(t,"SPLINEHINT %d %d",
      ((SPLINEHINTSTRUCT*)cmd->data)->splinehint
      ,((SPLINEHINTSTRUCT*)cmd->data)->splineorder
      );
  }
  else if(cmd->type==STATEHINT)
  {
    sprintf(t,"STATEHINT %d",
      ((STATEHINTSTRUCT*)cmd->data)->statehint
      );
  }
  else if(cmd->type==POSITIONHINT)
  {
    sprintf(t,"POSITIONHINT %d",
      ((POSITIONHINTSTRUCT*)cmd->data)->positionhint
      );
  }
  else if(cmd->type==OUT)
  {
    sprintf(t,"OUT %d %d",
      ((OUTPUTSTRUCT*)cmd->data)->p,
      ((OUTPUTSTRUCT*)cmd->data)->state
      );
  }
  else if(cmd->type==IN)
  {
    sprintf(t,"IN %d",((INPUTSTRUCT*)cmd->data)->p);
  }
  else if(cmd->type==STARTSUB)
  {
    sprintf(t,"SUB %s",((NAMESTRUCT*)cmd->data)->name);
  }
  else if(cmd->type==MACRO)
  {
    sprintf(t,"MACRO %s %d %d %d",((MACROSTRUCT*)cmd->data)->name
    ,((MACROSTRUCT*)cmd->data)->parameter0
    ,((MACROSTRUCT*)cmd->data)->parameter1
    ,((MACROSTRUCT*)cmd->data)->parameter2
    );
  }
  else if(cmd->type==RESETPRELOAD)
  {
    sprintf(t,"RESETPRELOAD %d",((RESETPRELOADSTRUCT*)cmd->data)->loadgroup);
  }
  else if(cmd->type==CALL)
  {
    sprintf(t,"CALL %s %d"
    ,((CALLSTRUCT*)cmd->data)->script
    ,((CALLSTRUCT*)cmd->data)->lag
    );
  }
  else if(cmd->type==LABEL)
  {
    sprintf(t,"LABEL %s",((LABELSTRUCT*)cmd->data)->label);
  }
  else if(cmd->type==JUMPLAYER)
  {
    sprintf(t,"JUMPLAYER %s %d"
    ,((JUMPLAYERSTRUCT*)cmd->data)->function
    ,((JUMPLAYERSTRUCT*)cmd->data)->layer
    );
  }
  else if(cmd->type==SCOPE)
  {
    sprintf(t,"SCOPE %d %d %d"
    ,((SCOPESTRUCT*)cmd->data)->parameter0
    ,((SCOPESTRUCT*)cmd->data)->parameter1
    ,((SCOPESTRUCT*)cmd->data)->parameter2
    );
  }
  else if(cmd->type==GOTO)
  {
    sprintf(t,"GOTO %s",((GOTOSTRUCT*)cmd->data)->label);
  }
  else if(cmd->type==PPSCRIPT)
  {
    sprintf(t,"PPSCRIPT %s idx=%d,loadgroup=%d"
    ,((PPSCRIPTSTRUCT*)cmd->data)->name
    ,((PPSCRIPTSTRUCT*)cmd->data)->idx
    ,((PPSCRIPTSTRUCT*)cmd->data)->loadgroup
    );
  }
  else if(cmd->type==TESTEVENT)
  {
    sprintf(t,"TESTEVENT %d %s %s",((EVENTSTRUCT*)cmd->data)->type,((EVENTSTRUCT*)cmd->data)->machineName,((EVENTSTRUCT*)cmd->data)->stateName);
  }
  else if(cmd->type==SLEEP)
  {
    sprintf(t,"SLEEP %d",((SLEEPSTRUCT*)cmd->data)->ms);
  }
  else if(cmd->type==WAITEVENT)
  {
    sprintf(t,"WAITEVENT %d %s %s",((EVENTSTRUCT*)cmd->data)->type,((EVENTSTRUCT*)cmd->data)->machineName,((EVENTSTRUCT*)cmd->data)->stateName);
  }
  else if(cmd->type==COUNTER)
  {
    sprintf(t,"COUNTER %s %s %s"
    ,((COUNTERSTRUCT*)cmd->data)->name
    ,((COUNTERSTRUCT*)cmd->data)->function
    ,((COUNTERSTRUCT*)cmd->data)->value);
  }
  else if(cmd->type==TUNING)
  {
    sprintf(t,"TUNING %s %d %3.2f"
    ,((TUNINGSTRUCT*)cmd->data)->name
    ,((TUNINGSTRUCT*)cmd->data)->vr
    ,((TUNINGSTRUCT*)cmd->data)->value);
  }
  else if(cmd->type==SETSPEED)
  {
    sprintf(t,"SETSPEED %3.2f"
    ,((SETSPEEDSTRUCT*)cmd->data)->factor*100.0);
  }
  else if(cmd->type==SIGNALEVENT)
  {
    sprintf(t,"SIGNALEVENT %d %s %s",((EVENTSTRUCT*)cmd->data)->type,((EVENTSTRUCT*)cmd->data)->machineName,((EVENTSTRUCT*)cmd->data)->stateName);
  }
  else if(cmd->type==PATH)
  {
    sprintf(t,"PATH %s id=%d,type=%d,time=%1.0f,loadgroup=%d,runbopt=%d"
	    //sprintf(t,"PATH %s id=%d,type=%d,time=%1.0f,loadgroup=%d"
    ,((PATHSTRUCT*)cmd->data)->tpathdef.name
    ,((PATHSTRUCT*)cmd->data)->tpathdef.id
    ,((PATHSTRUCT*)cmd->data)->tpathdef.pathtype
    ,((PATHSTRUCT*)cmd->data)->tpathdef.maxTime
    ,((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup
    ,((PATHSTRUCT*)cmd->data)->tpathdef.runbopt
    );
  }
  else if(cmd->type==POINT)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    if(robot->m_showPoint==0)
    {
      sprintf(t,"POINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
      robot->m_frames.frame[point->frameidx].name,
      point->fp.x,
      point->fp.y,
      point->fp.z,
      point->fp.v,
      point->fp.w,
      point->fp.u,
      point->p.dt,
      robot->m_tcp[point->p.tcpidx].name);
    }
    else if(robot->m_showPoint==1)
    {
      sprintf(t,"POINT(0) %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
      robot->m_frames.frame[point->frameidx].name,
      point->p.x,
      point->p.y,
      point->p.z,
      point->p.v,
      point->p.w,
      point->p.u,
      point->p.dt,
      robot->m_tcp[point->p.tcpidx].name);
    }
  }
  else if(cmd->type==HPOINT)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    sprintf(t,"HPOINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
    robot->m_frames.frame[point->frameidx].name,
    point->fp.x,
    point->fp.y,
    point->fp.z,
    point->fp.v,
    point->fp.w,
    point->fp.u,
    point->p.dt,
    robot->m_tcp[point->p.tcpidx].name);
  }
  else if(cmd->type==RPOINT)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    sprintf(t,"RPOINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
    robot->m_frames.frame[point->frameidx].name,
    point->fp.x,
    point->fp.y,
    point->fp.z,
    point->fp.v,
    point->fp.w,
    point->fp.u,
    point->p.dt,
    robot->m_tcp[point->p.tcpidx].name);
  }
  else if(cmd->type==HRPOINT)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    sprintf(t,"HRPOINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
    robot->m_frames.frame[point->frameidx].name,
    point->fp.x,
    point->fp.y,
    point->fp.z,
    point->fp.v,
    point->fp.w,
    point->fp.u,
    point->p.dt,
    robot->m_tcp[point->p.tcpidx].name);
  }
  else if(cmd->type==EPOINT)
  {
    point = (POINTSTRUCT*)cmd->data;
    refreshPoint(cmd);
    sprintf(t,"EPOINT %s %1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f,%1.0f %s",
    robot->m_frames.frame[point->frameidx].name,
//    point->fp.x+
point->pp.x,
//    point->fp.y+
point->pp.y,
//    point->fp.z+
point->pp.z,
//    point->fp.v+
point->pp.v,
//    point->fp.w+
point->pp.w,
//    point->fp.w+
point->pp.u,
    point->p.dt,
    robot->m_tcp[point->p.tcpidx].name);
  }
  else if(cmd->type==STOP)
  {
    sprintf(t,"STOP");
  }
  else if(cmd->type==ERROR)
  {
    sprintf(t,"ERROR %d %s"
    ,((ERRORSTRUCT*)cmd->data)->number
    ,((ERRORSTRUCT*)cmd->data)->text);
  }
}

void adjPoint(COMMANDSTRUCT *cmd
        ,tmpnFloat wx, tmpnFloat wy, tmpnFloat wz, tmpnFloat wv, tmpnFloat ww, tmpnFloat wu, tmpnFloat wt, int tcpidx)
{
  POINTSTRUCT *point;
  //TODO if epoint then adj from patternitem
  if(cmd->type==POINT||cmd->type==RPOINT||cmd->type==EPOINT||cmd->type==HPOINT||cmd->type==HRPOINT)
  {
     point = (POINTSTRUCT*)cmd->data;
     point->fp.x=wx-trobot->m_frames.frame[point->frameidx].x-point->pp.x;
     point->fp.y=wy-trobot->m_frames.frame[point->frameidx].y-point->pp.y;
     point->fp.z=wz-trobot->m_frames.frame[point->frameidx].z-point->pp.z;
     point->fp.v=wv-trobot->m_frames.frame[point->frameidx].v-point->pp.v;
     point->fp.w=ww-trobot->m_frames.frame[point->frameidx].w-point->pp.w;
     point->fp.u=wu-trobot->m_frames.frame[point->frameidx].u-point->pp.u;
     point->p.dt=wt;
     point->p.tcpidx=tcpidx;
     refreshPoint(cmd);
  }
}

int jointToTask(const char *filename)
{
  FILE *fp;
  FILE *fpout;
  int version;
  char t[256];
  char fn[256];
  char fname[256];
  char fnout[256];
  tmpnJoints joint;
  tmpnJoints actuator;
  int dt;
  tmpnRobot *robot=(tmpnRobot*)trobot;
   
  //forskel mellem mpnGuide og rs
// if(filename[0]!='/')
//    sprintf(fname,"%s/script/%s.rss",databasePath,filename);
// else
   sprintf(fname,"%s",filename);
    
 if(!strcmp(&fname[strlen(fname)-4],".rss")) {
      return FALSE;
    }
    sprintf(fn,"%s",fname);
    sprintf(fnout,"%s.rss",fname);
  
  fp = fopen(fn,"r");

  if(fp==NULL)
  {
    printf("xscript=%s not found!\n",fn);
    return FALSE;
  }

  fscanf(fp,"VERSION %d\n", &version);

  if(//version!=1
     version!=JOINTSCRIPTVERSION)
  {
    printf("SCRIPTVERSION error\n");
    return FALSE;
  }

  fpout = fopen(fnout,"w");
  if(fpout==NULL) {
    printf("File: %s could not be opened for writing!\n",filename);
    return FALSE;
  }
  fprintf(fpout,"VERSION %d\n", SCRIPTVERSION);

  memset(t, 0, 256);
  fgets(t,256,fp);

  while(!feof(fp))
  {
    if(sscanf(t,"JOINT %f,%f,%f,%f,%f,%f,%i"
     ,&joint.a
     ,&joint.b
     ,&joint.c
     ,&joint.d
     ,&joint.e
     ,&joint.f
     ,&dt
      )) {
    actuator.a = robot->m_sign.name.a*joint.a;
    actuator.b = -robot->m_sign.name.b*joint.b;
    actuator.c = -robot->m_sign.name.c*joint.c;
    
    actuator.d = robot->m_sign.name.d*joint.d;

    actuator.e = joint.e - actuator.d/robot->m_gearing.name.e;
    actuator.e = robot->m_sign.name.e*actuator.e;
    actuator.f = robot->m_sign.name.f*joint.f;

    actuator.a += robot->m_jointCalib.a;
    actuator.b += robot->m_jointCalib.b;
    actuator.c += robot->m_jointCalib.c;
    actuator.d += robot->m_jointCalib.d;
    actuator.e += robot->m_jointCalib.e;
    actuator.f += robot->m_jointCalib.f;
    
    tmpnComputeFK(robot, actuator.a
    , actuator.b
    , actuator.c
    , actuator.d
    , actuator.e
    , actuator.f, getTCPidx("zero",robot));
    //, actuator.f, 2);
    fprintf(fpout,"POINT base %f,%f,%f,%f,%f,%f,%i zero\n",robot->m_worldPoint.x
    , robot->m_worldPoint.y
    , robot->m_worldPoint.z
    , robot->m_worldPoint.v
    , robot->m_worldPoint.w
    , robot->m_worldPoint.u
    , dt
    );
    }           
    else fprintf(fpout,"%s",t);
    fgets(t,256,fp);
  }
  fclose(fp);
  fclose(fpout);
  return TRUE;
}

int generateCommandScript(const char *fn, int flag)
{
  return 0;
}

//firstcmd
void ResetCmdLoadBuffer(COMMANDSTRUCT *root, int loadgroup)
{
  COMMANDSTRUCT *prcmd;
    // clear all preloaded path
  prcmd=root;
  while(prcmd)
  {
    if(prcmd->type==PATH&&((PATHSTRUCT*)prcmd->data)->tpathdef.loadgroup==loadgroup)
    {
      ((PATHSTRUCT*)prcmd->data)->tpathdef.idx = -1;
    }
    prcmd = prcmd->next;
  }
}

COMMANDSTRUCT *LoadCommandScript(const char *filename, int flag)
{
  FILE *fp;
  COMMANDSTRUCT *cmd,*root;
  int i,version;
  char t[256];
  char tt[256];
  char fn[256];
  
  int level = 0;

  
  //forskel mellem mpnGuide og rs
//if(flag==1)
//  strcpy(fn,filename);
//else
  sprintf(fn,"%s/script/%s.rss",databasePath,filename);
  
  printf("opening %s\n",fn);
  fp = fopen(fn,"r");

  if(fp==NULL)
  {
    printf("yscript=%s not found!\n",fn);
    return NULL;
  }

  fscanf(fp,"VERSION %d\n", &version);

  if(//version!=1
     version!=SCRIPTVERSION)
  {
    printf("SCRIPTVERSION error\n");
    return NULL;
  }

  memset(t, 0, 256);
  fgets(t,256,fp);

  //read first line in script
  root = addCommandString(NULL,"ROOT",&level);
  cmd = root;

  
  while(!feof(fp))
  {
    strcpy(tt,t);
    for(i=0;i<strlen(t);i++)
    {
      if(t[i]!=' ') 
      {
        strcpy(tt,&t[i]);
        i=strlen(t);
      }
    }                 
    cmd = addCommandString(cmd,tt,&level);
    memset(t, 0, 256);
    fgets(t,256,fp);
  }
  fclose(fp);
  updatecmdPoints(root);
  return root;
}


static int numOfCounters=0;
static COUNTERSTRUCT counters[MAXCOUNTERS];

COUNTERSTRUCT *getCounter(char *name)
{
  int i;
  for(i=0;i<numOfCounters;i++)
  {
    if(strcmp(counters[i].name,name)==0)
      return &counters[i];
  }
  return NULL;
}

char *getCounterValue(char* value)
{
  //try to find a counter with where name=value
  COUNTERSTRUCT *vcnt=getCounter(value);
  if(vcnt==NULL) return value;
  return vcnt->value;
}

COUNTERSTRUCT *initCounter(char *name, char* value)
{
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    strcpy(cnt->value,getCounterValue(value));
    return cnt;
  }
  if(numOfCounters>=MAXCOUNTERS) return NULL;
  cnt=&counters[numOfCounters++];
  strcpy(cnt->name,name);
  strcpy(cnt->value,getCounterValue(value));
  return cnt;
}

COUNTERSTRUCT *incCounter(char *name, char* value)
{
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    sprintf(cnt->value,"%d",atoi(cnt->value)+atoi(getCounterValue(value)));
    return cnt;
  }
  return NULL;
}

COUNTERSTRUCT *mulCounter(char *name, char* value)
{
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    sprintf(cnt->value,"%d",atoi(cnt->value)*atoi(getCounterValue(value)));
    return cnt;
  }
  return NULL;
}

COUNTERSTRUCT *divCounter(char *name, char* value)
{
  int val;
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    val=atoi(getCounterValue(value));
    if(val==0) 
      sprintf(cnt->value,"0");
    else 
      sprintf(cnt->value,"%d",atoi(cnt->value)/val);
    return cnt;
  }
  return NULL;
}

COUNTERSTRUCT *decCounter(char *name, char* value)
{
  COUNTERSTRUCT *cnt=getCounter(name);
  if(cnt)
  {
    sprintf(cnt->value,"%d",atoi(cnt->value)-atoi(getCounterValue(value)));
    return cnt;
  }
  return NULL;
}

COMMANDSTRUCT *FindLabelCmd(COMMANDSTRUCT *pcmd, const char *label)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==NULL) return NULL;
  cmd = pcmd->next;
  while(cmd)
  {
    if(cmd->type==LABEL&&strcmp(((LABELSTRUCT*)cmd->data)->label,label)==0)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}

COMMANDSTRUCT *FindNextCmdToUpload(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==NULL) return NULL;
  cmd = pcmd->next;
  while(cmd)
  {
    if(cmd->type==PATH)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}
//firstcmd
COMMANDSTRUCT *FindFirstCmdToUpload(COMMANDSTRUCT *root)
{
  COMMANDSTRUCT *cmd;
  cmd=root;
  while(cmd)
  {
    if(cmd->type==PATH)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}

COMMANDSTRUCT *findNextToPreload(COMMANDSTRUCT *pcmd)
{
  int loadgroup;
  COMMANDSTRUCT *cmd;
  if(pcmd==NULL) return NULL;
  loadgroup=((PATHSTRUCT*)pcmd->data)->tpathdef.loadgroup;
  cmd = pcmd->next;
  while(cmd)
  {
    if(cmd->type==PATH&&((PATHSTRUCT*)cmd->data)->tpathdef.idx==-1&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}

COMMANDSTRUCT *findFirstPreloaded(COMMANDSTRUCT *root, int loadgroup)
{
  COMMANDSTRUCT *cmd;
  cmd=root;
  while(cmd)
  {
    if(cmd->type==PATH&&((PATHSTRUCT*)cmd->data)->tpathdef.idx!=-1&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}
//**************************************************
//* find the first path in group that is not loaded
//**************************************************
COMMANDSTRUCT *findFirstPathInGroup(COMMANDSTRUCT *root, int loadgroup)
{
  COMMANDSTRUCT *cmd;
  cmd=root;
  while(cmd)
  {
    if(cmd->type==PATH&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup)
    { 
      if(((PATHSTRUCT*)cmd->data)->tpathdef.idx==-1)
      {                   
        return cmd;
      }
    }
    cmd = cmd->next;
  }
  return NULL;
}

//**************************************************
//* find the cItem path in group 
//**************************************************
COMMANDSTRUCT *findItemPathInGroup(COMMANDSTRUCT *root, int loadgroup)
{
  COMMANDSTRUCT *cmd;
  int startload=0;

  if(loadgroup==0) 
  {
    startload=atoi(getCounterValue("cAItems"));
  }
  else if(loadgroup==1)
  {
    startload=atoi(getCounterValue("cBItems")); 
  }
  else
  {
    return findFirstPathInGroup(root,loadgroup);
  }
  if(rs_param.mc_task_debug>2) printf("startload(%d)=%d\n",loadgroup,startload); 
  cmd=root;
  while(cmd)
  {
    if(cmd->type==PATH&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup&&((PATHSTRUCT*)cmd->data)->tpathdef.id==startload) return cmd;
    cmd = cmd->next;
  }
  return NULL;
}

int countPreload(COMMANDSTRUCT *root, int loadgroup)
{
  int preload;
  COMMANDSTRUCT *cmd;
  cmd=root;
  preload=0;
  while(cmd)
  {
    if(cmd->type==PATH&&((PATHSTRUCT*)cmd->data)->tpathdef.idx!=-1&&((PATHSTRUCT*)cmd->data)->tpathdef.loadgroup==loadgroup)
    {
      preload++;
    }
    cmd = cmd->next;
  }
  return preload;
}

static int isRuncommand(COMMANDSTRUCT *cmd)
{
  if(cmd->type==MACRO
   ||cmd->type==SCOPE
   ||cmd->type==CALL
   ||cmd->type==RESETPRELOAD
   ||cmd->type==LABEL
   ||cmd->type==GOTO
   ||cmd->type==JUMPLAYER
   ||cmd->type==STOP
   ||cmd->type==ERROR
   ||cmd->type==MOVEAXIS
   ||cmd->type==CANCELAXIS
   ||cmd->type==TESTEVENT
   ||cmd->type==WAITEVENT
   ||cmd->type==SLEEP
   ||cmd->type==SIGNALEVENT
   ||cmd->type==COUNTER
   ||cmd->type==TUNING
   ||cmd->type==SETSPEED
   ||cmd->type==IN
   ||cmd->type==OUT
   ||cmd->type==PATH)
    return TRUE;
 return FALSE;
}

COMMANDSTRUCT *getLabelCommand(COMMANDSTRUCT *root, const char *label)
{
  COMMANDSTRUCT *cmd;
  cmd = root;
  while(cmd)
  {
    if(cmd->type==LABEL&&strcmp(((LABELSTRUCT*)cmd->data)->label,label)==0)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}

COMMANDSTRUCT *getNextRunCommand(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==NULL) return NULL;
  cmd = pcmd->next;
  while(cmd)
  {
    if(isRuncommand(cmd))
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}

COMMANDSTRUCT *getNextRunCommandAtSameLevel(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  int level;
  if(pcmd==NULL) return NULL;
  level=pcmd->flag;
  cmd = pcmd->next;
  while(cmd)
  {
    if(isRuncommand(cmd)&&cmd->flag<=level)
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}

POINTSTRUCT *getPoint(COMMANDSTRUCT *pcmd, int off)
{
  COMMANDSTRUCT *cmd;
  int i;
  if(pcmd==NULL) return NULL;
  if(off==0) return (POINTSTRUCT*)pcmd->data;
  if(off>0)
  {
    cmd = pcmd->next;
    i=1;
    while(cmd)
    {
      if(cmd->type==POINT&&i++>=off)
      {
        return (POINTSTRUCT*)cmd->data;
      }
      cmd = cmd->next;
    }
  }
  else
  {
    cmd = pcmd->prev;
    i=1;
    while(cmd)
    {
      if(cmd->type==POINT&&i++>=-off)
      {
        return (POINTSTRUCT*)cmd->data;
      }
      cmd = cmd->prev;
    }
  }
  return NULL;
}
COMMANDSTRUCT *getPrevPPScriptCommand(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==NULL) return NULL;
  cmd = pcmd->prev;
  while(cmd)
  {
    if(cmd->type==PPSCRIPT)
    {
      return cmd;
    }
    cmd = cmd->prev;
  }
  return NULL;
}

COMMANDSTRUCT *getPrevRunCommand(COMMANDSTRUCT *pcmd)
{
  COMMANDSTRUCT *cmd;
  if(pcmd==NULL) return NULL;
  cmd = pcmd->prev;
  while(cmd)
  {
    if(isRuncommand(cmd))
    {
      return cmd;
    }
    cmd = cmd->prev;
  }
  return NULL;
}

  

COMMANDSTRUCT *getFirstRunCommand(COMMANDSTRUCT *root)
{
  COMMANDSTRUCT *cmd;
  cmd=root;
  while(cmd)
  {
    if(isRuncommand(cmd))
    {
      return cmd;
    }
    cmd = cmd->next;
  }
  return NULL;
}

COMMANDSTRUCT *getLastRunCommand(COMMANDSTRUCT *root)
{
  COMMANDSTRUCT *cmd;
  for(cmd=root;cmd!=NULL&&cmd->next!=NULL;cmd=cmd->next);
  while(cmd)
  {
    if(isRuncommand(cmd))
    {
      return cmd;
    }
    cmd = cmd->prev;
  }
  return NULL;
}

void adjPath(PATHSTRUCT *path)
{
  COMMANDSTRUCT *pcmd = path->firstpoint; //set in CreateRunScript
  refreshPath(pcmd);
}

tmpnFloat pointDist(tmpnKeyPoint *p0, tmpnKeyPoint *p1)
{
  return sqrt((p1->x-p0->x)*(p1->x-p0->x)
             +(p1->y-p0->y)*(p1->y-p0->y)
             +(p1->z-p0->z)*(p1->z-p0->z)
             +(p1->v-p0->v)*(p1->v-p0->v)
             +(p1->w-p0->w)*(p1->w-p0->w)
             +(p1->u-p0->u)*(p1->w-p0->u));
}


void refreshPath(COMMANDSTRUCT *pcmd)
{
  POINTSTRUCT *point;
  PATHSTRUCT *path;
  int statehint=1;
  int positionhint=0;
  int i=0;
  int level;
  int firstPoint,lastPointIdx;
  COMMANDSTRUCT *cmd;
  tmpnRobot *robot=(tmpnRobot*)trobot;
  if(pcmd==NULL) return;
  path = (PATHSTRUCT*)pcmd->data;
  path->tpathdef.spline=robot->splinehint;
  path->tpathdef.splineorder=robot->splineorder;
  updatecmdPoints(pcmd);
  level=pcmd->flag;
  cmd = pcmd->next;
  lastPointIdx=-1;
  path->tpathdef.samplesBetweenKeypoints=defpathsamprate;
  while(cmd&&cmd->flag>level)
  {
    if(cmd&&cmd->type==SPLINEHINT)
    {
      path->tpathdef.spline=((SPLINEHINTSTRUCT*)cmd->data)->splinehint;
      path->tpathdef.splineorder=((SPLINEHINTSTRUCT*)cmd->data)->splineorder;
      cmd = cmd->next;
    }
    else if(cmd&&cmd->type==STATEHINT)
    {
      statehint=((STATEHINTSTRUCT*)cmd->data)->statehint;
      cmd = cmd->next;
    }
    else if(cmd&&cmd->type==POSITIONHINT)
    {
      positionhint=((POSITIONHINTSTRUCT*)cmd->data)->positionhint;
      cmd = cmd->next;
    }
    else if(cmd->type==POINT||cmd->type==RPOINT||cmd->type==EPOINT)
    {
      i++;
      path->tpathdef.maxidx=0;
      path->tpathdef.maxhidx=0;
      path->tpathdef.maxpidx=0;
      path->firstpoint=pcmd;
      firstPoint=TRUE;
      while(cmd&&cmd->flag>level
               &&cmd->type!=WSP
               &&cmd->type!=CALL
               &&cmd->type!=RESETPRELOAD
               &&cmd->type!=JUMPLAYER
               &&cmd->type!=MACRO
               &&cmd->type!=SCOPE
               &&cmd->type!=LABEL
               &&cmd->type!=GOTO
               &&cmd->type!=PPSCRIPT
               &&cmd->type!=IN
               &&cmd->type!=OUT
               &&cmd->type!=MOVEAXIS
               &&cmd->type!=CANCELAXIS
               &&cmd->type!=STOP
               &&cmd->type!=ERROR
               &&cmd->type!=TESTEVENT
               &&cmd->type!=WAITEVENT
               &&cmd->type!=SLEEP
               &&cmd->type!=SIGNALEVENT
               &&cmd->type!=COUNTER
               &&cmd->type!=TUNING
               &&cmd->type!=SETSPEED
               &&cmd->type!=SPLINEHINT
               &&cmd->type!=PATH
               &&cmd->type!=SADS)
      {
        if(cmd->type==POINT||cmd->type==RPOINT||cmd->type==EPOINT)
        {
          point = (POINTSTRUCT*)cmd->data;
          path->tpathdef.keypoint[path->tpathdef.maxidx].x=point->p.x;
          path->tpathdef.keypoint[path->tpathdef.maxidx].y=point->p.y;
          path->tpathdef.keypoint[path->tpathdef.maxidx].z=point->p.z;
          path->tpathdef.keypoint[path->tpathdef.maxidx].v=point->p.v;
          path->tpathdef.keypoint[path->tpathdef.maxidx].w=point->p.w;
          path->tpathdef.keypoint[path->tpathdef.maxidx].u=point->p.u;
          path->tpathdef.keypoint[path->tpathdef.maxidx].dt=point->p.dt;
          path->tpathdef.keypoint[path->tpathdef.maxidx].tcpidx=point->p.tcpidx;
          path->tpathdef.keypoint[path->tpathdef.maxidx].statehint=statehint;
          path->tpathdef.keypoint[path->tpathdef.maxidx].positionhint=positionhint;
          point->path = path;
          lastPointIdx=path->tpathdef.maxidx;
          path->tpathdef.maxidx++;
        }
        else if(cmd->type==HPOINT||cmd->type==HRPOINT)
        {
          point = (POINTSTRUCT*)cmd->data;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].x=point->p.x;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].y=point->p.y;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].z=point->p.z;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].v=point->p.v;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].w=point->p.w;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].u=point->p.u;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].dt=point->p.dt;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].tcpidx=point->p.tcpidx;
          path->tpathdef.hpoint[path->tpathdef.maxhidx].keypointidx=lastPointIdx;
          point->path = path;
          path->tpathdef.maxhidx++;
        }
        else if(cmd->type==STATEHINT)
        {
          statehint=((STATEHINTSTRUCT*)cmd->data)->statehint;
        }
        else if(cmd->type==POSITIONHINT)
        {
          positionhint=((POSITIONHINTSTRUCT*)cmd->data)->positionhint;
          path->tpathdef.poshint[path->tpathdef.maxpidx].positionhint=positionhint;
          path->tpathdef.poshint[path->tpathdef.maxpidx].time=-1;
          path->tpathdef.poshint[path->tpathdef.maxpidx].i=0;
          path->tpathdef.maxpidx++;
        }
        cmd = cmd->next;
      }
   }
    else
    {
      cmd = cmd->next;
    }
  }
}

int LoadCalibrationParam(tmpnRSSystem *ini)
{
  if(!tmpnPlantLoad(ini->plant,tplant))
  {
    return FALSE;
  }
  selectWorkcell(getWorkcellIdx(ini->workcell,tplant));
  selectRobot(getRobotIdx(ini->robot,(tmpnWorkcell*)tworkcell));

  printf("Plant: %s Workcell: %s Robot: %s loaded.... \nLocation: \e[32m %s \e[0m\n",tplant->name,tworkcell->name,trobot->m_name,ini->location);
  return TRUE;
}

int SaveCalibrationParam(tmpnRSSystem *ini)
{
  if(tmpnRobotSave(ini->robot,(tmpnRobot*)trobot)==FALSE)
  {
    return FALSE;
  }
  return TRUE;
}

static void updateRSSystem(char *s, tmpnRSSystem *ini)
{
  if(strncmp(s,"plant=",6)==0)
  {
    sscanf(s,"plant=%s\n",ini->plant);
  }
  else if(strncmp(s,"workcell=",9)==0)
  {
    sscanf(s,"workcell=%s\n",ini->workcell);
  }
  else if(strncmp(s,"location=",9)==0)
  {
    sscanf(s,"location=%s\n",ini->location);
  }
  else if(strncmp(s,"robot=",6)==0)
  {
    sscanf(s,"robot=%s\n",ini->robot);
  }
  else if(strncmp(s,"user=",5)==0)
  {
    sscanf(s,"user=%s\n",ini->user);
  }
  else if(strncmp(s,"password=",9)==0)
  {
    sscanf(s,"password=%s\n",ini->password);
  }
  else if(strncmp(s,"script=",7)==0)
  {
    sscanf(s,"script=%s\n",ini->script);
  }
  else if(strncmp(s,"mainDialog=",11)==0)
  {
    sscanf(s,"mainDialog=%s\n",ini->mainDialog);
  }
  else if(strncmp(s,"workcellid=",11)==0)
  {
    sscanf(s,"workcellid=%d\n",&ini->workcellid);
  }
  else if(strncmp(s,"touch.initialized=",18)==0)
  {
    sscanf(s,"touch.initialized=%d\n",&ini->touch.initialized);
  }
  else if(strncmp(s,"touch.offx=",11)==0)
  {
    sscanf(s,"touch.offx=%d\n",&ini->touch.offx);
  }
  else if(strncmp(s,"touch.offy=",11)==0)
  {
    sscanf(s,"touch.offy=%d\n",&ini->touch.offy);
  }
  else if(strncmp(s,"touch.calx=",11)==0)
  {
    sscanf(s,"touch.calx=%f\n",&ini->touch.calx);
  }
  else if(strncmp(s,"touch.caly=",11)==0)
  {
    sscanf(s,"touch.caly=%f\n",&ini->touch.caly);
  }
  else if(strncmp(s,"touchctrltype=",14)==0)
  {
    sscanf(s,"touchctrltype=%d\n",&ini->touch.ctrltype);
  }
  else if(strncmp(s,"touchport=",10)==0)
  {
    sscanf(s,"touchport=%s\n",ini->touch.port);
  }
  else if(strncmp(s,"statemachine_debug=",19)==0)
  {
    sscanf(s,"statemachine_debug=%d\n",&ini->statemachine_debug);
  }
  else if(strncmp(s,"io_debug=",9)==0)
  {
    sscanf(s,"io_debug=%d\n",&ini->io_debug);
  }
  else if(strncmp(s,"mc_task_debug=",14)==0)
  {
    sscanf(s,"mc_task_debug=%d\n",&ini->mc_task_debug);
  }
  else if(strncmp(s,"path_debug=",10)==0)
  {
    sscanf(s,"path_debug=%d\n",&ini->path_debug);
  }
  else if(strncmp(s,"startSpeed=",11)==0)
  {
    sscanf(s,"startSpeed=%d\n",&ini->startSpeed);
  }
  else if(strncmp(s,"simulateMC=",10)==0)
  {
    sscanf(s,"simulateMC=%d\n",&ini->simulateMC);
  }
  else if(strncmp(s,"pcIPaddr=",9)==0)
  {
    sscanf(s,"pcIPaddr=%s\n",ini->pcIPaddr);
  }
  else if(strncmp(s,"stmServerPort=",14)==0)
  {
    sscanf(s,"stmServerPort=%d\n",&ini->stmServerPort);
  }
  else if(strncmp(s,"mcIPaddr=",9)==0)
  {
    sscanf(s,"mcIPaddr=%s\n",ini->mcIPaddr);
  }
  else if(strncmp(s,"controllerIPaddr=",17)==0)
  {
    sscanf(s,"controllerIPaddr=%s\n",ini->mcIPaddr);
  }
  else if(strncmp(s,"useNic=",7)==0)
  {
    sscanf(s,"useNic=%s\n",ini->nic);
  }
  else if(strncmp(s,"lag=",4)==0)
  {
    sscanf(s,"lag=%d\n",&ini->lag);
  }
  else if(strncmp(s,"checkWeigher=",13)==0)
  {
    sscanf(s,"checkWeigher=%d\n",&ini->checkWeigher);
  }
  else if(strncmp(s,"roboStacker=",12)==0)
  {
    sscanf(s,"roboStacker=%d\n",&ini->roboStacker);
  }
  else if(strncmp(s,"scriptExec=",11)==0)
  {
    sscanf(s,"scriptExec=%d\n",&ini->scriptExec);
  }
  else if(strncmp(s,"new_trio_addr=",14)==0)
  {
    sscanf(s,"new_trio_addr=%d\n",&ini->new_trio_addr);
  }
  else if(strncmp(s,"mc_version=",11)==0)
  {
    sscanf(s,"mc_version=%d\n",&ini->mc_version);
  }
}

static int mntdatabase(void)
{
  FILE *fp;
  char buffer[256];
	fp = fopen("/mnt/mntdatabase.txt","r");
  if(fp==NULL)
		fp = fopen("mntdatabase.txt","r");
  if(fp==NULL)
    fp = fopen("/home/thn/sandbox/mnt/mntdatabase.txt","r");
  if(fp==NULL)
    fp = fopen("/home/lms/sandbox/mnt/mntdatabase.txt","r");
  if(fp==NULL)
    fp = fopen("/home/mil/sandbox/mnt/mntdatabase.txt","r");
  if(fp==NULL)
  {
    if(strlen(rs_systempath) == 0)
    {
      strcpy(rs_systempath,"/mnt/database");
      printf("mntdatabase.txt: defaulting to /mnt/database\n");
    }
    if(strlen(rs_systemini) == 0)
    {
      strcpy(rs_systemini,"rssystem.ini");
      printf("mntdatabase.txt: defaulting to rssystem.ini\n");
    }
    return TRUE;
  }

  if(strlen(rs_systempath) == 0)
  {
    if(fgets(buffer, sizeof(buffer), fp)!=NULL)
    {
      sscanf(buffer,"%s\n",rs_systempath);
    }
  }
  printf("using database=%s\n",rs_systempath);

  if(strlen(rs_systemini) == 0)
  {  
    if(fgets(buffer, sizeof(buffer), fp)!=NULL)
    {
      sscanf(buffer,"%s\n",rs_systemini);
      if(strcmp("605system.ini",rs_systemini) == 0)
      {
        if(fgets(buffer, sizeof(buffer), fp)!=NULL)
        {
          sscanf(buffer,"%s\n",rs_systemini);
          demo = 1;
        }
      }
    }
    else
    {
      strcpy(rs_systemini,"rssystem.ini");
      printf("defaulting to rssystem.ini\n");
    }
  }
  printf("using system=%s\n",rs_systemini);
  fclose(fp);
  return TRUE;
}

int LoadRSSystemData(tmpnRSSystem *ini)
{
  FILE *fp;
  char buffer[256];
  char filename[256];
  int cmd_version;
  if(!mntdatabase()) return FALSE;
  sprintf(filename,"%s/system/%s",rs_systempath,rs_systemini);
  fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("rsssystem.ini: Unknown file %s\n",filename);
    return FALSE;
  }
  fscanf(fp,"VERSION %d\n",&cmd_version);
  if(cmd_version!=1&&cmd_version!=2)
  {
    printf("rsssystem.ini: Unknown version in file %s\n", filename);
    return FALSE;
  }
  while(fgets(buffer, sizeof(buffer), fp)!=NULL)
  {
    updateRSSystem(buffer,ini);
  }
  if(ini->touch.initialized==4)
  {
    ini->touch.offx=0;
    ini->touch.offy=0;
    ini->touch.calx=1;
    ini->touch.caly=1;
  }
  fclose(fp);
  return TRUE;
}

int SaveRSSystemData(tmpnRSSystem *ini)
{
  FILE *fp;
  char filename[256];
  if(!mntdatabase()) return FALSE;
  sprintf(filename,"%s/system/%s",rs_systempath,rs_systemini);
  if((fp = fopen(filename, "w"))==NULL)
  {
    printf("rsssystem.ini: Save failed %s\n",filename);
    return FALSE;
  }
  fprintf(fp,"VERSION 2\n");
  fprintf(fp,"plant=%s\n",ini->plant);
  fprintf(fp,"workcell=%s\n",ini->workcell);
	fprintf(fp,"location=%s\n",ini->location);
  fprintf(fp,"robot=%s\n",ini->robot);
  fprintf(fp,"pcIPaddr=%s\n",ini->pcIPaddr);
  fprintf(fp,"stmServerPort=%d\n",ini->stmServerPort);
  fprintf(fp,"mcIPaddr=%s\n",ini->mcIPaddr);
  fprintf(fp,"useNic=%s\n",ini->nic);
  fprintf(fp,"script=%s\n",ini->script);
  fprintf(fp,"workcellid=%d\n",ini->workcellid);
  fprintf(fp,"lag=%d\n",ini->lag);
  fprintf(fp,"touch.initialized=%d\n",ini->touch.initialized);
  fprintf(fp,"touch.offx=%d\n",ini->touch.offx);
  fprintf(fp,"touch.offy=%d\n",ini->touch.offy);
  fprintf(fp,"touch.calx=%f\n",ini->touch.calx);
  fprintf(fp,"touch.caly=%f\n",ini->touch.caly);
  fprintf(fp,"touchctrltype=%d\n",ini->touch.ctrltype);
  fprintf(fp,"touchport=%s\n",ini->touch.port);
  fprintf(fp,"simulateMC=%d\n",ini->simulateMC);
  fprintf(fp,"mc_task_debug=%d\n",ini->mc_task_debug);
  fprintf(fp,"path_debug=%d\n",ini->path_debug);
  fprintf(fp,"statemachine_debug=%d\n",ini->statemachine_debug);
	fprintf(fp,"io_debug=%d\n",ini->io_debug);
  fprintf(fp,"startSpeed=%d\n",ini->startSpeed);
  fprintf(fp,"user=%s\n",ini->user);
  fprintf(fp,"password=%s\n",ini->password);
  fprintf(fp,"checkWeigher=%d\n",ini->checkWeigher);
  fprintf(fp,"roboStacker=%d\n",ini->roboStacker);
  fprintf(fp,"mainDialog=%s\n",ini->mainDialog);
  fprintf(fp,"scriptExec=%d\n",ini->scriptExec);
  fprintf(fp,"new_trio_addr=%d\n",ini->new_trio_addr);
  fprintf(fp,"mc_version=%d\n",ini->mc_version);

  fclose(fp);

  return TRUE;
}

int saveScopeSample(char *file, char *s)
{
  FILE *fp;
  char filename[256];
  sprintf(filename,"%s/scope/%s.txt",rs_systempath, file);
  fp = fopen(filename, "a");
  if(fp!=NULL)
  {
    fprintf(fp,"%s", s);
    fclose(fp);
  }
  return 0;
}

//***************************************************************************
//* libRunCounter                                                           *
//***************************************************************************

int libRunCounter(COMMANDSTRUCT *cmd, COMMANDSTRUCT **pcmd)
{
//  int loopcnt=0;
  clock_t start;
  if(rs_param.mc_task_debug>1) start = times(NULL);
  COUNTERSTRUCT *cnt;
  char *cVal;
  char *tVal;
  char cntval[256];
  
//  ploop=*pcmd;
//loop100:    
//  *pcmd=ploop;
//  loopcnt++;
  if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"=")==0)
  {
    cnt=initCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"+=")==0)
  {
    cnt=incCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"-=")==0)
  {
    cnt=decCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"*=")==0)
  {
    cnt=mulCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"/=")==0)
  {
    cnt=divCounter(((COUNTERSTRUCT*)cmd->data)->name,((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,cnt->value);
    *pcmd=getNextRunCommand(cmd);
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"==")==0)
  {
    cVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->name);
    tVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,tVal);
    if(!(atoi(cVal)==atoi(tVal)))
    {
      *pcmd=getNextRunCommandAtSameLevel(cmd);
    }
    else
    {
      *pcmd=getNextRunCommand(cmd);
    }
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,"<")==0)
  {
    cVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->name);
    tVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,tVal);
    if(!(atoi(cVal)<atoi(tVal)))
    {
      *pcmd=getNextRunCommandAtSameLevel(cmd);
    }
    else
    {
      *pcmd=getNextRunCommand(cmd);
    }
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,">")==0)
  {
    cVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->name);
    tVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,tVal);
    if(!(atoi(cVal)>atoi(tVal)))
    {
      *pcmd=getNextRunCommandAtSameLevel(cmd);
    }
    else
    {
      *pcmd=getNextRunCommand(cmd);
    }
  }
  else if(strcmp(((COUNTERSTRUCT*)cmd->data)->function,">=")==0)
  {
    cVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->name);
    tVal=getCounterValue(((COUNTERSTRUCT*)cmd->data)->value);
    strcpy(cntval,tVal);
    if(!(atoi(cVal)>=atoi(tVal)))
    {
      *pcmd=getNextRunCommandAtSameLevel(cmd);
    }
    else
    {
      *pcmd=getNextRunCommand(cmd);
    }
  }
  

//  jointToTask((char *)fname);
  //}
  return 0;
}


