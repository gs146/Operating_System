#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t s1,s2;
int buff[5];
pthread_mutex_t m;
void *producer()
{
	int i=0;
	while(1)
	{
		sem_wait(&s2);// check the value of s2 ,s2-- and if s2=0 then go inside (4 3 2 1 0 -1)
		pthread_mutex_lock(&m);
		buff[i++]=random()%10;
		printf("\n%d item is inserted at %d location",buff[i-1],i-1);
		pthread_mutex_unlock(&m);
		sem_post(&s1); //s1++
		if(i==5)i=0;
		sleep(1);
	}
}

void *consumer()
{
	int i=0,key;
	while(1)
	{
		sem_wait(&s1); // check the value of s1 ,s1-- and if s1=0 then go inside
		pthread_mutex_lock(&m);
		key=buff[i++];
		printf("\n%d item is extracted from %d location",key,i-1);
		pthread_mutex_unlock(&m);
		sem_post(&s2); //s2++
		if(i==5)i=0;
		sleep(1);
	}
}

int main()
{
	pthread_t pid,cid;
	pthread_mutex_init(&m,NULL);
	sem_init(&s1,0,0); //s1=0
	sem_init(&s2,0,5);
	pthread_create(&pid,NULL,producer,NULL);
	pthread_create(&cid,NULL,consumer,NULL);
	pthread_join(pid,NULL);
	pthread_join(cid,NULL);
}
