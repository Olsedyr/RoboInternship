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
#include "mpnview3d.h"
#include "mpnscript.h"
#include "mpntrackball.h"
#include "cmd.h"
#include "scene.h"


//for opengl 3D drawing
///*void makeCoord(); //compile
void drawSceneGL(int drawWhite, MPNScript *mpnscript);
//void drawPlayidxGL(tmpnPath *path, int idx);*/

#define MSCALE 100.0
#define DSCALE 0.01
#define GSHINE 0.0
#define ROTATE_SPEED 1.0  // SPEED OF ROTATION
#define SCROLL_SPEED 5.0  // SPEED OF ROTATION
#define NUMOFSCALE 20

static bool dirty=false;
static QTime movetime;
static int timerId = 0;// timer interval (millisec)
static int timer_interval = 0;// timer interval (millisec)
static int scaleTable[NUMOFSCALE]={1,2,4,5,10,20,40,50,100,200,400,500,1000,2000,4000,5000,10000,50000,100000,500000};
static int scaleIdx=5;

MPNView3D::MPNView3D( QWidget* parent, const char* name, QLabel *uw, QLabel *uw2, QLabel *stat, MPNScript *script, const QGLWidget* shareWidget )
    : QGLWidget( parent, name, shareWidget )
{
	mpnscript = script;
  statusupper = uw;
  statusupper2 = uw2;
  statuslower = stat;
  mpnscript->statuslower = stat;
  setMouseTracking( TRUE );
  setFocusPolicy( StrongFocus );

  actions.insert( Qt::Key_K, keyPickPlace );
  actions.insert( Qt::Key_S, keySample );
  actions.insert( Qt::Key_P, keyPath );
  actions.insert( Qt::Key_O, keySplineOrder );
  actions.insert( Qt::Key_T, keyTanScale );
  actions.insert( Qt::Key_Q, keyQuit );
  actions.insert( Qt::Key_A, keyAdjust );
  actions.insert( Qt::Key_Z, keyZoomZ );
  actions.insert( Qt::Key_X, keyDrawScript );
  actions.insert( Qt::Key_V, keyShowPoint );
  actions.insert( Qt::Key_W, keyShowWhite );
  actions.insert( Qt::Key_F1, keyScale );
  actions.insert( Qt::Key_F2, keyMoveX );
  actions.insert( Qt::Key_F3, keyMoveY );
  actions.insert( Qt::Key_F4, keyShow );
  actions.insert( Qt::Key_F5, keyMoveV );
  actions.insert( Qt::Key_F6, keyMoveW );
  actions.insert( Qt::Key_U, keyMoveU );
  actions.insert( Qt::Key_F7, keyMoveT );
  actions.insert( Qt::Key_F8, keyTCP );
  actions.insert( Qt::Key_F9, keyToolState );
  actions.insert( Qt::Key_F10, keyResetXY );
  actions.insert( Qt::Key_F11, keyResetYZ );
  actions.insert( Qt::Key_F12, keyResetXZ );
	actions.insert( Qt::Key_M, keyPIP );
  actions.insert( Qt::Key_Left,  keyLeft );
  actions.insert( Qt::Key_Right, keyRight );
  actions.insert( Qt::Key_Up,    keyUp );
  actions.insert( Qt::Key_Down,  keyDown );
  actions.insert( Qt::Key_PageUp,    keyPageUp );
  actions.insert( Qt::Key_PageDown,  keyPageDown );
  actions.insert( Qt::Key_Escape, keyEscape );
  actions.insert( Qt::Key_N, keyNewtau );
//  actions.insert( Qt::Key_PageUp, keyPageUp );
//  actions.insert( Qt::Key_PageDown, keyPageDown );

  wheelstates.insert( keyTanScale, glTanScale );
  wheelstates.insert( keyScale, glScale );
  wheelstates.insert( keyMoveX, glMoveX );
  wheelstates.insert( keyZoomZ, glZoomZ );
  wheelstates.insert( keyMoveY, glMoveY );
  wheelstates.insert( keyMoveV, glMoveV );
  wheelstates.insert( keyMoveW, glMoveW );
  wheelstates.insert( keyMoveU, glMoveU );
  wheelstates.insert( keyMoveT, glMoveT );

  m_scaleFactor = scaleTable[scaleIdx];
  m_wheelState = wheelstates[ keyScale ];

  reset();
  m_orto=true;
  m_adjust=false;
  m_material=true;
  m_showWhite=1;
  m_drawScript=true;
  m_pip=false;
  movetime.restart();
}

