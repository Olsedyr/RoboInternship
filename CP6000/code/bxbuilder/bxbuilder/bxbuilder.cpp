/***************************************************************************
                          bxbuilder.cpp  -  description
                             -------------------
    begin                : ons sep  4 23:46:17 CEST 2002
    copyright            : (C) 2002 by Lars Marcher Sandig
    email                : lms@boxsystem.com
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <unistd.h>

#include <qaccel.h>
#include <qwidgetfactory.h>
#include <qobjectlist.h>
#include <qlabel.h>
#include <qlistbox.h>
#include <qcheckbox.h>
#include <qlineedit.h>
#include <qgroupbox.h>
#include <qimage.h>
#include <qbitmap.h>
#include <qradiobutton.h>
#include <qlayout.h>

#include <qurloperator.h>

#include "bxbuilder.h"
#include "bxdialoglistview.h"
#include "filesave.xpm"
#include "fileopen.xpm"
#include "filenew.xpm"
#include "generadlg.h"

#define PICTURE       0x01
#define ICON          0x02

typedef struct BX_RESOURCE_ELEMENT_HEADER {
  char   id[255];
  int    type;
  int    size;
} BX_RESOURCE_ELEMENT_HEADER;

BxbuilderApp::BxbuilderApp()
{
  setCaption(tr("Bxbuilder "));

  ///////////////////////////////////////////////////////////////////
  // call inits to invoke all other construction parts
  initActions();
  initMenuBar();
  initToolBar();
  initStatusBar();

  initDoc();
  initView();

  QGridLayout *grid = new QGridLayout( view, 8, 8 );

  dialoglist = new BxDialogListView(view);
  project = new QListViewItem( dialoglist, NULL );
  project->setText(0, "New project");
  
  connect( dialoglist, SIGNAL( doubleClicked( QListViewItem* ) ), dialoglist, SLOT( listBoxItemdoubleClicked( QListViewItem* ) ) );

  grid->addMultiCellWidget( dialoglist, 8, 8, 7, 8 );

  viewToolBar->setOn(true);
  viewStatusBar->setOn(true);
}

BxbuilderApp::~BxbuilderApp()
{
  delete dialoglist;
}

/** initializes all QActions of the application */
void BxbuilderApp::initActions(){

  QPixmap openIcon, saveIcon, newIcon;
  newIcon = QPixmap(filenew);
  openIcon = QPixmap(fileopen);
  saveIcon = QPixmap(filesave);


  fileNew = new QAction(tr("New File"), newIcon, tr("&New"), QAccel::stringToKey(tr("Ctrl+N")), this);
  fileNew->setStatusTip(tr("Creates a new document"));
  fileNew->setWhatsThis(tr("New File\n\nCreates a new document"));
  connect(fileNew, SIGNAL(activated()), this, SLOT(slotFileNew()));

  fileOpen = new QAction(tr("Open File"), openIcon, tr("&Open..."), 0, this);
  fileOpen->setStatusTip(tr("Opens an existing document"));
  fileOpen->setWhatsThis(tr("Open File\n\nOpens an existing document"));
  connect(fileOpen, SIGNAL(activated()), this, SLOT(slotFileOpen()));

  fileSave = new QAction(tr("Save File"), saveIcon, tr("&Save"), QAccel::stringToKey(tr("Ctrl+S")), this);
  fileSave->setStatusTip(tr("Saves the actual document"));
  fileSave->setWhatsThis(tr("Save File.\n\nSaves the actual document"));
  connect(fileSave, SIGNAL(activated()), this, SLOT(slotFileSave()));

  fileSaveAs = new QAction(tr("Save File As"), tr("Save &as..."), 0, this);
  fileSaveAs->setStatusTip(tr("Saves the actual document under a new filename"));
  fileSaveAs->setWhatsThis(tr("Save As\n\nSaves the actual document under a new filename"));
  connect(fileSaveAs, SIGNAL(activated()), this, SLOT(slotFileSave()));

  fileClose = new QAction(tr("Close File"), tr("&Close"), QAccel::stringToKey(tr("Ctrl+W")), this);
  fileClose->setStatusTip(tr("Closes the actual document"));
  fileClose->setWhatsThis(tr("Close File\n\nCloses the actual document"));
  connect(fileClose, SIGNAL(activated()), this, SLOT(slotFileClose()));

  fileGenerate = new QAction(tr("Generate Bx souece code"), tr("&Generate"), QAccel::stringToKey(tr("Ctrl+G")), this);
  connect(fileGenerate, SIGNAL(activated()), this, SLOT(slotFileGenerate()));

  filePrint = new QAction(tr("Print File"), tr("&Print"), QAccel::stringToKey(tr("Ctrl+P")), this);
  filePrint->setStatusTip(tr("Prints out the actual document"));
  filePrint->setWhatsThis(tr("Print File\n\nPrints out the actual document"));
  connect(filePrint, SIGNAL(activated()), this, SLOT(slotFilePrint()));

  fileQuit = new QAction(tr("Exit"), tr("E&xit"), QAccel::stringToKey(tr("Ctrl+Q")), this);
  fileQuit->setStatusTip(tr("Quits the application"));
  fileQuit->setWhatsThis(tr("Exit\n\nQuits the application"));
  connect(fileQuit, SIGNAL(activated()), this, SLOT(slotFileQuit()));

  editCut = new QAction(tr("Cut"), tr("Cu&t"), QAccel::stringToKey(tr("-")), this);
  editCut->setStatusTip(tr("Cuts the selected dialogbox from the project"));
  editCut->setWhatsThis(tr("Cut\n\nCuts the selected dialogbox from the project"));
  connect(editCut, SIGNAL(activated()), this, SLOT(slotEditCut()));

  editAdd = new QAction(tr("Add"), tr("&Add"), QAccel::stringToKey(tr("+")), this);
  editAdd->setStatusTip(tr("Add Bx Dialog to the project"));
  editAdd->setWhatsThis(tr("Add\n\nAdd Bx Dialog to the project"));
  connect(editAdd, SIGNAL(activated()), this, SLOT(slotEditAdd()));

  editPaste = new QAction(tr("Paste"), tr("&Paste"), QAccel::stringToKey(tr("Ctrl+V")), this);
  editPaste->setStatusTip(tr("Pastes the clipboard contents to actual position"));
  editPaste->setWhatsThis(tr("Paste\n\nPastes the clipboard contents to actual position"));
  connect(editPaste, SIGNAL(activated()), this, SLOT(slotEditPaste()));

  viewToolBar = new QAction(tr("Toolbar"), tr("Tool&bar"), 0, this, 0, true);
  viewToolBar->setStatusTip(tr("Enables/disables the toolbar"));
  viewToolBar->setWhatsThis(tr("Toolbar\n\nEnables/disables the toolbar"));
  connect(viewToolBar, SIGNAL(toggled(bool)), this, SLOT(slotViewToolBar(bool)));

  viewStatusBar = new QAction(tr("Statusbar"), tr("&Statusbar"), 0, this, 0, true);
  viewStatusBar->setStatusTip(tr("Enables/disables the statusbar"));
  viewStatusBar->setWhatsThis(tr("Statusbar\n\nEnables/disables the statusbar"));
  connect(viewStatusBar, SIGNAL(toggled(bool)), this, SLOT(slotViewStatusBar(bool)));

  helpAboutApp = new QAction(tr("About"), tr("&About..."), 0, this);
  helpAboutApp->setStatusTip(tr("About the application"));
  helpAboutApp->setWhatsThis(tr("About\n\nAbout the application"));
  connect(helpAboutApp, SIGNAL(activated()), this, SLOT(slotHelpAbout()));

}

