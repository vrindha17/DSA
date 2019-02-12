#include<stdio.h>
#include<stdlib.h>

int *q,front=-1,rear=-1,empty=0,n;

void enqueue(int a);
void dequeue();
void print();

int main()
{int a;
scanf("%d",&n);
	q=malloc(n*sizeof(q));
	char ch;
do{
	scanf("%c",&ch);
	if(ch=='s')
        return 0;
	if(ch=='e'||ch=='E')
	{
	scanf("%d",&a);
	enqueue(a);
	}

	else if(ch=='d'||ch=='D')
	{
	dequeue();
	}

	else if(ch=='p'||ch=='P')
	{
	print();
	}

  }while(ch!='s'||ch!='S');
	free(q);
	return 0;
}

void enqueue(int a)
{
	if(front==-1 && rear==-1)
		{
		front=0;
		rear=0;
		q[0]=a;
		}
	else if(front==0 && rear==n-1)
		{
		printf("%d\n",-2);
		return;
		}

	else if(front==rear+1)
		{
		printf("%d\n",-2);
		return;
		}
	else if(rear==n-1)
		{
		rear=0;
		q[rear]=a;
		return;
		}	

	else 
		{
		
		rear++;
		q[rear]=a;
		return;
		}	

}


void dequeue()
{
	if(front==-1 && rear==-1)
		{
		printf("-1\n");
		return;
		}
	else if(front==rear)
		{printf("%d\n",q[front]);
		front=rear=-1;
		return;
		}
	else if(front==n-1)
		{printf("%d\n",q[front]);
		front=0;
		return;		
		}
	else
		{printf("%d\n",q[front]);
		front++;
		return;		
		}
}

void print()
{	int i;
	if (front==-1 && rear==-1)
	{
	printf("%d\n",-1);
		return;
	}
	if(front<=rear)
		{for(i=front;i<=rear;i++)	
			printf("%d ",q[i]);
		printf("\n");
		return;}
	for(i=front;i<n;i++)
		printf("%d ",q[i]);
	
	for(i=0;i<=rear;i++)
		printf("%d ",q[i]);
printf("\n");
return;
		

}
