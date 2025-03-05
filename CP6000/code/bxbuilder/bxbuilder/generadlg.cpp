/***************************************************************************
                          generadlg.cpp  -  description
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

#include <qfiledialog.h>
#include <qlineedit.h>
#include "generate.h"
#include "generadlg.h"

generadlg::generadlg(QWidget *parent, const char *name ) : formGenerate(parent,name)
{
//  QDir d;
//  editPath->setText(d.absPath());
}

generadlg::~generadlg()
{

}

/** No descriptions */
void generadlg::slotFindPath(){
  QString path = QFileDialog::getExistingDirectory(0, this);

  editPath->setText(path);
}
