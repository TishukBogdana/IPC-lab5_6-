#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
int main()
{
    int con_fd, res, i, len =0;
    struct sockaddr_in serv_addr;
    char * token;
    char * buf = (char*) malloc(sizeof(int)) ;
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htons(INADDR_ANY);
    serv_addr.sin_port=htons(2222);
  int fd = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
  if(fd==-1){perror("can't obtain socket");}
  bind(fd , (struct sockaddr_in*)&serv_addr, sizeof(serv_addr));

  while(1){
     listen(fd, 10);
     con_fd=accept(fd, (struct sockaddr_in*)NULL,NULL);
     res = fork();
     if(res==0){
      read(con_fd, buf, 4);
      len = atoi(buf);
      buf=(char*)malloc(len);
      read(con_fd, buf, len);
      token = strtok(buf," ");
      while(token){
      send_data(token[i],con_fd);
      }
     }

  }


    return 0;
}
void send_data(char * dirname, int con_fd){
   struct dirent * entry;
   DIR * dir  = opendir (dirname);
   if(dir==NULL){
   perror("");
   }
  do{
  entry = readdir(dir);
 if(entry) write(con_fd, entry->d_name, strlen(entry->d_name));
  }while(entry);
  closedir(dir);
 }
 ///todo: try with get_data

