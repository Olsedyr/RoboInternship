/***************************************************************************
                          cammain.c  -  description
                             -------------------
    begin                : søn okt 19 2003
    copyright            : (C) 2003 by Lars M Sandig
    email                : lms@mpn-lms
 ***************************************************************************/
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#include <unistd.h>

#include <libraw1394/raw1394.h>
#include <libdc1394/dc1394_control.h>

#include "lv.h"

pthread_cond_t profil_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t profil_mutex = PTHREAD_MUTEX_INITIALIZER;

static raw1394handle_t handle;
static dc1394_cameracapture camera;
CAMINFO caminfo = {0, 0, 0};
CAMPARAM camparam;
volatile FOI foi = {20, 180, 620, 300};
volatile HSI hsi = {3, 5, 50, 0.9};

unsigned char* img;
unsigned char* viewimg;
volatile unsigned int imgindex=0;
volatile int step = 4;
volatile int profile[640];

int savesystemdata(void)
{
  FILE *fp;

  fp = fopen("/mnt/system/system.dat", "w");
  if(fp == NULL)
    return -1;

  fwrite(&camparam, 1, sizeof(CAMPARAM), fp);
  fwrite(&foi, 1, sizeof(FOI), fp);
  fwrite(&hsi, 1, sizeof(HSI), fp);
  fwrite(&step, 1, sizeof(step), fp);

  fclose(fp);
  return 0;
}

int loadsystemdata(void)
{
  FILE *fp;

  fp = fopen("/mnt/system/system.dat", "r");
  if(fp == NULL)
    return -1;

  fread(&camparam, 1, sizeof(CAMPARAM), fp);
  fread(&foi, 1, sizeof(FOI), fp);
  fread(&hsi, 1, sizeof(HSI), fp);
  fread(&step, 1, sizeof(step), fp);

  fclose(fp);
  return 0;
}

void getCamParam(void)
{
  dc1394_get_video_framerate(handle, camera.node, &camparam.framerate);
  dc1394_get_video_mode(handle, camera.node,&camparam.mode);
  dc1394_get_video_format(handle, camera.node,&camparam.format);
  dc1394_get_iso_channel_and_speed(handle, camera.node,&camparam.channel, &camparam.speed);
  dc1394_get_iso_status(handle, camera.node, &camparam.is_on);
  dc1394_get_brightness(handle, camera.node, &camparam.brightness);
  dc1394_get_exposure(handle, camera.node, &camparam.exposure);
  dc1394_get_sharpness(handle, camera.node, &camparam.sharpness);
  dc1394_get_white_balance(handle, camera.node, &camparam.u_b_value, &camparam.v_r_value);
  dc1394_get_hue(handle, camera.node, &camparam.hue);
  dc1394_get_saturation(handle, camera.node, &camparam.saturation);
  dc1394_get_gamma(handle, camera.node, &camparam.gamma);
  dc1394_get_shutter(handle, camera.node, &camparam.shutter);
  dc1394_get_gain(handle, camera.node, &camparam.gain);
  dc1394_get_iris(handle, camera.node, &camparam.iris);
  dc1394_get_focus(handle, camera.node, &camparam.focus);
  dc1394_get_trigger_mode(handle, camera.node, &camparam.trigger_mode);
  dc1394_get_zoom(handle, camera.node, &camparam.zoom);
  dc1394_get_optical_filter(handle, camera.node, &camparam.optical_filter);
}
  
void setCamParam(void)
{
  dc1394_set_brightness(handle, camera.node,  camparam.brightness);
  dc1394_set_exposure(handle, camera.node,  camparam.exposure);
  dc1394_set_sharpness(handle, camera.node,  camparam.sharpness);
  dc1394_set_white_balance(handle, camera.node,  camparam.u_b_value,  camparam.v_r_value);
  dc1394_set_hue(handle, camera.node,  camparam.hue);
  dc1394_set_saturation(handle, camera.node,  camparam.saturation);
  dc1394_set_gamma(handle, camera.node,  camparam.gamma);
  dc1394_set_shutter(handle, camera.node,  camparam.shutter);
  dc1394_set_gain(handle, camera.node,  camparam.gain);
  dc1394_set_iris(handle, camera.node,  camparam.iris);
  dc1394_set_focus(handle, camera.node,  camparam.focus);
  dc1394_set_trigger_mode(handle, camera.node,  camparam.trigger_mode);
  dc1394_set_zoom(handle, camera.node,  camparam.zoom);
  dc1394_set_optical_filter(handle, camera.node,  camparam.optical_filter);
}

