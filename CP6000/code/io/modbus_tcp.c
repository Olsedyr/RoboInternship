/***************************************************************************
                          modbus_tcp.c  -  description
                             -------------------
    begin                : fre okt 31 2003
    copyright            : (C) 2003 by Lars M Sandig
    email                : lms@mpn-lms
 ***************************************************************************/

#include <pthread.h>

#include <fcntl.h>    /* File control definitions */
#include <stdio.h>    /* Standard input/output */
#include <stdlib.h>
#include <string.h>
#include <termio.h>   /* POSIX terminal control definitions */
#include <sys/time.h> /* Time structures for select() */
#include <unistd.h>   /* POSIX Symbolic Constants */
#include <errno.h>    /* Error definitions */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "cmd.h"
#include "modbus_tcp.h"

#define WAITSEC  1
#define WAITMSEC 0

typedef struct mbtcptab_struct
{
	int sfd;
	char ip_addr[20];
	pthread_mutex_t mbtcp_mutex;
	struct sockaddr_in server;
} mbtcptab_struct;

#define MAXMBTCPCONNECTIONS 10
mbtcptab_struct mbtcptab[MAXMBTCPCONNECTIONS];
static int mbtcpconnectioncount=0;
volatile int mid=0;
//pthread_mutex_t mbtcp_mutex = PTHREAD_MUTEX_INITIALIZER;
//#define DEBUG     /* uncomment to see the data sent and received */

/***********************************************************************

   send_query( file_descriptor, query_string, query_length )

Function to send a query out to a modbus slave.
************************************************************************/
int recvcnt=0;
//SFD
volatile int qid=1;
int send_query( int sfd, unsigned char *query, size_t string_length )
{
  int write_stat,retselect;

#ifdef DEBUG
  int i;
#endif
  int max_fds = sfd+1;
  struct timeval tv;
  fd_set wfds;

  tv.tv_sec = WAITSEC;
  tv.tv_usec = WAITMSEC;
  FD_ZERO( &wfds );
  FD_SET( sfd, &wfds );
  /* wait for a response */
  retselect = select( max_fds, NULL, &wfds, NULL, &tv );
//  printf("send retselect=%d\n",retselect);
  if( retselect<=0 )
  {
    tcflush( sfd, TCIOFLUSH );	/* flush the input & output streams */
    printf("retselect=%d\n",retselect);
    return 0;
  }
  query[0]=qid++;  
#ifdef DEBUG
/* Print to stderr the hex value of each character that is about to be */
/* sent to the modbus slave.       */

  fprintf( stderr, "S#%03d",string_length);
  for( i = 0; i < string_length; i++ )
  {
    fprintf( stderr, "[%2X]", query[ i ] );
  }
  fprintf( stderr, "\n" );
#endif

//  start = times(NULL);
//  tcflush( sfd, TCIOFLUSH );	/* flush the input & output streams */
  write_stat = send( sfd, query, string_length, 0  );
  if(write_stat!=string_length)
    printf("send write_stat=%d (%d)\n",write_stat,string_length);
//  tcflush( sfd, TCIFLUSH );	/* maybe not neccesary */
//  stop = times(NULL);
//  printf("send execute in %f\n",(float)(stop-start)/(float)sysconf(_SC_CLK_TCK));

  return( write_stat );
}

/*********************************************************************

  modbus_response( response_data_array, query_array )

   Function to the correct response is returned and check for correctness.

   Returns:	string_length if OK
    0 if failed
    Less than 0 for exception errors

  Note: All functions used for sending or receiving data via
        modbus return these return values.

**********************************************************************/
//SFD
int modbus_response( unsigned char *data, unsigned char *query, int sfd )
{
  int response_length;

  /* local declaration */
  int receive_response( unsigned char *received_string, int sfd );

  response_length = receive_response( data, sfd );
  if( response_length > 0 )
  {

    /********** check for exception response *****/

    if(( response_length && data[ 7 ] != query [ 7 ]) && (rs_param.io_debug>=3))
    {
      /* return the exception value as a -ve number */
      response_length = 0 - data[ 8 ];
      printf("data = %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n"
      ,data[0]
      ,data[1]
      ,data[2]
      ,data[3]
      ,data[4]
      ,data[5]
      ,data[6]
      ,data[7]
      ,data[8]
      ,data[9]
      ,data[10]
      ,data[11]
      ,data[12]
      ,data[13]);
      printf("query= %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n"
      ,query[0]
      ,query[1]
      ,query[2]
      ,query[3]
      ,query[4]
      ,query[5]
      ,query[6]
      ,query[7]
      ,query[8]
      ,query[9]
      ,query[10]
      ,query[11]
      ,query[12]
      ,query[13]);
    }
  }
  else
  {
    printf("response_length=%d\n",response_length);
  }

  return( response_length );
}

