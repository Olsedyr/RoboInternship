typedef struct fb_drv {
	void (*setpixel)(int x, int y, int c);
	int (*getpixel)(int x, int y);
	void (*line) (int x1, int y1, int x2, int y2, int c);
	void (*hline)(int x1, int y, int x2, int c);
	void (*fillbox)(int x, int y, int w, int h, int c) ;
	void (*putbox)(int x, int y, int w, int h, char *img, int ptype) ;
} fb_drv;

extern BxGfxDrvInfo FBInfo;
extern BX_RECT clipRect;
extern int __clip;

#define __clipx1 clipRect.left
#define __clipx2 clipRect.right
#define __clipy1 clipRect.top
#define __clipy2 clipRect.bottom
#define BYTEWIDTH FBInfo.ByteWidth
#define BYTESPERPIXEL FBInfo.BytesPrPixel
#define VBUF FBInfo.framebuffer
#define WIDTH FBInfo.Width
#define HEIGHT FBInfo.Height

extern void gl_setpixel(int x, int y, int c);
extern int gl_getpixel(int x, int y);
extern void gl_hline(int x1, int y, int x2, int c);
extern void gl_fillbox(int x, int y, int w, int h, int c);
extern void gl_putbox(int x, int y, int w, int h, char *img, int ptype);
extern int setupLowlevelDrv(int bpp);
