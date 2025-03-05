#ifndef BXDRIVERS
#define BXDRIVERS

#include "BxTypes.h"

#define BX_MAXDEVICENAME 25

#define BXDM_GRAYSCALE		1

typedef struct BXDEVMODE {// dvmd
	BX_CHAR  dmDeviceName[BX_MAXDEVICENAME]; 
  BX_WORD   dmSpecVersion;
	BX_WORD   dmDriverVersion;
	BX_WORD   dmSize; 
  BX_DWORD  dmBitsPerPel;
	BX_DWORD  dmPelsWidth;
	BX_DWORD  dmPelsHeight; 
  BX_DWORD  dmDisplayFlags; // BXDM_GRAYSCALE or color
	BX_DWORD  dmDisplayFrequency;
} BXDEVMODE; 

#define OUTMEMORY_BYTE(adr, byte) (outmemb((adr), (byte)))
#define OUTMEMORY_WORD(adr, byte) (outmemw((adr), (byte)))

#include "BxGfxDrv.h"

extern BxGfxDrv BxGfxMEMDrv;
/////////////////////////////////////////////////////////////////
// Driver proc rutine

#endif // BXDRIVERS
