/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#ifndef MPNSCRIPT_H
#define MPNSCRIPT_H

#include <qwidget.h>
#include <qlistbox.h>
#include <qlistview.h>
#include <qptrlist.h>
#include "mpncommand.h"
#include "tmpnrobot.h"

class QLabel;
class MPNCommand;
class MPNView3D;
class MPNViewData;
//class QListViewItemIterator;
//LVclass MPNScript : public QListView  {
class MPNScript : public QListView  {
   Q_OBJECT
public slots:
  void draw1000Nm(void);
  void drawData(void);
  void drawDyno(void);
  void drawAccel(void);
  void drawJerk(void);
  void drawSpeed(void);
//  void drawScript(void);
  void drawPos(void);
  void drawAxis(int axis);

  void Play(void);
  void setTimeScale(int timescale);
  void setMaxSamples(int maxsamples);
  void setHeightMM(int value);
  void setCoeffIdx(int value);
  void setCoeffType(int value);
  void setToPatternIdx(int value);
  void setFromPatternIdx(int value);


  void setPlayIdx(int i);
  void setPlayIdx(float x, float y, float z, float v, float w, float u);

  void setSelectedIdx(int );
  void removeLast();
  void reset();
  void simulateTRIO();
//  MPNCommand *newSample(QString s, int *level);
  MPNCommand *newCommand(COMMANDSTRUCT *cmd);
  MPNCommand *newRunCommand(COMMANDSTRUCT *cmd);
  void loadPlant();
  void savePlant();
  void saveAsPlant();
  void saveScript();
  void saveAsScript();
  void refreshAll(bool generate);
  void refreshAllPoints();
//  void saveCoeffs();
  void refreshCoeffs();
  void expandPath();
  void newPath();
  void newBoptItem();
  void newSample();
  void newPause();
  void newProgram();
  void newTomatProgram();
  void newFlamingoProgram();
  void generatePalletProgram();
  void compileProgram();
  void newScript();

  void selectCell();
  void SelectRobot();

  void loadScope();
  void loadScript();
  void loadScript( const char *fileName );
  
  void boptlistSelectedItem( QListBoxItem* i);
  void listBoxItemSelected( QListViewItem* i);
  void miniStep( int stepsize );
  void timerEvent( QTimerEvent *);
public: 
  MPNScript(QWidget *parent=0, const char *name=0);
  ~MPNScript();
  float pathLength(int i);
  float pathLength();

  MPNView3D   *mpnviewxy;
  MPNView3D   *mpnview3d;
  MPNViewData *mpnviewdata;
  MPNViewData *mpnviewdyno;
  QString     filename;
  QString     plantname;
  bool        m_play;
  bool        m_playAll;
  tmpnFloat   m_sumtime;
  int         m_showType;

  int         m_maxSamples;
  int         m_coeffType;
  int         m_coeffIdx;
  int         m_maxCoeffIdx;
  int         m_playidx;
  QString     m_coeff;
  QLabel      *statuslower;
  COMMANDSTRUCT *m_runcmd;
  PATHSTRUCT  *m_path;
  tmpnPath    m_tpath;
  tmpnPath    m_ipath;
  tmpnScope   m_scope;
  tmpnBoptCoeffItem *m_boptcoeffitem;
  int         m_fromPatternIdx;
  int         m_toPatternIdx;
  int         m_fromPatternID;
  int         m_toPatternID;
  tmpnItem    *m_fromItem;
  tmpnItem    *m_toItem;
  tmpnPattern *m_fromPattern;
  tmpnPattern *m_toPattern;
  tmpnFrame   *m_fromFrame;
  tmpnFrame   *m_toFrame;
};

#endif
