//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formIconCode.c
#include "Bx.h"
#include "formIcon.h"

BX_VOID formIconInit(HBOX hBox)
{
  //PIXMAP ID = 0
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABYES), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(0, "data/robostacker.bxr"), 0);
  //PIXMAP ID = 1
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABNO), BSTM_SETIMAGE, (BX_WPARAM)BxResourceLoadBxBitmap(1, "data/robostacker.bxr"), 0);
  //ICON ID = 2
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABSHUTDOWN), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(2, "data/robostacker.bxr"), 0);
  //ICON ID = 3
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABWARNING), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(3, "data/robostacker.bxr"), 0);
  //ICON ID = 4
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABPROGRAM), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(4, "data/robostacker.bxr"), 0);
  //ICON ID = 5
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABVISION), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(5, "data/robostacker.bxr"), 0);
  //ICON ID = 6
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABTOOLS_2), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(6, "data/robostacker.bxr"), 0);
  //ICON ID = 7
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABTOOLS), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(7, "data/robostacker.bxr"), 0);
  //ICON ID = 8
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABUNLOCK), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(8, "data/robostacker.bxr"), 0);
  //ICON ID = 9
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABSCOPE), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(9, "data/robostacker.bxr"), 0);
  //ICON ID = 10
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABOPTION), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(10, "data/robostacker.bxr"), 0);
  //ICON ID = 11
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABBOX), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(11, "data/robostacker.bxr"), 0);
  //ICON ID = 12
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABBAGS), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(12, "data/robostacker.bxr"), 0);
  //ICON ID = 13
  BxSendMessage(BxGetDlgItem(hBox, FORMICON_LABPALMBOX), BSTM_SETICON, (BX_WPARAM)BxResourceLoadBxIcon(13, "data/robostacker.bxr"), 0);
}

BX_VOID formIconUpdate(HBOX hBox)
{
}

