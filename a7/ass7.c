#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int fd,fd1;
	char fname[20],buf[100];
	printf("WRITE FILE ::  ");
	scanf("%s",fname);
	char str[]="rm ";
	strcat(str,fname);
	system(str);
	
	char str1[]="touch ";
	strcat(str1,fname);
	system(str1);
	
	fd=open(fname,O_WRONLY);
	printf("ENter the data to write in file :: ");
	scanf("%s",buf);
	write(fd,buf,strlen(buf));
	close(fd);
	
	printf("READ FILE ::  ");
	scanf("%s",fname);
	fd1=open(fname,O_RDONLY);
	if(fd1!=3)
	{
		printf("FILE DOESN'T EXIXTS\n");
		exit(0);
	}
	read(fd,buf,sizeof(buf));
	printf("\n------------CONTENTS IN FILE-----------\n");
	printf("%s\n",buf);
}

