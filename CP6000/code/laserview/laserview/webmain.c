/*
 * main.c -- Main program for the GoAhead WebServer (LINUX version)
 *
 * Copyright (c) GoAhead Software Inc., 1995-2000. All Rights Reserved.
 *
 * See the file "license.txt" for usage and redistribution license requirements
 */

/******************************** Description *********************************/

/*
 *	Main program for for the GoAhead WebServer. This is a demonstration
 *	main program to initialize and configure the web server.
 */

/********************************* Includes ***********************************/

#include	"uemf.h"
#include	"wsIntrn.h"
#include	<signal.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>

#ifdef WEBS_SSL_SUPPORT
#include	"websSSL.h"
#endif

#ifdef USER_MANAGEMENT_SUPPORT
#include	"um.h"
void	formDefineUserMgmt(void);
#endif

#include "lv.h"

/*********************************** Locals ***********************************/
/*
 *	Change configuration here
 */

static char_t		*rootWeb = T("web");			/* Root web directory */
static char_t		*password = T("");				/* Security password */
static int			port = 80;						/* Server port */
static int			retries = 5;					/* Server port retries */
static int			finished;						/* Finished flag */

/****************************** Forward Declarations **************************/

static int 	initWebs();
static int camPicture(int eid, webs_t wp, int argc, char_t **argv);
static int camStatus(int eid, webs_t wp, int argc, char_t **argv);
static int camParam(int eid, webs_t wp, int argc, char_t **argv);
static void formCam(webs_t wp, char_t *path, char_t *query);
static int foiParam(int eid, webs_t wp, int argc, char_t **argv);
static void formFoi(webs_t wp, char_t *path, char_t *query);
static int filterParam(int eid, webs_t wp, int argc, char_t **argv);
static void formFilter(webs_t wp, char_t *path, char_t *query);
static int  websHomePageHandler(webs_t wp, char_t *urlPrefix, char_t *webDir,
				int arg, char_t *url, char_t *path, char_t *query);
extern void defaultErrorHandler(int etype, char_t *msg);
extern void defaultTraceHandler(int level, char_t *buf);
extern void upldForm(webs_t wp, char_t *path, char_t *query);
#ifdef B_STATS
static void printMemStats(int handle, char_t *fmt, ...);
static void memLeaks();
#endif

/*********************************** Code *************************************/
/*
 *	Main -- entry point from LINUX
 */

void *webmain(void* argument)
{
/*
 *	Initialize the memory allocator. Allow use of malloc and start
 *	with a 60K heap.  For each page request approx 8KB is allocated.
 *	60KB allows for several concurrent page requests.  If more space
 *	is required, malloc will be used for the overflow.
 */
	bopen(NULL, (60 * 1024), B_USE_MALLOC);
	signal(SIGPIPE, SIG_IGN);

/*
 *	Initialize the web server
 */
	if (initWebs() < 0) {
		return NULL;
	}

#ifdef WEBS_SSL_SUPPORT
	websSSLOpen();
#endif

/*
 *	Basic event loop. SocketReady returns true when a socket is ready for
 *	service. SocketSelect will block until an event occurs. SocketProcess
 *	will actually do the servicing.
 */
	while (!finished) {
		if (socketReady(-1) || socketSelect(-1, 1000)) {
			socketProcess(-1);
		}
		websCgiCleanup();
		emfSchedProcess();
	}

#ifdef WEBS_SSL_SUPPORT
	websSSLClose();
#endif

#ifdef USER_MANAGEMENT_SUPPORT
	umClose();
#endif

/*
 *	Close the socket module, report memory leaks and close the memory allocator
 */
	websCloseServer();
	socketClose();
#ifdef B_STATS
	memLeaks();
#endif
	bclose();
	return NULL;
}

/******************************************************************************/
/*
 *	Initialize the web server.
 */

