/***************************************************************************
                          BxValue.h  -  description
                             -------------------
    begin                : Wed Sep 17 2003
    copyright            : (C) 2003 by lms
    email                : lms@mpn.nu
 ***************************************************************************/

#define BX_INT_VALUE    1
#define BX_LONG_VALUE   2
#define BX_FLOAT_VALUE  3
#define BX_STRING_VALUE 4

typedef struct BXINTVALUESTRUCT {
  BX_INT type;               // int, float, mm
  BX_INT value;              // value
  BX_CHAR vstr[20];          // value string
} BXINTVALUESTRUCT;

typedef struct BXFLOATVALUESTRUCT {
  BX_INT type;               // int, float, mm
  BX_FLOAT value;              // value
  BX_CHAR vstr[20];          // value string
} BXFLOATVALUESTRUCT;

typedef struct BXSTRINGVALUESTRUCT {
  BX_INT type;            // int, float, mm
  BX_INT length;           // length
  BX_CHAR *vstr;          // value string
} BXSTRINGVALUESTRUCT;

extern BX_BOOL BxAssignIntValue(HBOX hBox);
extern BX_BOOL BxSetIntValue(HBOX hBox, BX_INT val);
extern BX_INT BxGetIntValue(HBOX hBox);
extern BX_BOOL BxAssignFloatValue(HBOX hBox);
extern BX_BOOL BxSetFloatValue(HBOX hBox, BX_FLOAT val);
extern BX_FLOAT BxGetFloatValue(HBOX hBox);
extern BX_BOOL BxDeleteValue(HBOX hBox);
extern BX_BOOL BxAssignStringValue(HBOX hBox);
extern BX_BOOL BxSetStringValue(HBOX hBox, BX_PSTRING val);
extern BX_PSTRING BxGetStringValue(HBOX hBox);
extern BX_BOOL BxDeleteValue(HBOX hBox);