void saveTempImage(void)
{
  int x, y;
  
  if(imgindex == 0)
    memcpy(viewimg, &img[9*(640*480)], (640*480));
  else
    memcpy(viewimg, &img[(imgindex-1)*(640*480)], (640*480));

  for(x=foi.left;x<foi.right;x++)
  {
    viewimg[(foi.top*640)+(x)]   = 0xFF;
//    viewimg[(foi.top*640*3)+(x*3)]   = 0xFF;
//    viewimg[(foi.top*640*3)+(x*3)+1] = 0x00;
//    viewimg[(foi.top*640*3)+(x*3)+2] = 0x00;
    viewimg[(foi.bottom*640)+(x)]   = 0xFF;
//    viewimg[(foi.bottom*640*3)+(x*3)]   = 0xFF;
//    viewimg[(foi.bottom*640*3)+(x*3)+1] = 0x00;
//    viewimg[(foi.bottom*640*3)+(x*3)+2] = 0x00;
  }
  for(y=foi.top;y<foi.bottom;y++)
  {
    viewimg[(y*640)+(foi.left)]   = 0xFF;
//    viewimg[(y*640*3)+(foi.left*3)]   = 0xFF;
//    viewimg[(y*640*3)+(foi.left*3)+1] = 0x00;
//    viewimg[(y*640*3)+(foi.left*3)+2] = 0x00;
    viewimg[(y*640)+(foi.right)]   = 0xFF;
//    viewimg[(y*640*3)+(foi.right*3)]   = 0xFF;
//    viewimg[(y*640*3)+(foi.right*3)+1] = 0x00;
//    viewimg[(y*640*3)+(foi.right*3)+2] = 0x00;
  }

//  SaveDIB("/web/cam.bmp", viewimg, 640, 480);
  SaveGreyDIB("/web/cam.bmp", viewimg, 640, 480);
}

void convertimage(dc1394_cameracapture *camera)
{
  static const int CV1 = 358; // V1 = 1.140 * 256 * 157 / 128;
  static const int CV2 = 182; // V2 = 0.581 * 256 * 157 / 128;
  static const int CU1 =  88; // U1 = 0.394 * 256 * 112 / 128;
  static const int CU2 = 454; // U2 = 2.028 * 256 * 112 / 128;
  static const int rgbmin = 0;   //
  static const int rgbmax = 0xFF00; //
  unsigned int* m_ISOMemAkt;
  int x,y;
  int Ya,Y2a,Ua,Va;
  int r,g,b;
  int rb,gb,bb;
  unsigned char *imgdata = &img[imgindex*(640*480*3)];
  m_ISOMemAkt = (unsigned int*)camera->capture_buffer;

  for(y=foi.top;y<foi.bottom;y++)
  {
    x=0;
    while(x<640)
    {
      Y2a = (*m_ISOMemAkt>>24)&0xFF;
      Ua = (*m_ISOMemAkt>>16)&0xFF;
      Ya = (*m_ISOMemAkt>>8)&0xFF;
      Va = (*m_ISOMemAkt)&0xFF;

      Y2a = Y2a * 256;
      Ya = Ya * 256;
      Va -= 128;
      Ua -= 128;

      r = Ya + CV1*Va;
      if(r<rgbmin) r=rgbmin;
      if(r>rgbmax) r=rgbmax;

      g = Ya - CU1*Ua - CV2*Va;
      if(g<rgbmin) g=rgbmin;
      if(g>rgbmax) g=rgbmax;

      b = Ya + CU2*Ua;
      if(b<rgbmin) b=rgbmin;
      if(b>rgbmax) b=rgbmax;

      bb = (b>>8)&0x00FF;
      gb = (g>>8)&0x00FF;
      rb = (r>>8)&0x00FF;

      imgdata[(y*640*3)+(x*3)] = rb;
      imgdata[(y*640*3)+(x*3)+1] = gb;
      imgdata[(y*640*3)+(x*3)+2] = bb;
      x++;
      r = Y2a + CV1*Va;
      if(r<rgbmin) r=rgbmin;
      if(r>rgbmax) r=rgbmax;

      g = Y2a - CU1*Ua - CV2*Va;
      if(g<rgbmin) g=rgbmin;
      if(g>rgbmax) g=rgbmax;

      b = Y2a + CU2*Ua;
      if(b<rgbmin) b=rgbmin;
      if(b>rgbmax) b=rgbmax;

      bb = (b>>8)&0x00FF;
      gb = (g>>8)&0x00FF;
      rb = (r>>8)&0x00FF;

      imgdata[(y*640*3)+(x*3)] = rb;
      imgdata[(y*640*3)+(x*3)+1] = gb;
      imgdata[(y*640*3)+(x*3)+2] = bb;
      m_ISOMemAkt++;
      x++;
    }
  }
}


