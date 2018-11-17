#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int main()
{
   key_t key=1;
   int msgid;
  s_info *msg = (s_info*)malloc(sizeof(s_info));
  msgid=msgget(key,0444);
  if(msgid==-1){
  perror("can't get message queue");
  return EXIT_FAILURE;
  }
  msgrcv(msgid, msg, sizeof(s_info), 0,0);

 printf("SERVER_INFO:\n PID: %d \t UID: %d \t GID: %d \t\n TIME %s", msg->pid, msg->uid, msg->gid, ctime(&msg->tm));
     printf("LOAD:\t%f\t%f\t%f,", msg->load[0], msg->load[1],msg ->load[2]);
    return EXIT_SUCCESS;
}
