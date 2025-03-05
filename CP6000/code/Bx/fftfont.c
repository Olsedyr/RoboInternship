#include "Bx.h"
#include "font.h"

#ifdef DFBDRV
extern BX_BOOL InitDFBFontServer(FONT *font, char* fontname, int height);
#else
#ifdef SDLDRV
extern BX_BOOL InitSDLFontServer(FONT *font, char* fontname, int height);
#endif
#endif

BxFont* DefaultSmallFont;
BxFont* DefaultFont;
BxFont* DefaultButtonFont;
FONT __sysFont;
FONT __sysSmallFont;

//char masktable[8] = {(char)0x80,(char)0x40,(char)0x20,(
//					char)0x10,(char)0x08,(char)0x04,(char)0x02,(char)0x01};
extern char masktable[];

FONT *SYS_FONT;
extern FONT Arial_14;
extern FONT Arial_8;
extern FONT Times_10;
/*
int  num_glyphs;

int  ptsize;
int  hinted;

short  glyph_code[128];
int    num_codes;
*/


int FontStringLength(char *s,FONT *font)
{
  int a=0;
#ifdef DFBDRV
  font->dffont->GetStringWidth(font->dffont, s, -1, &a);
#else 
#ifdef SDLDRV
  SDL_Rect tR;
  
  tR = sge_TTF_TextSize(font->sgefont, s);
  a = tR.w;
#else
  int i, l=strlen(s);
	
	/* add up the character widths of all the characters in the string */
	for(i=0;i<l;i++) 
	{
//		a+=(font->metrics[(unsigned int)s[i]].advance);
		a+=(font->cacheBit[(unsigned int)s[i]].width);
	}
#endif
#endif
	return(a);
}

int FontStringHeight(char *s,FONT *font)
{
  int a=0;
#ifdef DFBDRV
//  font->dffont->GetHeight(font->dffont, &a);
  font->dffont->GetAscender(font->dffont, &a);
#else 
#ifdef SDLDRV
  SDL_Rect tR;
  
  tR = sge_TTF_TextSize(font->sgefont, s);
  a = tR.h;
  a -= sge_TTF_FontAscent(font->sgefont)/2;

#else
  int i, l=strlen(s);;
  /* add up the character widths of all the characters in the string */
	for(i=0;i<l;i++) {
		if(font->cacheBit[(int)s[i]].rows > a)
			a = font->cacheBit[(int)s[i]].rows;
//		if(font->metrics[(unsigned int)s[i]].bbox.yMax/64 > a)
//			a = font->metrics[(unsigned int)s[i]].bbox.yMax/64;
	}
#endif
#endif
  return(a);
}

int InitFontServer(void)
{
#ifdef DFBDRV
  InitDFBFontServer(&__sysFont, "data/decker.ttf", 20);
  DefaultFont = &__sysFont;
  InitDFBFontServer(&__sysSmallFont, "data/decker.ttf", 12);
  DefaultSmallFont = &__sysSmallFont;
#else 
#ifdef SDLDRV

  if(InitSDLFontServer(&__sysFont, "data/decker.ttf", 15)==FALSE)
    printf("error init font %s\n", "data/decker.ttf");
  else
    DefaultFont = &__sysFont;
  if(InitSDLFontServer(&__sysSmallFont, "data/decker.ttf", 12)==FALSE)
    printf("error init font %s\n", "data/decker.ttf");
  else
    DefaultSmallFont = &__sysSmallFont;
#else
  SYS_FONT = &Arial_8;
#endif
#endif
  return 0;
}

int BxOpenFont(FONT *font, BX_PSTRING fontfile, int size)
{
#ifdef DFBDRV
  InitDFBFontServer(font, fontfile, size);
#else 
#ifdef SDLDRV
  if(InitSDLFontServer(font, fontfile, size)==FALSE)
    printf("error init font %s\n", fontfile);
#endif
#endif
  return 0;
}

int BxCloseFont(FONT *font)
{
#ifdef DFBDRV
  font->dffont->Release( font->dffont );
#else 
#ifdef SDLDRV
  sge_TTF_CloseFont(font->sgefont);
#endif
#endif
  return 0;
}

void ShutdownFontServer(void)
{
#ifdef DFBDRV
  __sysFont.dffont->Release( __sysFont.dffont );
#else
#ifdef SDLDRV
  sge_TTF_CloseFont(__sysFont.sgefont);
  sge_TTF_CloseFont(__sysSmallFont.sgefont);
#endif
#endif
}


/* End */
