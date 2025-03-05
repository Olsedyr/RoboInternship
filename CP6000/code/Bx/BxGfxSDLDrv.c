#include <pthread.h>
#include <unistd.h>
#include "Bx.h"
#include "BxEvent.h"
#include "BxDrivers.h"
#include "font.h"

#include <SDL/SDL.h>
#include <SDL/SDL_thread.h>
#include <SDL/sge.h>

/* pixel packing */

#define PIXEL_RGB332(r,g,b)    ( (((r)&0xE0)     ) | \
                                 (((g)&0xE0) >> 3) | \
                                 (((b)&0xC0) >> 6) )

#define PIXEL_ARGB1555(a,r,g,b)( (((a)&0x80) << 8) | \
                                 (((r)&0xF8) << 7) | \
                                 (((g)&0xF8) << 2) | \
                                 (((b)&0xF8) >> 3) )

#define PIXEL_RGB16(r,g,b)     ( (((r)&0xF8) << 8) | \
                                 (((g)&0xFC) << 3) | \
                                 (((b)&0xF8) >> 3) )

#define PIXEL_RGB32(r,g,b)     ( ((r) << 16) | \
                                 ((g) <<  8) | \
                                  (b) )

#define PIXEL_ARGB(a,r,g,b)    ( ((a) << 24) | \
                                 ((r) << 16) | \
                                 ((g) << 8)  | \
                                  (b) )

#define PIXEL_YUY2(y,u,v)      ( ((v) << 24) | \
                                 ((y) << 16) | \
                                 ((u) << 8)  | \
                                  (y) )

#define PIXEL_UYVY(y,u,v)      ( ((y) << 24) | \
                                 ((v) << 16) | \
                                 ((y) << 8)  | \
                                  (u) )

#define RGB16_TO_RGB32(pixel)  ( (((pixel) & 0xF800) << 8) | \
                                 (((pixel) & 0x07E0) << 5) | \
                                 (((pixel) & 0x001F) << 3) )


#define PIXEL_R32(pixel)     ((pixel & 0x00ff0000) >> 16)
#define PIXEL_G32(pixel)     ((pixel & 0x0000ff00) >> 8)
#define PIXEL_B32(pixel)     ((pixel & 0x000000ff))

