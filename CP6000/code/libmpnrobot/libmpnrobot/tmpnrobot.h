/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#if !defined(TMPNROBOT_H)
#define TMPNROBOT_H


#include <sys/time.h>
#include <sys/times.h>
#include <pthread.h>

#define MAXCOUNTERS     100
#define MAXSCRIPTNAMES  10
#define MAXTCP          3
#define MAXSTATE        3
#define MAXKEYPOINTS    500
#define MAXHPOINTS      20
#define MAXPOSHINT      20
#define MAXPOSITIONS    5000
#define MAXPATHTABLEITEMS 500
#define MAXSTMPATHS     50
#define MAXFRAMENAMES   30
#define MAXTUNING       50
#define MAXLINK         5
#define MAXMACRONAMES   18
#define MAXWORKCELLS    2
#define MAXROBOTS       1
#define MAXTOOLS        3
#define MAXITEMS        10
#define MAXACCESSORIES  10
#define MAXPATTERNS     12
#define MAXSTATEMACHINELINES 5000
#define MAXPPSCRIPTS    10
#define MAXPATTERNITEMS 200
#define MAXPPCRIPTITEMS 200
#define MAXBOPTCOEFFITEMS 40
#define MAXAXIS         7
#define MAXSCOPE        1000
#define MAXSTATETEKST   1000
#define MAXSTATETEKSTS  6
#define MAXLANGLINES   1000
#define MAXLANGUAGES    6
#define MAXROBOTAXIS    6
#define MAXDIO          5
#define MAXCOMSKS       5
#define COMSK_MAXINITS  40
#define COMSK_MAXVALS   10
#define MAXMACS         4
#define MAC_MAXINITS    50
#define MAC_MAXINVALS   100
#define MAC_MAXOUTVALS  50
#define MAXCONNECT      30
#define MAXICPCONNECT   16
#define MAXREMOTESTM    100
#define MAXREMOTEVALUES 100
#define MAXREMOTEHOSTS  5
#define MAXLOADCELLS    3
#define MAXICPCONS      5
#define MAXUDPAGENTS    10
#define MAXLINKVALUE_DEPTH 100

//MPN COMMAND TYPES
#define SADS         1
#define MOVEABS      2
#define WAITEVENT    3
#define PATH         4
#define SIGNALEVENT  5
#define CANCELAXIS   6
#define WSP          7
#define OUT          8
#define IN           9
#define POINT        10
#define STARTSUB     11
#define ENDSUB       12 //only in load and store to define level/flag
#define CALL         13
#define RPOINT       14
#define STOP         15
#define LABEL        16
#define JUMPLAYER    17
#define MOVEAXIS     18
#define MACRO        19
#define PPSCRIPT     20 
#define GOTO         21
#define EPOINT       22
#define STATEHINT    23
#define SCOPE        24
#define SPLINEHINT   25
#define POSITIONHINT 26
#define HPOINT       27
#define HRPOINT      28
#define COUNTER      29
#define TUNING       30
#define TESTEVENT    31
#define SLEEP        32
#define SET	         33
#define SETSTATE     34
#define TIMEOUT      35
#define ADD          36
#define SUBT         37
#define ROOT         38
#define ELSE         39
#define END          40
#define TEST	       41
#define ELSETEST     42
#define OR           43
#define AND          44
#define ENDTEST      45
#define RESETPRELOAD 46
#define ERROR        47
#define SETSPEED     48
#define MUL          49
#define DIV          50 
#define CALC         51 
#define MODULO       52 
#define PRINT        53
#define LOAD         54
#define EXEC         55
#define SETFRAME     56
#define SETITEM      57
#define SETPATTERN   58
#define ROBOTSPEED   59
#define SETCPPATTERN 60

/*************************************************************/
/* Defines for input and output                              */
/*************************************************************/
#define NODATA	      0
#define LEGACYDATA    1 //bit
#define IBITDATA	    2 //bit input
#define OBITDATA	    3 //bit output
#define IWORDDATA     4 //word input
#define OWORDDATA     5 //word output
#define ISHORTDATA    6
#define OSHORTDATA    7
#define OUTCOMSK      8 //for comsk
#define INCOMSK       9 //for comsk
#define INICPCON      10 //for icpcon
#define OUTICPCON     11 //for icpcon
#define INLC          12 //for LoadCell
#define OUTMAC        13 //for Mac motor
#define INMAC         14 //for Mac motor
#define OUTPUT	      15
#define INPUT         16
// defines for statemachines
#define CONSTANT      17
#define VALUE         18
#define LINK          19
#define NUMBER        20
#define LINKVALUE     21
#define TABLE         22
#define FNUMBER       23
#define PATHHANDLE    24
#define FRAME         25
#define ITEM          26
#define PATTERN       27
#define CPPATTERN     28


// defines for statemachines
#define EQUAL         1
#define NOT_EQUAL     2
#define MORE          3
#define MORE_EQUAL    4
#define LESS          5
#define LESS_EQUAL    6

#define SCOPESTART    1
#define SCOPESTOP     2
#define SCOPESAVE     3

//MACRO's
//mpncommand 100 - 99999 reserved for macros
#define MPNCOMMAND_MACRO_OFFSET 100
#define TESTPALLET    (1+MPNCOMMAND_MACRO_OFFSET)
#define GETPALLET     (5+MPNCOMMAND_MACRO_OFFSET)
#define SAVENEXTPATH  (6+MPNCOMMAND_MACRO_OFFSET)
#define RUNSAVEDPATH  (7+MPNCOMMAND_MACRO_OFFSET)
#define SETIO         (13+MPNCOMMAND_MACRO_OFFSET)
#define GETIO         (14+MPNCOMMAND_MACRO_OFFSET)
#define CLEARSAVEDPATH (17+MPNCOMMAND_MACRO_OFFSET)

enum tcpName{caseGripper
            ,bagGripper
            ,zeroGripper};

#define ROBOTVERSION         3
#define ITEMVERSION          4
#define TOOLVERSION          2
#define PATTERNVERSION       2
#define CPPATTERNVERSION     1
#define PPSCRIPTVERSION      2
#define DIOVERSION           1
#define COMSKVERSION         1
#define LOADCELLVERSION      1
#define MACVERSION           1
#define ICPCONVERSION        1
#define WORKCELLVERSION      2
#define PLANTVERSION         1
#define SCRIPTVERSION        2
#define JOINTSCRIPTVERSION   1
#define ACCESSORYVERSION     1
#define STATETEKSTVERSION    1
#define STATEMACHINEVERSION  3
#define BOPTCOEFFVERSION     1
#define LANGUAGEVERSION      1
#define UDPSERVERVERSION     1
#define UDPCLIENTVERSION     1

#define TANSCALE         20.00

#define tmpnDouble double
#define tmpnFloat float
#define splineFloat float
#ifndef PI
#define PI 3.1415926535898
//  #define PI 3.14159265358979323846
#endif


//DEFINE GEOMETRY FOR RS2050
//the following has to be fullfilled for correct display of robot geometry and trajectories
//m_localTrans.y=FOOT_HEIGHT+GANTRY_HEIGHT+m_shoulderGearB+m_legHeight
//CONSTANT
#define FOOT_HEIGHT        0.0
#define FOOT_LENGTH      400.0
#define LEG_LENGTH       400.0
#define EMERGENCY_LENGTH 200.0
#define GANTRY_WIDTH     400.0
#define GANTRY_HEIGHT    302.0
#define SHOULDER_WIDTH   400.0
#define SHOULDER_HEIGHT  650.0
#define SHOULDER_LENGTH  400.0
#define GEAR_SIZE          0.0
#define UARM_SIZE        120.0
#define LARM_SIZE        100.0
#define WRIST_SIZE       110.0

//DEFINE GEOMETRY FOR RS1050
//the following has to be fullfilled for correct display of robot geometry and trajectories
//m_localTrans.y=FOOT_HEIGHT+GANTRY_HEIGHT+m_shoulderGearB+m_legHeight
//CONSTANT
#define FOOT_HEIGHT1        0.0
#define FOOT_LENGTH1      100.0
#define LEG_LENGTH1       100.0
#define EMERGENCY_LENGTH1 200.0
#define GANTRY_WIDTH1     100.0
#define GANTRY_HEIGHT1    302.0
#define SHOULDER_WIDTH1   200.0
#define SHOULDER_HEIGHT1  250.0
#define SHOULDER_LENGTH1  280.0
#define GEAR_SIZE1          0.0
#define UARM_SIZE1         90.0
#define LARM_SIZE1         80.0
#define WRIST_SIZE1       110.0

