#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;

};

	struct node *save=NULL,*prev=NULL;
	struct node *N=NULL;
	struct node *head=NULL;
	struct node *tail=NULL;
	struct node *newptr=NULL;
	struct node *num1=NULL;
	struct node *num2=NULL;
	struct node *num1end=NULL;
	struct node *num2end=NULL;
	struct node *after=NULL;
	struct node *before=NULL;

int ctr=0,borrowed=0,first=0;
struct node* createnode(int a);
void insert(struct node *ptr);
void display(struct node *ptr);
void difference_of_digits(struct node *num1,struct node *num2);
void greater(struct node *num1,struct node *num2);
void reverse(struct node *ptr);
void displaynew(struct node *ptr);

int main()
{
	char ch;
	ch=getchar();
	while(ch!='\n')
	{
		newptr=createnode(ch-'0');
		insert(newptr);
		ch=getchar();

	}
	num1=head;
	num1end=tail;
	head=NULL;
	tail=NULL;



	ch=getchar();
	while(ch!='\n')
	{
		newptr=createnode(ch-'0');
		
		insert(newptr);
		ch=getchar();

	}

	num2=head;
	num2end=tail;
	head=NULL;
	tail=NULL;
difference_of_digits(num1,num2);

return 0;}

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

	if(head==NULL &&tail==NULL)
		head=tail=ptr;
	else 
		{tail->next=ptr;
		tail=ptr;}


}


void display(struct node *ptr)
{
	while(ptr!=NULL)
		{
		printf("%d",ptr->data);
		ptr=ptr->next;
	
		}
	return;

}

void difference_of_digits(struct node *num1,struct node *num2)
{
	if(first==0)
	{first=1;
	
	greater(num1,num2);  //assigns value of ctr as 0 if equal ,1 if num1>num2 and 2 if num2>num1


		head=NULL;
		tail=NULL;

	head=num1;
	reverse(num1);
	num1=head;
	num1end=tail;


		head=NULL;
		tail=NULL;

	head=num2;
	reverse(num2);
	num2=head;
	num2end=tail;

		head=NULL;
		tail=NULL;

	difference_of_digits(num1,num2);

			if(ctr==1)
			{head=num1;
			reverse(num1);
			num1=head;
			displaynew(num1);}

			if(ctr==2)
			{head=num2;
			reverse(num2);
			num2=head;
			displaynew(num2);}
	if(ctr==0)
	  printf("0");
	return ;



	}

	else if(num1==NULL && num2==NULL)
		return	;
	
	else if(ctr==0)
		{num1->data=0;
		num2->data=0;
		num1->next=NULL;
		num2->next=NULL;
		return;}
	
	else if(ctr==1)
		{if(borrowed==1)
			num1->data-=1;
		num1->data-=num2->data;
		if(num1->data < 0)
			{num1->data+=10;
			borrowed=1;
			}
		else borrowed=0;
		difference_of_digits(num1->next,num2->next);
		}

	else if(ctr==2)
		{if(borrowed==1)
			num2->data-=1;
		num2->data-=num1->data;
		if(num2->data < 0)
			{num2->data+=10;
			borrowed=1;
			}
		else
			borrowed=0;
		difference_of_digits(num1->next,num2->next);
		}
////////////////////////////////////////////////////
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

void greater(struct node *num1,struct node *num2)
{

	if(num1==NULL && num2==NULL)
		return;
	else if(num1->data > num2->data)
		ctr=1;


	else if(num1->data < num2->data)
		ctr=2;
	
	else
		greater(num1->next,num2->next);
}

void displaynew(struct node *ptr)
{int start=1;
	while(ptr!=NULL)
	{
	if(ptr->data==0 &&start==1)
		{ ptr=ptr->next;
			continue;	
                    }
	else
		{
		printf("%d",ptr->data);
		  start=0;
		ptr=ptr->next;
		}
	}

}

