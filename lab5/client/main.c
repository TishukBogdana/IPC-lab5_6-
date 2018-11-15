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
    key_t key=5678;
    s_info * sh;
    int shmid;
    shmid=shmget(key, sizeof(s_info), 0444);

    sh=(s_info*)shmat(shmid, NULL, SHM_RDONLY);
     if(sh==-1){
   perror("can't share memory");
   return -1;
   }
    printf("SERVER INFO:\n PID: %d\t UID: %d \t GID : %d \n", sh->pid, sh->uid, sh->gid);
    printf("%s", ctime(&sh->tm));
    shmdt(sh);
    return 0;
}
