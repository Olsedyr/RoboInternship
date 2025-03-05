#include "Bx.h"

#include "gdi_header.h"

#include "inlstring.h"
#include "def.h"

static fb_drv fbdrv;

/* Two bytes per pixel graphics primitives */

#define ASSIGNVP16(x, y, vp) vp = VBUF + (y) * BYTEWIDTH + (x) * 2;
#define ASSIGNVPOFFSET16(x, y, vp) vp = (y) * BYTEWIDTH + (x) * 2;

void setpixel(int x, int y, int c) /* 16 bit */
{
	unsigned char *vp;
	ASSIGNVP16(x, y, vp);
	*(unsigned short *) vp = c;
}

int getpixel(int x, int y) /* 16 bit */
{
	unsigned char *vp;
	ASSIGNVP16(x, y, vp);
	return *(unsigned short *) vp;
}

void hline(int x1, int y, int x2, int c) /* 16 bit */
{
	unsigned char *vp;
	ASSIGNVP16(x1, y, vp);
	__memset2(vp, c, x2 - x1 + 1);
}

void fillbox(int x, int y, int w, int h, int c)  /* 16 bit */
{
	unsigned char *vp;
	int i;
	ASSIGNVP16(x, y, vp);
	for (i = 0; i < h; i++) {
		__memset2(vp, c, w);
		vp += BYTEWIDTH;
	}
}

void putbox_16(int x, int y, int w, int h, char *img, int ptype)  /* 16 bit */
{
	unsigned char *vp;
  char *vps = img;
	int i, j, sizeOfUShort = sizeof(unsigned short);
  unsigned short m = *(unsigned short*)img;
  ASSIGNVP16(x, y, vp);
	for (i = 0; i < h; i++) {
//	  memcpy(vp, vps, w*2);
	  for (j=0;j<w;j++) {
      if(*(unsigned short*)vps!=m)
        *(((unsigned short*)vp)+j) = *((unsigned short*)vps);
      vps += sizeOfUShort;
    }
//    vps += (w*2);
		vp += BYTEWIDTH;
	}
}

#define ASSIGNVP24(x, y, vp) vp = VBUF + (y) * BYTEWIDTH + (x) * 3;
#define ASSIGNVPOFFSET24(x, y, vp) vp = (y) * BYTEWIDTH + (x) * 3;

void setpixel_24(int x, int y, int c) /* 24 bit */
{
	unsigned char *vp;
	ASSIGNVP24(x, y, vp);
	*(unsigned int *) vp = c;
}

int getpixel_24(int x, int y) /* 24 bit */
{
	unsigned char *vp;
	ASSIGNVP24(x, y, vp);
	return *(unsigned int *) vp;
}

void hline_24(int x1, int y, int x2, int c) /* 24 bit */
{
	unsigned char *vp;
	int i;
	ASSIGNVP24(x1, y, vp);
	for(i=0;i<(x2 - x1 + 1); i++)
		*(unsigned int *)(vp+(i*3)) = c&0x00FFFFFF;
}

void fillbox_24(int x, int y, int w, int h, int c)  /* 24 bit */
{
	unsigned char *vp;
	int i, j;
	ASSIGNVP24(x, y, vp);
	for (i = 0; i < h; i++) {
		for(j=0;j<w;j++)
      *(unsigned int *)(vp+(j*3)) = c&0x00ffffff;
		vp += BYTEWIDTH;
	}
}

void putbox_24(int x, int y, int w, int h, char *img, int ptype)  /* 24 bit */
{
	unsigned char *vp, r, g, b;
	int i, j;

  ASSIGNVP24(x, y, vp);

  if(ptype==1)
  {
    r=img[0];
    g=img[1];
    b=img[2];
	  for (i = 0; i < h; i++)
    {
		  for(j=0;j<w; j++)
		  {
        if(!(img[(i*w*3)+(j*3)]==r&&img[(i*w*3)+(j*3)+1]==g&&img[(i*w*3)+(j*3)+2]==b))
        {
          *(vp+(j*3)) = img[(i*w*3)+(j*3)];
	        *(vp+(j*3)+1) = img[(i*w*3)+(j*3)+1];
	        *(vp+(j*3)+2) = img[(i*w*3)+(j*3)+2];
        }
      }
		  vp += BYTEWIDTH;
	  }
  }
  else
  {
	  for (i = 0; i < h; i++)
    {
	    for(j=0;j<w; j++)
	    {
	      *(vp+(j*3)) = img[(i*w*3)+(j*3)];
	      *(vp+(j*3)+1) = img[(i*w*3)+(j*3)+1];
	      *(vp+(j*3)+2) = img[(i*w*3)+(j*3)+2];
      }
	    vp += BYTEWIDTH;
	  }
  }
}