void clear_buffer(int sfd)
{
  int retselect;
  int rxchar = -1;
  int data_avail = FALSE;
  int read_stat;
  int max_fds = sfd+1;
  fd_set rfds;
  struct timeval tv;
  return;
#ifdef DEBUG
  fprintf( stderr, "eat loose stuff.\n");
#endif
  /* wait for a response */
  data_avail = TRUE;
  while( data_avail )
  {
    /* if no character at the buffer wait char_interval_timeout */
    /* before accepting end of response			    */
  tv.tv_sec = WAITSEC;
  tv.tv_usec = WAITMSEC;
  //  tv.tv_sec = 10;
  //  tv.tv_usec = 0;
    FD_ZERO( &rfds );
    FD_SET( sfd, &rfds );
    retselect=select( max_fds, &rfds, NULL, NULL, &tv);
    if( retselect > 0 )
    {
      read_stat = recv( sfd, &rxchar, 1, 0);
      rxchar = rxchar & 0xFF;
#ifdef DEBUG
      /* display the hex code of each character received */
      fprintf( stderr, "<%0.2X>", rxchar );
#endif
    }
    else
    {
      data_avail = FALSE;
    }
  }
#ifdef DEBUG
  fprintf( stderr, "\n" );
#endif
}
/***********************************************************************

  receive_response( array_for_data )

   Function to monitor for the reply from the modbus slave.
   This function blocks for timeout seconds if there is no reply.

   Returns:	Total number of characters received.
***********************************************************************/
//SFD
int receive_response(  unsigned char *received_string, int sfd )
{
  int retselect,bytes_received_idx;
  int bytes_received = 0;
  int max_fds = sfd+1;
  fd_set rfds;
  struct timeval tv;

  tv.tv_sec = WAITSEC;
  tv.tv_usec = WAITMSEC;
  //tv.tv_sec = 10;
  //tv.tv_usec = 0;
  FD_ZERO( &rfds );
  FD_SET( sfd, &rfds );
  /* wait for a response */
  retselect = select( max_fds, &rfds, NULL, NULL, &tv );
  if( retselect<=0 )
  {
    printf("no response within 1 sec. program halted!\n");
//    exit(1);
  }
  bytes_received=0;
  bytes_received_idx=0;

  while( retselect>0)
  {
		//    printf("isset=%d\n",FD_ISSET (sfd, &rfds));
    bytes_received = read( sfd, &received_string[bytes_received_idx], 6+received_string[5]-bytes_received_idx);
    if( bytes_received < 0 )
    {
      printf("SOCKET_FAILURE in read\n"); 
      bytes_received = SOCKET_FAILURE;
    }
    else
    {
#ifdef DEBUG
      fprintf( stderr, "R#%03d)",bytes_received);
      for( i = 0; i < bytes_received; i++ )
      {
        fprintf( stderr, "[%2X]", received_string[ bytes_received_idx+i ] );
      }
      fprintf( stderr, "\n" );
#endif
      bytes_received_idx+=bytes_received;
    }
    if(bytes_received_idx<6||bytes_received_idx<received_string[5]+6)
    {
			tv.tv_sec = WAITSEC;
			tv.tv_usec = WAITMSEC;
			//    tv.tv_sec = 10;
			//    tv.tv_usec = 0;
      FD_ZERO( &rfds );
      FD_SET( sfd, &rfds );
      retselect=select( max_fds, &rfds, NULL, NULL, &tv);
      if(retselect<=0)
      {
        printf("retselect=%d %d\n",retselect,errno);
        printf("no response within 1 sec. program halted !\n");
        return(0);
  //    exit(1);
      }
    }
    else
    {
//    printf("recv ended %d %d\n",bytes_received_idx,received_string[5]);
      retselect=0;
    }
    
  }
  if( bytes_received_idx > 7 )
  {
    bytes_received_idx -= 7;
  }

  return( bytes_received_idx );
}

/***********************************************************************

  The following functions construct the required query into
  a modbus query packet.

***********************************************************************/

#define REQUEST_QUERY_SIZE 12         /* the following packets require          */
#define CHECKSUM_SIZE 2               /* 6 unsigned chars for the packet plus   */
                                      /* 2 for the checksum.                    */

void build_request_packet( int slave, int function, int start_addr,
         int count, unsigned char *packet )
{
  int i;


  for( i = 0; i < 5 ; i++ ) packet[ i ] = 0;

  packet[ i++ ] = 6;
  packet[ i++ ] = slave;
  packet[ i++ ] = function;
  start_addr -= 1;
  packet[ i++ ] = start_addr >> 8;
  packet[ i++ ] = start_addr & 0x00ff;
  packet[ i++ ] = count >> 8;
  packet[ i ] = count &0x00ff;

}

/************************************************************************

  read_IO_status

  read_coil_stat_query and read_coil_stat_response interigate
  a modbus slave to get coil status. An array of coils shall be
  set to TRUE or FALSE according to the response from the slave.

*************************************************************************/
//SFD
int read_IO_status( int function, int slave, int start_addr, int count,
          int *dest, int dest_size, int sfd )
{
  /* local declaration */
  int read_IO_stat_response( int *dest, int dest_size, int coil_count,
          unsigned char *query, int sfd );

  int status;

  unsigned char packet[ REQUEST_QUERY_SIZE + CHECKSUM_SIZE ];
  build_request_packet( slave, function, start_addr, count, packet );

  //printf("read_IO_status\n");
  if( send_query( sfd, packet, REQUEST_QUERY_SIZE ) > -1 )
  {
    status = read_IO_stat_response( dest, dest_size,
            count, packet, sfd );
  }
  else
  {
    status = SOCKET_FAILURE;
  }

  return( status );
}



