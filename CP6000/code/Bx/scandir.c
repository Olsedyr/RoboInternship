int	MatchDir = 0;

#ifdef WINDOWS

# include <windows.h>
#include "bxscandir.h"

/* Scandir returns the number of entries or -1 if the directory cannot
   be opened or malloc fails. */

struct bxdirent	*ourarray;

int
jscandir( char *dir, struct bxdirent **nmptr, int (*qualify)(char *), int	(*sorter)(void *, void *))
{
	WIN32_FIND_DATA entry;
	HANDLE findHand;
	struct bxdirent	*tptr;
	unsigned int	nalloc = 10,
	nentries = 0;

	char dirname[_MAX_PATH];
	char *ptr;

	strcpy(dirname, dir);
	ptr = &dirname[strlen(dirname)-1];
	if (!((dirname[1] == ':' && dirname[2] == '\0') || *ptr == '/' || *ptr == '\\'))
		*++ptr = '/';
	strcpy(ptr+1, "*.*");

	if ((findHand = FindFirstFile(dirname, &entry)) == INVALID_HANDLE_VALUE)
		return -1;

	do  {
      nentries++;
	} while (FindNextFile(findHand, &entry));
	FindClose(findHand);
	
	ourarray = (struct bxdirent *) malloc(nentries * sizeof (struct bxdirent));
	
	if ((findHand = FindFirstFile(dirname, &entry)) == INVALID_HANDLE_VALUE)
		return -1;

    nentries = 0;
    do  {
		char filename[_MAX_PATH];

		if (MatchDir && (entry.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) == 0)
			continue;
		strcpy(filename, entry.cFileName);
		strlwr(entry.cFileName);
		if (qualify != NULL && !(*qualify)(entry.cFileName))
			continue;
		/* note: test ensures one space left in ourarray for NULL */
//		if (nentries+1 == nalloc)
//	    ourarray = (struct bxdirent **) realloc((struct bxdirent*) ourarray, (nentries+1) * sizeof (struct bxdirent));
#ifdef DIRECTORY_ADD_SLASH
		if ((entry.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) != 0)
			strcat(filename, "/");
#endif
        tptr = &ourarray[nentries];

		if ((entry.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY) == 0)
          tptr->d_type = 4;
        else
          tptr->d_type = 8;
        sprintf(tptr->d_name,"%s", filename);

        nentries++;
	} while (FindNextFile(findHand, &entry));
	FindClose(findHand);
//	ourarray[nentries] = NULL;

//	if (sorter != NULL)
//		qsort((char *) ourarray, nentries, sizeof (char **), sorter);
	
    *nmptr = ourarray;

	return nentries;
}

#endif /* WINDOWS */

void
freedir(nmptr, nentries)
struct bxdirent	**nmptr;
int	nentries;
{
	struct bxdirent	*ourarray = *nmptr;

	free(ourarray);
	nmptr = NULL;
}