#define CLAMP(x, low, high)\
             (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

    /* SDL interprets each pixel as a 32-bit number, so our masks must depend
       on the endianness (byte order) of the machine */
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
unsigned int    rmask = 0xff000000;
unsigned int    gmask = 0x00ff0000;
unsigned int    bmask = 0x0000ff00;
unsigned int    amask = 0x000000ff;
#else
unsigned int    rmask = 0x000000ff;
unsigned int    gmask = 0x0000ff00;
unsigned int    bmask = 0x00ff0000;
unsigned int    amask = 0xff000000;
#endif

pthread_mutex_t sdlscreen_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  sdlscreen_cond  = PTHREAD_COND_INITIALIZER;

SDL_Surface *screen=0;
                                 
static int screen_width, screen_height;

static float swf=1.0;
static float shf=1.0;

unsigned char *frame_buffer=NULL;
static int quit=0;

static BX_VOID BxGfxSDLDrv_CopyVirtualToPhysicArea(BX_RECT *rc);
BxGfxDrvInfo FBInfo;

void DrawFontString(char *s, FONT *font, int x, int y, int color, char align);

#define MAX_COL                  800
#define MAX_ROW                  600

BX_RECT clipRect = {0, 0, MAX_COL, MAX_ROW };

BX_RECT BxSetClipRect(BX_RECT *clip)
{
  BX_RECT bx_curr_rect;
  SDL_Rect curr_rect;
  SDL_Rect new_rect;
  
  SDL_GetClipRect(screen, &curr_rect);
  
  bx_curr_rect.left = curr_rect.x;
  bx_curr_rect.top = curr_rect.y;
  bx_curr_rect.right = curr_rect.x+curr_rect.w;
  bx_curr_rect.bottom = curr_rect.y+curr_rect.h;
  
  new_rect.x = (clip->left-1)*swf;
  new_rect.y = (clip->top-1)*shf;
  new_rect.w = (BxRectWidth(clip)+3)*swf;
  new_rect.h = (BxRectHeight(clip)+3)*shf;
  
  SDL_SetClipRect(screen, &new_rect);
  
  return bx_curr_rect;
}


BX_BOOL InitSDLFontServer(FONT *font, char* fontname, int height)
{
  if(sge_TTF_Init()!=0)
  {
    fprintf(stderr,"TT error: %s\n",SDL_GetError());
    return FALSE;
  }
  font->sgefont = sge_TTF_OpenFont(fontname, height);
  if(font->sgefont==NULL)
  {
    fprintf(stderr,"TT error: %s\n",SDL_GetError());
    return FALSE;
  } 
  sge_TTF_SetFontStyle(font->sgefont, SGE_TTF_NORMAL);
  font->size = height;
  return TRUE;
}

BX_VOID BxSleep(BX_DWORD ms)
{
//	sleepTask(CURRENTTASK, MS_TO_TICKS(ms));
}

void fbcon_bell(void)
{
/*
  int confd =open("/dev/tty1",O_RDWR);

  if(0<confd)
  {
    ioctl(confd, KDMKTONE, (50<<14) + 0x637);
    close(confd);
  }
*/
}


BX_BOOL GreyFramebuffer(BX_VOID)
{
  void                  *data;
  int                    pitch;
  int x, y, width, height;
  SDL_PixelFormat *format;
  
  data = screen->pixels;
  pitch = screen->pitch;
  format = screen->format;
  width = screen->w;
  height = screen->h;
  switch (format->BitsPerPixel) {
	case 16:
		for (y=0; y<height; y++) {
			unsigned short *dst16 = data + y * pitch;
			
			for(x=(y&1); x<width; x+=2)
			{
				dst16[x] = PIXEL_RGB16( 0, 0, 0 );
			}
		}
		break;
	case 32:
		for (y=0; y<height; y++) {
			unsigned int *dst32 = data + y * pitch;
			
			for(x=(y&1); x<width; x+=2)
				dst32[x] = PIXEL_ARGB( 0xff, 0, 0, 0 );
		}
		break;
	default:
		printf("Unhandled pixel format 0x%08x!\n", (unsigned int)format );
		break;
  }
	

  BxGfxSDLDrv_CopyVirtualToPhysicArea(NULL);
  
  return TRUE;
}

BX_BOOL GrapBGFramebuffer(BX_PBITMAP pBmp, BX_PRECT pRc)
{
  int pitch;
  int width, height;
	BX_INT prwidth;
  SDL_PixelFormat *format;
  BX_INT x, y, f;
  BX_VOID *pImg;

  pImg = screen->pixels;
  pitch = screen->pitch;
  format = screen->format;
  width = screen->w;
  height = screen->h;
	prwidth = BxRectWidth(pRc);

  switch (format->BitsPerPixel) {
       case 16:
            f = 0;
            unsigned short *dst16 = pBmp->bmBits;
            for(y=pRc->top; y<=pRc->bottom; y++)
            {
              unsigned short *src16 = pImg + (y * pitch) + (pRc->left * sizeof(unsigned short));
              for(x=0; x<=prwidth; x++)
              {
                dst16[f++] = src16[x];
              }
            }
            break;
       case 32:
            f = 0;
            unsigned int *dst32 = pBmp->bmBits;
            for(y=pRc->top; y<=pRc->bottom; y++)
            {
              unsigned int *src32 = pImg + (y * pitch) + (pRc->left * sizeof(unsigned int));
              for(x=0; x<=prwidth; x++)
              {
                dst32[f++] = src32[x];
              }
            }
            break;
       default:
            printf("Unhandled pixel format %d bit!\n", format->BitsPerPixel );
            break;
  }

  return TRUE;
}

BX_BOOL PutBGFramebuffer(BX_PBITMAP pBmp, BX_PRECT pRc)
{
  int pitch;
  int width, height;
	BX_INT prwidth;
  SDL_PixelFormat *format;
  BX_INT x, y, f;
  BX_VOID *pImg;

  pImg = screen->pixels;
  pitch = screen->pitch;
  format = screen->format;
  width = screen->w;
  height = screen->h;
	prwidth = BxRectWidth(pRc);

  switch (format->BitsPerPixel) {
       case 16:
            f = 0;
            unsigned short *src16 = pBmp->bmBits;
            for(y=pRc->top; y<=pRc->bottom; y++)
            {
              unsigned short *dst16 = pImg + (y * pitch) + (pRc->left * sizeof(unsigned short));
              for(x=0; x<=prwidth; x++)
              {
                dst16[x] = src16[f++];
              }
            }
            break;
       case 32:
            f = 0;
            unsigned int *src32 = pBmp->bmBits;
            for(y=pRc->top; y<=pRc->bottom; y++)
            {
              unsigned int *dst32 = pImg + (y * pitch) + (pRc->left * sizeof(unsigned int));
              for(x=0; x<=prwidth; x++)
              {
                dst32[x] = src32[f++];
              }
            }
            break;
       default:
            printf("Unhandled pixel format %d bit!\n", format->BitsPerPixel );
            break;
  }

  BxGfxSDLDrv_CopyVirtualToPhysicArea(pRc);
  return TRUE;
}

static BX_INT BxGfxSDLDrv_Init(BX_VOID)
{

  int width;
  int height;

  /* start SDL video */

  if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_NOPARACHUTE)==-1)
  {
  	printf("SDL_Init: %s\n",SDL_GetError());
		return 1;
  }

  /* Set window title */
  SDL_WM_SetCaption("Bx SDL", "sdl");

  /* open the screen */

  if(!(screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF )))
  {
		printf("SDL_SetVideoMode: %s\n",SDL_GetError());
		return 1;
  }
  
  swf = (float)screen->w/800.0;
  shf = (float)screen->h/600.0;

  screen_width = width = screen->w;
  screen_height = height = screen->h;

  FBInfo.Width = width;
  FBInfo.Height = height;
  FBInfo.BytesPrPixel = screen->format->BytesPerPixel;
  FBInfo.ByteWidth = FBInfo.Width * FBInfo.BytesPrPixel;

  sge_TTF_AA_Alpha();     

  pthread_mutex_lock( &sdlscreen_mutex );
	pthread_cond_signal( &sdlscreen_cond ); //signal screen init done
 	pthread_mutex_unlock( &sdlscreen_mutex );

  return BX_STATUS_OK;
}