/************************************************************************

  read_coil_status_tcp

  reads the boolean status of coils and sets the array elements
  in the destination to TRUE or FALSE

*************************************************************************/
//SFD
int read_coil_status_tcp( int slave, int start_addr, int count,
        int *dest, int dest_size, int fdidx )
{
  int function = 0x01;
  int status;

  status = read_IO_status( function, slave, start_addr, count,
            dest, dest_size, mbtcptab[fdidx].sfd );

	return( status );
}





/************************************************************************

  read_input_status_tcp

  same as read_coil_status but reads the slaves input table.

************************************************************************/
//SFD
int read_input_status_tcp( int slave, int start_addr, int count,
        int *dest, int dest_size, int fdidx )
{
  int function = 0x02;	/* Function: Read Input Status */
  int status;

  status = read_IO_status( function, slave, start_addr, count,
              dest, dest_size, mbtcptab[fdidx].sfd );

  return( status );
}

/**************************************************************************

  read_IO_stat_response

  this function does the work of setting array elements to TRUE
  or FALSE.

**************************************************************************/
//SFD
int read_IO_stat_response( int *dest, int dest_size, int coil_count,
        unsigned char *query, int sfd )
{

  unsigned char data[ MAX_RESPONSE_LENGTH ];
  int raw_response_length;
  int temp, i, bit, dest_pos = 0;
  int coils_processed = 0;

  raw_response_length = modbus_response( data, query, sfd );


  if( raw_response_length > 0 )
  {
    for( i = 0; i < ( data[8] ) && i < dest_size; i++ )
    {
      /* shift reg hi_byte to temp */
      temp = data[ 9 + i ] ;
      for( bit = 0x01; bit & 0xff &&
      coils_processed < coil_count; )
      {
        if( temp & bit )
        {
          dest[ dest_pos ] = TRUE;
        }
        else
        {
          dest[ dest_pos ] = FALSE;
        }
        coils_processed++;
        dest_pos++;
        bit = bit << 1;
      }
    }
  }

  return( raw_response_length );
}


/************************************************************************

  read_registers

  read the data from a modbus slave and put that data into an array.

************************************************************************/
//SFD
int read_registers( int function, int slave, int start_addr, int count,
        short *dest, int dest_size, int sfd )
{
  int reread = 0, i;
  /* local declaration */
  int read_reg_response( short *dest, int dest_size,
      unsigned char *query, int sfd );

  int status;

  unsigned char packet[ REQUEST_QUERY_SIZE + CHECKSUM_SIZE ];
  build_request_packet( slave, function, start_addr, count, packet );
reread_loop:
  //printf("read_registers\n");
  if( send_query( sfd, packet, REQUEST_QUERY_SIZE ) > -1 )
  {
    status = read_reg_response( dest, dest_size, packet, sfd );
    if(status<=0)
    {
      reread++;
      fprintf( stderr, "status %d reread %d\n", status, reread);
      if(reread < 100000000)
      {
        goto reread_loop;
      }
      else
      {
        for(i=0;i<REQUEST_QUERY_SIZE + CHECKSUM_SIZE;i++)
          fprintf( stderr, "[%.2X]", packet[i]);
        fprintf( stderr, "\n");
      }
    }
  }
  else
  {
    status = SOCKET_FAILURE;
    printf("SOCKET_FAILURE");
  }

  return( status );

}



/************************************************************************

  read_holding_registers


  Read the holding registers in a slave and put the data into
  an array.

*************************************************************************/
//SFD
int read_holding_registers_tcp( int slave, int start_addr, int count,
        short *dest, int dest_size, int fdidx )
{
  int function = 0x03;    /* Function: Read Holding Registers */
  int status;

  if( count > MAX_READ_REGS )
  {
    count = MAX_READ_REGS;
#ifdef DEBUG
    fprintf( stderr, "Too many registers requested.\n" );
#endif
  }

  pthread_mutex_lock(&mbtcptab[fdidx].mbtcp_mutex);
  status = read_registers( function, slave, start_addr, count,
            dest, dest_size, mbtcptab[fdidx].sfd );
  pthread_mutex_unlock(&mbtcptab[fdidx].mbtcp_mutex);

  return( status);
}

