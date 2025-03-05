#include "BxVKeys.h"

/* Some Key Defs */
/* Function keys */
#define	F1		(0x80|0x00)
#define	F2		(0x80|0x01)
#define	F3		(0x80|0x02)
#define	F4		(0x80|0x03)
#define	F5		(0x80|0x04)
#define	F6		(0x80|0x05)
#define	F7		(0x80|0x06)
#define	F8		(0x80|0x07)
#define	F9		(0x80|0x08)
#define	F10		(0x80|0x09)
#define	F11		(0x80|0x0a)
#define	F12		(0x80|0x0b)

/* Num lock affects these */
#define	END		(0x80|0x0c)
#define	DOWN		(0x80|0x0d)
#define	PGDWN		(0x80|0x0e)
#define	LEFT		(0x80|0x0f)
#define	MIDDLE		(0x80|0x10)
#define	RIGHT		(0x80|0x11)
#define	HOME		(0x80|0x12)
#define	UP		(0x80|0x13)
#define	PGUP		(0x80|0x14)
#define	INS		(0x80|0x15)
#define	DEL		(0x80|0x16)

/* Others */
#define	PRTSC		(0x80|0x17)
#define	PAUSE		(0x80|0x18)
#define	ALTDWN		(0x80|0x19)
#define	ALTUP		(0x80|0x1a)

/*
 * Index by scan code from a 101 key
 * AT style keyboard. The keyboard driver maps the
 * keycodes from the 84 key keyboard into the
 * keycodes from the 101 key keyboard.
 */


