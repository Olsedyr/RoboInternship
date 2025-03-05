#include "Bx.h"
#include "BxDrivers.h"
#include "font.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <linux/kd.h>

int fbp;
struct fb_fix_screeninfo fb_info;
static unsigned char *fb_buffer=NULL;
unsigned char *frame_buffer=NULL;

static BX_VOID BxGfxFBDrv_CopyVirtualToPhysicArea(BX_RECT *rc);
BxGfxDrvInfo FBInfo;

void DrawFontString(char *s, FONT *font, int x, int y, int color, char align);

#define MAX_COL                  800
#define MAX_ROW                  600
#define scalex                   10
#define scaley                   24

BX_RECT clipRect = {0, 0, MAX_COL, MAX_ROW };

BX_VOID BxSleep(BX_DWORD ms)
{
//	sleepTask(CURRENTTASK, MS_TO_TICKS(ms));
}

static BX_WORD ConvertColor(BX_COLORREF clr)
{
  BX_WORD c=0;

  c = (BxGetRValue(clr)>>3)<<11 | (BxGetGValue(clr)>>2)<<5 | BxGetBValue(clr)>>3;

  return c;
}

static BX_BYTE GetRValue16(BX_WORD clr)
{
  BX_BYTE c;

  c = (((clr&0xFC00)>>11)<<3);

  return c;
}

static BX_BYTE GetGValue16(BX_WORD clr)
{
  BX_BYTE c;

  c = (((clr&0x03E0)>>5)<<2);

  return c;
}

static BX_BYTE GetBValue16(BX_WORD clr)
{
  BX_BYTE c;

  c = (clr&0x001F)<<3;

  return c;
}

void fbcon_bell(void)
{
  int confd =open("/dev/tty1",O_RDWR);

  if(0<confd)
  {
    ioctl(confd, KDMKTONE, (50<<14) + 0x637);
    close(confd);
  }
}

static void fbcon_blank(int blank)
{
  ioctl(fbp, FBIOBLANK, blank ? VESA_POWERDOWN : VESA_NO_BLANKING);
}

static void fbcon_cursor(int blink)
{
  int confp =open("/dev/tty1",O_RDWR);

  if(0<confp)
  {
      write(confp,"\033[?25",5);   // disable cursor
      write(confp,"h",1);
      ioctl(confp, KDSETMODE, blink ? KD_TEXT : KD_GRAPHICS);  // disable screen blank
      close(confp);
  }
}


BX_BOOL GreyFramebuffer(BX_VOID)
{
  BX_INT x, y, c, f;
  BX_WORD *pImg, px;
  BX_RECT rc = {0,0,MAX_COL-1,MAX_ROW-1};
    
  pImg = (BX_WORD*)frame_buffer;

  f = FALSE;
  for(y=0; y<MAX_ROW; y++)
  {
    f = abs(f) - 1;
    for(x=abs(f); x<MAX_COL; x+=2)
    {
      pImg[(y*MAX_COL)+(x)] = 0;
    }
  }

  BxGfxFBDrv_CopyVirtualToPhysicArea(&rc);
  
  return TRUE;
}

BX_BOOL GrapBGFramebuffer(BX_PBITMAP pBmp, BX_PRECT pRc)
{
  BX_INT x, y, f;
  BX_BYTE *pImg;

  pImg = frame_buffer;

  f = 0;
  for(y=pRc->top; y<=pRc->bottom; y++)
  {
    for(x=pRc->left; x<=pRc->right; x++)
    {
      ((BX_PUCHAR)pBmp->bmBits)[f++] = pImg[(y*MAX_COL*2)+(x*2)];
      ((BX_PUCHAR)pBmp->bmBits)[f++] = pImg[(y*MAX_COL*2)+(x*2)+1];
    }
  }

  return TRUE;
}

BX_BOOL PutBGFramebuffer(BX_PBITMAP pBmp, BX_PRECT pRc)
{
  BX_INT x, y, f;
  BX_BYTE *pImg;

  pImg = frame_buffer;

  f = 0;
  for(y=pRc->top; y<=pRc->bottom; y++)
  {
    for(x=pRc->left; x<=pRc->right; x++)
    {
      pImg[(y*MAX_COL*2)+(x*2)] = ((BX_PUCHAR)pBmp->bmBits)[f++];
      pImg[(y*MAX_COL*2)+(x*2)+1] = ((BX_PUCHAR)pBmp->bmBits)[f++];
    }
  }

  BxGfxFBDrv_CopyVirtualToPhysicArea(pRc);

  return TRUE;
}


static BX_INT BxGfxFBDrv_Init(BX_VOID)
{
	fbp = open("/dev/fb", O_RDWR);

	if(fbp!=0 && setupLowlevelDrv(16)==0)
	{
    frame_buffer = malloc( MAX_ROW * MAX_COL * 2);

    fbcon_blank(FALSE);
    fbcon_cursor(FALSE);
    
		ioctl(fbp, FBIOGET_FSCREENINFO, &fb_info);
		fb_buffer = mmap(fb_buffer, fb_info.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbp, 0);

		FBInfo.Width = MAX_COL;
		FBInfo.Height = MAX_ROW;
		FBInfo.BytesPrPixel = 2;
		FBInfo.ByteWidth = FBInfo.Width * FBInfo.BytesPrPixel;
//		FBInfo.framebuffer = fb_buffer;
		FBInfo.framebuffer = frame_buffer;


    return BX_STATUS_OK;
	}

	return BX_DRIVER_STARTUP_FAILED;
}