#define BONE_BOX 1
#define BONE_CYL 2
#define BONE_TOOL 3
#define BONE_TCP 4


#ifndef TRUE
#define TRUE  1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define RADTODEG(a) ((a)*(tmpnFloat)180.0/(tmpnFloat)PI)
#define DEGTORAD(a) ((a)*(tmpnFloat)PI/(tmpnFloat)180.0)
#define MMTOM(a) ((a)*(tmpnFloat)0.001)
#define MTOMM(a) ((a)*(tmpnFloat)1000.0)
#define ROUND2(a) (a)>=0.0?((tmpnFloat)((int)((a)*(tmpnFloat)100.0 + (tmpnFloat)0.5001 ))*(tmpnFloat)0.01):((tmpnFloat)((int)((a)*100.0 - 0.5001 ))*0.01)
#define ROUND3(a) (a)>=0.0?((tmpnFloat)((int)((a)*(tmpnFloat)1000.0 + (tmpnFloat)0.5001 ))*(tmpnFloat)0.001):((tmpnFloat)((int)((a)*1000.0 - 0.5001 ))*0.001)
#define ROUND4(a) (a)>=0.0?((tmpnFloat)((int)((a)*(tmpnFloat)10000.0 + (tmpnFloat)0.5001 ))*(tmpnFloat)0.0001):((tmpnFloat)((int)((a)*10000.0 - 0.5001 ))*0.0001)
#define ROUND5(a) (a)>=0.0?((tmpnFloat)((int)((a)*(tmpnFloat)100000.0 + (tmpnFloat)0.5001 ))*(tmpnFloat)0.00001):((tmpnFloat)((int)((a)*100000.0 - 0.5001 ))*0.00001)

#define IROUND4(a) (a)>=0.0?((tmpnFloat)((int)((a)*(tmpnFloat)10000.0 + (tmpnFloat)0.501 ))*(tmpnFloat)0.0001):((tmpnFloat)((int)((a)*10000.0 - 0.501 ))*0.0001)

#ifndef MAX
#define MAX(a,b) ((a)>=(b)?(a):(b))
#endif
#ifndef MIN
#define MIN(a,b) ((a)>=(b)?(b):(a))
#endif

/* different states of outermost link */
#define iNoTool             0
#define iTool_1             1
#define iTool_1_kasse_20Kg  2

/////////////////



#define axis_t 0
#define axis_a 1
#define axis_b 2
#define axis_c 3
#define axis_d 4
#define axis_e 5
#define axis_f 6
#define axis_vt 10

#define scope_command_nothing	              	1
#define scope_command_init                    2
#define scope_command_wait                    3
#define scope_command_execute                 4
#define scope_command_stop                    5
#define scope_command_savenext                6
#define scope_command_nextsaved               7
#define scope_command_copydone                8

#define mpn_command_startup                   2
#define mpn_command_set_units_and_defaults    3
#define mpn_command_set_defpos                4
#define mpn_command_resetaxis                 5
#define mpn_command_movehome                  6
#define mpn_command_run_path                  7
#define mpn_command_set_mpn_home_all          8
#define mpn_command_set_mpn_auto_home         9
#define mpn_command_moveaxis                  10
#define mpn_command_cancelaxis                11
#define mpn_command_get_in                    12
#define mpn_command_set_out                   13

#define ctrl_command_watch_dog                2
//#define ctrl_command_get_op                   3
//#define ctrl_command_set_op                   4
#define ctrl_command_set_outport              5
#define ctrl_command_get_in                   6
#define ctrl_command_get_erroraxis            7
#define ctrl_command_moveallabs               8
#define ctrl_command_move                     9
#define ctrl_command_moveabs                  10
#define ctrl_command_movemodify               11
#define ctrl_command_get_version              12
#define ctrl_command_get_endmove              13
#define ctrl_command_axisvalues               14
#define ctrl_command_set_speedfactor          15
#define ctrl_command_get_speedfactor          16
#define ctrl_command_get_vr                   17
#define ctrl_command_set_vr                   18
#define ctrl_command_continue                 19

//#define FIRST_PATH_INDEX MAX_PATH_INDEX + NUM_OF_PATH_INDEX
#define NUMBER_OF_AXIS    7 //axis a,b,c,d,e,f,vt

#define AXIS_PARAM_SIZE         29
#define AXIS_PARAM_SIZE_BYTE    29*4

#define STATEMACHINES_SIZE      50

#define MTYPE_INDEX             22
#define MPOS_INDEX              24
#define DPOS_INDEX              25


#define SCOPE_NUMBER_OF_ARGS       20
#define CONTROLLER_NUMBER_OF_ARGS  10
#define MPN_NUMBER_OF_ARGS         10

#define MPN_CMD_SIZE            (MPN_NUMBER_OF_ARGS+2)
#define SCOPE_CMD_SIZE          (SCOPE_NUMBER_OF_ARGS+2)
#define CONTROLLER_CMD_SIZE     (CONTROLLER_NUMBER_OF_ARGS+2)

#define SCOPE_BUFFER_SIZE       20
#define SCOPE_BUFFER_SIZE_BYTE  20*4



//TABLE usages in TRIO
#define AXIS_T_PARAM_IDX        0
#define AXIS_A_PARAM_IDX        AXIS_T_PARAM_IDX + AXIS_PARAM_SIZE
#define AXIS_B_PARAM_IDX        AXIS_A_PARAM_IDX + AXIS_PARAM_SIZE
#define AXIS_C_PARAM_IDX        AXIS_B_PARAM_IDX + AXIS_PARAM_SIZE
#define AXIS_D_PARAM_IDX        AXIS_C_PARAM_IDX + AXIS_PARAM_SIZE
#define AXIS_E_PARAM_IDX        AXIS_D_PARAM_IDX + AXIS_PARAM_SIZE
#define AXIS_F_PARAM_IDX        AXIS_E_PARAM_IDX + AXIS_PARAM_SIZE

#define SCOPE_CMD_RTN_IDX       AXIS_F_PARAM_IDX + AXIS_PARAM_SIZE
#define SCOPE_CMD_ARG_IDX       (SCOPE_CMD_RTN_IDX + 1)
#define SCOPE_CMD_IDX           SCOPE_CMD_ARG_IDX + SCOPE_NUMBER_OF_ARGS

#define SCOPE_TYPE              (SCOPE_CMD_IDX + 1)
#define SCOPE_LENGTH            (SCOPE_TYPE + 1)
#define SCOPE_NUMOFSAMPLES      (SCOPE_LENGTH + 1)
#define SCOPE_ASCALE            (SCOPE_NUMOFSAMPLES + 1)
#define SCOPE_BSCALE            (SCOPE_ASCALE + 1)
#define SCOPE_CSCALE            (SCOPE_BSCALE + 1)
#define SCOPE_DSCALE            (SCOPE_CSCALE + 1)
#define SCOPE_ESCALE            (SCOPE_DSCALE + 1)
#define SCOPE_FSCALE            (SCOPE_ESCALE + 1)
#define SCOPE_BUFFER            (SCOPE_FSCALE + 1)

#define CONTROLLER_CMD_RTN_IDX  (SCOPE_BUFFER + SCOPE_BUFFER_SIZE)
#define CONTROLLER_CMD_ARG_IDX  (CONTROLLER_CMD_RTN_IDX + 1)
#define CONTROLLER_CMD_IDX      (CONTROLLER_CMD_ARG_IDX + CONTROLLER_NUMBER_OF_ARGS)

#define MPN_CMD_RTN_IDX         (CONTROLLER_CMD_IDX + 1)
#define MPN_CMD_ARG_IDX         (MPN_CMD_RTN_IDX + 1)
#define MPN_CMD_IDX             (MPN_CMD_ARG_IDX + MPN_NUMBER_OF_ARGS)

#define MPN_TRIO_BASIC_ERROR    (MPN_CMD_IDX + 1)
#define MPN_TRIO_BASIC_LINE_ERROR (MPN_TRIO_BASIC_ERROR + 1)
#define MPN_CANCEL              (MPN_TRIO_BASIC_LINE_ERROR + 1)
#define MPN_RUNNING             (MPN_CANCEL + 1)

