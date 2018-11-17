#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <errno.h>
#include <time.h>
int main()
{

s_info * info;
  int fd=open("data", O_RDWR|O_CREAT, 0666);
    if(fd ==-1){
perror("");
return EXIT_FAILURE;
}
  write(fd,"0", sizeof("w"));
  //get mmap
   info=(s_info*)mmap(NULL,4096,PROT_WRITE|PROT_READ, MAP_SHARED,fd,0 );
   if(info==-1){perror(""); return EXIT_FAILURE;}
   //get info
   info->pid=getpid();
     if(info->pid ==-1){
perror("can't get pid");
return EXIT_FAILURE;
}
   info->uid=getuid();
     if(info->uid ==-1){
perror("can't get uid");
return EXIT_FAILURE;
}
   info->gid=getgid();
     if(info->gid ==-1){
perror("can't get gid");
return EXIT_FAILURE;
}


while(1){
info->tm=time(NULL);
getloadavg(info->load, 3);
 sleep(1);
}
    return EXIT_SUCCESS;
}
