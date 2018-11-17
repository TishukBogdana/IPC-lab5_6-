#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED
#include <time.h>
struct server_info{
int pid;
int uid;
int gid;
 time_t tm;
 double load[3];
};
typedef struct server_info s_info;

#endif // STRUCTS_H_INCLUDED
