/************************************************		
 * Hemite.h					*
 *						*
 ************************************************/
typedef struct vec {
   int x;
   int y;
} vec, *pvec;

extern void CalcHemite(pvec v, pvec p1, pvec p2, 
		       pvec tan1, pvec tan2, double t);
