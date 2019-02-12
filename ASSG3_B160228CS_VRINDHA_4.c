#include<stdio.h>
#include<stdlib.h>


struct priority_q
{
	long int data,priority;

};
struct priority_q pq[100000];
long int heapsize=0;


long int parent(long int i)
{
return i/2;
}
long int left(long int i)
{
return 2*i;
}
long int right(long int i)
{
return 2*i+1;
}
void build_min_heap(struct priority_q *pq);
void heap_min(struct priority_q *pq);
void extract_min(struct priority_q *pq);
void get_min(struct priority_q pq[]);
void decrease_priority(struct priority_q pq[],long int elem,long int newpr);
void insert(struct priority_q pq[],long int elem,long int pr);
void min_heapify(struct priority_q pq[],long int i);

int main()
{
char ch;long int elem,pr,newpr;
do{

	
	scanf("%c",&ch);
	
	if(ch=='s'||ch=='S')
		return 0;

	else if(ch=='a')
		{
		scanf("%ld",&elem);
		scanf("%ld",&pr);
		insert(pq, elem, pr);
		}
	else if(ch=='e')
		{
		extract_min(pq);

		}	
	else if(ch=='g')
		{
		get_min(pq);
		}	
	else if(ch=='d')
		{scanf("%ld",&elem);
		scanf("%ld",&newpr);
		decrease_priority(pq,elem,newpr);
		}
	



	}while(ch!='s'||ch!='S');
return 0;
}


void get_min(struct priority_q pq[])
{
	if(heapsize==0)
	{
	printf("EMPTY\n");
	return;
	}
		
	printf("%ld (%ld)\n",pq[1].data,pq[1].priority);

}

void extract_min(struct priority_q pq[])
{
	
	if(heapsize<1)
	{
	printf("EMPTY\n");
	return;
	}

	printf("%ld (%ld)\n",pq[1].data,pq[1].priority);
	

	pq[1]=pq[heapsize];
	heapsize--;
	min_heapify(pq,1);


}

void decrease_priority(struct priority_q pq[],long int elem,long int newpr)
{
	int i=1;
	for(i=1;i<=heapsize;i++)
	{
	if(pq[i].data==elem)
		break;
	}

	pq[i].priority=newpr;
	
	while(i>1 && pq[parent(i)].priority>pq[i].priority)
	{
	struct priority_q var=pq[i];
	pq[i]=pq[parent(i)];
	pq[parent(i)]=var;
	i=parent(i);

	}

}

void insert(struct priority_q pq[],long int elem,long int pr)
{       
	heapsize++;
	pq[heapsize].data=elem;
	pq[heapsize].priority=pr;
	
	build_min_heap(pq);
	

}

void build_min_heap(struct priority_q pq[])
{
long int i;
for(i=heapsize/2;i>0;i--)
	min_heapify(pq,i);
}



void min_heapify(struct priority_q pq[],long int i)
{
long int l=left(i),r=right(i);
long int smallest;

if(l<=heapsize && pq[l].priority<pq[i].priority)
	smallest=l;
else smallest=i;

if(r<=heapsize && pq[r].priority<pq[smallest].priority)
	smallest=r;

if(smallest!=i)
	{
	struct priority_q temp=pq[smallest];
	pq[smallest]=pq[i];
	pq[i]=temp;
	min_heapify(pq,smallest);
	}


}



