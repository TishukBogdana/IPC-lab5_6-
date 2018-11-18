
#include <stdlib.h>


void reverse(char * array){
int i=0;
char tmp;
for(i=0;i<13;i++){
tmp = array[i];
array[i] = array[25-i];
array[25-i]=tmp;

}

return ;

}

