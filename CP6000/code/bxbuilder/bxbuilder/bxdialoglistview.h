/***************************************************************************
                          bxdialoglistview.h  -  description
                             -------------------
    begin                : man jan 5 2004
    copyright            : (C) 2004 by LMS
    email                : lms@maercher.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef BXDIALOGLISTVIEW_H
#define BXDIALOGLISTVIEW_H

#include <qwidget.h>
#include <qlistbox.h>
#include <qlistview.h>

/**
  *@author LMS
  */

class BxDialogListView : public QListView  {
   Q_OBJECT
public slots:
  void listBoxItemdoubleClicked( QListViewItem* i);

public: 
	BxDialogListView(QWidget *parent);
	~BxDialogListView();

};

#endif
