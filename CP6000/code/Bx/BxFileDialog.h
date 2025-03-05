#define BXFILEDIALOG_LOAD 0 //default
#define BXFILEDIALOG_SAVE 1

typedef struct BXFILEDLGSTRUCT {
  BX_CHAR   Path[255];
  BX_CHAR   Type[255];
  BX_INT    Style;
  BX_CHAR   Filename[1024];
} BXFILEDLGSTRUCT;

extern BX_INT BxFileDialog( HBOX hBox, BXFILEDLGSTRUCT* pFDlg );
