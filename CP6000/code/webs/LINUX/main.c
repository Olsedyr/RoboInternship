
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *webmain(void * argument );

/*********************************** Code *************************************/
/*
 *  Main -- entry point from LINUX
 */

int main(int argc, char** argv)
{
/*
  pthread_attr_t attr;
  struct sched_param sched_param;
  int ret;
  pthread_t web_task;

  pthread_attr_init(&attr);
  sched_param.sched_priority = 5;
  pthread_attr_setschedparam (&attr, &sched_param);

  ret = pthread_create(&web_task, &attr, webmain, NULL);

  pthread_join(web_task, NULL); // Vent paa web tasket stopper
*/

  webmain(NULL);
  
  return 0;
}
