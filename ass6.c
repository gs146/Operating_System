#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t c[5];

void *eating(void *arg)
{
	int j=(int)arg;
	
	
	printf("\n%d is hungry\n",j);
	
	sem_wait(&c[j]);
	sem_wait(&c[(j+1)%5]);
	printf("\n%d is starting eating \n",j);
	sleep(1);
	
	printf("\n%d completed eating\n",j);
	
	sem_post(&c[(j+1)%5]);
	sem_post(&c[j]);
	sleep(1);
}

int main()
{
	pthread_t p[5];
	for(int i=0;i<5;i++)
		sem_init(&c[i],0,1);
	
	for(int i=0;i<5;i++)
		pthread_create(&p[i],NULL,eating,(void *)i);
		
	
	for(int i=0;i<5;i++)
		pthread_join(p[i],NULL);
		
	
}

