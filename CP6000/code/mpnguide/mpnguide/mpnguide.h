/****************************************************************************
* Copyright (C) 2003 Thomas Noerby, MPN A/S.  All rights reserved.          *
*****************************************************************************/
#ifndef MPNGUIDE_H
#define MPNGUIDE_H

#include <qmainwindow.h>
#include <qwidget.h>
#include <qmap.h>

class MPNScript;
class MPNView3D;
class MPNViewData;
class QLabel;
class QLineEdit;
class QSlider;
class QComboBox;
class QSpinBox;
class QListBox;

class MPNGuide : public QWidget
{
    Q_OBJECT
public:
    MPNGuide( QWidget* parent = 0, const char* name = 0 );
    ~MPNGuide();
public slots:
  void fullScreen();
  void setOrto();
  void setResam();
  void setMaterial();
  void showData();
  void showXY();
  void show3D();
  void showDyno();
  void help();
//  void valueEditTextChanged( const QString& newText );
public:
  MPNScript  *mpnscript;
	QListBox *boptlist;
  MPNViewData *mpnviewdata;
  MPNViewData *mpnviewdyno;
  MPNView3D   *mpnview3d;
  MPNView3D   *mpnviewxy;

  QPopupMenu *file;
  QPopupMenu *tmpnplant;
  QPopupMenu *func;
  QPopupMenu *view;
  QPopupMenu *tmpnworkcell;
  QPopupMenu *tmpnrobot;
  QToolBar   *fileTools;

	QWidget    *central;
  QLabel     *status;
	QLabel     *msg;
  QLabel     *label4;
	QSpinBox   *spinScaleFactor;
	QSpinBox   *spinTanFactor;
	QSpinBox   *spinMaxSamples;
	QSpinBox   *spinHeightMM;
	QSpinBox   *spinCoeffType;
	QSpinBox   *spinCoeffIdx;
	QLineEdit  *editCoeff;
	QSpinBox   *spinRepeat;
	QSpinBox   *spinPlayIdx;
	QComboBox  *fromPattern;
	QComboBox  *toPattern;
	QComboBox  *fromFrame;
	QComboBox  *toFrame;
	QComboBox  *fromItem;
	QComboBox  *toItem;
	QSpinBox   *spinFromPatternIdx;
	QSpinBox   *spinToPatternIdx;
  int        material_id;
  int        orto_id;
  int        resam_id;
  int        full_id;
  int        showData_id;
  int        showDyno_id;
  int        showXY_id;
  int        show3D_id;


public:
};


#endif // GLOBJWIN_H