/************************************************************************

  read_holding_registers

  Read the holding registers in a slave and put the data into
  an array.

*************************************************************************/
//SFD
int read_holding_registers_tcp_async1( int slave, int start_addr, int count, short *dest, int dest_size, int fdidx )
{
  int function = 0x03;    /* Function: Read Holding Registers */
  int status;
  unsigned char packet[ REQUEST_QUERY_SIZE + CHECKSUM_SIZE ];
  int sfd = mbtcptab[fdidx].sfd;
  build_request_packet( slave, function, start_addr, count, packet );
  if( count > MAX_READ_REGS )
  {
    count = MAX_READ_REGS;
#ifdef DEBUG
    fprintf( stderr, "Too many registers requested.\n" );
#endif
  }
  pthread_mutex_lock(&mbtcptab[fdidx].mbtcp_mutex);
  status = send_query(sfd, packet, REQUEST_QUERY_SIZE);
  return( status);
}
/************************************************************************

	reads the response data from a slave and puts the data into an
	array.

**********************************************************************/
//SFD
int read_holding_registers_tcp_async2( int slave, int start_addr, int count, short *dest, int dest_size, int fdidx )
{

  int function = 0x03;    /* Function: Read Holding Registers */
  unsigned char packet[ REQUEST_QUERY_SIZE + CHECKSUM_SIZE ];
  int sfd = mbtcptab[fdidx].sfd;
	
  unsigned char data[ MAX_RESPONSE_LENGTH ];
	int raw_response_length;
	int response_length;
	int temp,i;
  build_request_packet( slave, function, start_addr, count, packet );
  
  response_length = receive_response( data, sfd );
  if( response_length > 0 )
  {
    /********** check for exception response *****/
    if( response_length && data[ 7 ] != packet [ 7 ] )
    {
      /* return the exception value as a -ve number */
      response_length = 0 - data[ 8 ];
    }
  }
	raw_response_length = response_length;
	if( raw_response_length > 0 ) raw_response_length -= 2;
  if( raw_response_length > 0 )
  {
    for( i = 0; i < ( data[8] * 2 ) && i < (raw_response_length / 2);	i++ )
		{
			/* shift reg hi_byte to temp */
			temp = data[ 9 + i *2 ] << 8;
			/* OR with lo_byte           */
			temp = temp | data[ 10 + i * 2 ];

			dest[i] = temp;
		}
	}                
  pthread_mutex_unlock(&mbtcptab[fdidx].mbtcp_mutex);
	return( raw_response_length );
}
/************************************************************************

  trio_read_registers

  read the data from a modbus slave and put that data into an array.

************************************************************************/
//SFD
int trio_read_registers( int function, int slave, int start_addr, int count,
        short *dest, int dest_size, int sfd )
{
  int reread = 0, i, j, sendret;

  /* local declaration */
  int read_reg_response( short *dest, int dest_size,
      unsigned char *query, int fd );

  int status;

  unsigned char packet[ REQUEST_QUERY_SIZE + CHECKSUM_SIZE ];
  unsigned char packet2[ (REQUEST_QUERY_SIZE + CHECKSUM_SIZE)*2 ];
  build_request_packet( slave, function, start_addr, count, packet );

  j=0;
  {
    for(i=0;i< REQUEST_QUERY_SIZE ;i++)
    {
      packet2[j++]=packet[i];
    }
  }
//  start = times(NULL);
//  printf("trio_read_registers=%d\n",count);
reread_loop:
//  printf("SEND read_trio_registers=%d\n",count);
  sendret=send_query(sfd,packet2,j);
//  stop = times(NULL);
//  printf("send_1 time in %f %d\n",(float)(stop-start)/(float)sysconf(_SC_CLK_TCK),sendret);
//  sendret=send_query(sfd,packet2,j);
//  stop = times(NULL);
//  printf("send_2 time in %f %d\n",(float)(stop-start)/(float)sysconf(_SC_CLK_TCK),sendret);
//  printf("send_query retur=%d\n",sendret);
  if( sendret > -1 )
  {
   
    packet[0]=packet2[0]; //copy id    
    status = read_reg_response( dest, dest_size, packet, sfd );
//    stop = times(NULL);
//    printf("resp_1 time in %f %d\n",(float)(stop-start)/(float)sysconf(_SC_CLK_TCK),status);
//    status = read_reg_response( dest, dest_size, packet, sfd );
//    stop = times(NULL);
//    printf("resp_2 time in %f %d\n",(float)(stop-start)/(float)sysconf(_SC_CLK_TCK),status);
//    printf("RECV read_trio_registers=%d\n",status);
    if(status<=0)
    {
      reread++;
			//		printf("trio status %d reread %d\n", status, reread);
      if(reread < 1000000)
      {
        goto reread_loop;
      }
      else
      {
        for(i=0;i<REQUEST_QUERY_SIZE + CHECKSUM_SIZE;i++)
          printf("[%.2X]", packet[i]);
        printf("\n");
      }
    }
  }
  else
  {
    status = SOCKET_FAILURE;
    printf("SOCKET_FAILURE\n"); for(;;);
  }              

  return( status );

}



