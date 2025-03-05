#ifndef _FONT_
#define _FONT_

#include "freetype.h"
#ifdef DFBDRV
#include <directfb.h>
#endif
#ifdef SDLDRV
#include <SDL/sge.h>
#endif

#define FONT_LEFTALIGN   1
#define FONT_RIGHTALIGN  2 
#define FONT_CENTERALIGN 4
#define FONT_TOPALIGN    8
#define FONT_BOTTOMALIGN 16
#define FONT_MIDALIGN    32

typedef struct FONT {
  int nFont;
  TT_Raster_Map* cacheBit;
  TT_Glyph_Metrics* metrics;
#ifdef DFBDRV
  IDirectFBFont *dffont;
#endif
#ifdef SDLDRV
  sge_TTFont *sgefont;
#endif
  int size;
} FONT;// *PFONT;

extern FONT *SYS_FONT;

int FontStringLength(char *s,FONT *font);
int InitFontServer(void);
void ShutdownFontServer(void);
extern int BxOpenFont(FONT *font, BX_PSTRING fontfile, int size);
extern int BxCloseFont(FONT *font);

#endif //_FONT_
