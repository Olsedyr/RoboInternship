/****************************************************************************
* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/times.h>

#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include "Bx.h"
#include "cmd.h"

#include "advantys.h"

volatile int stmUpAndRunning=0;

int waitCond(volatile int *stopState, pthread_cond_t *cond, pthread_mutex_t *mutex, volatile int *state, int teststate)
{
  int ret=FALSE;
  pthread_mutex_lock(mutex);
  while(*state!=teststate&&(*stopState!=1)) pthread_cond_wait(cond, mutex);
  ret=TRUE;
  pthread_mutex_unlock(mutex);
  return ret;
}

char *getCurrentStateName(int machine)
{
  int stateidx;
  stateidx = tworkcell->statemachines.statemachine[machine].istate;
  return tworkcell->statemachines.statemachine[machine].state[stateidx].name;
}

int testState(int machine, int state)
{
  return (tworkcell->statemachines.statemachine[machine].istate==state);
}

int setState(int machine, int state)
{
  pthread_mutex_lock(&tworkcell->statemachines.statemachine[machine].change_mtx);
  tworkcell->statemachines.statemachine[machine].istate=state;
  tworkcell->statemachines.statemachine[machine].next_istate=-1;
  pthread_cond_broadcast(&tworkcell->statemachines.statemachine[machine].change);
  pthread_mutex_unlock(&tworkcell->statemachines.statemachine[machine].change_mtx);
  
  return TRUE;
}

int testMachineState(const char *machinename, const char *statename)
{
  int machine,state;
  machine = getMachineIdx(machinename);
  if(machine==-1) return FALSE;
  state   = getMachineStateIdx(machinename,statename);
  if(state==-1) return FALSE;
  return testState(machine,state);
}

void setMachineState(const char *machinename, const char *statename)
{
  int machine,state;
  machine = getMachineIdx(machinename);
  if(machine==-1) 
  {
    printf("machine = %s not found\n",machinename);
    return;
  }
  state   = getMachineStateIdx(machinename,statename);
  if(state==-1) 
  {
    printf("state %s in machine = %s not found\n",machinename,statename);
    return;
  }
  setState(machine,state);
}

//TODO this function is only used by Nyhuus
int waitState(int machine, int state)
{
   return waitCond(&tworkcell->statemachines.statemachine[machine].stop,
                   &tworkcell->statemachines.statemachine[machine].change,
						 &tworkcell->statemachines.statemachine[machine].change_mtx,
			 &tworkcell->statemachines.statemachine[machine].istate,
			 state);
}

void setSTMTimer(struct timeval *stmtm, long val)
{
  struct timeval stmTime;
	
  gettimeofday(&stmTime, NULL);

  stmtm->tv_sec = stmTime.tv_sec + val/1000000;
  stmtm->tv_usec = stmTime.tv_usec + (val-((long)(val/1000000)*1000000));
	if (stmtm->tv_usec >= 1000000)
	{
		stmtm->tv_sec += 1;
		stmtm->tv_usec -= 1000000;
	}
}

int getSTMTimer(struct timeval *stmtm)
{
  struct timeval stmTime;

  gettimeofday(&stmTime, NULL);
  // stmtm - stmTime = time left
  // times up <=> time left < 0
  
  // http://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html

  // Perform the carry for the later subtraction by updating stmTime.
  if (stmtm->tv_usec < stmTime.tv_usec) {
    int nsec = (stmTime.tv_usec - stmtm->tv_usec) / 1000000 + 1;
    stmTime.tv_usec -= 1000000 * nsec;
    stmTime.tv_sec += nsec;
  }
  if (stmtm->tv_usec - stmTime.tv_usec > 1000000) {
    int nsec = (stmTime.tv_usec - stmtm->tv_usec) / 1000000;
    stmTime.tv_usec += 1000000 * nsec;
    stmTime.tv_sec -= nsec;
  }
  
  if(stmtm->tv_sec < stmTime.tv_sec) //times up
    return 1;
  else // Calculate time left
    return ((stmtm->tv_sec - stmTime.tv_sec) * 1000000) + (stmtm->tv_usec - stmTime.tv_usec);
}

int getStateMachineError(int number)
{
  int i,j;
  int *errorCode;
  j=0;
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    errorCode = getMachineValuePtr(i,"errorCode");
    if(errorCode!=NULL)
    {
      if(*errorCode!=0)
      {
        if(j==number)
        {
          if(rs_param.statemachine_debug>2)
            printf("errorCode=%d for stm(%d)=%s state=%s\n",*errorCode,i,tworkcell->statemachines.statemachine[i].name
		  							,tworkcell->statemachines.statemachine[i].state[tworkcell->statemachines.statemachine[i].istate].name);
        return *errorCode;
        }
        if(j>0) return 0;
        j++;
      }
    }
  }
  return 0;
}

int getStateMachineMessage(void)
{
  int i;
  int *message;
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    message = getMachineValuePtr(i,"message");
    if(message!=NULL)
    {
      if(*message!=0)
      {
        if(rs_param.statemachine_debug>2)
          printf("message=%d for stm(%d)=%s state=%s\n",*message,i,tworkcell->statemachines.statemachine[i].name
									,tworkcell->statemachines.statemachine[i].state[tworkcell->statemachines.statemachine[i].istate].name);
        return *message;
      }
    }
  }
  return 0;
}

int clearStateMachineError(void)
{
  int i;
  int *errorCode;
  
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    errorCode = getMachineValuePtr(i,"errorCode");
    if(errorCode!=NULL)
    {
      if(*errorCode!=0)
      {
        if(rs_param.statemachine_debug>2)
          printf("errorCode=%d cleared for stm(%d)=%s state=%s\n",*errorCode,i,tworkcell->statemachines.statemachine[i].name
									,tworkcell->statemachines.statemachine[i].state[tworkcell->statemachines.statemachine[i].istate].name);
        *errorCode=0;
			  return TRUE;
    	}
		}
  }
  return FALSE;
}

int setStateMachinesIdle(void)
{
  int i;
  int waiting=0;
  struct timeval stmTime;
  long diff;
  int workcell,robot,program;
  int forcedIdle;
  return 0;
	/* exceptions */
  workcell=getMachineIdx("WorkCell");
	robot=getMachineIdx("Robot");
	program=getMachineIdx("Program");
	/* ************** */
  if(rs_param.statemachine_debug>2)
    printf("while(waiting)\n");
  waiting=1;
  forcedIdle=0;
  while (waiting) 
  {
    waiting=0;
    for(i=0;i<tworkcell->statemachines.maxidx;i++)
    {
      gettimeofday(&stmTime, NULL);
			diff = ((tworkcell->statemachines.statemachine[i].stoptimer.tv_sec-stmTime.tv_sec)*1000000) 
             +(tworkcell->statemachines.statemachine[i].stoptimer.tv_usec-stmTime.tv_usec);
      if(rs_param.statemachine_debug>2)
        printf("stm(%d)=%s diff=%ld\n",i,tworkcell->statemachines.statemachine[i].name,diff);
      if(i!=workcell&&i!=robot&&i!=program&&!testState(i, getStateIdx(i,"ST_IDLE")))
      {
        if(diff>0) 
        {
          waiting++;
          if(rs_param.statemachine_debug>2)
            printf("waiting for stm(%d)=%s state=%s\n",i,tworkcell->statemachines.statemachine[i].name
									,tworkcell->statemachines.statemachine[i].state[tworkcell->statemachines.statemachine[i].istate].name);
        }
        else
        {
		      if(tworkcell->statemachines.statemachine[i].delaystop>0) forcedIdle++;
            setState(i,getStateIdx(i,"ST_IDLE"));
          if(rs_param.statemachine_debug>2)
            printf("stm(%d)=%s seting state=ST_IDLE\n",i,tworkcell->statemachines.statemachine[i].name);
        }
      }
      /*    pthread_mutex_lock(&tworkcell->statemachines.statemachine[i].change_mtx);
      tworkcell->statemachines.statemachine[i].istate = getStateIdx(i,"ST_IDLE");
      pthread_cond_broadcast(&tworkcell->statemachines.statemachine[i].change);
      pthread_mutex_unlock(&tworkcell->statemachines.statemachine[i].change_mtx);*/
    }
    usleep(100000);
  }
  if(rs_param.statemachine_debug>2)
    printf("statemachines are now all in ST_IDLE\n");
  //clear errors
  //TODO do not clear errors unless user has accepted/seen them