/************************************************************************

  trio_read_holding_registers

  // trio bug 
  Read the holding registers in a slave and put the data into
  an array.

*************************************************************************/
//SFD
int trio_read_holding_registers_tcp( int slave, int start_addr, int count,
        short *dest, int dest_size, int fdidx )
{
  int function = 0x03;    /* Function: Read Holding Registers */
  int status;

  if( count > MAX_READ_REGS )
  {
    count = MAX_READ_REGS;
#ifdef DEBUG
    fprintf( stderr, "Too many registers requested.\n" );
#endif
  }
//  takeTcpModbus();

  pthread_mutex_lock(&mbtcptab[fdidx].mbtcp_mutex);
  if(rs_param.new_trio_addr)
  {
    start_addr -= 1;
    start_addr *= 2;
    start_addr += 1;
  }
  status = trio_read_registers( function, slave, start_addr, count,
            dest, dest_size, mbtcptab[fdidx].sfd );
  pthread_mutex_unlock(&mbtcptab[fdidx].mbtcp_mutex);

//  releaseTcpModbus();
  return( status);
}





/************************************************************************

	read_input_registers

	Read the inputg registers in a slave and put the data into
	an array.

*************************************************************************/

int read_input_registers_tcp( int slave, int start_addr, int count,
				short *dest, int dest_size, int sfd )
{
	int function = 0x04;	/* Function: Read Input Reqisters */
	int status;

	if( count > MAX_INPUT_REGS )
	{
		count =  MAX_INPUT_REGS;
#ifdef DEBUG
		fprintf( stderr, "Too many input registers requested.\n" );
#endif
	}

	status = read_registers( function, slave, start_addr, count,
						dest, dest_size, sfd );

	return( status );
}





/************************************************************************

	read_reg_response

	reads the response data from a slave and puts the data into an
	array.

************************************************************************/
//SFD
int read_reg_response( short *dest, int dest_size, unsigned char *query, int sfd )
{

	unsigned char data[ MAX_RESPONSE_LENGTH ];
	int raw_response_length;
	int temp,i;

	

	raw_response_length = modbus_response( data, query, sfd );
	if( raw_response_length > 0 )
		raw_response_length -= 2;


  if( raw_response_length > 0 )
  {
    for( i = 0;
    i < ( data[8] * 2 ) && i < (raw_response_length / 2);
									i++ )
		{
			/* shift reg hi_byte to temp */
			temp = data[ 9 + i *2 ] << 8;
			/* OR with lo_byte           */
			temp = temp | data[ 10 + i * 2 ];

			dest[i] = temp;
		}
	}                
	return( raw_response_length );
}










/***********************************************************************

	preset_response

	Gets the raw data from the input stream.

***********************************************************************/
//SFD
int preset_response( unsigned char *query, int sfd )
{
	unsigned char data[ MAX_RESPONSE_LENGTH ];
	int raw_response_length;

	raw_response_length = modbus_response( data, query, sfd );

	return( raw_response_length );
}






/*************************************************************************

	set_single

	sends a value to a register in a slave.

**************************************************************************/
//SFD
int set_single( int function, int slave, int addr, int value, int sfd )
{

	int status;
	int i;

	unsigned char packet[ REQUEST_QUERY_SIZE ];


	for( i = 0; i < 5; i++ ) packet[ i ] = 0;
	packet[ i++ ] = 6;
	packet[ i++ ] = slave;
	packet[ i++ ] = function;
	addr -= 1;
	packet[ i++ ] = addr >> 8;
	packet[ i++ ] = addr & 0x00FF;
	packet[ i++ ] = value >> 8;
	packet[ i++ ] = value & 0x00FF;

//TODO resend_loop
//  printf("set_single\n");
	if( send_query( sfd, packet, i ) > -1 )
	{
		status = preset_response( packet, sfd );
	}
	else
	{
		status = SOCKET_FAILURE;
	}

	return( status );
}






/*************************************************************************

	force_single_coil

	turn on or off a single coil on the slave device

*************************************************************************/

int force_single_coil_tcp( int slave, int coil_addr, int state, int sfd )
{
	int function = 0x05;
	int status;

	if( state ) state = 0xFF00;

	status = set_single( function, slave, coil_addr, state, sfd );

	return( status );
}





/*************************************************************************

	preset_single_register

	sets a value in one holding register in the slave device

*************************************************************************/

//SFD
int preset_single_register_tcp(int slave, int reg_addr, int value, int fdidx )
{
	int function = 0x06;
	int status;
  
	pthread_mutex_lock(&mbtcptab[fdidx].mbtcp_mutex);

	status = set_single( function, slave, reg_addr, value, mbtcptab[fdidx].sfd );

	pthread_mutex_unlock(&mbtcptab[fdidx].mbtcp_mutex);
	
	return( status );
}





/************************************************************************

	set_multiple_coils

	Takes an array of ints and sets or resets the coils on a slave
	appropriatly.

*************************************************************************/

#define PRESET_QUERY_SIZE 1000
//#define PRESET_QUERY_SIZE 210

