#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int n,heapsize=-1,dest,distance[10000],visited[10000],heap[10000],sum=0;
struct vertex
{
	int data,weight;
	struct vertex *next;
};

struct table{
    struct vertex *list;
}vertex_array[10000];

void min_heapify(int i);
int extract_min();
int parent(int x);
void prim();
void heap_insert(int i);
void insert_edge(int i,int x);
void relax(struct vertex *ptr,int u);
void print();






int main()
{
int i,j,x;
char ch;
  scanf("%d",&n);
  ch=getchar();
	for(i=0;i<10000;i++)
		vertex_array[i].list=NULL;
	i=0;struct vertex *temp=NULL;
	while(i<n)
	{
		
		scanf("%d",&x);
		ch=getchar();
		struct vertex *ptr=(struct vertex*)malloc(sizeof(struct vertex));
		ptr->data=x;
		ptr->weight=0;
		ptr->next=NULL;
		temp=vertex_array[i].list;

		if(temp==NULL)
			{vertex_array[i].list=ptr;}
		else
		{
			while(temp->next!=NULL)
			{temp=temp->next;}
			temp->next=ptr;

		}
	
				
		if(ch=='\n')
			i++;
	}


	i=0;
	while(i<n)
	{	struct vertex *temp=vertex_array[i].list;
		
		while(temp!=NULL)
		{
		scanf("%d",&x);
		ch=getchar();
		temp->weight=x;
		temp=temp->next;}
		i++;
	}

     
	prim();  
	sum=0;
	for(i=0;i<n;i++)
	
		sum+=distance[i];
	printf("%d\n",sum);
  return 0;
}







/*


int main()
{
int i,j;int y,z;
int t,d;char x,c;
  scanf("%d",&n);
  scanf("%c",&c);
for( i=0;i<n;i++)
 {
     visited[i]=0;
 }
for(j=0;j<n;j++)
   {
      vertex_array[j].list=NULL;
      while(1)
     {
        scanf("%c",&c);
        if(c=='\n')break;
        else
        {
            y=c-'0';
            while(1)
            {
                scanf("%c",&x);
                if(x=='\n' || x==' ' ) break;
                z=x-'0';
                y=y*10 +z;
                
            }
        }
       
        struct vertex *newnode=malloc(sizeof(struct vertex));
        newnode->data=y;
        newnode->weight=0;
        newnode->next=NULL;
        if( vertex_array[j].list==NULL)
        {
            vertex_array[j].list=newnode;
        }
        else
        {
            struct vertex *temp=vertex_array[j].list;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
        }
        if(x=='\n') break;
        
    }
  }
  
  for(j=0;j<n;j++)
   {
       struct vertex*temp=vertex_array[j].list;
      while(1)
     {
        scanf("%c",&c);
        if(c=='\n')break;
        else
        {
            y=c-'0';
            while(1)
            {
                scanf("%c",&x);
                if(x=='\n' || x==' ' ) break;
                z=x-'0';
                y=y*10 +z;
                
            }
        }
        temp->weight=y;
        temp=temp->next;
        if(x=='\n') break;
        
    }
  }
	prim();  
	sum=0;
	for(i=0;i<n;i++)
		sum+=distance[i];
	printf("%d\n",sum);
  return 0;
}



*/
void insert_edge(int i,int x)
{
	struct vertex *ptr=(struct vertex*)malloc(sizeof(struct vertex));
	ptr->data=x;
	ptr->weight=0;
	ptr->next=NULL;

	if(vertex_array[i].list==NULL)
	{	vertex_array[i].list=ptr;
		return;
	}
	struct vertex *temp=vertex_array[i].list,*prev=NULL;
	
	while(temp!=NULL)
	{	prev=temp;
		temp=temp->next;
	}
	
	prev->next=ptr;
}


void heap_insert(int i)
{
	heapsize++;
	heap[heapsize]=i;
	i=heapsize;
	
/*	for(i=heapsize/2;i>=0;i--)
		min_heapify(i);*/
	while(i>0 && distance[heap[parent(i)]]>distance[heap[i]])
	{       int swap=heap[parent(i)];
	        heap[parent(i)]=heap[i];
	        heap[i]=swap;
	        i=parent(i);

	}
}




void min_heapify(int i)
{
	int l=2*i+1,r=2*i+2;
	int smallest;

	if(l<=heapsize && distance[heap[l]] < distance[heap[i]])
		smallest=l;
	else smallest=i;

	if(r<=heapsize && distance[heap[r]] < distance[heap[smallest]] )
		smallest=r;

	if(smallest!=i)
	{
		int temp=heap[smallest];
		heap[smallest]=heap[i];
		heap[i]=temp;
		min_heapify(smallest);
	}


}



int extract_min()
{	int temp=heap[0];
	heap[0]=heap[heapsize];
	heapsize--;
	min_heapify(0);
	return temp;
}

int parent(int x)
{
	if(x%2==0)
		return (x-2)/2;
	return (x-1)/2;
}
void prim()
{
	int i;
	for(i=0;i<n;i++)
	{
		distance[i]=INT_MAX;
		visited[i]=0;	
	}

	distance[0]=0;
	//for(i=0;i<n;i++)
		heap_insert(0);

	while(heapsize!=-1)
	{
		int u=extract_min();


		visited[u]=1;
		struct vertex *ptr=vertex_array[u].list;
		
		while(ptr!=NULL)
		{

			if(visited[ptr->data]==0)
			 {     int t=ptr->weight;
				if(t < distance[ptr->data])
            				{distance[ptr->data]=t;
						//sum+=distance[ptr->data];
					}
             			heap_insert(ptr->data);
			//relax(ptr,u);

         		 }	
		
			ptr=ptr->next;	
		}

	
	}

}
void relax(struct vertex *ptr,int u)
{
	
	      int t=ptr->weight;
				if(t < distance[ptr->data])
            				distance[ptr->data]=t;
             			//heap_insert(ptr->data);

         		 			
			
		

}

void print()
{
	int i=0;
	while(i<n)
	{
		struct vertex *ptr=vertex_array[i].list;
		
		while(ptr!=NULL)
		{
			printf("%d %d  %d\n",i,ptr->data,ptr->weight);
			ptr=ptr->next;
		}printf("\n");
		i++;
	//printf("%d %d\n",i,n);

	}
	

	return;

}
