
#ifndef __pptree_h
#define __pptree_h

#define NEW(type) (type*)malloc(sizeof(type))

typedef float REAL;

typedef struct PPSTRUCT {
  int lineno;
  int numV; 
  char *name;
  int type; 
  int itprlay; 
  int layers; 
  struct MOVE_LIST *move_list;    
} PPSTRUCT;

typedef struct MOVE_LIST {
  int lineno;
  enum {move_listK,emptymove_listK} kind;
  struct MOVE_LIST *move_list; 
  struct MOVEDEC *movedec;
} MOVE_LIST;

typedef struct MOVEDEC {
  int lineno;
  char *item; 
  int idxlayer; 
  int idxnum; 
  struct FRAME *fromframe; 
  struct STARTMACRO *startmacro; 
  struct VIAP *startvia; 
  struct FRAME *toframe; 
  struct ENDMACRO *endmacro; 
  struct VIAP *endvia; 
  struct OPT_WITH *opt_with;
} MOVEDEC;

typedef struct FRAME {
  int lineno;
  enum {frameK,framerelK} kind;
  union {
    struct {char *id;} frameF;
    struct {char *id; struct SIXNUMS *sixnums;} framerelF; 
  } val;
} FRAME;

typedef struct VIAP {
  int lineno;
  enum {viaK,emptyviaK} kind;
  struct SIXNUMS *posnums;
  struct SIXNUMS *velnums;
} VIAP;

typedef struct STARTMACRO {
  int lineno;
  enum {uplinestartmacroK,emptystartmacroK} kind;
  union {
    struct {REAL length;REAL time;} uplineM; 
  } val;
} STARTMACRO;

typedef struct ENDMACRO {
  int lineno;
  enum {downlineendmacroK,spiralendmacroK,emptyendmacroK} kind;
  union {
    struct {REAL length;REAL time;} downlineM; 
    struct {REAL amplitude; REAL offsx; REAL offsz; REAL length; REAL freq; REAL time;} spiralM; 
  } val;
} ENDMACRO;

typedef struct OPT_WITH {
  int lineno;
  enum {paramopt_withK,defaultsopt_withK} kind;
  struct PARAMLIST *paramlist;
} OPT_WITH;

typedef struct PARAMLIST {
  int lineno;
  enum {paramlist_paramlistK,param_paramlistK} kind;
  struct PARAMLIST *paramlist;
  struct PARAM *param;
} PARAMLIST;

typedef struct PARAM {
  int lineno;
  enum {quinticparamK,cubicparamK,positionhintparamK,maxvelparamK,maxaccparamK,samplerateparamK} kind;
  union {
    REAL positionhinttime;
    struct SIXNUMS *maxvel;
    struct SIXNUMS *maxacc;
    REAL samplerate;
  } val;
} PARAM;

typedef struct SIXNUMS {
  int lineno;
  REAL nums[6];
} SIXNUMS;

PPSTRUCT *makePP(int numV,char *name,int type,int itemsprlayer,int layers,MOVE_LIST *move_list);
MOVE_LIST *makeMOVE_LIST(MOVE_LIST *move_list,MOVEDEC *movedec);
MOVE_LIST *makeMOVE_LISTempty();
MOVEDEC *makeMOVEDEC(char *item,int idxlayer,int idxnum,FRAME *fromframe,STARTMACRO *startmacro,VIAP *startvia,FRAME *toframe,ENDMACRO *endmacro,VIAP *endvia,OPT_WITH *opt_with);
FRAME *makeFRAME(char *id);
FRAME *makeFRAMErel(char *id,SIXNUMS *f);
VIAP *makeVIA(SIXNUMS *pos,SIXNUMS *vel);
VIAP *makeVIAempty();
STARTMACRO *makeSTARTMACROupline(REAL length,REAL time);
STARTMACRO *makeSTARTMACROempty();
ENDMACRO *makeENDMACROdownline(REAL length,REAL time);
ENDMACRO *makeENDMACROspiral(REAL amplitude, REAL offsx, REAL offsz, REAL length, REAL freq, REAL time);
ENDMACRO *makeENDMACROempty();
OPT_WITH *makeOPT_WITHparamlist(PARAMLIST *pl);
OPT_WITH *makeOPT_WITHdefaults();
PARAMLIST *makePARAMLISTparamlist(PARAMLIST *pl,PARAM *p);
PARAMLIST *makePARAMLISTparam(PARAM *p);
PARAM *makePARAMquintic();
PARAM *makePARAMcubic();
PARAM *makePARAMpositionhint(REAL poshinttime);
PARAM *makePARAMmaxvel(SIXNUMS *maxvel);
PARAM *makePARAMmaxacc(SIXNUMS *maxacc);
PARAM *makePARAMsamplerate(REAL samplerate);
SIXNUMS *makeSIXNUMS(REAL a, REAL b,REAL c, REAL d, REAL e, REAL f);
REAL makeREALnum(int i);
REAL makeREALfloating(float f);

#endif /* pptree_h */
