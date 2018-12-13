#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
    int con_fd, res, i, num, len =0;
    struct sockaddr_in serv_addr;


    char * buf = (char*) malloc(sizeof(char)*5);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=INADDR_ANY;
    serv_addr.sin_port=htons(2222);
  int fd = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);
  if(fd==-1){perror("can't obtain socket");}
  if(bind(fd , (struct sockaddr_in*)&serv_addr, sizeof(serv_addr))){
  perror("can't bind");
  }

  while(1){
     if(listen(fd, 10)==-1){
     perror("can't listen");};
     con_fd=accept(fd, NULL,NULL);
     if(con_fd==-1){perror("connect problem");}

     res = 0;
     if(res==0){
      read(con_fd, buf, 5);
      len = atoi(buf);
      read(con_fd, buf, 5);
      num = atoi(buf);
      buf=(char*) malloc(len);
      send_data(buf,con_fd);

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
 ///todo: try with get_data, error handle

char ** delim(){
   char * get,resv;
}
