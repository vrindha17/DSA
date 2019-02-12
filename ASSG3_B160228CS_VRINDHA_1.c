#include<stdio.h>
#include<stdlib.h>

struct node
{	int data;
	struct node *next;
};


	struct node *N=NULL;
	struct node *head=NULL;
	struct node *tail=NULL;
	struct node *newptr=NULL;
	struct node *after=NULL;
	struct node *before=NULL;

struct node* createnode(int a);
void insert(struct node *ptr);
void display(struct node *ptr);
void reverse(struct node *ptr);
int ctr=0;
int main()
{
	int a;
	char ch;
  	while(ch!='\n')
		{scanf("%d",&a);
		ch=getchar();
		newptr=createnode(a);
		insert(newptr);}

reverse(head);

display(head);


	return 0;



}

struct node* createnode(int a)
{
	struct node *N=(struct node*)malloc(sizeof(struct node*));
	if(N==NULL)
	      {	printf("ERROR");
		return NULL;}
	N->data=a;
	N->next=NULL;
	return N;
}

void insert(struct node *ptr)
{
	if(head==NULL&&tail==NULL)
		{head=ptr;
		 tail=ptr;
		 return;}
		
	tail->next=ptr;
	tail=ptr;

}

void display(struct node *ptr)
{
	while(ptr!=NULL)
		{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	
		}
	return;

}

void reverse(struct node *ptr)
{
       if(ptr->next==NULL)
	{
	ptr->next=before;
	head=ptr;
	return;
	}

	if(ptr==head)
	{

	after=ptr->next;
	before=ptr;
	ptr->next=NULL;
	tail=ptr;
	}

  
	else
	{
	after=ptr->next;
	ptr->next=before;
	before=ptr;
	}
	
	reverse(after);

}


