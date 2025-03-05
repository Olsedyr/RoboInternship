/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#include <qfile.h>
#include <qstringlist.h>
#include <qfiledialog.h>
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <qptrlist.h>
#include <qspinbox.h>
#include <qcombobox.h>
#include "tmpnrobot.h"
#include "mpnscript.h"
#include "mpnguide.h"
#include "qspinbox.h"
#include "mpnview3d.h"
#include "mpnviewdata.h"
#include <math.h>
#include <pthread.h>
#include "tmpnrobot.h"
#include "mpncommand.h"
#include "genscript.h"
#include "scene.h"
#include "cmd.h"
#include <stdlib.h>

extern int layerHeightMM;
static int srefresh=true;
static bool updatePlayidx=true;
volatile int expandpath=0;
static QTime playtime;

static QTime stopur;

static int timerId = 0;// timer interval (millisec)
static int timer_interval = 0;// timer interval (millisec)

pthread_mutex_t dlock_mutex = PTHREAD_MUTEX_INITIALIZER;

extern tmpnBoptCoeffItem coeff;


extern "C" int getFotoFriMM(void)
{
  return 1000;
}

char cttext[11][256]={"viapos1","viahast1","viapos2","viahast2"};
char ctext[22][256]={"a","b","c","d"};

typedef struct tmpnStack
{
  int cItem;       //current number of items
  char frame[256]; //base frame
} tmpnStack;

typedef struct tmpnStacks
{
  int maxidx;       //current number of stacks
  tmpnStack stack[15];
} tmpnStacks;

tmpnStacks stacks={13,{{0,"palletA0"},{1,"palletA1"},{2,"palletB0"},{3,"palletB1"},{4,"palletB2"},{5,"palletB3"},{6,"palletB4"},{7,"palletB5"},{8,"palletB6"},{9,"palletB7"},{10,"palletB8"},{11,"palletB6rev"},{12,"palletB7rev"}}};

int pattern[5][150]={
                    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0} //pattern C11,C18 pallet A
                   ,{2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3} //pattern C11,C18 pallet B
									 ,{4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3,4,5,2,3} //pattern Ferva (S) pallet B
									 ,{8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7,8,9,6,10,7} //pattern Ferva (L) pallet B
										,{10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6,10,12,11,7,6} //pattern FervaRev (L) pallet B
                   };
int fromIdx=0;
int toIdx=0;

int hasStack(char *name)
{
  int s;
  for(s=0;s<stacks.maxidx;s++)
  {
    if(strcmp(stacks.stack[s].frame,name)==0)
      return s; 
  }
  return -1;
}

MPNScript::MPNScript(QWidget *parent, const char *name ) : QListView(parent,name)
{
  srefresh=false;
  m_playAll=true;
  m_runcmd=NULL;
  m_path=NULL;
  m_tpath.maxidx=0;
//  m_tpath.position = (tmpnPosition*)malloc(sizeof(tmpnPosition)*MAXPOSITIONS);
  m_playidx=0;
  m_coeffIdx=0;
  m_coeffType=0;
  m_boptcoeffitem = &coeff; 
  coeff.pathtype = 25;
  coeff.viatype = 0;

  m_ipath.maxidx=0;
//  m_ipath.position = (tmpnPosition*)malloc(sizeof(tmpnPosition)*MAXPOSITIONS);

  m_scope.maxidx=0;
  m_scope.sample = (tmpnScopeItem*)malloc(sizeof(tmpnScopeItem)*MAXSCOPE);
	  addColumn( "MPNCommand" );
  m_sumtime=0.0;
  m_play=false;
  setTimeScale(8000);
  setMaxSamples(10); 
//setCoeff(0); 
  setFocusPolicy( NoFocus );
  timerId = startTimer( timer_interval ); //animation
  setRootIsDecorated( TRUE );
  setAllColumnsShowFocus( TRUE );
  setColumnWidthMode(0,QListView::Manual);
  setColumnWidth(0,350);
  setSorting(-1,FALSE);
  newScript();
//  sprintf(rs_systempath,"/home/thn/broot/database");
  LoadRSSystemData(&rs_param);
  tmpnSetDatabase(rs_systempath);
  LoadCalibrationParam(&rs_param);
  trobot->m_simulateTRIO = 1;
 
  sprintf(rs_param.scriptname,"%sStart",rs_param.script);

  loadScript( rs_param.scriptname );
  
  loadScene((tmpnWorkcell*)tworkcell);
	tmpnBoptCoeff* Bc = getBoptCoeff((tmpnWorkcell*)tworkcell);
	if (Bc!=NULL&&Bc->maxidx>0)
		m_boptcoeffitem = &Bc->item[0];
  srefresh=true;
  m_showType=3;
}

MPNScript::~MPNScript()
{
}

void MPNScript::setTimeScale(int timescale)
{
  if(m_path)
  {
    m_playidx=0;
    m_path->tpathdef.maxTime = timescale;
    generatePath((tmpnRobot*)trobot,&m_path->tpathdef, &m_tpath);
  }
  if(srefresh)
  {
    refreshAll(false);
  }
}

void MPNScript::setMaxSamples(int maxsamples)
{
  m_maxSamples = maxsamples;
  defpathsamprate = maxsamples;
  if(m_path)
  {
    m_path->tpathdef.samplesBetweenKeypoints=defpathsamprate;
    generatePath((tmpnRobot*)trobot,&m_path->tpathdef, &m_tpath);
  }
  if(srefresh)
  {
    refreshAll(false);
  }
}

void MPNScript::setToPatternIdx(int idx)
{
  m_toPatternIdx = idx;
  expandpath=1; 
}

void MPNScript::setFromPatternIdx(int idx)
{
  m_toPatternIdx = idx;
  expandpath=1;
}

void MPNScript::setHeightMM(int value)
{
  layerHeightMM = value;
  expandpath=1;
}

