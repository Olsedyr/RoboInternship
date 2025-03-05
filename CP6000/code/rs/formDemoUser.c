//Copyright (C) 2005 by MPN A/S - Guided by vision(R)
// formDemoUser.c
#include "rs.h"
#include "Bx.h"
#include "formDemo.h"
#include "formCP.h"
#include "formCW.h"
#include "formStdRun.h"
#include "cmd.h"

BX_BOOL formDemoUserInit(HBOX hBox,BX_LPARAM lParam)
{
  return TRUE;
}

BX_BOOL formDemoUserUpdate(HBOX hBox)
{
  return TRUE;
}

BX_BOOL formDemo_cmdRS_Click(HBOX hBox)
{
  FILE *fp;
  char filename[256];
  sprintf(filename,"mntdatabase.txt");
  if((fp = fopen(filename, "w"))==NULL)
  {
    printf("mntdatabase.txt: Save failed %s\n",filename);
    return FALSE;
  }
  fprintf(fp,"%s\n",rs_systempath);
  fprintf(fp,"605system.ini\n");
  fprintf(fp,"322system.ini\n");
  fclose(fp);
  mpnexit(9);
  return TRUE;
}

BX_BOOL formDemo_cmdCP_Click(HBOX hBox)
{
  FILE *fp;
  char filename[256];
  sprintf(filename,"mntdatabase.txt");
  if((fp = fopen(filename, "w"))==NULL)
  {
    printf("mntdatabase.txt: Save failed %s\n",filename);
    return FALSE;
  }
  fprintf(fp,"%s\n",rs_systempath);
  fprintf(fp,"605system.ini\n");
  fprintf(fp,"708system.ini\n");
  fclose(fp);
  mpnexit(9);
  return TRUE;
}

BX_BOOL formDemo_cmdCW_Click(HBOX hBox)
{
  FILE *fp;
  char filename[256];
  sprintf(filename,"mntdatabase.txt");
  if((fp = fopen(filename, "w"))==NULL)
  {
    printf("mntdatabase.txt: Save failed %s\n",filename);
    return FALSE;
  }
  fprintf(fp,"%s\n",rs_systempath);
  fprintf(fp,"605system.ini\n");
  fprintf(fp,"509system.ini\n");
  fclose(fp);
  mpnexit(9);
  return TRUE;
}

BX_BOOL formDemo_cmdCM_Click(HBOX hBox)
{
  FILE *fp;
  char filename[256];
  sprintf(filename,"mntdatabase.txt");
  if((fp = fopen(filename, "w"))==NULL)
  {
    printf("mntdatabase.txt: Save failed %s\n",filename);
    return FALSE;
  }
  fprintf(fp,"%s\n",rs_systempath);
  fprintf(fp,"605system.ini\n");
  fprintf(fp,"803system.ini\n");
  fclose(fp);
  mpnexit(9);
  return TRUE;
}

//used by formStdRun, formCP, formCW and formCM
BX_BOOL formDemo_cmdDemoClose_Click(HBOX hBox)
{
  FILE *fp;
  char filename[256];
  sprintf(filename,"mntdatabase.txt");
  if((fp = fopen(filename, "w"))==NULL)
  {
    printf("mntdatabase.txt: Save failed %s\n",filename);
    return FALSE;
  }
  fprintf(fp,"%s\n",rs_systempath);
  fprintf(fp,"605system.ini\n");
  fclose(fp);
  mpnexit(9);
  return TRUE;
}