static GLfloat lightZeroPosition[] = {6000.0, 1500.0, 6000.0, 1.0};
static GLfloat lightZeroColorA[] = {0.5, 0.5, 0.5, 1.0};
static GLfloat lightZeroColorD[] = {0.1, 0.1, 0.1, 1.0};
static GLfloat lightZeroColorS[] = {0.3, 0.3, 0.3, 1.0};

void MPNView3D::initializeGL()
{
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_BLEND);
  glBlendColor(0.9,0.9,0.9,0.9);
  //glBlendFunc(GL_SRC_COLOR,GL_DST_COLOR);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glAlphaFunc(GL_GREATER,0.05);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
  /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 10000.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0, 0, m_zView,  /* eye is at (0,0,30) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);      /* up is in positive Y direction */
  glClearColor( 0.0,0.0, 0.0, 0.0 ); // Let OpenGL clear to black
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
  glEnable(GL_LIGHTING);
  glLightfv(GL_LIGHT0, GL_AMBIENT, lightZeroColorA);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColorD);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightZeroColorS);
  glLightfv(GL_LIGHT0, GL_POSITION, lightZeroPosition);
  glEnable(GL_LIGHT0);
  glShadeModel( GL_SMOOTH );
  glEnable(GL_CULL_FACE);
  timerId = startTimer( timer_interval ); //animation
}

void MPNView3D::drawScene(void)
{
/// Local Variables ///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
  GLfloat m[4][4];

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if(m_orto)
  {
    glOrtho( -m_ortoZoom*gemw, m_ortoZoom*gemw, -m_ortoZoom*gemh, m_ortoZoom*gemh, 0.1, 50000.0 );
  }
  else
  {
    glFrustum( -gemw, gemw, -gemh, gemh, 5.0, 40000.0 );
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  {
    gluLookAt(m_xView, m_yView, m_zView, //eye
              m_xView, m_yView, 0.0, //center
              0.0, 1.0, 0.);
  }
  build_rotmatrix(m, m_curquat);
  glMultMatrixf(&m[0][0]);
  glEnable(GL_NORMALIZE);
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glRotatef( m_xRot, 1.0, 0.0, 0.0 );
  glRotatef( m_yRot, 0.0, 1.0, 0.0 );
  glRotatef( m_zRot, 0.0, 0.0, 1.0 );
  
  glDisable(GL_DEPTH_TEST);	// TURN OFF DEPTH TEST FOR CLEAR
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);	// ENABLE DEPTH TESTING
  glPushMatrix();
	glScalef((float)m_scaleFactor*DSCALE,(float)m_scaleFactor*DSCALE,(float)m_scaleFactor*DSCALE);
	if(m_drawScript)
		drawSceneGL(m_showWhite,mpnscript);
	else
		drawSceneGL(false,NULL);
  glPopMatrix();
  glFinish();

  QString s;
  int maxidx=0,nos,hpoint0,hpoint1;
//  if(mpnscript->m_path!=NULL)
  maxidx=mpnscript->m_tpath.maxidx;
  if(mpnscript->m_path!=NULL&&maxidx!=0)
  {
    nos = (int)(maxidx*1000/mpnscript->m_path->tpathdef.maxTime);
    hpoint0 = mpnscript->m_path->tpathdef.hpoint[0].time;
    hpoint1 = mpnscript->m_path->tpathdef.hpoint[1].time;
  }
//  s.sprintf("%3.2f,%3.2f,%3.2f,%3.2f,%3.2f -> %f,%f,%f,%f,%f SCALE=%f z%3.0f cambox=%d pos/sec %d"
  if(maxidx==0) maxidx=1;
           
  s.sprintf("%3.2f,%3.2f,%3.2f,%3.2f,%3.2f,%3.2f -> %3.2f,%3.2f,%3.2f,%3.2f,%3.2f,%3.2f cambox=%d pos/sec %d h0=%d h1=%d,t=%d"
      ,trobot->m_worldPoint.x
      ,trobot->m_worldPoint.y
      ,trobot->m_worldPoint.z
      ,trobot->m_worldPoint.v
      ,trobot->m_worldPoint.w
      ,trobot->m_worldPoint.u
      ,trobot->m_actuator.a
      ,trobot->m_actuator.b
      ,trobot->m_actuator.c
      ,trobot->m_actuator.d
      ,trobot->m_actuator.e
      ,trobot->m_actuator.f
//      ,MSCALE/(float)m_scaleFactor,m_ortoZoom
      ,maxidx,nos
//      ,mpnscript->m_tpath.position[mpnscript->m_playidx].t
      ,mpnscript->m_playidx*1000000/maxidx
      ,hpoint0
      ,hpoint1
      );
      statusupper->setText(s);

      staticforce((tmpnRobot*)trobot);
  s.sprintf("jointspace: %3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f   static: %3.4f,%3.4f,%3.4f,%3.4f,%3.4f,%3.4f"
      ,trobot->m_joint.a
      ,trobot->m_joint.b
      ,trobot->m_joint.c
      ,trobot->m_joint.d
      ,trobot->m_joint.e
      ,trobot->m_joint.f
      ,trobot->m_staticForce.name.a
      ,trobot->m_staticForce.name.b
      ,trobot->m_staticForce.name.c
      ,trobot->m_staticForce.name.d
      ,trobot->m_staticForce.name.e
      ,trobot->m_staticForce.name.f
      );
      statusupper2->setText(s);
}