#define MPN_STATE               (MPN_RUNNING + 1)
#define MPN_SPEEDFACTOR         (MPN_STATE + 1)
#define MPN_TRIO_SUMMARY        (MPN_SPEEDFACTOR + 1)
#define MPN_TRIO_SUMMARY_SIZE   18
#define MPN_KASSELIFT           (MPN_TRIO_SUMMARY + 50)
#define MPN_KASSELIFT_SIZE      5 
#define MPN_LAST                (MPN_KASSELIFT + 50)

//ALLOCATE NEW TABLE SPACE BEFORE NUM_OF_PATH_INDEX
#define UPLOADGROUP_SIZE        25000
#define UPLOADGROUP_START       5000
#define NUM_OF_PATH_INDEX(a)    (UPLOADGROUP_START+UPLOADGROUP_SIZE*(a))
#define PATH_INDEX(a)           (UPLOADGROUP_START+UPLOADGROUP_SIZE*(a) + 1)
#define FIRST_PATH_INDEX(a)     (UPLOADGROUP_START+UPLOADGROUP_SIZE*(a) + 101)

#define MAX_PATH_INDEX          40
#define MAX_PATH_UPLOAD         3
#define MAX_PATH_AGE            15
#define MAXLOADGROUP            1

#define ROBOSTATE_IDLE 0
#define ROBOSTATE_STARTING 1
#define ROBOSTATE_RUNNING 2
#define ROBOSTATE_STOPPING 3
#define ROBOSTATE_PAUSED 4
#define ROBOSTATE_WDOGOFF 5
#define ROBOSTATE_ERROR 6
#define ROBOSTATE_RESTARTING 7
/*************************************************************/
/* STMSERVER and STMCLIENT                                   */
/*************************************************************/

#define STMPORT 1299    // the port users will be connecting to
#define STMCLIENT_RECVBUFFER 2048  // size of receive buffer
#define STMCLIENT_SNDBUFFER 2048   // size of send buffer
#define STMCLIENT_TIMEOUT 1 // Timeout [s] on connection
#define STMCLIENT_UPDATEINTERVAL 100000  //Update interval [us] per query
#define STMCLIENT_POLLDEADINTERVAL 7000000  //poll interval for dead remotestatemachines [us]

#define STMSERVER_BACKLOG 7     // how many pending connections queue will hold

#define STMSERVER_TIMEOUT 10     // Timeout [s] on connection
#define STMSERVER_RECVBUFFER 2048  // size of receive buffer
#define STMSERVER_SNDBUFFER 2048    // size of send buffer
#define STMSERVER_MAXSTATEMCOUNT 256 //maximum number of statemachines to be queried
#define STMSERVER_MAXVALUECOUNT  512 //maximum number of values to be queried


#define RESPONSE_STMSERVER 0
#define RESPONSE_MODEL 1
#define RESPONSE_WORKCELL 2
#define RESPONSE_STMUNKNOWN 3
#define RESPONSE_STMKNOWN 4
#define RESPONSE_REPEAT_START 5
#define RESPONSE_REPEAT_END 6
#define RESPONSE_CLEAR_OK 7
#define RESPONSE_GOODBYE 8
#define RESPONSE_RUBBISH 9
#define RESPONSE_NONE 10
#define RESPONSE_VALUEUNKNOWN 11
#define RESPONSE_VALUEKNOWN 12

/*************************************************************/
/* UDPSERVER and UDPCLIENT                                   */
/*************************************************************/

#define UDPSERVER 0
#define UDPCLIENT 1

#define UDPCLIENT_RECVBUFFER 2048  // size of receive buffer
#define UDPCLIENT_SNDBUFFER 2048   // size of send buffer
#define UDPCLIENT_TIMEOUT 1        // Timeout [s] on connection

#define UDPSERVER_RECVBUFFER 2048  // size of receive buffer
#define UDPSERVER_SNDBUFFER 2048    // size of send buffer

#define UDP_MAXQUESTIONS 32 //maximum number of different question
#define UDP_MAXFORMATVALUES 10 //maximum number of values in format

/*******************************/

#define INITVAL      0
#define INVAL        1
#define OUTVAL       2

typedef struct comskConnect
{
	int fixdec; // number of decimal places after dot
	float factor;
	float fdata;
	int major;
	int minor;
	short* data;
	char key[256];
	char comment[256];
} comskConnect;

typedef struct comskstruct
{ 
  char module_name[256];
	int address;
  int numOfInitWords;
  int numOfInWords;
  int numOfOutWords;
	comskConnect initdata[COMSK_MAXINITS];
  comskConnect idata[COMSK_MAXVALS];
  comskConnect odata[COMSK_MAXVALS];
} comskstruct;

typedef struct tmpnComSK
{
  int sfd;
  int simulate;
	int type; //RW (slow) or WONLY (fast)
  char ipaddr[256];
  int numOfModules;
  comskstruct *iotab;
	int highadr; //Following fields are for type=WONLY
	int lowadr;
	int adrcount;
	short oarray[COMSK_MAXVALS*10];
} tmpnComSK;

typedef struct tmpnComSKs
{
  char name[256];
  int maxidx;
  tmpnComSK comsk[MAXCOMSKS];
} tmpnComSKs;

/*******************************/
// MAC

#define MAC_SHORTINT          0
#define MAC_SHORTUINT         1
#define MAC_LONGINT           2
#define MAC_FIXED4            3
#define MAC_FIXED8            4
#define MAC_FIXED16           5
#define MAC_FIXED24           6
#define MAC_LONGINT_ASFLOAT   7
#define MAC_SHORTINT_ASFLOAT  8
#define MAC_SHORTUINT_ASFLOAT 9
#define MAC_CMD               10


typedef struct macConnect
{
	int type; // longint, shortint, shortuint, fixed4, fixed8, fixed16, fixed24, maccmd
	float factor;
	int reg;
	int bitmode;
	void *bitparent;
	int data;
	float fdata;
	int userchange;
	char key[256];
	char comment[256];
} macConnect;

typedef struct macstruct
{ 
  char module_name[256];
	int address;
  int numOfInitWords;
  int numOfInWords;
  int numOfOutWords;
	macConnect initdata[MAC_MAXINITS];
  macConnect idata[MAC_MAXINVALS];
  macConnect odata[MAC_MAXOUTVALS];
} macstruct;

typedef struct tmpnMac
{
	char filename[256];
  int sfd;
  int simulate;
  char ipaddr[256];
	int port;
  int numOfMotors;
  macstruct *iotab;
} tmpnMac;

typedef struct tmpnMacs
{
  char name[256];
  int maxidx;
  tmpnMac mac[MAXMACS];
} tmpnMacs;

/*******************************/
typedef struct loadcellConnect
{
	float factor;
	float fdata;
	int ignoreError;
	char key[256];
	char comment[256];
} loadcellConnect;

typedef struct tmpnLoadCell
{
  int sfd;
  int simulate;
  char ipaddr[256];
	int port;
	int fastmoxa;
  int numOfModules;
  loadcellConnect iotab[8];
} tmpnLoadCell;

typedef struct tmpnLoadCells
{
  char name[256];
  int maxidx;
  tmpnLoadCell loadcell[MAXLOADCELLS];
} tmpnLoadCells;

/*******************************/

#define INPUT_BASE      5392
#define OUTPUT_BASE     1

#define STBDDI3610      1
#define STBDDO3600      2
#define STBEPI2145      3
#define STBEHC3020      4
#define STBDDI3420      5
#define STBAVI1270      6
#define STBAVO1250      7
#define STBDDI3725      8
#define STBDDO3705      9

typedef struct tmpnConnect
{
  int connectType;
  int wordidx; 
  int bitidx;
  int shift;
  unsigned short mask;
  union
  {
    short *sdata; 
    unsigned short *udata; 
  };
  char name[256]; //connect name in dio
  char key[256];
  char text[256];
} tmpnConnect;

typedef struct stbstruct
{
  int type;
  char typeStr[256];
  char module_name[256];
  int maxidx;
  int numOfInWords;
  int numOfOutWords;
  tmpnConnect connect[MAXCONNECT];
  unsigned short *idata;
  unsigned short *odata;
} stbstruct;

typedef struct tmpnDIO
{
  int sfd;
  volatile int cleardioerror;
  int simulate;
  char ipaddr[256];
  int numOfModules;
  stbstruct *iotab;
  int numOfInWords;
  unsigned short idata[1000];
  int numOfOutWords;
  unsigned short odata[1000];
} tmpnDIO;

