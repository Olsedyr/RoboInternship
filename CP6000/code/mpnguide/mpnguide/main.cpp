/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#include <qapplication.h>
#include <qnetwork.h>
#include <qgl.h>
#include <GL/glu.h>
#include "mpnguide.h"

int main( int argc, char **argv )
{
  QApplication::setColorSpec( QApplication::CustomColor );
  QApplication a(argc,argv);
  if ( !QGLFormat::hasOpenGL() ) 
  {
    qWarning( "This system has no OpenGL support. Exiting." );
    return -1;
  }
  MPNGuide w;
  w.move(0,0);
  w.setCaption("MPN A/S - Guided by vision(R)");
  a.setMainWidget( &w );
  w.show();
  w.resize( 1024, 768);
  return a.exec();
}