static int initWebs()
{
	struct hostent	*hp;
	struct in_addr	intaddr;
	char			host[128], dir[128], webdir[128];
	char			*cp;
	char_t			wbuf[128];

/*
 *	Initialize the socket subsystem
 */
  socketOpen();

#ifdef USER_MANAGEMENT_SUPPORT
/*
 *	Initialize the User Management database
 */
	umOpen();
	umRestore(T("umconfig.txt"));
#endif

/*
 *	Define the local Ip address, host name, default home page and the
 *	root web directory.
 */
	if (gethostname(host, sizeof(host)) < 0) {
		error(E_L, E_LOG, T("Can't get hostname"));
		printf("Can't get hostname\n");
		return -1;
	}
	if ((hp = gethostbyname(host)) == NULL) {
		error(E_L, E_LOG, T("Can't get host address"));
		printf("Can't get host address: %s\n", host);
		return -1;
	}
	memcpy((char *) &intaddr, (char *) hp->h_addr_list[0],
		(size_t) hp->h_length);

/*
 *	Set ../web as the root web. Modify this to suit your needs
 */
	getcwd(dir, sizeof(dir));
	if ((cp = strrchr(dir, '/'))) {
		*cp = '\0';
	}
	sprintf(webdir, "%s/%s", dir, rootWeb);

/*
 *	Configure the web server options before opening the web server
 */
	websSetDefaultDir(webdir);
	cp = inet_ntoa(intaddr);
	ascToUni(wbuf, cp, min(strlen(cp) + 1, sizeof(wbuf)));
	websSetIpaddr(wbuf);
	ascToUni(wbuf, host, min(strlen(host) + 1, sizeof(wbuf)));
	websSetHost(wbuf);

/*
 *	Configure the web server options before opening the web server
 */
	websSetDefaultPage(T("home.asp"));
	websSetPassword(password);

/*
 *	Open the web server on the given port. If that port is taken, try
 *	the next sequential port for up to "retries" attempts.
 */
	websOpenServer(port, retries);

/*
 * 	First create the URL handlers. Note: handlers are called in sorted order
 *	with the longest path handler examined first. Here we define the security
 *	handler, forms handler and the default web page handler.
 */
	websUrlHandlerDefine(T(""), NULL, 0, websSecurityHandler,
		WEBS_HANDLER_FIRST);
	websUrlHandlerDefine(T("/goform"), NULL, 0, websFormHandler, 0);
	websUrlHandlerDefine(T("/cgi-bin"), NULL, 0, websCgiHandler, 0);
	websUrlHandlerDefine(T(""), NULL, 0, websDefaultHandler,
		WEBS_HANDLER_LAST);

/*
 *	Now define two test procedures. Replace these with your application
 *	relevant ASP script procedures and form functions.
 */
  websAspDefine(T("camPicture"), camPicture);
  websAspDefine(T("camStatus"), camStatus);
  websAspDefine(T("camParam"), camParam);
  websFormDefine(T("formCam"), formCam);
  websFormDefine(T("upldForm"), upldForm);
  websAspDefine(T("foiParam"), foiParam);
  websFormDefine(T("formFoi"), formFoi);
  websAspDefine(T("filterParam"), filterParam);
  websFormDefine(T("formFilter"), formFilter);

/*
 *	Create the Form handlers for the User Management pages
 */
#ifdef USER_MANAGEMENT_SUPPORT
	formDefineUserMgmt();
#endif

/*
 *	Create a handler for the default home page
 */
	websUrlHandlerDefine(T("/"), NULL, 0, websHomePageHandler, 0);
	return 0;
}

static int camStatus(int eid, webs_t wp, int argc, char_t **argv)
{
  websWrite(wp, T("Total frames: %d<BR>"), caminfo.frames);
  websWrite(wp, T("Droped frame: %d<BR>"), caminfo.droped);
  websWrite(wp, T("Droped total frame: %d<BR>"), caminfo.dropedTotal);
  websWrite(wp, T("<BR>"));
  return 0;
}