MPNView3D::~MPNView3D()
{
	m_mousePressed=FALSE;
    makeCurrent();				// We're going to do gl calls

}



void MPNView3D::resizeGL( int width, int height )
{
  GLfloat aspect;
  glViewport(0, 0, width, height);
  aspect = (GLfloat)width/(GLfloat)height;
  gemw = (float) width / (float) height;
  gemh = 1.0;
  W=width;
  H=height;
}


void MPNView3D::paintGL()
{
  if(m_pip == true)
  {
    glEnable(GL_SCISSOR_TEST);
    glMatrixMode(GL_MODELVIEW);
    
    glViewport(0,0,W,H);
    glScissor(0,0,W,H);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    drawScene();
    
    glViewport(0,0,W/2,H/2);
    glScissor(0,0,W/2,H/2);
    glLoadIdentity();
    float t=m_yRot;
    m_yRot -= 90;
    //glRotatef(90,0.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    drawScene();
    m_yRot = t;
  }
  else
  {
    glDisable(GL_SCISSOR_TEST);
    glViewport(0,0,W,H);
    glLoadIdentity();
    drawScene();
  }
}

void MPNView3D::reset()
{
  scaleIdx=7;
  m_scaleFactor=scaleTable[scaleIdx];
  m_xRot = 0.0;
  m_yRot = 0.0;
  m_zRot = 0.0;
  m_xView = 0.0;
  m_yView = 0.0;
  m_zView = 5000.0;
  m_ortoZoom=1500.0;
  trackball(m_curquat, 0.0, 0.0, 0.0, 0.0);
}

void MPNView3D::resetViewXY()
{
  scaleIdx=8;
  m_scaleFactor=scaleTable[scaleIdx];
  m_xRot = 0.0;
  m_yRot = 0.0;
  m_zRot = 0.0;
  m_xView = 0.0;
  m_yView = 0.0;
  trackball(m_curquat, 0.0, 0.0, 0.0, 0.0);
  mpnscript->refreshAll(false);
}
void MPNView3D::resetViewYZ()
{
  scaleIdx=8;
  m_scaleFactor=scaleTable[scaleIdx];
  m_xRot = 0.0;
  m_yRot = -90.0;
  m_zRot = 0.0;
  m_xView = 0.0;
  m_yView = 0.0;
  trackball(m_curquat, 0.0, 0.0, 0.0, 0.0);
  mpnscript->refreshAll(false);
}
void MPNView3D::resetViewXZ()
{
  scaleIdx=8;
  m_scaleFactor=scaleTable[scaleIdx];
  m_xRot = 90.0;
  m_yRot = 90.0;
  m_zRot = 0.0;
  m_xView = 0.0;
  m_yView = 0.0;
  trackball(m_curquat, 0.0, 0.0, 0.0, 0.0);
  mpnscript->refreshAll(false);
}
void MPNView3D::setOrto(bool value)
{
  m_orto=value;
  mpnscript->refreshAll(false);
}
void MPNView3D::setMaterial(bool value)
{
  m_material=value;

  if(m_material)
  {
    glEnable(GL_LIGHTING);
//    glEnable(GL_COLOR_MATERIAL);
 }
  else
  {
    glDisable(GL_LIGHTING);
//    glDisable(GL_COLOR_MATERIAL);
  }
  refreshAll();
}

