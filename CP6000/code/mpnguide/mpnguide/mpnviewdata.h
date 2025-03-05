/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#ifndef MPNVIEWDATA_H
#define MPNVIEWDATA_H

#include <qgl.h>
#include <qimage.h>
#include <qlistbox.h>
#include <qlabel.h>
#include <qmap.h>
#include "mpncommand.h"
#include "mpnscript.h"


class MPNViewData : public QGLWidget
{
    Q_OBJECT

public:

    MPNViewData( QWidget* parent, const char* name, QLabel *usedWire=NULL, QLabel *statuslower=NULL, MPNScript *mpnscript=NULL, const QGLWidget* shareWidget=0 );
    ~MPNViewData();

public slots:
  void mouseMoveEvent( QMouseEvent *e );
  void mousePressEvent( QMouseEvent *e );
  void mouseReleaseEvent( QMouseEvent *e );
  void refreshAll();
  void reset();
public:
  void drawData(void);
  void wheelEvent( QWheelEvent * );
  void initializeGL();
  void paintGL();
  void resizeGL( int w, int h );
  void deltaScaleFactor(int dif);
  void doMouseThing();
//  void makeCoord();
  enum Action { keyShow, keyTrack, keyScale, keyMoveX, keyLeft, keyRight};
  QMap<int,Action> actions;
  enum wheelState { glScale, glMoveX };
  QMap<int,wheelState> wheelstates;
  void changeWheelState(int keyboardAction);
  void keyPressEvent( QKeyEvent *event );
  void keyReleaseEvent( QKeyEvent *event );



  float     m_scaleX;
  GLfloat   gemw;
  GLfloat   gemh;
  bool      m_track;
  float     m_W;
  float     m_H;
  float     m_ortoZoom;
  float     m_xView,m_yView,m_zView;
  float     m_Grab_Trans_X,m_Grab_Trans_Y,m_Grab_Trans_Z;

  
  float     m_scaleFactor;
  int       m_wheelState;
  QPoint    m_presspos;
  QPoint    m_oldpresspos;
  bool      m_mousePressed;
  MPNScript *mpnscript;
  QLabel    *statusupper;
  QLabel    *statusLower;
};


#endif