typedef struct tmpnDIOs
{
  char name[256];
  int maxidx;
  tmpnDIO dio[MAXDIO];
} tmpnDIOs;

typedef struct MPN_SUMMARY {
  float wdog; //int
  float emergency;
  float state;
  float mtypet;
  float mtypef;
  float axist;
  float axisa;
  float axisb;
  float axisc;
  float axisd;
  float axise;
  float axisf;
  float fea;
  float feb;
  float fec;
  float fed;
  float fee;
  float fef;
} MPN_SUMMARY;

#define ICP_7063BD 0

typedef struct tmpnICPConnect
{
	int bitpos;
  char key[256];  //connect name in icpcon-file
	unsigned int *udata; 
} tmpnICPConnect;

typedef struct icpconstruct
{
  int type;
  char typeStr[256];
  char module_name[256];
	int address;
	int dosetup;
  int numOfInBits;
  int numOfOutBits;
  tmpnICPConnect inconnect[MAXICPCONNECT];
	tmpnICPConnect outconnect[MAXICPCONNECT];
  unsigned int idata;
  unsigned int odata;
} icpconstruct;

typedef struct tmpnICPcon
{
  int sfd;
  int simulate;
  char ipaddr[256];
	int port;
  int numOfModules;
  icpconstruct *iotab;
} tmpnICPcon;

typedef struct tmpnICPcons
{
  int maxidx;
  tmpnICPcon icpcon[MAXICPCONS];
} tmpnICPcons;

typedef struct AXIS_PARAMETER {
  float atype; //int
  float p_gain;
  float i_gain;
  float d_gain;
  float ov_gain;
  float vff_gain;
  float units;
  float speed;
  float accel;
  float decel;
  float creep;
  float jogspeed;
  float felimit;
  float dac; //int
  float servo; //int
  float redispt;
  float fwd_in; //int
  float rev_in; //int
  float dat_in; //int
  float fh_in; //int
  float fslimit;
  float rslimit;
  float mtype; //int
  float ntype; //int
  float mpos;
  float dpos;
  float fe;
  float axisstatus; //int
  float vpspeed;
} AXIS_PARAMETER;

typedef struct SCOPECMD
{
  float rtn;
  float arg[SCOPE_NUMBER_OF_ARGS];
  float cmd_nr;
  float type;
  float length;
  float numofsamples;
  float scale[6];
  float buffer[SCOPE_BUFFER_SIZE];
} SCOPECMD;

typedef struct CONTROLLERCMD
{
  float rtn;
  float arg[CONTROLLER_NUMBER_OF_ARGS];
  float cmd_nr;
} CONTROLLERCMD;

typedef struct MPNCMD
{
  float rtn;
  float arg[MPN_NUMBER_OF_ARGS];
  float cmd_nr;
} MPNCMD;

typedef struct AXIS_NAME
{
  AXIS_PARAMETER t,a,b,c,d,e,f;
} AXIS_NAME;

typedef union AXIS_UNION
{
  AXIS_NAME name;
  AXIS_PARAMETER array[NUMBER_OF_AXIS];
}  AXIS_UNION;

typedef struct TABLESPACE
{
  AXIS_UNION      axis;
  SCOPECMD        scope;
  CONTROLLERCMD   ctrl_cmd;
  MPNCMD          mpn_cmd;
  MPN_SUMMARY     summary;
  float mpn_trio_basic_error;
  float mpn_trio_basic_line_error;
  float mpn_cancel;
  float mpn_running;
  float mpn_state;
  float num_of_path_index;
  float path_index[100];
} TABLESPACE;




/////////////////


typedef struct tmpnVectorXYZ
{
  tmpnFloat x,y,z;
} tmpnVectorXYZ;

typedef struct tmpnColor
{
	tmpnFloat r,g,b;
} tmpnColor;
//************************************************
//Open GL
//************************************************
typedef struct tmpnMaterial
{
  float diffuse[4];
  float ambient[4];
  float specular[4];
  float shininess;
} tmpnMaterial;
typedef struct tmpnBone
{
  long    id;// BONE ID
  char    name[80];
  tmpnVectorXYZ rot;
  tmpnVectorXYZ trans;
  tmpnVectorXYZ dim;
  tmpnColor  color;
  tmpnMaterial material;
  int     gllist;
  int     cyl;
} tmpnBone;

typedef struct tmpnScene
{
  int       coord;
  //robot
  tmpnBone  floor;
  tmpnBone  foot,leg;
  tmpnBone  gantry,shoulder;
  tmpnBone  upperArm,lowerArm,lowerArm2,wrist,flange;
  tmpnBone  gearA,gearB,gearC,gearD,gearE;

  //tools
  tmpnBone  tool;

  struct
  {
    int       maxidx;
    tmpnBone  accessory[MAXACCESSORIES];
  } accessories;

//  tmpnBone  m_Station;
//  tmpnBone  m_Belt;

  tmpnBone  pallet;

  tmpnBone  key;

  int       boxpicked;
  int       palletAboxPlaced[10][4];
  int       palletCboxPlaced[10][4];
} tmpnScene;


typedef struct tmpnVector
{
  tmpnFloat x,y,z,v,w,u;
} tmpnVector;

typedef struct tmpnDualVector
{
  tmpnFloat x,y,z,v,w,u;
  int absx,absy,absz,absv,absw,absu;
} tmpnDualVector;

typedef struct tmpnFrame
{
  //Homogenius matrix form can be used if rotate has to be implemented
  char name[256];
  tmpnFloat x,y,z,v,w,u;
} tmpnFrame;

typedef struct tmpnFrames
{
  int maxidx;
  tmpnFrame frame[MAXFRAMENAMES];
} tmpnFrames;

typedef struct tmpnTimingItem
{
  char name[256];
  tmpnFloat value;
} tmpnTimingItem;

typedef struct tmpnTiming
{
  int maxidx;
  tmpnTimingItem item[MAXTUNING];
} tmpnTiming;

typedef struct tmpnMacro
{
  char name[256];
  int idx; //mpncommand 100 - 99999 reserved for macros
} tmpnMacro;

typedef struct tmpnJoints
{
  tmpnFloat a,b,c,d,e,f;
} tmpnJoints;

typedef union tmpnJointsUnion
{
  tmpnJoints name;
  tmpnFloat array[6];
} tmpnJointsUnion;

//************************************************
//BOPTCOEFF
//************************************************

typedef struct tmpnBoptParamStruct
{
	// c = constant
	// f = foo1 
	// b = bar1
	// p = foo2 (poo)
	// g = bar2 (gar)
	// l = lengthdiff
	// h = heightdiff
	// t = tiltdiff
	// r = rotationdiff
	int numofparams;
	char table[16];
	float value;
	int ABS;
} tmpnBoptParamStruct;

typedef struct tmpnBoptViaVector
{
	tmpnBoptParamStruct x[16];
	tmpnBoptParamStruct y[16];
	tmpnBoptParamStruct z[16];
	tmpnBoptParamStruct v[16];
	tmpnBoptParamStruct w[16];
} tmpnBoptViaVector;

typedef struct tmpnBoptMacroItem
{
	/*
		---
    type
		positionhint
		---
    length
		time
		amplitude
		offsx
		offsz
		frequency
		---
	*/
	int integer[2];
	float floating[6];
} tmpnBoptMacroItem;

typedef struct tmpnBoptParamItem
{
	/*
		---
		tcpidx
		blendtype
		---
		maxheight
		minheight
		samplerate
		timefactor
		maxlength
		lockv
		---
	*/
	int integer[2];
	float floating[6];
} tmpnBoptParamItem;

typedef struct tmpnBoptCoeffItem
{
	char pathName[256];
	int mode;
	int pathtype;
	int viatype;
  struct 
  {
    char fromFrame[256];
    char toFrame[256]; 
    char fromItem[256]; 
    char toItem[256]; 
    char fromPattern[256]; 
    char toPattern[256]; 
  } def;   //default (used in mpnguide)
	tmpnBoptViaVector viapos[2];
	tmpnBoptViaVector viavel[2];
  tmpnBoptMacroItem macro[2];
	float mv[5];
	float ma[5];
	tmpnBoptParamItem params;
} tmpnBoptCoeffItem;

typedef struct tmpnBoptCoeff
{
  char name[128];
	char filename[256];
	int maxidx;
	tmpnBoptCoeffItem item[MAXBOPTCOEFFITEMS];
} tmpnBoptCoeff;


