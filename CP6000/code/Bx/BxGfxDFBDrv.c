#include "Bx.h"
#include "BxDrivers.h"
#include "font.h"
#include "../hmi/hmi.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <linux/kd.h>

#include <directfb.h>

/* macro for a safe call to DirectFB functions */
#define DFBCHECK(x...)                                                     \
               err = x;                                                    \
               if (err != DFB_OK) {                                        \
                    fprintf( stderr, "%s <%d>:\n\t", __FILE__, __LINE__ ); \
                    DirectFBErrorFatal (#x, err);                         \
               }

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
                                 
static IDirectFB              *dfb;
static IDirectFBSurface       *primary;
static IDirectFBSurface       *sub;
static IDirectFBEventBuffer 	*events;
//static IDirectFBEventBuffer   *keybuffer;
static DFBResult              err;

static int screen_width, screen_height;
static int mouse_x=0, mouse_y=0;

static DFBSurfaceDescription   dsc;
static DFBRectangle            rect;

struct fb_fix_screeninfo fb_info;
//static unsigned char *fb_buffer=NULL;
unsigned char *frame_buffer=NULL;

static BX_VOID BxGfxDFBDrv_CopyVirtualToPhysicArea(BX_RECT *rc);
BxGfxDrvInfo FBInfo;

void DrawFontString(char *s, FONT *font, int x, int y, int color, char align);

#define MAX_COL                  800
#define MAX_ROW                  600
#define scalex                   10
#define scaley                   24
#define CURSORW                  8
#define CURSORH                  8

BX_RECT clipRect = {0, 0, MAX_COL, MAX_ROW };

BX_RECT BxSetClipRect(BX_RECT *clip)
{
  BX_RECT bx_curr_rect;
  DFBRegion new_rect;
  
  new_rect.x1 = clip->left-1;
  new_rect.y1 = clip->top-1;
  new_rect.x2 = clip->right+1;
  new_rect.y2 = clip->bottom+1;
  
  sub->SetClip(sub, &new_rect);
  
  return bx_curr_rect;
}


BX_BOOL InitDFBFontServer(FONT *font, char* fontname, int height)
{
  DFBFontDescription font_dsc;

  font_dsc.flags = DFDESC_HEIGHT;
  font_dsc.height = height;
  DFBCHECK (dfb->CreateFont (dfb, fontname, &font_dsc, &font->dffont));
  font->size = height;
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
    ioctl(confd, KDMKTONE, (50<<14) + 0x637);
    close(confd);
  }
}


BX_BOOL GreyFramebuffer(BX_VOID)
{
  BX_INT                 f;
  DFBResult              ret;
  void                  *data;
  int                    pitch;
  int                    x, y, width, height;
  DFBSurfacePixelFormat  format;


  ret = sub->Lock( sub, DSLF_READ | DSLF_WRITE, &data, &pitch );
  if (ret) {
       DirectFBError( "IDirectFBSurface::Lock() failed", ret );
       return ret;
  }

  sub->GetSize( sub, &width, &height );
  sub->GetPixelFormat( sub, &format );

  switch (format) {
       case DSPF_RGB16:
            f = FALSE;
            for (y=0; y<height; y++) {
                 __u16 *dst = data + y * pitch;

                 f = abs(f) - 1;
                 for(x=abs(f); x<width; x+=2)
                 {
//                      __u32 px = RGB16_TO_RGB32(dst[x]);
//                      __u32 gpx = (PIXEL_R32(px) + PIXEL_G32(px) + PIXEL_B32(px))/3;
//                      dst[x] = PIXEL_RGB16( gpx, gpx, gpx );
                      dst[x] = PIXEL_RGB16( 0, 0, 0 );
                 }
            }
            break;
       case DSPF_ARGB1555:
            f = FALSE;
            for (y=0; y<height; y++) {
                 __u16 *dst = data + y * pitch;

                 f = abs(f) - 1;
                 for(x=abs(f); x<width; x+=2)
                      dst[x] = PIXEL_ARGB1555( 0xff, 0, 0, 0 );
            }
            break;
       case DSPF_ARGB:
            f = FALSE;
            for (y=0; y<height; y++) {
                 __u32 *dst = data + y * pitch;

                 f = abs(f) - 1;
                 for(x=abs(f); x<width; x+=2)
                      dst[x] = PIXEL_ARGB( 0xff, 0, 0, 0 );
            }
            break;
       case DSPF_RGB332:
            f = FALSE;
            for (y=0; y<height; y++) {
                 __u8 *dst = data + y * pitch;

                 f = abs(f) - 1;
                 for(x=abs(f); x<width; x+=2)
                      dst[x] = PIXEL_RGB332( 0, 0, 0 );
            }
            break;
       default:
            printf("Unhandled pixel format 0x%08x!\n", format );
            break;
  }

  sub->Unlock( sub );

  BxGfxDFBDrv_CopyVirtualToPhysicArea(NULL);
  
  return TRUE;
}

