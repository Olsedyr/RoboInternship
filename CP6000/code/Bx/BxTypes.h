#ifndef BXTYPES
#define BXTYPES
///////////////////////////////////////////////////////////////
// Type definition
typedef          long		    BX_S64; // 64 Bit
typedef unsigned long		    BX_U64; // 64 Bit unsigned
typedef          int		    BX_S32; // 32 Bit
typedef unsigned int		    BX_U32; // 32 Bit unsigned
typedef          short	    BX_S16; // 16 Bit
typedef unsigned short	    BX_U16; // 16 Bit unsigned
typedef          char		    BX_S8;  //  8 Bit
typedef unsigned char		    BX_U8;  //  8 Bit unsigned

typedef unsigned char       BX_BYTE; // 8 Bit
typedef char                BX_CHAR; // 8 Bit
typedef unsigned char       BX_UCHAR; // 8 Bit
typedef unsigned short      BX_WORD; // 16 Bit
typedef unsigned int        BX_DWORD; // 32 Bit
typedef BX_U64					    BX_QWORD; // 64 Bit
typedef long                BX_LONG;  // 32 Bit
typedef short								BX_SHORT; // 16 Bit signed
typedef int                 BX_INT; // 32 Bit signed
typedef void                BX_VOID;
typedef float               BX_FLOAT;  // 32 Bit
typedef double              BX_DOUBLE; // 64 Bit

typedef unsigned int        BX_UINT;
typedef unsigned int        *BX_PUINT;

typedef BX_BYTE             *BX_PUCHAR;
typedef BX_BYTE             *BX_PBYTE;
typedef int                 BX_BOOL;

/* Types use for passing & returning polymorphic values */
typedef BX_UINT BX_WPARAM;
typedef BX_LONG BX_LPARAM;
typedef BX_LONG BX_LRESULT;

typedef BX_DWORD BX_COLORREF;

#define CONST               const

typedef BX_VOID             *BX_PVOID; // pointer
typedef char								*BX_PSTRING;

#define max(a,b)            (((a) > (b)) ? (a) : (b))

#define min(a,b)            (((a) < (b)) ? (a) : (b))

#define BXMIN	min
#define BXMAX	max
#define BXABS(c) ((c)<(0) ? (-c) : (c))

#define BX_MAKEWORD(a, b)      ((BX_WORD)(((BX_BYTE)(a)) | ((BX_WORD)((BX_BYTE)(b))) << 8))
#define BX_MAKELONG(a, b)      ((BX_LONG)(((BX_WORD)(a)) | ((BX_DWORD)((BX_WORD)(b))) << 16))
#define BX_LOWORD(l)           ((BX_WORD)(l))
#define BX_HIWORD(l)           ((BX_WORD)(((BX_DWORD)(l) >> 16) & 0xFFFF))
#define BX_LOBYTE(w)           ((BX_BYTE)(w))
#define BX_HIBYTE(w)           ((BX_BYTE)(((BX_WORD)(w) >> 8) & 0xFF))


typedef BX_PVOID            BX_HOOK;
#define DECLARE_HOOK(name) typedef BX_HOOK name

DECLARE_HOOK				(HBOX);
//DECLARE_HOOK				(HAPP);
DECLARE_HOOK        (HBC);
//DECLARE_HOOK        (HCURSOR);
DECLARE_HOOK        (PFONT);
DECLARE_HOOK        (PPEN);
DECLARE_HOOK        (PBRUSH);
DECLARE_HOOK		(PRGN);
DECLARE_HOOK		(PINSTANCE);

//DECLARE_HOOK        (HDEVICE);

DECLARE_HOOK			  (PCLASS);

typedef BX_LONG (*BXPROC)(
        HBOX  hBox,     // handle of box
        BX_UINT  uMsg,  // message identifier
        BX_WPARAM  wParam,      // first message parameter
        BX_LPARAM  lParam       // second message parameter
	);

typedef BX_BOOL (*BXDLGPROC)(HBOX hBox, BX_UINT uMsg	,BX_WPARAM wParam, BX_LPARAM lParam);




#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* Define NULL pointer value and the offset() macro */

#ifndef NULL
#ifdef  __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

DECLARE_HOOK        (BX_HTASK);

///////////////////////////////////////////////////////////////
// Structure definition

typedef struct BX_POINT
{
	BX_LONG x;
	BX_LONG y;
} BX_POINT, *BX_PPOINT;


typedef struct BX_RECT
{
	BX_WORD left;
	BX_WORD top;
	BX_WORD right;
	BX_WORD bottom;
} BX_RECT, *BX_PRECT;

#endif // BXTYPES
