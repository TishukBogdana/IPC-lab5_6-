#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
///todo:error handle
int main()
{
    key_t key = 1;

    s_info * msg;
    int msgid;
    int err;
    msgid=msgget(key, IPC_CREAT|0666);
    if(msgid==-1){
    perror("can't get message queue");
    return 0;
    }
    msg=(s_info*)malloc(sizeof(s_info));
    msg->pid=getpid();
    msg->uid=getuid();
    msg->gid=getgid();
   while (1){
    msg->tm =time(NULL);

    err=msgsnd(msgid, msg,sizeof(s_info),0 );

sleep(1);
msgrcv(msgid, msg,sizeof(s_info),0,IPC_NOWAIT );

}
    return 0;
}
