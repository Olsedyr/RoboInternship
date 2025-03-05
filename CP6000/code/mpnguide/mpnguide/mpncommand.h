/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#ifndef MPNCOMMAND_H
#define MPNCOMMAND_H
#include <qlistview.h>
#include <qlineedit.h>
#include <qgl.h>
#include <qstring.h>
#include <tmpnrobot.h>

class MPNCommand : public QListViewItem
{
public:
  MPNCommand(QListView* parent=NULL,COMMANDSTRUCT *c=NULL);
  MPNCommand(QListViewItem *parent, QListViewItem *after, COMMANDSTRUCT *c);
  void refresh();
  ~MPNCommand();
  COMMANDSTRUCT *cmd;
};
class MPNCommandIterator : public QListViewItemIterator
{
public:
  MPNCommandIterator(MPNCommand *item):QListViewItemIterator((QListViewItem*)item){};
  MPNCommand *current() const {return (MPNCommand *)QListViewItemIterator::current();};
};
#endif

//SDSD
