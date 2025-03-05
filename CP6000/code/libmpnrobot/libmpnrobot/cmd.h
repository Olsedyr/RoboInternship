/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include <pthread.h>
#include "tmpnrobot.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifdef __cplusplus
extern "C" tmpnRSSystem rs_param;
extern "C" char rs_systempath[256];
extern "C" char rs_systemini[256];
extern "C" long defpathspeed;
extern "C" int defpathsamprate;
extern "C" TABLESPACE tspace;
extern "C" volatile int roboState;
//extern "C" volatile int roboError;
extern "C" float speedFactor;
extern "C" volatile int ctrlNumOfUploads[MAXLOADGROUP];
extern "C" volatile int jumpToLayer;
extern "C" volatile int scriptLoaded;
extern "C" pthread_cond_t script_cond;
extern "C" pthread_mutex_t script_mutex;
extern "C" pthread_cond_t upload_cond;
extern "C" pthread_mutex_t upload_mtx;
extern "C" pthread_cond_t uploaddone_cond;
extern "C" pthread_mutex_t uploaddone_mtx;
#else
extern tmpnRSSystem rs_param;
extern char rs_systempath[256];
extern char rs_systemini[256];
extern char cmdstr[][255];
extern long defpathspeed;
extern int defpathsamprate;
extern TABLESPACE tspace;
extern volatile int roboState;
//extern volatile int roboError;
extern float speedFactor;
extern volatile int ctrlNumOfUploads[MAXLOADGROUP];
extern volatile int jumpToLayer;
extern volatile int scriptLoaded;
extern pthread_cond_t script_cond;
extern pthread_mutex_t script_mutex;
extern pthread_cond_t upload_cond;
extern pthread_mutex_t upload_mtx;
extern pthread_cond_t uploaddone_cond;
extern pthread_mutex_t uploaddone_mtx;

#endif


