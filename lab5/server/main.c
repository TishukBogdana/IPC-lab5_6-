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

    key_t key=5648;
    int shmid;

    //get shared segment
   shmid=shmget(key,sizeof(s_info), IPC_CREAT|0666);
    if(sh==-1){
   perror("can't get shared memory id");
   return EXIT_FAILURE;
   }
   sh = (s_info *) shmat(shmid,NULL,0);
    if(sh==-1){
   perror("can't share memory");
   return EXIT_FAILURE;
   }
//make a structure of data
sh->pid = getpid();
if(sh->pid ==-1){
perror("can't get pid");
return EXIT_FAILURE;
}
sh->uid= getuid();
if(sh->uid ==-1){
perror("can't get uid");
return EXIT_FAILURE;
}
 sh->gid = getgid();
 if(sh->gid ==-1){
perror("can't get gid");
return EXIT_FAILURE;
}
//signal handling
signal( SIGINT, sig_handler);

while (1){

sh->tm =time(NULL);
getloadavg(sh->load, 3);
sleep(1);
}
return EXIT_SUCCESS;
}

