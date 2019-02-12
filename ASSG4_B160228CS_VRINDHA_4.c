#include<stdio.h>
#include<stdlib.h>

struct btnode
{	int rootval;
	struct btnode *left;
	struct btnode *right;
};
int k=0;int ctr=0;
int find_pos_root(int rootval,int i,int l,int inorder[]);
struct btnode* createbt(int inorder[],int preorder[],int i,int l);
void printing(struct btnode *ptr);
struct btnode* createnode(int val); 

int main()
{	struct btnode *newptr=NULL;
	int i,n;
	scanf("%d",&n);
	
	int inorder[n],preorder[n];

	for(i=0;i<n;i++)
		scanf("%d",&preorder[i]);
	
	for(i=0;i<n;i++)
		scanf("%d",&inorder[i]);
	
	newptr=createbt(inorder,preorder,0,n-1);
	printing(newptr);
	return 0;
}

int find_pos_root(int val,int i,int l,int inorder[])
{
	for(int t=i;t<=l;t++)
		if(inorder[t]==val)
			return t;
}

struct btnode* createnode(int val)
{
	struct btnode *ptr=(struct btnode*)malloc(sizeof(struct btnode));
	ptr->rootval=val;
	ptr->left=NULL;
	ptr->right=NULL;
}

struct btnode* createbt(int inorder[],int preorder[],int i,int l)
{	int j;
	if(i>l)
		return NULL;

	struct btnode *newptr=createnode(preorder[k]);
	k++;

	if(i==l)
		return newptr;
		
	newptr->left=createbt(inorder,preorder,i,find_pos_root(newptr->rootval,i,l,inorder)-1);
	newptr->right=createbt(inorder,preorder,find_pos_root(newptr->rootval,i,l,inorder)+1,l);
	return newptr;

}


/*void printing(struct btnode *ptr)
{
	if(ptr==NULL)
		{printf("()");return ;}
	printf("(%d",ptr->rootval);
	printing(ptr->left);
	printing(ptr->right);
	printf(")");

}*/
void printing(struct btnode *ptr)
{
	
	if(ctr==0)
		printf("( %d",ptr->rootval);
	else
		printf(" ( %d",ptr->rootval);

	ctr=1;
	if(ptr->left!=NULL)
		printing(ptr->left);
	else printf(" ( )");
	
	if(ptr->right!=NULL)
		printing(ptr->right);
	else printf(" ( )");

	printf(" )");
}
