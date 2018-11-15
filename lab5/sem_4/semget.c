#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/sem.h>
#include "header.h"
#include "sem_sys_v.h"
#include <errno.h>
int main()
{
int semid,i=0;
key_t key =1;
pthread_t thread_inv;
pthread_t thread_rev;
char array[26] = {0};
char init='a';
sem_buf * s_buf = (sem_buf*)malloc(sizeof(sem_buf));
s_buf->sem_num=0;
s_buf->sem_op=1;
s_buf->sem_flg=0;
semid = semget(key, 1, IPC_CREAT|0666);

    for(i=0;i<26;i++){
    array[i]=init;
    init++;
    }


while(1){

pthread_create(&thread_inv, NULL , thread_inverse, array);

  print_arr(array, 26);
 sleep(1);
 pthread_create(&thread_rev, NULL , thread_reverse, array);
  sem_wait(sem);
  print_arr(array, 26);
 sleep(1);
  }
    return 0;
}




void print_arr(const char * arr, int size){
int i=0;
for(i=0;i<size;i++){
printf("%c", arr[i]);
}
printf("\n");
}
