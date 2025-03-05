/****************************************************************************
* Copyright (C) 2005 by MPN A/S - Guided by vision(R) Thomas Noerby         *
* All rights reserved.                                                      *
*****************************************************************************/
#include "logger.h"
#include <stdio.h>
#include <time.h>
#include <cmd.h>

#define MAXLOG 100

int logMsg(char *s)
{
  FILE *fp;
  char logBuffer[MAXLOG][256];
  char logTime[32];
  int j,i=1;
  char filename[256];
  
  time_t t;

  sprintf(filename,"%s/system/rs.log",rs_systempath);
  
  time(&t);
  strftime(logTime, 25, "%T %D", localtime(&t));

  sprintf(logBuffer[0], "%s %s\n", logTime, s); 

  fp = fopen(filename, "r");
  
  if(fp!=NULL)
  {
    while(!feof(fp) && i < MAXLOG)
    {
      if(fgets(logBuffer[i], 255, fp)!=NULL)
        i++;
    }
  
    fclose(fp);
  }
  
  fp = fopen(filename, "w");
  
  if(fp!=NULL)
  {
    for(j=0;j<i;j++)
      fprintf(fp,"%s", logBuffer[j]);
  
    fclose(fp);
  }
  return 0;
}

int logStatus(char *s)
{
  FILE *fp;
  char logBuffer[256];
  char logTime[32];
  char filename[256];
  
  time_t t;

  time(&t);
  
  strftime(logTime, 25, "%y", localtime(&t));

  sprintf(filename,"%s/stat/status%s.log",rs_systempath, logTime);
  
  strftime(logTime, 25, "%D,%T", localtime(&t));

  sprintf(logBuffer, "%s,%s\n", logTime,s); 

  fp = fopen(filename, "a");
  
  if(fp!=NULL)
  {
    fprintf(fp,"%s", logBuffer);
  
    fclose(fp);
  }
  return 0;
}