void MPNScript::setCoeffIdx(int value)
{
  char s[256];
  char subs[256];
  if(value>=m_maxCoeffIdx) return;
  m_coeffIdx = value;
	if (m_coeffType>=1&&m_coeffType<=12)
	{
		switch(m_coeffIdx)
		{
		case 0:	sprintf(subs,"c"); break;
		case 1:	sprintf(subs,"f"); break;
		case 2:	sprintf(subs,"ff"); break;
		case 3:	sprintf(subs,"fff"); break;
		case 4:	sprintf(subs,"ffff"); break;
		case 5:	sprintf(subs,"fffff"); break;
		case 6:	sprintf(subs,"b"); break;
		case 7:	sprintf(subs,"bb"); break;
		case 8:	sprintf(subs,"bbb"); break;
		case 9:	sprintf(subs,"bbbb"); break;
		case 10: sprintf(subs,"bbbbb"); break;
		case 11: sprintf(subs,"l"); break;
		case 12: sprintf(subs,"ll"); break;
		case 13: sprintf(subs,"lll"); break;
		case 14: sprintf(subs,"llll"); break;
		case 15: sprintf(subs,"lllll"); break;
		}
	}
  switch(m_coeffType)
  {
    case 0: sprintf(s,"viatype");               m_coeff.sprintf("%d",m_boptcoeffitem->viatype); break;
	  case 1: sprintf(s,"viapos1.x %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viapos[0].x[m_coeffIdx].value); break;
    case 2: sprintf(s,"viapos1.y %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viapos[0].y[m_coeffIdx].value);  break;
    case 3: sprintf(s,"viapos1.z %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viapos[0].z[m_coeffIdx].value);  break;
    case 4: sprintf(s,"viavel1.x %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viavel[0].x[m_coeffIdx].value);  break;
    case 5: sprintf(s,"viavel1.y %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viavel[0].y[m_coeffIdx].value);  break;
    case 6: sprintf(s,"viavel1.z %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viavel[0].z[m_coeffIdx].value);  break;
    case 7: sprintf(s,"viapos2.x %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viapos[1].x[m_coeffIdx].value);  break;
    case 8: sprintf(s,"viapos2.y %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viapos[1].y[m_coeffIdx].value);  break;
    case 9: sprintf(s,"viapos2.z %s",subs);     m_coeff.sprintf("%0.2f",m_boptcoeffitem->viapos[1].z[m_coeffIdx].value);  break;
    case 10: sprintf(s,"viavel2.x %s",subs);    m_coeff.sprintf("%0.2f",m_boptcoeffitem->viavel[1].x[m_coeffIdx].value);  break;
    case 11: sprintf(s,"viavel2.y %s",subs);    m_coeff.sprintf("%0.2f",m_boptcoeffitem->viavel[1].y[m_coeffIdx].value);  break;
    case 12: sprintf(s,"viavel2.z %s",subs);    m_coeff.sprintf("%0.2f",m_boptcoeffitem->viavel[1].z[m_coeffIdx].value);  break;
    case 13: 
      switch(m_coeffIdx)
      {
        case 0: sprintf(s,"macro1.int type"); break;
        case 1: sprintf(s,"macro1.int hint"); break;
      } 
      m_coeff.sprintf("%d",m_boptcoeffitem->macro[0].integer[m_coeffIdx]); 
      break;
    case 14:
      switch(m_coeffIdx)
      {
        case 0: sprintf(s,"macro1.float length"); break;
        case 1: sprintf(s,"macro1.float time"); break;
        case 2: sprintf(s,"macro1.float ampl"); break;
        case 3: sprintf(s,"macro1.float offx"); break;
        case 4: sprintf(s,"macro1.float offy"); break;
        case 5: sprintf(s,"macro1.float frekv"); break;
      } 
      m_coeff.sprintf("%0.2f",m_boptcoeffitem->macro[0].floating[m_coeffIdx]); 
      break;
    case 15: 
      switch(m_coeffIdx)
      {
        case 0: sprintf(s,"macro2.int type"); break;
        case 1: sprintf(s,"macro2.int hint"); break;
      } 
      m_coeff.sprintf("%d",m_boptcoeffitem->macro[1].integer[m_coeffIdx]);
      break;
	  case 16: 
      switch(m_coeffIdx)
      {
			  case 0: sprintf(s,"macro2.float length"); break;
        case 1: sprintf(s,"macro2.float time"); break;
        case 2: sprintf(s,"macro2.float ampl"); break;
        case 3: sprintf(s,"macro2.float offx"); break;
        case 4: sprintf(s,"macro2.float offy"); break;
        case 5: sprintf(s,"macro2.float frekv"); break;
      } 
      m_coeff.sprintf("%0.2f",m_boptcoeffitem->macro[1].floating[m_coeffIdx]); 
      break;
    case 17: sprintf(s,"mv");           m_coeff.sprintf("%0.2f",m_boptcoeffitem->mv[m_coeffIdx]); break;
    case 18: sprintf(s,"ma");           m_coeff.sprintf("%0.2f",m_boptcoeffitem->ma[m_coeffIdx]); break;
    case 19: 
      switch(m_coeffIdx)
      {
        case 0: sprintf(s,"params.int tcpidx"); break;
        case 1: sprintf(s,"params.int blendtype"); break;
      }
      m_coeff.sprintf("%d",m_boptcoeffitem->params.integer[m_coeffIdx]); 
      break;
    case 20: 
      switch(m_coeffIdx)
      {
        case 0: sprintf(s,"params.float maxheight"); break;
        case 1: sprintf(s,"params.float minheight"); break;
        case 2: sprintf(s,"params.float samplerate"); break;
        case 3: sprintf(s,"params.float timefactor"); break;
			  case 4: sprintf(s,"params.float maxlength"); break;
      } 
      m_coeff.sprintf("%0.2f",m_boptcoeffitem->params.floating[m_coeffIdx]); 
      break;
  }
  if(m_path)
  {
    if (m_path->tpathdef.runbopt) 
    {
      ((MPNGuide*)parent())->spinScaleFactor->setValue( (int)m_path->tpathdef.maxTime );
    }
  }
}

void MPNScript::setCoeffType(int value)
{
  m_coeffType = value;
  switch(m_coeffType)
  {
    case 0: m_maxCoeffIdx = 1; break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12: m_maxCoeffIdx = 16; break;
    case 13:
    case 15: m_maxCoeffIdx = 2; break;
    case 14: 
    case 16: m_maxCoeffIdx = 6; break;
    case 17: 
    case 18: m_maxCoeffIdx = 5; break; 
    case 19: m_maxCoeffIdx = 2; break;
    case 20: m_maxCoeffIdx = 5; break;
  }
  
  ((MPNGuide*)parent())->spinCoeffIdx->setRange(0,m_maxCoeffIdx-1);

  setCoeffIdx(0);
  ((MPNGuide*)parent())->spinCoeffIdx->setValue(0);
//if(m_path)
}

void MPNScript::Play()
{
  m_play=!m_play;
  if(m_play)
  {
    playtime.restart();
  }
}

void MPNScript::reset()
{
  m_sumtime=0.0;
}

void MPNScript::refreshAll(bool )
{
	pthread_mutex_lock(&dlock_mutex);
  mpnview3d->refreshAll();
  if(mpnviewdata->isVisible()) mpnviewdata->refreshAll();
	pthread_mutex_unlock(&dlock_mutex);
}

void MPNScript::boptlistSelectedItem( QListBoxItem *item)
{
  int idx = ((MPNGuide*)parent())->boptlist->currentItem();
  if(idx>=0)
  {
	  m_boptcoeffitem=&((tmpnWorkcell*)tworkcell)->boptcoeff.item[idx];
  	setCoeffType(0);
    
    ((MPNGuide*)parent())->fromFrame->setCurrentText(m_boptcoeffitem->def.fromFrame);
    ((MPNGuide*)parent())->toFrame->setCurrentText(m_boptcoeffitem->def.toFrame);
    ((MPNGuide*)parent())->fromItem->setCurrentText(m_boptcoeffitem->def.fromItem);
    ((MPNGuide*)parent())->toItem->setCurrentText(m_boptcoeffitem->def.toItem);
    ((MPNGuide*)parent())->fromPattern->setCurrentText(m_boptcoeffitem->def.fromPattern);
    ((MPNGuide*)parent())->toPattern->setCurrentText(m_boptcoeffitem->def.toPattern);

//  	((MPNGuide*)parent())->spinCoeffType->setValue(0);
    expandpath=1;
  } 
}

void MPNScript::listBoxItemSelected(  QListViewItem* i)
{
  MPNCommand *cmd = (MPNCommand*)i;
  POINTSTRUCT *point;
  //if running return

  if(cmd==NULL||cmd->cmd==NULL)
  {
     m_runcmd=NULL;
     m_path=NULL;
     return;
  }
  {  
    if(cmd->cmd->type==PATH)
    {
      m_runcmd = cmd->cmd;
      m_path=(PATHSTRUCT*)m_runcmd->data;
      m_path->tpathdef.samplesBetweenKeypoints=defpathsamprate;
        // if bopt then boptcmd 
      expandpath=1;
    }
    else if(cmd->cmd->type==POINT)
    {
      point = (POINTSTRUCT *)cmd->cmd->data;
      if(tmpnComputeIK((tmpnRobot*)trobot,point->p.x,point->p.y,point->p.z,point->p.v,point->p.w,point->p.u,point->p.tcpidx))
      {
      }
      if(m_path!=point->path)
      {
        m_path=point->path;
        if(m_path!=NULL)
        {
          generatePath((tmpnRobot*)trobot,&m_path->tpathdef, &m_tpath);
          ((MPNGuide*)parent())->spinScaleFactor->setValue( (int)m_path->tpathdef.maxTime );
        }
      }
      refreshAll(false);
    }
    else
    {
      m_path=NULL;
    }
  }
}

void MPNScript::removeLast()
{

  MPNCommand *cur=(MPNCommand*)currentItem();
  COMMANDSTRUCT *cmd=NULL;
  if(cur)
  {
    m_path = NULL;
    m_runcmd = NULL;
    if(cur->cmd) deleteCommand(cur->cmd);
    delete cur;
    cur=(MPNCommand*)currentItem();
    if(cur!=NULL&&cur->cmd!=NULL)
    {
      cmd=cur->cmd;
    }
//    compileProgram();
    if(cmd!=NULL)
    {
      setCurrentItem((MPNCommand*)cmd->listitem);
//      for(parent=(MPNCommand*)currentItem();parent!=NULL;parent=parent->parent())
//      {
//        parent->setVisible(true);
//      }
    }
  }
}

COMMANDSTRUCT *root=NULL;
void MPNScript::newProgram()
{
  COMMANDSTRUCT *ptrcmd;
  COMMANDSTRUCT *command;
  QString s,sp;
  QStringList lst,lstp;
  bool ok;
  int level=0,i,res = QInputDialog::getInteger(
          "Layer height", "Enter a number:", 2000, 1, 2000, 1,
          &ok, this );
  layerHeightMM = res;
  
  for(i=0;i<tworkcell->ppscripts.maxidx;i++)
  {
    lstp<<((char*)(tworkcell->ppscripts.ppscript[i].name));
  }

  sp=QInputDialog::getItem("select ppscript", "Select an item:",lstp,0,FALSE,&ok,this);
//  sp="30410Kg_80";
  //TODO read from ppscript and display inputdialog for each parameter that can be used
  //in the chosen ppscript script generation example: layerHeight + layer + item + ...

  stopur.restart();

  newScript();
  updatePlayidx=false;
  tworkcell->m_root=addCommandString(NULL,"ROOT",&level);
    //Use same generateProgram for all types
  ptrcmd=generateProgramNS((COMMANDSTRUCT*)tworkcell->m_root,(tmpnRobot*)trobot,&level,res,res%9,sp);
  ptrcmd=addCommandString(ptrcmd,"END",&level);

  m_runcmd=NULL;
  m_path=NULL;
  
  m_runcmd = getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
  refreshPath(m_runcmd);
  m_path=(PATHSTRUCT*)m_runcmd->data;
  generatePath((tmpnRobot*)trobot,&m_path->tpathdef, &m_tpath);
  

//  int forbrug = stopur.restart();
//  sprintf(buf,"ms=%d",forbrug);
//  QMessageBox::information( this, "Stopur",stopur.toString("hh:mm:ss.zzz"),buf);
    
  for(command=(COMMANDSTRUCT*)tworkcell->m_root;command!=NULL;command=command->next)
  {
    newCommand(command);
  }


  updatePlayidx=true;
  
}

void MPNScript::newTomatProgram()
{
  COMMANDSTRUCT *command;
  int level=0;
 // bool ok;
//  int res = QInputDialog::getInteger(
//          "Number of boxes", "Enter a number:", 36, 1, 36, 1,
//          &ok, this );
  newScript();
  updatePlayidx=false;
  tworkcell->m_root=addCommandString(NULL,"ROOT",&level);
//  generateTomatProgram((COMMANDSTRUCT*)tworkcell->m_root,(tmpnRobot*)trobot,&level
//                    ,"Netto",0,res,"EuropalleNettoA");
  for(command=(COMMANDSTRUCT*)tworkcell->m_root;command!=NULL;command=command->next)
  {
    newCommand(command);
  }
  updatePlayidx=true;
}

void MPNScript::newFlamingoProgram()
{
  COMMANDSTRUCT *command;
  int level=0;
//  bool ok;
 // int res = QInputDialog::getInteger(
 //         "Number of boxes", "Enter a number:", 32, 0, 32, 1,
 //         &ok, this );
  newScript();
  updatePlayidx=false;
  tworkcell->m_root=addCommandString(NULL,"ROOT",&level);
//  generateFlamingoProgram((COMMANDSTRUCT*)tworkcell->m_root,(tmpnRobot*)trobot,&level
//                      ,"HSflamingo",0,res,"HSflamingoA","HSflamingoB");
  for(command=(COMMANDSTRUCT*)tworkcell->m_root;command!=NULL;command=command->next)
  {
    newCommand(command);
  }
  updatePlayidx=true;
}

void MPNScript::newScript()
{
  clear();
  if(trobot==NULL) return;
  RemoveAllCommands((COMMANDSTRUCT**)&tworkcell->m_root);
  m_path = NULL;
  m_runcmd = NULL;
  if(srefresh)
  {
    refreshAll(false);
  }
}

void MPNScript::loadScript()
{
  QString fn = QFileDialog::getOpenFileName( QString::null, QString::null, this);
  char fileName[256];
  char *filename=&fileName[0];
  int i;

  if ( !fn.isEmpty() )
  {
    newScript();
    sprintf(fileName,"%s",fn.latin1());
    fileName[strlen(fileName)-4]=0; 
    for(i=strlen(fileName)-1;i>0;i--)
    {
      if(fileName[i]=='/')
      {
        filename=&fileName[i+1];
        break;
      }
    }
     
    loadScript( filename );
  }
}

void MPNScript::loadScope()
{
  QString fn = QFileDialog::getOpenFileName( QString::null, QString::null, this);
  if ( !fn.isEmpty() )
  {
    m_scope.maxidx=0;
    tmpnScopeLoad( fn , &m_tpath);
  }
}

/*void MPNScript::saveCoeffs()
{
	switch( QMessageBox::question( this, "Saving",
																 "Really save current BoptCoeff?\n\n",
																 "Yes",
																 "No", 0, 0, 1 ) ) {
	case 0: // The user clicked the Retry again button or pressed Enter
		// try again
		tmpnBoptCoeffSave(&((tmpnWorkcell*)tworkcell)->boptcoeff);
		break;
	case 1: // The user clicked the Quit or pressed Escape
		// exit
		break;
	}
}*/
void MPNScript::expandPath()
{
  int stackFromItem=-1;
  int stackToItem=-1;

  if(m_path)
  {
    if (m_path->tpathdef.runbopt) 
    {
      int i,s,sFrom,sTo;
      char *fromname=NULL,*toname=NULL;
      tmpnFrame tFromFrame = {"tFrom",0.0,0.0,0.0,0.0,0.0,0.0};
      tmpnFrame tToFrame = {"tTo",0.0,0.0,0.0,0.0,0.0,0.0};
      m_fromPatternIdx = ((MPNGuide*)parent())->spinFromPatternIdx->text().toInt();
      m_toPatternIdx = ((MPNGuide*)parent())->spinToPatternIdx->text().toInt();
      m_fromPattern = getPattern(((MPNGuide*)parent())->fromPattern->currentText(),(tmpnWorkcell*)tworkcell);
      m_toPattern = getPattern(((MPNGuide*)parent())->toPattern->currentText(),(tmpnWorkcell*)tworkcell);
      QString fromFrameName = ((MPNGuide*)parent())->fromFrame->currentText();
      QString toFrameName = ((MPNGuide*)parent())->toFrame->currentText();
			m_fromPatternID = ((MPNGuide*)parent())->fromPattern->currentItem();
			m_toPatternID = ((MPNGuide*)parent())->toPattern->currentItem();
      m_fromItem = getItem(((MPNGuide*)parent())->fromItem->currentText(),(tmpnWorkcell*)tworkcell);
      m_toItem = getItem(((MPNGuide*)parent())->toItem->currentText(),(tmpnWorkcell*)tworkcell);
      tmpnFrame *fromFrame;
      if(strcmp((char *)fromFrameName.latin1(),"mpos") == 0)
      {
        tFromFrame.x = trobot->m_worldPoint.x;
        tFromFrame.y = trobot->m_worldPoint.y;
        tFromFrame.z = trobot->m_worldPoint.z;
        tFromFrame.v = trobot->m_worldPoint.v;
        tFromFrame.w = trobot->m_worldPoint.w;
        tFromFrame.u = trobot->m_worldPoint.u;
				fromFrame = &tFromFrame;
      }
      else
      {
        fromFrame = getStmFrame((char *)fromFrameName.latin1());
      }
      tmpnFrame *toFrame = getStmFrame((char *)toFrameName.latin1());
      m_fromFrame = fromFrame;
      m_toFrame = toFrame;
      sFrom=hasStack((char *)fromFrameName.latin1());
      sTo=hasStack((char *)toFrameName.latin1());
			for(s=0;s<stacks.maxidx;s++)
      {
        stacks.stack[s].cItem=0; 
      }
      if(sFrom>=0)
      {
        for(i=0;i<m_fromPatternIdx;i++)
        {
          stacks.stack[pattern[m_fromPatternID][i]].cItem++;
        }
        stackFromItem = stacks.stack[sFrom].cItem;
      }
      else
        stackFromItem = m_fromPatternIdx; 
       
      if(sTo>=0)
      {
        for(i=0;i<m_toPatternIdx;i++)
        {
          stacks.stack[pattern[m_toPatternID][i]].cItem++;
        }
        stackToItem = stacks.stack[sTo].cItem;
      }
      else
        stackToItem = m_toPatternIdx; 
      if(m_fromItem!=NULL) fromname=m_fromItem->name;
      if(m_toItem!=NULL) toname=m_toItem->name;
			if(m_fromPattern!=NULL)
      {
        tFromFrame.x = fromFrame->x + m_fromPattern->item[m_fromPatternIdx].wcp.x;
        tFromFrame.y = fromFrame->y + m_fromPattern->item[m_fromPatternIdx].wcp.y;
        tFromFrame.z = fromFrame->z + m_fromPattern->item[m_fromPatternIdx].wcp.z;
        tFromFrame.v = fromFrame->v + m_fromPattern->item[m_fromPatternIdx].wcp.v;
        tFromFrame.w = fromFrame->w + m_fromPattern->item[m_fromPatternIdx].wcp.w;
        tFromFrame.u = fromFrame->u + m_fromPattern->item[m_fromPatternIdx].wcp.u;
				fromFrame = &tFromFrame;
        stackFromItem = layerHeightMM;
      }
			if(m_toPattern!=NULL)
      {
        tToFrame.x = toFrame->x + m_toPattern->item[m_toPatternIdx].wcp.x;
        tToFrame.y = toFrame->y + m_toPattern->item[m_toPatternIdx].wcp.y;
        tToFrame.z = toFrame->z + m_toPattern->item[m_toPatternIdx].wcp.z;
        tToFrame.v = toFrame->v + m_toPattern->item[m_toPatternIdx].wcp.v;
        tToFrame.w = toFrame->w + m_toPattern->item[m_toPatternIdx].wcp.w;
        tToFrame.u = toFrame->u + m_toPattern->item[m_toPatternIdx].wcp.u;
        toFrame = &tToFrame;
        stackToItem = layerHeightMM;
      }
			expandPathBoptGeneric((tmpnRobot*)trobot
                           ,&m_path->tpathdef
                           ,stackFromItem
                           ,stackToItem
                           ,0
                           ,fromFrame
                           ,toFrame
                           ,fromname
                           ,toname
                           ,0
                           ,m_boptcoeffitem->mode
                           ,m_boptcoeffitem->pathtype
                           ,getBoptCoeff((tmpnWorkcell*)tworkcell));
		}
    else 
    {
      refreshPath(m_runcmd);
		}
    generatePath((tmpnRobot*)trobot,&m_path->tpathdef, &m_tpath);
		((MPNGuide*)parent())->spinScaleFactor->setValue( (int)m_path->tpathdef.maxTime );
  }
  if(srefresh)
  {
    refreshAll(false);
  }
}

void MPNScript::refreshCoeffs()
{
	tmpnBoptCoeff *b = &((tmpnWorkcell*)tworkcell)->boptcoeff;
	tmpnBoptCoeffLoad(b->filename,b);
  expandpath=1;
}

void MPNScript::newPath()
{
  MPNCommand *i       = (MPNCommand*)currentItem();
  COMMANDSTRUCT* pathcmd;
  COMMANDSTRUCT* cur;
  POINTSTRUCT *point;
  int level=0;
  if(i==NULL) return;
  cur = i->cmd;
  if(cur==NULL) return;
  level=cur->flag;
  point = (POINTSTRUCT *)cur->data;
  pathcmd = addCommandString(cur,"PATH x id=0,type=30,time=10000,loadgroup=0,runbopt=0",&level);
  newCommand(pathcmd);
  setCurrentItem((MPNCommand*)pathcmd->listitem);
}

void MPNScript::newBoptItem()
{
	char s[256];
  QString ss;
  QStringList lst;
  int i;
  bool ok;
 
  for(i=0;i<tworkcell->boptcoeff.maxidx;i++)
  {
    sprintf(s,"%02d: %s %s %d %d",i,tworkcell->boptcoeff.name
                                   ,tworkcell->boptcoeff.item[i].pathName
                                   ,tworkcell->boptcoeff.item[i].mode
                                   ,tworkcell->boptcoeff.item[i].pathtype);
    lst<<s;
  }
  ss=QInputDialog::getItem("Adjust coeff", "Select an item:",lst,1,FALSE,&ok,NULL);
  sscanf(ss.latin1(),"%d",&i);
  
	m_boptcoeffitem=&((tmpnWorkcell*)tworkcell)->boptcoeff.item[i];
	setCoeffType(0);
  
  ((MPNGuide*)parent())->fromFrame->setCurrentText(m_boptcoeffitem->def.fromFrame);
  ((MPNGuide*)parent())->toFrame->setCurrentText(m_boptcoeffitem->def.toFrame);
  ((MPNGuide*)parent())->fromItem->setCurrentText(m_boptcoeffitem->def.fromItem);
  ((MPNGuide*)parent())->toItem->setCurrentText(m_boptcoeffitem->def.toItem);
  ((MPNGuide*)parent())->fromPattern->setCurrentText(m_boptcoeffitem->def.fromPattern);
  ((MPNGuide*)parent())->toPattern->setCurrentText(m_boptcoeffitem->def.toPattern);

//	((MPNGuide*)parent())->spinCoeffType->setValue(0);
}

void MPNScript::newSample()
{
  MPNCommand *i       = (MPNCommand*)currentItem();
  COMMANDSTRUCT* cmd;
  COMMANDSTRUCT* cur;
  POINTSTRUCT *point;
  int level=0;
  if(m_path==NULL) return;
  if(i==NULL) return;
  cur = i->cmd;
  if(cur==NULL) return;
  level=cur->flag;
  if(cur->type==PATH)
  {
    level++;
    cmd = addCommandString(cur,"POINT home 0.0,0.0,0.0,0.0,0.0",&level);
    ((POINTSTRUCT *)cmd->data)->frameidx=0;
    adjPoint(cmd,trobot->m_worldPoint.x
                ,trobot->m_worldPoint.y
                ,trobot->m_worldPoint.z
                ,trobot->m_worldPoint.v
                ,trobot->m_worldPoint.w
                ,trobot->m_worldPoint.u
                ,10.0,0);
  }
  else if(cur->type==POINT)
  {
    cmd = addCommandString(cur,"POINT - 0.0,0.0,0.0,0.0,0.0",&level);
    point = (POINTSTRUCT *)cur->data;
    ((POINTSTRUCT *)cmd->data)->frameidx=point->frameidx;
    ((POINTSTRUCT *)cmd->data)->p.tcpidx=point->p.tcpidx;
    adjPoint(cmd,trobot->m_worldPoint.x
                ,trobot->m_worldPoint.y
                ,trobot->m_worldPoint.z
                ,trobot->m_worldPoint.v
                ,trobot->m_worldPoint.w
                ,trobot->m_worldPoint.u
                ,10.0,point->p.tcpidx);
  }
  else
  {
    return;
  }
  newCommand(cmd);
  ((POINTSTRUCT*)cmd->data)->path=m_path;

  generatePath((tmpnRobot*)trobot,&m_path->tpathdef, &m_tpath);
  setCurrentItem((MPNCommand*)cmd->listitem);
}

void MPNScript::newPause()
{
  bool ok;
  int res = QInputDialog::getInteger(
          "Layer height", "Enter a number:", 2000, 1, 2000, 1,
          &ok, this );
  layerHeightMM = res;
}


void MPNScript::generatePalletProgram()
{
}

//here we insert a COMMANDSTRUCT into listview
MPNCommand *MPNScript::newCommand(COMMANDSTRUCT *cmd)
{
  MPNCommand *after=NULL;
  MPNCommand *newitem=NULL;
  COMMANDSTRUCT *parent=NULL;
  COMMANDSTRUCT *previus=NULL;
  if(cmd==NULL) return NULL;
  //works for both cmd and runcmd
  parent = getParentCommand(cmd);
  previus = getPreviusCommand(cmd);
  if(previus!=NULL) after=(MPNCommand*)previus->listitem;
  if(parent==NULL)
  {
    if(this->firstChild()==NULL)
		{
      newitem = new MPNCommand(this,cmd);
		}
    else
		{
      newitem=new MPNCommand((MPNCommand*)this->firstChild(),after,cmd);
		}
    newitem->cmd->listitem=newitem;
  }
  else
  {
    newitem=new MPNCommand((MPNCommand*)parent->listitem,after,cmd);
		newitem->cmd->listitem=newitem;
  }
  return newitem;
}

//here we insert a (run)COMMANDSTRUCT into listview
MPNCommand *MPNScript::newRunCommand(COMMANDSTRUCT *cmd)
{
  MPNCommand *after=NULL;
  MPNCommand *newitem=NULL;
  COMMANDSTRUCT *parent=NULL;
  COMMANDSTRUCT *previus=NULL;
  if(cmd==NULL) return NULL;
  //works for both cmd and runcmd
  parent = getParentCommand(cmd);
  previus = getPreviusCommand(cmd);
  if(previus!=NULL) after=(MPNCommand*)previus->listitem;
  if(parent==NULL)
  {
    newitem = new MPNCommand(this,cmd);
		newitem->cmd->listitem=newitem;
  }
  else
  {
    newitem=new MPNCommand((MPNCommand*)parent->listitem,after,cmd);
		newitem->cmd->listitem=newitem;
  }
  return newitem;
}

void MPNScript::loadScript( const char *fileName )
{
  char fn[256];
  COMMANDSTRUCT *cmd;
/*  if(strcmp(&fname[strlen(fname)-4],".rss")) 
  {
    jointToTask((char *)fileName)
    sprintf(fn,"%s.rss",fileName);
  }
  else*/ 
  {
    sprintf(fn,"%s",fileName);
  }
  tworkcell->m_root=LoadCommandScript((char *)fn, 0);
  //LoadCommandScript((char *)fileName, 0);
  //copy to listview
  for(cmd=(COMMANDSTRUCT*)tworkcell->m_root;cmd!=NULL;cmd=cmd->next)
  {
    newCommand(cmd);
  }
}

void MPNScript::compileProgram()
{
  COMMANDSTRUCT *command;
  m_path = NULL;
  m_runcmd = NULL;
  clear();
//  CreateRunScript(); //should only be called when commands are added or deleted
  //copy to listview
  for(command=(COMMANDSTRUCT*)tworkcell->m_root;command!=NULL;command=command->next)
  {
    newCommand(command);
  }
//  //copy to listview
//  for(command=firstruncmd;command!=NULL;command=command->next)
//  {
//    newRunCommand(command);
//  }
}

void MPNScript::saveScript()
{
  if ( filename.isEmpty() )
  {
    saveAsScript();
    return;
  }                                                          
  SaveCommandScript((COMMANDSTRUCT*)tworkcell->m_root,(char*)filename.latin1());
}

void MPNScript::setPlayIdx(float x, float y, float z, float v, float w, float )
{
  int i;
  if(m_path==NULL) return;
  for ( i= 0; i < m_tpath.maxidx; i++)
  {
    if(fabs(m_tpath.position[i].taskSpace.x-x)<0.1
    && fabs(m_tpath.position[i].taskSpace.y-y)<0.1
    && fabs(m_tpath.position[i].taskSpace.z-z)<0.1
    && fabs(m_tpath.position[i].taskSpace.v-v)<0.1
    && fabs(m_tpath.position[i].taskSpace.w-w)<0.1)
    {
      m_playidx=i;
    }
  }
  if(m_playidx>=m_tpath.maxidx) m_playidx = m_tpath.maxidx-1;
  if(m_playidx<0) m_playidx=0;
}

void MPNScript::setPlayIdx(int i)
{
  m_playidx=i;
  if(m_path==NULL) return;
  if(!m_play)
    if(m_tpath.maxidx>0)
      m_sumtime=(float)m_playidx*m_path->tpathdef.maxTime/(float)m_tpath.maxidx;


  if(m_playidx>=m_tpath.maxidx) m_playidx = m_tpath.maxidx-1;
  if(m_playidx<0) m_playidx=0;
  if(tmpnComputeIK((tmpnRobot*)trobot
                  ,m_tpath.position[m_playidx].taskSpace.x
                  ,m_tpath.position[m_playidx].taskSpace.y
                  ,m_tpath.position[m_playidx].taskSpace.z
                  ,m_tpath.position[m_playidx].taskSpace.v
                  ,m_tpath.position[m_playidx].taskSpace.w
                  ,m_tpath.position[m_playidx].taskSpace.u
                  ,m_tpath.position[m_playidx].tcpidx)) 
  {
    tmpnJointToActuator((tmpnRobot*)trobot,m_tpath.position[m_playidx].tcpidx);
    refreshAll(false);
  }
//    setCurrentItem((MPNCommand*)m_tpath.position[m_playidx].);

}

void MPNScript::setSelectedIdx(int )
{
  //find which keyPoint we are at
//  for(i=0;i<idx;i++)
//  {
//    m_path->tpathdef.keypoint
//  }
/*  itm = (MPNCommand*)item(sel);
  if(itm!=NULL)
  {
    updatePlayidx=false;
    setSelected(sel,true);
    updatePlayidx=true;
  }  */
}

void MPNScript::saveAsScript()
{
  QString fn = QFileDialog::getSaveFileName( QString::null, QString::null, this );
  if ( !fn.isEmpty() )
  {
	  filename = fn;
	  saveScript();
  }
}

void MPNScript::miniStep(int stepsize)
{
  COMMANDSTRUCT *runcmd=NULL;

  if(stepsize>0)
  {
    runcmd=getNextRunCommand(m_runcmd);
    if(runcmd==NULL)
      m_runcmd=getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
    else
      m_runcmd=runcmd;
  }
  else
  {
    runcmd = getPrevRunCommand(m_runcmd);
    if(runcmd==NULL)
      m_runcmd = getLastRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
    else
      m_runcmd=runcmd;
  }
//  setSelected((MPNCommand*)runcmd->listitem,true);
  if(m_runcmd->type==PATH)
  {
    refreshPath(m_runcmd);
  }
  if(m_runcmd!=NULL)
    setCurrentItem((MPNCommand*)m_runcmd->listitem);
}


void MPNScript::refreshAllPoints()
{
  MPNCommandIterator it((MPNCommand*)firstChild());
  while ( it.current() )
  {
    if(it.current()->cmd!=NULL&&(it.current()->cmd->type==POINT||it.current()->cmd->type==RPOINT||it.current()->cmd->type==EPOINT||it.current()->cmd->type==EPOINT))
    {
      it.current()->refresh();
    }
    ++it;
  }
}

void MPNScript::simulateTRIO()
{
  trobot->m_simulateTRIO = !trobot->m_simulateTRIO;
  if(m_path)
  {
    generatePath((tmpnRobot*)trobot,&m_path->tpathdef, &m_tpath);
    refreshAll(false);
  }
}
  
void MPNScript::drawData()
{
  int i,prev;
  tmpnFloat lastxx,xx;
  if(m_path==NULL) return;
  draw1000Nm();
  lastxx=0.0;
  prev=0;
  for ( i= prev+1; i < m_tpath.maxidx; i++)
  {
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
    xx=m_tpath.position[i].t;
    
    glColor3f(10.0f,0.0f,0.0f);

    glVertex3f(lastxx,0.01*m_tpath.position[prev].pctRatedSpeed.name.a,0.0);
    glVertex3f(xx,0.01*m_tpath.position[i].pctRatedSpeed.name.a,0.0);
    glColor3f(0.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,0.01*m_tpath.position[prev].pctRatedSpeed.name.b,0.0);
    glVertex3f(xx,0.01*m_tpath.position[i].pctRatedSpeed.name.b,0.0);
    glColor3f(0.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,0.01*m_tpath.position[prev].pctRatedSpeed.name.c,0.0);
    glVertex3f(xx,0.01*m_tpath.position[i].pctRatedSpeed.name.c,0.0);
    glColor3f(0.0f, 10.0f, 10.0f);
    glVertex3f(lastxx,0.01*m_tpath.position[prev].pctRatedSpeed.name.d,0.0);
    glVertex3f(xx,0.01*m_tpath.position[i].pctRatedSpeed.name.d,0.0);
    glColor3f(10.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,0.01*m_tpath.position[prev].pctRatedSpeed.name.e,0.0);
    glVertex3f(xx,0.01*m_tpath.position[i].pctRatedSpeed.name.e,0.0);
    glColor3f(10.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,0.01*m_tpath.position[prev].pctRatedSpeed.name.f,0.0);
    glVertex3f(xx,0.01*m_tpath.position[i].pctRatedSpeed.name.f,0.0);
    lastxx=xx;
    prev=i;
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }
/*  for ( i=0; i < m_path->tpathdef.maxhidx; i++)
  {
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
    glColor3f(10.0f,10.0f,10.0f);
    glVertex3f(m_tpath.position[m_path->tpathdef.hpoint[i].i].t  ,1.0,0.0);
    glVertex3f(m_tpath.position[m_path->tpathdef.hpoint[i].i].t  ,-1.0,0.0);
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }*/
  for ( i=0; i < m_path->tpathdef.maxpidx; i++)
  {
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
    glColor3f(10.0f,10.0f,10.0f);
//    glVertex3f(m_tpath.position[m_path->tpathdef.poshint[i].i].t  ,1.0,0.0);
//    glVertex3f(m_tpath.position[m_path->tpathdef.poshint[i].i].t  ,-1.0,0.0);
    glVertex3f(m_path->tpathdef.poshint[i].time  ,1.0,0.0);
    glVertex3f(m_path->tpathdef.poshint[i].time  ,-1.0,0.0);
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }
}


void MPNScript::draw1000Nm()
{
  glPushMatrix();
  glEnable(GL_COLOR_MATERIAL);
  glBegin(GL_LINES);
  glColor3f(10.0f,10.0f,10.0f);
  glVertex3f(0.0,1.0,0.0);
  glVertex3f(m_tpath.position[m_tpath.maxidx-1].t,1.0,0.0);
  glVertex3f(0.0,0.0,0.0);
  glVertex3f(m_tpath.position[m_tpath.maxidx-1].t,0.0,0.0);
  glVertex3f(0.0,-1.0,0.0);
  glVertex3f(m_tpath.position[m_tpath.maxidx-1].t,-1.0,0.0);
  glVertex3f(0.0,1.0,0.0);
  glVertex3f(0.0,-1.0,0.0);
  glColor3f(10.0f,10.0f,10.0f);
  glVertex3f(m_tpath.position[m_playidx].t,1.0,0.0);
  glVertex3f(m_tpath.position[m_playidx].t,-1.0,0.0);
  glEnd();
  glDisable(GL_COLOR_MATERIAL);
  glPopMatrix();
}

void MPNScript::drawDyno()
{
  int i,prev;
  tmpnFloat lastxx=0.0,xx;
  if(m_path==NULL) return;
  draw1000Nm();
  prev=0;
  for ( i= prev+1; i < m_tpath.maxidx; i++)
  {
    xx=m_tpath.position[i].t;
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
    glColor3f(10.0f,0.0f,0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].force.name.a/trobot->m_maxForceNm.name.a,0.0);
    glVertex3f(xx,m_tpath.position[i].force.name.a/trobot->m_maxForceNm.name.a,0.0);
    glColor3f(0.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].force.name.b/trobot->m_maxForceNm.name.b,0.0);
    glVertex3f(xx,m_tpath.position[i].force.name.b/trobot->m_maxForceNm.name.b,0.0);
    glColor3f(0.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].force.name.c/trobot->m_maxForceNm.name.c,0.0);
    glVertex3f(xx,m_tpath.position[i].force.name.c/trobot->m_maxForceNm.name.c,0.0);
    glColor3f(0.0f, 10.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].force.name.d/trobot->m_maxForceNm.name.d,0.0);
    glVertex3f(xx,m_tpath.position[i].force.name.d/trobot->m_maxForceNm.name.d,0.0);
    glColor3f(10.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].force.name.e/trobot->m_maxForceNm.name.e,0.0);
    glVertex3f(xx,m_tpath.position[i].force.name.e/trobot->m_maxForceNm.name.e,0.0);
    glColor3f(10.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].force.name.f/trobot->m_maxForceNm.name.f,0.0);
    glVertex3f(xx,m_tpath.position[i].force.name.f/trobot->m_maxForceNm.name.f,0.0);
    lastxx=xx;
    prev=i;
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }
}

void MPNScript::drawAccel()
{
  int i,prev;
  tmpnFloat lastxx,xx;
  
  if(m_path==NULL) return;
  draw1000Nm();
  lastxx=0.0;
  prev=0;

  for ( i= 1; i < m_tpath.maxidx; i++)
  {
    xx=m_tpath.position[i].t;
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
    glColor3f(10.0f,0.0f,0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].accelRad.name.a/(PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].accelRad.name.a/(PI*PI),0.0);
    glColor3f(0.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].accelRad.name.b/(PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].accelRad.name.b/(PI*PI),0.0);
    glColor3f(0.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].accelRad.name.c/(PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].accelRad.name.c/(PI*PI),0.0);
    glColor3f(0.0f, 10.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].accelRad.name.d/(PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].accelRad.name.d/(PI*PI),0.0);
    glColor3f(10.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].accelRad.name.e/(PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].accelRad.name.e/(PI*PI),0.0);
    glColor3f(10.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].accelRad.name.f/(PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].accelRad.name.f/(PI*PI),0.0);
    lastxx=xx;
    prev=i;
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }
}

