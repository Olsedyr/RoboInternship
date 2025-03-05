
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

void *webmain(void * argument );
void *cammain(void * argument );
void *servermain(void *arguments);

/*********************************** Code *************************************/
/*
 *  Main -- entry point from LINUX
 */

int main(int argc, char** argv)
{
  pthread_attr_t attr;
  struct sched_param sched_param;
  int ret;
  pthread_t web_task, cam_task, svr_task;

  pthread_attr_init(&attr);
  sched_param.sched_priority = 0;
  pthread_attr_setschedparam (&attr, &sched_param);

  ret = pthread_create(&web_task, &attr, webmain, NULL);
  pthread_setschedparam (web_task, SCHED_RR, &sched_param);

  pthread_attr_init(&attr);
  sched_param.sched_priority = 2;
  pthread_attr_setschedparam (&attr, &sched_param);

  ret = pthread_create(&svr_task, &attr, servermain, NULL);
  pthread_setschedparam (svr_task, SCHED_RR, &sched_param);

  sched_param.sched_priority = 5;
  pthread_attr_setschedparam (&attr, &sched_param);

  ret = pthread_create(&cam_task, &attr, cammain, NULL);
  pthread_setschedparam (cam_task, SCHED_RR, &sched_param);

  pthread_join(web_task, NULL); // Vent paa web tasket stopper
  return 0;
}
