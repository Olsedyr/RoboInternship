#include "hemite.h"
/********************************************************
 *     Hemite curve					*
 *							*
 * x(t) = x1*(2*t^3-3*t^2+1)+x2*(-2*t^3+2*t^2)+		*
 *	dx1*(t^3-2*t^2+t)+dx2*(t^3-t^2)			*
 *							*
 * y(t) = y1*(2*t^3-3*t^2+1)+y2*(-2*t^3+2*t^2)+		*
 *	dy1*(t^3-2*t^2+t)+dy2*(t^3-t^2)			*
 *							*
 * p1 = (x1, y1)					*
 * p2 = (x2, y2)					*
 * tan1 = (dx1, dy1)					*
 * tan2 = (dx2, dy2)					*
 *							*
 ********************************************************/

void CalcHemite(pvec v, pvec p1, pvec p2, 
	pvec tan1, pvec tan2, double t)
{
	double t3, t2, A, B, C, D;

	t2 = t * t;
	t3 = t * t2;
	A = 2 * t3 - 3 * t2 + 1;
	B = -2 * t3 + 3 * t2;
	C = t3 - 2 * t2 + t;
	D = t3 - t2;
	v->x = p1->x * A + p2->x * B + tan1->x * C + tan2->x * D;
	v->y = p1->y * A + p2->y * B + tan1->y * C + tan2->y * D;
}
