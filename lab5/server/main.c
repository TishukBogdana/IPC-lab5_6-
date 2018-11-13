#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "structs.h"
//#include <sys/loadavg.h>
int main()
{
    time_t tm;
    key_t key=5678;
    int shmid;
    s_info * sh ;

  //FILE * f ;

   shmid=shmget(key,27, IPC_CREAT|0666);
   sh = (s_info *) shmat(shmid,NULL,0);
   // creat("data", 777 );
   // f=fopen("data","a");

  sh->pid = getpid();
 sh->uid= getuid();
 sh->gid = getgid();
   // fprintf(f, "PID: %d\tUID: %d\tGID: %d", pid,uid,gid);

while (1){
sh->tm =time(NULL);
sleep(1);
}
}