static int camPicture(int eid, webs_t wp, int argc, char_t **argv)
{
  saveTempImage();
//  websWrite(wp, T("<img src=""cam.bmp"" width=320 height=240 border=1>"));
  websWrite(wp, T("<img src=""cam.bmp"" border=1>"));
  return 0;
}

static int camParam(int eid, webs_t wp, int argc, char_t **argv)
{
  getCamParam();
  websWrite(wp, T("<table border=0>"));

  websWrite(wp, T("<tr><td>Brightness</td><td><input type=""text"" name=""brightness"" value=""%d""></td><td>Exposure</td><td><input type=""text"" name=""exposure"" value=""%d""></td></tr>"), camparam.brightness, camparam.exposure);
  websWrite(wp, T("<tr><td>Sharpness</td><td><input type=""text"" name=""sharpness"" value=""%d""></td><td>White balance</td><td> %d %d </td></tr>"), camparam.sharpness, camparam.u_b_value, camparam.v_r_value);
  websWrite(wp, T("<tr><td>Hue</td><td><input type=""text"" name=""hue"" value=""%d""></td><td>Saturation</td><td><input type=""text"" name=""saturation"" value=""%d""></td></tr>"), camparam.hue, camparam.saturation);
  websWrite(wp, T("<tr><td>Gamma</td><td><input type=""text"" name=""gamma"" value=""%d""></td><td>Shutter</td><td><input type=""text"" name=""shutter"" value=""%d""></td></tr>"), camparam.gamma, camparam.shutter);
  websWrite(wp, T("<tr><td>Gain</td><td><input type=""text"" name=""gain"" value=""%d""></td><td>Iris</td><td><input type=""text"" name=""iris"" value=""%d""></td></tr>"), camparam.gain, camparam.iris);
  websWrite(wp, T("<tr><td>Focus</td><td><input type=""text"" name=""focus"" value=""%d""></td><td>Trigger mode</td><td> %d </td></tr>"), camparam.focus, camparam.trigger_mode);
  websWrite(wp, T("<tr><td>Zoom</td><td><input type=""text"" name=""zoom"" value=""%d""></td><td>Optical filter</td><td> %d </td></tr>"), camparam.zoom, camparam.optical_filter);
  websWrite(wp, T("<tr><td>Framerate</td><td> %d </td><td>Video mode</td><td> %d </td></tr>"), camparam.framerate, camparam.mode);
  websWrite(wp, T("<tr><td>Video format</td><td> %d </td><td>Channel</td><td> %d </td></tr>"), camparam.format, camparam.channel);
  websWrite(wp, T("<tr><td>Speed</td><td> %d </td><td>Iso on</td><td> %d </td></tr>"), camparam.speed, camparam.is_on);
  websWrite(wp, T("</table>"));
  return 0;
}

static void formCam(webs_t wp, char_t *path, char_t *query)
{
  char_t	*brightness, *exposure, *sharpness;
  char_t	*iris, *focus, *zoom;
  char_t	*hue, *saturation, *gain;
  char_t	*gamma, *shutter;
  char_t newpath[255];
    
  brightness = websGetVar(wp, T("brightness"), T("128"));
  exposure = websGetVar(wp, T("exposure"), T("128"));
  sharpness = websGetVar(wp, T("sharpness"), T("128"));
  iris = websGetVar(wp, T("iris"), T("128"));
  focus = websGetVar(wp, T("focus"), T("128"));
  zoom = websGetVar(wp, T("zoom"), T("128"));
  hue = websGetVar(wp, T("hue"), T("128"));
  saturation = websGetVar(wp, T("saturation"), T("128"));
  gamma = websGetVar(wp, T("gamma"), T("128"));
  shutter = websGetVar(wp, T("shutter"), T("128"));
  gain = websGetVar(wp, T("gain"), T("128"));

  sscanf(brightness,"%d", &camparam.brightness);
  sscanf(exposure,"%d", &camparam.exposure);
  sscanf(sharpness,"%d", &camparam.sharpness);
  sscanf(iris,"%d", &camparam.iris);
  sscanf(focus,"%d", &camparam.focus);
  sscanf(zoom,"%d", &camparam.zoom);
  sscanf(hue,"%d", &camparam.hue);
  sscanf(saturation,"%d", &camparam.saturation);
  sscanf(gamma,"%d", &camparam.gamma);
  sscanf(shutter,"%d", &camparam.shutter);
  sscanf(gain,"%d", &camparam.gain);

  setCamParam();
  savesystemdata();

  sprintf(newpath, "http://%s/camparam.asp", websGetHostUrl());
  websRedirect(wp, newpath);

}

