#include "Bx.h"
#include "BxDrivers.h"
#include "font.h"

#include "gdi_header.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <linux/kd.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/Xvlib.h>
#include <X11/keysym.h>
#define _GNU_SOURCE
#include <getopt.h>

/* declarations for Xwindows */
Display *display=NULL;
Window window=(Window)NULL;
long width,height;
long device_width,device_height;
int connection=-1;
XvImage *xv_image=NULL;
XvAdaptorInfo *info;

/* ok the following constant should be by right included thru in Xvlib.h */
#ifndef XV_YV12
#define XV_YV12 0x32315659
#endif

#ifndef XV_YUY2
#define XV_YUY2 0x32595559
#endif

#ifndef XV_UYVY
#define XV_UYVY 0x59565955
#endif

#ifndef XV_I420
#define XV_I420 0x30323449
#endif

static BX_VOID BxGfxX11Drv_CopyVirtualToPhysicArea(BX_RECT *rc);
long format=XV_YUY2;
GC gc;

int adaptor=-1;

int fbp;

unsigned char *frame_buffer=NULL;
unsigned char *xvframe_buffer=NULL;
BxGfxDrvInfo FBInfo;

/* macro by Bart Nabbe */
#define RGB2YUV(r, g, b, y, u, v)\
  y = (9798*r + 19235*g + 3736*b)  / 32768;\
  u = (-4784*r - 9437*g + 14221*b)  / 32768 + 128;\
  v = (20218*r - 16941*g - 3277*b) / 32768 + 128;\
  y = y < 0 ? 0 : y;\
  u = u < 0 ? 0 : u;\
  v = v < 0 ? 0 : v;\
  y = y > 255 ? 255 : y;\
  u = u > 255 ? 255 : u;\
  v = v > 255 ? 255 : v

static inline
void rgb2yuy2 (unsigned char *RGB, unsigned char *YUV, int NumPixels) {
  int i, j;
  register int y0, y1, u0, u1, v0, v1 ;
  register int r, g, b;

  for (i = 0, j = 0; i < 3 * NumPixels; i += 6, j += 4)
    {
      r = RGB[i + 0];
      g = RGB[i + 1];
      b = RGB[i + 2];
      RGB2YUV (r, g, b, y0, u0 , v0);
      r = RGB[i + 3];
      g = RGB[i + 4];
      b = RGB[i + 5];
      RGB2YUV (r, g, b, y1, u1 , v1);
      YUV[j + 0] = y0;
      YUV[j + 1] = (u0+u1)/2;
      YUV[j + 2] = y1;
      YUV[j + 3] = (v0+v1)/2;
    }
}

void DrawFontString(char *s, FONT *font, int x, int y, int color, char align);

#define MAX_COL                  800
#define MAX_ROW                  600

BX_RECT clipRect = {0, 0, MAX_COL, MAX_ROW };

static BX_DWORD ConvertColor(BX_COLORREF clr)
{
	BX_DWORD c=0;

//	c = (BxGetRValue(clr)>>3)<<11 | (BxGetGValue(clr)>>2)<<5 | BxGetBValue(clr)>>3;
	c = clr;

	return c;

}

BX_BOOL GreyFramebuffer(BX_VOID)
{
  BX_INT x, y, c, f;
  BX_BYTE *pImg, px;
  BX_RECT rc = {0,0,MAX_COL-1,MAX_ROW-1};

  pImg = frame_buffer;

  f = FALSE;
  for(y=0; y<MAX_ROW; y++)
  {
    f = abs(f) - 1;
    for(x=abs(f); x<MAX_COL; x+=2)
    {
/*
      c=0.0;
      px = pImg[(y*MAX_COL)+(x)];
      c = (((px&0xFC00)>>11)<<3) + (((px&0x03E0)>>5)<<2) + ((px&0x001F)<<3);
      c /=3.0;

      pImg[(y*MAX_COL)+(x)] = ((c>>3)<<11 | (c>>2)<<5 | c>>3);
*/
      pImg[(y*MAX_COL*3)+(x*3)] = pImg[(y*MAX_COL*3)+(x*3)+1] = pImg[(y*MAX_COL*3)+(x*3)+2] = 0;
    }
  }

  BxGfxX11Drv_CopyVirtualToPhysicArea(&rc);

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
      ((BX_PUCHAR)pBmp->bmBits)[f++] = pImg[(y*MAX_COL*3)+(x*3)];
      ((BX_PUCHAR)pBmp->bmBits)[f++] = pImg[(y*MAX_COL*3)+(x*3)+1];
      ((BX_PUCHAR)pBmp->bmBits)[f++] = pImg[(y*MAX_COL*3)+(x*3)+2];
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
      pImg[(y*MAX_COL*3)+(x*3)] = ((BX_PUCHAR)pBmp->bmBits)[f++];
      pImg[(y*MAX_COL*3)+(x*3)+1] = ((BX_PUCHAR)pBmp->bmBits)[f++];
      pImg[(y*MAX_COL*3)+(x*3)+2] = ((BX_PUCHAR)pBmp->bmBits)[f++];
    }
  }

  BxGfxX11Drv_CopyVirtualToPhysicArea(pRc);

  return TRUE;
}

