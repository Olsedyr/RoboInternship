#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termio.h>
#include <fcntl.h>
#include <termios.h>
#include <pthread.h>
#include "Bx.h"

#include <linux/kd.h>

static struct termio ttysave;
struct termio tty;

BX_VOID BxSetEvent(BX_VOID);
BX_BOOL BxInsertKeyboardEvent(BX_WORD state, BX_WORD scan_code);
BX_BOOL kbdDone;

void restore( struct termio* tty_save )
{
	if( ioctl(0, TCSETAF, tty_save) == -1 )
	{
		perror("ioctl");
		exit(5);
	}
	ioctl(0, KDSETMODE, KD_TEXT);
	return;
}

void init_kbd(void)
{
	int flag=1;

	if( flag )
	{
		flag = 0;
		if( ioctl( 0, TCGETA, &tty) == -1 )
		{
			perror("ioctl");
			exit(1);
		}
		ttysave = tty;
		tty.c_lflag &= ~(ICANON | ECHO | ISIG ) ;
		tty.c_cc[VMIN] =1;
		tty.c_cc[VTIME] =0;
		if( ioctl(0, TCSETAF, &tty ) == -1 )
		{
			restore(&ttysave);
			perror("ioctl");
			exit(2);
		}

	}
	ioctl(0, KDSETMODE, KD_GRAPHICS);
}

char getch(int wait)
{
	char c=0;
	int total;
	struct termio tmptty;

	if(!wait)
	{
		ioctl( 0, TCGETA, &tmptty);
		tmptty.c_lflag |= O_NDELAY;
		tmptty.c_cc[VMIN] =0;
		tmptty.c_cc[VTIME] =0;
		if( ioctl( 0, TCSETA, &tmptty) == -1)
		{
			restore(&ttysave);
			perror("ioctl");
			exit(2);
		}
	}

	switch( total = read( 0, &c, 1 ))
	{
		case -1:
			restore(&ttysave);
			perror("read");
			exit(3);
		case 0:
			if(wait)
			{
				restore(&ttysave);
				fputs("EOF error!", stderr );
				exit(4);
			}
		default:
			;
	}

	if(!wait)
	{

		tmptty.c_lflag &= ~O_NDELAY;
		tmptty.c_cc[VMIN] =1;
		tmptty.c_cc[VTIME] =0;
		if( ioctl( 0, TCSETA, &tmptty) == -1)
		{
			restore(&ttysave);
			perror("ioctl");
			exit(2);
		}
	}

	return c;
}

void *KbdTask(void* arg)
{
	int c;
	char ch;

	kbdDone = FALSE;

	init_kbd();

	while(!kbdDone)
	{
		c = -1;
		ch = getch(TRUE);
		//printf("%X\n", ch);
		switch(ch){
			case 0x1B:
				ch = getch(FALSE);
				//printf(" %X\n", ch);
				switch(ch){
					case 0x00:
						c=27;
						break;
					case 0x5B:
						ch = getch(FALSE);
						//printf(" %X\n", ch);
						switch(ch) {
							case 0x41:
								c=147;
								break;
							case 0x42:
								c=141;
								break;
							case 0x43:
								c=145;
								break;
							case 0x44:
								c=143;
								break;
						}
						break;

				}
				break;
			case 0x09: // TAB
				c=9;
				break;
			case 0x0A: // ENTER
				c=13;
				break;
			case 0x3: // Ctrl-C
				kbdDone = TRUE;
				break;

		}

		if(c!=-1)
		{
			BxInsertKeyboardEvent(1, c);
			BxSetEvent(); 
		}
		//printf(" \n");
	}
	restore(&ttysave);
  exit(0);
  return NULL;
}
