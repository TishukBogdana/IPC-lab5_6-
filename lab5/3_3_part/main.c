#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(char * argv[])
{
char * string ="hello\n";
int pid, pipe_;
int pipefd[2];
char arr[70];

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
dup2(pipefd[0],0);
execlp("/usr/bin/wc","wc", NULL);
wait(NULL);
exit(0);

}
else{
close(pipefd[0]);

write(pipefd[1],string, strlen(string)+1);

}
}


