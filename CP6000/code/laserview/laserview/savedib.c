/***************************************************************************
                          savedib.c  -  description
                             -------------------
    begin                : tir okt 21 2003
    copyright            : (C) 2003 by Lars M Sandig
    email                : lms@mpn-lms
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "lv.h"

int SaveDIB(char* filename, unsigned char *imgdata, long BW, long BH)
{
  FILE* fp;
//  netYUV* startyuv;
  unsigned char head[54]={0x42,0x4D
    ,0,0,0,0
    ,0,0,0,0
    ,54,0,0,0
    ,40,0,0,0
    ,0,0,0,0
    ,0,0,0,0
    ,1,0,24,0
    ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  int j;
  unsigned int l;
  unsigned int temp;
  long x,y;
  unsigned char r,g,b;
  l = BW * BH + 54;
  head[5] = (unsigned char)(l >> 24);
  temp = l << 8;
  head[4] = (unsigned char)(temp >> 24);
  temp = l << 16;
  head[3] = (unsigned char)(temp >> 24);
  temp = l << 24;
  head[2] = (unsigned char)(temp >> 24);

  l = BW;
  temp = l;
  head[21] = (unsigned char)(temp >> 24);
  temp = l << 8;
  head[20] = (unsigned char)(temp >> 24);
  temp = l << 16;
  head[19] = (unsigned char)(temp >> 24);
  temp = l << 24;
  head[18] = (unsigned char)(temp >> 24);

  l = BH;
  temp = l;
  head[25] = (unsigned char)(temp >> 24);
  temp = l << 8;
  head[24] = (unsigned char)(temp >> 24);
  temp = l << 16;
  head[23] = (unsigned char)(temp >> 24);
  temp = l << 24;
  head[22] = (unsigned char)(temp >> 24);

  if ((fp = fopen(filename, "w"))==NULL)	return FALSE;
  for(j=0;j<54;j++)
  {
    if(fwrite(&head[j], 1, 1, fp)!=1) return FALSE;
  }

  for(y=BH-1;y>=0;y--)
  {
    for(x=0;x<BW;x++)
    {
      r = imgdata[(BW*y*3)+(x*3)+2];
      g = imgdata[(BW*y*3)+(x*3)+1];
      b = imgdata[(BW*y*3)+(x*3)];

//      fwrite(&b, 1, 1, fp);
//      fwrite(&g, 1, 1, fp);
//      fwrite(&r, 1, 1, fp);
      fwrite(&r, 1, 1, fp);
      fwrite(&g, 1, 1, fp);
      fwrite(&b, 1, 1, fp);
    }
  }
  fclose(fp);
  return TRUE;
}


int SaveGreyDIB(char* filename, unsigned char *imgdata, long BW, long BH)
{
  FILE* fp;
//  netYUV* startyuv;
  unsigned char head[54]={0x42,0x4D
    ,0,0,0,0
    ,0,0,0,0
    ,54,0,0,0
    ,40,0,0,0
    ,0,0,0,0
    ,0,0,0,0
    ,1,0,24,0
    ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  int j;
  unsigned int l;
  unsigned int temp;
  long x,y;
  unsigned char b;
  l = BW * BH + 54;
  head[5] = (unsigned char)(l >> 24);
  temp = l << 8;
  head[4] = (unsigned char)(temp >> 24);
  temp = l << 16;
  head[3] = (unsigned char)(temp >> 24);
  temp = l << 24;
  head[2] = (unsigned char)(temp >> 24);

  l = BW;
  temp = l;
  head[21] = (unsigned char)(temp >> 24);
  temp = l << 8;
  head[20] = (unsigned char)(temp >> 24);
  temp = l << 16;
  head[19] = (unsigned char)(temp >> 24);
  temp = l << 24;
  head[18] = (unsigned char)(temp >> 24);

  l = BH;
  temp = l;
  head[25] = (unsigned char)(temp >> 24);
  temp = l << 8;
  head[24] = (unsigned char)(temp >> 24);
  temp = l << 16;
  head[23] = (unsigned char)(temp >> 24);
  temp = l << 24;
  head[22] = (unsigned char)(temp >> 24);

  if ((fp = fopen(filename, "w"))==NULL)	return FALSE;
  for(j=0;j<54;j++)
  {
    if(fwrite(&head[j], 1, 1, fp)!=1) return FALSE;
  }

  for(y=BH-1;y>=0;y--)
  {
    for(x=0;x<BW;x++)
    {
      b = imgdata[(BW*y)+(x)];
      fwrite(&b, 1, 1, fp);
      fwrite(&b, 1, 1, fp);
      fwrite(&b, 1, 1, fp);
    }
  }
  fclose(fp);
  return TRUE;
}
