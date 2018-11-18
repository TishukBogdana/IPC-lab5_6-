#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include "header.h"
#include <synch.h>

 pthread_rwlock_t rwlock=PTHREAD_RWLOCK_INITIALIZER;

int main()
{
int i=0;
pthread_t thread_inv;
pthread_t thread_rev;
    char array[26] = {0};
    char init='a';
int x=pthread_rwlock_init(&rwlock, NULL);
    for(i=0;i<26;i++){
    array[i]=init;
    init++;
    }


while(1){

pthread_create(&thread_inv, NULL , thread_inverse, array);
usleep(500000);
  print_arr(array, 26);


 pthread_create(&thread_rev, NULL , thread_reverse, array);
  
 usleep(500000);
  print_arr(array, 26);


  }
    return 0;
}
void * thread_reverse(char* array){
pthread_rwlock_wrlock(&rwlock);
reverse(array);
pthread_rwlock_unlock(&rwlock);
pthread_exit(0);
return NULL;
}
void * thread_inverse(char* array){
pthread_rwlock_wrlock(&rwlock);
inverse(array);
pthread_rwlock_unlock(&rwlock);
pthread_exit(0);
return NULL;
}

void print_arr(const char * arr, int size){
pthread_rwlock_wrlock(&rwlock);
int i=0;
for(i=0;i<size;i++){
printf("%c", arr[i]);
}
 pthread_rwlock_unlock(&rwlock);
printf("\n");
}
