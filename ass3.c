#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int m,n,p,q,sum;
int c[10][10],a[10][10],b[10][10];
typedef struct pk
{
	int i,j;
}pk;
void * multi(void *par)
{
	pk *data=par;
	sum=0;
	for(int k=0;k<n;k++)
	{
		sum+=(a[data->i][k]*b[k][data->j]);
	}
	c[data->i][data->j]=sum;
	return NULL;
}

int main()
{
	pthread_t t1;
	
	printf("Enter the size of the first matrix :: ");
	scanf("%d%d",&m,&n);
	printf("Enter the size of the second matrix :: ");
	scanf("%d%d",&p,&q);
	if(n!=p)
		printf("MULTIPLICATION is not possible\n");
	
	printf("Enter the first matrix\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("Enter the second matrix\n");
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
			scanf("%d",&b[i][j]);
	}
	for(int i=0;i<m;i++)
	{
		
		for(int j=0;j<q;j++)
		{
			pk *p=(pk *)malloc(sizeof(pk));
			p->i=i;
			p->j=j;
			pthread_create(&t1,NULL,multi,p);
			pthread_join(t1,NULL);
		}
		
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<q;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
}
