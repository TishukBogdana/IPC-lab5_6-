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
#include <signal.h>
int con_fd;
void segv_handler(){
printf("use");
close(con_fd);
return;

}

int main()
{
    int  res, i, num, len =0;
    struct sockaddr_in serv_addr;
signal(SIGSEGV, segv_handler);
    char * resv;
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
      buf=(char*) malloc(len*sizeof(char));
      resv = (char *)malloc(len*sizeof(char));
      read(con_fd, buf, len);
     for(i=0;i<num;i++){
      strcpy(resv, buf);
      strtok(resv, "_");
     write(1, resv, strlen(resv) );
     write(1, "\n", strlen("\n") );
     //удивительный костыль
      send_data(resv, con_fd);
      buf = buf+strlen(resv)+1;
      }
      sprintf(buf, "%d", strlen("/"));
 write(con_fd, buf, 5);
      write(con_fd, "/", strlen("/") );
}

}
return 0;
}
void send_data(char * dirname, int con_fd){

   char * len = (char*) malloc(sizeof(char)*5);
   struct dirent * entry;

   DIR * dir  = opendir (dirname);

   if(dir==NULL){

   perror("");
   return;
   }
   sprintf(len, "%d", strlen(dirname));
  write(con_fd, len, 5);

   write(con_fd, dirname, strlen(dirname) );

  do{
  entry = readdir(dir);
 if(entry) {
 sprintf(len, "%d", strlen(entry->d_name));
 write(con_fd, len, 5);
 write(con_fd, entry->d_name, strlen(entry->d_name));
 }
  }while(entry);
  closedir(dir);
  return;
 }
 ///todo: try with get_data, error handle


