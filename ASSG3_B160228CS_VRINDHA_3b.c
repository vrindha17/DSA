#include<stdio.h>
#include<stdlib.h>
int *q;
struct queue
{
	int data;
	struct queue *next;

};

struct queue *front=NULL,*rear=NULL,*ptr=NULL,*newptr=NULL;

struct queue* createnode(int a);
void enqueue(struct queue *ptr);
void dequeue();
void print();

int main()
{

	q=malloc(sizeof(struct queue));
	int a;
	char ch;
scanf("%c",&ch);
do{
	
	if(ch=='s')
        return 0;

	if(ch=='e'||ch=='E')
	{
	scanf("%d",&a);
	newptr=createnode(a);
	enqueue(newptr);
	}

	else if(ch=='d'||ch=='D')
	{
	dequeue();
	}

	else if(ch=='p'||ch=='P')
	{
	print(front);
	}

	scanf("%c",&ch);
  }while(ch!='s'||ch!='S');
	free(q);
	return 0;

return 0;
}


struct queue* createnode(int a)
{
	struct queue *N=(struct queue*)malloc(sizeof(struct queue*));
	if(N==NULL)
	      {	printf("ERROR");
		return NULL;}
	N->data=a;
	N->next=NULL;
	return N;
}

void enqueue(struct queue *ptr)
{
	if(front==NULL&&rear==NULL)
		{

		front=ptr;
		 rear=ptr;
		 return;}
		
	rear->next=ptr;
	rear=ptr;

}


void dequeue(struct queue *ptr)
{	
	if(front==NULL)
		{
		printf("-1\n");
		rear=NULL;
		 return;}
	if (front==rear)
		{printf("%d\n",front->data);
		front=NULL;
		rear=NULL;
		}
	printf("%d\n",front->data);	
	front=front->next;

}

void print(struct queue *ptr)
{
	if(ptr==NULL)
		{
		printf("-1\n");
		return;
		}		
	
	while(ptr!=NULL)
		{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	
		}
        printf("\n");
	return;

}

