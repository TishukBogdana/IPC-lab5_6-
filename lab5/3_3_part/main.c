#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
char * string ="hello\n";
int pid, pipe_;
int fd, ch, ch2;
int pipefd[2];
char * arr = (char * ) malloc(sizeof(char));
if(argc<2){
printf("enter a filename");
return EXIT_FAILURE;
}
fd=open(argv[1],0666);
if(fd==-1){
perror(argv[1]);
return EXIT_FAILURE;
}
pipe_ = pipe(pipefd);
pid = fork();
if(pipe==-1){
perror("");
return EXIT_FAILURE;}
if(pid<0){
perror("");
return EXIT_FAILURE;
}
if(pid==0){
close(pipefd[1]);
ch2=dup2(pipefd[0],0);
if(ch2==-1){
perror("");
return EXIT_FAILURE;}
execlp("/usr/bin/wc","wc", "-c", NULL);
wait(NULL);
exit(0);

}
else{
close(pipefd[0]);

ch =1;

while(ch){

 ch=read(fd,arr,1);
 ch=read(fd,arr,1);
 write(pipefd[1],arr,1);
}

}
return 0;
}