BX_BOOL GrapBGFramebuffer(BX_PBITMAP pBmp, BX_PRECT pRc)
{
  DFBResult              ret;
  int                    pitch;
  int                    width, height;
  DFBSurfacePixelFormat  format;
  BX_INT x, y, f;
  BX_VOID *pImg;

  ret = sub->Lock( sub, DSLF_READ, &pImg, &pitch );
  if (ret) {
       DirectFBError( "IDirectFBSurface::Lock() failed", ret );
       return ret;
  }

  sub->GetSize( sub, &width, &height );
  sub->GetPixelFormat( sub, &format );


  switch (format) {
       case DSPF_RGB16:
            f = 0;
            __u16 *dst = pBmp->bmBits;
            for(y=pRc->top; y<=pRc->bottom; y++)
            {
              __u16 *src = pImg + (y * pitch) + (pRc->left * sizeof(__u16));
              for(x=0; x<=BxRectWidth(pRc); x++)
              {
                dst[f++] = src[x];
              }
            }

            break;
       case DSPF_RGB332:
            f = 0;
            for(y=pRc->top; y<=pRc->bottom; y++)
            {
              __u8 *dst = pImg + y * pitch;
              for(x=pRc->left; x<=pRc->right; x++)
              {
                ((BX_DWORD*)pBmp->bmBits)[f++] = dst[x];
              }
            }
            break;
       default:
            printf("Unhandled pixel format 0x%08x!\n", format );
            break;
  }

  sub->Unlock( sub );
  return TRUE;
}

BX_BOOL PutBGFramebuffer(BX_PBITMAP pBmp, BX_PRECT pRc)
{
  DFBResult              ret;
  int                    pitch;
  int                    width, height;
  DFBSurfacePixelFormat  format;
  BX_INT x, y, f;
  BX_VOID *pImg;

  ret = sub->Lock( sub, DSLF_WRITE, &pImg, &pitch );
  if (ret) {
       DirectFBError( "IDirectFBSurface::Lock() failed", ret );
       return ret;
  }

  sub->GetSize( sub, &width, &height );
  sub->GetPixelFormat( sub, &format );


  switch (format) {
       case DSPF_RGB16:
          f = 0;
          __u16 *src = pBmp->bmBits;
          for(y=pRc->top; y<=pRc->bottom; y++)
          {
            __u16 *dst = pImg + (y * pitch) + (pRc->left * sizeof(__u16));
            for(x=0; x<=BxRectWidth(pRc); x++)
            {
              dst[x] = src[f++];
            }
          }
          break;
       case DSPF_RGB332:
            f = 0;
            for(y=pRc->top; y<=pRc->bottom; y++)
            {
              __u8 *dst = pImg + y * pitch;
              for(x=pRc->left; x<=pRc->right; x++)
              {
                dst[x] = ((BX_DWORD*)pBmp->bmBits)[f++];
              }
            }
            break;
       default:
            printf("Unhandled pixel format 0x%08x!\n", format );
            break;
  }

  sub->Unlock( sub );

  BxGfxDFBDrv_CopyVirtualToPhysicArea(pRc);
  return TRUE;
}


typedef struct _DeviceInfo DeviceInfo;

struct _DeviceInfo {
     DFBInputDeviceID           device_id;
     DFBInputDeviceDescription  desc;
     DeviceInfo                *next;
};

static DeviceInfo            *devices = NULL;