static int foiParam(int eid, webs_t wp, int argc, char_t **argv)
{
  websWrite(wp, T("<table border=1>"));

  websWrite(wp, T("<tr><td>Left</td><td><input type=""text"" name=""left"" value=""%d""></td><td>Step size</td><td><input type=""text"" name=""step"" value=""%d""></td></tr>"), foi.left, step);
  websWrite(wp, T("<tr><td>Top</td><td><input type=""text"" name=""top"" value=""%d""></td></tr>"), foi.top);
  websWrite(wp, T("<tr><td>Right</td><td><input type=""text"" name=""right"" value=""%d""></td></tr>"), foi.right);
  websWrite(wp, T("<tr><td>Bottom</td><td><input type=""text"" name=""bottom"" value=""%d""></td></tr>"), foi.bottom);
  websWrite(wp, T("</table>"));
  return 0;
}

static void formFoi(webs_t wp, char_t *path, char_t *query)
{
  char_t	*left, *top, *right, *bottom, *sstep;
  char_t newpath[255];

  left = websGetVar(wp, T("left"), T("20"));
  sscanf(left,"%d", &foi.left);
  top = websGetVar(wp, T("top"), T("180"));
  sscanf(top,"%d", &foi.top);
  right = websGetVar(wp, T("right"), T("620"));
  sscanf(right,"%d", &foi.right);
  bottom = websGetVar(wp, T("bottom"), T("300"));
  sscanf(bottom,"%d", &foi.bottom);
  sstep = websGetVar(wp, T("step"), T("4"));
  sscanf(sstep,"%d", &step);

  savesystemdata();
  sprintf(newpath, "http://%s/camfoi.asp", websGetHostUrl());
  websRedirect(wp, newpath);

}

static int filterParam(int eid, webs_t wp, int argc, char_t **argv)
{
  char_t floats[25];
  
  websWrite(wp, T("<table border=1>"));

  sprintf(floats,"%f", hsi.h_min);
  websWrite(wp, T("<tr><td>H min</td><td><input type=""text"" name=""hmin"" value=""%s""></td></tr>"), floats);
  sprintf(floats,"%f", hsi.h_max);
  websWrite(wp, T("<tr><td>H max</td><td><input type=""text"" name=""hmax"" value=""%s""></td></tr>"), floats);
  sprintf(floats,"%f", hsi.s);
  websWrite(wp, T("<tr><td>S</td><td><input type=""text"" name=""hsis"" value=""%s""></td></tr>"), floats);
  sprintf(floats,"%f", hsi.i);
  websWrite(wp, T("<tr><td>I</td><td><input type=""text"" name=""hsii"" value=""%s""></td></tr>"), floats);
  websWrite(wp, T("</table>"));
  return 0;
}

static void formFilter(webs_t wp, char_t *path, char_t *query)
{
  char_t	*hmax, *hmin, *s, *i;
  char_t newpath[255];

  hmin = websGetVar(wp, T("hmin"), T("3.0"));
  sscanf(hmin,"%f", &hsi.h_min);
  hmax = websGetVar(wp, T("hmax"), T("5.0"));
  sscanf(hmax,"%f", &hsi.h_max);
  s = websGetVar(wp, T("hsis"), T("0.9"));
  sscanf(s,"%f", &hsi.s);
  i = websGetVar(wp, T("hsii"), T("50.0"));
  sscanf(i,"%f", &hsi.i);

  savesystemdata();
  sprintf(newpath, "http://%s/camfilter.asp", websGetHostUrl());
  websRedirect(wp, newpath);

}

