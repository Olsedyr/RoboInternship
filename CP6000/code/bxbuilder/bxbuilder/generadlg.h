/***************************************************************************
                          generadlg.h  -  description
                             -------------------
    begin                : tor sep 12 2002
    copyright            : (C) 2002 by Lars Marcher Sandig
    email                : lms@boxsystem.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef GENERADLG_H
#define GENERADLG_H

#include <qwidget.h>
#include <generate.h>

/**
  *@author Lars Marcher Sandig
  */

class generadlg : public formGenerate  {
   Q_OBJECT
public: 
	generadlg(QWidget *parent=0, const char *name=0);
	~generadlg();
public slots: // Public slots
  /** No descriptions */
  void slotFindPath();
};

#endif
