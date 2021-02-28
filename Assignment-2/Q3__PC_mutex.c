#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,full=0,empty=3,x_data=0;
 
int main()
{
	int n;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((mutex==1)&&(empty!=0))
						producer();
					else
						printf("Buffer is full: Data Full");
					break;
			case 2:	if((mutex==1)&&(full!=0))
						consumer();
					else
						printf("Buffer is empty:No data");
					break;
			case 3:
					exit(0);
					break;
		}
	}
	
	return 0;
}
 
int wait(int s_int)
{
	return (--s_int);
}
 
int signal(int s_int)
{
	return(++s_int);
}
 
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x_data++;
	printf("\nProducer produces no of item %d",x_data);
	mutex=signal(mutex);
}
 
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\nConsumer consumes no of  item %d",x_data);
	x_data--;
	mutex=signal(mutex);
}