void BxbuilderApp::initMenuBar()
{
  ///////////////////////////////////////////////////////////////////
  // MENUBAR

  ///////////////////////////////////////////////////////////////////
  // menuBar entry fileMenu
  fileMenu=new QPopupMenu();
  fileNew->addTo(fileMenu);
  fileOpen->addTo(fileMenu);
  fileClose->addTo(fileMenu);
  fileMenu->insertSeparator();
  fileSave->addTo(fileMenu);
  fileSaveAs->addTo(fileMenu);
  fileMenu->insertSeparator();
  fileGenerate->addTo(fileMenu);
  fileMenu->insertSeparator();
  filePrint->addTo(fileMenu);
  fileMenu->insertSeparator();
  fileQuit->addTo(fileMenu);

  ///////////////////////////////////////////////////////////////////
  // menuBar entry editMenu
  editMenu=new QPopupMenu();
  editAdd->addTo(editMenu);
  editCut->addTo(editMenu);
  editPaste->addTo(editMenu);

  ///////////////////////////////////////////////////////////////////
  // menuBar entry viewMenu
  viewMenu=new QPopupMenu();
  viewMenu->setCheckable(true);
  viewToolBar->addTo(viewMenu);
  viewStatusBar->addTo(viewMenu);
  ///////////////////////////////////////////////////////////////////
  // EDIT YOUR APPLICATION SPECIFIC MENUENTRIES HERE

  ///////////////////////////////////////////////////////////////////
  // menuBar entry helpMenu
  helpMenu=new QPopupMenu();
  helpAboutApp->addTo(helpMenu);

  ///////////////////////////////////////////////////////////////////
  // MENUBAR CONFIGURATION
  menuBar()->insertItem(tr("&File"), fileMenu);
  menuBar()->insertItem(tr("&Edit"), editMenu);
  menuBar()->insertItem(tr("&View"), viewMenu);
  menuBar()->insertSeparator();
  menuBar()->insertItem(tr("&Help"), helpMenu);

}

void BxbuilderApp::initToolBar()
{
  ///////////////////////////////////////////////////////////////////
  // TOOLBAR
  fileToolbar = new QToolBar(this, "file operations");
  fileNew->addTo(fileToolbar);
  fileOpen->addTo(fileToolbar);
  fileSave->addTo(fileToolbar);
  fileToolbar->addSeparator();
  QWhatsThis::whatsThisButton(fileToolbar);

}

void BxbuilderApp::initStatusBar()
{
  ///////////////////////////////////////////////////////////////////
  //STATUSBAR
  statusBar()->message(tr("Ready."), 2000);
}

void BxbuilderApp::initDoc()
{
   doc=new BxbuilderDoc();
}

void BxbuilderApp::initView()
{
  ////////////////////////////////////////////////////////////////////
  // set the main widget here
  view=new BxbuilderView(this, doc);
  setCentralWidget(view);
}

bool BxbuilderApp::queryExit()
{
  int exit=QMessageBox::information(this, tr("Quit..."),
                                    tr("Do your really want to quit?"),
                                    QMessageBox::Ok, QMessageBox::Cancel);

  if (exit==1)
  {

  }
  else
  {

  };

  return (exit==1);
}

