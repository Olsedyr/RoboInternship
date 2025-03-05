/***************************************************************************
                          bxbuilderdoc.cpp  -  description
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

#include "bxbuilderdoc.h"

BxbuilderDoc::BxbuilderDoc()
{
  modified = false;
}

BxbuilderDoc::~BxbuilderDoc()
{
}

void BxbuilderDoc::newDoc()
{
}

bool BxbuilderDoc::save()
{
  return true;
}

bool BxbuilderDoc::saveAs(const QString &filename)
{
  return true;
}

bool BxbuilderDoc::load(const QString &filename)
{
  emit documentChanged();
  return true;
}

bool BxbuilderDoc::isModified() const
{
  return modified;
}
