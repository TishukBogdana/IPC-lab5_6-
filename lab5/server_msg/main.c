#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
///todo:error handle, synchro
int main()
{
    key_t key = 4568;

    s_info * msg;
    int msgid;
    int err;
    msgid=msgget(key, IPC_CREAT|0666);
    msg=(s_info*)malloc(sizeof(s_info));
    msg->pid=getpid();
    msg->uid=getuid();
    msg->gid=getgid();
   while (1){
    msg->tm =time(NULL);
    err=msgsnd(msgid, msg,sizeof(s_info),0 );
sleep(100);
msgrcv(msgid, msg,sizeof(s_info),0,0 );
}
    return 0;
}
