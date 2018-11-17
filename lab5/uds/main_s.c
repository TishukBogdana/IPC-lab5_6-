#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <signal.h>
int soc;
s_info info;
void sig_handler1(int num){
remove("abcdefghijklmn");
print_info();
 _exit(0);
}
void sig_handler(int num){
print_info();
}
int main()
{
struct sockaddr my_addr;

int check,n_soc;
char * s_data="abcdefghijklmn";
signal( SIGINT, sig_handler1);
signal( SIGHUP, sig_handler);
signal( SIGTERM, sig_handler);
signal( SIGUSR1, sig_handler);
signal( SIGUSR2, sig_handler);
// obtain info
info.pid=getpid();
if(info.pid ==-1){
perror("can't obtain pid");
 return EXIT_FAILURE;}

info.uid=getuid();
if(info.pid ==-1){
perror("can't obtain pid");
 return EXIT_FAILURE;}
info.gid=getgid();

if(info.pid ==-1){
perror("can't obtain pid");
 return EXIT_FAILURE;}
 //prepare structs for socket
my_addr.sa_family=AF_UNIX;
strncpy(my_addr.sa_data, s_data, strlen(s_data));
soc = socket(AF_UNIX, SOCK_STREAM,0);
if(soc==-1){
perror("can't obtain socket");
return EXIT_FAILURE;
}
check = bind(soc, &my_addr, sizeof (struct sockaddr));
if(check==-1){
perror("can't bind socket");
return EXIT_FAILURE;
}
//listening requests from clients
while(1){
check = listen(soc, 10);
if(check==-1){
perror("can't listen socket");
return EXIT_FAILURE;
}
char data[14];
n_soc=accept(soc, NULL, NULL);
if(n_soc==-1){
perror("can't accept socket");
return EXIT_FAILURE;
}
info.tm=time(NULL);
getloadavg(info.load,3);
check=send(n_soc, &info, sizeof(s_info), 0);
if(check==-1){perror("");
return EXIT_FAILURE;}
}


    return 0;
}
void print_info(){
printf("SERVER_INFO:\n PID: %d \t UID: %d \t GID: %d \t\n TIME %s", info.pid, info.uid, info.gid, ctime(&info.tm));
 printf("LOAD:\t%f\t%f\t%f,", info.load[0], info.load[1],info.load[2]);
}
