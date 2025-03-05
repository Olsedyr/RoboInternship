#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//extern void * memcpy(void * ps , const void * pct , size_t n);

#define BxMemAlloc		malloc
#define BxMemFree		free

#define BxStringCopy      strcpy
#define BxStringNCopy     strncpy
#define BxStringCompare   strcmp
#define BxStringLength    strlen
