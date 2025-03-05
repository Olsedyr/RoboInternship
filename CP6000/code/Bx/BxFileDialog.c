#include "Bx.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define             BXID_FILEDLG		10000
#define             BXID_FILELIST		102
static BXLISTSTRUCT FileDlgList;
static char currentPath[255] = "/";

BOXSTRUCT FILEDIALOGLIST[] = {
	{ BXID_FILEDLG	, 0, 0, 800, 600, DIALOG,"",BXS_VISIBLE, &FILEDIALOGLIST[1], NULL}
	,{ IDOK		, 10, 10, 160, 60,	BUTTON,"Ok",BBS_PUSHBUTTON | BXS_VISIBLE ,&FILEDIALOGLIST[2], &FILEDIALOGLIST[0]}
	,{ IDCANCEL	, 10, 10, 160, 60,	BUTTON,"Fortryd",BBS_PUSHBUTTON | BXS_VISIBLE ,&FILEDIALOGLIST[3], &FILEDIALOGLIST[0]}
	,{ BXID_FILELIST, 10, 10, 160, 60, STATIC,"List",BXS_VISIBLE, NULL, &FILEDIALOGLIST[0]}
};

static void setupList(HBOX hBox, char *dir, char *type)
{
  struct dirent **namelist;
  struct stat dstat;
  int n, i, j;
  char s[255];

  n = BxList_GetCount(BxGetDlgItem(hBox, BXID_FILELIST));
  for(i=0;i<n;i++)
  {
    BxList_DeleteString( BxGetDlgItem(hBox, BXID_FILELIST), 0);
  }

//  j = n = scandir( dir, &namelist, 0, alphasort );
//  j = n = scandir( dir, &namelist, 0, 0 );
  if(n >= 0)
  {
/*
	while(j--)
	{
      stat(namelist[j]->d_name, &dstat);
	  if(S_ISDIR(dstat.st_mode))
        namelist[j]->d_type=4;
      else
        namelist[j]->d_type=8;
    }
*/
    for(i=0;i<n;i++)
    {
      stat(namelist[j]->d_name, &dstat);
	  if(S_ISDIR(dstat.st_mode))
//      if(namelist[i]->d_type==4)
	  {
	    sprintf(s,"[ %s ]", namelist[i]->d_name);
        BxList_AddString(BxGetDlgItem(hBox, BXID_FILELIST), s);
	  }
    }
    for(i=0;i<n;i++)
    {
      stat(namelist[j]->d_name, &dstat);
	  if(!(S_ISDIR(dstat.st_mode)))
//      if(namelist[i]->d_type==8)
	  {
        if(type!=NULL)
        {
	      if(strcmp(&namelist[i]->d_name[strlen(namelist[i]->d_name)-strlen(type)], type) == 0)
	      {
	        sprintf(s,"%s",namelist[i]->d_name);
	        BxList_AddString(BxGetDlgItem(hBox, BXID_FILELIST), s);
	      }
        }
        else
	    {
	      sprintf(s,"%s", namelist[i]->d_name);
	      BxList_AddString(BxGetDlgItem(hBox, BXID_FILELIST), s);
	    }
      }
    }
  }
}

static void initList(HBOX hBox, BXFILEDLGSTRUCT *pBxFDlgList)
{
  FileDlgList.m_ViewPos = 0;

  setupList(hBox, pBxFDlgList->Path, pBxFDlgList->Type);
}

static BX_BOOL bxFileDlgInit( HBOX hBox, BX_LPARAM lParam )
{
	struct dirent **namelist;
	int n;
	BXFILEDLGSTRUCT *pBxFDlgList = (BXFILEDLGSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;
	BX_LAYOUTSTRUCT FDlgLayout;

	BxCreateLayout( &FDlgLayout, hBox, 6, 10, 10, 10 );

	BxAssignBoxToLayout( BxGetDlgItem(hBox, IDOK), &FDlgLayout, 	4, 8, 5, 10);
	BxAssignBoxToLayout( BxGetDlgItem(hBox, IDCANCEL), &FDlgLayout, 	5, 8, 6, 10);
	BxAssignBoxToLayout( BxGetDlgItem(hBox, BXID_FILELIST), &FDlgLayout, 	0, 0, 6, 8);

	BxList_Create( BxGetDlgItem(hBox, BXID_FILELIST), &FileDlgList, 0);

  initList(hBox, pBxFDlgList);

  BxEnableBox(BxGetDlgItem(hBox, IDOK), FALSE);
	return ( TRUE ) ;
}


static void cmdListScript_Click(HBOX hBox)
{
  BX_CHAR *str, dirs[255], newPath[255];
  BXFILEDLGSTRUCT *pBxFDlgList = (BXFILEDLGSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;

  if((str = BxList_GetString(BxGetDlgItem(hBox, BXID_FILELIST), BxList_GetSelected(BxGetDlgItem(hBox, BXID_FILELIST)))) != NULL )
  {
    if(str[0] == '[')
    {
      sprintf(dirs, "%s", &str[2]);
      dirs[strlen(dirs)-2]='\0';
      sprintf(newPath,"%s/%s", pBxFDlgList->Path, dirs );
      chdir(newPath);
      getcwd(pBxFDlgList->Path, 255);
      initList(hBox, pBxFDlgList);
      BxEnableBox(BxGetDlgItem(hBox, IDOK), FALSE);
    }
    else
      BxEnableBox(BxGetDlgItem(hBox, IDOK), TRUE);
  }
}	


static BX_BOOL bxFileDlgProc( HBOX hBox, BX_UINT uMsg, BX_WPARAM wParam, BX_LPARAM lParam )
{
	BXFILEDLGSTRUCT *pBxFDlgList = (BXFILEDLGSTRUCT *)((BOXSTRUCT*)hBox)->m_userData;

	switch (uMsg)
	{
		case BM_INITDIALOG :
			bxFileDlgInit( hBox, lParam );
			return TRUE;
			break;
		case BM_COMMAND :
			{
				switch( BX_LOWORD( wParam ) ) 
				{
					case IDOK :
						if(BxList_GetSelected(BxGetDlgItem(hBox, BXID_FILELIST))> -1)
							sprintf(pBxFDlgList->Filename, "%s/%s", pBxFDlgList->Path, BxList_GetString(BxGetDlgItem(hBox, BXID_FILELIST),BxList_GetSelected(BxGetDlgItem(hBox, BXID_FILELIST))));
						BxEndDialog(hBox, IDOK);
						return TRUE;
						break;
					case IDCANCEL :
						BxStringCopy(pBxFDlgList->Filename, "");
						BxEndDialog(hBox, IDCANCEL);
						return TRUE;
						break;
					case BXID_FILELIST :
            cmdListScript_Click(hBox);
						return FALSE;
						break;
				}
				break;
			}
			break;
		default:
			return(DefBoxProc(hBox,uMsg,wParam,lParam));
	}
	return FALSE ;
}


BX_INT BxFileDialog( HBOX hBox, BXFILEDLGSTRUCT* pFDlg )
{
	HBOX hFileDlg;
	BX_INT rtnVal;

	if(hBox == NULL)
		return -1;

	FILEDIALOGLIST[0].m_userData = (BX_PVOID)pFDlg;
	hFileDlg = BxCreateDialog(GetAppInstance(hBox), &FILEDIALOGLIST[0], bxFileDlgProc);

  if(strcmp(pFDlg->Path, "")==0)
    getcwd(pFDlg->Path, 255);

	rtnVal = DoModal(hFileDlg);

	return rtnVal;
}