void MPNScript::drawJerk()
{
  int i,prev;
  tmpnFloat lastxx,xx;
  
  if(m_path==NULL) return;
  draw1000Nm();
  lastxx=0.0;
  prev=0;

  for ( i= prev+1; i < m_tpath.maxidx; i++)
  {
    xx=m_tpath.position[i].t;
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
    glColor3f(10.0f,0.0f,0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].jerkRad.name.a/(PI*PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].jerkRad.name.a/(PI*PI*PI),0.0);
    glColor3f(0.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].jerkRad.name.b/(PI*PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].jerkRad.name.b/(PI*PI*PI),0.0);
    glColor3f(0.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].jerkRad.name.c/(PI*PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].jerkRad.name.c/(PI*PI*PI),0.0);
    glColor3f(0.0f, 10.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].jerkRad.name.d/(PI*PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].jerkRad.name.d/(PI*PI*PI),0.0);
    glColor3f(10.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].jerkRad.name.e/(PI*PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].jerkRad.name.e/(PI*PI*PI),0.0);
    glColor3f(10.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].jerkRad.name.f/(PI*PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].jerkRad.name.f/(PI*PI*PI),0.0);
    lastxx=xx;
    prev=i;
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }
}

void MPNScript::drawSpeed()
{
  int i,prev;
  tmpnFloat lastxx=0.0,xx;
  if(m_path==NULL) return;
  draw1000Nm();

  prev=0;
  for ( i= 1; i < m_tpath.maxidx; i++)
  {
    xx=m_tpath.position[i].t;
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
    glColor3f(10.0f,0.0f,0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].speedRad.name.a/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].speedRad.name.a/PI,0.0);
    glColor3f(0.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].speedRad.name.b/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].speedRad.name.b/PI,0.0);
    glColor3f(0.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].speedRad.name.c/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].speedRad.name.c/PI,0.0);
    glColor3f(0.0f, 10.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].speedRad.name.d/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].speedRad.name.d/PI,0.0);
    glColor3f(10.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].speedRad.name.e/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].speedRad.name.e/PI,0.0);
    glColor3f(10.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].speedRad.name.f/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].speedRad.name.f/PI,0.0);
    prev=i;
    lastxx=xx;
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }
}