//  clearErrorAdvantys((tmpnDIO *)(&tworkcell->dios.dio[0])); //set flag and wait
  return forcedIdle;
}

int stopStateMachines(void)
{
  int i;
  return 0;
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    setSTMTimer(&tworkcell->statemachines.statemachine[i].stoptimer, (long)tworkcell->statemachines.statemachine[i].delaystop);
  }
  return setStateMachinesIdle();
}

void startStateMachines(void)
{
  int i;
  return;
//  clearErrorAdvantys((tmpnDIO*)&tworkcell->dios.dio[0]); //set flag and wait
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
    setSTMTimer(&tworkcell->statemachines.statemachine[i].stoptimer, (long)0);
  }
  while(clearStateMachineError());
  setStateMachinesIdle();
}


int parseStateCmd(int idx)
{
  //struct timeval stmTime;
  tmpnStateMachine *stm = &tworkcell->statemachines.statemachine[idx];
  PRINTSTRUCT *print;
  SETSTRUCT *set;
  LOADSTRUCT *load;
  EXECSTRUCT *exec;
  SETFRAMESTRUCT *setframe;
	SETITEMSTRUCT *setitem;
	ROBOTSPEEDSTRUCT *robotspeed;
	SETPATTERNSTRUCT *setpattern;
	SETCPPATTERNSTRUCT *setcppattern;
  TESTSTRUCT *test;
  CALCSTRUCT *calc;
  int arg1, arg2, prgidx=0,src1,src2;
  float farg1, farg2;
  float fsrc1, fsrc2, fdest;

  char *strarg1="UNKNOWN";
  char *strarg2;
	//  char logstr[256];
  tmpnStateMachineState *state;
  long diff;
  long dest;
	int ltest=0;
  pthread_mutex_lock(&stm->change_mtx);
  if(stm->istate>=stm->numstate
		 ||stm->istate<0)
  {
    printf("unknown state\n");
  }
	
	state = &stm->state[stm->istate];
	while(state->prg[prgidx].type!=END)
	{
	  switch(state->prg[prgidx].type)
	  {
		case TIMEOUT :
			setSTMTimer(&stm->timer, stm->timeout[((TIMEOUTSTRUCT*)state->prg[prgidx].data)->idx].timeout);
			stm->new_istate = ((TIMEOUTSTRUCT*)state->prg[prgidx].data)->number;
			ltest=0;
			prgidx++;
			break;
		case ELSETEST :
			if (ltest!=state->prg[prgidx].level)
			{
				prgidx = ((TESTSTRUCT*)state->prg[prgidx].data)->doneIdx;
				break;
			}
		case TEST :
	  case OR :
	  case AND :
			test=(TESTSTRUCT*)state->prg[prgidx].data;
			ltest=state->prg[prgidx].level;
      if(test->test.subtype==0)
      {
        //TODO point direct to data   
				arg1 = getArgInt(stm,&test->test);
				if(test->cmp.subtype==1)
					farg1 = arg1;
			}
      else
      {
        farg1 = getArgFloat(stm,&test->test);
      }
	    if(test->cmp.subtype==0)
      {	
        //TODO point direct to data   
        arg2 = getArgInt(stm,&test->cmp);
				if(test->test.subtype==1)
					farg2 = arg2;
      }
      else
      {
        farg2 = getArgFloat(stm,&test->cmp);
      }
      if(test->test.type == LINK)
			{
				if (stm->link[test->test.idx].stmidx!=-1)
				{
					arg1 = tworkcell->statemachines.statemachine[stm->link[test->test.idx].stmidx].istate;
				}
				else
				{
					int remidx;
					remidx = getRemoteStatemachineIdx((tmpnWorkcell *)tworkcell,stm->link[test->test.idx].name);
					tmpnRemoteStateMachine *remstm = &(((tmpnWorkcell *)tworkcell)->remotestatemachines.remotestatemachine[remidx]);
					if (remidx>=0)
					{
						if (pthread_mutex_trylock(&remstm->remotelock)==0)
						{
							strcpy(remstm->safe,remstm->state);
							pthread_mutex_unlock(&remstm->remotelock);
						}
						strarg1 = (char*) remstm->safe;
					}		
				}
      }
      else if(test->test.type == TIMEOUT)
      {
        arg1 = getSTMTimer(&stm->timer);
        farg1=arg1;
			}	
      if(test->cmp.type == LINK)
			{
				if (stm->link[test->test.idx].stmidx!=-1)
				{
					arg2 = test->cmp.number;
					farg2 = arg2;
				}
				else
				{
					strarg2 = test->cmp.valstring;
				}
      }			
			if ((test->cmp.type != LINK)||(stm->link[test->test.idx].stmidx!=-1))
			{
				prgidx = test->falseIdx;
				if (test->test.subtype==1||test->cmp.subtype==1)
				{
					switch(test->validation)
					{
					case EQUAL :
						//	if(test->cmp.type == LINK)
						//		printf("Arg1 %i %s Arg2 %i %s\n",arg1,test->test.valstring,arg2,test->cmp.valstring);
						if( farg1 == farg2)
							prgidx = test->trueIdx;
						break;
					case NOT_EQUAL :
						if( farg1 != farg2)
							prgidx = test->trueIdx;
						break;
					case MORE :
						if( farg1 > farg2)
							prgidx = test->trueIdx;
						break;
					case MORE_EQUAL :
						if( farg1 >= farg2)
							prgidx = test->trueIdx;
						break;
					case LESS :
						if( farg1 < farg2)
							prgidx = test->trueIdx;
						break;
					case LESS_EQUAL :
						if( farg1 <= farg2)
							prgidx = test->trueIdx;
						break;
					default:
						printf("TEST unknown validation\n");
						break;
					}
				}
				else
				{
					switch(test->validation)
					{
					case EQUAL :
						//	if(test->cmp.type == LINK)
						//		printf("Arg1 %i %s Arg2 %i %s\n",arg1,test->test.valstring,arg2,test->cmp.valstring);
						if( arg1 == arg2)
							prgidx = test->trueIdx;
						break;
					case NOT_EQUAL :
						if( arg1 != arg2)
							prgidx = test->trueIdx;
						break;
					case MORE :
						if( arg1 > arg2)
							prgidx = test->trueIdx;
						break;
					case MORE_EQUAL :
						if( arg1 >= arg2)
							prgidx = test->trueIdx;
						break;
					case LESS :
						if( arg1 < arg2)
							prgidx = test->trueIdx;
						break;
					case LESS_EQUAL :
						if( arg1 <= arg2)
							prgidx = test->trueIdx;
						break;
					default:
						printf("TEST unknown validation\n");
						break;
					}
				}
			}
			else 
			{
				prgidx = test->falseIdx;
				int retval = !strcmp(strarg1,strarg2);
				if ((retval&&test->validation==EQUAL)||(!retval&&test->validation==NOT_EQUAL))
				{
					prgidx = test->trueIdx;
				}
			}
			break;
		case ROBOTSPEED :
			robotspeed = (ROBOTSPEEDSTRUCT*)state->prg[prgidx].data;
			fsrc1 = getArgFloat(stm,&robotspeed->src);
			speedFactor=fsrc1*0.01;
			ltest=0;
			prgidx++;
			break;
		case SET :
			set = (SETSTRUCT*)state->prg[prgidx].data;
      //TODO 4 cases int=int int=float float=int float=float
      if(set->dest.subtype==0)
      {
	      src1 = getArgInt(stm,&set->src);
        setArgInt(stm,&set->dest,src1); 
      }
      else
      {
	      fsrc1 = getArgFloat(stm,&set->src);
        setArgFloat(stm,&set->dest,fsrc1); 
      }

			if(set->dest.type==VALUE&&set->src.type==TIMEOUT)
			{
        arg1 = getSTMTimer(&stm->timer);
				stm->value[set->dest.idx].data=arg1;
			}
			ltest=0;
			prgidx++;
			break;
	  case CALC :
	    calc = (CALCSTRUCT*)state->prg[prgidx].data;
      // TEST dest datatype and get accordingly
      if(calc->dest.subtype==0)
      {
        src1 = getArgInt(stm,&calc->src1);
	      src2 = getArgInt(stm,&calc->src2);
  	    switch(calc->optype)
	      {
	      case ADD: 	dest = src1 + src2; break;
	      case MODULO: if(src2==0) dest = 0; else dest = src1 % src2; break;
  	    case SUBT: 	dest = src1 - src2; break;
  	    case MUL: 	dest = src1 * src2; break;
  	    case DIV: 	if(src2==0) dest = 0; else dest = src1 / src2; break;
  			default: break;
  	    }
	      setArgInt(stm,&calc->dest,dest);
      }
      else
      {
        fsrc1 = getArgFloat(stm,&calc->src1);
	      fsrc2 = getArgFloat(stm,&calc->src2);
  	    switch(calc->optype)
	      {
	      case ADD: 	fdest = fsrc1 + fsrc2; break;
	      case MODULO: 
					src1 = getArgInt(stm,&calc->src1);
					src2 = getArgInt(stm,&calc->src2);
					if(src2==0) 
						fdest = 0.0; 
					else
					{ 
						fdest = src1 % src2; 
					}
					break;
  	    case SUBT: 	fdest = fsrc1 - fsrc2; break;
  	    case MUL: 	fdest = fsrc1 * fsrc2; break;
  	    case DIV: 	if(fsrc2==0.0) fdest = 0.0; else fdest = fsrc1 / fsrc2; break;
  			default: break;
  	    }
	      setArgFloat(stm,&calc->dest,fdest);
      }
			ltest=0;
			prgidx++;
			break;
		case SETSTATE :
			stm->next_istate = ((SETSTATESTRUCT*)state->prg[prgidx].data)->number;
			ltest=0;
			prgidx++;
			break;
		case SETFRAME :
	    setframe = (SETFRAMESTRUCT*)state->prg[prgidx].data;
			memcpy(setframe->destFrame,setframe->srcFrame,sizeof(tmpnFrame));
			ltest=0;
			prgidx++;
			break;
		case SETITEM :
			setitem = (SETITEMSTRUCT*)state->prg[prgidx].data;
			*(setitem->destItem)=setitem->srcItem;
			ltest=0;
			prgidx++;
			break;
		case SETPATTERN :
			setpattern = (SETPATTERNSTRUCT*)state->prg[prgidx].data;
			*(setpattern->destPattern)=setpattern->srcPattern;
			ltest=0;
			prgidx++;
			break;
		case SETCPPATTERN :
			setcppattern = (SETCPPATTERNSTRUCT*)state->prg[prgidx].data;
			*(setcppattern->destCPPattern)=setcppattern->srcCPPattern;
			ltest=0;
			prgidx++;
			break;
		case EXEC:
	    exec = (EXECSTRUCT*)state->prg[prgidx].data;
			exec->path->state = ST_EXEC;
			ltest=0;
			prgidx++;
			break;
		case LOAD:
	    load = (LOADSTRUCT*)state->prg[prgidx].data;
			memcpy(&load->path->key.from.frame,load->fromFrame,sizeof(tmpnFrame));
			memcpy(&load->path->key.to.frame,load->toFrame,sizeof(tmpnFrame));
			load->path->state = ST_LOAD;
			ltest=0;
			prgidx++;
			break;
		case ELSE :
			ltest=0;
			prgidx = ((ELSESTRUCT*)state->prg[prgidx].data)->doneIdx;
			break;
		case ENDTEST :
			ltest=0;
			prgidx++;			
			break;
		case PRINT :
			print = (PRINTSTRUCT*)state->prg[prgidx].data;
      if(print->arg.type==TIMEOUT)
			{
        arg1 = getSTMTimer(&stm->timer);
        printf("PRINT TIMEOUT cnt: %s=%d",stm->timeout[print->arg.idx].name,arg1);
        if(print->newline) printf("\n");
			}
		  printArg(stm,&print->arg,print->newline);	
			ltest=0;
			prgidx++;
			break;
/* 		case ADD : */
/* 			arg1 = stm->value[((ADDSTRUCT*)state->prg[prgidx].data)->arg1idx].data; */
/* 			arg2 = stm->value[((ADDSTRUCT*)state->prg[prgidx].data)->arg2idx].data; */
/* 			stm->value[((ADDSTRUCT*)state->prg[prgidx].data)->idx].data = arg1 + arg2; */
/* 			ltest=0; */
/* 			prgidx++; */
/* 			break; */
/* 		case SUBT : */
/* 			arg1 = stm->value[((SUBTSTRUCT*)state->prg[prgidx].data)->arg1idx].data; */
/* 			arg2 = stm->value[((SUBTSTRUCT*)state->prg[prgidx].data)->arg2idx].data; */
/* 			stm->value[((SUBTSTRUCT*)state->prg[prgidx].data)->idx].data = arg1 - arg2; */
/* 			ltest=0; */
/* 			prgidx++; */
/* 			break; */
/* 		case MUL : */
/* 			arg1 = stm->value[((MULSTRUCT*)state->prg[prgidx].data)->arg1idx].data; */
/* 			arg2 = stm->value[((MULSTRUCT*)state->prg[prgidx].data)->arg2idx].data; */
/* 			stm->value[((MULSTRUCT*)state->prg[prgidx].data)->idx].data = arg1 * arg2; */
/* 			ltest=0; */
/* 			prgidx++; */
/* 			break; */
/* 		case DIV : */
/* 			arg1 = stm->value[((DIVSTRUCT*)state->prg[prgidx].data)->arg1idx].data; */
/* 			arg2 = stm->value[((DIVSTRUCT*)state->prg[prgidx].data)->arg2idx].data; */
/* 			if(arg2==0) */
/* 				stm->value[((DIVSTRUCT*)state->prg[prgidx].data)->idx].data = 0; */
/* 			else	 */
/* 				stm->value[((DIVSTRUCT*)state->prg[prgidx].data)->idx].data = arg1 / arg2; */
/* 			ltest=0; */
/* 			prgidx++; */
/* 			break; */
		default:
			printf("type=%d unknown in stm=%s state=%s prg=%d\n",state->prg[prgidx].type,stm->name,state->name,prgidx);
			return -1;
			break;
		}
	}
  
  if(stm->istate==stm->timerstate)
  {
    diff = getSTMTimer(&stm->timer);
    if(diff==1&&stm->new_istate!=-1)
		{
			stm->next_istate = stm->new_istate;
			stm->new_istate=-1;
		}
  }

  pthread_cond_broadcast(&stm->change);
  pthread_mutex_unlock(&stm->change_mtx);
	
  return 0;
}

