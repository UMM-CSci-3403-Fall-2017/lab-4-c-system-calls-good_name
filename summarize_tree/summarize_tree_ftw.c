#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

#define MAX_FTW_DEPTH 16

static int num_dirs;
static int num_regulars;

static int callback(const char *fpath, const struct stat *sb, int typeflag){
	if(typeflag == FTW_D) {
		num_dirs++;
	}else{
		num_regulars++;
	}
	return 0;
}

int main (int argc, char** argv){
	num_dirs = 0;
	num_regulars = 0;

	  // Ensure an argument was provided.
	 if (argc != 2) {
	    printf ("Usage: %s <path>\n", argv[0]);
	    prinhttps://github.com/UMM-CSci-3403-Fall-2017/lab-4-c-system-calls-good_name.gittf ("       where <path> is the file or root of the tree you want to summarize.\n");

   	    return 1;
  }


	ftw(argv[1], callback, MAX_FTW_DEPTH);

	printf("There were %d directories.\n", num_dirs);
	printf("There were %d regular files.\n", num_regulars);

	return 0;
}