void MPNScript::drawPos()
{
  int i,prev;
  tmpnFloat lastxx=0.0,xx;
  if(m_path==NULL) return;
  draw1000Nm();
  prev=0;
  for ( i= 1; i < m_tpath.maxidx; i++)
  {
    xx=m_tpath.position[i].t;
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);
    glColor3f(10.0f,0.0f,0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].posRad.name.a/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].posRad.name.a/PI,0.0);
    glColor3f(0.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].posRad.name.b/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].posRad.name.b/PI,0.0);
    glColor3f(0.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].posRad.name.c/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].posRad.name.c/PI,0.0);
    glColor3f(0.0f, 10.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].posRad.name.d/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].posRad.name.d/PI,0.0);
    glColor3f(10.0f, 10.0f, 0.0f);
    glVertex3f(lastxx,m_tpath.position[prev].posRad.name.e/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].posRad.name.e/PI,0.0);
    glColor3f(10.0f, 0.0f, 10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].posRad.name.f/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].posRad.name.f/PI,0.0);
    lastxx=xx;
    prev=i;
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }
}

//TODO seperate robot class
void MPNScript::loadPlant()
{
  QString s;
  QStringList lst;
  bool ok;

  //tmpnSetDatabase("/home/thn/broot/database");

  lst<<"HSPack";
  lst<<"Nyhuus";
  lst<<"AlfredKatrine";
  lst<<"304";
  lst<<"305";
  lst<<"307";
  lst<<"401";
  lst<<"308";
  lst<<"309";
  lst<<"310";
  lst<<"602";

  s=QInputDialog::getItem("select plant", "Select an item:",lst,0,FALSE,&ok,this);
  tmpnPlantLoad(s,tplant);
  selectWorkcell(0);
  selectRobot(0);
  loadScene((tmpnWorkcell*)tworkcell);
  trobot->m_simulateTRIO = 1;
}


