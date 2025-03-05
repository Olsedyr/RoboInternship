/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#include <qimage.h>
#include <qslider.h>
#include <qspinbox.h>
#include <GL/glu.h>
#include <math.h>
#include "mpncommand.h"
#include "qgl.h"
#include "cmd.h"

MPNCommand::MPNCommand(QListViewItem * parent, QListViewItem * after, COMMANDSTRUCT *c)
           :QListViewItem( parent, after,"A")
{
  cmd=c;
//  cmd->listitem=this;
  refresh();
}

MPNCommand::MPNCommand(QListView * parent, COMMANDSTRUCT *c)
           :QListViewItem( parent, NULL,"A")
{
  cmd=c;
//  cmd->listitem=this;
  refresh();
}

void MPNCommand::refresh()
{
  QString str;
  char t[256];
  getCommandString(t,cmd);
  if(strlen(t) < 255)
  {
    str.sprintf("%s",t);
    setText(0,str);
  }
}

MPNCommand::~MPNCommand
()
{
}

