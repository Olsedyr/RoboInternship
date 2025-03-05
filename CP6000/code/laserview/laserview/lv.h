/***************************************************************************
                          lv.h  -  description
                             -------------------
    begin                : søn okt 19 2003
    copyright            : (C) 2003 by Lars M Sandig
    email                : lms@mpn-lms
 ***************************************************************************/

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef struct CAMINFO
{
  unsigned long frames;
  unsigned int droped;
  unsigned int dropedTotal;
} CAMINFO;

extern CAMINFO caminfo;

typedef struct CAMPARAM
{
  unsigned int framerate;
  unsigned int mode;
  unsigned int format;
  unsigned int channel;
  unsigned int speed;
  int          is_on;
  unsigned int brightness;
  unsigned int exposure;
  unsigned int sharpness;
  unsigned int u_b_value;
  unsigned int v_r_value;
  unsigned int hue;
  unsigned int saturation;
  unsigned int gamma;
  unsigned int shutter;
  unsigned int gain;
  unsigned int iris;
  unsigned int focus;
  unsigned int trigger_mode;
  unsigned int zoom;
  unsigned int optical_filter;
} CAMPARAM;

extern CAMPARAM camparam;

typedef struct FOISTRUCT
{
  int left;
  int top;
  int right;
  int bottom;
} FOI;

extern volatile FOI foi;

typedef struct HSISTRUCT
{
  float h_min;
  float h_max;
  float i;
  float s;
} HSI;

extern volatile HSI hsi;
extern volatile int step;

extern int SaveDIB(char* filename, unsigned char *imgdata, long BW, long BH);
extern int SaveGreyDIB(char* filename, unsigned char *imgdata, long BW, long BH);

extern void saveTempImage(void);
extern void getCamParam(void);
extern void setCamParam(void);
extern int savesystemdata(void);
extern int loadsystemdata(void);