void MPNScript::selectCell()
{
  int i;
  QString s;
  QStringList lst;
  bool ok;
  for(i=0;i<tplant->workcells.maxidx;i++)
  {
    lst<<tplant->workcells.workcell[i].name;
  }
  i=getWorkcellIdx((const char*)tworkcell->name,tplant);
  s=QInputDialog::getItem("select workcell", "Select an item:",lst,i,FALSE,&ok,this);
  selectWorkcell(getWorkcellIdx(s,tplant));
  selectRobot(0);
  loadScene((tmpnWorkcell*)tworkcell);
  trobot->m_simulateTRIO = 1;
}

void MPNScript::SelectRobot()
{
  int i;
  QString s;
  QStringList lst;
  bool ok;
  for(i=0;i<tworkcell->robots.maxidx;i++)
  {
    lst<<((char*)tworkcell->robots.robot[i].m_name);
  }
  i=getRobotIdx((const char*)trobot->m_name,(tmpnWorkcell*)tworkcell);
  s=QInputDialog::getItem("select robot", "Select an item:",lst,i,FALSE,&ok,this);
  selectRobot(getRobotIdx(s,(tmpnWorkcell*)tworkcell));
  loadScene((tmpnWorkcell*)tworkcell);
  trobot->m_simulateTRIO = 1;
}

void MPNScript::savePlant()
{
  if ( plantname.isEmpty() )
  {
    saveAsPlant();
    return;
  }
  //tmpnPlantSave(plantname.latin1(),&tplant);
}

void MPNScript::saveAsPlant()
{
  QString fn = QFileDialog::getSaveFileName( QString::null, QString::null, this );
  if ( !fn.isEmpty() )
  {
    plantname = fn;
    savePlant();
  }
}

static COMMANDSTRUCT *lastPlayedRunCommand=NULL;

//statemachine simulation
void MPNScript::timerEvent(QTimerEvent*)
{
  int p,next,tsum;
  //char fn[256];

  if(m_runcmd==NULL)
    m_runcmd = getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
  if(m_runcmd==NULL) return;
  if(m_runcmd->type==PATH)
    m_path = (PATHSTRUCT*)m_runcmd->data;
  if(expandpath==1)
  {
    expandpath=0;
		expandPath();
	}
  if(m_play)
  {
    int time = playtime.restart();
    m_sumtime+=(float)time;
    if(m_runcmd==NULL)
      m_runcmd = getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
    if(m_runcmd==NULL) return;
		if(m_runcmd->type==PATH)
      m_path = (PATHSTRUCT*)m_runcmd->data;
     setCurrentItem((MPNCommand*)m_runcmd->listitem);
    //TODO test against this cmd's timeScale
    if(m_sumtime>=(float)((MPNGuide*)parent())->spinScaleFactor->text().toInt())
    {
      if(m_playAll)
      {
        if(m_runcmd->type==PATH)
        {
          m_runcmd = getNextRunCommand(m_runcmd);
          if(m_runcmd==NULL)
            m_runcmd = getFirstRunCommand((COMMANDSTRUCT*)tworkcell->m_root);
          if(m_runcmd==NULL) return;
            setCurrentItem((MPNCommand*)m_runcmd->listitem);
        }
        lastPlayedRunCommand=m_runcmd;
        if(m_runcmd->type==CALL)
        {
          CALLSTRUCT *call;
          call=(CALLSTRUCT*)m_runcmd->data;
          sprintf(rs_param.scriptname,"%s",call->script);
          newScript();
          loadScript( rs_param.scriptname );
          ((MPNGuide*)parent())->spinScaleFactor->setValue( 0 );
        }
				else if(m_runcmd->type==PATH)
        {
          m_path = (PATHSTRUCT*)m_runcmd->data;
          if(m_path==NULL) return;
        }
        else
        {
          m_path=NULL;
          ((MPNGuide*)parent())->spinScaleFactor->setValue( 0 );
          m_runcmd = getNextRunCommand(m_runcmd);
        }
      }
      if(m_runcmd!=NULL&&m_runcmd->type==PATH)
        m_sumtime=-200.0; //simulate spline expand in MC224
      else
        m_sumtime=0.0;
      playtime.restart();
      //m_playidx=0;
      //((MPNGuide*)parent())->spinPlayIdx->setValue( m_playidx );
    }
    else
    {
      if(m_runcmd->type==MACRO)
      {
//          m_macro = (MACROSTRUCT*)m_runcmd->data;
        ((MPNGuide*)parent())->spinPlayIdx->setValue( 0 );
//          ((MPNGuide*)parent())->spinScaleFactor->setValue( 0 );
      }
      else if(m_runcmd->type==PATH&&m_path!=NULL)
      {
        next=0;
        for(p=0;p<m_tpath.maxidx;p++)
        {
          next++;
          tsum = (int)((m_tpath.position[p].t
                /m_tpath.position[m_tpath.maxidx-1].t)
                *(float)m_path->tpathdef.maxTime);
                      
          if(tsum>=m_sumtime)
          {
            m_playidx=p;
            p=m_tpath.maxidx;
          }
        }
        ((MPNGuide*)parent())->spinPlayIdx->setValue( m_playidx );
      }
    }
  }
}

