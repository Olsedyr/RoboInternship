/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#include <qtextstream.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlistbox.h>
#include <qspinbox.h>
#include <qpixmap.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qslider.h>
#include <qlayout.h>
#include <qframe.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qapplication.h>
#include <qkeycode.h>
#include <qmainwindow.h>
#include <qmessagebox.h>

#include "cmd.h"
#include "mpnscript.h"
#include "mpnguide.h"
#include "mpnview3d.h"
#include "mpnviewdata.h"



MPNGuide::MPNGuide( QWidget* parent, const char* name )
    : QWidget( parent, name )
{
  char s[256];
  QLabel* upperstatus = new QLabel( this );
  upperstatus->setText("current point");
  upperstatus->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  upperstatus->setAlignment( AlignVCenter | AlignLeft );

  QLabel* upperstatus2 = new QLabel( this );
  upperstatus2->setText("force");
  upperstatus2->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  upperstatus2->setAlignment( AlignVCenter | AlignLeft );

  QLabel* lowerstatus = new QLabel( this );
  lowerstatus->setText("Let's pretend this is a status bar");
  lowerstatus->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  lowerstatus->setAlignment( AlignVCenter | AlignLeft );

  QFrame* f3 = new QFrame( this, "frame3" );
  f3->setFrameStyle( QFrame::Sunken | QFrame::Panel );
  f3->setLineWidth( 2 );
  
  // Create a list box in witch mpnscript commands are to be shown
  // the mpnscript has mpnrobot,mpnview3d as child's
  mpnscript = new MPNScript( this, "MPNScript");
  boptlist = new QListBox( this, "boptlist");

  
  //Open a 3d-view and let mpnscript point to it and back
  mpnview3d = new MPNView3D( f3, "mpnview3d" , upperstatus, upperstatus2, lowerstatus, mpnscript);
//  mpnviewxy = new MPNView3D( f3, "mpnviewxy" , upperstatus, upperstatus2, status, mpnscript);
  mpnviewdata = new MPNViewData( f3, "mpnviewdata" , upperstatus, lowerstatus, mpnscript);
//  mpnviewdyno = new MPNViewData( f3, "mpnviewdyno" , upperstatus, status, mpnscript);
  mpnscript->mpnview3d = mpnview3d;
//  mpnscript->mpnviewxy = mpnviewxy;
  mpnscript->mpnviewdata = mpnviewdata;
//  mpnscript->mpnviewdyno = mpnviewdyno;

//  mpnviewxy = new MPNViewXY( f3, "mpnviewxy" , upperstatus, status, mpnscript);

  connect( mpnscript, SIGNAL( selectionChanged( QListViewItem* ) ), mpnscript, SLOT( listBoxItemSelected( QListViewItem* ) )  );
  connect( boptlist, SIGNAL( selectionChanged( QListBoxItem* ) ), mpnscript, SLOT( boptlistSelectedItem(QListBoxItem* ) )  );
//  connect( mpnscript, SIGNAL( doubleClicked( QListViewItem* ) ), mpnscript, SLOT( listBoxItemdoubleClicked( QListViewItem* ) )  );
  QGridLayout *grid = new QGridLayout( 8, 8 );
  QHBoxLayout* hlayout = new QHBoxLayout( NULL, 2, 2, "hlayout");
//  grid->setResizeMode(QLayout::Fixed);
//  hlayout->setResizeMode(QLayout::Fixed);
  hlayout->addWidget( f3, 1 );
	hlayout->addLayout( grid );

  // Create a menu
  file = new QPopupMenu( this );
  view = new QPopupMenu( this );
  func = new QPopupMenu( this );
  tmpnplant = new QPopupMenu( this );
  tmpnworkcell = new QPopupMenu( this );
  tmpnrobot = new QPopupMenu( this );
  view->setCheckable(true);
  func->setCheckable(true);

  file->insertItem( "New", mpnscript, SLOT(newScript()) );
  file->insertItem( "&Open", mpnscript, SLOT(loadScript()) );
  file->insertItem( "&Save", mpnscript, SLOT(saveScript()) );
  file->insertItem( "Save &As", mpnscript, SLOT(saveAsScript()) );
  file->insertItem( "Exit",  qApp, SLOT(quit()), CTRL+Key_Q );

  tmpnplant->insertItem( "&Open", mpnscript, SLOT(loadPlant()) );
  tmpnplant->insertItem( "&Save", mpnscript, SLOT(savePlant()) );
  tmpnplant->insertItem( "Save &As", mpnscript, SLOT(saveAsPlant()) );
  
  tmpnworkcell->insertItem( "&select workcell", mpnscript, SLOT(selectCell()) );
  tmpnrobot->insertItem( "&select robot", mpnscript, SLOT(SelectRobot()) );


  full_id   = view->insertItem( "&Show fullscreen", this,  SLOT(fullScreen()) );
//  showXY_id = view->insertItem( "&Show XY", this,  SLOT(showXY()) );
//  show3D_id  = view->insertItem( "&Show 3D", this,  SLOT(show3D()) );
  showData_id  = view->insertItem( "&Show Data", this,  SLOT(showData()) );
//  showDyno_id  = view->insertItem( "&Show Dyno", this,  SLOT(showDyno()) );
  view->insertItem( "&Reset 3D XY", mpnview3d,  SLOT(resetViewXY()) );
  view->insertItem( "&Reset 3D YZ", mpnview3d,  SLOT(resetViewYZ()) );
  view->insertItem( "&Reset 3D XZ", mpnview3d,  SLOT(resetViewXZ()) );
  view->insertItem( "&Reset Data", mpnviewdata,  SLOT(reset()) );
  view->insertItem( "&simulateTRIO", mpnscript,  SLOT(simulateTRIO()) );
  orto_id = view->insertItem( "&Orto", this,  SLOT(setOrto()) );
  resam_id = view->insertItem( "&Resam", this,  SLOT(setResam()) );
  material_id = view->insertItem( "&Material", this,  SLOT(setMaterial()) );
//  func->insertItem( "New &call", mpnscript,  SLOT(newSub()) );
  func->insertItem( "New &path", mpnscript,  SLOT(newPath()) );
//  func->insertItem( "New &frame", mpnscript,  SLOT(newFrame()) );
  func->insertItem( "&heightMM", mpnscript,  SLOT(newPause()) );
  func->insertItem( "&newProgram", mpnscript,  SLOT(newProgram()) );
//  func->insertItem( "New &TomatProgram", mpnscript,  SLOT(newTomatProgram()) );
//  func->insertItem( "New &FlamingoProgram", mpnscript,  SLOT(newFlamingoProgram()) );
//  func->insertItem( "Compile", mpnscript,  SLOT(compileProgram()) );
  // Create a menu bar
  QMenuBar *m = new QMenuBar( this );
  m->setSeparator( QMenuBar::InWindowsStyle );
  m->insertItem("&File", file );
  m->insertItem("&View", view );
  m->insertItem("&Func", func );
//  m->insertItem("&Plant", tmpnplant );
//  m->insertItem("&Workcell", tmpnworkcell );
//  m->insertItem("&Robot", tmpnrobot );
//  m->insertItem("&Scope", mpnscript, SLOT(loadScope()) );
  m->insertItem("&Help", this, SLOT(help()) );

  QLabel* label1 = new QLabel( this );
  label1->setText("timeScale:");
  label1->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  label1->setFixedHeight( label1->sizeHint().height() );
  label1->setAlignment( AlignVCenter | AlignLeft );
  spinScaleFactor = new QSpinBox( this );
  spinScaleFactor->setRange( 1, 10000000 );
  connect( spinScaleFactor, SIGNAL(valueChanged(int)), mpnscript, SLOT(setTimeScale(int)) );

  QLabel* label2 = new QLabel( this );
  label2->setText("playIdx:");
  label2->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  label2->setFixedHeight( label2->sizeHint().height() );
  label2->setAlignment( AlignVCenter | AlignLeft );
  spinPlayIdx = new QSpinBox( this );
  spinPlayIdx->setRange( 0, 10000000 );
  connect( spinPlayIdx, SIGNAL(valueChanged(int)), mpnscript, SLOT(setPlayIdx(int)) );

  QLabel* label3 = new QLabel( this );
  label3->setText("maxSamples:");
  label3->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  label3->setFixedHeight( label3->sizeHint().height() );
  label3->setAlignment( AlignVCenter | AlignLeft );

  spinMaxSamples = new QSpinBox( this );
  spinMaxSamples->setRange( 1, 100000 );
  connect( spinMaxSamples, SIGNAL(valueChanged(int)), mpnscript, SLOT(setMaxSamples(int)) );
  spinMaxSamples->setValue(10);

  label4 = new QLabel( this );
  label4->setText("heightMM:");
  label4->setFrameStyle( QFrame::Panel | QFrame::Sunken );
  label4->setFixedHeight( label4->sizeHint().height() );
  label4->setAlignment( AlignVCenter | AlignLeft );

  spinHeightMM = new QSpinBox( this );
  spinHeightMM->setRange( 0, 2000 );
  connect( spinHeightMM, SIGNAL(valueChanged(int)), mpnscript, SLOT(setHeightMM(int)) );
  spinHeightMM->setValue(0);
  
	spinCoeffIdx = new QSpinBox( this );
  spinCoeffIdx->setRange( 0, 21 );
  connect( spinCoeffIdx, SIGNAL(valueChanged(int)), mpnscript, SLOT(setCoeffIdx(int)) );
  spinCoeffIdx->setValue(0);

//  editCoeff = new QLineEdit( this );
  //spinCoeff->setRange( -10000, 10000 );
//  connect( editCoeff, SIGNAL(textChanged(const QString&)), mpnscript, SLOT(setCoeff(const QString&)) );
//  editCoeff->setText(0);

//  QPushButton* qbReset = new QPushButton( "Reset", this );
//  connect( qbReset, SIGNAL( clicked() ), mpnscript, SLOT( reset() ) );
  QPushButton* qbBoptItem = new QPushButton( "BoptItem", this );
  connect( qbBoptItem, SIGNAL( clicked() ), mpnscript, SLOT( newBoptItem() ) );
//  QPushButton* qbPoint = new QPushButton( "Point", this );
//  connect( qbPoint, SIGNAL( clicked() ), mpnscript, SLOT( newSample() ) );
  QPushButton* qbRefresh = new QPushButton( "Refresh", this );
  connect( qbRefresh, SIGNAL( clicked() ), mpnscript, SLOT( refreshCoeffs() ) );
//  QPushButton* qbPath = new QPushButton( "Path", this );
//  connect( qbPath, SIGNAL( clicked() ), mpnscript, SLOT( newPath() ) );
  fromPattern = new QComboBox( FALSE, this, "read-only combobox" );
  toPattern = new QComboBox( FALSE, this, "read-only combobox" );

  fromFrame = new QComboBox( FALSE, this, "read-only combobox" );
  toFrame = new QComboBox( FALSE, this, "read-only combobox" );

  fromItem = new QComboBox( FALSE, this, "read-only combobox" );
  toItem = new QComboBox( FALSE, this, "read-only combobox" );

  fromPattern->insertItem("2PLASTA");
  fromPattern->insertItem("2PLASTB");
  fromPattern->insertItem("Ferva(S)");
	fromPattern->insertItem("Ferva(L)");
	fromPattern->insertItem("FervaRev(L)");
  toPattern->insertItem("2PLASTA");
  toPattern->insertItem("2PLASTB");
  toPattern->insertItem("Ferva(S)");
  toPattern->insertItem("Ferva(L)");
	toPattern->insertItem("FervaRev(L)");
	int i;
	for (i=0;i<tworkcell->patterns.maxidx;i++)
	{
		fromPattern->insertItem((const char*)tworkcell->patterns.pattern[i].name);
		toPattern->insertItem((const char*)tworkcell->patterns.pattern[i].name);	
	}
	
  int idx=getMachineIdx("Frames");
	for (i=0;i<tworkcell->statemachines.statemachine[idx].numvalue;i++)
	{
		tmpnStateMachineValue* stmval = &tworkcell->statemachines.statemachine[idx].value[i];
		if (stmval->type==FRAME)
		{
			fromFrame->insertItem(stmval->name);
			toFrame->insertItem(stmval->name);
		}
	}
  fromFrame->insertItem("mpos");
  fromItem->insertItem("NULL");
	toItem->insertItem("NULL");
	for (i=0;i<tworkcell->items.maxidx;i++)
	{
		fromItem->insertItem((const char*)tworkcell->items.item[i].name);
		toItem->insertItem((const char*)tworkcell->items.item[i].name);	
	}
  //************************************************************************
  //* boptcoeff
  //************************************************************************
  for(i=0;i<tworkcell->boptcoeff.maxidx;i++)
  {
    sprintf(s,"%02d: %s %s %d %d",i,tworkcell->boptcoeff.name
                                   ,tworkcell->boptcoeff.item[i].pathName
                                   ,tworkcell->boptcoeff.item[i].mode
                                   ,tworkcell->boptcoeff.item[i].pathtype);
    boptlist->insertItem(s,i);
  }

  spinFromPatternIdx = new QSpinBox( this );
  spinFromPatternIdx->setRange( 0, 3000 );
  spinFromPatternIdx->setValue(0);
  connect( spinFromPatternIdx, SIGNAL(valueChanged(int)), mpnscript, SLOT(setFromPatternIdx(int)) );

  spinToPatternIdx = new QSpinBox( this );
  spinToPatternIdx->setRange( 0, 3000 );
  spinToPatternIdx->setValue(0);
  connect( spinToPatternIdx, SIGNAL(valueChanged(int)), mpnscript, SLOT(setToPatternIdx(int)) );

  QPushButton* qbPlay = new QPushButton( "Play", this );
  connect( qbPlay, SIGNAL( clicked() ), mpnscript, SLOT( Play() ) );
  QPushButton* qbDelete = new QPushButton( "Delete", this );
  connect( qbDelete, SIGNAL( clicked() ), mpnscript, SLOT( removeLast() ) );

  grid->addMultiCellWidget( label1,             1, 1, 1, 4 );
  grid->addMultiCellWidget( spinScaleFactor,    1, 1, 5, 8 );
  grid->addMultiCellWidget( label2,             2, 2, 1, 4 );
  grid->addMultiCellWidget( spinPlayIdx,        2, 2, 5, 8 );
  grid->addMultiCellWidget( label3,             3, 3, 1, 4 );
  grid->addMultiCellWidget( spinMaxSamples,     3, 3, 5, 8 );

  grid->addMultiCellWidget( label4,             4, 4, 1, 5 );
  grid->addMultiCellWidget( spinHeightMM,       4, 4, 6, 8 );

  //
  grid->addMultiCellWidget( qbBoptItem,         5, 5, 1, 4 );
//  grid->addMultiCellWidget( qbPoint,            5, 5, 1, 2 );
//  grid->addMultiCellWidget( qbPath,             5, 5, 5, 6 );
  grid->addMultiCellWidget( qbRefresh,          5, 5, 5, 8 );
  //
  grid->addMultiCellWidget( fromFrame,          6, 6, 1, 3 );
  grid->addMultiCellWidget( fromItem,           6, 6, 4, 5 );
  grid->addMultiCellWidget( fromPattern,        6, 6, 6, 7 );
  grid->addMultiCellWidget( spinFromPatternIdx, 6, 6, 8, 8 );

  grid->addMultiCellWidget( toFrame,            7, 7, 1, 3 );
  grid->addMultiCellWidget( toItem,             7, 7, 4, 5 );
  grid->addMultiCellWidget( toPattern,          7, 7, 6, 7 );
  grid->addMultiCellWidget( spinToPatternIdx,   7, 7, 8, 8 );

  grid->addMultiCellWidget( qbPlay,             8, 8, 1, 4 );
  grid->addMultiCellWidget( qbDelete,           8, 8, 5, 8 );
//  grid->addMultiCellWidget( qbReset,            7, 7, 1, 8 ); 
  grid->addMultiCellWidget( boptlist,          9, 45, 1, 8 );
  grid->addMultiCellWidget( mpnscript,          46, 49, 1, 8 );

  
  //Put the GL widgets inside the frames
  QVBoxLayout* glayout  = new QVBoxLayout( f3, 2, 2, "glayout");
  QHBoxLayout* glayoutTop = new QHBoxLayout( NULL, 0, 0, "gflayoutTop");
  QHBoxLayout* glayoutBottom = new QHBoxLayout( NULL, 0, 0, "gflayoutBottom");
  QHBoxLayout* glayoutBottom2 = new QHBoxLayout( NULL, 0, 0, "gflayoutBottom2");
  QHBoxLayout* glayoutBottom3 = new QHBoxLayout( NULL, 0, 0, "gflayoutBottom3");
  QVBoxLayout* glayoutXY  = new QVBoxLayout( NULL, 0, 0, "glayoutXY");
  QVBoxLayout* glayout3D  = new QVBoxLayout( NULL, 0, 0, "glayout3D");
  QVBoxLayout* glayoutData  = new QVBoxLayout( NULL, 0, 0, "glayoutData");
  QVBoxLayout* glayoutDyno  = new QVBoxLayout( NULL, 0, 0, "glayoutDyno");
  glayout->addLayout(glayoutTop);
  glayout->addLayout(glayoutBottom);
  glayout->addLayout(glayoutBottom2);
  glayout->addLayout(glayoutBottom3);

  glayoutTop->addLayout(glayoutXY);
  glayoutBottom->addLayout(glayout3D);
  glayoutBottom2->addLayout(glayoutData);
  glayoutBottom3->addLayout(glayoutDyno);

//  glayoutXY->addWidget( mpnviewxy, 0 );
  glayout3D->addWidget( mpnview3d);
  glayoutData->addWidget( mpnviewdata);
  
  glayout->setStretchFactor ( glayoutBottom, 2 );
  glayout->setStretchFactor ( glayoutBottom2, 1 );

//  glayoutDyno->addWidget( mpnviewdyno, 0 );

  QVBoxLayout* vtoplayout = new QVBoxLayout( this,0 ,0, "vtoplayout");

  QHBoxLayout* hlayout2 = new QHBoxLayout( NULL, 2, 0, "hlayout2");
  QHBoxLayout* hlayout3 = new QHBoxLayout( NULL, 2, 0, "hlayout3");
  QHBoxLayout* hlayout4 = new QHBoxLayout( NULL, 2, 0, "hlayout4");
  hlayout3->addWidget( lowerstatus );
  hlayout2->addWidget( upperstatus );
  hlayout4->addWidget( upperstatus2 );


  vtoplayout->setMenuBar( m );
  vtoplayout->addLayout(hlayout2);
  vtoplayout->addLayout(hlayout4);
  vtoplayout->addLayout(hlayout);
  vtoplayout->addLayout(hlayout3);


//  mpnviewxy->hide();
  view->setItemChecked(showXY_id,false);
  view->setItemChecked(show3D_id,true);
  view->setItemChecked(showData_id,false);
  view->setItemChecked(showDyno_id,false);
  view->setItemChecked(orto_id,false);
  view->setItemChecked(resam_id,false);
  view->setItemChecked(material_id,false);

  boptlist->setSelected(0,true);

    
  mpnviewdata->hide();
}

