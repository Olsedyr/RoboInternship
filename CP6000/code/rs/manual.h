#if !defined(MANUAL_H)
#include "Bx.h"
#include "cmd.h"
#include "stm.h"

BX_BOOL manual_setOutput(const char *stmname, const char *outputname, const int value);
BX_BOOL manual_togleOutput(const char *stmname, const char *outputname);
BX_BOOL manual_resetOutput(const int value);
BX_BOOL manual_activityCheck(HBOX hBox, const int cmdButton);
BX_BOOL manual_idle(const char* stmname);

#endif // MANUAL_H