void MPNScript::drawAxis(int axis)
{
  int i,ii,prev;
  tmpnFloat lastxx=0.0,xx;
  if(m_path==NULL) return;
  draw1000Nm();
  ii=1;

  prev=0;

  for ( i= prev+1; i < m_tpath.maxidx; i++)
  {
    xx=m_tpath.position[i].t;
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glBegin(GL_LINES);

    switch(axis)
    {
      case 0: glColor3f(10.0f,0.0f,0.0f); break;
      case 1: glColor3f(0.0f,10.0f,0.0f); break;
      case 2: glColor3f(0.0f,0.0f,10.0f); break;
      case 3: glColor3f(0.0f,10.0f,10.0f); break;
      case 4: glColor3f(10.0f,10.0f,0.0f); break;
    }      

    //draw limit for gear avg torque (ratedNmGear)
    glVertex3f(0.0,0.001*trobot->m_ratedNmGear.array[axis],0.0);
    glVertex3f(m_tpath.position[m_tpath.maxidx-1].t,0.001*trobot->m_ratedNmGear.array[axis],0.0);
    glVertex3f(0.0,-0.001*trobot->m_ratedNmGear.array[axis],0.0);
    glVertex3f(m_tpath.position[m_tpath.maxidx-1].t,-0.001*trobot->m_ratedNmGear.array[axis],0.0);
    //draw torque
    glVertex3f(lastxx,0.001*m_tpath.position[prev].force.array[axis],0.0);
    glVertex3f(xx,0.001*m_tpath.position[i].force.array[axis],0.0);

    glColor3f(10.0f,10.0f,10.0f);
    glVertex3f(lastxx,0.001*m_tpath.position[prev].scope.array[axis],0.0);
    glVertex3f(xx,0.001*m_tpath.position[i].scope.array[axis],0.0);

    glColor3f(10.0f,10.0f,10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].speedRad.array[axis]/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].speedRad.array[axis]/PI,0.0);
    glColor3f(0.0f,10.0f,10.0f);
    glVertex3f(lastxx,m_tpath.position[prev].accelRad.array[axis]/(PI*PI),0.0);
    glVertex3f(xx,m_tpath.position[i].accelRad.array[axis]/(PI*PI),0.0);
    glColor3f(0.5f,0.0f,1.0f);
    glVertex3f(lastxx,m_tpath.position[prev].posRad.array[axis]/PI,0.0);
    glVertex3f(xx,m_tpath.position[i].posRad.array[axis]/PI,0.0);
    lastxx=xx;
    ii++;
    prev=i;
    glEnd();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
  }
}

//********************************************
//draw scene GL stuff
//********************************************
static int coord=-1;
static tmpnMaterial green2Material={{0.05f, 0.55, 0.05, 0.4},{0.08f, 0.55, 0.05, 0.4},{0.5f, 0.5, 0.5, 0.4}, 1.0};


static void gsetmpnMaterial(tmpnMaterial m)
{
  glColor3f(m.ambient[0], m.ambient[1], m.ambient[2]);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, m.diffuse);
  glMaterialfv(GL_FRONT, GL_AMBIENT, m.ambient);
  glMaterialfv(GL_FRONT, GL_SPECULAR, m.specular);
  glMaterialf( GL_FRONT,GL_SHININESS, m.shininess );
}



void makeCoord(void)
{
  coord = glGenLists( 1 );
  glNewList( coord, GL_COMPILE );
  glPushMatrix();
  glEnable(GL_COLOR_MATERIAL);
  //gsetmpnMaterial(RMaterial);
  glBegin(GL_LINES);
  glColor4f(2.0f, 0.0f, 0.0f, 0.8f);	// X AXIS STARTS - COLOR RED
  //gsetmpnMaterial(RMaterial);
  glVertex3f(-100.0f,  0.0f, 0.0f);
  glVertex3f( 100.0f,  0.0f, 0.0f);
  glVertex3f( 100.0f,  0.0f, 0.0f);	// TOP PIECE OF ARROWHEAD
  glVertex3f( 80.0f,  20.0f, 0.0f);
  glVertex3f( 100.0f,  0.0f, 0.0f);	// BOTTOM PIECE OF ARROWHEAD
  glVertex3f( 80.0f, -20.0f, 0.0f);
  glColor4f(0.0f, 2.0f, 0.0f, 0.8f);	// Y AXIS STARTS - COLOR GREEN
  //gsetmpnMaterial(GMaterial);
  glVertex3f( 0.0f,  100.0f, 0.0f);
  glVertex3f( 0.0f, -100.0f, 0.0f);
  glVertex3f( 0.0f,  100.0f, 0.0f);	// TOP PIECE OF ARROWHEAD
  glVertex3f( 20.0f,  80.0f, 0.0f);
  glVertex3f( 0.0f,  100.0f, 0.0f);	// BOTTOM PIECE OF ARROWHEAD
  glVertex3f( -20.0f,  80.0f, 0.0f);
  glColor4f(0.0f, 0.0f, 2.0f, 0.8f);	// Z AXIS STARTS - COLOR BLUE
  //gsetmpnMaterial(BMaterial);
  glVertex3f( 0.0f,  0.0f,  100.0f);
  glVertex3f( 0.0f,  0.0f, -100.0f);
  glVertex3f( 0.0f,  0.0f, 100.0f);	// TOP PIECE OF ARROWHEAD
  glVertex3f( 0.0f,  20.0f, 80.0f);
  glVertex3f( 0.0f, 0.0f, 100.0f);	// BOTTOM PIECE OF ARROWHEAD
  glVertex3f( 0.0f, -20.0f, 80.0f);
  glEnd();
  glDisable(GL_COLOR_MATERIAL);
  glPopMatrix();
  glEndList();
}

void makeVia(int idx)
{
	extern tmpnDualVector viavectpos1;
	extern tmpnVector viavecthast1;
	extern tmpnDualVector viavectpos2;
	extern tmpnVector viavecthast2;
	extern tmpnVector toVector;
	extern tmpnVector fromVector;
	extern macroparamstruct startmacro;
	extern macroparamstruct endmacro;

  glPushMatrix();
  glEnable(GL_COLOR_MATERIAL);
	if (idx==0)
	{
		glColor4f(2.0f, 2.0f, 0.0f, 0.8f);	// VIA 1 START
		glTranslatef((viavectpos1.absx) ? viavectpos1.x : fromVector.x+viavectpos1.x, (viavectpos1.absy) ? viavectpos1.y : fromVector.y+viavectpos1.y+startmacro.length, (viavectpos1.absz) ? viavectpos1.z : fromVector.z+viavectpos1.z);
		glBegin(GL_LINES);
		glVertex3f(0.0f,  0.0f, 0.0f);
		glVertex3f(viavecthast1.x, viavecthast1.y, viavecthast1.z);
		glEnd();
		glTranslatef(viavecthast1.x, viavecthast1.y, viavecthast1.z);
		float len=sqrt(viavecthast1.x*viavecthast1.x+viavecthast1.y*viavecthast1.y+viavecthast1.z*viavecthast1.z);
		GLUquadricObj* quad=gluNewQuadric();
		float angle = acosf(viavecthast1.z/len);
		glRotatef(-RADTODEG(angle),viavecthast1.y+0.001,-viavecthast1.x-0.001,0);
		gluCylinder(quad,len/10.0,0,len/8.0,4,1);
		gluDeleteQuadric(quad);
	}
	else if (idx==1)
	{
		glColor4f(2.0f, 0.0f, 2.0f, 0.8f);	// VIA 2 START
		glTranslatef((viavectpos2.absx) ? viavectpos2.x : toVector.x+viavectpos2.x, (viavectpos2.absy) ? viavectpos2.y : toVector.y+viavectpos2.y+endmacro.length, (viavectpos2.absz) ? viavectpos2.z : toVector.z+viavectpos2.z);
		glBegin(GL_LINES);
		glVertex3f(0.0f,  0.0f, 0.0f);
		glVertex3f(viavecthast2.x,  viavecthast2.y, viavecthast2.z);
		glEnd();
		glTranslatef(viavecthast2.x, viavecthast2.y, viavecthast2.z);
		float len=sqrt(viavecthast2.x*viavecthast2.x+viavecthast2.y*viavecthast2.y+viavecthast2.z*viavecthast2.z);
		GLUquadricObj* quad=gluNewQuadric();
		float angle = acosf(viavecthast2.z/len);
		glRotatef(-RADTODEG(angle),viavecthast2.y+0.001,-viavecthast2.x-0.001,0);
		gluCylinder(quad,len/10.0,0,len/8.0,4,1);		
		gluDeleteQuadric(quad);
	}
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
}

static void drawBone(tmpnBone *bone)
{
	GLUquadricObj* quad = gluNewQuadric();
  glColor3f(bone->color.r, bone->color.g, bone->color.b);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, bone->material.diffuse);
  glMaterialfv(GL_FRONT, GL_AMBIENT, bone->material.ambient);
  glMaterialfv(GL_FRONT, GL_SPECULAR, bone->material.specular);
  glMaterialf( GL_FRONT,GL_SHININESS, bone->material.shininess );

  glTranslatef(bone->trans.x, bone->trans.y, bone->trans.z);
  glRotatef(bone->rot.x, 1.0f, 0.0f, 0.0f);
  glRotatef(bone->rot.y, 0.0f, 1.0f, 0.0f);
  glRotatef(bone->rot.z, 0.0f, 0.0f, 1.0f);

  if(bone->cyl==BONE_BOX)
  {
    glPushMatrix();
    glBegin( GL_POLYGON );
    glVertex3f(     0.0, bone->dim.y, 0.0 );
    glVertex3f(bone->dim.x, bone->dim.y, 0.0 );
    glVertex3f(bone->dim.x,      0.0, 0.0 );
    glVertex3f(     0.0,      0.0, 0.0 );
    glEnd();
    glBegin( GL_POLYGON );
    glVertex3f(     0.0,      0.0, bone->dim.z );
    glVertex3f(bone->dim.x,      0.0, bone->dim.z );
    glVertex3f(bone->dim.x, bone->dim.y, bone->dim.z );
    glVertex3f(     0.0, bone->dim.y, bone->dim.z );
    glEnd();
    glBegin( GL_POLYGON );
    glVertex3f(bone->dim.x, bone->dim.y, 0.0 );
    glVertex3f(bone->dim.x, bone->dim.y, bone->dim.z );
    glVertex3f(bone->dim.x,      0.0, bone->dim.z );
    glVertex3f(bone->dim.x,      0.0, 0.0 );
    glEnd();
    glBegin( GL_POLYGON );
    glVertex3f(0.0,      0.0, 0.0 );
    glVertex3f(0.0,      0.0, bone->dim.z );
    glVertex3f(0.0, bone->dim.y, bone->dim.z );
    glVertex3f(0.0, bone->dim.y, 0.0 );
    glEnd();
    glBegin( GL_POLYGON );
    glVertex3f(0.0,      0.0, 0.0 );
    glVertex3f(bone->dim.x, 0.0, 0.0 );
    glVertex3f(bone->dim.x, 0.0, bone->dim.z );
    glVertex3f(0.0,      0.0, bone->dim.z );
    glEnd();
    glBegin( GL_POLYGON );
    glVertex3f(0.0,      bone->dim.y, bone->dim.z );
    glVertex3f(bone->dim.x, bone->dim.y, bone->dim.z );
    glVertex3f(bone->dim.x, bone->dim.y, 0.0 );
    glVertex3f(0.0,      bone->dim.y, 0.0 );
    glEnd();
    glPopMatrix();
  }
  if(bone->cyl==BONE_CYL)
  {
    glPushMatrix();
    glRotatef(90.0, 0.0f, 1.0f, 0.0f);
    gluCylinder(quad,bone->dim.y,bone->dim.z,bone->dim.x,10,1);
    glRotatef(180.0, 0.0f, 1.0f, 0.0f);
    gluDisk(quad,0.0,bone->dim.y,10,1);
    glRotatef(-180.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0, 0.0, bone->dim.x);
    gluDisk(quad,0.0,bone->dim.z,10,1);
    glPopMatrix();
  }
	gluDeleteQuadric(quad);
}