#ifdef __cplusplus
extern "C" {
#endif
extern int jointToTask(const char *filename);
extern int tmpnScopeLoad(const char *filename, tmpnPath *path);

extern int SaveCommandScript(COMMANDSTRUCT *root, const char *filename);
extern COMMANDSTRUCT *LoadCommandScript(const char *filename, int flag);
extern int AddProgram(int PrgStmIdx, char *newName, int copyfromidx);
extern int SaveProgramVal(int PrgStmIdx, STMCOMMANDSTRUCT *stmcmd, char *prgname);
extern int SaveTimeVal(const char *stmname, const char *timename,int val);
extern int SaveConstVal(const char *stmname, const char *constname,tmpnStateMachineValue* val);
extern int SaveItemVal(const char *stmname, const char *name, const char *itemName);
extern int SaveCPPatternVal(const char *stmname, const char *name, const char *cppName);
extern int SaveFrameVal(const char *stmname, tmpnFrame *newfr);
extern int SaveMacInitVal(tmpnMac* mac, int modidx, int initidx);
extern int tmpnRobotLoad(const char *filename, tmpnRobot *robot);
extern int tmpnRobotSave(const char *filename, tmpnRobot *robot);
extern void selectRobot(int i);

extern int tmpnPatternLoad(const char *filename, tmpnPattern *pattern);
extern int tmpnPatternSave(tmpnPattern *pattern);
extern tmpnPattern *getPattern(const char *name, tmpnWorkcell *workcell);
extern void getPatternString(char *s, int i, tmpnPattern *pattern);

extern int tmpnCPPatternLoad(const char *filename, tmpnCPPatterns *cppatterns);
extern int tmpnCPPatternSave(tmpnCPPattern *cppattern);
extern tmpnCPPattern *getCPPattern(const char *name, tmpnWorkcell *workcell);

extern tmpnPPScript *getPPScript(const char *name, tmpnWorkcell *workcell);

extern int tmpnBoptCoeffLoad(const char *filename, tmpnBoptCoeff *boptcoeff);
extern int tmpnBoptCoeffSave(tmpnBoptCoeff *boptcoeff);

extern tmpnBoptCoeff *getBoptCoeff(tmpnWorkcell *workcell);
extern tmpnBoptCoeffItem *getBoptCoeffItem(tmpnBoptCoeff *boptcoeff, int mode, int pathtype);

extern char *getLanguageLineFromIdx(tmpnLanguage *lang, int idx, char *defaultstring);
extern char *getLanguageLineFromKey(tmpnLanguage *lang, int key, char *defaultstring);
extern char *getLanguageLineFromEnglish(tmpnLanguage *lang, char *englishline, char *defaultstring);
extern int selectLanguage(tmpnLanguages *langs, char *languagename);
extern int tmpnItemLoad(const char *filename, tmpnItem *item);
extern int tmpnItemSave(tmpnItem *item);
extern tmpnItem *getItem(const char *name, tmpnWorkcell *workcell);

extern int tmpnToolLoad(const char *filename, tmpnTool *tool);
extern tmpnTool *getTool(const char *name, tmpnWorkcell *workcell);

extern int tmpnWorkcellLoad(const char *filename, tmpnWorkcell *workcell);
extern int tmpnWorkcellSave(const char *filename, tmpnWorkcell *workcell);
extern void selectWorkcell(int i);

extern int tmpnPlantLoad(const char *filename, tmpnPlant *plant);
extern int tmpnPlantSave(const char *filename, tmpnPlant *plant);

extern int tmpnStateMachineLoad(const char *filename, tmpnStateMachine *statemachine, int level);
extern int tmpnStateLoad(const char *filename, tmpnStateMachine *statemachine, int level);
extern void SetupSTMLink1(tmpnStateMachine *stm);
extern void SetupSTMLink2(tmpnStateMachine *stm);
extern int getArgInt(tmpnStateMachine * stm, ARGSTRUCT *arg);
extern void setArgInt(tmpnStateMachine * stm, ARGSTRUCT *arg, int value);
extern void printArg(tmpnStateMachine * stm, ARGSTRUCT *arg, int newline);

extern void copyAxisToRobotFile(tmpnRobot *robot);
extern void copyAxisToTableSpace(tmpnRobot *robot);

extern int LoadCalibrationParam(tmpnRSSystem *ini);
extern int SaveCalibrationParam(tmpnRSSystem *ini);
extern int LoadRSSystemData(tmpnRSSystem *ini);
extern int SaveRSSystemData(tmpnRSSystem *ini);

extern char *getMachineTypeName(int num);
extern int getMachineIdx(const char *machinename);
extern int getMachineStateIdx(const char *machinename, const char *statename);
extern int getStateIdx(int machine, const char *statename);
extern void deleteSTMPrg(tmpnStateMachine *statemachine);
extern void setStateTekst(char *tekst, int state, int line);
extern const char *tmpnGetDatabase(void);
extern void tmpnSetDatabase(const char *database);
extern int getRemoteStatemachineIdx(tmpnWorkcell *workcell,char *str);
extern int getRemoteValueIdx(tmpnWorkcell *workcell,char *str1,char *str2);
extern int getTCPidx(char *name, tmpnRobot *trobot);
extern int getFrameIdx(const char *name, tmpnRobot *robot);
extern int getRobotIdx(const char *name, tmpnWorkcell *workcell);
extern int getWorkcellIdx(const char *name, tmpnPlant *plant);

extern tmpnFloat getTimingValue(const char *name, tmpnRobot *robot);
extern int connectSimulated(tmpnConnect *connect);

extern void getCommandString(char *t, COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *addCommandString(COMMANDSTRUCT *ptrcmd, const char *t, int* level);
extern void deleteCommand(COMMANDSTRUCT *cmd);
extern void refreshPoint(COMMANDSTRUCT *cmd);
extern void adjPoint(COMMANDSTRUCT *cmd
        ,tmpnFloat wx, tmpnFloat wy, tmpnFloat wz, tmpnFloat wv, tmpnFloat ww, tmpnFloat wu, tmpnFloat wt, int tcpidx);

extern void refreshPath(COMMANDSTRUCT *cmd);
extern void adjPath(PATHSTRUCT *path);
extern void updatecmdPoints(COMMANDSTRUCT *cmd);
extern char *getProgramName(char *stmname);


extern tmpnStateMachineValue *getMachineValue(int machine, char *valuename);
extern int getMachineVersion(int machine);
extern tmpnFrame *getStmFrame(char *framename);
extern int *getMachineValuePtr(int machine, char *valuename);
extern unsigned short *getMachineInputPtr(int machine, char *inputname);

tmpnConnect *getConnectPtr(stbstruct *stb,char *name);
unsigned short getConnectValue(tmpnConnect *connect);
int getConnectValueInt(tmpnConnect *connect);
short getConnectValueSigned(tmpnConnect *connect);
void setConnectValue(tmpnConnect *connect, unsigned short value);
void setConnectValueInt(tmpnConnect *connect, int value);
void setConnectValueSigned(tmpnConnect *connect, short value);
macConnect *getMacConnectPtr(tmpnStateMachine *stm, char *name);

extern float getArgFloat(tmpnStateMachine * stm, ARGSTRUCT *arg);
extern void setArgFloat(tmpnStateMachine * stm, ARGSTRUCT *arg, float value);

//RunCommand list
extern void selectRunCommand(COMMANDSTRUCT *runcmd);
extern COMMANDSTRUCT *getRunCommand(void);
extern COMMANDSTRUCT *getNextRunCommand(COMMANDSTRUCT *pcmd);
extern COMMANDSTRUCT *getNextRunCommandAtSameLevel(COMMANDSTRUCT *pcmd);
extern COMMANDSTRUCT *getPrevRunCommand(COMMANDSTRUCT *pcmd);
extern COMMANDSTRUCT *getFirstRunCommand(COMMANDSTRUCT *root);
extern COMMANDSTRUCT *getFirstCommand(   COMMANDSTRUCT *root);
extern COMMANDSTRUCT *getLastRunCommand( COMMANDSTRUCT *root);
extern COMMANDSTRUCT *AddCommand(int type);
extern COMMANDSTRUCT *InsertCommand(COMMANDSTRUCT *ptrcmd, int type);
extern POINTSTRUCT *getPoint(COMMANDSTRUCT *pcmd, int off);
extern COMMANDSTRUCT *getPrevPPScriptCommand(COMMANDSTRUCT *pcmd);

extern int GetActualNumber(void);
extern int FindNextCommand(void);
extern int FindPrevCommand(void);
extern int FindFirstCommand(void);
extern int FindLastCommand(void);
extern int GetCurrentCommandType(void);
extern COMMANDSTRUCT *GetCommandNumber(int idx);
extern COMMANDSTRUCT *selectCommand(COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *getParentCommand(COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *getPreviusCommand(COMMANDSTRUCT *cmd);
extern COUNTERSTRUCT *getCounter(char *name);
extern COUNTERSTRUCT *initCounter(char *name, char *value);
extern COUNTERSTRUCT *incCounter(char *name, char *value);
extern COUNTERSTRUCT *decCounter(char *name, char *value);
extern COUNTERSTRUCT *mulCounter(char *name, char *value);
extern COUNTERSTRUCT *divCounter(char *name, char *value);
extern char *getCounterValue(char* value);
extern COMMANDSTRUCT *FindNextCmdToUpload(COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *findNextToPreload(COMMANDSTRUCT *cmd);
extern COMMANDSTRUCT *FindLayerCmd(COMMANDSTRUCT *pcmd, int layer);

extern COMMANDSTRUCT *expandPath(COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);

extern void RemoveAllCommands(COMMANDSTRUCT **root);
extern void ResetCmdLoadBuffer(COMMANDSTRUCT *root, int loadgroup);
extern COMMANDSTRUCT *FindFirstCmdToUpload(COMMANDSTRUCT *root);
extern int countPreload(COMMANDSTRUCT *root, int loadgroup);
extern COMMANDSTRUCT *getLabelCommand(COMMANDSTRUCT *root, const char *label);
extern COMMANDSTRUCT *findFirstPreloaded(  COMMANDSTRUCT *root, int loadgroup);
extern COMMANDSTRUCT *findFirstPathInGroup(COMMANDSTRUCT *root, int loadgroup);
extern COMMANDSTRUCT *findItemPathInGroup( COMMANDSTRUCT *root, int loadgroup);
extern int libRunCounter(COMMANDSTRUCT *cmd, COMMANDSTRUCT **pcmd);

extern char *getStateString(int idx);
int saveScopeSample(char *file, char *s);
extern int getCmpType(tmpnStateMachine *stm, char *s, int ln);
extern void getArgBody(tmpnStateMachine * stm, ARGSTRUCT *data, char arg[]);
extern float getArgValueFloat(tmpnStateMachineValue *val, char *val2, int *argSubType);
extern int getArgValueInt(tmpnStateMachineValue *val, char *val2, int *argSubType);
extern void setArgValueFloat(tmpnStateMachineValue *val, char *val2, float v);
extern void setArgValueInt(tmpnStateMachineValue *val, char *val2, int v);
extern int getArgSubType(tmpnStateMachine * stm, ARGSTRUCT *arg);
extern int findTopInTable(tmpnStateMachineValue *value);
extern void copyFramesFromSTMtoRobot(void);
#ifdef __cplusplus
}
#endif