xVkeys xVkeysTab[] = {
 /* unshifted  shifted  virtual key    */	/* Scan, key number		*/
 { 	0,	0,	      0	},	/* 0x00, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x01, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x02, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x03, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x04, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x05, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x06, Key num 0 		*/
 { 	F1,	F1,	      VK_F1},	/* 0x07, Key num 112 		*/
 { 	033,	033,	  VK_ESCAPE	},	/* 0x08, Key num 110, ESC 	*/
 { 	0,	0,	      0	},	/* 0x09, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x0a, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x0b, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x0c, Key num 0 		*/
 { 	'\t',	'\t',	  VK_TAB	},	/* 0x0D, Key num 16 		*/
 { 	'`',	'~',	  0	},	/* 0x0E, Key num 1 		*/
 { 	F2,	F2,	      VK_F2},	/* 0x0F, Key num 113 		*/
 { 	0,	0,	      0	},	/* 0x10, Key num 0 		*/
 { 	0,	0,	      VK_LCONTROL	},	/* F0 0x11, Key num 58 		*/
 { 	0,	0,	      VK_LSHIFT	},	/* F0 0x12, Key num 44 		*/
 { 	0,	0,	      0	},	/* 0x13, Key num 0 		*/
 { 	0,	0,	      VK_CAPITAL	},	/* F0 0x14, Key num 30 		*/
 { 	'q',	'Q',	  'Q'	},	/* 0x15, Key num 17 		*/
 { 	'1',	'!',	  '1'	},	/* 0x16, Key num 2 		*/
 { 	F3,	F3,	      VK_F3},	/* 0x17, Key num 114 		*/
 { 	0,	0,	      0	},	/* 0x18, Key num 0 		*/
 { 	0,	0,	      VK_LMENU	},	/* F0 0x19, Key num 60 		*/
 { 	'z',	'Z',	  'Z'	},	/* 0x1A, Key num 46 		*/
 { 	's',	'S',	  'S'	},	/* 0x1B, Key num 32 		*/
 { 	'a',	'A',	  'A'	},	/* 0x1C, Key num 31 		*/
 { 	'w',	'W',	  'W'	},	/* 0x1D, Key num 18 		*/
 { 	'2',	'@',	  '2'	},	/* 0x1E, Key num 3 		*/
 { 	F4,	F4,	      VK_F4},	/* 0x1F, Key num 115 		*/
 { 	0,	0,	      0	},	/* 0x20, Key num 0 		*/
 { 	'c',	'C',	  'C'	},	/* 0x21, Key num 48 		*/
 { 	'x',	'X',	  'X'	},	/* 0x22, Key num 47 		*/
 { 	'd',	'D',	  'D'	},	/* 0x23, Key num 33 		*/
 { 	'e',	'E',	  'E'	},	/* 0x24, Key num 19 		*/
 { 	'4',	'$',	  '4'	},	/* 0x25, Key num 5 		*/
 { 	'3',	'#',	  '3'	},	/* 0x26, Key num 4 		*/
 { 	F5,	F5,	      VK_F5},	/* 0x27, Key num 116 		*/
 { 	0,	0,	      0	},	/* 0x28, Key num 0 		*/
 { 	' ',	' ',	  VK_SPACE	},	/* 0x29, Key num 61 		*/
 { 	'v',	'V',	  'V'	},	/* 0x2A, Key num 49 		*/
 { 	'f',	'F',	  'F'	},	/* 0x2B, Key num 34 		*/
 { 	't',	'T',	  'T'	},	/* 0x2C, Key num 21 		*/
 { 	'r',	'R',	  'R'	},	/* 0x2D, Key num 20 		*/
 { 	'5',	'%',	  '5'	},	/* 0x2E, Key num 6 		*/
 { 	F6,	F6,	      VK_F6},	/* 0x2F, Key num 117 		*/
 { 	0,	0,	      0	},	/* 0x30, Key num 0 		*/
 { 	'n',	'N',	  'N'	},	/* 0x31, Key num 51 		*/
 { 	'b',	'B',	  'B'	},	/* 0x32, Key num 50 		*/
 { 	'h',	'H',	  'H'	},	/* 0x33, Key num 36 		*/
 { 	'g',	'G',	  'G'	},	/* 0x34, Key num 35 		*/
 { 	'y',	'Y',	  'Y'	},	/* 0x35, Key num 22 		*/
 { 	'6',	'^',	  '6'	},	/* 0x36, Key num 7 		*/
 { 	F7,	F7,	      VK_F7},	/* 0x37, Key num 118 		*/
 { 	0,	0,	      0	},	/* 0x38, Key num 0 		*/
 { 	0,	0,	      VK_RMENU	},	/* 0x39, Key num 62 		*/
 { 	'm',	'M',	  'M'	},	/* 0x3A, Key num 52 		*/
 { 	'j',	'J',	  'J'	},	/* 0x3B, Key num 37 		*/
 { 	'u',	'U',	  'U'	},	/* 0x3C, Key num 23 		*/
 { 	'7',	'&',	  '7'	},	/* 0x3D, Key num 8 		*/
 { 	'8',	'*',	  '8'	},	/* 0x3E, Key num 9 		*/
 { 	F8,	F8,	      VK_F8},	/* 0x3F, Key num 119 		*/
 { 	0,	0,	      0	},	/* 0x40, Key num 0 		*/
 { 	',',	'<',	  0	},	/* 0x41, Key num 53 		*/
 { 	'k',	'K',	  'K'	},	/* 0x42, Key num 38 		*/
 { 	'i',	'I',	  'I'	},	/* 0x43, Key num 24 		*/
 { 	'o',	'O',	  'O'	},	/* 0x44, Key num 25 		*/
 { 	'0',	')',	  '0'	},	/* 0x45, Key num 11 		*/
 { 	'9',	'(',	  '9'	},	/* 0x46, Key num 10 		*/
 { 	F9,	F9,	      VK_F9},	/* 0x47, Key num 120 		*/
 { 	0,	0,	      0	},	/* 0x48, Key num 0 		*/
 { 	'.',	'>',	  0	},	/* 0x49, Key num 54 		*/
 { 	'/',	'?',	  0	},	/* 0x4A, Key num 55 		*/
 { 	'l',	'L',	  'L'	},	/* 0x4B, Key num 39 		*/
 { 	';',	':',	  0	},	/* 0x4C, Key num 40 		*/
 { 	'p',	'P',	  'P'	},	/* 0x4D, Key num 26 		*/
 { 	'-',	'_',	  0	},	/* 0x4E, Key num 12 		*/
 { 	F10,	F10,	  VK_F10},	/* 0x4F, Key num 121 		*/
 { 	0,	0,	      0	},	/* 0x50, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x51, Key num 0 		*/
 { 	'\'',	'\"',	  0	},	/* 0x52, Key num 41 		*/
 { 	0,	0,	      0	},	/* 0x53, Key num 0 		*/
 { 	'[',	'{',	  0	},	/* 0x54, Key num 27 		*/
 { 	'=',	'+',	  0	},	/* 0x55, Key num 13 		*/
 { 	F11,	F11,	  VK_F11},	/* 0x56, Key num 122 		*/
 { 	PRTSC,	PRTSC,	VK_PRINT},	/* 0x57, Key num 124 		*/
 { 	0,	0,	      VK_RCONTROL	},	/* 0x58, Key num 64 		*/
 { 	0,	0,	      VK_RSHIFT	},	/* F0 0x59, Key num 57 		*/
 { 	'\r',	'\r',	  VK_RETURN	},	/* 0x5A, Key num 43 		*/
 { 	']',	'}',	  0	},	/* 0x5B, Key num 28 		*/
 { 	'\\',	'|',	  0	},	/* 0x5C, Key num 29 		*/
 { 	0,	0,	      0	},	/* 0x5d, Key num 0 		*/
 { 	F12,	F12,	  VK_F12},	/* 0x5E, Key num 123 		*/
 { 	0,	0,	      VK_SCROLL	},	/* 0x5F, Key num 125 		*/
 { 	DOWN,	DOWN,	  VK_DOWN	},	/* 0x60, Key num 84 		*/
 { 	LEFT,	LEFT,	  VK_LEFT	},	/* 0x61, Key num 79 		*/
 { 	PAUSE,	PAUSE,	VK_PAUSE},	/* 0x62, Key num 126 		*/
 { 	UP,	UP,	      VK_UP	},	/* 0x63, Key num 83 		*/
 { 	DEL,	DEL,	  VK_DELETE	},	/* 0x64, Key num 76 		*/
 { 	END,	END,	  VK_END	},	/* 0x65, Key num 81 		*/
// { 	MCTRL('H'), MCTRL('H'),	0 }, /* 0x66, Key num 15 		*/
 { 	0, 0,	0 }, /* 0x66, Key num 15 		*/
 { 	INS,	INS,	  VK_INSERT	},	/* 0x67, Key num 75 		*/
 { 	0,	0,	      0	},	/* 0x68, Key num 0 		*/
 { 	END,	'1',	  VK_NUMPAD1	},	/* 0x69, Key num 93 		*/
 { 	RIGHT,	RIGHT,	VK_RIGHT	},	/* 0x6A, Key num 89 		*/
 { 	LEFT,	'4',	  VK_NUMPAD4	},	/* 0x6B, Key num 92 		*/
 { 	HOME,	'7',	  VK_NUMPAD7	},	/* 0x6C, Key num 91 		*/
 { 	PGDWN,	PGDWN,	0	},	/* 0x6D, Key num 86 		*/
 { 	HOME,	HOME,	  VK_NUMPAD7	},	/* 0x6E, Key num 80 		*/
 { 	PGUP,	PGUP,	  VK_NUMPAD9	},	/* 0x6F, Key num 85 		*/
 { 	INS,	'0',	  VK_NUMPAD0	},	/* 0x70, Key num 99 		*/
 { 	DEL,	'.',	  VK_SEPARATOR	},	/* 0x71, Key num 104 		*/
 { 	DOWN,	'2',	  VK_NUMPAD2	},	/* 0x72, Key num 98 		*/
 { 	MIDDLE,	'5',	VK_NUMPAD5	},	/* 0x73, Key num 97 		*/
 { 	RIGHT,	'6',	VK_NUMPAD6	},	/* 0x74, Key num 102 		*/
 { 	UP,	'8',	    VK_NUMPAD8	},	/* 0x75, Key num 96 		*/
 { 	0,	0,	      VK_NUMLOCK	},	/* 0x76, Key num 90 		*/
 { 	'/',	'/',	  0	},	/* 0x77, Key num 95 		*/
 { 	0,	0,	      0	},	/* 0x78, Key num 0 		*/
 { 	'\r',	'\r',	  VK_RETURN  },	/* F0 0x79, Key num 108 	*/
 { 	PGDWN,	'3',	VK_NUMPAD3	},	/* 0x7A, Key num 103 		*/
 { 	0,	0,	      0	},	/* 0x7b, Key num 0 		*/
 { 	'+',	'+',	  VK_ADD	},	/* 0x7C, Key num 106 		*/
 { 	PGUP,	'9',	  VK_NUMPAD9	},	/* 0x7D, Key num 101 		*/
 { 	'*',	'*',	  VK_MULTIPLY	},	/* 0x7E, Key num 100 		*/
 { 	0,	0,	      0	},	/* 0x7f, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x80, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x81, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x82, Key num 0 		*/
 { 	0,	0,	      0	},	/* 0x83, Key num 0 		*/
 { 	'-',	'-',	  VK_SUBTRACT	}	/* 0x84, Key num 105 		*/
} ;