//************************************************
//PATTERN
//************************************************
typedef struct tmpnItem
{
  char type[256];//"BAG","BOX","EUROPALLET","HALFPALLET","BIGBOX" etc
  char name[256];
  char filename[256];
  tmpnVectorXYZ dim; //fysisk
  tmpnFloat sy; //stablet y
  tmpnFloat gy; //grip y
  tmpnFloat my; //move y
  tmpnFloat gx; //grip x
  tmpnFloat weight;//for dynamic model
  int user;
} tmpnItem;

typedef struct tmpnPatternItem
{
  int layer;
  tmpnFrame wcp;
} tmpnPatternItem;

typedef struct tmpnPattern
{
  char name[256]; //unique key to pattern
  char filename[256]; 
  int maxidx;
  float width;
  float length;
  tmpnPatternItem item[MAXPATTERNITEMS];
} tmpnPattern;   //size=14200 med 50 items

//************************************************
//CPPATTERN
//************************************************

typedef struct tmpnCPPatternItem
{
  int layer;
  int maxpush;
  int gettime;
  int *ppps;//maxpush indicates number of ppps
  int *paccs;
  int *pspeeds;
} tmpnCPPatternItem;

typedef struct tmpnCPPattern
{
  char name[256]; //unique key to pattern
  char filename[256];
  int user;
  int selectedItem;
  int selectedPPP;
  int maxidx;
  tmpnCPPatternItem *items;
} tmpnCPPattern;

//************************************************
//PATH
//************************************************
typedef struct tmpnKeyPoint
{
  int tcpidx;
  int statehint;
  tmpnFloat positionhint;
  tmpnFloat x,y,z,v,w,u;
  tmpnFloat dt;                  //time used to get here from prev position
  tmpnFloat t;                   //time used to get here from t=0
  tmpnFloat sp;                  //sampleperiod
} tmpnKeyPoint;

typedef struct tmpnHPoint
{
  int i;
  int time; //in  1/1000000 pathtime
  tmpnFloat x,y,z,v,w,u;
  tmpnFloat dt;                   //time used to get here from prev position
  int tcpidx;
  int keypointidx;
} tmpnHPoint;

typedef struct tmpnPosHint
{
  int positionhint;
  int i;
  int time; //in  1/1000000 pathtime
} tmpnPosHint;

typedef struct tmpnPosition {
   tmpnVector taskSpace;
   tmpnJointsUnion jointSpace;
   tmpnJointsUnion actuatorSpace;
   //only used for resampling with speed/force restraints
   tmpnKeyPoint *keypoint;   
   int tcpidx;
   int statehint;
   tmpnFloat positionhint;
   tmpnJointsUnion dif;           //distance from prev position
   tmpnJointsUnion speed;         //distance/sec in this point
   tmpnJointsUnion rev;           //motor rev/min in this point
   tmpnJointsUnion pctRatedSpeed; //% off nominel speed
   tmpnJointsUnion posRad;        //position in rad
   tmpnJointsUnion speedRad;      //rad or m/sec in prev interval
   tmpnJointsUnion accelRad;      //rad or m/sec*sec in prev interval
   tmpnJointsUnion jerkRad ;      //rad or m/sec*sec*sec in prev interval
   tmpnJointsUnion force;         //N or Nm in prev interval
   tmpnJointsUnion scope;         //N or Nm in prev interval from actual path
   int maxrev;                    //index fastest joint at this position (0=a,1=b ect)
   tmpnFloat dt;                  //time used to get here from prev position
   tmpnFloat t;                   //time used to get here from t=0
   tmpnFloat sp;                   //time used to get here from t=0
} tmpnPosition;

typedef struct tmpnPathDef
{
  char name[256];
  int id;
  volatile int seqnum;
  volatile int idx; //index in pathbuffer on MC. if idx==-1 the path is not loaded
  int maxidx;
  int numofsamples;
  int samplesBetweenKeypoints;
  int pathtype;
  int runbopt;
  int spline;
  int loadgroup; //used to preload the next path in more than one group (f.eks. palletA and palletB path's are placed in group 0 and 1):
  int splineorder;
  tmpnFloat maxTime;
  tmpnFloat maxSpeed;
  tmpnKeyPoint keypoint[MAXKEYPOINTS]; //TODO move statehint to hpoint and change keypoint to tmpnVector
  int maxhidx;
  tmpnHPoint hpoint[MAXHPOINTS];
  int maxpidx;
  tmpnPosHint poshint[MAXPOSHINT];
} tmpnPathDef;

typedef struct tmpnPath
{
  int maxidx;
  tmpnPosition position[MAXPOSITIONS];
} tmpnPath;

//for uploading
typedef struct bufferstruct
{
  tmpnPathDef *tpathdef;
  tmpnPath pathdata;
} bufferstruct;

/*************************************************************/
/* tmpnPathHandle.state                                      */
/*************************************************************/
#define ST_IDLE         1 //inactive state  (         : wait for LOAD command)
#define ST_LOADED       2 //inactive state  (         : wait for EXEC or FREE command)
#define ST_FINISHED     3 //inactive state  (         : wait for EXEC,FREE or LOAD command)
#define ST_ERROR        4 //inactive state  (         : wait for FREE command) 
#define ST_INACTIVE     5 //command state   (STM      : tell EXECUTER to execute path)
#define ST_LOAD         6 //command state   (STM      : tell LOADER to load path)
#define ST_EXEC         7 //command state   (STM      : tell EXECUTER to execute path)
#define ST_BOPTING      8 //active state    (LOADER   : optimize acording to parameters and goto LOADING)
#define ST_LOADING      9 //active state    (LOADER   : send path to MC and goto LOADED)
#define ST_EXECUTING   10 //active state    (EXECUTER : run path and goto FINISHED)

typedef struct tmpnPathKeyFrame
{
  tmpnFrame frame; 
  int cItem; //item number
  int cLayer; 
  char itemName[256]; 
  tmpnItem *item;  
  char patternName[256];  
  tmpnPattern *pattern;  
} tmpnPathKeyFrame;

typedef struct tmpnPathKey
{
  int mode; //mode
  int type; //pathtype
	tmpnBoptCoeffItem* boptcoeff;
  tmpnPathKeyFrame from;
  tmpnPathKeyFrame to;
} tmpnPathKey;

typedef struct tmpnPathHandle
{
  tmpnPathKey key; 
  int state; //see above
//  int errorCode; //copy of errorCode in robot.statemachine
  char script[256];
  struct COMMANDSTRUCT *firstpoint;
} tmpnPathHandle;

typedef struct tmpnPathItem
{
  tmpnPathHandle handle;  
  tmpnPathDef pathdef;
  int bopted; //bopted=1 path is bopted
  tmpnPathHandle *path; //if !=NULL it points to a pathhandle in a statemachine
} tmpnPathItem;

//for saving bopted path's
typedef struct tmpnPathTable
{
  int maxidx;
  int newidx;
  tmpnPathItem item[MAXPATHTABLEITEMS];
  int currentidx;
  tmpnPath pathdata;
} tmpnPathTable;

typedef struct tmpnScopeItem
{
  tmpnJointsUnion force;
} tmpnScopeItem;

typedef struct tmpnScope
{
  int maxidx;
  tmpnScopeItem *sample;
} tmpnScope;
typedef struct tmpnAccessory
{
  char name[256]; //"belt","station","roll"
  tmpnVectorXYZ dimention;
  tmpnVectorXYZ transformation;
  tmpnMaterial  material;  
} tmpnAccessory;

//************************************************
//STATEMACHINE
//************************************************

typedef struct tmpnRemoteHost
{
  char name[128];
  int port;
  int sockfd;
  int alive;
  int repeat;
  int sndbuf_idx;
  char sndbuf[STMCLIENT_SNDBUFFER];
} tmpnRemoteHost;

typedef struct tmpnRemoteStateMachine
{
  tmpnRemoteHost *remotehost;
  char name[128];
  char state[128];
  char safe[128];
	pthread_mutex_t remotelock;
} tmpnRemoteStateMachine;

typedef struct tmpnRemoteValue
{
  tmpnRemoteHost *remotehost;
  char name[128];
  char link[128];
	int subtype;
	int data;
	float fdata;
} tmpnRemoteValue;

typedef struct tmpnMachineType
{
  int idx;
  char name[256];
} tmpnMachineType;

typedef struct tmpnStateName
{
  int  idx;
  char name[256];
} tmpnStateName;

