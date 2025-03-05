extern int isRunning(void);
extern void setMachineState(const char *machinename, const char *statename);
extern int testMachineState(const char *machinename, const char *statename);
extern int getStateMachineError(void);
extern int getStateMachineMessage(void);
