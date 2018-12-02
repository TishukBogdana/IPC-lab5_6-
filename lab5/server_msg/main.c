#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>
//#include <sys/getloadavg.h>
int main()
{
    struct msqid_ds queue;
    key_t key = 2;
    s_info * msg;
    int msgid;
    int err;

    msgid=msgget(key, IPC_CREAT|0666);
    if(msgid==-1){
    perror("can't get message queue");
    return EXIT_FAILURE;
    }
    msg=(s_info*)malloc(sizeof(s_info));
    msg->pid=getpid();
    if(msg->pid ==-1){
perror("can't get pid");
return EXIT_FAILURE;
}
    msg->uid=getuid();
    if(msg->uid ==-1){
perror("can't get uid");
return EXIT_FAILURE;
}
msgctl(msgid,IPC_STAT,&queue);
queue.msg_qbytes = sizeof(msg);
msgctl(msgid,IPC_SET,&queue);


    msg->gid=getgid();
    if(msg->gid ==-1){
perror("can't get gid");
return EXIT_FAILURE;
}

   while (1){
    msg->tm =time(NULL);
    getloadavg(msg->load, 3);
    err=msgsnd(msgid, msg,sizeof(s_info),0);
if(err==-1){perror("can't send message");}
sleep(1);
//msgrcv(msgid, msg,sizeof(s_info),0,IPC_NOWAIT );

}
    return EXIT_SUCCESS;
}
