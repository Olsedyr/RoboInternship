#include "Bx.h"

#include "rs.h"
#include "rslib.h"

int supervisorLogin(HBOX hBox)
{
  if(BxVirtualKeyboard( hBox, "user", 10)==IDOK)
  {
    strcpy(userid,BxVirtualKeyboard_GetString());
    BxVirtualKeyboard_LoginMode();
    if(BxVirtualKeyboard( hBox, "", 10)==IDOK)
    {
      strcpy(password,BxVirtualKeyboard_GetString());
    }
    //synonymer
    if(strcmp(userid,"")==0) strcpy(userid,"user");
    //find level for alle kendte brugere
    accesslevel=OPERATORLEVEL;
    if(strcmp(userid,"user")==0&&strcmp(password,"user")==0) accesslevel=SERVICELEVEL;
    if(strcmp(userid,"mpn")==0&&strcmp(password,"Robotten")==0) accesslevel=SERVICELEVEL;
    if(strcmp(userid,"mpn")==0&&strcmp(password,"Rotten")==0) accesslevel=MANAGERLEVEL;
  }
  return accesslevel;
}

BX_BOOL formTools_cmdSupervisor_Click(HBOX hBox)
{
  supervisorLogin(hBox);
  return TRUE;
}

