#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include <semaphore.h>
#include "header.h"
sem_t* sem;
int main()
{
int i=0;
pthread_t thread_inv;
pthread_t thread_rev;
    char array[26] = {0};
    char init='a';
     sem = (sem_t*) malloc(sizeof(sem_t));
    sem_init(sem, 0, 0);
    for(i=0;i<26;i++){
    array[i]=init;
    init++;
    }
while(1){

pthread_create(&thread_inv, NULL , thread_inverse, array);
  sem_wait(sem);
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
