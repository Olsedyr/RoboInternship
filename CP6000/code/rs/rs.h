/***************************************************************************
                          rs.h  -  description
                             -------------------
    begin                : Wed Aug 6 2003
    copyright            : (C) 2003 by MPN A/S - Guided by vision(R) Lars M Sandig
    email                : lms@mpn.nu
 ***************************************************************************/
// robostacker header file
#include "cmd.h"

void mpnexit(int returnval);

typedef struct visionstructure
{
  int fps;
  int connected;
  char camip[25];
  int minimum;
  int minlen;
  int minwidth;
  int length;
  int width;
  int height;
  float angle;
} visionstructure;

extern int accesslevel;
extern char userid[256];
extern char password[256];


extern char *GetRSVersion(void);
extern char *GetRSType(void);
extern void PrintError(long rc);

extern void *boxMain(void *t);
extern void *one_second_interval(void * argument );
extern void *x11event_task(void *t);
extern void *dfdevent_task(void *t);
extern void *sdlevent_task(void *t);
extern void *EloTask(void *arg);
extern void *KbdTask(void *arg);
extern void *EGalaxTask(void *arg);
extern void *mc_task(void * argument );
extern void *dioc_task(void * argument );
extern void *upload_task(void * argument );
extern void *visionTask(void *argument);
extern void *conveyorTask(void *argument);
extern unsigned long SetUpdateFreq(unsigned long updfq);
extern int IsWDOGOn(void);
extern int roboCheckForException(void* hBox);

extern int MoveAllAbs(float a, float b, float c, float d, float e);
extern int MoveAbs(int axis, float pos);
extern int Move(int axis, float pos);
extern int MoveModify(int axis, float pos);
extern int CancelMotion(int axis);
extern float GetMType(int axis);
extern float GetMPos(int axis);
//extern float GetDPos(int axis);
extern float GetVersion(void);
extern float GetEndMove(int axis);
extern float GetVR(int number);


void InitializeRobostacker(void);
extern int GuidedByVision(int state);

extern float autoHomeSensor(void);
extern float moveToHomeSensor(int axis);
extern int GetAxisParamValues(int axis, int table);
extern int SetAxisParamValues(int axis, int table);
extern void SetKasseLiftValues(float enable, float speed, float accel, float decel, float setpoint);
extern volatile visionstructure vicam;
extern int LoadVisionParam(void);
extern int SaveVisionParam(void);

extern int GetRunningState(void);

extern int GetBasicError(void);
extern int GetBasicLineError(void);
extern int GetErrorAxis(void);

extern int GoRobot(int run);
extern int continueRobot(void);
extern int testContinue(void);
extern int RobotState(void);
extern int RobotState(void);
extern int CancelMc(int v);
extern int SetOutput(int port, int state);
extern int emergency(void);
extern int GetInput(void);
extern float GetAktuelSpeed(int axis);
extern float GetAktuelAccel(int axis);
extern float GetAktuelDecel(int axis);
extern float GetAktuelSramp(int axis);
extern int SetSpeed(int axis, float val);
extern int SetAccel(int axis, float val);
extern int SetDecel(int axis, float val);

extern int SetSram(int axis, float val);
extern void ParseCmd(volatile COMMANDSTRUCT **pcmd);
extern float SetSpeedFactor(float ns);
extern float GetSpeedFactor(void);
extern int SetDefPos(void);
extern int CmdStartup(void);
extern int GetReply(void);
extern int GetCtrlReply(void);
extern int SetUnitsAndDefaults(void);
extern int ResetAxis(void);
extern int SetHomeAll(void);
extern float GetRetur(void);
extern float GetCtrlRetur(void);
extern int SetTraficLight(int state);
extern int RoboError(void);

extern int LoadPathFile(char* filename);
extern int SavePathFile(char* filename);

extern void CreatePathPoints(tmpnPathDef *pathdef);
extern void CreateRunScript(void);

extern int FindTouchCtrl(void);
extern float GetVR(int number);
extern float SetVR(int number, float val);

extern int logMsg(char *s);
extern int logStatus(char *s);