void MPNGuide::setMaterial()
{
  if(view->isItemChecked(material_id))
  {
    mpnview3d->setMaterial(false);
    view->setItemChecked(material_id,false);
  }
  else
  {
    mpnview3d->setMaterial(true);
    view->setItemChecked(material_id,true);
  }
}

void MPNGuide::setOrto()
{
  if(view->isItemChecked(orto_id))
  {
    mpnview3d->setOrto(false);
    view->setItemChecked(orto_id,false);
  }
  else
  {
    mpnview3d->setOrto(true);
    view->setItemChecked(orto_id,true);
  }
}

void MPNGuide::setResam()
{
  if(view->isItemChecked(resam_id))
  {
//    resam=0;
    view->setItemChecked(resam_id,false);
  }
  else
  {
//    resam=1;
    view->setItemChecked(resam_id,true);
  }
  mpnscript->refreshAll(true);
}

void MPNGuide::fullScreen()
{
  if(view->isItemChecked(full_id))
  {
    showNormal();
    view->setItemChecked(full_id,false);
  }
  else
  {
    mpnscript->setColumnWidth(0,150);
    showFullScreen();
    view->setItemChecked(full_id,true);
  }
}

void MPNGuide::showXY()
{
  if(view->isItemChecked(showXY_id))
  {
    mpnviewxy->hide();
    view->setItemChecked(showXY_id,false);
  }
  else
  {
    mpnviewxy->show();
    view->setItemChecked(showXY_id,true);
  }
}

