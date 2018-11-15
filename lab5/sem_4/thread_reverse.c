#include <semaphore.h>
#include <stdlib.h>
extern sem;

void * thread_reverse(char * array){
int i=0;
char tmp;
for(i=0;i<13;i++){
tmp = array[i];
array[i] = array[25-i];
array[25-i]=tmp;

}
sem_post(sem);

return NULL;

}