/******************************************************************************/
/*
 *	Home page handler
 */

static int websHomePageHandler(webs_t wp, char_t *urlPrefix, char_t *webDir,
	int arg, char_t *url, char_t *path, char_t *query)
{
/*
 *	If the empty or "/" URL is invoked, redirect default URLs to the home page
 */

/*
  if (*url == '\0' || gstrcmp(url, T("/")) == 0) {
        websRedirect(wp, T("upload.htm"));
    return 1;
  }
*/
  return 0;
}

/******************************************************************************/
/*
 *	Default error handler.  The developer should insert code to handle
 *	error messages in the desired manner.
 */

void defaultErrorHandler(int etype, char_t *msg)
{
#if 0
	write(1, msg, gstrlen(msg));
#endif
}

/******************************************************************************/
/*
 *	Trace log. Customize this function to log trace output
 */

void defaultTraceHandler(int level, char_t *buf)
{
/*
 *	The following code would write all trace regardless of level
 *	to stdout.
 */
#if 0
	if (buf) {
		write(1, buf, gstrlen(buf));
	}
#endif
}

/******************************************************************************/
/*
 *	Returns a pointer to an allocated qualified unique temporary file name.
 *	This filename must eventually be deleted with bfree();
 */

char_t *websGetCgiCommName()
{
	char_t	*pname1, *pname2;

	pname1 = tempnam(NULL, T("cgi"));
	pname2 = bstrdup(B_L, pname1);
	free(pname1);
	return pname2;
}

/******************************************************************************/
/*
 *	Launch the CGI process and return a handle to it.
 */

int websLaunchCgiProc(char_t *cgiPath, char_t **argp, char_t **envp,
					  char_t *stdIn, char_t *stdOut)
{
	int	pid, fdin, fdout, hstdin, hstdout, rc;

	fdin = fdout = hstdin = hstdout = rc = -1;
	if ((fdin = open(stdIn, O_RDWR | O_CREAT, 0666)) < 0 ||
		(fdout = open(stdOut, O_RDWR | O_CREAT, 0666)) < 0 ||
		(hstdin = dup(0)) == -1 ||
		(hstdout = dup(1)) == -1 ||
		dup2(fdin, 0) == -1 ||
		dup2(fdout, 1) == -1) {
		goto DONE;
	}

 	rc = pid = fork();
 	if (pid == 0) {
/*
 *		if pid == 0, then we are in the child process
 */
		if (execve(cgiPath, argp, envp) == -1) {
			printf("content-type: text/html\n\n"
				"Execution of cgi process failed\n");
		}
		exit (0);
	}

DONE:
	if (hstdout >= 0) {
		dup2(hstdout, 1);
	}
	if (hstdin >= 0) {
		dup2(hstdin, 0);
	}
	if (fdout >= 0) {
		close(fdout);
	}
	if (fdin >= 0) {
		close(fdin);
	}
	return rc;
}

/******************************************************************************/
/*
 *	Check the CGI process.  Return 0 if it does not exist; non 0 if it does.
 */

int websCheckCgiProc(int handle)
{
/*
 *	Check to see if the CGI child process has terminated or not yet.
 */
	if (waitpid(handle, NULL, WNOHANG) == handle) {
		return 0;
	} else {
		return 1;
	}
}

/******************************************************************************/

#ifdef B_STATS
static void memLeaks()
{
	int		fd;

	if ((fd = gopen(T("leak.txt"), O_CREAT | O_TRUNC | O_WRONLY)) >= 0) {
		bstats(fd, printMemStats);
		close(fd);
	}
}

/******************************************************************************/
/*
 *	Print memory usage / leaks
 */

static void printMemStats(int handle, char_t *fmt, ...)
{
	va_list		args;
	char_t		buf[256];

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);
	write(handle, buf, strlen(buf));
}
#endif

/******************************************************************************/