/*!
  Set up the OpenGL view port, matrix mode, etc.
*/
void MPNView3D::setTime( MPNCommand * item)
{
//    bool ok;
    if(item==NULL) return;
/*    double res = QInputDialog::getDouble(
            "Time", "Enter ms as decimal number:", item->p.tan, 0,
            9999, 2, &ok, this );
    if ( ok ) {
        item->p.tan=res;
        item->refresh();
        //need for generatePath
        mpnscript->refreshAll(true);
    } else {
        // user pressed Cancel
    }                         */
}

void MPNView3D::setSplineOrder()
{
    bool ok;
    int res = QInputDialog::getInteger(
            "Spline order", "Enter a number:", 4, 1, 7, 1,
            &ok, this );
    trobot->splineorder = res;
    res = QInputDialog::getInteger(
            "Trajectory type", "Enter a number:", 8, 0, 20, 1,
            &ok, this );
    trobot->splinehint = res;
    adjPath(mpnscript->m_path);
    generatePath((tmpnRobot*)trobot,&mpnscript->m_path->tpathdef, &mpnscript->m_tpath);
    mpnscript->refreshAll(false);
}

void MPNView3D::mousePressEvent( QMouseEvent *e )
{
  //grabMouse( crossCursor );
  m_mousePressed = TRUE;
  m_presspos = e->pos();
  m_Grab_Trans_X = m_xView;
  m_Grab_Trans_Y = m_yView;
  m_Grab_Trans_Z = m_zView;
}



void MPNView3D::mouseReleaseEvent( QMouseEvent * e )
{
  m_presspos = e->pos();
  m_mousePressed = FALSE;
  //releaseMouse();
  if(dirty)
  {
    mpnscript->refreshAll(false);
    dirty=false;
  }
}

void MPNView3D::doMouseThing()
{
}
void MPNView3D::deltaScaleFactor(int dif)
{
  if(dif>0) scaleIdx++;
  if(dif<=0) scaleIdx--;
  if(scaleIdx<0) scaleIdx=0;
  if(scaleIdx>=NUMOFSCALE) scaleIdx=NUMOFSCALE-1;
  m_scaleFactor = scaleTable[scaleIdx];
  mpnscript->refreshAll(false);  //no need for generatePath
}

void MPNView3D::mouseMoveEvent( QMouseEvent *e )
{
  QString str;
  float difx,dify,difz;

  if((e->state() & QMouseEvent::LeftButton) != 0)
  {
    if ((e->state() & QMouseEvent::ControlButton) != 0
      ||(e->state() & QMouseEvent::RightButton) != 0)
    {
      if ((e->pos().x() - m_presspos.x()) != 0)
      {
        m_xView = m_Grab_Trans_X - ((float)SCROLL_SPEED * (e->pos().x() - m_presspos.x()));
        refreshAll();        //no need for generatePath
      }
      if ((e->pos().y() - m_presspos.y()) != 0)
      {
        m_yView = m_Grab_Trans_Y + ((float)SCROLL_SPEED * (e->pos().y() - m_presspos.y()));
        refreshAll();        //no need for generatePath
      }
      m_Grab_Trans_X = m_xView;
      m_Grab_Trans_Y = m_yView;
      m_Grab_Trans_Z = m_zView;
      m_presspos = e->pos();
    }
    else
    {
      trackball(m_lastquat,(2.0 * m_presspos.x() - W) / W,(H - 2.0 * m_presspos.y()) / H
        ,(2.0 * e->pos().x() - W) / W,(H - 2.0 * e->pos().y()) / H);
      m_presspos = e->pos();
      add_quats(m_lastquat, m_curquat, m_curquat);
      refreshAll();
    }
  }
  // IF YOU CLICK ANYWHERE, SOLVE THE SYSTEM
  if((e->state()&QMouseEvent::ShiftButton)==0
   &&(e->state()&QMouseEvent::RightButton)!=0)
  {
    difx = e->pos().x() - m_presspos.x();
    dify = e->pos().y() - m_presspos.y();
    adjustPoint(difx*2.5,-dify*2.5,0.0,0.0,0.0,0.0,0.0);
    m_presspos = e->pos();
  }
  if((e->state()&QMouseEvent::ShiftButton)!=0
   &&(e->state()&QMouseEvent::RightButton)!=0)
  {
    difz = e->pos().x() - m_presspos.x();
    adjustPoint(0.0,0.0,difz*2.5,0.0,0.0,0.0,0.0);
    m_presspos = e->pos();
  }
}