BX_INT BxGfxSDLDrv_Shutdown(BX_VOID)
{
  SDL_Quit();
  return BX_STATUS_OK;
}

static BX_VOID BxGfxSDLDrv_Rectangle(BX_RECT * pRect, BX_COLORREF pen, BX_COLORREF brush, BX_BYTE alpha)
{
  sge_FilledRectAlpha(screen,pRect->left*swf, pRect->top*shf, pRect->right*swf, pRect->bottom*shf, SDL_MapRGB(screen->format,BxGetRValue(brush), BxGetGValue(brush), BxGetBValue(brush)), alpha);
  sge_RectAlpha(screen,pRect->left*swf, pRect->top*shf, pRect->right*swf, pRect->bottom*shf, SDL_MapRGB(screen->format,BxGetRValue(pen), BxGetGValue(pen), BxGetBValue(pen)), alpha);
}


static BX_VOID BxGfxSDLDrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen, BX_BYTE alpha)
{
  sge_LineAlpha(screen,x1*swf, y1*shf, x2*swf, y2*shf, SDL_MapRGB(screen->format,BxGetRValue(pen),BxGetGValue(pen),BxGetBValue(pen)), alpha);
}


static BX_VOID BxGfxSDLDrv_FillRect(BX_RECT * pRect, BX_COLORREF brush, BX_BYTE alpha)
{
  sge_FilledRectAlpha(screen,pRect->left*swf, pRect->top*shf, pRect->right*swf, pRect->bottom*shf, SDL_MapRGB(screen->format,BxGetRValue(brush), BxGetGValue(brush), BxGetBValue(brush)), alpha);
}