void Threshold(void)
{
  int x, y, hit=0;
  float h,s,i,rh,gh,bh,min,tmp, tmp2;
  unsigned char *imgdata = &img[imgindex*(640*480*3)];
  int pindex = 1;
  for(x=foi.left;x<foi.right;x+=step)
  {
    hit = 0;
    y = foi.top;
    while(y < foi.bottom)
    {
      rh = imgdata[(y*640*3)+(x*3)];
      gh = imgdata[(y*640*3)+(x*3)+1];
      bh = imgdata[(y*640*3)+(x*3)+2];

      if(rh<gh)min=(rh<bh)?rh:bh; else min=(gh<bh)?gh:bh;

      if((i = (rh+gh+bh)/3.0)==0.0)
      {
        h=s=0.0;
      }
      else
      {
        if((s = 1.0-(min/i))<=1e-6)
          h=s=0.0;
        else
        {
          tmp2 = sqrt( (double)((rh-gh)*(rh-gh) + (rh-bh)*(gh-bh)) );
          if(tmp2>0)
            tmp= 0.5 * (float)(rh-gh + rh-bh) / tmp2;
          else
            tmp = 0;
          if(tmp>=1.0)
            h=0.0;
          else
            h=acos(tmp);
        }
        if(bh>gh)
          h=2*M_PI-h;
      }
      if((h > hsi.h_min && h < hsi.h_max) && i > hsi.i && s > hsi.s)
      {
        profile[pindex] = y;
        imgdata[(y*640*3)+(x*3)]   = 0x00;
        imgdata[(y*640*3)+(x*3)+1] = 0xff;
        imgdata[(y*640*3)+(x*3)+2] = 0x00;
        y=foi.bottom;
      }
      else
      {
        imgdata[(y*640*3)+(x*3)]   = 0xff;
        imgdata[(y*640*3)+(x*3)+1] = 0xff;
        imgdata[(y*640*3)+(x*3)+2] = 0xff;
        profile[pindex] = y;
      }
      y++;
    }
    pindex++;
  }
  profile[0] = pindex;
}

void ThresholdGrey(void)
{
  int x, y, hit=0;
  float rh;
  unsigned char *imgdata = &img[imgindex*(640*480)];
  int pindex = 1;

  memcpy(imgdata, camera.capture_buffer, (640*480));

  for(x=foi.left;x<foi.right;x+=step)
  {
    hit = 0;
    y = foi.top;
    while(y < foi.bottom)
    {
      rh = imgdata[(y*640)+(x)];

      if(rh > hsi.i)
      {
        profile[pindex] = y;
        imgdata[(y*640)+(x)] = 0xFF;
        y=foi.bottom;
      }
      else
      {
        imgdata[(y*640)+(x)] = 0xFF;
        profile[pindex] = y;
      }
      y++;
    }
    pindex++;
  }
  profile[0] = pindex;
}