int set_multiple_coils_tcp( int slave, int start_addr, int coil_count,
				int *data, int fd )
{
	int byte_count;
	int i, bit, packet_size, data_legth;
	int coil_check = 0;
	int data_array_pos = 0;
	int status;

	unsigned char packet[ PRESET_QUERY_SIZE ];

	if( coil_count > MAX_WRITE_COILS )
	{
		coil_count = MAX_WRITE_COILS;
#ifdef DEBUG
		fprintf( stderr, "Writing to too many coils.\n" );
#endif
	}
	for( packet_size = 0; packet_size < 5; packet_size++ )
		packet[ packet_size ] = 0;
	packet[ packet_size++ ] = 6;
	packet[ packet_size++ ] = slave;
	packet[ packet_size++ ] = 0x0F;
	start_addr -= 1;
	packet[ packet_size++ ] = start_addr >> 8;
	packet[ packet_size++ ] = start_addr & 0x00FF;
	packet[ packet_size++ ] = coil_count >> 8;
	packet[ packet_size++ ] = coil_count & 0x00FF;
	byte_count = (coil_count / 8) + 1;
	packet[ packet_size ] = byte_count;

	bit = 0x01;

	for( i = 0; i < byte_count; i++)
	{
		packet[ ++packet_size ] = 0;

		while( bit & 0xFF && coil_check++ < coil_count )
		{
			if( data[ data_array_pos++ ] )
			{
				packet[ packet_size ] |= bit;
			}
			else
			{
				packet[ packet_size ] &=~ bit;
			}
			bit = bit << 1;
		}
		bit = 0x01;
	}

	data_legth = packet_size - 5;
	packet[ 4 ] = data_legth >> 8;
	packet[ 5 ] = data_legth & 0x00FF;


	if( send_query( fd, packet, ++packet_size ) > -1 )
	{
		status = preset_response( packet, fd );
	}
	else
	{
		status = SOCKET_FAILURE;
	}

	return( status );
}

/*************************************************************************

	preset_multiple_registers

	copy the values in an array to an array on the slave.

***************************************************************************/

int preset_multiple_registers_tcp( int slave, int start_addr,
				    int reg_count, short *data, int fd , int numOfResends )
{
  int j, resend=0;
  int byte_count, i, packet_size, data_legth;
  int status;

  pthread_mutex_lock(&mbtcptab[fd].mbtcp_mutex);

	unsigned char packet[ PRESET_QUERY_SIZE ];
  unsigned char packet2[ PRESET_QUERY_SIZE ];

  if( reg_count > MAX_WRITE_REGS )
  {
    reg_count = MAX_WRITE_REGS;
#ifdef DEBUG
    fprintf( stderr, "Trying to write to too many registers.\n" );
#endif
	}

  for( packet_size = 0; packet_size < 5; packet_size++ )
		packet[ packet_size ] = 0;
  packet[ packet_size++ ] = 6;
	packet[ packet_size++ ] = slave;
	packet[ packet_size++ ] = 0x10;
	start_addr -= 1;
	packet[ packet_size++ ] = start_addr >> 8;
	packet[ packet_size++ ] = start_addr & 0x00FF;
	packet[ packet_size++ ] = reg_count >> 8;
	packet[ packet_size++ ] = reg_count & 0x00FF;
	byte_count = reg_count * 2;
	packet[ packet_size ] = byte_count;

	for( i = 0; i < reg_count; i++ )
	{
    packet[ ++packet_size ] = ((unsigned short)data[ i ]) >> 8;
		packet[ ++packet_size ] = ((unsigned short)data[ i ]) & 0x00FF;
	}

  data_legth = packet_size - 5;
  packet[ 4 ] = data_legth >> 8;
  packet[ 5 ] = data_legth & 0x00FF;

  j=0;
  for(i=0;i<=packet_size;i++)
  {
    packet2[j++]=packet[i];
  }

resend_loop:
  if( (status = send_query( mbtcptab[fd].sfd, packet2, j )) > -1 )
  {
    if(status!=j)
    {
      fprintf( stderr, "status %d bytecount %d\n", status, j);
      printf("status %d bytecount %d\n", status, j);
      goto resend_loop;
    }
    packet[0]=packet2[0]; //copy id
    status = preset_response( packet, mbtcptab[fd].sfd );
    if(status<=0)
    {
      resend++;
			if (rs_param.io_debug>=3)
			{
				printf("status %d bytecount %d\n", status, j);
				printf("status %d resend %d\n", status, resend);
				fprintf( stderr, "status %d resend %d\n", status, resend);
				fprintf( stderr, "status %d bytecount %d\n", status, j);
			}
      if(resend < numOfResends)
      {
        goto resend_loop;
      }
      else
      {
				if (rs_param.io_debug>=3)
				{
					for(i=0;i<j;i++)
						fprintf( stderr, "[%.2X]", packet2[i]);
					fprintf( stderr, "\n");
					status = SOCKET_FAILURE;
				}
			}
    }
  }
  else
  {
    status = SOCKET_FAILURE;
    fprintf( stderr, "SOCKET_FAILURE\n");
    for(;;);
  }

  pthread_mutex_unlock(&mbtcptab[fd].mbtcp_mutex);

  return( status );
}

/*************************************************************************

	preset_multiple_registers

	copy the values in an array to an array on the slave.

***************************************************************************/

