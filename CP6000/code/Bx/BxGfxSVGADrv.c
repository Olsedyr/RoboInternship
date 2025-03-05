#include "Bx.h"
#include "BxDrivers.h"
#include "font.h"

#ifdef SVGAGFXDRV
#include <vga.h>
#include <vgagl.h>

GraphicsContext *physicalscreen;

extern void  __setpage(int page);
void DrawFontString(char *s, FONT *font, int x, int y, int color, char align);

#define MAX_COL                  800
#define MAX_ROW                  600
static int VGAMODE =             G800x600x64K;
#define scalex                   10
#define scaley                   24
static BX_RECT clipRect = {0, 0, MAX_COL, MAX_ROW };

static BX_WORD ConvertColor(BX_COLORREF clr)
{
	BX_WORD c=0;

	c = (BxGetRValue(clr)>>3)<<11 | (BxGetGValue(clr)>>2)<<5 | BxGetBValue(clr)>>3;

	return c;

}

static BX_INT BxGfxSVGADrv_Init(BX_VOID)
{

	vga_init();

	vga_setmode(VGAMODE);

	if(gl_setcontextvga(VGAMODE) < 0)
	{
		vga_setmode(TEXT);
		printf("context not available.\n");
		return BX_DRIVER_STARTUP_FAILED;
	}
	physicalscreen = gl_allocatecontext();

	gl_getcontext(physicalscreen);
//  gl_setcontext(physicalscreen);

	gl_setclippingwindow(clipRect.left, clipRect.top, clipRect.right, clipRect.bottom);
	gl_clearscreen(0x0);

	return BX_STATUS_OK;
}


static BX_VOID BxGfxSVGADrv_Rectangle(BX_RECT * pRect, BX_COLORREF pen, BX_COLORREF brush)
{
	gl_fillbox(pRect->left, pRect->top, pRect->right-pRect->left, pRect->bottom-pRect->top, ConvertColor(brush));
	gl_hline(pRect->left, pRect->top, pRect->right, ConvertColor(pen));
	gl_hline(pRect->left, pRect->bottom, pRect->right, ConvertColor(pen));
	gl_line(pRect->left, pRect->top, pRect->left, pRect->bottom, ConvertColor(pen));
	gl_line(pRect->right, pRect->top, pRect->right, pRect->bottom, ConvertColor(pen));
}


static BX_VOID BxGfxSVGADrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
{
	gl_line(x1, y1, x2, y2, ConvertColor(pen));
}


static BX_VOID BxGfxSVGADrv_FillRect(BX_RECT * pRect, BX_COLORREF brush)
{
	gl_fillbox(pRect->left, pRect->top, pRect->right-pRect->left, pRect->bottom-pRect->top, ConvertColor(brush));
}


static BX_BOOL BxGfxSVGADrv_TextOut(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT * pFont, BX_COLORREF FntClr, BX_COLORREF BkClr)
{
//  gl_setfontcolors(ConvertColor(FntClr), ConvertColor(BkClr));
//	gl_write( scalex*x, scaley*y, pStr );
	DrawFontString(pStr, pFont, x, y, ConvertColor(FntClr), 0);

	return TRUE;
}



static BX_COLORREF BxGfxSVGADrv_SetPixel(BX_INT x, BX_INT y, BX_COLORREF color)
{
	gl_setpixel(x, y, ConvertColor(color));

	return color;
}