typedef struct tmpnStateMachineIO
{
  char name[256];
  int iotype; //INPUT or OUTPUT or OUTCOMSK or INCOMSK or INLC or INMAC or OUTMAC or INICPCON or OUTICPCON
  //unsigned short *data; //data pointer could be placed in tmpnConnect
  //int bitidx;//bitidx could be placed in tmpnConnect
	union {
		tmpnConnect *connect;
		comskConnect *comskconnect;
		loadcellConnect *loadcellconnect;
		macConnect *macconnect;
		tmpnICPConnect *icpconnect;
	};
} tmpnStateMachineIO;

typedef struct STMCOMMANDSTRUCT
{
  int type;
  void *data;
  int level;
} STMCOMMANDSTRUCT;

typedef struct tmpnStateMachineState
{
  char name[256];
  int statenum;
  int maxprgidx;
  STMCOMMANDSTRUCT *prg;
} tmpnStateMachineState;

typedef struct tmpnStateMachineTimeout
{
  char name[256];
  int timeout;
} tmpnStateMachineTimeout;

typedef struct tmpnStateMachineTable
{
  int maxsize;
  int filter; //0=NO FILTER 1=AVG
  int newtablesize;
  int curtablesize;
  int sum;
  int sumcnt;
  int maxidx;
  int min;
  int max;
  int *item;
  int topsearchwidth; ///< how far back the search of the toppoint should go
  int topidx; ///< index of found toppoint
  float fsum;
  float fmin;
  float fmax;
  float *fitem;
  float topval; ///< value of found toppoint
} tmpnStateMachineTable;

typedef struct tmpnStateMachineValue
{
  char name[256];
  int type; //VALUE CONSTANT TABLE LINKVALUE
  int subtype; //0=int 1=float
  int data;
  float fdata;
  char linkname[256];
  char link[256];
  //could be declared as union
  tmpnStateMachineTable *table; //used if type=TABLE
  tmpnPathHandle *path; //used if type=PATH
  tmpnFrame *frame; //used if type=FRAME
  tmpnItem *item; //used if type=ITEM
  tmpnPattern *pattern; //used if type=PATTERN
  tmpnCPPattern *cppattern; //used if type=CPPATTERN
  struct tmpnStateMachineValue *linkvalue;
	tmpnRemoteValue *remote; //used if remotevalue <=> linkvalue==NULL
} tmpnStateMachineValue;

typedef struct tmpnStateMachineLink
{
  int stmidx; 
  char localname[256];
  char name[256];
} tmpnStateMachineLink;

typedef struct tmpnStateMachine
{
  int version;
  int type;
  char filename[256];
  char name[256];
  //TODO liste over hvilke STM's der har mcSignal's er i brug
  //
  int mcSignal; //hvis TRUE sendes denne STM's istate til MC
                //og MC kan sætte state via setState()
  int delaystop;
  struct timeval stoptimer;

  volatile int istate;
  int next_istate;
  int new_istate;
  volatile int stop;
  pthread_cond_t change;
  pthread_mutex_t change_mtx;
  struct timeval timer;
	int timerstate;
	tmpnStateMachineValue *debugvalue;
  int numstate;
  tmpnStateMachineState *state;
	int numvalue;
  tmpnStateMachineValue *value;
  int numtimeout;
  tmpnStateMachineTimeout *timeout;
  int numinput;
  tmpnStateMachineIO *input;
  int numoutput;
  tmpnStateMachineIO *output;
  int numlink;
  tmpnStateMachineLink *link;
} tmpnStateMachine;

//************************************************
//UDP Server and Client
//************************************************
typedef struct tmpnUdpQuestionStruct
{
	float freq;
	char questionformat[256];
	char responseformat[256];
	int maxresponseval;
	tmpnStateMachineValue *responseval[UDP_MAXFORMATVALUES];
} tmpnUdpQuestionStruct;

typedef struct tmpnUdpAgentStruct
{
	int type; //UDPSERVER or UDPCLIENT
	int simulate;
	char ipaddr[256];
  int port;
  int sockfd;
  int sndbuf_idx;
  char sndbuf[UDPSERVER_SNDBUFFER];
	int maxqlines;
	tmpnUdpQuestionStruct qlines[UDP_MAXQUESTIONS];
} tmpnUdpAgentStruct;

typedef struct tmpnUdpAgents
{
  int servers_maxidx;
	int clients_maxidx;
  tmpnUdpAgentStruct *server;
  tmpnUdpAgentStruct *client;
} tmpnUdpAgents;

//************************************************
//PPSCRIPT
//************************************************
typedef struct tmpnPPScriptItem
{
  char cmd[256]; //so far only move cmd's
  char item[256]; //what is to be moved
  char from[256]; //frame TODO: use object's frame and pattern info instead of "just frame"
  char to[256];   //frame
  int layer;
  int idx;
  tmpnVector wcp;
} tmpnPPScriptItem;

typedef struct tmpnCoeff
{
  char name[256];
  float value;
} tmpnCoeff;

typedef struct tmpnPPScript
{
  char name[256];
  int type; //type=1 Nyhuus10Kg+Nyhuus5Kg
            //type=2 AlfredIn
  int maxidx;
  int itemsPrLayer;
  int layers;
  tmpnPPScriptItem item[MAXPPCRIPTITEMS];
} tmpnPPScript;

typedef struct tmpnRSSystem
{
  char plant[256];
  char workcell[256];
  char location[256];
  char robot[256];
  char pcIPaddr[256];
  char mcIPaddr[256];
  char nic[256];
  char script[256];
  int  workcellid;
  int lag;
  struct 
  {
    int initialized;
    int offx;
    int offy;
    float calx;
    float caly;
    int ctrltype;
    char port[256];
  } touch;
  char scriptname[256];
  int  simulateMC;
  int  mc_task_debug;
  int  path_debug;
  int  statemachine_debug;
	int  io_debug;
  int  startSpeed;
  char user[256];
  char password[256];
  int  checkWeigher;
  int  roboStacker;
  char mainDialog[256];
  int  scriptExec;
  int  new_trio_addr;
  int stmServerPort;
  int mc_version;
} tmpnRSSystem;
//************************************************
//ROBOT
//************************************************
typedef struct tmpnTCP
{
  char name[256];
  tmpnFloat x,y,z,v,w,u;
} tmpnTCP;

typedef struct tmpnTool
{
  char name[256];
  tmpnVectorXYZ dim;
  tmpnFloat weight;//for dynamic model
	int itemsperlift;
	//  int state; //set centerOfMass and momentOfInertia
	//  int tcpidx;
	//  tmpnTCP tcp[MAXTCP];     //only transform of x,y,z is currently implemented
} tmpnTool;


typedef struct tmpnServoAxis {
} tmpnServoAxis;
 
typedef struct tmpnLink
{
  tmpnFloat length;              // Length
  tmpnFloat mass;                // mass
  tmpnFloat massDisplacement[3]; // Centre of Mass displacements
  tmpnFloat inertia[3][3];       // Inertia tensors for link
} tmpnLink;

typedef struct tmpnStateTekst
{
  int idx;
  char tekst[256];
} tmpnStateTekst;

typedef struct tmpnStateTeksts
{
  char name[256];
  int maxidx;
  tmpnStateTekst item[MAXSTATETEKST];
} tmpnStateTeksts;

typedef struct tmpnStateTekstList
{
	int numofStateTeksts;
  tmpnStateTeksts stateteksts[MAXSTATETEKSTS];
	int currentStateTekst;
} tmpnStateTekstList;

typedef struct tmpnLanguageLine
{
  int key;
  char tekst[256];
	char english[256];
} tmpnLanguageLine;

typedef struct tmpnLanguage
{
  char name[256];
  int maxidx;
  tmpnLanguageLine item[MAXLANGLINES];
} tmpnLanguage;

typedef struct tmpnLanguages
{
	int numoflanguages;
  tmpnLanguage language[MAXLANGUAGES];
	int currentLanguage;
} tmpnLanguages;

typedef struct tmpnScript
{
  char name[256];
} tmpnScript;

typedef struct tmpnScripts
{
  int maxidx;
  tmpnScript item[MAXSCRIPTNAMES];
} tmpnScripts;

typedef struct COMMANDSTRUCT {
  int type;
  void *data;
  struct COMMANDSTRUCT *next;
  struct COMMANDSTRUCT *prev;
  int flag;
  void *listitem;
  int include; //include=0 => normal cmd include=1 => copy of other script (do not save)
} COMMANDSTRUCT;