int preset_multiple_registers_tcp_async1( int slave, int start_addr,
				    int reg_count, short *data, int fd)
{
  int j;
  int byte_count, i, packet_size, data_legth;
  int status;

  pthread_mutex_lock(&mbtcptab[fd].mbtcp_mutex);

	unsigned char packet[ PRESET_QUERY_SIZE ];
  unsigned char packet2[ PRESET_QUERY_SIZE ];

  if( reg_count > MAX_WRITE_REGS )
  {
    reg_count = MAX_WRITE_REGS;
#ifdef DEBUG
    fprintf( stderr, "Trying to write to too many registers.\n" );
#endif
	}

  for( packet_size = 0; packet_size < 5; packet_size++ )
		packet[ packet_size ] = 0;
  packet[ packet_size++ ] = 6;
	packet[ packet_size++ ] = slave;
	packet[ packet_size++ ] = 0x10;
	start_addr -= 1;
	packet[ packet_size++ ] = start_addr >> 8;
	packet[ packet_size++ ] = start_addr & 0x00FF;
	packet[ packet_size++ ] = reg_count >> 8;
	packet[ packet_size++ ] = reg_count & 0x00FF;
	byte_count = reg_count * 2;
	packet[ packet_size ] = byte_count;

	for( i = 0; i < reg_count; i++ )
	{
    packet[ ++packet_size ] = ((unsigned short)data[ i ]) >> 8;
		packet[ ++packet_size ] = ((unsigned short)data[ i ]) & 0x00FF;
	}

  data_legth = packet_size - 5;
  packet[ 4 ] = data_legth >> 8;
  packet[ 5 ] = data_legth & 0x00FF;

  j=0;
  for(i=0;i<=packet_size;i++)
  {
    packet2[j++]=packet[i];
  }

  if( (status = send_query( mbtcptab[fd].sfd, packet2, j )) > -1 )
  {
  }
  else
  {
    status = SOCKET_FAILURE;
    fprintf( stderr, "SOCKET_FAILURE\n");
    for(;;);
  }

  return( status );
}

int preset_multiple_registers_tcp_async2( int slave, int start_addr,
				    int reg_count, short *data, int fd )
{
  int j, resend=0;
  int byte_count, i, packet_size, data_legth;
  int status;
	unsigned char packet[ PRESET_QUERY_SIZE ];
  unsigned char packet2[ PRESET_QUERY_SIZE ];

  if( reg_count > MAX_WRITE_REGS )
  {
    reg_count = MAX_WRITE_REGS;
#ifdef DEBUG
    fprintf( stderr, "Trying to write to too many registers.\n" );
#endif
	}

  for( packet_size = 0; packet_size < 5; packet_size++ )
		packet[ packet_size ] = 0;
  packet[ packet_size++ ] = 6;
	packet[ packet_size++ ] = slave;
	packet[ packet_size++ ] = 0x10;
	start_addr -= 1;
	packet[ packet_size++ ] = start_addr >> 8;
	packet[ packet_size++ ] = start_addr & 0x00FF;
	packet[ packet_size++ ] = reg_count >> 8;
	packet[ packet_size++ ] = reg_count & 0x00FF;
	byte_count = reg_count * 2;
	packet[ packet_size ] = byte_count;

	for( i = 0; i < reg_count; i++ )
	{
    packet[ ++packet_size ] = ((unsigned short)data[ i ]) >> 8;
		packet[ ++packet_size ] = ((unsigned short)data[ i ]) & 0x00FF;
	}

  data_legth = packet_size - 5;
  packet[ 4 ] = data_legth >> 8;
  packet[ 5 ] = data_legth & 0x00FF;

  j=0;
  for(i=0;i<=packet_size;i++)
  {
    packet2[j++]=packet[i];
  }

  //  packet[0]=packet2[0]; //copy id
  status = preset_response( packet, mbtcptab[fd].sfd );
  if(status<=0)
  {
    printf("status %d bytecount %d\n", status, j);
    printf("status %d resend %d\n", status, resend);
    fprintf( stderr, "status %d resend %d\n", status, resend);
    fprintf( stderr, "status %d bytecount %d\n", status, j);
    for(i=0;i<j;i++)
      fprintf( stderr, "[%.2X]", packet2[i]);
    fprintf( stderr, "\n");
    status = SOCKET_FAILURE;
  }

  pthread_mutex_unlock(&mbtcptab[fd].mbtcp_mutex);

  return( status );
}

/*************************************************************************

	trio_preset_multiple_registers
  because of an error in trio's ethernet module we need this call.
	copy the values in an array to an array on the slave.

***************************************************************************/