static DFBEnumerationResult
enum_input_device( DFBInputDeviceID           device_id,
                   DFBInputDeviceDescription  desc,
                   void                      *data )
{
	DeviceInfo **devices = data;
	DeviceInfo  *device;
	
	/* Make sure only one inputdevice of each type */
	DeviceInfo **itdevices = devices;
	while (itdevices!=NULL&&(*itdevices)!=NULL)
	{
		if (desc.type == (*itdevices)->desc.type)
			return DFENUM_OK;
		itdevices = &(*itdevices)->next;
	}
	
	printf("DFBInputDeviceDescription %s %i\n",desc.name,desc.type);
	device = malloc( sizeof(DeviceInfo) );
	
	device->device_id = device_id;
	device->desc      = desc;
	device->next      = *devices;
	
	*devices = device;
	
	return DFENUM_OK;
}

const char *get_device_name( DeviceInfo       *devices,
														 DFBInputDeviceID  device_id )
{
     while (devices) {
          if (devices->device_id == device_id)
               return devices->desc.name;
          devices = devices->next;
     }
     
     return "<unknown>";
}


static BX_INT BxGfxDFBDrv_Init(BX_VOID)
{
  int                     width;
  int                     height;
  DFBSurfacePixelFormat  format;

  DFBCHECK (DirectFBInit (NULL, NULL));

  /* create the super interface */
  DFBCHECK (DirectFBCreate (&dfb));

  /* create a list of input devices */
  dfb->EnumInputDevices( dfb, enum_input_device, &devices );

  /* create an event buffer for all devices */
  DFBCHECK(dfb->CreateInputEventBuffer( dfb, DICAPS_ALL,
                                           DFB_FALSE, &events ));

  dfb->SetCooperativeLevel (dfb, DFSCL_FULLSCREEN);

  /*  create the primary surface  */
  dsc.flags = DSDESC_CAPS;
  dsc.caps  = DSCAPS_PRIMARY;
//  dsc.caps |= DSCAPS_FLIPPING;
  DFBCHECK (dfb->CreateSurface (dfb, &dsc, &primary));

  primary->GetSize (primary, &width, &height);
  screen_width = width;
  screen_height = height;

  primary->SetClip (primary, NULL);

  rect.x = 0;
  rect.y = 0;
  rect.w = width;
  rect.h = height;

  primary->GetSubSurface (primary, &rect, &sub);

  sub->GetPixelFormat( sub, &format );

  FBInfo.Width = width;
  FBInfo.Height = height;

  switch (format) {
     case DSPF_RGB16:
        FBInfo.BytesPrPixel = 2;
        break;
     case DSPF_RGB32:
        FBInfo.BytesPrPixel = 4;
        break;
     default:
        printf("Unhandled pixel format 0x%08x!\n", format );
        break;
  }        

  FBInfo.ByteWidth = FBInfo.Width * FBInfo.BytesPrPixel;
//		FBInfo.framebuffer = fb_buffer;
//  FBInfo.framebuffer = frame_buffer;

  return BX_STATUS_OK;
}

BX_INT BxGfxDFBDrv_Shutdown(BX_VOID)
{

  events->Release( events );
//  keybuffer->Release( keybuffer );
  sub->Release (sub);
  primary->Release (primary);
  dfb->Release (dfb);
  return BX_STATUS_OK;
}

static BX_VOID BxGfxDFBDrv_Rectangle(BX_RECT * pRect, BX_COLORREF pen, BX_COLORREF brush)
{
  sub->SetColor(sub, BxGetRValue(brush), BxGetGValue(brush), BxGetBValue(brush), 0xff);
  sub->FillRectangle(sub, pRect->left, pRect->top, BxRectWidth(pRect), BxRectHeight(pRect));
  sub->SetColor(sub, BxGetRValue(pen), BxGetGValue(pen), BxGetBValue(pen), 0xff);
  sub->DrawRectangle(sub, pRect->left, pRect->top, BxRectWidth(pRect), BxRectHeight(pRect));
}


static BX_VOID BxGfxDFBDrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
{
  sub->SetColor(sub, BxGetRValue(pen), BxGetGValue(pen), BxGetBValue(pen), 0xff);
  sub->DrawLine(sub, x1, y1, x2, y2);
}


