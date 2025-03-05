/****************************************************************************
** Form implementation generated from reading ui file './generate.ui'
**
** Created: Mon Aug 22 15:43:17 2005
**      by: The User Interface Compiler ($Id: generate.cpp,v 1.1 2006/01/25 05:47:32 thn Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "generate.h"

#include <qvariant.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a formGenerate as a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
formGenerate::formGenerate( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )

{
    if ( !name )
	setName( "formGenerate" );
    setEnabled( TRUE );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setMinimumSize( QSize( 483, 100 ) );
    setMaximumSize( QSize( 0, 0 ) );
    setBaseSize( QSize( 429, 100 ) );
    setBackgroundOrigin( QDialog::ParentOrigin );

    TextLabel1 = new QLabel( this, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 20, 10, 50, 21 ) );

    PushButton1 = new QPushButton( this, "PushButton1" );
    PushButton1->setGeometry( QRect( 390, 10, 81, 31 ) );

    PushButton2 = new QPushButton( this, "PushButton2" );
    PushButton2->setGeometry( QRect( 390, 50, 81, 31 ) );
    PushButton2->setAutoDefault( FALSE );

    PushButton3 = new QPushButton( this, "PushButton3" );
    PushButton3->setGeometry( QRect( 340, 30, 30, 21 ) );

    editPath = new QLineEdit( this, "editPath" );
    editPath->setGeometry( QRect( 20, 30, 310, 24 ) );

    genUserFiles = new QCheckBox( this, "genUserFiles" );
    genUserFiles->setGeometry( QRect( 20, 70, 150, 21 ) );

    genResource = new QCheckBox( this, "genResource" );
    genResource->setGeometry( QRect( 190, 70, 160, 21 ) );
    genResource->setChecked( TRUE );
    languageChange();
    resize( QSize(483, 100).expandedTo(minimumSizeHint()) );

    // signals and slots connections
    connect( PushButton3, SIGNAL( released() ), this, SLOT( slotFindPath() ) );
    connect( PushButton2, SIGNAL( released() ), this, SLOT( close() ) );
    connect( PushButton1, SIGNAL( clicked() ), this, SLOT( accept() ) );
}

/*
 *  Destroys the object and frees any allocated resources
 */
formGenerate::~formGenerate()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void formGenerate::languageChange()
{
    setCaption( tr( "Code generator" ) );
    TextLabel1->setText( tr( "Path." ) );
    PushButton1->setText( tr( "Generate" ) );
    PushButton2->setText( tr( "Cancel" ) );
    PushButton3->setText( tr( "..." ) );
    genUserFiles->setText( tr( "generate user files" ) );
    genResource->setText( tr( "generate resource file" ) );
}

void formGenerate::slotFindPath()
{
    qWarning( "formGenerate::slotFindPath(): Not implemented yet" );
}

