#include<stdio.h>
#include<stdlib.h>

struct forest
{
	int key;
	int rank;
	struct forest *parent;
};

struct forest *a[10000],*b[10000],*c[10000],*d[10000];
int ctr1=0,ctr2=0,ctr3=0,ctr4=0,temp=0;
void makeset(int x);

struct forest* find1(int x);
void union1(int x,int y);

struct forest* find2(int x);
void union2(int x,int y);

struct forest* find3(int x);
void union3(int x,int y);

struct forest* find4(int x);
void union4(int x,int y);

struct forest* pathconv3(struct forest *k);
struct forest* pathconv4(struct forest *k);

int main()
{	int i;
	for(i=0;i<10000;i++)
		{
		a[i]=NULL;
		b[i]=NULL;
		c[i]=NULL;
		d[i]=NULL;		
		}
	char ch;
	int x,y;
	scanf("%c",&ch);

	while(ch!='s')
	{
	if(ch=='m')
		{scanf("%d",&x);
		makeset(x);
		}
	else if(ch=='f')
		{
		scanf("%d",&x);
		struct forest *k=find1(x);
		ctr1+=temp;
		if(find1(x)==NULL)
			printf("NOT FOUND\n");
		else printf("%d ",find1(x)->key);

		k=find2(x);
		ctr2+=temp;
		if(find2(x)==NULL)
			printf("NOT FOUND\n");
		else printf("%d ",find2(x)->key);
 
	
		k=find3(x);
		ctr3+=temp;
		if(find3(x)==NULL)
			printf("NOT FOUND\n");
		else printf("%d ",find3(x)->key);

		
		k=find4(x);
		ctr4+=temp;	
		if(find4(x)==NULL)
			printf("NOT FOUND\n");
		else printf("%d\n",find4(x)->key);
		}
	else if(ch=='u')
		{
		scanf("%d %d",&x,&y);
		union1(x,y);
		union2(x,y);
		union3(x,y);
		union4(x,y);
		}
	scanf("%c",&ch);

	}
if(ch=='s')
{
	printf("%d %d %d %d\n",ctr1,ctr2,ctr3,ctr4);
}

return 0;}



void makeset(int x)
{
	struct forest *ptr1=(struct forest*)malloc(sizeof(struct forest));
	struct forest *ptr2=(struct forest*)malloc(sizeof(struct forest));
	struct forest *ptr3=(struct forest*)malloc(sizeof(struct forest));
	struct forest *ptr4=(struct forest*)malloc(sizeof(struct forest));
	
	ptr1->key=x;
	ptr1->parent=ptr1;
	ptr1->rank=0;
	
	ptr2->key=x;
	ptr2->parent=ptr2;
	ptr2->rank=0;
	
	ptr3->key=x;
	ptr3->parent=ptr3;
	ptr3->rank=0;
	
	ptr4->key=x;
	ptr4->parent=ptr4;
	ptr4->rank=0;
	
	a[x]=ptr1;
	b[x]=ptr2;
	c[x]=ptr3;
	d[x]=ptr4;

	printf("%d\n",x);
}

struct forest* find1(int x)
{	temp=0;
	if(a[x]==NULL)
		return NULL;
	struct forest *ptr=a[x];
	while(ptr!=NULL)
	{	temp++;
		if(ptr->parent==ptr)
			return ptr;
		ptr=ptr->parent;
	}
}
void union1(int x,int y)
{
	
	if(find1(x)==NULL||find1(y)==NULL)
		{
		printf("ERROR\n");
		return;		
		}
	struct forest *u=find1(x);
	ctr1+=temp;
	struct forest *v=find1(y);
	ctr1+=temp;

	if(find1(x)==find1(y))
		{
		printf("%d ",find1(x)->key);
		return;
		}
	
	find1(y)->parent=find1(x);
	printf("%d ",find1(x)->key);
	return;
}

struct forest* find2(int x)
{	temp=0;
	if(b[x]==NULL)
		return NULL;
	struct forest *ptr=b[x];
	while(ptr!=NULL)
	{	temp++;
		if(ptr->parent==ptr)
			return ptr;
		ptr=ptr->parent;
	}

}

void union2(int x,int y)
{

	if(find2(x)==NULL||find2(y)==NULL)
		{
		printf("ERROR\n");
		return;		
		}
	struct forest *u=find2(x);
	ctr2+=temp;
	struct forest *v=find2(y);
	ctr2+=temp;

	if(find2(x)==find2(y))
		{
		printf("%d ",find2(x)->key);
		return; 
		}
	else if(find2(x)!=find2(y))
		{int r1=find2(x)->rank,r2=find2(y)->rank;
			if(find2(x)->rank >= find2(y)->rank)
				find2(y)->parent=find2(x);
			else 
				find2(x)->parent=find2(y);

			
			if(r1==r2)
				find2(x)->rank=find2(x)->rank+1;
	
			printf("%d ",find2(x)->key);
		}

}

struct forest* find3(int x)
{
	/*if(x->parent!=x)
		x->parent=findset(x->parent);
	return x->parent;
	*/

	temp=0;
	if(c[x]==NULL)
		return NULL;
	
	return pathconv3(c[x]);

}

struct forest* pathconv3(struct forest *k)
{	temp++;
	
	if(k->parent!=k)
		k->parent=pathconv3(k->parent);
	return k->parent;
}

void union3(int x,int y)
{

	if(find3(x)==NULL||find3(y)==NULL)
		{
		printf("ERROR\n");
		return;		
		}

	struct forest *u=find3(x);
	ctr3+=temp;
	struct forest *v=find3(y);
	ctr3+=temp;

	if(find3(x)==find3(y))
		{
		printf("%d ",find3(x)->key);
		return;
		}
	
	find3(y)->parent=find3(x);
	printf("%d ",find3(x)->key);
	return;
}

struct forest* find4(int x)
{
temp=0;
	if(d[x]==NULL)
		return NULL;
	
	return pathconv4(d[x]);

}


struct forest* pathconv4(struct forest *k)
{
	temp++;
	if(k->parent!=k)
		k->parent=pathconv4(k->parent);
	return k->parent;
	

}

void union4(int x,int y)
{

	struct forest *u=find4(x);
	ctr4+=temp;
	struct forest *v=find4(y);
	ctr4+=temp;
	
	if(find4(x)==NULL||find4(y)==NULL)
		{
		printf("ERROR\n");
		return;		
		}


	if(find4(x)==find4(y))
		{
		printf("%d\n",find4(x)->key);
		return; 
		}
	else if(find4(x)!=find4(y))
		{int r1=find4(x)->rank,r2=find4(y)->rank;
			if(find4(x)->rank >= find4(y)->rank)
				find4(y)->parent=find4(x);
			else 
				find4(x)->parent=find4(y);

			
			if(r1==r2)
				find4(x)->rank=find4(x)->rank+1;
	
			printf("%d\n",find4(x)->key);
		}


}