static BX_VOID BxGfxDFBDrv_FillRect(BX_RECT * pRect, BX_COLORREF brush)
{
  sub->SetColor(sub, BxGetRValue(brush), BxGetGValue(brush), BxGetBValue(brush), 0xff);
  sub->FillRectangle(sub, pRect->left, pRect->top, BxRectWidth(pRect), BxRectHeight(pRect));
}


static BX_BOOL BxGfxDFBDrv_TextOut(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT * pFont, BX_COLORREF FntClr, BX_COLORREF BkClr)
{

  DFBCHECK (sub->SetFont (sub, pFont->dffont));

  DFBCHECK (sub->SetColor (sub, BxGetRValue(FntClr), BxGetGValue(FntClr), BxGetBValue(FntClr), 0xFF));  

  DFBCHECK (sub->DrawString (sub, pStr, -1, x, y, DSTF_LEFT));

//  DrawFontString(pStr, pFont, x, y, ConvertColor(FntClr), 0);
	return TRUE;
}

static BX_COLORREF BxGfxDFBDrv_SetPixel(BX_INT x, BX_INT y, BX_COLORREF color)
{
  sub->SetColor(sub, BxGetRValue(color), BxGetGValue(color), BxGetBValue(color), 0xff);
  sub->DrawLine(sub, x, y, x, y);
	return color;
}


static BX_COLORREF BxGfxDFBDrv_Circle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color)
{
//  gl_circle(cx, cy, r, ConvertColor(color));
  return color;
}

static BX_COLORREF BxGfxDFBDrv_FillCircle(BX_INT cx, BX_INT cy, BX_INT r, BX_COLORREF color)
{
//  gl_fillcircle(cx, cy, r, ConvertColor(color));
  return color;
}

static BX_BOOL BxGfxDFBDrv_PutBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_INT paintType)
{
  DFBResult              ret;
  int                    pitch;
  int                    width, height;
  DFBSurfacePixelFormat  format;
  BX_VOID *pImg;
  BX_INT i, j;

  ret = sub->Lock( sub, DSLF_WRITE, &pImg, &pitch );
  if (ret) {
       DirectFBError( "IDirectFBSurface::Lock() failed", ret );
       return ret;
  }

  sub->GetSize( sub, &width, &height );
  sub->GetPixelFormat( sub, &format );


  switch (format) {
       case DSPF_RGB16:
          for(i=0;i<h;i++)
          {
            __u16 *dst = pImg + (y+i) * pitch + (x * sizeof(__u16));
            for(j=0;j<w;j++)
              dst[j] = PIXEL_RGB16(bits[((i*w*4)+(j*4))+2],bits[((i*w*4)+(j*4))+1],bits[((i*w*4)+(j*4))]);
          }
          break;
       case DSPF_RGB332:
            break;
       default:
            printf("Unhandled pixel format 0x%08x!\n", format );
            break;
  }

  sub->Unlock( sub );

  BxGfxDFBDrv_CopyVirtualToPhysicArea(NULL);

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


static BX_BOOL BxGfxDFBDrv_PutMaskedBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_UCHAR * mask)
{
  DFBResult              ret;
  int                    pitch;
  int                    width, height;
  DFBSurfacePixelFormat  format;
  BX_VOID *pImg;
  BX_INT i, j;

  ret = sub->Lock( sub, DSLF_WRITE, &pImg, &pitch );
  if (ret) {
       DirectFBError( "IDirectFBSurface::Lock() failed", ret );
       return ret;
  }

  sub->GetSize( sub, &width, &height );
  sub->GetPixelFormat( sub, &format );


  switch (format) {
       case DSPF_RGB16:
          for(i=0;i<h;i++)
          {
            __u16 *dst = pImg + (y+i) * pitch + (x * sizeof(__u16));
            for(j=0;j<w;j++)
            {
              if(mask[((i*w*3)+(j*3))]==0 && mask[((i*w*3)+(j*3))+1]==0 && mask[((i*w*3)+(j*3))+2]==0)
                dst[j] = PIXEL_RGB16(bits[((i*w*3)+(j*3))],bits[((i*w*3)+(j*3))+1],bits[((i*w*3)+(j*3))+2]);
            }
          }
          break;
       case DSPF_RGB332:
            break;
       default:
            printf("Unhandled pixel format 0x%08x!\n", format );
            break;
  }

  sub->Unlock( sub );

  BxGfxDFBDrv_CopyVirtualToPhysicArea(NULL);

  return TRUE;
}


