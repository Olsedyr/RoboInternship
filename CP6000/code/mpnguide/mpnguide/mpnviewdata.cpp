/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#include <qimage.h>
#include <qpainter.h>
#include <math.h>
#include <qtimer.h>
#include <qdatetime.h>
#include <qlabel.h>
#include <qinputdialog.h>
#include <GL/glu.h>
#include "mpnviewdata.h"
#include "mpnscript.h"
#include "mpntrackball.h"
#include "tmpnrobot.h"
#include "mpnview3d.h"
#define MSCALE 100.0
#define DSCALE 0.01
#define GSHINE 0.0
#define ROTATE_SPEED 1.0  // SPEED OF ROTATION
#define SCROLL_SPEED 1.0  // SPEED OF ROTATION
#define NUMOFSCALE 20

//static int timerId = 0;// timer interval (millisec)
//static int timer_interval = 50;// timer interval (millisec)
static float scaleTable[NUMOFSCALE]={1,2,4,5,10,20,40,50,100,200,400,500,1000,2000,4000,5000,10000,50000,100000,500000};
static int scaleIdx=3;

MPNViewData::MPNViewData( QWidget* parent, const char* name, QLabel *uw, QLabel *stat, MPNScript *script, const QGLWidget* shareWidget )
    : QGLWidget( parent, name, shareWidget )
{
  mpnscript = script;
  m_scaleX=1.0;
  m_yView = 0.0;
  m_xView = 0.0;
  m_ortoZoom=1.0;
  statusupper = uw;
  statusLower = stat;
  setMouseTracking( TRUE );
  setFocusPolicy( StrongFocus );

  actions.insert( Qt::Key_F1, keyScale );
  actions.insert( Qt::Key_F2, keyMoveX );
  actions.insert( Qt::Key_F3, keyTrack );
  actions.insert( Qt::Key_Left,  keyLeft );
  actions.insert( Qt::Key_Right, keyRight );
  wheelstates.insert( keyScale, glScale );
  wheelstates.insert( keyMoveX, glMoveX );
  m_scaleFactor = scaleTable[scaleIdx];
  m_wheelState = wheelstates[ keyScale ];
  m_track  = false;
  reset();
}

static GLfloat lightZeroPosition[] = {3.0, 10.0, 5.0, 1.0};
static GLfloat lightZeroColorA[] = {0.2, 0.2, 0.2, 1.0};
static GLfloat lightZeroColorD[] = {0.2, 0.2, 0.2, 1.0};
static GLfloat lightZeroColorS[] = {0.7, 0.7, 0.7, 1.0};

void MPNViewData::initializeGL()
{
  glEnable(GL_DEPTH_TEST);
//  glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
//  glBlendColor(0.9,0.9,0.9,0.9);
  glBlendFunc(GL_SRC_COLOR,GL_DST_COLOR);
//  glAlphaFunc(GL_ALWAYS,0.5);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
  /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 10000.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0, 0, m_zView,  /* eye is at (0,0,30) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);      /* up is in positive Y direction */

//  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
//  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
//  glEnable( GL_TEXTURE_2D );
//  glTexImage2D( GL_TEXTURE_2D, 0, 3, logoBits.width(), logoBits.height(), 0,
//	  GL_RGBA, GL_UNSIGNED_BYTE, logoBits.bits() );
	// Let OpenGL clear to black
  glClearColor( 0.0,0.0, 0.0, 0.0 ); // Let OpenGL clear to black

//  mpnscript->mpnrobot->makeMachine();

//  glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lmodel_ambient );
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
//  glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SINGLE_COLOR );
  glEnable(GL_LIGHTING);
//  glEnable(GL_COLOR_MATERIAL);
  glLightfv(GL_LIGHT0, GL_AMBIENT, lightZeroColorA);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColorD);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightZeroColorS);
  glLightfv(GL_LIGHT0, GL_POSITION, lightZeroPosition);
  glEnable(GL_LIGHT0);
  glShadeModel( GL_SMOOTH );
  glEnable(GL_CULL_FACE);
}