static BX_BOOL BxGfxSDLDrv_TextOut(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT * pFont, BX_COLORREF FntClr, BX_COLORREF BkClr, BX_BYTE alpha)
{
//  sge_TTF_SetFontSize(pFont->sgefont, pFont->size);
  sge_tt_textout_UTF8(screen,pFont->sgefont,pStr, x*swf,y*shf,  SDL_MapRGB(screen->format,BxGetRValue(FntClr), BxGetGValue(FntClr), BxGetBValue(FntClr)),  SDL_MapRGB(screen->format,0, 0, 0),alpha); 

  return TRUE;
}



static BX_COLORREF BxGfxSDLDrv_SetPixel(BX_INT x, BX_INT y, BX_COLORREF color, BX_BYTE alpha)
{
  sge_PutPixelAlpha(screen,x*swf, y*shf, SDL_MapRGB(screen->format,BxGetRValue(color), BxGetGValue(color), BxGetBValue(color)), alpha);
  return color;
}


static BX_COLORREF BxGfxSDLDrv_Circle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color, BX_BYTE alpha)
{
  sge_CircleAlpha(screen,cx*swf, cy*shf, r, SDL_MapRGB(screen->format,BxGetRValue(color), BxGetGValue(color), BxGetBValue(color)), alpha);
  return color;
}

static BX_COLORREF BxGfxSDLDrv_FillCircle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color, BX_BYTE alpha)
{
  sge_FilledCircleAlpha(screen,cx*swf, cy*shf, r, SDL_MapRGB(screen->format,BxGetRValue(color), BxGetGValue(color), BxGetBValue(color)), alpha);
  return color;
}

static BX_BOOL BxGfxSDLDrv_PutBitmap(BX_INT x, BX_INT y, BX_PBITMAP pBmp, BX_INT paintType, BX_BYTE alpha)
{
  SDL_Surface *bitmap;

  bitmap = SDL_DisplayFormat(pBmp->img);
  if(paintType == BITMAPTYPE_TRANSPARENT)
  {
  	SDL_SetAlpha(bitmap, SDL_SRCALPHA | SDL_RLEACCEL, alpha);
    SDL_SetColorKey(bitmap, SDL_SRCCOLORKEY|SDL_RLEACCEL, sge_GetPixel(bitmap,0,0));
  }	
  sge_Blit(bitmap, screen, 0, 0, x, y, bitmap->w, bitmap->h);

  SDL_FreeSurface(bitmap);
  
  BxGfxSDLDrv_CopyVirtualToPhysicArea(NULL);

  return TRUE;
}

static BX_BOOL BxGfxSDLDrv_PutMaskedBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_UCHAR * mask, BX_BYTE alpha)
{
  int  pitch;
  int  width, height;
  SDL_PixelFormat *format;
  BX_VOID *pImg;
	SDL_Surface *dest;
  SDL_Surface *bitmap;
  
  pImg = screen->pixels;
  pitch = screen->pitch;
  format = screen->format;
  width = screen->w;
  height = screen->h;
	
  dest = SDL_CreateRGBSurfaceFrom(bits, w, h, 24, w*3, rmask, gmask, bmask, amask);
  if(dest == NULL) {
		fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
		return FALSE;
  }  
  
	bitmap = SDL_DisplayFormat(dest);
	SDL_SetColorKey(bitmap, SDL_SRCCOLORKEY|SDL_RLEACCEL, sge_GetPixel(bitmap,0,0));
	
  sge_Blit(bitmap, screen, 0, 0, x, y, w, h);
	//  sge_transform(bitmap, screen, 1.0, swf, shf, 0, 0, x*swf, y*shf, SGE_TAA | SGE_TSAFE);
	
  SDL_FreeSurface(dest);
  SDL_FreeSurface(bitmap);
	
  BxGfxSDLDrv_CopyVirtualToPhysicArea(NULL);
	
  return TRUE;
}

