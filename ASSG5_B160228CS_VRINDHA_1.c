#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct adjlist
{
	int val,dist;
	char colour[25];
	struct adjlist *next,*qnext;
};

struct pointers
{	struct adjlist *head,*tail;
	char colour[25];
}*array=NULL;

void push(int i);
int pop();
int v,ctr=0,stop=0,stack[10000],top=-1;
struct adjlist *queue=NULL,*front=NULL,*rear=NULL;
void print();
void dfs();
void bfs();
void insert(int index,int x);
void enqueue(struct adjlist *s);
struct adjlist* dequeue();
void changecolour(int x,char color[]);
void dfs_visit(int i,int key);
struct adjlist* find(int x);

int main()
{
	char ch,string[10];
	int i,x=0,ctr;

	scanf("%d",&v);
	ch=getchar();
	array=(struct pointers*)malloc(v*sizeof(struct pointers));
	queue=(struct adjlist*)malloc(10000*sizeof(struct adjlist));

	for(i=0;i<v;i++)
	{	array[i].head=NULL;
		array[i].tail=NULL;
		x=0;ctr=0;
		ch=getchar();
		while(ch!='\n')
		{	ctr=1;
			if(ch==' ')
			{insert(i,x);	
			x=0;
			}
			
		else x=x*10+ch-'0';
		ch=getchar();
		}
		if(ctr!=0)
		insert(i,x);
	}
		//printf("done insertion");

	do{//printf("enter string :");
	scanf("%s",string);
	if(strcmp(string,"stp")==0)
		return 0;

	if(strcmp(string,"dfs")==0)
		 	dfs();
	else if(strcmp(string,"bfs")==0)
		{	
			bfs();}

	printf("\n");
		}while(strcmp(string,"stp")!=0);
	

//print();
	return 0;
}

void insert(int index,int x)
{
	struct adjlist *temp=(struct adjlist*)malloc(sizeof(struct adjlist));
	temp->val=x;
	temp->dist=INT_MAX;
	strcpy(temp->colour,"white");
	temp->next=NULL;
	temp->qnext=NULL;
	

	if(array[index].head==NULL)
	{
		array[index].head=temp;
		array[index].tail=temp;
		return;
	}

	array[index].tail->next=temp;
	array[index].tail=temp;
	return;
}

void print()
{
	int i;
	for(i=0;i<v;i++)
	{	struct adjlist *ptr=(struct adjlist*)malloc(sizeof(struct adjlist));
		ptr=array[i].head;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->val);
			ptr=ptr->next;
		}
	printf("\n");
	}
}

void enqueue(struct adjlist *s)
{
	if(front==NULL&&rear==NULL)
		{	front=s;
			rear=s;
			return;
		}
	else
		{	rear->qnext=s;
			rear=s;
			
		}

}

struct adjlist* dequeue()
{
	if(front==rear)
		{struct adjlist *temp=front;
		front=rear=NULL;
		return temp;
		}
	else {struct adjlist *temp=front;
		front=front->qnext;
		return temp;
		}
}


struct adjlist* find(int x)
{
	int i;
	for(i=0;i<v;i++)
	{	struct adjlist *ptr=array[i].head;
		while(ptr!=NULL)
		{
			if(ptr->val==x)
				return ptr;
			ptr=ptr->next;
		}

	}
	return NULL;

}
void bfs()
{	int start,key;
	scanf("%d",&start);
	scanf("%d",&key);
	
	
	int i;
	for(i=0;i<v;i++)
	{	struct adjlist *ptr=array[i].head;
		
		while(ptr!=NULL)
		{
			changecolour(ptr->val,"white");//strcpy(ptr->colour,"white");
			ptr=ptr->next;
		}

	}


	if(start==key)
		{printf("%d ",start);
		 return;
		}

	struct adjlist *s=array[start].head;
	printf("%d ",start);

	changecolour(start,"gray");//strcpy(s->colour,"gray");

	if(key==s->val)
		return;

	changecolour(s->val,"gray");
	front=NULL;
	rear=NULL;

	struct adjlist *temp=s;
	while(temp!=NULL)
	{printf("%d ",temp->val);
	 if(temp->val==key)
		return;
	enqueue(temp);
	changecolour(temp->val,"gray");
	temp=temp->next;}

	while(front!=NULL || rear!=NULL)
	{
		struct adjlist *u=dequeue();
		struct adjlist *ptr=array[u->val].head;
		
		while(ptr!=NULL)
		{
			if(ptr->val==key)
				{	printf("%d ",key);
					return;}
			if(strcmp(ptr->colour,"white")==0)
				{	
					printf("%d ",ptr->val);
					changecolour(ptr->val,"gray");//strcpy(ptr->colour,"gray");
					enqueue(ptr);
				}
			ptr=ptr->next;
		}
		changecolour(u->val,"black");//strcpy(u->colour,"black");
	}
}