static void drawBoxSpecific(tmpnItem *item)
{
  if(item==NULL) return;
  glPushMatrix();
  gsetmpnMaterial(green2Material);
  glBegin( GL_POLYGON );
  glVertex3f( 0.0, item->dim.y, 0.0 );
  glVertex3f(item->dim.x, item->dim.y, 0.0 );
  glVertex3f(item->dim.x, 0.0, 0.0 );
  glVertex3f( 0.0, 0.0, 0.0 );
  glEnd();
  glBegin( GL_POLYGON );
  glVertex3f( 0.0, 0.0, item->dim.z );
  glVertex3f(item->dim.x, 0.0, item->dim.z );
  glVertex3f(item->dim.x, item->dim.y, item->dim.z );
  glVertex3f( 0.0, item->dim.y, item->dim.z );
  glEnd();
  glBegin( GL_POLYGON );
  glVertex3f(item->dim.x, item->dim.y, 0.0 );
  glVertex3f(item->dim.x, item->dim.y, item->dim.z );
  glVertex3f(item->dim.x, 0.0, item->dim.z );
  glVertex3f(item->dim.x, 0.0, 0.0 );
  glEnd();
  glBegin( GL_POLYGON );
  glVertex3f(0.0, 0.0, 0.0 );
  glVertex3f(0.0, 0.0, item->dim.z );
  glVertex3f(0.0, item->dim.y, item->dim.z );
  glVertex3f(0.0, item->dim.y, 0.0 );
  glEnd();
  glBegin( GL_POLYGON );
  glVertex3f(0.0, 0.0, 0.0 );
  glVertex3f(item->dim.x, 0.0, 0.0 );
  glVertex3f(item->dim.x, 0.0, item->dim.z );
  glVertex3f(0.0, 0.0, item->dim.z );
  glEnd();
  glBegin( GL_POLYGON );
  glVertex3f(0.0, item->dim.y, item->dim.z );
  glVertex3f(item->dim.x, item->dim.y, item->dim.z );
  glVertex3f(item->dim.x, item->dim.y, 0.0 );
  glVertex3f(0.0, item->dim.y, 0.0 );
  glEnd();
  glPopMatrix();
}

static void drawTool(int tcpidx, tmpnBone *bone, tmpnTool *tool)
{

	GLUquadricObj* quad = gluNewQuadric();
	if(tool==NULL) return;
	
	//case tcp
	glTranslatef(trobot->m_tcp[tcpidx].x
							 ,trobot->m_tcp[tcpidx].y
							 ,trobot->m_tcp[tcpidx].z);
	glRotatef(-trobot->m_tcp[tcpidx].v,0,0,1);
	glRotatef(trobot->m_tcp[tcpidx].w,1,0,0);
	glRotatef(trobot->m_tcp[tcpidx].u,0,1,0);
	glCallList(coord);
  
	glPushMatrix();
	bone->dim.x=tool->dim.y;
	bone->dim.y=tool->dim.x;
	bone->dim.z=tool->dim.z;
	bone->trans.x=0.0;
	bone->trans.y=0.0;
	bone->trans.z=0.0;
	glTranslatef(-tool->dim.y,-tool->dim.x*0.5,-tool->dim.z*0.5);
	drawBone(bone);
	glPopMatrix();

	gluDeleteQuadric(quad);
}

static void drawKeyPointGL(tmpnPathDef *pathdef)
{
  int i,prev;
  tmpnVector p1,p2;
  if(pathdef==NULL) return;
  if(pathdef->maxidx==0) return;
  prev=0;
  p1.x = pathdef->keypoint[prev].x;
  p1.y = pathdef->keypoint[prev].y;
  p1.z = pathdef->keypoint[prev].z;
  p1.v = pathdef->keypoint[prev].v;
  p1.w = pathdef->keypoint[prev].w;
  p1.u = pathdef->keypoint[prev].u;
  glPushMatrix();
  glEnable(GL_COLOR_MATERIAL);
  glBegin(GL_LINES);
  for ( i= prev+1; i < pathdef->maxidx; i++)
  {
    p2.x = pathdef->keypoint[i].x;
    p2.y = pathdef->keypoint[i].y;
    p2.z = pathdef->keypoint[i].z;
    p2.v = pathdef->keypoint[i].v;
    p2.w = pathdef->keypoint[i].w;
    p2.u = pathdef->keypoint[i].u;
    {
      glColor4f(0.7, 0.7, 2.5, 1.0f);
    }
    glVertex3f(p1.x,p1.y,p1.z);
    glVertex3f(p2.x,p2.y,p2.z);
    p1.x=p2.x;
    p1.y=p2.y;
    p1.z=p2.z;
    prev=i;
  }
  glEnd();
  glDisable(GL_COLOR_MATERIAL);
  glPopMatrix();
}

static void drawScriptGL(tmpnPath *path, int drawWhite)
{
  int i,prev;
  tmpnFloat col;
  tmpnVector p1,p2;

  if(path==NULL) return;
  if(path->maxidx==0) return;
  prev=0;
  p1.x = path->position[prev].taskSpace.x;
  p1.y = path->position[prev].taskSpace.y;
  p1.z = path->position[prev].taskSpace.z;
  p1.v = path->position[prev].taskSpace.v;
  p1.w = path->position[prev].taskSpace.w;
  p1.u = path->position[prev].taskSpace.u;


  glPushMatrix();
  glEnable(GL_COLOR_MATERIAL);
  glBegin(GL_LINES);
  glVertex3f(p1.x,p1.y,p1.z);
  for (i=prev+1;i<path->maxidx;i++)
  {
    p2.x = path->position[i].taskSpace.x;
    p2.y = path->position[i].taskSpace.y;
    p2.z = path->position[i].taskSpace.z;
    p2.v = path->position[i].taskSpace.v;
    p2.w = path->position[i].taskSpace.w;
    p2.u = path->position[i].taskSpace.u;
    if(path->position[prev].taskSpace.x<trobot->m_min.x
     ||path->position[prev].taskSpace.y<trobot->m_min.y
     ||path->position[prev].taskSpace.z<trobot->m_min.z
     ||path->position[prev].taskSpace.v<trobot->m_min.v
     ||path->position[prev].taskSpace.w<trobot->m_min.w
     ||path->position[prev].taskSpace.u<trobot->m_min.u
     ||path->position[prev].taskSpace.x>trobot->m_max.x
     ||path->position[prev].taskSpace.y>trobot->m_max.y
     ||path->position[prev].taskSpace.z>trobot->m_max.z
     ||path->position[prev].taskSpace.v>trobot->m_max.v
     ||path->position[prev].taskSpace.w>trobot->m_max.w
     ||path->position[prev].taskSpace.u>trobot->m_max.u
     ||path->position[i].taskSpace.x<trobot->m_min.x
     ||path->position[i].taskSpace.y<trobot->m_min.y
     ||path->position[i].taskSpace.z<trobot->m_min.z
     ||path->position[i].taskSpace.v<trobot->m_min.v
     ||path->position[i].taskSpace.w<trobot->m_min.w
     ||path->position[i].taskSpace.u<trobot->m_min.u
     ||path->position[i].taskSpace.x>trobot->m_max.x
     ||path->position[i].taskSpace.y>trobot->m_max.y
     ||path->position[i].taskSpace.z>trobot->m_max.z
     ||path->position[i].taskSpace.v>trobot->m_max.v
     ||path->position[i].taskSpace.w>trobot->m_max.w
     ||path->position[i].taskSpace.u>trobot->m_max.u)
    {
      glColor4f(3.0f, 0.0f, 0.0f,1.0f);
    }
    else
    {
      if(drawWhite==0)
      {
        col = fabs(path->position[i].pctRatedSpeed.array[path->position[i].maxrev]);
        if(col>100.0) col=100.0;
        glColor4f(col*0.2, 0.0, 20.0-col*0.2,1.0f);
      }
      else
      {
        glColor4f(2.5, 2.5, 2.5,1.0f);
      }
    }
    glVertex3f(p2.x,p2.y,p2.z);
    prev=i;
  }
  glEnd();
  glDisable(GL_COLOR_MATERIAL);
  glPopMatrix();
}

static void drawPlayidxGL(tmpnPath *path, int idx)
{
  if(path==NULL) return;
  glPushMatrix();
  glEnable(GL_COLOR_MATERIAL);
  if(idx>=0&&idx<path->maxidx&&path->position[idx].keypoint!=NULL)
  {
    glTranslatef(path->position[idx].keypoint->x
                ,path->position[idx].keypoint->y
                ,path->position[idx].keypoint->z);
    drawBone(&scene->key);
  }
  glDisable(GL_COLOR_MATERIAL);
  glPopMatrix();
}

static void drawHPointGL(tmpnPathDef *pathdef)
{
  int i;
  if(pathdef==NULL) return;
  glPushMatrix();
  glEnable(GL_COLOR_MATERIAL);
  for(i=0;i<pathdef->maxhidx;i++)
  {
    glPushMatrix();
    glTranslatef(pathdef->hpoint[i].x
                ,pathdef->hpoint[i].y
                ,pathdef->hpoint[i].z);
    drawBone(&scene->key);
    glPopMatrix();
  }
  glDisable(GL_COLOR_MATERIAL);
  glPopMatrix();
}


