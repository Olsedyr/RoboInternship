#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFLEN 512
#define NPACK 10
#define PORT 9930

void diep(char *s)
{
  perror(s);
  exit(1);
}

int main(void)
{
	int rlen;
	char *formatstr="hej spasser, giv mig en value %s";
  struct sockaddr_in si_me, si_other;
  int s, i, slen=sizeof(si_other);
  char buf[BUFLEN];
	char sendbuf[BUFLEN];
	char sendbuf2[BUFLEN];
	char tempbuf1[BUFLEN];
	char tempbuf2[BUFLEN];
	sprintf(sendbuf,"Tak for beskeden\n");
	sprintf(sendbuf2,"Broadcast!!\n");
  if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    diep("socket");

  memset((char *) &si_me, sizeof(si_me), 0);
  si_me.sin_family = AF_INET;
  si_me.sin_port = htons(PORT);
  si_me.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(s, (struct sockaddr *)&si_me, sizeof(si_me))==-1)
      diep("bind");
	
  for (;;) 
	{
		rlen=recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen);
    if (rlen==-1)
      diep("recvfrom()");
		buf[rlen]='\0';
    printf("Received packet from %s:%d\nData: %s\n\n", 
           inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
		if (sscanf(buf,formatstr,tempbuf1)==1) 
		{
			sprintf(tempbuf2,"Din value %s er %i\n",tempbuf1,42);
			sendto(s,tempbuf2,strlen(tempbuf2)+1,0,(struct sockaddr *)&si_other,slen);
		}
		else
		{
			sendto(s,sendbuf,strlen(sendbuf)+1,0,(struct sockaddr *)&si_other,slen);
		}
		
  }
	
  close(s);
  return 0;
	
}