/////////////////////////////////////////////////////////////////////
// SLOT IMPLEMENTATION
/////////////////////////////////////////////////////////////////////


void BxbuilderApp::slotFileNew()
{
  statusBar()->message(tr("Creating new project..."));
  doc->newDoc();
  dialoglist->clear();
  project = new QListViewItem( dialoglist, NULL );
  project->setText(0, "New project");
  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotFileOpen()
{
  QFileDialog fd;
  QString s1, s2, s3, s4, snum, srec, path;
  
  statusBar()->message(tr("Opening file..."));

  QString fileName = fd.getOpenFileName(0,"*.bxp",this);
  if (!fileName.isEmpty())
  {
    LoadProject(fileName);
    QString s = fileName.section( '/', -1 );
    project->setText(0, s);
    project->setText(1, fileName);
  }
  else
  {
    statusBar()->message(tr("Opening aborted"), 2000);
  }
}


void BxbuilderApp::slotFileSave()
{
  statusBar()->message(tr("Saving project under new filename..."));
  QString fn = QFileDialog::getSaveFileName(0, "Project (*.bxp)", this);
  if (!fn.isEmpty())
  {
    QString s = fn.section( ".bxp", -1 );
    if(!s.isEmpty())
      fn += ".bxp";
    s = fn.section( '/', -1 );
    project->setText(0, s);
    project->setText(1, fn);
    SaveProject(fn);
//    doc->saveAs(fn);
  }
  else
  {
    statusBar()->message(tr("Saving aborted"), 2000);
  }

  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotFileSaveAs()
{
  statusBar()->message(tr("Saving project under new filename..."));
  QString fn = QFileDialog::getSaveFileName(0, "Project (*.bxp)", this);
  if (!fn.isEmpty())
  {
    QString s = fn.section( ".bxp", -1 );
    if(!s.isEmpty())
      fn += ".bxp";
    s = fn.section( '/', -1 );
    project->setText(0, s);
    project->setText(1, fn);
    SaveProject(fn);
//    doc->saveAs(fn);
  }
  else
  {
    statusBar()->message(tr("Saving aborted"), 2000);
  }

  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotFileClose()
{
  statusBar()->message(tr("Closing file..."));

  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotFileGenerate()
{
  generadlg gDlg;
  QString fileName;
  QString path;
  statusBar()->message(tr("Generating..."));

  gDlg.show();
  QString s1 = project->text(1).section( '/', -1 );
  QString s = project->text(1).section( "/"+s1, 0 );
  gDlg.editPath->setText(s);

  if( gDlg.exec() == QDialog::Accepted )
  {
    path = gDlg.editPath->text() + "/";

    if(dialoglist->currentItem()!=0 && dialoglist->currentItem()!=project)
    {
      QListViewItem *e = dialoglist->currentItem();
      fileName = e->text(1);
      GenerateCode(fileName, path);
    }
    else
    {
      QString p1 = project->text(0).section( ".bxp", 0 );
      QFile f1(path + p1 + QString(".bxr"));
      if( f1.open( IO_WriteOnly ) == false)
      {
        printf("ERROR: cannot create new file.\n");
        return;
      }
      f1.close();

      QListViewItem *e = project->firstChild();
      if(e)
      {
        while(e)
        {
          fileName = e->text(1);
          GenerateCode(fileName, path);
          e = e->nextSibling();
        }
      }
    }
  }

  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotFilePrint()
{
  statusBar()->message(tr("Printing..."));
  QPrinter printer;
  if (printer.setup(this))
  {
    QPainter painter;
    painter.begin(&printer);

    ///////////////////////////////////////////////////////////////////
    // TODO: Define printing by using the QPainter methods here

    painter.end();
  };

  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotFileQuit()
{
  statusBar()->message(tr("Exiting application..."));
  ///////////////////////////////////////////////////////////////////
  // exits the Application
  if(doc->isModified())
  {
    if(queryExit())
    {
      qApp->quit();
    }
    else
    {

    };
  }
  else
  {
    qApp->quit();
  };

  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotEditCut()
{
  statusBar()->message(tr("Cutting selection..."));

  if( dialoglist->currentItem() != 0 && dialoglist->currentItem() != project)
    delete dialoglist->currentItem();
  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotEditAdd()
{
  QFileDialog fd;
  QString s1, s2, s3, s4, snum, srec, path;

  statusBar()->message(tr("Adding BxDialogbox..."));

  QString fileName = fd.getOpenFileName(0,"*.ui",this);
  if (!fileName.isEmpty())
  {
    QListViewItem *element = new QListViewItem( project, dialoglist->lastItem());
    QString s = fileName.section( '/', -1 );
    element->setText(0, s);
    element->setText(1, fileName);
//    QDialog *creditForm = (QDialog *) QWidgetFactory::create( fileName );

    QString message=tr("Added document: ")+fileName;
    statusBar()->message(message, 2000);
  }
  else
  {
    statusBar()->message(tr("Adding aborted"), 2000);
  }
}

void BxbuilderApp::slotEditPaste()
{
  statusBar()->message(tr("Inserting clipboard contents..."));

  statusBar()->message(tr("Ready."));
}


void BxbuilderApp::slotViewToolBar(bool toggle)
{
  statusBar()->message(tr("Toggle toolbar..."));
  ///////////////////////////////////////////////////////////////////
  // turn Toolbar on or off

  if (toggle== false)
  {
    fileToolbar->hide();
  }
  else
  {
    fileToolbar->show();
  };

  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotViewStatusBar(bool toggle)
{
  statusBar()->message(tr("Toggle statusbar..."));
  ///////////////////////////////////////////////////////////////////
  //turn Statusbar on or off

  if (toggle == false)
  {
    statusBar()->hide();
  }
  else
  {
    statusBar()->show();
  }

  statusBar()->message(tr("Ready."));
}

void BxbuilderApp::slotHelpAbout()
{
 
  QMessageBox::about(this,tr("About..."),

tr("//*****************************************************************************\n//* Copyright (C) 2003 by MPN A/S - Guided by vision(R) Lars Marcher Sandig   *\n//* All rights reserved.                                                      *\n//*****************************************************************************"));
}

/** No descriptions */
int BxbuilderApp::GenerateCode(QString filename, QString path)
{
  QString s1, s2, s3, s4, snum, srec;
  int i, id;
  int genUserHeader=false, genUserCode=false;
  QString idstr;
//  QWidget *creditForm = QWidgetFactory::create(filename);
  QDialog *creditForm = (QDialog *) QWidgetFactory::create( filename );
        // Set up the dynamic dialog here

  QObjectList *l = creditForm->queryList( );
  QObjectListIt it( *l ); // iterate over the buttons
  QObject *obj;
  // Generer headerfil
  
  QString p1 = project->text(0).section( ".bxp", 0 );
  s1 = creditForm->name();
  s2 = s1 + ".h";
  QFile f1(path + s1 + ".h");
  QFile f2(path + s1 + ".c");
  QFile f3(path + s1 + "Code.c");
  QFile f4(path + s1 + "User.h");
  QFile f5(path + s1 + "User.c");
  QFile f6(path + p1 + "Bxr.h");

  f1.open( IO_WriteOnly );
	f2.open( IO_WriteOnly );
	f3.open( IO_WriteOnly );

  if( f4.open( IO_ReadOnly ) == false)
	{
    f4.open( IO_WriteOnly );
    genUserHeader = true;
  }
  else
    f4.close();
    
	if( f5.open( IO_ReadOnly ) == false)
  {
    f5.open( IO_WriteOnly );
    genUserCode = true;
  }
  else
    f5.close();

  f6.open( IO_WriteOnly | IO_Append);

	QTextStream t1 ( &f1 );
	QTextStream t2 ( &f2 );
	QTextStream t3 ( &f3 );
	QTextStream t4 ( &f4 );
	QTextStream t5 ( &f5 );
	QTextStream t6 ( &f6 );

//*****************************************************************************
//* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
//* All rights reserved.                                                      *
//*****************************************************************************
	t1 << "//Copyright (C) 2005 by MPN A/S - Guided by vision(R)\n";
	t1 << "// " + s2 + '\n';
	t1 << "#if !defined(" + s1.upper() + "_H)\n";
	t1 << "#define " + s1.upper() + "_H\n";
	t1 << "#include \"Bx.h\"\n";
	t1 << "#include \"" + s1 + "User.h\"\n";

	t2 << "//Copyright (C) 2005 by MPN A/S - Guided by vision(R)\n";
	t2 << "// " + s1 + ".c\n";
	t2 << "#include \"Bx.h\"\n";
	t2 << "#include \"" + s1 + ".h\"\n\n";
	t2 << "BOXSTRUCT " + s1 + "[] = {\n";
  srec.sprintf("{%d,%d,%d,%d}", 0, 0, creditForm->width(), creditForm->height());
	t2 << " {10000," + srec + ",DIALOG,\"\",BXS_VISIBLE,&" + s1 + "[1], NULL}\n";

	t3 << "//Copyright (C) 2005 by MPN A/S - Guided by vision(R)\n";
	t3 << "// " + s1 + "Code.c\n";
	t3 << "#include \"Bx.h\"\n";
	t3 << "#include \"" + s1 + ".h\"\n\n";

	if( genUserHeader )
	{
		t4 << "//Copyright (C) 2005 by MPN A/S - Guided by vision(R)\n";
		t4 << "// " + s1 + "User.h\n\n";
		t4 << "extern BX_BOOL " + s1 + "UserInit(HBOX hBox,BX_LPARAM lParam);\n";
		t4 << "extern BX_BOOL " + s1 + "UserUpdate(HBOX hBox);\n";
  }
  
	if( genUserCode )
	{
		t5 << "//Copyright (C) 2005 by MPN A/S - Guided by vision(R)\n";
		t5 << "// " + s1 + "User.c\n";
		t5 << "#include \"Bx.h\"\n";
		t5 << "#include \"" + s1 + ".h\"\n\n";
		t5 << "BX_BOOL " + s1 + "UserInit(HBOX hBox,BX_LPARAM lParam)\n";
		t5 << "{\n";
    t5 << "  return TRUE;\n";
		t5 << "}\n\n";
		t5 << "BX_BOOL " + s1 + "UserUpdate(HBOX hBox)\n";
		t5 << "{\n";
    t5 << "  return TRUE;\n";
		t5 << "}\n\n";
	}

	i = 1;
	while ( (obj = it.current()) != 0 )
  {
  // for each found object...
    ++it;
    if (
        ((QWidget*)obj)->isHidden() == FALSE &&
        (strcmp ( obj->className(), "QPushButton" ) == 0 ||
        strcmp ( obj->className(), "QLabel" ) == 0 ||
        strcmp ( obj->className(), "QGroupBox" ) == 0 ||
        strcmp ( obj->className(), "QListBox" ) == 0  ||
        strcmp ( obj->className(), "QScrollBar" ) == 0  ||
        strcmp ( obj->className(), "QCheckBox" ) == 0  ||
        strcmp ( obj->className(), "QRadioButton" ) == 0)
       )
    {
      s3 = obj->name();
      s4.sprintf("%d",i++);
  	  t1 << "#define " + s1.upper() + "_" + s3.upper() + " " + s4 + '\n';
      if ( strcmp ( obj->className(), "QPushButton" ) == 0 ||
          strcmp ( obj->className(), "QListBox" ) == 0  ||
          strcmp ( obj->className(), "QScrollBar" ) == 0  ||
          strcmp ( obj->className(), "QCheckBox" ) == 0  ||
          strcmp ( obj->className(), "QRadioButton" ) == 0
      )
			t1 << "extern BX_BOOL " + s1 + "_" + s3 + "_Click(HBOX hBox);\n";
			if( genUserCode )
			{
        if ( strcmp ( obj->className(), "QPushButton" ) == 0 ||
            strcmp ( obj->className(), "QCheckBox" ) == 0 ||
            strcmp ( obj->className(), "QRadioButton" ) == 0 ||
            strcmp ( obj->className(), "QScrollBar" ) == 0 ||
            strcmp ( obj->className(), "QListBox" ) == 0 )
		    {
          t5 << "BX_BOOL " + s1 + "_" + s3 + "_Click(HBOX hBox)\n";
					t5 << "{\n";
          t5 << "  return TRUE;\n";
					t5 << "}\n\n";
        }
			}

      if (((QWidget*)obj)->parentWidget() != ((QWidget*)obj)->topLevelWidget())
        srec.sprintf("{%d,%d,%d,%d}", (((QWidget*)obj)->parentWidget())->frameGeometry().left() + ((QWidget*)obj)->frameGeometry().left(),
            (((QWidget*)obj)->parentWidget())->frameGeometry().top() + ((QWidget*)obj)->frameGeometry().top(),
            (((QWidget*)obj)->parentWidget())->frameGeometry().left() + ((QWidget*)obj)->frameGeometry().right(),
            (((QWidget*)obj)->parentWidget())->frameGeometry().top() + ((QWidget*)obj)->frameGeometry().bottom());
      else
        srec.sprintf("{%d,%d,%d,%d}", ((QWidget*)obj)->frameGeometry().left(),
            ((QWidget*)obj)->frameGeometry().top(),
            ((QWidget*)obj)->frameGeometry().right(),
            ((QWidget*)obj)->frameGeometry().bottom());
      if ( strcmp ( obj->className(), "QLabel" ) == 0)
      {
	int bbstrue = 0;
        t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",STATIC,\"" + ((QLabel*)obj)->text() + "\",";
        if(((QLabel*)obj)->frameShape() != QGroupBox::NoFrame)
	{        
	  t2 << "BXS_BORDER";
	  bbstrue++;
	}
        if ( ((QLabel*)obj)->pixmap() != 0)
	{ 
	  if (bbstrue) t2 << "|";
	  t2 << "BSS_BITMAP";
	  bbstrue++;
	}
        if ( ((QLabel*)obj)->alignment() & AlignRight)
	{
	  if (bbstrue) t2 << "|";
          t2 << "BSS_RIGHT";
	  bbstrue++;
	}
        if ( ((QLabel*)obj)->alignment() & AlignHCenter)
	{
	  if (bbstrue) t2 << "|";
          t2 << "BSS_CENTER";
	  bbstrue++;
	}
	if (((QWidget*)obj)->isEnabled()==TRUE)
	{
	  if (bbstrue) t2 << "|";
	  t2 << "BXS_VISIBLE,";
	}
	else t2 << ",";
     
      }
      if ( strcmp ( obj->className(), "QGroupBox" ) == 0)
      {
	if (((QWidget*)obj)->isEnabled()==TRUE)
	{ 
	  t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",STATIC,\"" + ((QGroupBox*)obj)->title() + "\",BSS_WHITEFRAME|BXS_VISIBLE,";
	}
	else 
	{
	  t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",STATIC,\"" + ((QGroupBox*)obj)->title() + "\",BSS_WHITEFRAME,";
	}
      }
      if ( strcmp ( obj->className(), "QListBox" ) == 0)
      {
				if (((QWidget*)obj)->isEnabled()==TRUE)
				{
					t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",LIST,\"" "\",BXS_VISIBLE,";
				}
				else 
				{
					t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",LIST,\"" "\",";
				}
        t3 << "BXLISTSTRUCT " + s1 + "_" + s3 + "List;\n";
      }
      if ( strcmp ( obj->className(), "QScrollBar" ) == 0)
      {
	if (((QWidget*)obj)->isEnabled()==TRUE)
	{
        t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",STATIC,\"" "\",BXS_VISIBLE,";
	}
	else
	{
	  t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",STATIC,\"" "\",";
	}
        t3 << "BXSCROLLBARSTRUCT " + s1 + "_" + s3 + "Scroll;\n";
      }
      if ( strcmp ( obj->className(), "QPushButton" ) == 0)
      {
        if ( ((QButton*)obj)->pixmap() == 0)
          t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",BUTTON,\"" + ((QButton*)obj)->text() + "\",BBS_PUSHBUTTON";
        else
          t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",BUTTON,\"" + ((QButton*)obj)->text() + "\",BBS_BITMAP";
	if (((QWidget*)obj)->isEnabled()==TRUE)
	  t2 << "|BXS_VISIBLE,";
	else
	  t2 << ",";
      }
      if ( strcmp ( obj->className(), "QCheckBox" ) == 0)
      {
	t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",BUTTON,\"" + ((QButton*)obj)->text() + "\",BBS_CHECKBOX";
	if (((QWidget*)obj)->isEnabled()==TRUE)
	  t2 << "|BXS_VISIBLE,";
	else
	  t2 << ",";
      }
      if ( strcmp ( obj->className(), "QRadioButton" ) == 0)
      {
	t2 << " ,{" + s1.upper() + "_" + s3.upper() + "," + srec + ",BUTTON,\"" + ((QButton*)obj)->text() + "\",BBS_RADIOBOX";
	if (((QWidget*)obj)->isEnabled()==TRUE)
	  t2 << "|BXS_VISIBLE,";
	else
	  t2 << ",";
      }
      t2 << "&" + s1 + "[" + snum.setNum(i) + "], &" + s1 + "[0]}\n";
    }
  }
	t2 << " ,{BXID_STATIC,{0,0,0,0},STATIC,\"\",0,";
	t2 << "NULL, &" + s1 + "[0]}\n";
	
	t2 << "};\n\n";

    t2 << "BX_BOOL " + s1 + "Proc(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam)\n";
    t2 << "{\n";
	  t2 << " switch(uMsg)\n";
    t2 << "	{\n";
    t2 << "		case BM_UPDATE:\n";
    t2 << "			{\n";
    t2 << "				" + s1 + "Update(hBox);\n";
    t2 << "				return " + s1 + "UserUpdate(hBox);\n";
    t2 << "				break;\n";
    t2 << "			}\n";
    t2 << "		case BM_INITDIALOG:\n";
    t2 << "			{\n";
    t2 << "				" + s1 + "Init(hBox);\n";
    t2 << "				return " + s1 + "UserInit(hBox,lParam);\n";
    t2 << "				break;\n";
    t2 << "			}\n";
    t2 << "		case BM_COMMAND:\n";
    t2 << "			{\n";
    t2 << "				switch(BX_LOWORD(wParam))\n";
    t2 << "				{\n";
    QObjectListIt it2( *l ); // iterate over the buttons
    while ( (obj = it2.current()) != 0 )
    {
      ++it2;
			s3 = obj->name();
      if (
           ((QWidget*)obj)->isHidden() == FALSE &&
           (strcmp ( obj->className(), "QPushButton" ) == 0 ||
           strcmp ( obj->className(), "QListBox" ) == 0  ||
           strcmp ( obj->className(), "QScrollBar" ) == 0  ||
           strcmp ( obj->className(), "QCheckBox" ) == 0  ||
           strcmp ( obj->className(), "QRadioButton" ) == 0)
         )
      {
			  t2 << "         case " + s1.upper() + "_" + s3.upper() + ":\n";
				t2 << "             return " + s1 + "_" + s3 + "_Click(hBox);\n";
      }
    }
    t2 << "				}\n";
    t2 << "				break;\n";
    t2 << "			}\n";
    t2 << "		default:\n";
    t2 << "			return(DefBoxProc(hBox,uMsg,wParam,lParam));\n";
    t2 << "	}\n";
    t2 << "	return 0L;\n";
    t2 << "}\n";

		t1 << "extern BX_CHAR " + s1 + "Text[][MAXLANGUAGE][255];\n";
		t1 << "extern BOXSTRUCT " + s1 + "[];\n";
		t1 << "extern BX_BOOL " + s1 + "Proc(HBOX hBox, BX_UINT uMsg ,BX_WPARAM wParam, BX_LPARAM lParam);\n";
		t1 << "extern BX_VOID " + s1 + "Update(HBOX hBox);\n";
		t1 << "extern BX_VOID " + s1 + "Init(HBOX hBox);\n";

		t1 << "#endif // " + s1.upper() + "_H\n";

		t3 << "BX_VOID " + s1 + "Init(HBOX hBox)\n";
		t3 << "{\n";
    QObjectListIt it3( *l ); // iterate over the buttons
    while ( (obj = it3.current()) != 0 )
    {
      ++it3;

      if(((QWidget*)obj)->isHidden() == FALSE)
      {
        s3 = obj->name();
        if ( strcmp ( obj->className(), "QLabel" ) == 0)
        {
          if ( ((QLabel*)obj)->pixmap() != 0)
          {
            if (((QLabel*)obj)->pixmap()->mask() != 0)
            {
              id = AddIcon(((QLabel*)obj)->pixmap(), path+p1+QString(".bxr"));
              idstr.sprintf("%d", id);
              t6 << "#define " + s1.upper() + "_" + s3.upper() + "_ICON " + idstr + '\n';
              t3 << "  //ICON ID = " + idstr + "\n";
              t3 << "  BxSendMessage(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(" + idstr + ", \"" + "data/" + p1 + QString(".bxr") + "\"), 0);\n";
            }
            else
            {
              id = AddPicture(((QLabel*)obj)->pixmap(), path+p1+QString(".bxr"));
              idstr.sprintf("%d", id);
              t6 << "#define " + s1.upper() + "_" + s3.upper() + "_PIXMAP " + idstr + '\n';
              t3 << "  //PIXMAP ID = " + idstr + "\n";
              t3 << "  BxSendMessage(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(" + idstr + ", \"" + "data/" + p1 + QString(".bxr") + "\"), 0);\n";
            }
          }
          else
          {
//            id = AddString(((QLabel*)obj)->text(), path+p1+QString(".bxl"));
//            idstr.sprintf("%d", id);
//            t3 << "  BxSetBoxText(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BxTr( " + idstr + " ));\n";
          }
        }
        if ( strcmp ( obj->className(), "QPushButton" ) == 0)
        {
          if ( ((QButton*)obj)->pixmap() != 0)
          {
            if (((QLabel*)obj)->pixmap()->mask() != 0)
            {
              id = AddIcon(((QLabel*)obj)->pixmap(), path+p1+QString(".bxr"));
              idstr.sprintf("%d", id);
              t6 << "#define " + s1.upper() + "_" + s3.upper() + "_ICON " + idstr + '\n';
              t3 << "  //ICON ID = " + idstr + "\n";
              t3 << "  BxSendMessage(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxIcon(" + idstr + ", \"" + "data/" + p1 + QString(".bxr") + "\"), 0);\n";
            }
            else
            {
              id = AddPicture(((QButton*)obj)->pixmap(), path+p1+QString(".bxr"));
              idstr.sprintf("%d", id);
              t6 << "#define " + s1.upper() + "_" + s3.upper() + "_PIXMAP " + idstr + '\n';
              t3 << "  //PIXMAP ID = " + idstr + "\n";
              t3 << "  BxSendMessage(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BBM_SETBITMAP, (BX_WPARAM)BxResourceLoadBxBitmap(" + idstr + ", \"" + "data/" + p1 + QString(".bxr") + "\"), 0);\n";
            }
          }
          else
          {
//            id = AddString(((QButton*)obj)->text(), path+p1+QString(".bxl"));
//            idstr.sprintf("%d", id);
//            t3 << "  BxSetBoxText(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BxTr( " + idstr + " ));\n";
          }
        }
        if ( strcmp ( obj->className(), "QRadioButton" ) == 0)
        {
//          id = AddString(((QButton*)obj)->text(), path+p1+QString(".bxl"));
//          idstr.sprintf("%d", id);
//          t3 << "  BxSetBoxText(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BxTr( " + idstr + " ));\n";
          if (((QRadioButton*)obj)->isOn())
          {
            t3 << "  BxSetCheck(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), TRUE);\n";
          }
        }
        if ( strcmp ( obj->className(), "QCheckBox" ) == 0)
        {
//          id = AddString(((QButton*)obj)->text(), path+p1+QString(".bxl"));
//          idstr.sprintf("%d", id);
//          t3 << "  BxSetBoxText(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BxTr( " + idstr + " ));\n";
        }
        if ( strcmp ( obj->className(), "QGroupBox" ) == 0)
        {
//          id = AddString(((QGroupBox*)obj)->title(), path+p1+QString(".bxl"));
//          idstr.sprintf("%d", id);
//          t3 << "  BxSetBoxText(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), BxTr( " + idstr + " ));\n";
        }
        if (strcmp ( obj->className(), "QListBox" ) == 0)
        {
          t3 << "  BxList_Create(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), &" + s1 + "_" + s3 + "List, 0);\n";
        }
        if (strcmp ( obj->className(), "QScrollBar" ) == 0)
        {
          t3 << "  BxScrollBar_Create(BxGetDlgItem(hBox, " + s1.upper() + "_" + s3.upper() + "), &" + s1 + "_" + s3 + "Scroll, " + (((QScrollBar*)obj)->orientation() == Qt::Horizontal ? "BSB_HORIZONTAL);\n" : "BSB_VERTICAL);\n") ;
        }
      }
    }
		t3 << "}\n\n";

		t3 << "BX_VOID " + s1 + "Update(HBOX hBox)\n";
		t3 << "{\n";
		t3 << "}\n\n";


		f1.close();
		f2.close();
		f3.close();

	  if( genUserHeader )
	    f4.close( );
    if( genUserCode )
      f5.close( );
    f6.close();
    delete l; // delete the list, not the objects

  return 0;
}
/** No descriptions */
int BxbuilderApp::AddPicture(const QPixmap *pix, QString ofile){
  QFile f1(ofile);
  BX_RESOURCE_ELEMENT_HEADER rhd;
  int t,w,h,bpl, count=0;
  short d,bpp;
  QImage img, img2;

  img = *pix;
  img.convertDepth(32);

  if( f1.open( IO_ReadOnly ) == true)
  {
    f1.readBlock((char*)&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER));
    while(f1.atEnd()==false)
    {
      if(rhd.type == PICTURE)
      {
        f1.readBlock((char*)&t, sizeof(int));
        f1.readBlock((char*)&w, sizeof(int));
        f1.readBlock((char*)&h, sizeof(int));
        f1.readBlock((char*)&bpl, sizeof(int));
        f1.readBlock((char*)&d, sizeof(short));
        f1.readBlock((char*)&bpp, sizeof(short));
        img2.create(w,h,d);
        f1.readBlock((char*)img2.bits(), rhd.size-20);
        if(img==img2)
        {
          // resource exists
           f1.close();
           return atoi(rhd.id);
        }
      }
      else
      {
        if(f1.at(f1.at()+rhd.size)==FALSE)
          exit(0);
      }
      count++;
      f1.readBlock((char*)&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER));
    }
  }
  f1.close();

  if( f1.open( IO_WriteOnly | IO_Append) == false)
  {
    printf("ERROR: cannot create new file.\n");
    return -2;
  }

  unsigned char *idat;
  int dat;

  // billed id = filnavn.
  sprintf(rhd.id,"%d", count);
  rhd.type = PICTURE;
  rhd.size = img.numBytes() + 20;
  f1.writeBlock((char*)&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER));
  // gem billed i resource filen.
  dat = 0; //Type ?????
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = img.width();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = img.height();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = img.bytesPerLine();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = img.depth();
  f1.writeBlock((char*)&dat, sizeof(short));
  f1.writeBlock((char*)&dat, sizeof(short));
  idat = img.bits();
  for(int i=0;i<img.numBytes();i++)
    f1.writeBlock((char*)idat++, 1);

  f1.close();

  return atoi(rhd.id);
}

int BxbuilderApp::AddIcon(const QPixmap *pix, QString ofile){
  QFile f1(ofile);
  BX_RESOURCE_ELEMENT_HEADER rhd;
  int t,w,h,bpl, count=0;
  short d,bpp;
  QImage img, imgm, img2;

  img = *pix;
  img.convertDepth(32);

  if(pix->mask()!=0)
  {
    imgm = pix->mask()->convertToImage().convertDepth(32);
  }

  if( f1.open( IO_ReadOnly ) == true)
  {
    f1.readBlock((char*)&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER));
    while(f1.atEnd()==false)
    {
      if(rhd.type == ICON)
      {
        f1.readBlock((char*)&t, sizeof(int));
        f1.readBlock((char*)&w, sizeof(int));
        f1.readBlock((char*)&h, sizeof(int));
        f1.readBlock((char*)&bpl, sizeof(int));
        f1.readBlock((char*)&d, sizeof(short));
        f1.readBlock((char*)&bpp, sizeof(short));
        img2.create(w,h,d);
        f1.readBlock((char*)img2.bits(), (rhd.size/2)-20);
        if(imgm==img2)
        {
          // resource exists
          f1.close();
          return atoi(rhd.id);
        }
        else
          f1.at(f1.at()+(rhd.size/2));
      }
      else
      {
        if(f1.at(f1.at()+rhd.size)==FALSE)
          exit(0);
      }
      count++;
      f1.readBlock((char*)&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER));
    }
  }
  f1.close();

  if( f1.open( IO_WriteOnly | IO_Append) == false)
  {
    printf("ERROR: cannot create new file.\n");
    return -2;
  }

  unsigned char *idat;
  int dat;

  // billed id = filnavn.
  sprintf(rhd.id,"%d", count);
  rhd.type = ICON;
  rhd.size = (img.numBytes() + 20) * 2;
  f1.writeBlock((char*)&rhd, sizeof(BX_RESOURCE_ELEMENT_HEADER));
  // gem mask i resource filen.
  dat = 0; //Type ?????
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = imgm.width();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = imgm.height();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = imgm.bytesPerLine();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = imgm.depth();
  f1.writeBlock((char*)&dat, sizeof(short));
  f1.writeBlock((char*)&dat, sizeof(short));
  idat = imgm.bits();
  for(int i=0;i<imgm.numBytes();i++)
    f1.writeBlock((char*)idat++, 1);

  // gem icon i resource filen.
  dat = 0; //Type ?????
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = img.width();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = img.height();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = img.bytesPerLine();
  f1.writeBlock((char*)&dat, sizeof(int));
  dat = img.depth();
  f1.writeBlock((char*)&dat, sizeof(short));
  f1.writeBlock((char*)&dat, sizeof(short));
  idat = img.bits();
  for(int i=0;i<img.numBytes();i++)
    f1.writeBlock((char*)idat++, 1);

  f1.close();
  return atoi(rhd.id);
}

int BxbuilderApp::AddString(QString s, QString ofile){
  QFile f1(ofile);
  QTextStream s1(&f1);
  int count=0;

  if( f1.open( IO_ReadOnly ) == true)
  {
    while(s1.eof()==false)
    {
      if(s == s1.readLine())
      {
        f1.close();
        return count;
      }
      count++;
    }
  }
  f1.close();

  if( f1.open( IO_WriteOnly | IO_Append) == false)
  {
    printf("ERROR: cannot create new bxl-file.\n");
    return -2;
  }

  s1<<s + "\n";
  
  f1.close();

  return count;
}


int BxbuilderApp::SaveProject(QString filename)
{
  QFile f1(filename);
  f1.open( IO_WriteOnly );

  QTextStream t1 ( &f1 );

  QListViewItem *e = project->firstChild();
  if(e)
  {
    while(e)
    {
      t1 << e->text(1) + "\n";
      e = e->nextSibling();
    }
  }

  f1.close();
  return TRUE;
}

int BxbuilderApp::LoadProject(QString filename)
{
  QString fileName, s, s3;
  QListViewItem *element;
  QFile f1(filename);
  f1.open( IO_ReadOnly );
  QString s1 = filename.section( "/", -1 );
  QString s2 = filename.section( "/"+s1, 0 );

  QTextStream t1 ( &f1 );

  dialoglist->clear();
  project = new QListViewItem( dialoglist, NULL );
  project->setText(0, "New project");
  
  while(!f1.atEnd())
  {
    fileName = t1.readLine();
    element = new QListViewItem( project, dialoglist->lastItem() );
    s = fileName.section( '/', -1 );
    element->setText(0, s);
    s3 = s2 + "/" + s;
    element->setText(1, s3);
  }
  f1.close();
  return TRUE;
}
