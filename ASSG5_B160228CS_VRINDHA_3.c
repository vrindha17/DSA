#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int n,heapsize=-1,dest,distance[10000],visited[10000],heap[10000];
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
void dijkstra(int start);
void heap_insert(int i);
void insert_edge(int i,int x);
void relax(struct vertex *ptr,int u);
void print();


int main()
{
int i,j,y,z,t,d;char x,c;
  scanf("%d",&n);
  scanf("%c",&c);

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
  char ch[4];
  while(1)
  {
  scanf("%s",ch);
  if(!strcmp(ch,"apsp"))
  {
      scanf("%d",&t);
      dijkstra(t);
      for(i=0;i<n;i++)
         {
           if(distance[i]==INT_MAX)
            printf("INF ");
           else
            printf("%d ",distance[i]);
          }
      printf("\n");
      for(i=0;i<n;i++)
      visited[i]=0;
  }
  else if(!strcmp(ch,"sssp"))
  {
       scanf("%d%d",&t,&d);
       dijkstra(t);
     if(distance[d]==INT_MAX)
     printf("UNREACHABLE\n");
     else
      printf("%d\n",distance[d]);
      for(i=0;i<n;i++)
      visited[i]=0;
  }
  else if(!strcmp(ch,"stop"))
  return 0;
  }
  return 0;
}







/*int main()
{	int i,x,ctr=0;
	char ch;
	scanf("%d",&n);
	
	i=0;
	while(i<n)
	{
		scanf("%d",&x);
		insert_edge(i,x);
		ch=getchar();
		ctr++;
		if(ch=='\n')
			i++;
	}

	i=0;int j=0;
	struct vertex *temp=vertex_array[i].list;
	while(j<ctr)
	{
		scanf("%d",&x);
		if(temp!=NULL)
			temp->weight=x;
		else 
			{i++;temp=vertex_array[i].list;temp->weight=x;}	
	j++;temp=temp->next;
	}

	char string[10];
	do{scanf("%s",string);

		if(strcmp(string,"apsp")==0)
		{
			int start;
			scanf("%d",&start);
			dijkstra(start);
			
			
     			for(i=0;i<n;i++)
         		{	if(distance[i]==INT_MAX)
         				{   printf("INF ");}
           			else
            				printf("%d ",distance[i]);
          		}
      			printf("\n");
      
		}
		else if(strcmp(string,"sssp")==0)
		{
			int start;
			scanf("%d",&start);
			scanf("%d",&dest);
			dijkstra(start);
			
			if(distance[dest]==INT_MAX)
				printf("UNREACHABLE\n");
			else
				printf("%d\n",distance[dest]);
		}
		else if(strcmp(string,"sssp")==0)
			return 0;
	}while(strcmp(string,"stop")!=0);
//print();
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
void dijkstra(int start)
{
	int i;
	for(i=0;i<n;i++)
	{
		distance[i]=INT_MAX;
		visited[i]=0;	
	}

	distance[start]=0;

	heap_insert(start);

	while(heapsize!=-1)
	{
		int u=extract_min();

		visited[u]=1;
		struct vertex *ptr=vertex_array[u].list;
		//relax(ptr,u);
		while(ptr!=NULL)
		{

			if(visited[ptr->data]==0)
			 {      int t=distance[u]+ptr->weight;
				if(t < distance[ptr->data])
            				distance[ptr->data]=t;
             			heap_insert(ptr->data);

         		 }	
		
			ptr=ptr->next;	
		}

	
	}

}
void relax(struct vertex *ptr,int u)
{
	
		while(ptr!=NULL)
		{//printf("%d\n",ptr->data);
			if(visited[ptr->data]==0)
			 {      int t=distance[u]+ptr->weight;
				if(t < distance[ptr->data])
            				distance[ptr->data]=t;
             			heap_insert(ptr->data);

         		 }			
			ptr=ptr->next;	
		}

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
