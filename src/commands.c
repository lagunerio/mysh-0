#include <string.h>
#include <stdio.h>
#include "commands.h"

#define PATH_LEN 8096


int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char current_path[PATH_LEN] = {""};

  if(!getcwd(current_path, PATH_LEN)) return -1;

  fprintf(stdout, "%s\n", current_path);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  
//validate and change directory at the same time  
  return(chdir(argv[1]));
}

int validate_pwd_argv(int argc, char** argv) {
  
  return 1;
}