int stmcycle=0;
int stmcycles=0;
int stmcyclespersec=0;
static volatile int stm_running = TRUE;

int stmStop(void)
{
  int last = stm_running;
	
	stm_running = FALSE;
	return last;
}

int stmStart(void)
{
  int last = stm_running;
	
	stm_running = TRUE;
	return last;
}

void doCW(void);
void setupCW(void);
unsigned long long tdiff;
#define rdtscll(low) asm volatile("rdtsc":"=A"(low))
//TODO create seperate driver for eack type of io
// Open() Read() Write() Close()


void *stm_task(void * argument )
{
  int i,j,statechange;
  clock_t start;
  clock_t stop;
  float diff;
  float maxdif=0.0;
  unsigned long long ttstart;
  unsigned long long ttstop;
  static struct timeval currentTime;
  static struct timeval startTime;
  static int firsttime = 1;
  if(firsttime==1)
  {
    firsttime=0;
    gettimeofday(&startTime, NULL);
  }
  for(i=0;i<tworkcell->statemachines.maxidx;i++)
  {
		setState(i,getStateIdx(i,"ST_IDLE"));
  }

	for (i=0;i<tworkcell->dios.maxidx;i++)
		openAdvantys((tmpnDIO*)&tworkcell->dios.dio[i]);

  start = times(NULL);
  rdtscll(ttstart);
  diff=0.0;  
  //how many clk's in one sec
  while(diff<1.0)
  {
    stop = times(NULL);
    rdtscll(ttstop);
    tdiff=ttstop-ttstart;
    diff=(float)(stop-start)/(float)sysconf(_SC_CLK_TCK);
  }
  //printf("************************ clk %010Ld in %f sec\n",tdiff,diff);
  stmcycles=0;
  start = times(NULL);
	stmUpAndRunning++;
  for(;;) //scan forever
  {     
    rdtscll(ttstart);
		for (i=0;i<tworkcell->dios.maxidx;i++)
			readAdvantys1((tmpnDIO*)&tworkcell->dios.dio[i]);
		for (i=0;i<tworkcell->dios.maxidx;i++)
			readAdvantys2((tmpnDIO*)&tworkcell->dios.dio[i]);
    rdtscll(ttstop);
		if(((float)(ttstop-ttstart)/(float)tdiff)>0.02)
			printf("readAdvantys executed in %010Ld clk %f\n",(ttstop-ttstart),(float)(ttstop-ttstart)/(float)tdiff);
    //TODO filter on input
//*****************************************************
//* execute the current state in each statemachine
//*****************************************************
    rdtscll(ttstart);
    if(stm_running)
    {
			stmcycle++;
			stmcycles++;
			for(i=0;i<tworkcell->statemachines.maxidx;i++)
	  	{
        //printf("parsing %i\n",i);
  			parseStateCmd(i);
	 		}
  		// Update state
	  	for(i=0;i<tworkcell->statemachines.maxidx;i++)
		  {
				tmpnStateMachine *stm = &tworkcell->statemachines.statemachine[i];
        statechange=0; 
        pthread_mutex_lock(&stm->change_mtx);
			  if(stm->next_istate != -1)
			  {
				  stm->istate = stm->next_istate;
				  stm->next_istate = -1;
          statechange=1; 
				  //TODO only signal change if there has been a change (istate != next_istate ?)
				  pthread_cond_broadcast(&stm->change);
			  }
        pthread_mutex_unlock(&stm->change_mtx);
        if(statechange==1)
        {
          if(rs_param.statemachine_debug==2)
				  {
            if(stm->debugvalue==NULL)
						{
              gettimeofday(&currentTime, NULL);
						  printf("%05ld:%03ld ",currentTime.tv_sec-startTime.tv_sec, currentTime.tv_usec/1000);
						  printf("cycle %d STM=%s state=%s\n", stmcycle, stm->name, stm->state[stm->istate].name);
					  }
            else
            {
              if(stm->debugvalue->data==1)
						  {
                gettimeofday(&currentTime, NULL);
						    printf("%05ld:%03ld ",currentTime.tv_sec-startTime.tv_sec, currentTime.tv_usec/1000);
						    printf("cycle %d STM=%s state=%s\n", stmcycle, stm->name, stm->state[stm->istate].name);
					    }
					  }
					}
          //Show all execpt those that have Value=DEBUG defined as <> 1
          if(rs_param.statemachine_debug==1)
				  {
            if(stm->debugvalue!=NULL&&stm->debugvalue->data==1)
						{
              gettimeofday(&currentTime, NULL);
						  printf("%05ld:%03ld ",currentTime.tv_sec-startTime.tv_sec, currentTime.tv_usec/1000);
						  printf("cycle %d STM=%s state=%s\n", stmcycle, stm->name, stm->state[stm->istate].name);
					  }
				  }
				}
			}
		}
		rdtscll(ttstop);
    if((ttstop-ttstart)>maxdif) maxdif=(ttstop-ttstart);
		if(rs_param.io_debug>=2)
      printf("stm executed in %010Ld clk %f max=%f\n"
            ,(ttstop-ttstart)
            ,(float)(ttstop-ttstart)/(float)tdiff
            ,(float)(maxdif/(float)tdiff));
    // Set output
    usleep(800);
    rdtscll(ttstart);
		for (i=0;i<tworkcell->dios.maxidx;i++)
			writeAdvantys1((tmpnDIO*)&tworkcell->dios.dio[i]);
		for (i=0;i<tworkcell->dios.maxidx;i++)
			writeAdvantys2((tmpnDIO*)&tworkcell->dios.dio[i]);
    rdtscll(ttstop);
    usleep(800);
    if(((float)(ttstop-ttstart)/(float)tdiff)>0.02)
      printf("writeAdvantys executed in %010Ld clk %f\n",(ttstop-ttstart),(float)(ttstop-ttstart)/(float)tdiff);
    stop = times(NULL);
    diff=(float)(stop-start)/(float)sysconf(_SC_CLK_TCK);
    if(diff>1.00) 
    {  
			stmcyclespersec=stmcycles;
		  if(rs_param.io_debug)
        printf("************************ advantys scan executed %d scans in %f sec\n",stmcycles,diff);
      start = times(NULL);
      stmcycles=0;
    }
  }
  return NULL;
}

