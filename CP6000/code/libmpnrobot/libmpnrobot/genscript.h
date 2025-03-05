/****************************************************************************
* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include "tmpnrobot.h"
#ifdef __cplusplus
extern "C" {
#endif
#define FCONY(a,b,c) ((a)+robot->m_frames.frame[(c)].y-robot->m_frames.frame[(b)].y)
//#define FCONX(a,b,c) ((a)+robot->m_frames.frame[(c)].x-robot->m_frames.frame[(b)].x)
//#define FCONZ(a,b,c) ((a)+robot->m_frames.frame[(c)].z-robot->m_frames.frame[(b)].z)
//#define FCONV(a,b,c) ((a)+robot->m_frames.frame[(c)].v-robot->m_frames.frame[(b)].v)
//#define FCONW(a,b,c) ((a)+robot->m_frames.frame[(c)].w-robot->m_frames.frame[(b)].w)
//#define FCONU(a,b,c) ((a)+robot->m_frames.frame[(c)].u-robot->m_frames.frame[(b)].u)

//#define WORLDX(a,b) ((a)+robot->m_frames.frame[(b)].x)
//#define WORLDY(a,b) ((a)+robot->m_frames.frame[(b)].y)
//#define WORLDZ(a,b) ((a)+robot->m_frames.frame[(b)].z)

/* Trajectory types (for trajopt()) */
#define NOVIA 0
#define STARTVIA 1
#define ENDVIA 2
#define BOTHVIA 3

/* Macro types (for trajopt()) */

#define NOMACRO 0
#define SPIRAL 1
#define UPLINE 2
#define DOWNLINE 3
#define FASTUPLINE 4
#define FASTDOWNLINE 5

