#include "manual.h"

BOXSTRUCT *b = NULL;
int busy = 0;
int busyidx = -1;
int busyCmd = -1;
tmpnConnect *busyconnect = NULL;

BX_BOOL manual_setOutput(const char *stmname, const char *outputname, const int value)
{
  int i,idx;
  if(busyidx == -1)
  {
    idx = getMachineIdx(stmname);
    if(idx == -1)
      return FALSE;
    if(!testState(idx,getStateIdx(idx, "ST_IDLE")) &&
       !testState(idx,getStateIdx(idx, "ST_HALT")))
      return FALSE;
    int stateidx=getStateIdx(idx,"ST_HALT");
    if (stateidx>=0)
      setState(idx, stateidx);
    else
      return FALSE;
    busyidx=idx;
  }
  tmpnStateMachine *stm = &tworkcell->statemachines.statemachine[busyidx];
  for(i=0;i<stm->numoutput;i++)
  {
    if (stm->output[i].iotype==OUTPUT)
    {
      if(strcmp(stm->output[i].name, outputname)==0)
      {
        busyconnect=stm->output[i].connect;
        setConnectValueInt(busyconnect,value);
        printf("%s: %s %d\n",stmname,outputname,value);
        busy=1;
        busyCmd=-1;
        return TRUE;
      }
    }
  }
  busyidx=-1;
  return FALSE;
}

BX_BOOL manual_togleOutput(const char *stmname, const char *outputname)
{
  int i, idx = getMachineIdx(stmname);
  if(idx == -1)
    return FALSE;
  if(!testState(idx,getStateIdx(idx, "ST_IDLE")) &&
     !testState(idx,getStateIdx(idx, "ST_HALT")))
    return FALSE;
  int stateidx=getStateIdx(idx,"ST_HALT");
  if (stateidx>=0)
    setState(idx, stateidx);
  else
    return FALSE;

  tmpnStateMachine *stm = &tworkcell->statemachines.statemachine[idx];
  for(i=0;i<stm->numoutput;i++)
  {
    if (stm->output[i].iotype==OUTPUT)
    {
      if(strcmp(stm->output[i].name, outputname)==0)
      {
        tmpnConnect *connect=stm->output[i].connect;
        int now=0;
        if((now=getConnectValueInt(connect)))
          setConnectValueInt(connect,0);
        else
          setConnectValueInt(connect,1);
        printf("%s: %s %d\n",stmname,outputname,now);
        return TRUE;
      }
    }
  }
  return FALSE;
}
BX_BOOL manual_resetOutput(const int value)
{
  if(busy==1 && busyidx != -1 && busyconnect != NULL){
    busy=0;
    setConnectValueInt(busyconnect,value);
    busyidx=-1;
    busyconnect=NULL;
    printf("and now %d\n",value);
    return TRUE;
  }
  return FALSE;
}

BX_BOOL manual_activityCheck(HBOX hBox, const int cmdButton)
{
  //BA_CLICKACTIVE comes on mousedown and click function on mouseup
  b = BxGetDlgItem(hBox, cmdButton);
  if((b->boxState & BBS_STATEMASK) == BA_CLICKACTIVE)
  {
    return TRUE;
  }
  return FALSE;
}

BX_BOOL manual_idle(const char* stmname)
{
  int idx = getMachineIdx(stmname);
  int stateidx=getStateIdx(idx,"ST_IDLE");
  if (stateidx>=0 && testState(idx,getStateIdx(idx, "ST_HALT")))
    setState(idx, stateidx);
  return TRUE;
}
