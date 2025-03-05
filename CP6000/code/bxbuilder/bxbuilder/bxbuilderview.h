/***************************************************************************
                          bxbuilderview.h  -  description
                             -------------------
    begin                : ons sep  4 23:46:17 CEST 2002
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

#ifndef BXBUILDERVIEW_H
#define BXBUILDERVIEW_H

// include files for QT
#include <qwidget.h>

// application specific includes
#include "bxbuilderdoc.h"

/**
 * This class provides an incomplete base for your application view. 
 */

class BxbuilderView : public QWidget
{
  Q_OBJECT
  public:
    BxbuilderView(QWidget *parent=0, BxbuilderDoc* doc=0);
    ~BxbuilderView();
  
  protected slots:
    void slotDocumentChanged();
  
};

#endif
