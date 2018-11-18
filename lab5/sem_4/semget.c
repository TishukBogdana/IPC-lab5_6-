#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/sem.h>
#include "header.h"
#include "sem_sys_v.h"
#include <errno.h>

sem_buf * s_buf, * s_buf_dec;
int semid;

int main()
{
int i, ctl=0;
key_t key =1;
pthread_t thread_inv;
pthread_t thread_rev;
char array[26] = {0};
char init='a';

//initializing structs for sem operations
s_buf = (sem_buf*)malloc(sizeof(sem_buf));
s_buf_dec = (sem_buf*)malloc(sizeof(sem_buf));

s_buf->sem_num=0;
s_buf->sem_op=1;
s_buf->sem_flg=0;

s_buf_dec->sem_num=0;
s_buf_dec->sem_op=-1;
s_buf_dec->sem_flg=0;

// obtain group of semaphores
semid = semget(key, 1, IPC_CREAT|0666);
if (semid ==-1){
perror("can't obtain semaphore group");
return EXIT_FAILURE;
}
    for(i=0;i<26;i++){
    array[i]=init;
    init++;
    }
//init begin value of 1_st semaphore
 ctl = semctl(semid,0,SETVAL,0);
 if (ctl ==-1){
perror("ctl error");
return EXIT_FAILURE;
}
  
while(1){
pthread_create(&thread_inv, NULL , thread_inverse, array);
  print_arr(array, 26);
 sleep(1);
 pthread_create(&thread_rev, NULL , thread_reverse, array);
  print_arr(array, 26);
 sleep(1);
  }
    return 0;
}

//reverce array procedure
void * thread_reverse(char* array){
int ch;
reverse(array);
ch=semop(semid,s_buf,1);
if(ch==-1){
perror("");
return ;
}
}

//inverse register procedure
void * thread_inverse(char* array){
int ch;
inverse(array);
ch=semop(semid,s_buf,1);
if(ch==-1){
perror("");
return ;
}
}

//print result procedure
void print_arr(const char * arr, int size){
int ch,i=0;
ch=semop(semid,s_buf_dec,1);
if(ch==-1){
perror("");
return ;
}
for(i=0;i<size;i++){
printf("%c", arr[i]);
}
printf("\n");
return;
}