void *cammain(void *arguments)
{
  int i, j=1;
  int numNodes;
  int numCameras;
  nodeid_t * camera_nodes;
  dc1394_camerainfo info;
  dc1394bool_t value;
  int node_index;
  time_t starttid;
  time_t tmptid;


  pthread_cond_init(&profil_cond, 0);
  
//  img = (unsigned char*)malloc(640*480*3*10);
  img = (unsigned char*)malloc(640*480*10);
//  viewimg = (unsigned char*)malloc(640*480*3);
  viewimg = (unsigned char*)malloc(640*480);

  /*-----------------------------------------------------------------------
   *  Open ohci and asign handle to it
   *-----------------------------------------------------------------------*/
  handle = dc1394_create_handle(0);
  if (handle==NULL)
  {
    fprintf( stderr, "Unable to aquire a raw1394 handle\n"
             "did you insmod the drivers?\n");
    fflush(stdout);
    exit(1);
  }

  numNodes = raw1394_get_nodecount(handle);
  camera_nodes = dc1394_get_camera_nodes(handle,&numCameras,0);
  fflush(stdout);
  if (numCameras<1)
  {
    fprintf( stderr, "no cameras found :(\n");
    fflush(stdout);
    raw1394_destroy_handle(handle);
  }
  else
  {
    for(i=0;i<numCameras;i++)
    {
      dc1394_is_camera(handle, camera_nodes[i], &value);
      if(value==DC1394_TRUE)
      {
        dc1394_get_camera_info(handle, camera_nodes[i], &info);
      }
    }
    node_index = 0;

    /*-----------------------------------------------------------------------
     *  to prevent the iso-transfer bug from raw1394 system, check if
     *  camera is highest node. For details see
     *  http://linux1394.sourceforge.net/faq.html#DCbusmgmt
     *  and
     *  http://sourceforge.net/tracker/index.php?func=detail&aid=435107&group_id=8157&atid=108157
     *-----------------------------------------------------------------------*/

    if( camera_nodes[node_index] == numNodes-1)
    {
      fprintf( stderr, "\n"
             "Sorry, your camera is the highest numbered node\n"
             "of the bus, and has therefore become the root node.\n"
             "The root node is responsible for maintaining \n"
             "the timing of isochronous transactions on the IEEE \n"
             "1394 bus.  However, if the root node is not cycle master \n"
             "capable (it doesn't have to be), then isochronous \n"
             "transactions will not work.  The host controller card is \n"
             "cycle master capable, however, most cameras are not.\n"
             "\n"
             "The quick solution is to add the parameter \n"
             "attempt_root=1 when loading the OHCI driver as a \n"
             "module.  So please do (as root):\n"
             "\n"
             "   rmmod ohci1394\n"
             "   insmod ohci1394 attempt_root=1\n"
             "\n"
             "for more information see the FAQ at \n"
             "http://linux1394.sourceforge.net/faq.html#DCbusmgmt\n"
             "\n");
       fflush(stdout);
       exit(1);
    }

    fprintf(stderr, "Found camera : %d\n", numCameras);
    fflush(stdout);

    dc1394_init_camera(handle, camera_nodes[node_index]);

    if( dc1394_dma_setup_capture(handle, camera_nodes[node_index],
                       0,
                       FORMAT_VGA_NONCOMPRESSED,
//                       MODE_640x480_YUV422,
                       MODE_640x480_MONO,
//                       MODE_640x480_RGB,
                       SPEED_400,
                       FRAMERATE_30,
                       10,
                       1, //#define DROP_FRAMES 1
                       "/dev/video1394/0",
                       &camera) != DC1394_SUCCESS)
      fprintf( stderr,"setup capture error\n");
      fflush(stdout);

   /*-----------------------------------------------------------------------
    *  have the camera start sending us data
    *-----------------------------------------------------------------------*/
    if (dc1394_start_iso_transmission(handle,camera.node)
      !=DC1394_SUCCESS)
    {
      fprintf( stderr, "unable to start camera iso transmission\n");
      fflush(stdout);
      dc1394_dma_release_camera(handle,&camera);
      raw1394_destroy_handle(handle);
      exit(1);
    }

    printf("loading data....");
    if(loadsystemdata()!=0)
    {
      printf("FAILED\n");
      printf("Creating default data.\n");
      getCamParam();      //get default data and save
      savesystemdata();
    }
    printf("DONE\n");

    setCamParam();

    starttid = time(NULL);
    j=0;
    i=0;
    for(;;)
    {
      dc1394_dma_single_capture(&camera);
//      convertimage(&camera);
//      Threshold();
      ThresholdGrey();
      pthread_cond_signal(&profil_cond);
      j++;
      imgindex++;
      if(imgindex >= 10)
        imgindex = 0;
      caminfo.frames++;
      dc1394_dma_done_with_buffer(&camera);
      tmptid = time(NULL);
      if(tmptid-starttid >= 1)
      {
        caminfo.droped = 30-j;
        caminfo.dropedTotal += caminfo.droped;
        j=0;
        starttid = tmptid;
      }
    }

    if (dc1394_stop_iso_transmission(handle,camera.node)
      !=DC1394_SUCCESS)
    {
      fprintf( stderr, "unable to stop camera iso transmission\n");
      fflush(stdout);
      dc1394_dma_release_camera(handle,&camera);
      raw1394_destroy_handle(handle);
      exit(1);
    }
    dc1394_dma_release_camera(handle,&camera);
    raw1394_destroy_handle(handle);
  }

  free(img);
  free(viewimg);
  return EXIT_SUCCESS;
}
