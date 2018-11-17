#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include "structs.h"
#include <errno.h>
int main()
{
   int soc, check;
   char * data ="abcdefghijklmn";
   struct sockaddr serv_addr;
   serv_addr.sa_family=AF_UNIX;
   strncpy(serv_addr.sa_data,data, strlen(data));
   s_info * info = (s_info*) malloc(sizeof(s_info));
   soc = socket(AF_UNIX, SOCK_STREAM, 0);
   if(soc==-1){
   perror("cant obtain socket");
   return EXIT_FAILURE;
   }

  check =  connect(soc,  &serv_addr, sizeof(struct sockaddr));
  if(check==-1){
  perror("can't connect");
  return EXIT_FAILURE;
  }
  recv(soc,info, sizeof(s_info),0);
  printf("SERVER_INFO:\n PID: %d \t UID: %d \t GID: %d \t\n TIME %s", info->pid, info->uid, info->gid, ctime(&info->tm));
 printf("LOAD:\t%f\t%f\t%f,", info->load[0], info->load[1],info ->load[2]);
    return 0;
}
