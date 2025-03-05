/***************************************************************************
                          bxdialoglistview.cpp  -  description
                             -------------------
    begin                : man jan 5 2004
    copyright            : (C) 2004 by LMS
    email                : lms@maercher.com
 ***************************************************************************/

#include <unistd.h>

#include "bxdialoglistview.h"

BxDialogListView::BxDialogListView(QWidget *parent=0):QListView(parent)
{
  addColumn( "Project" );
  addColumn( "Path" );
  setRootIsDecorated( TRUE );
  setAllColumnsShowFocus( TRUE );
  setColumnWidthMode(0,QListView::Manual);
  setColumnWidth(0,250);
  setColumnWidth(1,200);
  setSorting(-1,FALSE);
}

BxDialogListView::~BxDialogListView()
{
}

void BxDialogListView::listBoxItemdoubleClicked(  QListViewItem* i)
{
  QString s("/usr/bin/designer");
  s += " " + i->text(1);
  system(s.latin1());
}

