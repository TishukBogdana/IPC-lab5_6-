
#include <stdlib.h>


void inverse( char * array){
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
return;
}