int trio_preset_multiple_registers_tcp( int slave, int start_addr,
				    int reg_count, short *data, int fd )
{
  int j, resend=0;
  int byte_count, i, packet_size, data_legth;
  int status;
  int pthreadret;
	unsigned char packet[ PRESET_QUERY_SIZE ];
  unsigned char packet2[ PRESET_QUERY_SIZE ];

//  takeTcpModbus();
  pthreadret=pthread_mutex_lock(&mbtcptab[fd].mbtcp_mutex);
  if(pthreadret!=0) printf("&mbtcptab[fd].mbtcp_mutex pthreadret=%d\n",pthreadret);


  if( reg_count > MAX_WRITE_REGS )
  {
    reg_count = MAX_WRITE_REGS;
#ifdef DEBUG
    fprintf( stderr, "Trying to write to too many registers.\n" );
#endif
	}

  if(rs_param.new_trio_addr)
  {
    start_addr -= 1;
    start_addr *= 2;
    start_addr += 1;
  }

  for( packet_size = 0; packet_size < 5; packet_size++ )
		packet[ packet_size ] = 0;
  packet[ packet_size++ ] = 6;
	packet[ packet_size++ ] = slave;
	packet[ packet_size++ ] = 0x10;
	start_addr -= 1;
	packet[ packet_size++ ] = start_addr >> 8;
	packet[ packet_size++ ] = start_addr & 0x00FF;
	packet[ packet_size++ ] = reg_count >> 8;
	packet[ packet_size++ ] = reg_count & 0x00FF;
	byte_count = reg_count * 2;
	packet[ packet_size ] = byte_count;

	for( i = 0; i < reg_count; i++ )
	{
    packet[ ++packet_size ] = ((unsigned short)data[ i ]) >> 8;
		packet[ ++packet_size ] = ((unsigned short)data[ i ]) & 0x00FF;
	}

  data_legth = packet_size - 5;
  packet[ 4 ] = data_legth >> 8;
  packet[ 5 ] = data_legth & 0x00FF;

  j=0;
  {
    for(i=0;i<=packet_size;i++)
    {
      packet2[j++]=packet[i];
    }
  }
resend_loop:
//  printf("SEND byte_count=%d\n",byte_count);
  if( (status = send_query( mbtcptab[fd].sfd, packet2, j )) > -1 )
  {
    if(status!=j)
    {
      printf("trio status %d bytecount %d\n", status, j);
      goto resend_loop;
    }
    packet[0]=packet2[0]; //copy id
    status = preset_response( packet, mbtcptab[fd].sfd );
//    printf("RECV byte_count=%d\n",status);
    if(status<=0)
    {
      resend++;
      printf("trio status %d resend %d\n", status, resend);
      printf("trio status %d bytecount %d\n", status, j);
      if(resend < 1000000)
      {
        goto resend_loop;
      }
      else
      {
        for(i=0;i<j;i++)
          printf("[%.2X]", packet2[i]);
        printf("\n");
      }
    }
    else
    {
    }
  }
  else
  {
    status = SOCKET_FAILURE;
    printf("SOCKET_FAILURE\n"); for(;;);
  }

  pthread_mutex_unlock(&mbtcptab[fd].mbtcp_mutex);
//  releaseTcpModbus();
  
  return( status );
}


#define MODBUS_TCP_PORT 502

int set_up_tcp( char *ip_address )
{
  int i;
  int connect_stat;
  int on=1;
	
  if(mbtcpconnectioncount >= MAXMBTCPCONNECTIONS)
    return -1;
	
  for(i=0;i<mbtcpconnectioncount;i++)
  {
    if(strcmp(ip_address, mbtcptab[i].ip_addr)==0)
			return i;
  }		
  
  strcpy(mbtcptab[mbtcpconnectioncount].ip_addr, ip_address);
  pthread_mutex_init(&mbtcptab[mbtcpconnectioncount].mbtcp_mutex, NULL);

  mbtcptab[mbtcpconnectioncount].sfd = socket( PF_INET, SOCK_STREAM, IPPROTO_TCP );
	setsockopt(mbtcptab[mbtcpconnectioncount].sfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  mbtcptab[mbtcpconnectioncount].server.sin_family = AF_INET;
  mbtcptab[mbtcpconnectioncount].server.sin_port = htons( MODBUS_TCP_PORT );
  mbtcptab[mbtcpconnectioncount].server.sin_addr.s_addr = inet_addr(ip_address);
	
  if( mbtcptab[mbtcpconnectioncount].sfd >= 0 )
  {
    connect_stat = connect( mbtcptab[mbtcpconnectioncount].sfd, (struct sockaddr *)&mbtcptab[mbtcpconnectioncount].server,
			    sizeof(struct sockaddr_in) );
    
    if( connect_stat < 0 )
    {
      //plc_log_errmsg( 0, "\nConnect - error %d\n",
      //				connect_stat );
      close( mbtcptab[mbtcpconnectioncount].sfd );
      mbtcptab[mbtcpconnectioncount].sfd = -1;
      // exit( connect_stat );
    }
  }
  printf("%s: mbtcptab[mbtcpconnectioncount=%d].sfd=%d\n",ip_address,mbtcpconnectioncount,mbtcptab[mbtcpconnectioncount].sfd);
  if (mbtcptab[mbtcpconnectioncount].sfd == -1)	return -1;
  return( mbtcpconnectioncount++ );
}

int close_tcp(int sfd)
{
  close( mbtcptab[sfd].sfd );
  return 1;
}
