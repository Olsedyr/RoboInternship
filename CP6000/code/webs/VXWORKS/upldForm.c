/* upldForm.c - GoForm to handle file upload */

/*
modification history
--------------------
01a,13feb01,lohct  written.
*/

/*
DESCRIPTION
This GoForm procedure handles http file upload.

SEE ALSO:
"GoForms - GoAhead WebServer"
*/

#include "vxWorks.h"
#include "../webs.h"

/* forward declarations */
void        upldForm(webs_t wp, char_t * path, char_t * query);


/*******************************************************************************
*
* upldForm - GoForm procedure to handle file uploads for upgrading device
*
* This routine handles http file uploads for upgrading device.
*
* RETURNS: OK, or ERROR if the I/O system cannot install the driver.
*/

void upldForm(webs_t wp, char_t * path, char_t * query) {
    char_t *     fn;
    char_t *     bn = NULL;

    a_assert(websValid(wp));
    websHeader(wp);

    fn = websGetVar(wp, T("filename"), T(""));
    if (fn != NULL && *fn != '\0') {
        if ((int)(bn = gstrrchr(fn, '/') + 1) == 1) {
            if ((int)(bn = gstrrchr(fn, '\\') + 1) == 1) {
                bn = fn;
            }
        }
    }

    websWrite(wp, T("Filename = %s<br>Size = %d bytes<br>"), bn, wp->lenPostData);


    websFooter(wp);
    websDone(wp, 200);
}    /* void upldForm(webs_t wp, char_t * path, char_t * query) */
