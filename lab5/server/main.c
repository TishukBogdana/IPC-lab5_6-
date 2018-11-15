#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include "structs.h"
//#include <sys/loadavg.h>
 s_info * sh ;
void sig_handler(int num){
shmdt(sh);
printf("ok");
 exit(0);
}
int main()
{
///todo: sysload avg helios

    time_t tm;
    key_t key=5678;
    int shmid;



    //get shared segment
   shmid=shmget(key,sizeof(s_info), IPC_CREAT|0666);
   sh = (s_info *) shmat(shmid,NULL,0);
    if(sh==-1){
   perror("can't share memory");
   return 1;
   }
//make a structure of data
  sh->pid = getpid();
 sh->uid= getuid();
 sh->gid = getgid();
//signal handling

signal( SIGINT, sig_handler);

while (1){
sh->tm =time(NULL);
sleep(1);
}

}