BX_VOID BxSleep(BX_DWORD ms)
{
//	sleepTask(CURRENTTASK, MS_TO_TICKS(ms));
}

void fbcon_bell(void)
{
  int confd =open("/dev/tty1",O_RDWR);

  if(0<confd)
  {
    ioctl(confd, KDMKTONE, (50<<16) + 0x637);
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


/* helper functions */

static void display_frame(BX_RECT *rc)
{
  unsigned char *temp_xvframe_buffer=NULL;
  unsigned char *temp_frame_buffer=NULL;
  int i, w, h;
  Visual vis;
      
  if(xvframe_buffer!=NULL && adaptor>=0)
  {
    if(rc!=NULL)
    {
      rc->left = ((int)((rc->left+1)/2))*2;

      w = BxRectWidth(rc);
      h = BxRectHeight(rc);

      w = ((int)((w+1)/2))*2;
        
      temp_frame_buffer = malloc( w * h * 3);
      temp_xvframe_buffer = malloc( w * h * 2);

      for(i=0;i<BxRectHeight(rc);i++)
        memcpy(&temp_frame_buffer[w*3*i],
               &frame_buffer[((width)*(rc->top+i)*3)+(rc->left*3)],
               w*3);
      
      rgb2yuy2 (temp_frame_buffer, temp_xvframe_buffer, w * h);

      for(i=0;i<BxRectHeight(rc);i++)
        memcpy(&xvframe_buffer[((width)*(rc->top+i)*2)+(rc->left*2)],
                &temp_xvframe_buffer[w*2*i],
               w*2);

		xv_image=XvCreateImage(display,info[adaptor].base_id,format,xvframe_buffer,
			device_width,device_height);
		XvPutImage(display,info[adaptor].base_id,window,gc,xv_image,
			0,0,device_width,device_height,
			0,0,width,height);
		xv_image=NULL;
/*
      xv_image=XvCreateImage(display,info[adaptor].base_id,format,temp_xvframe_buffer,
			  w,h);

		  XvPutImage(display,info[adaptor].base_id,window,gc,xv_image,
			  0,0,w,h,
			  rc->left,rc->top,w,h);
      xv_image=NULL;
*/
      free(temp_frame_buffer);
      free(temp_xvframe_buffer);
      return;
    }
    rgb2yuy2 (frame_buffer, xvframe_buffer, MAX_ROW*MAX_COL);
		xv_image=XvCreateImage(display,info[adaptor].base_id,format,xvframe_buffer,
			device_width,device_height);
		XvPutImage(display,info[adaptor].base_id,window,gc,xv_image,
			0,0,device_width,device_height,
			0,0,width,height);
		xv_image=NULL;
  }
}

static void QueryXv()
{
	int num_adaptors;
	int num_formats;
	XvImageFormatValues *formats=NULL;
	int i,j;
	char xv_name[5];

	XvQueryAdaptors(display,DefaultRootWindow(display),&num_adaptors,&info);

	for(i=0;i<num_adaptors;i++) {
		formats=XvListImageFormats(display,info[i].base_id,&num_formats);
		for(j=0;j<num_formats;j++) {
			xv_name[4]=0;
			memcpy(xv_name,&formats[j].id,4);
			if(formats[j].id==format) {
				fprintf(stderr,"using Xv format 0x%x %s %s\n",formats[j].id,xv_name,(formats[j].format==XvPacked)?"packed":"planar");
				if(adaptor<0)adaptor=i;
			}
		}
	}
		XFree(formats);
	if(adaptor<0)
		fprintf(stderr,"No suitable Xv adaptor found");

}

static void cleanup(void) {
 if ((void *)window != NULL)
		XUnmapWindow(display,window);
	if (display != NULL)
		XFlush(display);
  if(frame_buffer!=NULL)
    free(frame_buffer);
  if(xvframe_buffer!=NULL)
    free(xvframe_buffer);
}

static BX_INT BxGfxX11Drv_Init(BX_VOID)
{
	setupLowlevelDrv(24);

  frame_buffer = malloc( MAX_ROW * MAX_COL * 3);
  xvframe_buffer = malloc( MAX_ROW * MAX_COL * 2);

  if(frame_buffer!=NULL)
	{
		FBInfo.Width = MAX_COL;
		FBInfo.Height = MAX_ROW;
		FBInfo.BytesPrPixel = 3;
		FBInfo.ByteWidth = FBInfo.Width * FBInfo.BytesPrPixel;
		FBInfo.framebuffer = frame_buffer;

		return BX_STATUS_OK;
	}

	return BX_DRIVER_STARTUP_FAILED;
}

BX_INT BxGfxX11Drv_Shutdown(BX_VOID)
{
  cleanup();
	return BX_STATUS_OK;
}

static BX_VOID BxGfxX11Drv_Rectangle(BX_RECT * pRect, BX_COLORREF pen, BX_COLORREF brush)
{
	gl_fillbox(pRect->left, pRect->top, pRect->right-pRect->left, pRect->bottom-pRect->top, ConvertColor(brush));
	gl_hline(pRect->left, pRect->top, pRect->right, ConvertColor(pen));
	gl_hline(pRect->left, pRect->bottom, pRect->right, ConvertColor(pen));
	gl_line(pRect->left, pRect->top, pRect->left, pRect->bottom, ConvertColor(pen));
	gl_line(pRect->right, pRect->top, pRect->right, pRect->bottom, ConvertColor(pen));
}


static BX_VOID BxGfxX11Drv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
{
	gl_line(x1, y1, x2, y2, ConvertColor(pen));
}

static BX_COLORREF BxGfxX11Drv_Circle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color)
{
  gl_circle(cx, cy, r, ConvertColor(color));
  return color;
}

static BX_COLORREF BxGfxX11Drv_FillCircle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color)
{
  gl_fillcircle(cx, cy, r, ConvertColor(color));
  return color;
}


