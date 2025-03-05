
typedef struct tmpnStateMachineStateTransition
{
  char name[256];
} tmpnStateMachineStateTransition;

typedef struct tmpnStateMachineState
{
  char name[256];
  int statenum;
  int numtransition;
  tmpnStateMachineStateTransition transition[10];
} tmpnStateMachineState;

typedef struct tmpnStateMachine
{
  int version;
  int type;
  char filename[256];
  char name[256];
  int numstate;
  tmpnStateMachineState state[50];
} tmpnStateMachine;