void MPNView3D::refreshAll()
{
  updateGL();
}

void MPNView3D::adjustPoint(float difx, float dify, float difz, float difv, float difw, float difu, float dift)
{
  MPNCommand* aitem;
  float samplePointX,samplePointY,samplePointZ,samplePointV,samplePointW,samplePointU,samplePointT;
  POINTSTRUCT *point;
//  tmpnPosition pos;
//LV  aitem = (MPNCommand*)mpnscript->item(mpnscript->currentItem());
  aitem = (MPNCommand*)mpnscript->currentItem();
  if(aitem!=NULL&&(aitem->cmd->type==POINT||aitem->cmd->type==HPOINT||aitem->cmd->type==RPOINT))
  {
    point=(POINTSTRUCT*)aitem->cmd->data;
    trobot->m_tcpidx=point->p.tcpidx;
  }
  samplePointX = trobot->m_worldPoint.x + difx*MSCALE/(float)m_scaleFactor;
  samplePointY = trobot->m_worldPoint.y + dify*MSCALE/(float)m_scaleFactor;
  samplePointZ = trobot->m_worldPoint.z + difz*MSCALE/(float)m_scaleFactor;
  samplePointV = trobot->m_worldPoint.v + difv*MSCALE/(float)m_scaleFactor;
  samplePointW = trobot->m_worldPoint.w + difw*MSCALE/(float)m_scaleFactor;
  samplePointU = trobot->m_worldPoint.u + difu*MSCALE/(float)m_scaleFactor;

  if(tmpnComputeIK((tmpnRobot*)trobot,samplePointX,samplePointY,samplePointZ,samplePointV,samplePointW,samplePointU,trobot->m_tcpidx))
  {
    if(m_adjust&&aitem!=NULL&&(aitem->cmd->type==POINT||aitem->cmd->type==HPOINT||aitem->cmd->type==RPOINT))
    {
      point=(POINTSTRUCT*)aitem->cmd->data;
      samplePointT = point->p.dt+dift*MSCALE/(float)m_scaleFactor;
      adjPoint(aitem->cmd
              ,trobot->m_worldPoint.x
              ,trobot->m_worldPoint.y
              ,trobot->m_worldPoint.z
              ,trobot->m_worldPoint.v
              ,trobot->m_worldPoint.w
              ,trobot->m_worldPoint.u
              ,samplePointT,point->p.tcpidx);
      mpnscript->m_path=point->path;
      adjPath(mpnscript->m_path);
      //TODO genrate only affected part of path
      generatePath((tmpnRobot*)trobot,&mpnscript->m_path->tpathdef, &mpnscript->m_tpath);
      aitem->refresh();
    }
    mpnscript->refreshAll(false);
  }
}