static BX_VOID BxGfxX11Drv_FillRect(BX_RECT * pRect, BX_COLORREF brush)
{
	gl_fillbox(pRect->left, pRect->top, pRect->right-pRect->left, pRect->bottom-pRect->top, ConvertColor(brush));
}


static BX_BOOL BxGfxX11Drv_TextOut(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT * pFont, BX_COLORREF FntClr, BX_COLORREF BkClr)
{
//	DrawFontString(pStr, pFont, x, y, ConvertColor(FntClr), 0);
	return TRUE;
}

#define ASSIGNVP16(x, y, vp) vp = VBUF + (y) * BYTEWIDTH + (x) * 2;

static BX_COLORREF BxGfxX11Drv_SetPixel(BX_INT x, BX_INT y, BX_COLORREF color)
{
	gl_setpixel(x, y, ConvertColor(color));
	return color;
}

static BX_BOOL BxGfxX11Drv_PutBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_INT paintType)
{
  BX_BYTE *img;
  BX_INT i, j;

  img = (BX_BYTE*)malloc(h*w*3);

  for(i=0;i<h;i++)
  {
    for(j=0;j<w;j++)
    {
      img[(i*w*3)+(j*3)] = bits[((i*w*4)+(j*4))+2];
      img[(i*w*3)+(j*3)+1] = bits[((i*w*4)+(j*4))+1];
      img[(i*w*3)+(j*3)+2] = bits[((i*w*4)+(j*4))];
    }
  }
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


static BX_BOOL BxGfxX11Drv_PutMaskedBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_UCHAR * mask)
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

static BX_VOID BxGfxX11Drv_CopyVirtualToPhysicArea(BX_RECT *rc)
{
  display_frame(rc);
  if(display!=NULL)
    XSync(display, FALSE);
}

