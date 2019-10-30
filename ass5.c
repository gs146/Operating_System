#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int rc=0;
sem_t m,s;

void *reader(void *arg)
{
	int j=(int)arg;
	
	printf("\n%d reader is created \n",j);
	sem_wait(&m);
	rc++;
	if(rc==1)
	sem_wait(&s);
	sem_post(&m);
	printf("\n%d reader is reading \n",j);
	sleep(1);
	sem_wait(&m);
	rc--;
	if(rc==0)
	sem_post(&s);
	sem_post(&m);
	printf("\n%d reader is completed \n",j);
}

void *writer(void *arg)
{
	int j=(int)arg;
	
	
	printf("\n%d writer is created \n",j);
	sem_wait(&s);
	printf("\n%d writer is writing \n",j);
	sleep(2);
	sem_post(&s);
	
	printf("\n%d writer is completed \n",j);
}
int main()
{
	pthread_t r[3],w[3];
	sem_init(&s,0,1); //s=1
	sem_init(&m,0,1);
	for(int i=0;i<3;i++)
	{
		pthread_create(&r[i],NULL,reader,(void *)i);
		sleep(1);
		pthread_create(&w[i],NULL,writer,(void *)i);
		sleep(1);
	}
	for(int i=0;i<3;i++)
	{
		pthread_join(r[i],NULL);
		pthread_join(w[i],NULL);
	}
}