BX_BOOL BxGfxDFBDrv_PutCursor(BX_INT x, BX_INT y,BX_INT w, BX_INT h)
{
  DFBResult              ret;
  int                    pitch;
  int                    width, height;
	static int oldx=-1,oldy=-1;
  DFBSurfacePixelFormat  format;
  BX_VOID *pImg;
  BX_INT i, j;
	
	if (sub==NULL) return TRUE;
	
  ret = sub->Lock( sub, DSLF_WRITE, &pImg, &pitch );
  if (ret) {
       DirectFBError( "IDirectFBSurface::Lock() failed", ret );
       return ret;
  }

  sub->GetSize( sub, &width, &height );
  sub->GetPixelFormat( sub, &format );


  switch (format) {
	case DSPF_RGB16:
		//printf("Cursor at: %i %i old: %i %i\n",x,y,oldx,oldy);
		for(i=0;i<h;i++)
		{
			__u16 *dst = pImg + (y+i) * pitch + (x * sizeof(__u16));
			for(j=0;j<w;j++)
			{
				dst[j] ^= PIXEL_RGB16(255,255,255);
			}
		}
		if (oldx!=-1&&oldy!=-1)
		{
			for(i=0;i<h;i++)
			{
				__u16 *dst = pImg + (oldy+i) * pitch + (oldx * sizeof(__u16));
				for(j=0;j<w;j++)
				{
					dst[j] ^= PIXEL_RGB16(255,255,255);
				}
			}
		}
		oldx=x;
		oldy=y;
		break;
	case DSPF_RGB332:
		break;
	default:
		printf("Unhandled pixel format 0x%08x!\n", format );
		break;
  }
	
  sub->Unlock( sub );
	BxGfxDFBDrv_CopyVirtualToPhysicArea(NULL);

  return TRUE;
}

static BX_VOID BxGfxDFBDrv_CopyVirtualToPhysicArea(BX_RECT *rc)
{
  primary->Flip(primary, NULL, DSFLIP_WAITFORSYNC);
}

void BxUpdateOff(void)
{
//     sge_Update_OFF();
}

void BxUpdateOn(void)
{
//     sge_Update_ON();
}

BxGfxDrv BxGfxDFBDrv = 
{
  BxGfxDFBDrv_Init, //BX_INT (*Init)(BX_VOID);
  BxGfxDFBDrv_PutMaskedBitmap, //BX_BOOL (*PutMaskedBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits, BX_UCHAR* mask);
  BxGfxDFBDrv_PutBitmap, //BX_BOOL (*PutBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits);
  BxGfxDFBDrv_SetPixel, //BX_COLORREF (*SetPixel)(BX_INT x, BX_INT y, BX_COLORREF color);
  BxGfxDFBDrv_TextOut, //BX_BOOL (*TextOut)(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT* pFont, BX_COLORREF FntClr, BX_COLORREF BkClr);
  BxGfxDFBDrv_FillRect, //BX_VOID (*FillRect)(BX_RECT* pRect, BX_COLORREF brush);
  BxGfxDFBDrv_Rectangle,  //BX_VOID (*Rectangle)(BX_RECT* pRect, BX_COLORREF pen, BX_COLORREF brush);
  BxGfxDFBDrv_Line,  //BX_VOID BxGfxSVGADrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
  BxGfxDFBDrv_Circle,
  BxGfxDFBDrv_FillCircle,
  BxGfxDFBDrv_CopyVirtualToPhysicArea
};