void MPNView3D::wheelEvent( QWheelEvent *e )
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
      if((e->state() & QWheelEvent::ShiftButton) != 0)
        deltaScaleFactor((int)e->delta()/12); //+-10
      else
        deltaScaleFactor((int)e->delta()/120); //+-1
      break;
    case glZoomZ:
        if(m_orto)
          m_ortoZoom = m_ortoZoom + dif*10.0;
        else
          m_zView = m_zView + dif*10.0;
        mpnscript->refreshAll(false);
      break;
    case glMoveX:
        adjustPoint(dif,0.0,0.0,0.0,0.0,0.0,0.0);
      break;
    case glMoveY:
        adjustPoint(0.0,dif,0.0,0.0,0.0,0.0,0.0);
      break;
    case glMoveZ:
        adjustPoint(0.0,0.0,dif,0.0,0.0,0.0,0.0);
      break;
    case glMoveV:
        adjustPoint(0.0,0.0,0.0,dif,0.0,0.0,0.0);
      break;
    case glMoveW:
        adjustPoint(0.0,0.0,0.0,0.0,dif,0.0,0.0);
      break;
    case glMoveU:
        adjustPoint(0.0,0.0,0.0,0.0,0.0,dif,0.0);
      break;
    case glMoveT:
        adjustPoint(0.0,0.0,0.0,0.0,0.0,0.0,dif);
      break;
    default:
      return;
  }
}

void MPNView3D::changeWheelState(int keyboardAction)
{
  m_wheelState = wheelstates[ keyboardAction ];
}