int isRunning(char *WorkCell)
{
  if(testMachineState(WorkCell,"ST_STARTING")
     ||testMachineState(WorkCell,"ST_RESTARTING")
     ||testMachineState(WorkCell,"ST_RUNNING")
     ||testMachineState(WorkCell,"ST_STOPPING")
     ||testMachineState(WorkCell,"ST_PAUSING")
     ||testMachineState(WorkCell,"ST_PAUSED"))
	{
		return TRUE;
	}
  return FALSE;
}

//***************************************************************************
//* getWorkCellStr                                                          *
//***************************************************************************
void getWorkCellStr(char *WorkCell, char *programstr, char *workcellstr)
{
	tmpnLanguage *langptr=(tmpnLanguage*)&tworkcell->languages.language[tworkcell->languages.currentLanguage];
  if(testMachineState(WorkCell,"ST_IDLE"))
	{
		if (programstr != NULL)
			sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 97,"Ready"));
		else
			sprintf(workcellstr,"%s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),getLanguageLineFromIdx(langptr, 98,"Not ready"));
	} 
  else if(testMachineState(WorkCell,"ST_STARTING"))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 128,"Starting"));
	}
	else if(testMachineState(WorkCell,"ST_RESTARTING"))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 129,"Continuing"));
	}
	else if(testMachineState(WorkCell,"ST_RUNNING"))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 130,"Running"));
	}
	else if(testMachineState(WorkCell,"ST_STOPPING"))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 131,"Stopping"));
	}
	else if(testMachineState(WorkCell,"ST_PAUSING"))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 132,"Preparing pause"));
	}
	else if(testMachineState(WorkCell,"ST_PAUSED"))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 133,"Paused"));
	}
	else if(testMachineState(WorkCell,"ST_ERROR"))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 134,"Error"));
	}
	else if(testMachineState(WorkCell,"ST_HALT"))
	{
		sprintf(workcellstr,"%s %s - %s.",getLanguageLineFromIdx(langptr, 1,"Program"),programstr,getLanguageLineFromIdx(langptr, 135,"Halted"));
	}
}
//***************************************************************************
//* getButtonState                                                          *
//***************************************************************************
extern int accesslevel; //mc.c
void getButtonState(char *WorkCell, char *Emergency, int *menuEn, int *runEn, int *stopEn)
{ 
	*menuEn=FALSE;
	*runEn=TRUE;
	*stopEn=TRUE;

  if(!isRunning(WorkCell))
  {
		*menuEn=TRUE;
		*runEn=TRUE;
		*stopEn=FALSE;
  }
	else
  {
		*stopEn = TRUE;
		*runEn=FALSE;
    if(accesslevel>OPERATORLEVEL)
    {
			*menuEn=TRUE;
    }
  }
	if (!testMachineState(Emergency,"ST_POWERON"))
	{
		*menuEn=TRUE;
		*stopEn=FALSE;
		*runEn=FALSE;
	}
	else
	{
		if(testMachineState(WorkCell,"ST_HALT")
			 ||testMachineState(WorkCell,"ST_IDLE")
			 ||testMachineState(WorkCell,"ST_PAUSED"))
		{
			*menuEn=TRUE;
			*runEn=TRUE;
			*stopEn=FALSE;
		}
		else
		{
			*runEn=FALSE;
			if(accesslevel>OPERATORLEVEL)
				*menuEn=TRUE;
			else   
				*menuEn=FALSE;
		}
		if(testMachineState(WorkCell,"ST_RUNNING"))
			*stopEn=TRUE;
		else
			*stopEn=FALSE;
	}
	if(testMachineState(WorkCell,"ST_ERROR"))
	{
		*stopEn=FALSE;
		*runEn=FALSE;
	}
}


void signalContinue(void)
{
	// old method
	// setMachineState("ContinueKnap","ST_HIGH");
	
	//new
	*getMachineValuePtr(getMachineIdx("ContinueKnap"),"knap")=1;
}
