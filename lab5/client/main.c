#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main()
{
    key_t key=5648;
    s_info * sh;
    int shmid;
    shmid=shmget(key, sizeof(s_info), 0444);
 if(sh==-1){
   perror("can't get shared memory id");
   return EXIT_FAILURE;
   }
    sh=(s_info*)shmat(shmid, NULL, SHM_RDONLY);
     if(sh==-1){
   perror("can't share memory");
   return EXIT_FAILURE;
   }
    printf("SERVER INFO:\n PID: %d\t UID: %d \t GID : %d \n", sh->pid, sh->uid, sh->gid);
    printf("TIME:\t%s", ctime(&sh->tm));
    printf("LOAD:\t%f\t%f\t%f,", sh->load[0], sh->load[1],sh ->load[2]);
    shmdt(sh);
    return EXIT_SUCCESS;
}