void MPNGuide::show3D()
{
  if(view->isItemChecked(show3D_id))
  {
    mpnview3d->hide();
    view->setItemChecked(show3D_id,false);
  }
  else
  {
    mpnview3d->show();
    view->setItemChecked(show3D_id,true);
  }
}

void MPNGuide::showData()
{
  if(view->isItemChecked(showData_id))
  {
    mpnviewdata->hide();
    view->setItemChecked(showData_id,false);
  }
  else
  {
    mpnviewdata->show();
    view->setItemChecked(showData_id,true);
  }
}
void MPNGuide::showDyno()
{
  if(view->isItemChecked(showDyno_id))
  {
    mpnviewdyno->hide();
    view->setItemChecked(showDyno_id,false);
  }
  else
  {
    mpnviewdyno->show();
    view->setItemChecked(showDyno_id,true);
  }
}

MPNGuide::~MPNGuide()

{
}

void MPNGuide::help()
{
  static QMessageBox* about = new QMessageBox( "MPNGuide created by Thomas Noerby, MPN A/S - Guided by vision(R)",
  "<h3>MPNGuide</h3>"
  "<ul><li>c konstant"
  "<li>f 1 i bund (fromFrame)"
  "<li>b 1 i top (fromFrame)"
  "<li>p 1 i bund (toFrame)"
  "<li>g 1 i top (toFrame)"
  "<li>l 1 ved z-diff=maxLength"
  "<li>t 1 ved tiltdiff=180"
  "<li>r 1 ved rotdiff=360"
  "</ul>", QMessageBox::Information, 1, 0, 0, this, 0, FALSE );
    about->setButtonText( 1, "Dismiss" );
    about->show();
}



