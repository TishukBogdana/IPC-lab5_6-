#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>
#include "header.h"
pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;
int main()
{
int i=0;
pthread_t thread_inv;
pthread_t thread_rev;
    char array[26] = {0};
    char init='a';
    int x=pthread_mutex_init(&mutex, NULL);
    for(i=0;i<26;i++){
    array[i]=init;
    init++;
    }


while(1){

pthread_create(&thread_inv, NULL , thread_inverse, array);
pthread_mutex_lock(&mutex);
  print_arr(array, 26);
 pthread_mutex_unlock(&mutex);
 usleep(1000000);
 pthread_create(&thread_rev, NULL , thread_reverse, array);
  pthread_mutex_lock(&mutex);
  print_arr(array, 26);
 pthread_mutex_unlock(&mutex);
 usleep(1000000);

  }
    return 0;
}
void * thread_reverse(char* array){
pthread_mutex_lock(&mutex);
reverse(array);
pthread_mutex_unlock(&mutex);
pthread_exit(0);
return NULL;
}
void * thread_inverse(char* array){
pthread_mutex_lock(&mutex);
inverse(array);
pthread_mutex_unlock(&mutex);
pthread_exit(0);
return NULL;
}

void print_arr(const char * arr, int size){
int i=0;
for(i=0;i<size;i++){
printf("%c", arr[i]);
}
printf("\n");
}
