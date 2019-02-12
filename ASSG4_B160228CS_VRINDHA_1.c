#include<stdio.h>
#include<stdlib.h>

int h1(int x);
int h2(int x);
int isprime(int i);


void linear();
void quadratic();
void doublehashing();
void chaining();

void insertlinear();
void deletelinear();
void printlinear();
void searchlinear();

void insertquadratic();
void deletequadratic();
void printquadratic();
void searchquadratic();

void insertdoublehashing();
void deletedoublehashing();
void printdoublehashing();
void searchdoublehashing();

void insertchaining();
void deletechaining();
void printchaining();
void searchchaining();

struct node
{
	int key;
	struct node *next;
};

struct pointers
{
	struct node *head,*tail;
};

int m;
int *a=NULL;
struct pointers *b=NULL;


struct node* createnode(int x);


int main()
{	int i;
	char ch;
	scanf("%c",&ch);
	scanf("%d",&m);
	a=(int*)malloc(m*sizeof(int));
	b=(struct pointers*)malloc(m*sizeof(struct pointers));


	for(i=0;i<m;i++)
	{	
	b[i].head=NULL;
	b[i].tail=NULL;

	}
	for(i=0;i<m;i++)
	{
	a[i]=-1;
	}
	
	if(ch=='a')
		linear();
	else if(ch=='b')
		quadratic();
	else if(ch=='c')
		doublehashing();
	else 
		chaining();
free(a);
free(b);
return 0;
}




int h1(int x)
	{return x%m;}

int h2(int x)
	{int r,i;
	for(i=m-1;i>1;i--)
 	{if(isprime(i))
		{r=i;
		break;}
 	} 

	return r-(x%r);
	}

int isprime(int i)
	{int j;
	for(j=2;j<i;j++)
		if(i%j==0)
			break;	
	
	if(j==i)
 		return 1;

	else
   		return 0;
}


void linear()
{	int x;
	char choice;

	do{	scanf("%c",&choice);
		if(choice=='t')
			return;
		else if(choice=='i')
			{scanf("%d",&x);
                          insertlinear(x);}	
		else if(choice=='s')
			{scanf("%d",&x);
			searchlinear(x);}
		else if(choice=='d')
			{scanf("%d",&x);
			deletelinear(x);}
		else if(choice=='p')
			printlinear();		
		}while(choice!='t');
}	

void quadratic()
{

	char choice;
	
	int x;
	do
	{	scanf("%c",&choice);
		if(choice=='t')
			return;
		else if(choice=='i')
			{scanf("%d",&x);
			insertquadratic(x);}
		else if(choice=='s')
			{scanf("%d",&x);
			searchquadratic(x);}
		else if(choice=='d')
			{scanf("%d",&x);
			deletequadratic(x);}	
		else if(choice=='p')
			printquadratic();		
		
	}while(choice!='t');


}
void doublehashing()
{
	char choice;
	int x;
	do
	{	scanf("%c",&choice);
		if(choice=='t')
			return;
		else if(choice=='i')
			{scanf("%d",&x);
			insertdoublehashing(x);}
		else if(choice=='s')
			{scanf("%d",&x);
			searchdoublehashing(x);}
		else if(choice=='d')
			{scanf("%d",&x);
			deletedoublehashing(x);}	
		else if(choice=='p')
			printdoublehashing();		
		
	}while(choice!='t');


}
void chaining()
{

	char choice;
	int x;

	do
	{scanf("%c",&choice);
		if(choice=='t')
			return;
		else if(choice=='i')
			{scanf("%d",&x);
			insertchaining(x);}
		else if(choice=='s')
			{scanf("%d",&x);
			searchchaining(x);}
		else if(choice=='d')
			{scanf("%d",&x);
			deletechaining(x);}	
		else if(choice=='p')
			printchaining();		
		
	}while(choice!='t');


}




void insertlinear(int x)
{	int h,i=0;
	while(1)
	{
	h=(h1(x)+i)%m;
	if(a[h]==-1||a[h]==-2)
		{a[h]=x;
		return;}
	i++;}	
}


