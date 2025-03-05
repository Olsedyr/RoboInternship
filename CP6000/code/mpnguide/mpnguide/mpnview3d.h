/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#ifndef MPNVIEW3D_H
#define MPNVIEW3D_H

#include <qgl.h>
#include <qimage.h>
#include <qlistbox.h>
#include <qlabel.h>
#include <qmap.h>
#include "mpncommand.h"
#include "mpnscript.h"

class MPNView3D : public QGLWidget
{
    Q_OBJECT

public:

    MPNView3D( QWidget* parent, const char* name, QLabel *statusupper=NULL, QLabel *statusupper2=NULL, QLabel *statuslower=NULL, MPNScript *mpnscript=NULL, const QGLWidget* shareWidget=0 );
    ~MPNView3D();

public slots:
  void drawScene(void);
  void mouseMoveEvent( QMouseEvent *e );
  void mousePressEvent( QMouseEvent *e );
  void mouseReleaseEvent( QMouseEvent *e );
  void reset();
  void resetViewXY();
  void resetViewYZ();
  void resetViewXZ();
  void setOrto(bool value);
  void setMaterial(bool value);
  void refreshAll();
public:
  void setSplineOrder();
  void adjustPoint(float difx, float dify, float difz, float difv, float difw, float difu, float dift);
  void setTime(MPNCommand *item);
  void deltaScaleFactor(int dif);
  void wheelEvent( QWheelEvent * );
  void initializeGL();
  void paintGL();
  void resizeGL( int w, int h );
  void doMouseThing();
  void makeMachine();
  void makeMachine2();
  void timerEvent( QTimerEvent *);

  enum Action { keyPageUp,keyPageDown,keyToolState,keyTool,keySplineOrder, keyShowWhite, keyTanRotX, keyTanRotY, keyTanScale, keyDrawScript, keyShowPoint, keyPickPlace, keySample, keyPath, keyQuit, keyScale, keyMoveX, keyMoveY
								, keyMoveU,  keyShow,  keyMoveV,  keyMoveW, keyMoveT, keyTCP, keyResetXY,keyResetYZ,keyResetXZ,keyPIP
              , keyLeft, keyRight, keyUp, keyDown, keyAdjust, keyEscape, keyZoomZ, keyNewtau};
  QMap<int,Action> actions;

  enum wheelState { glTanRotX, glTanRotY, glTanScale, glScale, glMoveX, glMoveY, glMoveZ, glMoveV, glMoveW, glMoveU, glMoveT, glZoomZ  };
  QMap<int,wheelState> wheelstates;
  void changeWheelState(int keyboardAction);
  void keyPressEvent( QKeyEvent *event );
  void keyReleaseEvent( QKeyEvent *event );

	int			  viewActive;
	float	  	scaleFactor;
  QImage  logoBits;
  GLfloat   gemw;
  GLfloat   gemh;
	int			  W;
  int       H;
  GLint		  plane;

  float     m_Grab_Rot_X,m_Grab_Rot_Y,m_Grab_Rot_Z;
  float     m_Grab_Trans_X,m_Grab_Trans_Y,m_Grab_Trans_Z;
  int       m_scaleFactor;
  int       m_wheelState;
  QPoint    m_presspos;
  QPoint    m_oldpresspos;
  bool      m_mousePressed;
  float     m_ortoZoom;
  bool      m_orto;
  bool      m_material;
  int       m_showWhite;
  bool      m_drawScript;
  bool      m_adjust;
  float     m_xView,m_yView,m_zView;
  float     m_xRot,m_yRot,m_zRot;
  float     m_curquat[4];
  float     m_lastquat[4];
  bool      m_pip; // picture in picture

  MPNScript *mpnscript;
  QLabel    *statusupper;
  QLabel    *statusupper2;
  QLabel    *statuslower;


};


#endif
