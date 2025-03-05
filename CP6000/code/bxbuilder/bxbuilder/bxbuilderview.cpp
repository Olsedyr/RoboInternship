/***************************************************************************
                          bxbuilderview.cpp  -  description
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

#include "bxbuilderview.h"

BxbuilderView::BxbuilderView(QWidget *parent, BxbuilderDoc *doc) : QWidget(parent)
{
  /** connect doc with the view*/
  connect(doc, SIGNAL(documentChanged()), this, SLOT(slotDocumentChanged()));
}

BxbuilderView::~BxbuilderView()
{
}

void BxbuilderView::slotDocumentChanged()
{
  //TODO update the view

}