typedef struct tmpnRobot
{
  char m_name[256];
  tmpnFloat m_gantryLength;
  tmpnFloat m_legHeight;
  tmpnFloat m_shoulderGearB;
  tmpnLink m_Link[5];   //** robot without tool
  tmpnLink m_State[3]; //** robot states for Link 4(axis e) with tool and load
  tmpnJointsUnion m_sign;   //actual motor rev direction
  tmpnJointsUnion m_ratedRpmGear;  //
  tmpnJointsUnion m_ratedNmGear;  //
  tmpnJointsUnion m_ratedRPM;  //all motors are rated for 3000 rev pr minute
  tmpnJointsUnion m_ratedNm;   //
  tmpnJointsUnion m_maxForceNm;   //
  tmpnJointsUnion m_pulses;  //all encoders are 65536 encoder pulses pr rev
  tmpnJointsUnion m_gearing; //
  tmpnJointsUnion m_unit;   //mm or deg
  
  tmpnJointsUnion m_units; //m_pulses*m_gearing/m_unit
  tmpnJointsUnion m_p_gain;
  tmpnJointsUnion m_i_gain;
  tmpnJointsUnion m_d_gain;
  tmpnJointsUnion m_ov_gain;
  tmpnJointsUnion m_vff_gain;
  tmpnJointsUnion m_speed;
  tmpnJointsUnion m_accel;
  tmpnJointsUnion m_decel;
  tmpnJointsUnion m_creep;
  tmpnJointsUnion m_jogspeed;
  tmpnJointsUnion m_felimit;

  tmpnJointsUnion m_Trms; //last computed rated mean squared Torque (motor)
  tmpnJointsUnion m_lifeTimeGear; //last computed gear lifetime
//  tmpnJointsUnion m_jointsCalib;   //factor for calibration ???
  tmpnVector m_min;     //in taskSpace coord mm
  tmpnVector m_max;     //in taskSpace coord mm
  //TODO: advanced min max values for protection
  tmpnVector m_worldPoint; //last computed invers/forward kinematic taskSpace point ajusted for min max
  //SIMPLE ROBOT CALIBRATION OF AXIS B CENTER
  tmpnVector m_localTrans; //in mm x=x in taskSpace, y=hight over floor in taskSpace, z=z in taskSpace
  //ONLINE ROBOT CALIBRATION
  tmpnJoints m_jointCalib;
  //ENCODER ABSOLUTE SLM
  tmpnJoints m_mpnhome;
  //TOOL DATA
  int       m_state;  //last used state
  int       m_tcpidx; //last used tcpidx
  tmpnTCP   m_tcp[MAXTCP];
  //RESULT OF IK
  tmpnJoints m_actuator;   //last computed angles in deg derived from IK(physical)
  tmpnJoints m_joint;      //last computed angles in deg derived from IK(logical)
  tmpnJointsUnion m_staticForce; //last computed staticForce
  //frames
  tmpnFrames m_frames;
  int        m_showPoint;
  int        m_snapToGrid;  //round to nearest 1/100 mm
  int        m_simulateTRIO;
 // tmpnFloat  splinehint;
 // tmpnFloat  splineorder;
  int  splinehint;
  int  splineorder;
  tmpnTiming timing;
  
} tmpnRobot;

typedef struct tmpnRobots
{
  int maxidx;
  tmpnRobot robot[MAXROBOTS];
} tmpnRobots;

typedef struct tmpnPatterns
{
  int maxidx;
  tmpnPattern pattern[MAXPATTERNS];//size=142000 med 10 items
} tmpnPatterns;

typedef struct tmpnCPPatterns
{
  int maxidx;
  tmpnCPPattern *cppattern;
} tmpnCPPatterns;

typedef struct tmpnItems
{
  int maxidx;
  tmpnItem item[MAXITEMS];
} tmpnItems;

typedef struct tmpnTools
{
  int maxidx;
  tmpnTool tool[MAXTOOLS];
} tmpnTools;

typedef struct tmpnAccessories
{
  int maxidx;
  tmpnAccessory accessory[MAXACCESSORIES];
} tmpnAccessories;

typedef struct tmpnPPScripts
{
  int maxidx;
  tmpnPPScript ppscript[MAXPPSCRIPTS];
} tmpnPPScripts;

typedef struct tmpnStateMachines
{
  int maxidx;
  tmpnStateMachine *statemachine;
} tmpnStateMachines;

typedef struct tmpnRemoteStateMachines
{
  int maxidx;
  tmpnRemoteStateMachine remotestatemachine[MAXREMOTESTM];
} tmpnRemoteStateMachines;

typedef struct tmpnRemoteValues
{
  int maxidx;
  tmpnRemoteValue remotevalue[MAXREMOTEVALUES];
} tmpnRemoteValues;

typedef struct tmpnRemoteHosts
{
  int maxidx;
  tmpnRemoteHost remotehost[MAXREMOTEHOSTS];
} tmpnRemoteHosts;

typedef struct tmpnWorkcell
{
  char name[256];
	char filename[256];
	tmpnLanguages languages;
  tmpnRobots robots;
  tmpnPatterns patterns;
  tmpnCPPatterns cppatterns;
  tmpnTools tools;
  tmpnItems items;
  tmpnAccessories accessories;
  tmpnPPScripts ppscripts;
	tmpnBoptCoeff boptcoeff;
  tmpnStateMachines statemachines;
  tmpnRemoteStateMachines remotestatemachines;
  tmpnRemoteValues remotevalues;
  tmpnRemoteHosts remotehosts;
	tmpnUdpAgents udpagents;
  tmpnDIOs dios;
	tmpnComSKs comsks;
	tmpnLoadCells loadcells;
	tmpnMacs macs;
	tmpnICPcons icpcons;
  tmpnScripts scripts; //what scripts can be run in this workcell
  tmpnStateTekstList statetekstlist;
  
  //these variables are shared between uploadtask and runtask
  volatile COMMANDSTRUCT *m_root;
 //TODO move lock's and communication variables here
//  volatile int jumpToLayer; //used by NYHUUS
//  volatile int scriptLoaded; //script_mutex
//  volatile int resetPreload; //script_mutex


} tmpnWorkcell;

typedef struct tmpnWorkcells
{
  int maxidx;
  tmpnWorkcell workcell[MAXWORKCELLS];
} tmpnWorkcells;

typedef struct tmpnPlant
{
  char name[256];
  tmpnWorkcells workcells;
} tmpnPlant;
//************************************************
//SCRIPT
//************************************************
typedef struct SPLINEHINTSTRUCT {
  int splinehint;
  int splineorder;
} SPLINEHINTSTRUCT;

typedef struct RESETPRELOADSTRUCT {
  int loadgroup;
} RESETPRELOADSTRUCT; 

typedef struct ROOTSTRUCT {
  int dummy;
} ROOTSTRUCT;

typedef struct STATEHINTSTRUCT {
  int statehint;
} STATEHINTSTRUCT;

typedef struct POSITIONHINTSTRUCT {
  int positionhint;
} POSITIONHINTSTRUCT;

typedef struct SADSSTRUCT {
  tmpnFloat speed;
  tmpnFloat accel;
  tmpnFloat decel;
  int sramp;
} SADSSTRUCT;

typedef struct MOVEABSSTRUCT {
  tmpnFloat  dest_a;
  tmpnFloat  dest_b;
  tmpnFloat  dest_c;
  tmpnFloat  dest_d;
  tmpnFloat  dest_e;
  tmpnFloat  dest_f;
} MOVEABSSTRUCT;

typedef struct MOVEAXISSTRUCT {
  int  axis;
  tmpnFloat  speed;
  tmpnFloat  accel;
  tmpnFloat  decel;
  tmpnFloat  distance;
  int  wait;
} MOVEAXISSTRUCT;

typedef struct CANCELAXISSTRUCT {
  int  axis;
  int  wait;
} CANCELAXISSTRUCT;

typedef struct WSPSTRUCT { //WORLD SPACE POINT STRUCT
  tmpnFloat  x;
  tmpnFloat  y;
  tmpnFloat  z;
  tmpnFloat  v;
  tmpnFloat  w;
  tmpnFloat  u;
} WSPSTRUCT;

extern WSPSTRUCT CalOffset;

typedef struct OUTPUTSTRUCT { //OUTPUT STRUCT
  int  p;
  int state;
} OUTPUTSTRUCT;

typedef struct INPUTSTRUCT { //INPUT STRUCT
  int  p;
} INPUTSTRUCT;

