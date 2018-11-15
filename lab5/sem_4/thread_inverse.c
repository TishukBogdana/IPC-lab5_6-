#include <semaphore.h>
#include <stdlib.h>
extern sem;

void * thread_inverse( char * array){
int i=0;
if((array[i]=='a')||(array[i]=='z')){
for(i=0;i<26;i++){
array[i]-=32;
}
}

if((array[i]=='A')||(array[i]=='Z')){
for(i=0;i<26;i++){
array[i]+=32;
}
}
sem_post(sem);

return NULL;
}
