#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>



int main(int argc, char * argv[])
{


 int sock_fd, i, len=0;

    char  buf[5];
    char * resv ;
     struct sockaddr_in cli_addr;
   cli_addr.sin_family=AF_INET;
    cli_addr.sin_addr.s_addr=INADDR_ANY;
    cli_addr.sin_port=htons(2222);

     //calculate length of message
     for(i=2;i<argc;i++){
     len += strlen(argv[i])+1;
     }
     sprintf(buf,"%d",len);
     sock_fd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
     if(sock_fd==-1){perror("can't open socket");}
     if(connect(sock_fd,(struct sockaddr*)&cli_addr, sizeof(cli_addr))==-1){
     perror("can't access server");
}

     write(sock_fd, buf, 5);
     sprintf(buf,"%d",argc-2);
     write(sock_fd, buf, 5);
     for(i=2;i<argc;i++){
     write(sock_fd, argv[i], strlen(argv[i]));
     write(sock_fd, " ", strlen(" "));
     }
while(1){

 read(sock_fd, buf, 5);
len = atoi(buf);
resv= (char* )malloc(len*sizeof(char));
read(sock_fd, resv, len);
if(!strcmp(resv,"/")) break;
write(1, resv, len);
write(1, "\n", strlen("\n"));
}
return 0;
}
