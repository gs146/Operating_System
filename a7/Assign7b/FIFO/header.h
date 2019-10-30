#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

#define fifo2 "/tmp/ser_fifo"
#define fifo1 "/tmp/clt_fifo"
#define __size 10000

typedef struct Exchange_data
{
	pid_t pid;
	char data[__size];
}Exchange_data;
