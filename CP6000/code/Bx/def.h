#define uchar unsigned char
#define swap(x, y) { int temp = x; x = y; y = temp; }
#define swapb(x, y) { uchar temp = x; x = y; y = temp; }
#ifndef max
#define max(x, y) ((x > y) ? x : y)
#endif
#ifndef min
#define min(x, y) ((x > y) ? y : x)
#endif
#define outside(x, y) (x < __clipx1 || x > __clipx2 || y < __clipy1 \
	|| y > __clipy2)
#define x_outside(x) (x < __clipx1 || x > __clipx2)
#define y_outside(y) (y < __clipy1 || y > __clipy2)
#define clipxleft(x) if (x < __clipx1) x = __clipx1;
#define clipxright(x) if (x > __clipx2) x = __clipx2;
#define clipytop(y) if (y < __clipy1) y = __clipy1;
#define clipybottom(y) if (y > __clipy2) y = __clipy2;

/*
#define setpixel (*(__currentcontext.ff.driver_setpixel_func))
#define getpixel (*(__currentcontext.ff.driver_getpixel_func))
#define hline (*(__currentcontext.ff.driver_hline_func))
#define fillbox (*(__currentcontext.ff.driver_fillbox_func))
#define putbox (*(__currentcontext.ff.driver_putbox_func))
#define getbox (*(__currentcontext.ff.driver_getbox_func))
#define putboxmask (*(__currentcontext.ff.driver_putboxmask_func))
#define putboxpart (*(__currentcontext.ff.driver_putboxpart_func))
#define getboxpart (*(__currentcontext.ff.driver_getboxpart_func))
#define copybox (*(__currentcontext.ff.driver_copybox_func))

#define TEXT_TABSIZE 8
*/