void drawSceneGL(int drawWhite, MPNScript *mpnscript)
{
	tmpnTool *tool;
	tmpnFloat gantrywidth,footlength,footheight,shoulderlength,emergencylength;
	PATHSTRUCT *pathstruct=mpnscript->m_path;
	tmpnPath *path=&mpnscript->m_tpath;
	int playidx=mpnscript->m_playidx;
	tmpnItem *fromItem=mpnscript->m_fromItem;
	tmpnItem *toItem=mpnscript->m_toItem;
	tmpnFrame *fromFrame=mpnscript->m_fromFrame;
	tmpnFrame *toFrame=mpnscript->m_toFrame;

  int s,f,l,i,ltcpidx;
  static int firstcall=TRUE;
  tmpnItem *item=fromItem;
    
	int wkcell = atoi((const char*)trobot->m_name);
	if((wkcell<400)||(wkcell>499))
	{
		gantrywidth = GANTRY_WIDTH;
		footlength = FOOT_LENGTH;
		footheight = FOOT_HEIGHT;
		shoulderlength = SHOULDER_LENGTH;
		emergencylength = EMERGENCY_LENGTH;
	}
	else
	{
		gantrywidth = GANTRY_WIDTH1;
		footlength = FOOT_LENGTH1;
		footheight = FOOT_HEIGHT1;
		shoulderlength = SHOULDER_LENGTH1;
		emergencylength = EMERGENCY_LENGTH1;
	}	
	if (fromItem==NULL)
  {
    item=toItem;
  }
  if(firstcall)
  {
    makeCoord();
    firstcall=FALSE;
  }
	
  drawBone(&scene->floor);
  glTranslatef(700.0,50.0,(shoulderlength+emergencylength)+100.0);//setFrame(workcell)
  glCallList(coord);
  //now we are at our workcell's origin(0,0,0)
	
  if(path!=NULL)
  {
    drawScriptGL(path,drawWhite);
		makeVia(0);
		makeVia(1);
  }
  if(pathstruct!=NULL)
  {
    drawPlayidxGL(path,playidx);
    drawKeyPointGL(&pathstruct->tpathdef);
    drawHPointGL(&pathstruct->tpathdef);
  }
  {
    tmpnFloat gantrylenhalf;
    //draw gantry
		gantrylenhalf = gantrywidth*0.5;
    glPushMatrix();
		  glTranslatef(-gantrylenhalf,0.0,-(shoulderlength+emergencylength));
			glPushMatrix();
			  drawBone(&scene->foot);
				drawBone(&scene->leg);
				drawBone(&scene->gantry);
			glPopMatrix();
		  glPushMatrix();
		    glTranslatef(0.0,0.0,trobot->m_gantryLength-footlength);
				drawBone(&scene->foot);
				drawBone(&scene->leg);
		  glPopMatrix();
		glPopMatrix();
		
    //draw robot
    //update robot with new position
    //TODO let TRIO-statemachine update robot
    scene->gearA.trans.z = trobot->m_joint.a;
    scene->gearB.rot.z   = trobot->m_joint.b;
    scene->gearC.rot.z   = trobot->m_joint.c;
    scene->gearD.rot.z   = -trobot->m_joint.d;
    scene->gearE.rot.x   = trobot->m_joint.e;
  //  scene->gearF.rot.x   = trobot->m_joint.f;
    glPushMatrix();
      glTranslatef(-gantrylenhalf,FOOT_HEIGHT+trobot->m_legHeight,-(shoulderlength+emergencylength));
      drawBone(&scene->gearA);
      glCallList(coord);
      drawBone(&scene->shoulder);
      glCallList(coord);
      drawBone(&scene->gearB);
      glCallList(coord);
      drawBone(&scene->upperArm);
      glCallList(coord);
      drawBone(&scene->gearC);
      drawBone(&scene->lowerArm);
      glCallList(coord);
      drawBone(&scene->lowerArm2);
      drawBone(&scene->gearD);
      drawBone(&scene->wrist);
      glCallList(coord);
      drawBone(&scene->gearE);
      drawBone(&scene->flange);
      glPushMatrix();
        glCallList(coord);
      glPopMatrix();
  
      ltcpidx=0;
      if(path!=NULL&&path->maxidx>0)
        ltcpidx=path->position[playidx].tcpidx;

      /*********** drawTool  *******************/
			tool=getTool("default",(tmpnWorkcell*)tworkcell);
			if (item!=NULL&&(!strcmp(item->name,"HybschA")||!strcmp(item->name,"EPS610"))) 
			{
				tool=getTool("310P",(tmpnWorkcell*)tworkcell);
			}
			else if (item!=NULL&&(!strcmp(item->name,"KKA"))) 
			{
				tool=getTool("313P",(tmpnWorkcell*)tworkcell);
			}
			else if (item!=NULL&&(!strcmp(item->name,"LNA"))) 
			{
				tool=getTool("314P",(tmpnWorkcell*)tworkcell);
			}
			glPushMatrix();
      drawTool(ltcpidx,&scene->tool,tool);
      if((item!=NULL)&&(pathstruct!=NULL)&&((pathstruct->tpathdef.pathtype==21)||(pathstruct->tpathdef.pathtype==24)||(pathstruct->tpathdef.pathtype==34)))
      {
				int ipl;
				float cpl=tool->itemsperlift*item->dim.x*0.5;
				for (ipl=0;ipl<tool->itemsperlift;ipl++)
				{
					glPushMatrix();
					glRotatef(90,0,0,1);
					glTranslatef(-cpl+(item->dim.x)*ipl,-item->my,-item->dim.z*0.5);
					drawBoxSpecific(item);
					glPopMatrix();
				}
			}
			glPopMatrix();
  }
  glPopMatrix();
  /*******************************************/
  /*********** drawCase  ********************/
  if((item!=NULL)&&(pathstruct!=NULL)&&((pathstruct->tpathdef.pathtype==22)||(pathstruct->tpathdef.pathtype==23)||(pathstruct->tpathdef.pathtype==43)||(pathstruct->tpathdef.pathtype==44)))
  {
  	glPushMatrix();
    if (pathstruct->tpathdef.pathtype==22)
    {
			if(fromFrame!=NULL)
      {
				glTranslatef(fromFrame->x, fromFrame->y, fromFrame->z);
				glRotatef(fromFrame->w, 0.0f, 1.0f, 0.0f);
				glCallList(coord);
      }
    }
    else if (pathstruct->tpathdef.pathtype==43)
    {
      if(fromFrame!=NULL)
      {
				glTranslatef(fromFrame->x-item->gx, fromFrame->y, fromFrame->z);
				glRotatef(fromFrame->w, 0.0f, 1.0f, 0.0f);
				glCallList(coord);
      }
    }
    else if ((pathstruct->tpathdef.pathtype==23)||(pathstruct->tpathdef.pathtype==44))
    {
      if(toFrame!=NULL)
      {
				glTranslatef(toFrame->x-item->gx, toFrame->y, toFrame->z);
				glRotatef(toFrame->w, 0.0f, 1.0f, 0.0f);
				glCallList(coord);
      }
    }
    glPushMatrix();
		int ipl;
		float cpl=tool->itemsperlift*item->dim.x*0.5;
		for (ipl=0;ipl<tool->itemsperlift;ipl++)
		{
			glPushMatrix();
			glTranslatef(-cpl+(item->dim.x)*ipl,0,-item->dim.z*0.5);
			drawBoxSpecific(item);
			glPopMatrix();
		}
    glPopMatrix();

		glPopMatrix();

  }
  /*******************************************/
	
  //ACCESSORIES
  for(l=0;l<scene->accessories.maxidx;l++)
  {
    glPushMatrix();
		drawBone(&scene->accessories.accessory[l]);
    glPopMatrix();
  }
	
  /*******************************************/
	tmpnFrame *fr;
	fr = getStmFrame("palletA");
	if(fr!=NULL)
	{
		glPushMatrix();
		glTranslatef(fr->x
 						  ,fr->y
								 ,fr->z);
   	glCallList(coord);
  	glPushMatrix();
		drawBone(&scene->pallet);
 		glPopMatrix();
    glPopMatrix();
	}
	fr = getStmFrame("palletB");
	if(fr!=NULL)
	{
		glPushMatrix();
		glTranslatef(fr->x
								 ,fr->y
								 ,fr->z);
		glCallList(coord);
  	glPushMatrix();
		if((wkcell>400)&&(wkcell<499))
		{
			glTranslatef(800,0,0);
			glRotatef(-90, 0.0f, 1.0f, 0.0f);
		}
		drawBone(&scene->pallet);
 		glPopMatrix();
    glPopMatrix();
	}

	int stmidx=getMachineIdx("Frames");
	tmpnStateMachine *stmFrames;
  if(stmidx>=0)
    stmFrames = &tworkcell->statemachines.statemachine[stmidx];
  
	int extra;
  for(f=0;f<stmFrames->numvalue;f++)
  {
    if(stmFrames->value[f].type==FRAME)
    { 
      glPushMatrix();
			//glRotatef(stmFrames->value[f].frame->v, 0.0f, 0.0f, 1.0f);
			glTranslatef(stmFrames->value[f].frame->x
    						  ,stmFrames->value[f].frame->y
                  ,stmFrames->value[f].frame->z);
			glRotatef(stmFrames->value[f].frame->w, 0.0f, 1.0f, 0.0f);
      glCallList(coord);
      s=hasStack((char*)stmFrames->value[f].frame->name);
      if(s>=0&&item!=NULL)
      {
	      glPushMatrix();
				extra=0;
				if ((pathstruct->tpathdef.pathtype==25)||(pathstruct->tpathdef.pathtype==44)) 
					if (pattern[mpnscript->m_fromPatternID][mpnscript->m_fromPatternIdx]==s)
						extra++;
				int ipl;
				float cpl=tool->itemsperlift*item->dim.x*0.5;
      	for(i=0;i<stacks.stack[s].cItem+extra;i++)
      	{			
					for (ipl=0;ipl<tool->itemsperlift;ipl++)
					{
						glPushMatrix();
						glTranslatef(-cpl+(item->dim.x)*ipl,0,-0.5*item->dim.z);
						drawBoxSpecific(item);
						glPopMatrix();
					}
          glTranslatef(0.0,item->sy,0.0);
       	}
        glPopMatrix();
      }
		  glPopMatrix();
    }
  }
  
  /******
   * Hardcoded til Saransk Pos 1 (wcid 318), kan måske bruges til andre.
   * Bruger heightMM (sy) som antal lag og bygger pallestakken
   * op efter pattern (f.eks. CanBricks)
   ******/
  if(wkcell == 318)
  {
    tmpnPattern *pattern = NULL;
    tmpnFrame *frame = NULL;
    int patternIdx = 0;
    
    if(pathstruct != NULL)
    {
      if (pathstruct->tpathdef.pathtype == 24)
      {
        pattern = mpnscript->m_toPattern;
        frame = mpnscript->m_toFrame;
        patternIdx = mpnscript->m_toPatternIdx;
      }
      else if ((pathstruct->tpathdef.pathtype==25)
               ||(pathstruct->tpathdef.pathtype==44))
      {
        pattern = mpnscript->m_fromPattern;
        frame = mpnscript->m_fromFrame;
        patternIdx = mpnscript->m_fromPatternIdx;
      }
    }
    if(pattern!=NULL)
    {
      {
        if(item!=NULL)
        {
          int layersInPattern = pattern->item[pattern->maxidx-1].layer+1;//ok?
          
          glPushMatrix();
          glTranslatef(frame->x
                       ,frame->y
                       ,frame->z);
          glRotatef(frame->w, 0.0f, 1.0f, 0.0f);
          glCallList(coord);
          int j;
          for(j=0;j<layerHeightMM;j++)
          {
            for(i=0;i<pattern->maxidx;i++)
            {
              if(pattern->item[i].layer == j % layersInPattern)
              {
                glPushMatrix();
                glTranslatef(pattern->item[i].wcp.x,
                             0,
                             pattern->item[i].wcp.z);
                int ipl;
                float cpl=tool->itemsperlift*item->dim.x*0.5;
                for (ipl=0;ipl<tool->itemsperlift;ipl++)
                {
                  glPushMatrix();
                  glTranslatef(-cpl+(item->dim.x)*ipl,
                               0,
                               -0.5*item->dim.z);
                  drawBoxSpecific(item);
                  glPopMatrix();
                }
                glPopMatrix();
              }
            }
            glTranslatef(0.0,item->sy,0.0);
          }
          
          //draw items from pattern
          int curLayer = pattern->item[patternIdx].layer;
          
          for(i=0;i<patternIdx;i++)
          {
            if(pattern->item[i].layer == curLayer)
            {
              glPushMatrix();
              
              glTranslatef(pattern->item[i].wcp.x,
                           0,
                           pattern->item[i].wcp.z);
              int ipl;
              float cpl=tool->itemsperlift*item->dim.x*0.5;
              for (ipl=0;ipl<tool->itemsperlift;ipl++)
              {
                glPushMatrix();
                glTranslatef(-cpl+(item->dim.x)*ipl,
                             0,
                             -0.5*item->dim.z);
                drawBoxSpecific(item);
                glPopMatrix();
              }
              glPopMatrix();
            }
          }
          glPopMatrix();
        }
      }
    }
  }
}