void deletelinear(int x)
{
	int h,i=0;
	while(1)
	{
	h=(h1(x)+i)%m;
	if(a[h]==x)
		{a[h]=-2;
		return;}
	i++;}
	

}
void printlinear()
{
	for(int i=0;i<m;i++)
	{if(a[i]==-1||a[i]==-2)
	  printf("%d ()\n",i);		
	else 
          printf("%d (%d)\n",i,a[i]);	
	}
}
void searchlinear(int x)
{


	int h,i=0;
	while(i<m)
	{
	h=(h1(x)+i)%m;
	if(a[h]==x)
		{printf("1\n");
		return;}
	if(a[h]==-1)
		{printf("-1\n");
		return;}
		
	i++;}
	printf("-1\n");

}

void insertquadratic(int x)
{
int h,i=0;
	while(1)
	{
	h=(h1(x)+(i*i))%m;
	if(a[h]==-1||a[h]==-2)
		{a[h]=x;
		return;}
	i++;}

}
void deletequadratic(int x)
{

	int h,i=0;
	while(1)
	{
	h=(h1(x)+(i*i))%m;
	if(a[h]==x)
		{a[h]=-2;
		return;}
	i++;}

}
void printquadratic()
{

	for(int i=0;i<m;i++)
	{if(a[i]==-1||a[i]==-2)
	  printf("%d ()\n",i);		
	else 
          printf("%d (%d)\n",i,a[i]);	
	}
}
void searchquadratic(int x)
{

	int h,i=0,ctr=0;
	while(i<m)
	{h=(h1(x)+(i*i))%m;
	if(a[h]==x)
		{printf("1\n");
		return;}
	if(a[h]==-1)
		{printf("-1\n");
		return;}
		
	i++;}
printf("-1\n");

}

void insertdoublehashing(int x)
{

int h,i=0;
	while(1)
	{
	h=(h1(x)+(i*h2(x)))%m;
	if(a[h]==-1||a[h]==-2)
		{a[h]=x;
		return;}
	i++;}

}
void deletedoublehashing(int x)
{

	int h,i=0;
	while(1)
	{
	h=(h1(x)+(i*h2(x)))%m;
	if(a[h]==x)
		{a[h]=-2;
		return;}
	i++;}

}
void printdoublehashing()
{

	for(int i=0;i<m;i++)
	{if(a[i]==-1||a[i]==-2)
	  printf("%d ()\n",i);		
	else 
          printf("%d (%d)\n",i,a[i]);	
	}

}
void searchdoublehashing(int x)
{

	int h,i=0;
	while(i<m)
	{
	h=(h1(x)+(i*h2(x)))%m;
	if(a[h]==x)
		{printf("1\n");
		return;}
	if(a[h]==-1)
		{printf("-1\n");
		return;}
		
	i++;}

}

struct node* createnode(int x)
{
	struct node *ptr=malloc(sizeof(struct node));
	ptr->key=x;
	ptr->next=NULL;

	return ptr;

}

void insertchaining(int x)
{
	int h=x%m;
	struct node *newptr=(struct node*)malloc(sizeof(struct node));
	newptr->key=x;
	newptr->next=NULL;

	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr=(struct node*)b[h].head;


	if(ptr==NULL)
	{
	b[h].head=newptr;
	b[h].tail=newptr;
	return;
	}
	
	

	b[h].tail->next=newptr;
	b[h].tail=newptr;


}
void deletechaining(int x)
{

	int h=x%m;
	struct node *ptr=NULL,*prev=NULL;
	ptr=b[h].head;
	
	
	if(ptr->key==x)
	{if(ptr==b[h].head&&ptr==b[h].tail)
		{
		b[h].head=NULL;
		b[h].tail=NULL;
		}
	b[h].head=ptr->next;
	return;
	}
	
	while(ptr!=NULL)
	{
	if(x==ptr->key)
		break;
	prev=ptr;
	ptr=ptr->next;
	}

prev->next=ptr->next;
if(ptr==b[h].tail)
  b[h].tail=prev;

return;

}
void printchaining()
{int i;
struct node *ptr=NULL;	
int ctr=0;
	for(i=0;i<m;i++)
	{	ctr=0;    
		 printf("%d (",i);

		ptr=b[i].head;
		
		while(ptr!=NULL)
		{
		if(ctr!=0)
			printf(" ");
		
		printf("%d",ptr->key);
		ptr=ptr->next;	
		ctr=1;	
		}
	printf(")\n");
	}
}
void searchchaining(int x)
{
	int h=x%m;
	struct node *ptr=NULL;
	ptr=b[h].head;

	while(ptr!=NULL)
	{
	if(x==ptr->key)
	{printf("1\n");return;
	}	
	ptr=ptr->next;

	}
printf("-1\n");
return;


}
