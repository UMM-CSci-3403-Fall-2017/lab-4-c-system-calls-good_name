#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

static int num_dirs, num_regular;

bool is_dir(const char* path) {
	//allocate memory for a buffer and us it to store stat info
	struct stat *buf = malloc(1024*sizeof(int));
        int stat_val;
        stat_val = stat(path, buf);

	//check for successful stat call
        if(stat_val == 0){
		//free allocated memory and return true if path is a directory
                if(S_ISDIR(buf->st_mode)){
                        free(buf);
                        return true;
                }
        }

        //free allocated memory and return false
	free(buf);
        return false;
}

//initialize sub function for use in recursion
void process_path(const char*);

void process_directory(const char* path) {
	//initialize vars
	DIR *dir;
        struct dirent *sub_d;
	
	//increment directory count
        num_dirs++;
	
	//open working directory and store info about current entry in dirent struct
        dir = opendir(path);
        chdir(path);
        sub_d=readdir(dir);

	//while sub directories+files exist, recursively iterate through file hierarchy
        while(sub_d != NULL){
		//check for infinite loop condition
        	if(strcmp(sub_d->d_name,".")!=0 && strcmp(sub_d->d_name,"..")!=0){
                        //make recursive call
			process_path(sub_d->d_name);
                }
        sub_d=readdir(dir);
        }
	
	//close directory and navigate up file tree
        closedir(dir);
        chdir("..");
}

void process_file(const char* path) {
	//increment file count
	num_regular++;
}

void process_path(const char* path) {
  //call appropriate subfunction depending on path filetype
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;
  
  //call subfunction
  process_path(argv[1]);

  //print counts
  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