typedef struct macroparamstruct
{
  int type;
  tmpnFloat amplitude; //mm 
  tmpnFloat offsx; //mm
  tmpnFloat offsz; //mm
  tmpnFloat length; //mm
  tmpnFloat frequency; //Hz
  tmpnFloat time;     //sec
  int positionhint; //not used if = 0, if = 1: used at end of macro, if = 2: use at start of macro
} macroparamstruct;

  
  void convert(tmpnVector *wp, int fromIdx, tmpnFloat x, tmpnFloat y, tmpnFloat z, tmpnFloat v, tmpnFloat w, tmpnFloat u, int toIdx, tmpnRobot *robot);
  COMMANDSTRUCT *split(COMMANDSTRUCT *ptrcmd, tmpnFloat x0, tmpnFloat y0, tmpnFloat z0, tmpnFloat v0, tmpnFloat w0, tmpnFloat u0
		       ,tmpnFloat x1, tmpnFloat y1, tmpnFloat z1, tmpnFloat v1, tmpnFloat w1, tmpnFloat u1
		       ,int nos, int *level, const char *framename, const char *tcpname);
  COMMANDSTRUCT *convertsplit(COMMANDSTRUCT *ptrcmd, tmpnFloat x0, tmpnFloat y0, tmpnFloat z0, tmpnFloat v0, tmpnFloat w0, tmpnFloat u0
			      ,const char* fromFrame0, tmpnFloat x1, tmpnFloat y1, tmpnFloat z1, tmpnFloat v1, tmpnFloat w1, tmpnFloat u1
			      ,const char* fromFrame1, tmpnRobot *robot, int nos, int *level, const char *toFrame, const char *tcpname, int endpoint);
  COMMANDSTRUCT *spiralMacro(tmpnRobot *robot, tmpnPathDef *ptrpath, int* curidx, tmpnFloat A, tmpnFloat offsx, tmpnFloat offsz, tmpnFloat L, tmpnFloat f, tmpnFloat T, tmpnVector* pos, int nos, int TCPidx);
  inline tmpnFloat spiralspeed(tmpnFloat L, tmpnFloat T);
  COMMANDSTRUCT *uplineMacro(tmpnRobot *robot, tmpnPathDef *ptrpath, int* curidx, tmpnFloat L, tmpnFloat T, tmpnVector* pos, int nos, int TCPidx);
  inline tmpnFloat uplinespeed(tmpnFloat L, tmpnFloat T);
  COMMANDSTRUCT *downlineMacro(tmpnRobot *robot, tmpnPathDef *ptrpath, int* curidx, tmpnFloat L, tmpnFloat T, tmpnVector* pos, int nos, int TCPidx);
  inline tmpnFloat downlinespeed(tmpnFloat L, tmpnFloat T);
  void blendquintic(tmpnPathDef *ptrpath, int* curidx, tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* a1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnJointsUnion* a2, tmpnFloat ttime, int nos, int TCPidx, tmpnRobot *robot, int positionhint, int last);
  tmpnFloat blendquinticmaxvel(tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* a1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnJointsUnion* a2, tmpnFloat ttime, tmpnJointsUnion *mv);
  tmpnFloat blendquinticmaxacc(tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* a1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnJointsUnion* a2,tmpnFloat ttime,tmpnJointsUnion *ma);
  void blendcubic(tmpnPathDef *ptrpath, int* curidx, tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnFloat ttime, int nos, int TCPidx, tmpnRobot *robot, int positionhint, int last);
  tmpnFloat blendcubicmaxacc(tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnFloat ttime, tmpnJointsUnion *ma);
  tmpnFloat blendcubicmaxvel(tmpnJointsUnion* p1, tmpnJointsUnion* v1, tmpnJointsUnion* p2, tmpnJointsUnion* v2, tmpnFloat ttime, tmpnJointsUnion *mv);
  tmpnFloat trajopt(tmpnRobot *robot, tmpnPathDef *ptrpath, int pathidnum, int pathtype, int loadgroup, int trajectorytype, tmpnFloat samplerate, int fromTCPidx, int toTCPidx,tmpnJointsUnion* mv, tmpnJointsUnion* ma, tmpnVector* frompos, tmpnVector* fromvel, tmpnVector* topos, tmpnVector* tovel, tmpnDualVector* via1pos, tmpnVector* via1vel, tmpnDualVector* via2pos, tmpnVector* via2vel, macroparamstruct* startmacro, macroparamstruct* endmacro,int blendtype,float lockv);
	void jerkMinimizer(tmpnRobot *robot, tmpnPathDef *ptrpath, int tcpidx, int jerkscale);
  void expandBopt(tmpnRobot *robot, COMMANDSTRUCT* ptrcmd);
  void convertToFrame(tmpnVector *wp, int fromIdx, tmpnKeyPoint *p, int toIdx, tmpnRobot *robot);
  void convertToFrame_vectorstyle(tmpnVector *wp, tmpnFrame *fromF, tmpnVector *p, tmpnFrame *toF);
  void blendCorner3(tmpnRobot *robot, COMMANDSTRUCT *corner);
  void seekCorner(tmpnRobot *robot, COMMANDSTRUCT *corner, tmpnFloat rx, tmpnFloat rz);
  void seekCornerX(tmpnRobot *robot, COMMANDSTRUCT *corner, tmpnFloat rzminus, tmpnFloat rzplus, tmpnFloat rxminus, tmpnFloat rxplus);
  COMMANDSTRUCT *generateProgram(COMMANDSTRUCT *ptrcmd, tmpnRobot *robot, int *level, int layerHeightMM, int forceLayer, const char *ppscriptnameA);
  //rs302.c
  COMMANDSTRUCT *generateTomatProgram(COMMANDSTRUCT *ptrcmd, tmpnRobot *robot, int *level, const char *boxname, int dest, int numOfBoxes
				      , const char *patternname);
  //rs303.c
  COMMANDSTRUCT *generateFlamingoProgram(COMMANDSTRUCT *ptrcmd, tmpnRobot *robot, int *level, const char *boxname, int dest, int numOfBoxes
					 , const char *ppscriptnameA, const char *ppscriptnameB);
  //rs304.c
  COMMANDSTRUCT *generateProgramNS(COMMANDSTRUCT *ptrcmd, tmpnRobot *robot, int *level, int layerHeightMM, int forceLayer, const char *ppscriptnameA);
  COMMANDSTRUCT *expandPath304BoptHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPath304Bopt(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup, int layerHeightMM);
  //rs305.c
  COMMANDSTRUCT *generateProgramAlfredIn(COMMANDSTRUCT *ptrcmd, tmpnRobot *robot, int *level, int forceLayer, int forceItem, const char *ppscriptname);
  COMMANDSTRUCT *generateProgramAlfredOut(COMMANDSTRUCT *ptrcmd, tmpnRobot *robot, int *level, int forceLayer, int forceItem, const char *ppscriptname);
  COMMANDSTRUCT *expandSubPathAlfredOut(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  COMMANDSTRUCT *expandSubPathAlfredIn(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup); 
  COMMANDSTRUCT *expandPathAlfredBoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  COMMANDSTRUCT *expandPathAlfredBoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPathAlfredBoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);   
  void expandPathAlfredBoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);
  //rs306.c
  COMMANDSTRUCT *expandSubPathKatrineIn(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup); 
  COMMANDSTRUCT *expandSubPathKatrineOut(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  //rs307.c
  COMMANDSTRUCT *expandPath307BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  COMMANDSTRUCT *expandPath307BoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPath307BoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);   
  void expandPath307BoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);
  //rs308.c
  COMMANDSTRUCT *expandPath308BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  COMMANDSTRUCT *expandPath308BoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPath308BoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);   
  void expandPath308BoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);
  //rs309.c
  COMMANDSTRUCT *expandPath309BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  COMMANDSTRUCT *expandPath309BoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPath309BoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);   
  void expandPath309BoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);
  //rs310.c
  COMMANDSTRUCT *expandPath310BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  COMMANDSTRUCT *expandPath310BoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  COMMANDSTRUCT *expandPath310HybschABoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPath310BoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);   
  void expandPath310BoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPath310HybschABoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);
  //rs401.c
  COMMANDSTRUCT *expandPath401BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPath401BoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);
  //rs602.c
  COMMANDSTRUCT *expandPath602BoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  COMMANDSTRUCT *expandPath602BoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
  void expandPath602BoptIn(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);   
  void expandPath602BoptOut(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup);
	COMMANDSTRUCT *expandPathGeneralBoptInHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
	COMMANDSTRUCT *expandPathGeneralBoptOutHeader(tmpnRobot *robot, COMMANDSTRUCT *ptrcmd, int *level, int forceItem, const char *ppscriptname, int loadgroup);
	void expandPathBoptGeneral(tmpnRobot *robot, tmpnPathDef *ptrpath, int forceItem, const char *ppscriptname, int loadgroup, tmpnBoptCoeff* BoptCoeffs);
	int expandPathBoptGeneric(tmpnRobot *robot, tmpnPathDef *ptrpath, int cALayer, int cBLayer, int pathidx, tmpnFrame *fromFrame, tmpnFrame *toFrame, const char *startItem, const char *endItem, int loadgroup, int boptMode, int pathtype, tmpnBoptCoeff* BoptCoeffs);
	int expandBoptLoader(tmpnRobot *robot, tmpnPathItem *path);
#ifdef __cplusplus
}
#endif