void dfs()
{	int i,start,key;
	top=-1;
	scanf("%d",&start);
	scanf("%d",&key);

	for(i=0;i<v;i++)
	{	struct adjlist *ptr=array[i].head;
		while(ptr!=NULL)
		{	changecolour(ptr->val,"white");//strcpy(ptr->colour,"white");
			ptr=ptr->next;
		}
	}

	if(start==key)
		{printf("%d",start);
		 return;
		}

	struct adjlist *s=array[start].head;
	changecolour(start,"gray");
	push(start);

	while(top!=-1)
	{
		int u=pop();
		printf("%d ",u);
		if(u==key)
			return;
		struct adjlist *ptr=array[u].head;
		
		while(ptr!=NULL)
		{	if(strcmp(ptr->colour,"white")==0)
				{	changecolour(ptr->val,"gray");
					push(ptr->val);
				}
			ptr=ptr->next;
		}
		changecolour(u,"black");
	}

}




void changecolour(int x,char color[])
{
	int i;
	for(i=0;i<v;i++)
	{	struct adjlist *ptr=array[i].head;
		while(ptr!=NULL)
		{
			if(ptr->val==x)
				strcpy(ptr->colour,color);
			ptr=ptr->next;
		}

	}
	return ;

}
void push(int i)
{top++;
	stack[top]=i;
}
int pop()
{int x=stack[top];
	top--;
	return x;
}



/*

void dfs()
{int start,key;//printf("hi");
	scanf("%d",&start);
	
	//printf("hi");
	scanf("%d",&key);
	//printf("hi");

	//scanf("%d",&key);
	//printf("hi");

	int i;
	for(i=0;i<v;i++)
	{	strcpy(array[i].colour,"white");
		struct adjlist *ptr=array[i].head;
		while(ptr!=NULL)
		{
			changecolour(ptr->val,"white");
			//strcpy(ptr->colour,"white");
			ptr=ptr->next;
		}

	}

	
	if(start==key)
		{printf("%d\n",start);return;}
	ctr=0;
	for(i=start;i<v;i++)
	{	if(ctr==1)
			return;
		if(strcmp(array[i].colour,"white")==0)
  			{
				printf("%d ",i);
				if(i==key)
					return;
			 //strcpy(array[i].colour,"gray");
 			 //changecolour(i,"gray");
			 dfs_visit(i,key);}
	}

	for(i=0;i<start;i++)
	{	if(ctr==1)
			return;
		if(strcmp(array[i].colour,"white")==0)
  			{	printf("%d ",i);
 				if(i==key)
					return;
			 //strcpy(array[i].colour,"gray");
 			 //changecolour(i,"gray");
			 dfs_visit(i,key);}
	}

}

void dfs_visit(int i,int key)
{	
	changecolour(i,"gray");
	strcpy(array[i].colour,"gray");
	
	if(i==key)
		{printf("%d\n",key);
		ctr=1;
		return;}

	struct adjlist *ptr=array[i].head;
	
	while(ptr!=NULL)
	{
		if(strcmp(ptr->colour,"white")==0)
		{	
			if(ptr->val==key)
				{printf("%d\n",key);
				 ctr=1;
				 return;}
			printf("%d ",ptr->val);
			dfs_visit(ptr->val,key);
		}
		if(ctr==1)
			return;
		strcpy(array[ptr->val].colour,"black");
		changecolour(ptr->val,"black");
		ptr=ptr->next;
	}
	
}
*/