BxGfxDrv BxGfxX11Drv = 
{
	BxGfxX11Drv_Init, //BX_INT (*Init)(BX_VOID);
	BxGfxX11Drv_PutMaskedBitmap, //BX_BOOL (*PutMaskedBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits, BX_UCHAR* mask);
	BxGfxX11Drv_PutBitmap, //BX_BOOL (*PutBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits);
	BxGfxX11Drv_SetPixel, //BX_COLORREF (*SetPixel)(BX_INT x, BX_INT y, BX_COLORREF color);
	BxGfxX11Drv_TextOut, //BX_BOOL (*TextOut)(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT* pFont, BX_COLORREF FntClr, BX_COLORREF BkClr);
	BxGfxX11Drv_FillRect, //BX_VOID (*FillRect)(BX_RECT* pRect, BX_COLORREF brush);
	BxGfxX11Drv_Rectangle,  //BX_VOID (*Rectangle)(BX_RECT* pRect, BX_COLORREF pen, BX_COLORREF brush);
	BxGfxX11Drv_Line,  //BX_VOID BxGfxSVGADrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
  BxGfxX11Drv_Circle,
  BxGfxX11Drv_FillCircle,
  BxGfxX11Drv_CopyVirtualToPhysicArea
};

void *x11event_task(void *t)
{
	XEvent xev;
	XGCValues xgcv;
	long background=0x000000;

	/* make the window */
	display=XOpenDisplay(getenv("DISPLAY"));
	if(display==NULL)
	{
		fprintf(stderr,"Could not open display \"%s\"\n",getenv("DISPLAY"));
		cleanup();
		exit(-1);
	}

	QueryXv();

	if ( adaptor < 0 )
	{
		cleanup();
		exit(-1);
	}

  device_width=width=MAX_COL;
	device_height=height=MAX_ROW;

	window=XCreateSimpleWindow(display,DefaultRootWindow(display),0,0,width,height,0,
		WhitePixel(display,DefaultScreen(display)),
		background);

	XSelectInput(display,window,StructureNotifyMask|KeyPressMask|ButtonPressMask|ButtonReleaseMask|ButtonMotionMask);
	XMapWindow(display,window);
	connection=ConnectionNumber(display);

  gc=XCreateGC(display,window,0,&xgcv);
  
  XSetFunction(display, gc, GXcopy);

  XGetGCValues(display, gc, GCFunction, &xgcv);

  /* main event loop */
	while(1)
  {
		XFlush(display);

    while(XPending(display)>0){
			XNextEvent(display,&xev);
			switch(xev.type){
				case ConfigureNotify:
//					width=xev.xconfigure.width;
//					height=xev.xconfigure.height;
//					display_frame(NULL);
					break;
				case MotionNotify:
            BxInsertMouseEvent(2, xev.xmotion.x, xev.xmotion.y);
	          BxSetEvent();
          break;
				case ButtonRelease:
          BxInsertMouseEvent(4, xev.xbutton.x, xev.xbutton.y);
	        BxSetEvent();
          break;
        case ButtonPress:
          BxInsertMouseEvent(1, xev.xbutton.x, xev.xbutton.y);
	        BxSetEvent();
          break;
        case KeyPress:
					switch(XKeycodeToKeysym(display,xev.xkey.keycode,0)){
						case XK_q:
						case XK_Q:
//							cleanup();
							break;
						case XK_comma:
						case XK_less:
//							width=width/2;
//							height=height/2;
//							XResizeWindow(display,window,width,height);
//							display_frame();
							break;
						case XK_period:
						case XK_greater:
//							width=2*width;
//							height=2*height;
//							XResizeWindow(display,window,width,height);
//							display_frame();
							break;
						case XK_Left:
			        BxInsertKeyboardEvent(1, 143);
			        BxSetEvent();
							break;
						case XK_Right:
			        BxInsertKeyboardEvent(1, 145);
			        BxSetEvent();
							break;
						case XK_Up:
			        BxInsertKeyboardEvent(1, 147);
			        BxSetEvent();
							break;
						case XK_Down:
			        BxInsertKeyboardEvent(1, 141);
			        BxSetEvent();
							break;
						case XK_Return:
			        BxInsertKeyboardEvent(1, 13);
			        BxSetEvent();
							break;
						}
					break;
				}
			} /* XPending */
		} /* while not interrupted */
  return NULL;
}