BX_INT BxGfxFBDrv_Shutdown(BX_VOID)
{
  int confp;

  free(frame_buffer);
	munmap(fb_buffer, fb_info.smem_len);

	close(fbp);
  confp = open ("/dev/tty1",O_RDWR);
  if(0<confp)
  {
    write(confp,"\033[?25",5);
    write(confp,"l",1);
    ioctl(confp, KDSETMODE, KD_TEXT);
    close(confp);
  }
	return BX_STATUS_OK;
}

static BX_VOID BxGfxFBDrv_Rectangle(BX_RECT * pRect, BX_COLORREF pen, BX_COLORREF brush)
{
   gl_fillbox(pRect->left, pRect->top, pRect->right-pRect->left, pRect->bottom-pRect->top, ConvertColor(brush));
  gl_hline(pRect->left, pRect->top, pRect->right, ConvertColor(pen));
  gl_hline(pRect->left, pRect->bottom, pRect->right, ConvertColor(pen));
  gl_line(pRect->left, pRect->top, pRect->left, pRect->bottom, ConvertColor(pen));
  gl_line(pRect->right, pRect->top, pRect->right, pRect->bottom, ConvertColor(pen));
}


static BX_VOID BxGfxFBDrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
{
	gl_line(x1, y1, x2, y2, ConvertColor(pen));
}


static BX_VOID BxGfxFBDrv_FillRect(BX_RECT * pRect, BX_COLORREF brush)
{
	gl_fillbox(pRect->left, pRect->top, pRect->right-pRect->left, pRect->bottom-pRect->top, ConvertColor(brush));
}


static BX_BOOL BxGfxFBDrv_TextOut(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT * pFont, BX_COLORREF FntClr, BX_COLORREF BkClr)
{
//	DrawFontString(pStr, pFont, x, y, ConvertColor(FntClr), 0);
	return TRUE;
}



static BX_COLORREF BxGfxFBDrv_SetPixel(BX_INT x, BX_INT y, BX_COLORREF color)
{
	gl_setpixel(x, y, ConvertColor(color));

	return color;
}


static BX_COLORREF BxGfxFBDrv_Circle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color)
{
  gl_circle(cx, cy, r, ConvertColor(color));
  return color;
}

static BX_COLORREF BxGfxFBDrv_FillCircle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color)
{
  gl_fillcircle(cx, cy, r, ConvertColor(color));
  return color;
}

static BX_BOOL BxGfxFBDrv_PutBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_INT paintType)
{
  BX_WORD *img;
  BX_INT i, j;

  img = (BX_WORD*)malloc(sizeof(BX_WORD)*(h*w));

  for(i=0;i<h;i++)
    for(j=0;j<w;j++)
      img[(i*w)+j] = ConvertColor(BX_RGB(bits[((i*w*4)+(j*4))+2],bits[((i*w*4)+(j*4))+1],bits[((i*w*4)+(j*4))]));
  gl_putbox(x, y, w, h, img, paintType);

  free( img );
	return TRUE;
}

/*
static void __mymemcpy(char* dst, char* src, size_t n)
{
  size_t i;

  for(i=0;i<n;i++)
    outmemb((unsigned int)dst++, *(src++));
}
*/
#define __memcpy(dst,src,n)			__mymemcpy((dst),(src),(n))


static BX_BOOL BxGfxFBDrv_PutMaskedBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_UCHAR * mask)
{
  BX_INT i, j;

  for(i=0;i<h;i++)
  {
    for(j=0;j<w;j++)
    {
      if(mask[((i*w*3)+(j*3))]==0 && mask[((i*w*3)+(j*3))+1]==0 && mask[((i*w*3)+(j*3))+2]==0)
        gl_setpixel(x+j, y+i, ConvertColor(BX_RGB(bits[((i*w*3)+(j*3))],bits[((i*w*3)+(j*3))+1],bits[((i*w*3)+(j*3))+2])));
    }
  }
  return TRUE;
}

static BX_VOID BxGfxFBDrv_CopyVirtualToPhysicArea(BX_RECT *rc)
{
  unsigned short *sptr = (unsigned short*)(frame_buffer);
  unsigned short *dptr = (unsigned short*)(fb_buffer);
  int i, j;

  for(i=rc->top;i<rc->bottom;i++)
  {
    for(j=rc->left;j<rc->right;j++)
    {
      dptr[(i*MAX_COL)+(j)] = sptr[(i*MAX_COL)+(j)];
    }
  }
}

BxGfxDrv BxGfxFBDrv = 
{
  BxGfxFBDrv_Init, //BX_INT (*Init)(BX_VOID);
  BxGfxFBDrv_PutMaskedBitmap, //BX_BOOL (*PutMaskedBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits, BX_UCHAR* mask);
  BxGfxFBDrv_PutBitmap, //BX_BOOL (*PutBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits);
  BxGfxFBDrv_SetPixel, //BX_COLORREF (*SetPixel)(BX_INT x, BX_INT y, BX_COLORREF color);
  BxGfxFBDrv_TextOut, //BX_BOOL (*TextOut)(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT* pFont, BX_COLORREF FntClr, BX_COLORREF BkClr);
  BxGfxFBDrv_FillRect, //BX_VOID (*FillRect)(BX_RECT* pRect, BX_COLORREF brush);
  BxGfxFBDrv_Rectangle,  //BX_VOID (*Rectangle)(BX_RECT* pRect, BX_COLORREF pen, BX_COLORREF brush);
  BxGfxFBDrv_Line,  //BX_VOID BxGfxSVGADrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
  BxGfxFBDrv_Circle,
  BxGfxFBDrv_FillCircle,
  BxGfxFBDrv_CopyVirtualToPhysicArea
};