static BX_VOID BxGfxSDLDrv_CopyVirtualToPhysicArea(BX_RECT *rc)
{
  SDL_Flip(screen);
	usleep(1);
}

void BxUpdateOff(void)
{
	sge_Update_OFF();
}

void BxUpdateOn(void)
{
	sge_Update_ON();
}

BxGfxDrv BxGfxSDLDrv = 
{
  BxGfxSDLDrv_Init, //BX_INT (*Init)(BX_VOID);
  BxGfxSDLDrv_PutMaskedBitmap, //BX_BOOL (*PutMaskedBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits, BX_UCHAR* mask);
  BxGfxSDLDrv_PutBitmap, //BX_BOOL (*PutBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits);
  BxGfxSDLDrv_SetPixel, //BX_COLORREF (*SetPixel)(BX_INT x, BX_INT y, BX_COLORREF color);
  BxGfxSDLDrv_TextOut, //BX_BOOL (*TextOut)(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT* pFont, BX_COLORREF FntClr, BX_COLORREF BkClr);
  BxGfxSDLDrv_FillRect, //BX_VOID (*FillRect)(BX_RECT* pRect, BX_COLORREF brush);
  BxGfxSDLDrv_Rectangle,  //BX_VOID (*Rectangle)(BX_RECT* pRect, BX_COLORREF pen, BX_COLORREF brush);
  BxGfxSDLDrv_Line,  //BX_VOID BxGfxSVGADrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
  BxGfxSDLDrv_Circle,
  BxGfxSDLDrv_FillCircle,
  BxGfxSDLDrv_CopyVirtualToPhysicArea
};


int sdlevent_task(void *t)
{
  SDL_Event event;
	float swf = 800.0/800.0;
  float shf = 600.0/600.0;
  int sdlmouse=*((int*)t);

	pthread_mutex_lock( &sdlscreen_mutex );
	pthread_cond_wait( &sdlscreen_cond, &sdlscreen_mutex ); //wait for screeninit done
	pthread_mutex_unlock( &sdlscreen_mutex );
  /* main event loop */	
	if (sdlmouse)
	{
		while(!quit)
		{
			SDL_WaitEvent(&event);
			switch(event.type)
			{
			case SDL_QUIT:
				quit++;
				break;
			case SDL_MOUSEBUTTONDOWN:
				BxInsertMouseEvent(1, (int)((float)event.button.x/swf), (int)((float)event.button.y/shf));
				BxSetEvent();
				break;
			case SDL_MOUSEMOTION:
				if(event.motion.state & SDL_BUTTON(1))   
				{
					BxInsertMouseEvent(2, (int)((float)event.motion.x/swf), (int)((float)event.motion.y/shf));
					BxSetEvent();
				}
				break;
			case SDL_MOUSEBUTTONUP:
				BxInsertMouseEvent(4, (int)((float)event.button.x/swf), (int)((float)event.button.y/shf));
				BxSetEvent();
				break;
			
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					BxInsertKeyboardEvent(1, 27);
					BxSetEvent();
					break;
				case SDLK_UP:
					BxInsertKeyboardEvent(1, 147);
					BxSetEvent();
					break;
				case SDLK_DOWN:
					BxInsertKeyboardEvent(1, 141);
					BxSetEvent();
					break;
				case SDLK_LEFT:
					BxInsertKeyboardEvent(1, 143);
					BxSetEvent();
					break;
				case SDLK_RIGHT:
					BxInsertKeyboardEvent(1, 145);
					BxSetEvent();
					break;
				case SDLK_RETURN:
					BxInsertKeyboardEvent(1, 13);
					BxSetEvent();
					break;
				default:
					break;
				}
				break;
			case SDL_KEYUP:
				break;
			default:
				break;
			}
		}
	}
	else
	{
		SDL_ShowCursor(SDL_DISABLE);
		while(!quit)
		{
			SDL_WaitEvent(&event);
			if (event.type==SDL_QUIT)
				break;
		}
	}
  SDL_Quit();
	exit(0);
}