typedef struct EVENTSTRUCT {
  int type;
  char  machineName[256];
  char  stateName[256];
  char  machine;
  char  state;
} EVENTSTRUCT;

typedef struct COUNTERSTRUCT {
  char function[256];
  char name[256];
  char value[256];
} COUNTERSTRUCT;

typedef struct ERRORSTRUCT {
  int number;
  char text[256];
} ERRORSTRUCT;

typedef struct TUNINGSTRUCT {
  char name[256];
  int vr;
  tmpnFloat value;
} TUNINGSTRUCT;

typedef struct SETSPEEDSTRUCT {
  tmpnFloat factor;
} SETSPEEDSTRUCT;

typedef struct MACROSTRUCT {
  char  name[256];
  int  idx;
  int parameter0; //evt parameter 0 last param=-1
  int parameter1; //evt parameter 1
  int parameter2; //evt parameter 2
} MACROSTRUCT;

typedef struct CALLSTRUCT {
  char  script[256];
  int  lag;
} CALLSTRUCT;

typedef struct GOTOSTRUCT {
  char label[256];
} GOTOSTRUCT;

typedef struct LABELSTRUCT {
  char label[256];
} LABELSTRUCT;

typedef struct SLEEPSTRUCT {
  int ms;
} SLEEPSTRUCT;

typedef struct JUMPLAYERSTRUCT {
  char function[256];
  int  layer;
} JUMPLAYERSTRUCT;

typedef struct SCOPESTRUCT {
  int parameter0; //parameter 0 -
  int parameter1; //parameter 1
  int parameter2; //parameter 2
} SCOPESTRUCT;

typedef struct CACHESTRUCT { 
  char  name[256];
  int  idx;
} CACHESTRUCT;

typedef struct PPSCRIPTSTRUCT {
  char name[256]; 
  int  idx,loadgroup;
} PPSCRIPTSTRUCT;

typedef struct PATHSTRUCT { //PATH STRUCT
  tmpnPathDef tpathdef;
  struct COMMANDSTRUCT *firstpoint;
} PATHSTRUCT;

typedef struct POINTSTRUCT { //POINT STRUCT
  tmpnKeyPoint fp;
  tmpnKeyPoint p;  //calgulated world coordinate
                   //p=fp+frame[frameidx]+pp
  tmpnKeyPoint pp; //if pointtype=RPOINT then pp=previuspoint->fp
  int frameidx;    //index into m_frames
  PATHSTRUCT *path; //wich path is using this point
} POINTSTRUCT;

typedef struct SUBSTRUCT { //SUB STRUCT also used by
  char  name[256];
} SUBSTRUCT;

typedef struct NAMESTRUCT {
  char  name[256];
} NAMESTRUCT;

typedef struct ARGSTRUCT
{
  int type; 
  int idx;
  int number;
  float fnumber;
  int subtype; //what type is data 0=int 1=float
  char valstring[256];
  char valstring2[256];
} ARGSTRUCT;

typedef struct SETSTRUCT
{
  ARGSTRUCT dest; 
  ARGSTRUCT src; 
} SETSTRUCT;

typedef struct ROBOTSPEEDSTRUCT
{
  ARGSTRUCT src; 
} ROBOTSPEEDSTRUCT;

typedef struct CALCSTRUCT
{
  ARGSTRUCT dest; 
  ARGSTRUCT src1; 
  int optype;
  ARGSTRUCT src2; 
} CALCSTRUCT;

typedef struct PRINTSTRUCT
{
  ARGSTRUCT arg; 
  int newline;
} PRINTSTRUCT;

typedef struct TESTSTRUCT
{
  ARGSTRUCT test; 
  int validation;
  ARGSTRUCT cmp; 
  int trueIdx;
  COMMANDSTRUCT *trueCmd;
  int falseIdx;
  COMMANDSTRUCT *falseCmd;
	int doneIdx;
} TESTSTRUCT;

typedef struct ELSESTRUCT
{
  int doneIdx;
  COMMANDSTRUCT *nextCmd;
} ELSESTRUCT;

typedef struct SETSTATESTRUCT
{
  char name[256];
  int number;
} SETSTATESTRUCT;

typedef struct SETFRAMESTRUCT
{
  tmpnFrame *destFrame; 
  tmpnFrame *srcFrame; 
  char dest[256];
  char src[256];
} SETFRAMESTRUCT;

typedef struct SETITEMTRUCT
{
  tmpnItem **destItem; 
  tmpnItem *srcItem; 
  char dest[256];
  char src[256];
} SETITEMSTRUCT;

typedef struct SETPATTERNSTRUCT
{
  tmpnPattern **destPattern; 
  tmpnPattern *srcPattern; 
  char dest[256];
  char src[256];
} SETPATTERNSTRUCT;

typedef struct SETCPPATTERNSTRUCT
{
  tmpnCPPattern **destCPPattern;
  tmpnCPPattern *srcCPPattern;
  char dest[256];
  char src[256];
} SETCPPATTERNSTRUCT;

typedef struct TIMEOUTSTRUCT
{
  int idx;
  int number;
  char statename[256];
} TIMEOUTSTRUCT;

typedef struct LOADSTRUCT
{
  tmpnPathHandle *path; 
  tmpnFrame *fromFrame; 
  tmpnFrame *toFrame; 
  char dest[256];
  char src1[256];
  char src2[256];
} LOADSTRUCT;

typedef struct EXECSTRUCT
{
  tmpnPathHandle *path; 
  char dest[256];
} EXECSTRUCT;

typedef struct MULSTRUCT
{
  int idx;
	int arg1idx;
  int arg2idx;
} MULSTRUCT;

typedef struct DIVSTRUCT
{
  int idx;
	int arg1idx;
  int arg2idx;
} DIVSTRUCT;

typedef struct ADDSTRUCT
{
  int idx;
	int arg1idx;
  int arg2idx;
} ADDSTRUCT;

typedef struct SUBTSTRUCT
{
  int idx;
	int arg1idx;
  int arg2idx;
} SUBTSTRUCT;

typedef struct ENDSTRUCT
{

} ENDSTRUCT;

typedef struct tmpnScopeData
{
  tmpnStateMachine *stm;
  ARGSTRUCT arg;
  tmpnStateMachineValue *sampling;
} tmpnScopeData;



#ifdef __cplusplus
extern "C" {
#endif
  int staticforce(tmpnRobot *robot);
  int tmpnComputeIK(tmpnRobot *trobot, tmpnFloat wx, tmpnFloat wy, tmpnFloat wz, tmpnFloat wv, tmpnFloat ww, tmpnFloat wu, int tcpidx);
  int tmpnJointToActuator(tmpnRobot *robot,int tcpidx);
  int tmpnComputeFK(tmpnRobot *trobot, tmpnFloat a, tmpnFloat b, tmpnFloat c, tmpnFloat d, tmpnFloat e, tmpnFloat f, int tcpidx);
  int tmpnComputeFKlogic(tmpnRobot *trobot, tmpnFloat a, tmpnFloat b, tmpnFloat c, tmpnFloat d, tmpnFloat e, tmpnFloat f, int tcpidx);
  void solve(tmpnRobot *robot, int maxidx, tmpnPosition *position, tmpnFloat maxTime, tmpnFloat *maxSpeed, int order);
  void generatePath(tmpnRobot *tmpnrobot, tmpnPathDef *pathdef, tmpnPath *path);
  void copyPath(tmpnPath *dest, tmpnPath *source);
  void hackPositionHint(tmpnPath *path, tmpnPathDef *pathdef);
  void copyKeypoint(tmpnPath *path, tmpnPathDef *pathdef);
  //http://hyperphysics.phy-astr.gsu.edu/hbase/hframe.html
#ifdef __cplusplus
}
#endif
//data definitions (could be implemented in mysql)
#ifdef __cplusplus
extern "C" tmpnRobot *initrobot;
extern "C" volatile tmpnRobot *trobot;
extern "C" volatile tmpnWorkcell *tworkcell;
extern "C" tmpnPlant *tplant;
extern "C" int newtau;
extern "C" tmpnBoptCoeffItem coeff;
#else
tmpnRobot *initrobot;
volatile tmpnRobot *trobot;
volatile tmpnWorkcell *tworkcell;
tmpnPlant *tplant;
int newtau;
extern tmpnBoptCoeffItem coeff;
extern tmpnStateName stateName[];
#endif
#endif //TMPNROBOT_H