void MPNView3D::keyPressEvent( QKeyEvent *event )
{
  float dif;
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
    case keyTCP:
      trobot->m_tcpidx++;
      if(trobot->m_tcpidx>=MAXTCP)
        trobot->m_tcpidx=0;
      if(mpnscript->m_path)
      {
        generatePath((tmpnRobot*)trobot,&mpnscript->m_path->tpathdef, &mpnscript->m_tpath);
      }
      if(tmpnComputeIK((tmpnRobot*)trobot
                      ,trobot->m_worldPoint.x
                      ,trobot->m_worldPoint.y
                      ,trobot->m_worldPoint.z
                      ,trobot->m_worldPoint.v
                      ,trobot->m_worldPoint.w
                      ,trobot->m_worldPoint.u
                      ,trobot->m_tcpidx))
      {
      }
      mpnscript->refreshAll(false);
      break;
    case keyToolState:
      trobot->m_state++;
      if(trobot->m_state>MAXSTATE)
        trobot->m_state=0;
      if(mpnscript->m_path)
      {
        generatePath((tmpnRobot*)trobot,&mpnscript->m_path->tpathdef, &mpnscript->m_tpath);
      }
      mpnscript->refreshAll(false);
      break;
    case keySplineOrder:
      setSplineOrder();
      break;
    case keyShowPoint:
      trobot->m_showPoint++;
      if(trobot->m_showPoint>1) trobot->m_showPoint=0;
      mpnscript->refreshAllPoints();
      mpnscript->refreshAll(false);
      break;
    case keyShow:
      mpnscript->m_showType=mpnscript->m_showType+1;
      if(mpnscript->m_showType>9) mpnscript->m_showType=0;
      mpnscript->refreshAll(false);
      break;
    case keySample:
      mpnscript->newSample();
      mpnscript->refreshAll(false);
      break;
    case keyShowWhite:
      if(m_showWhite==1) m_showWhite=0; else m_showWhite=1; 
      refreshAll();
      break;
    case keyPickPlace:
//      mpnscript->scene->m_boxpicked=!mpnscript->scene->m_boxpicked;
      break;
    case keyDrawScript:
      m_drawScript=!m_drawScript;
      break;
    case keyPath:
      mpnscript->m_playAll=!mpnscript->m_playAll;
      break;
    case keyQuit:
      break;
    case keyScale:
      changeWheelState(a);
      break;
    case keyZoomZ:
      changeWheelState(a);
      break;
    case keyMoveX:
      changeWheelState(a);
      break;
    case keyMoveY:
      changeWheelState(a);
      break;
    case keyMoveV:
      changeWheelState(a);
      break;
    case keyMoveW:
      changeWheelState(a);
      break;
    case keyMoveU:
      changeWheelState(a);
      break;
    case keyMoveT:
      changeWheelState(a);
      break;
    case keyResetXY:
      resetViewXY();
      break;
    case keyResetYZ:
      resetViewYZ();
      break;
    case keyResetXZ:
			resetViewXZ();
      break;
	  case keyPIP:
			m_pip=!m_pip;
			refreshAll();
			break;
    case keyAdjust:
      m_adjust=!m_adjust;
      break;
    case keyEscape:
      m_adjust=false;
      break;
    case keyNewtau:
      if(newtau==1) newtau=0; else newtau=1;
      if(mpnscript->m_path)
      {
        generatePath((tmpnRobot*)trobot,&mpnscript->m_path->tpathdef, &mpnscript->m_tpath);
      }
      mpnscript->refreshAll(false);
      
      break;
    case keyRight:
        if((event->state() & QKeyEvent::AltButton) != 0)
        {
          adjustPoint(0.0,0.0,-dif,0.0,0.0,0.0,0.0);
        }
        else if((event->state() & QKeyEvent::ControlButton) == 0)
        {
          adjustPoint(-dif,0.0,0.0,0.0,0.0,0.0,0.0);
        }
        else
        {
          if((event->state() & QKeyEvent::ShiftButton) == 0)
          {
            MPNCommandIterator it((MPNCommand*)mpnscript->currentItem());
            if(it.current()) --it;
            while ( it.current() )
            {
              if(it.current()->cmd!=NULL&&(it.current()->cmd->type==POINT||it.current()->cmd->type==RPOINT||it.current()->cmd->type==EPOINT||it.current()->cmd->type==HPOINT))
              {
                mpnscript->setCurrentItem(it.current());
                break;
              }
              it--;
            }
          }
          else
          {
            mpnscript->miniStep(-1);
          }
        }
      break;
    case keyLeft:
        if((event->state() & QKeyEvent::AltButton) != 0)
        {
          adjustPoint(0.0,0.0,dif,0.0,0.0,0.0,0.0);
        }
        else if((event->state() & QKeyEvent::ControlButton) == 0)
        {
          adjustPoint(dif,0.0,0.0,0.0,0.0,0.0,0.0);
        }
        else
        {
          if((event->state() & QKeyEvent::ShiftButton) == 0)
          {
            MPNCommandIterator it((MPNCommand*)mpnscript->currentItem());
            if(it.current()) ++it;
            while ( it.current() )
            {
              if(it.current()->cmd!=NULL&&(it.current()->cmd->type==POINT||it.current()->cmd->type==RPOINT||it.current()->cmd->type==EPOINT||it.current()->cmd->type==HPOINT))
              {
                mpnscript->setCurrentItem(it.current());
                break;
              }
              it++;
            }
          }
          else
          {
            mpnscript->miniStep(1);
          }
        }
      break;
    case keyUp:
        switch ( m_wheelState )
        {
          case glMoveV:
            adjustPoint(0.0,0.0,0.0,dif,0.0,0.0,0.0);
            break;
          case glMoveW:
            adjustPoint(0.0,0.0,0.0,0.0,dif,0.0,0.0);
            break;
          case glMoveU:
            adjustPoint(0.0,0.0,0.0,0.0,0.0,dif,0.0);
            break;
          case glMoveT:
            adjustPoint(0.0,0.0,0.0,0.0,0.0,0.0,dif);
            break;
          default:
            adjustPoint(0.0,dif,0.0,0.0,0.0,0.0,0.0);
        }
      break;
    case keyDown:
        switch ( m_wheelState )
        {
          case glMoveV:
            adjustPoint(0.0,0.0,0.0,-dif,0.0,0.0,0.0);
            break;
          case glMoveW:
            adjustPoint(0.0,0.0,0.0,0.0,-dif,0.0,0.0);
            break;
          case glMoveU:
            adjustPoint(0.0,0.0,0.0,0.0,0.0,-dif,0.0);
            break;
          case glMoveT:
            adjustPoint(0.0,0.0,0.0,0.0,0.0,0.0,-dif);
            break;
          default:
            adjustPoint(0.0,-dif,0.0,0.0,0.0,0.0,0.0);
        }
      break;
    case keyPageDown:
      if((event->state() & QKeyEvent::ShiftButton) == 0)
        deltaScaleFactor(10);
      else
        deltaScaleFactor(1);
      break;
    case keyPageUp:
      if((event->state() & QKeyEvent::ShiftButton) == 0)
        deltaScaleFactor(-10);
      else
        deltaScaleFactor(-1);
      break;
    default:
      event->ignore();
      return;

  }
  event->accept();
}

void MPNView3D::keyReleaseEvent( QKeyEvent *event )
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

void MPNView3D::timerEvent(QTimerEvent*)
{

}
