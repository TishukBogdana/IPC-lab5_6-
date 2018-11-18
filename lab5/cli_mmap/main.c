#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <time.h>
int main()
{
    s_info * info;
    int fd=0;
    fd=open("../server_mmap/data", 0666);
    if(!(fd==-1)){
  info=(s_info *)mmap(NULL, 4096, PROT_READ, MAP_SHARED, fd, 0);
  if(info==-1){
  perror("");
  return EXIT_FAILURE;
  }
 printf("SERVER_INFO:\n PID: %d \t UID: %d \t GID: %d \t\n TIME %s", info->pid, info->uid, info->gid, ctime(&info->tm));
 printf("LOAD:\t%f\t%f\t%f\n", info->load[0], info->load[1],info ->load[2]);
    }else{ perror("data"); return EXIT_FAILURE;}
    return EXIT_SUCCESS;
}
