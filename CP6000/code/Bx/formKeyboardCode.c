//////////////////////////////////////////////////////
// 
// formKeyboardCode.c
// 
////////////////////////////////////////////////////// 
#include "Bx.h"
#include "formKeyboard.h"
BX_BOOL formKeyboardInit(HBOX hBox)
{
  return TRUE;
}
BX_BOOL formKeyboardUpdate(HBOX hBox)
{
  return TRUE;
}
void formKeyboard_BxButton1_Click(HBOX hBox)
{
  BxEndDialog(hBox,IDCANCEL);
}