#define ASSIGNVP32(x, y, vp) vp = VBUF + (y) * BYTEWIDTH + (x) * 4;
#define ASSIGNVPOFFSET32(x, y, vp) vp = (y) * BYTEWIDTH + (x) * 4;

void setpixel_32(int x, int y, int c) /* 32 bit */
{
	unsigned char *vp;
	ASSIGNVP32(x, y, vp);
	*(unsigned int *) vp = c;
}

int getpixel_32(int x, int y) /* 32 bit */
{
	unsigned char *vp;
	ASSIGNVP32(x, y, vp);
	return *(unsigned int *) vp;
}

void hline_32(int x1, int y, int x2, int c) /* 32 bit */
{
	unsigned char *vp;
	int i;
	ASSIGNVP32(x1, y, vp);
	for(i=0;i<(x2 - x1 + 1); i++)
		*(((unsigned int *)vp)+i) = c;
}

void fillbox_32(int x, int y, int w, int h, int c)  /* 32 bit */
{
	unsigned char *vp;
	int i, j;
	ASSIGNVP32(x, y, vp);
	for (i = 0; i < h; i++) {
		for(j=0;j<w; j++)
			*(((unsigned int *)vp)+j) = c;
		vp += BYTEWIDTH;
	}
}

void putbox_32(int x, int y, int w, int h, char *img, int ptype)  /* 32 bit */
{
	unsigned char *vp;
	int i, j;
	ASSIGNVP32(x, y, vp);
	for (i = 0; i < h; i++) {
		for(j=0;j<w; j++)
		{
	    *(vp+j) = img[(i*w*3)+(j*3)];
	    *(vp+j+1) = img[(i*w*3)+(j*3)+1];
	    *(vp+j+2) = img[(i*w*3)+(j*3)+2];
    }
		vp += BYTEWIDTH;
	}
}


/* Primitive functions */

void gl_setpixel(int x, int y, int c)
{
	if (__clip && outside(x, y))
		return;
	fbdrv.setpixel(x, y, c);
}


int gl_getpixel(int x, int y)
{
	if (__clip && outside(x, y))
		return -1;
	return fbdrv.getpixel(x, y);
}

void gl_hline(int x1, int y, int x2, int c)
{
	//	if (__clip) {
	if (y_outside(y))
		return;
	clipxleft(x1);
	clipxright(x2);
	if (x1 > x2)
		return;
	//}
	fbdrv.hline(x1, y, x2, c);
}

void gl_fillbox(int x, int y, int w, int h, int c)
{
	if (__clip) {
		if (x + w < __clipx1 || x > __clipx2)
			return;
		if (y + h < __clipy1 || y > __clipy2)
			return;
		if (x < __clipx1) {
			w -= __clipx1 - x;
			x = __clipx1;
		}
		if (y < __clipy1) {
			h -= __clipy1 - y;
			y = __clipy1;
		}
		if (x + w > __clipx2 + 1)
			w = __clipx2 - x + 1;
		if (y + h > __clipy2 + 1)
			h = __clipy2 - y + 1;
	}
	if (w <= 0 || h <= 0)
		return;
	fbdrv.fillbox(x, y, w, h, c);
}

void gl_putbox(int x, int y, int w, int h, char* img, int ptype)
{
	if (__clip) {
		if (x + w < __clipx1 || x > __clipx2)
			return;
		if (y + h < __clipy1 || y > __clipy2)
			return;
		if (x < __clipx1) {
			w -= __clipx1 - x;
			x = __clipx1;
		}
		if (y < __clipy1) {
			h -= __clipy1 - y;
			y = __clipy1;
		}
		if (x + w > __clipx2 + 1)
			w = __clipx2 - x + 1;
		if (y + h > __clipy2 + 1)
			h = __clipy2 - y + 1;
	}
	if (w <= 0 || h <= 0)
		return;
  if(fbdrv.putbox)
	  fbdrv.putbox(x, y, w, h, img, ptype);
}

int setupLowlevelDrv(int bpp)
{
	switch(bpp) {
		case 16:
			fbdrv.setpixel = setpixel;
			fbdrv.getpixel = getpixel;
			fbdrv.hline = hline;
			fbdrv.fillbox = fillbox;
      fbdrv.putbox = putbox_16;
			return 0;
			break;
		case 24:
			fbdrv.setpixel = setpixel_24;
			fbdrv.getpixel = getpixel_24;
			fbdrv.hline = hline_24;
			fbdrv.fillbox = fillbox_24;
      fbdrv.putbox = putbox_24;
			return 0;
			break;
		case 32:
			fbdrv.setpixel = setpixel_32;
			fbdrv.getpixel = getpixel_32;
			fbdrv.hline = hline_32;
			fbdrv.fillbox = fillbox_32;
      fbdrv.putbox = putbox_32;
			return 0;
			break;
	}

	return -1;
}
