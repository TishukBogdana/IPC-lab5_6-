#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
int i=0;
    char array[26] = {0};
    char init='a';
    for(i=0;i<26;i++){
    array[i]=init;
    init++;
    }
    thread_inverse(array, 26);
    thread_reverse(array, 26);
    return 0;
}

void thread_inverse( char * array, int size){
int i=0;
if(array[i]=='a'){
for(i=0;i<size;i++){
array[i]-=32;
}
}

if(array[i]=='A'){
for(i=0;i<size;i++){
array[i]+=32;
}
}

}

void thread_reverse(char * array, int size){
int i=0;
char tmp;
for(i=0;i<size/2;i++){
tmp = array[i];
array[i] = array[size-1-i];
array[size-1-i]=tmp;

}


}