static BX_BOOL BxGfxSVGADrv_PutBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits)
{
	BX_WORD *img;
	BX_INT i, j;

	img = (BX_WORD*)malloc(sizeof(BX_WORD)*(h*w));

	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			img[(i*w)+j] = ConvertColor(BX_RGB(bits[((i*w*3)+(j*3))],bits[((i*w*3)+(j*3))+1],bits[((i*w*3)+(j*3))+2]));
	gl_putbox(x, y, w, h, img);

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


static BX_BOOL BxGfxSVGADrv_PutMaskedBitmap(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR * bits, BX_UCHAR * mask)
{
	BX_WORD *img;
	BX_WORD *mimg;
	BX_INT i, j, l, k;
	int vp, bw = w*2, biw=w/8;
	int page;
	char *bp;
	char *mp;


	img = (BX_WORD*)malloc(sizeof(BX_WORD)*(h*w));

	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			img[(i*w)+j] = ConvertColor(BX_RGB(bits[((i*w*3)+(j*3))],bits[((i*w*3)+(j*3))+1],bits[((i*w*3)+(j*3))+2]));

	mimg = (BX_WORD*)malloc(sizeof(BX_WORD)*(h*w));

	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			mimg[(i*w)+j] = ConvertColor(BX_RGB(mask[((i*w*3)+(j*3))],mask[((i*w*3)+(j*3))+1],mask[((i*w*3)+(j*3))+2]));
/*

  bp = (char*)img;
  mp = (char*)mimg;

  vp = y * BYTEWIDTH + x*2;
  page = vp >> 16;
  vp &= 0xffff;
  __setpage(page);
  for (i = 0; i < h; i++) 
	{
		if (vp + w > 0x10000)
	  if (vp >= 0x10000) 
		{
			page++;
			__setpage(page);
			vp &= 0xffff;
	  } 
		else 
		{		
			l = 0x10000 - vp;
			k=0;
			for(j=0;j<l;j++) 
			{
				if(!*(mp+j))
					outmemb((unsigned int)(VBUF + vp)+j, *(bp+j));
			}
			page++;
			__setpage(page);
			l = (vp + bw) & 0xffff;
			for(j=0;j<l;j++) 
      {  
				if(!*(mp + 0x10000 - vp + j))
				{
					outmemb((unsigned int)VBUF+j, *(bp + 0x10000 - vp + j)); 
				}
			}
			vp = (vp + BYTEWIDTH) & 0xffff;
			bp += bw;
			mp += bw;
			continue;
	  }
		k=0;
		for(j=0;j<bw;j++) 
		{
			if(!*(mp+j))
			{
				outmemb((unsigned int)(VBUF + vp + j), *(bp+j));
			}
		}
		bp += bw;
		mp += bw;
		vp += BYTEWIDTH;
  }
*/  
	gl_putbox(x, y, w, h, mimg);
	gl_putbox(x, y, w, h, img);
	free( img );
	free( mimg );
	return TRUE;
}

BxGfxDrv BxGfxSVGADrv = 
{
	BxGfxSVGADrv_Init, //BX_INT (*Init)(BX_VOID);
	BxGfxSVGADrv_PutMaskedBitmap, //BX_BOOL (*PutMaskedBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits, BX_UCHAR* mask);
	BxGfxSVGADrv_PutBitmap, //BX_BOOL (*PutBitmap)(BX_INT x, BX_INT y, BX_INT w, BX_INT h, BX_UCHAR* bits);
	BxGfxSVGADrv_SetPixel, //BX_COLORREF (*SetPixel)(BX_INT x, BX_INT y, BX_COLORREF color);
	BxGfxSVGADrv_TextOut, //BX_BOOL (*TextOut)(BX_INT x, BX_INT y, BX_PSTRING pStr, BX_INT lenStr, FONT* pFont, BX_COLORREF FntClr, BX_COLORREF BkClr);
	BxGfxSVGADrv_FillRect, //BX_VOID (*FillRect)(BX_RECT* pRect, BX_COLORREF brush);
	BxGfxSVGADrv_Rectangle,  //BX_VOID (*Rectangle)(BX_RECT* pRect, BX_COLORREF pen, BX_COLORREF brush);
	BxGfxSVGADrv_Line  //BX_VOID BxGfxSVGADrv_Line(BX_INT x1, BX_INT y1, BX_INT x2, BX_INT y2, BX_COLORREF pen)
};
#endif //SVGAGFXDRV