void MPNViewData::drawData(void)
{
/// Local Variables ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

  glDisable(GL_DEPTH_TEST);	// TURN OFF DEPTH TEST FOR CLEAR
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);	// ENABLE DEPTH TESTING
//  if(mpnscript->m_tpath==NULL) return;
  glPushMatrix();
  if(m_track)
  {
    glTranslatef(-mpnscript->m_playidx*m_scaleX*m_scaleFactor/mpnscript->m_tpath.maxidx,0.0,0.0);
    }
  //glTranslatef(0.0,-m_yView,0.0);
  //downscale to fit
  glScalef(2.0*gemw*m_scaleX*m_scaleFactor
	   ,m_scaleFactor*0.5,1.0);
  glTranslatef(-1.0/2-m_xView,-m_yView,0.0);
  if(mpnscript->m_showType==0) mpnscript->drawData();
  else if(mpnscript->m_showType==1) mpnscript->drawPos();
  else if(mpnscript->m_showType==2) mpnscript->drawSpeed();
  else if(mpnscript->m_showType==3) mpnscript->drawAccel();
  else if(mpnscript->m_showType==4) mpnscript->drawJerk();
  else if(mpnscript->m_showType==5) mpnscript->drawDyno();
  else if(mpnscript->m_showType==6) mpnscript->drawAxis(0);
  else if(mpnscript->m_showType==7) mpnscript->drawAxis(1);
  else if(mpnscript->m_showType==8) mpnscript->drawAxis(2);
  else if(mpnscript->m_showType==9) mpnscript->drawAxis(3);
  else if(mpnscript->m_showType==10) mpnscript->drawAxis(4);
  glPopMatrix();
  glFinish();
  QString s;
  
  if(mpnscript->m_showType==0) s.sprintf("Rated speed(pct) (a=%3.4f, b=%3.4f, c=%3.4f, d=%3.4f, e=%3.4f, f=%3.4f, t=%3.4f) %d %d %3.4f"
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].pctRatedSpeed.name.a
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].pctRatedSpeed.name.b
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].pctRatedSpeed.name.c
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].pctRatedSpeed.name.d
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].pctRatedSpeed.name.e
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].pctRatedSpeed.name.f
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].t
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].statehint
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].tcpidx
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].positionhint
  );
  else if(mpnscript->m_showType==1) s.sprintf("Pos(rad) (a=%3.4f, b=%3.4f, c=%3.4f, d=%3.4f, e=%3.4f, f=%3.4f) %d"
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].posRad.name.a
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].posRad.name.b
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].posRad.name.c
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].posRad.name.d
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].posRad.name.e
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].posRad.name.f
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].statehint
  );
  else if(mpnscript->m_showType==2) s.sprintf("Speed(rad/s) (a=%3.4f, b=%3.4f, c=%3.4f, d=%3.4f, e=%3.4f, f=%3.4f) %d"
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].speedRad.name.a
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].speedRad.name.b
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].speedRad.name.c
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].speedRad.name.d
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].speedRad.name.e
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].speedRad.name.f
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].statehint
  );
  else if(mpnscript->m_showType==3) s.sprintf("acceleration(rad/s^2) (a=%3.4f, b=%3.4f, c=%3.4f, d=%3.4f, e=%3.4f, f=%3.4f) %d"
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].accelRad.name.a
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].accelRad.name.b
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].accelRad.name.c
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].accelRad.name.d
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].accelRad.name.e
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].accelRad.name.f
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].statehint
  );
  else if(mpnscript->m_showType==4) s.sprintf("jerk(rad/s^3) (a=%3.4f, b=%3.4f, c=%3.4f, d=%3.4f, e=%3.4f, f=%3.4f) %d"
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].jerkRad.name.a
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].jerkRad.name.b
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].jerkRad.name.c
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].jerkRad.name.d
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].jerkRad.name.e
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].jerkRad.name.f
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].statehint
  );
  else if(mpnscript->m_showType==5) s.sprintf("torque(Nm) (%3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f) (%3.2f,%3.2f,%3.2f,%3.2f,%3.2f,%3.2f) %d"
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].force.name.a
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].force.name.b
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].force.name.c
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].force.name.d
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].force.name.e
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].force.name.f
    ,trobot->m_Trms.array[0]
    ,trobot->m_Trms.array[1]
    ,trobot->m_Trms.array[2]
    ,trobot->m_Trms.array[3]
    ,trobot->m_Trms.array[4]
    ,trobot->m_Trms.array[5]
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].statehint
  );
  else if(mpnscript->m_showType>5&&mpnscript->m_showType<11) s.sprintf("(pct),pos(rad),speed(rad/s),accel(rad/s^2),torque(Nm) %3.4f,%3.4f,%3.4f,%3.4f,%3.4f (%3.2f,%3.2f,%3.2f,%3.2f,%3.2f,%3.2f) %d %f"
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].pctRatedSpeed.array[mpnscript->m_showType-6]
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].posRad.array[mpnscript->m_showType-6]
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].speedRad.array[mpnscript->m_showType-6]
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].accelRad.array[mpnscript->m_showType-6]
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].force.array[mpnscript->m_showType-6]
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].taskSpace.x
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].taskSpace.y
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].taskSpace.z
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].taskSpace.v
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].taskSpace.w
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].taskSpace.u
    ,mpnscript->m_tpath.position[mpnscript->m_playidx].statehint
    ,trobot->m_lifeTimeGear.array[mpnscript->m_showType-6]
  );
  statusLower->setText(s);
}

MPNViewData::~MPNViewData()
{
  m_mousePressed=FALSE;
  makeCurrent();  // We're going to do gl calls
}



void MPNViewData::resizeGL( int width, int height )
{
  GLfloat aspect;
  glViewport(0, 0, width, height);
  aspect = (GLfloat)width/(GLfloat)height;
  gemw = (float) width / (float) height;
  gemh = 1.0;
  m_W=width;
  m_H=height;
  reset();
}


void MPNViewData::paintGL()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho( -m_ortoZoom*gemw, m_ortoZoom*gemw, -m_ortoZoom*gemh, m_ortoZoom*gemh, 0.1, 200000.0 );
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 1.0,
    0.0, 0.0, 0.0,
    0.0, 1.0, 0.0);
  drawData();
}

