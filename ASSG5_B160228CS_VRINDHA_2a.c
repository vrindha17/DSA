#include<stdio.h>
#include<stdlib.h>

struct vertex
{
	int key;
	struct vertex *parent;
}*v[10000];

struct edge
{
	int u,v,w;
	struct edge *next;
}*e[10000],edge_array[100000];

int n,ctr=0,sum=0;
void makeset(int x);
struct vertex* find(int x);
void union1(int x,int y);
void print();
void sort();
void insert_edge(int i,int x); 
void kruskal();
int main()
{	int i,x;
	char ch;
	for(i=0;i<10000;i++)
	{	e[i]=NULL;
		v[i]=NULL;
	}
		
	scanf("%d",&n);

	i=0;
	while(i<n)
	{
		scanf("%d",&x);
		insert_edge(i,x);
		edge_array[ctr].u=i;
		edge_array[ctr].v=x;
		ch=getchar();
		ctr++;
		if(ch=='\n')
			i++;
	}

	i=0;int j=0;
	while(i<n)
	{
		
		struct edge *temp=e[i];
		while(temp!=NULL)
		{	scanf("%d",&x);
			edge_array[j].w=x;
			temp->w=x;
			temp=temp->next;
			j++;
		}
		i++;
	}
	kruskal();
printf("%d",sum);

return 0;}

void insert_edge(int i,int x)
{
	struct edge *ptr=(struct edge*)malloc(sizeof(struct edge));
	ptr->u=x;
	ptr->next=NULL;

	if(e[i]==NULL)
	{	e[i]=ptr;
		return;
	}
	struct edge *temp=e[i],*prev=NULL;
	
	while(temp!=NULL)
	{	prev=temp;
		temp=temp->next;
	}
	
	prev->next=ptr;
}
void print()
{
	int i=0;
	while(i<n)
	{
		struct edge *ptr=e[i];
		
		while(ptr!=NULL)
		{
			printf("%d-%d  %d\n",i,ptr->u,ptr->w);
			ptr=ptr->next;
		}printf("\n");
		i++;

	}
	
	for(i=0;i<ctr;i++)
	{
		printf("%d %d %d\n",edge_array[i].u,edge_array[i].v,edge_array[i].w);
	}

}


void kruskal()
{	int i;
	for(i=0;i<n;i++)
		makeset(i);
	sort();
	
	for(i=0;i<ctr;i++)
	{
		if(find(edge_array[i].u)!=find(edge_array[i].v))
		{	union1(edge_array[i].u,edge_array[i].v);
			sum+=edge_array[i].w;		
		}

	}


}


void makeset(int x)
{	struct vertex *ptr=(struct vertex*)malloc(sizeof(struct vertex));
	ptr->key=x;
	ptr->parent=ptr;
	v[x]=ptr;
}

void sort()
{	int i,j;
	for(i=0;i<ctr-1;i++)
		for(j=0;j<ctr-1;j++)
			if(edge_array[j].w>edge_array[j+1].w)
			{
				struct edge temp=edge_array[j];
				edge_array[j]=edge_array[j+1];
				edge_array[j+1]=temp;
			}
//print();
}


struct vertex* find(int x)
{	if(v[x]==NULL)
		return NULL;
	struct vertex *ptr=v[x];
	while(ptr!=NULL)
	{	if(ptr->parent==ptr)
			return ptr;
		ptr=ptr->parent;
	}
}

void union1(int x,int y)
{
	
	if(find(x)==NULL||find(y)==NULL)
		{
		printf("ERROR\n");
		return;		
		}

	if(find(x)==find(y))
		return;
		
	
	find(y)->parent=find(x);
	return;
}

