/****************************************************************************
** Form interface generated from reading ui file './generate.ui'
**
** Created: Mon Aug 22 15:42:58 2005
**      by: The User Interface Compiler ($Id: generate.h,v 1.1 2006/01/25 05:47:44 thn Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORMGENERATE_H
#define FORMGENERATE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class formGenerate : public QDialog
{
    Q_OBJECT

public:
    formGenerate( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~formGenerate();

    QLabel* TextLabel1;
    QPushButton* PushButton1;
    QPushButton* PushButton2;
    QPushButton* PushButton3;
    QLineEdit* editPath;
    QCheckBox* genUserFiles;
    QCheckBox* genResource;

public slots:
    virtual void slotFindPath();

protected:

protected slots:
    virtual void languageChange();
};

#endif // FORMGENERATE_H