void MPNViewData::reset()
{
  scaleIdx=0;
  m_scaleFactor=scaleTable[scaleIdx];
  m_scaleX=1.0;
  m_yView = 0.0;
  m_xView = 0.0;
}

void MPNViewData::mousePressEvent( QMouseEvent *e )
{
  m_mousePressed = TRUE;
  m_presspos = e->pos();
  m_Grab_Trans_X = m_xView;
  m_Grab_Trans_Y = m_yView;
  m_Grab_Trans_Z = m_zView;
  float numOfIndexPrPixel = ((float)mpnscript->m_tpath.maxidx/m_W)/m_scaleFactor;
  mpnscript->setPlayIdx((int)((float)(/*m_xView+*/m_presspos.x())*numOfIndexPrPixel));
  refreshAll();  
}



void MPNViewData::mouseReleaseEvent( QMouseEvent * e )
{
	m_presspos = e->pos();
	m_mousePressed = FALSE;
//	releaseMouse();
}

void MPNViewData::doMouseThing()
{
}

void MPNViewData::deltaScaleFactor(int dif)
{
//  float oldScale = m_scaleFactor;
//  float oldxView = m_xView;
//  float oldyView = m_yView;
  if(dif>0) scaleIdx++;
  if(dif<=0) scaleIdx--;
  if(scaleIdx<0) scaleIdx=0;
  if(scaleIdx>=NUMOFSCALE) scaleIdx=NUMOFSCALE-1;
  m_scaleFactor = scaleTable[scaleIdx];

//  m_xView = oldxView - ;
  
  mpnscript->refreshAll(false);  //no need for generatePath
}

void MPNViewData::mouseMoveEvent( QMouseEvent *e )
{
  QString str;
//  float difx,dify,difz;

  if((e->state() & QMouseEvent::LeftButton) != 0)
  {
    if ((e->state() & QMouseEvent::ControlButton) != 0)
    {
      if ((e->pos().x() - m_presspos.x()) != 0)
      {
        m_xView = m_Grab_Trans_X - (e->pos().x() - m_presspos.x())*1000.0;
        
        refreshAll();        //no need for generatePath
      }
      if ((e->pos().y() - m_presspos.y()) != 0)
      {
        m_yView = m_Grab_Trans_Y + (float)((e->pos().y() - m_presspos.y())*2)/m_H;
        refreshAll();        //no need for generatePath
      }
      m_Grab_Trans_X = m_xView;
      m_Grab_Trans_Y = m_yView;
      m_Grab_Trans_Z = m_zView;
      m_presspos = e->pos();
    }
    else
    {
      m_presspos = e->pos();
      float numOfIndexPrPixel = ((float)mpnscript->m_tpath.maxidx/m_W)/m_scaleFactor;
      mpnscript->setPlayIdx((int)((float)(/*m_xView+*/m_presspos.x())*numOfIndexPrPixel));
//      refreshAll();
    }              
  }
}


void MPNViewData::refreshAll()
{
  updateGL();
}


void MPNViewData::wheelEvent( QWheelEvent *e )
{
  int dif;
  QString s;

  e->accept();
  if((e->state() & QWheelEvent::ShiftButton) != 0)
    dif = (int)e->delta()/120;
  else
    dif = (int)e->delta()/12;
  switch ( m_wheelState )
  {
    case glScale:
      if((e->state() & QWheelEvent::ControlButton) != 0)
      {
        m_scaleX = m_scaleX + dif;
        refreshAll();
      }
      else
      {
        if((e->state() & QWheelEvent::ShiftButton) != 0)
          deltaScaleFactor((int)e->delta()/12); //+-10
        else
          deltaScaleFactor((int)e->delta()/120); //+-1
      }
      break;
    case glMoveX:
        m_xView = m_xView + dif*1000.0;
        refreshAll();
      break;
    default:
      return;
  }
}

void MPNViewData::changeWheelState(int keyboardAction)
{
  m_wheelState = wheelstates[ keyboardAction ];
}


void MPNViewData::keyPressEvent( QKeyEvent *event )
{
  float dif;
//  int i;
  QString s;
  if ( /*event->isAutoRepeat() ||*/ !actions.contains( event->key() ) )
  {
    event->ignore();
    return;
  }

  if((event->state() & QKeyEvent::ShiftButton) != 0)
    dif = 1;
  else
    dif = 10;

  Action a = actions[ event->key() ];
  switch ( a )
  {
    case keyTrack:
      m_track=!m_track;
      refreshAll();
      break;
    case keyScale:
      changeWheelState(a);
      break;
    case keyMoveX:
      changeWheelState(a);
      break;
    default:
      mpnscript->mpnview3d->keyPressEvent(event);
//      event->ignore();
      return;
  }
  event->accept();
}

void MPNViewData::keyReleaseEvent( QKeyEvent *event )
{
  if ( event->isAutoRepeat() || !actions.contains( event->key() ) )
  {
    event->ignore();
    return;
  }
  Action a = actions[ event->key() ];
  switch ( a )
  {
    default:
      event->ignore();
      return;
  }
  event->ignore();
}