void *dfdevent_task(void *t)
{
  DFBInputEvent evt;
  int quit = 0;
	
//  while(!keybuffer)
  while(!events)
    usleep(10000);
    
  /* main event loop */
  while(!quit)
  {
    events->WaitForEvent( events );
//    keybuffer->WaitForEvent( keybuffer );
    /* process keybuffer */
//    while (keybuffer->GetEvent( keybuffer, DFB_EVENT(&evt)) == DFB_OK)
    while (events->GetEvent( events, DFB_EVENT(&evt)) == DFB_OK)
    {
      //const char *device_name;
			//  device_name = get_device_name( devices, evt.device_id );
			//  printf ("%s\n", device_name);
					//	printf("key pressed! %i %i : %i %i\n",evt.type,DIET_KEYPRESS,evt.key_symbol,evt.key_id);
			
      switch(evt.type)
      {
			  case DIET_KEYPRESS:
					switch (DFB_LOWER_CASE(evt.key_symbol))
					{
						case DIKS_ESCAPE:
							BxInsertKeyboardEvent(1, 27);
							BxSetEvent();
						break;
						case DIKS_SMALL_Q:
						case DIKS_BACK:
						case DIKS_STOP:
						break;
						case DIKS_CURSOR_UP:
							BxInsertKeyboardEvent(1, 147);
							BxSetEvent();
						break;
					case DIKS_TAB:
							BxInsertKeyboardEvent(1, 9);
							BxSetEvent();
						break;
						case DIKS_CURSOR_DOWN:
							//	printf("Cursor down!\n");
							BxInsertKeyboardEvent(1, 141);
							BxSetEvent();
						break;
						case DIKS_CURSOR_LEFT:
							BxInsertKeyboardEvent(1, 143);
							BxSetEvent();
						break;
						case DIKS_CURSOR_RIGHT:
							BxInsertKeyboardEvent(1, 145);
							BxSetEvent();
						break;
						case DIKS_ENTER:
							BxInsertKeyboardEvent(1, 13);
							BxSetEvent();
						break;
						default:
						break;
					}
				break;
        case DIET_KEYRELEASE:
				break;
        case DIET_BUTTONPRESS:
          BxInsertMouseEvent(1, GetCalcX(), GetCalcY());
          BxSetEvent();
//     else {  /* BUTTON_PRESS or BUTTON_RELEASE */
//          snprintf (buf, sizeof(buf), "Button %d", evt->button);
//     }
				break;
        case DIET_BUTTONRELEASE:
          BxInsertMouseEvent(4, GetCalcX(), GetCalcY());
          BxSetEvent();
				break;
        case DIET_AXISMOTION:
          if (evt.flags & DIEF_AXISABS) 
					{
               switch (evt.axis) 
							 {
									case DIAI_X:
												mouse_x = evt.axisabs;
												SetRawX(mouse_x);
									break;
									case DIAI_Y:
												mouse_y = evt.axisabs;
												SetRawY(mouse_y);
									break;
									default:
		//                    snprintf (buf, sizeof(buf),
		//                              "Axis %d (abs): %d", evt->axis, evt->axisabs);
									break;
               }
          }
          else if (evt.flags & DIEF_AXISREL) 
					{
						int lim;
						switch (evt.axis) 
						{
						case DIAI_X:
							mouse_x += evt.axisrel;
							lim = (MAX_COL-CURSORW)/GetTouchXFactor()+GetTouchXOffset();
							mouse_x = CLAMP(mouse_x, GetTouchXOffset(), lim-1);
							SetRawX(mouse_x);
							break;
							BxGfxDFBDrv_PutCursor(GetCalcX(),GetCalcY(),CURSORW,CURSORH);
						case DIAI_Y:
							mouse_y += evt.axisrel;
							lim = (MAX_ROW-CURSORH)/GetTouchYFactor()+GetTouchYOffset();
							mouse_y = CLAMP(mouse_y, GetTouchYOffset(), lim-1);
							SetRawY(mouse_y);
							BxGfxDFBDrv_PutCursor(GetCalcX(),GetCalcY(),CURSORW,CURSORH);
							break;
						default:
							//                    snprintf (buf, sizeof(buf),
							//                              "Axis %d (rel): %d", evt->axis, evt->axisrel);
							break;
						}
          }
//          mouse_x = CLAMP (mouse_x, 0, screen_width  - 1);
//          mouse_y = CLAMP (mouse_y, 0, screen_height - 1);
					break;
			default:
        break;
			}
    }
  }
//				case MotionNotify:
//            BxInsertMouseEvent(2, xev.xmotion.x, xev.xmotion.y);
//	          BxSetEvent();
//          break;
//				case ButtonRelease:
//          BxInsertMouseEvent(4, xev.xbutton.x, xev.xbutton.y);
//	        BxSetEvent();
//          break;
//        case ButtonPress:
//          BxInsertMouseEvent(1, xev.xbutton.x, xev.xbutton.y);
//	        BxSetEvent();
//          break;
  return NULL;
}


