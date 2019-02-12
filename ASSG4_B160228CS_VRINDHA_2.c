#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree
{	int val;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
}*bst=NULL;
int ctr=0;
void insert(int element);
void search(struct tree *ptr,int element);
void minimum(struct tree *ptr);
void maximum(struct tree *ptr);
void predecessor(struct tree *ptr,int element);
void successor(struct tree *ptr,int element);
void delete(struct tree *ptr,int element);
void inorder(struct tree *ptr);
void preorder(struct tree *ptr);
void postorder(struct tree *ptr);
struct tree* createnode(int val);
void transplant(struct tree *u,struct tree *v);		
struct tree* tree_minimum(struct tree *ptr);

int main()
{	struct tree *ptr=NULL;
	char string[100];
	int element;
	do{
		scanf("%s",string);

		if(strcmp(string,"stop")==0)
			return 0;
		else if(strcmp(string,"insr")==0)
			{scanf("%d",&element);
			insert(element);
			}
		else if(strcmp(string,"srch")==0)
			{ptr=bst;
			scanf("%d",&element);
			search(ptr,element);
			}
		else if(strcmp(string,"minm")==0)
			{ptr=bst;
			minimum(ptr);
			}
		else if(strcmp(string,"maxm")==0)
			{ptr=bst;
			maximum(ptr);
			}
		else if(strcmp(string,"pred")==0)
			{ptr=bst;
			scanf("%d",&element);
			predecessor(ptr,element);
			}
		else if(strcmp(string,"succ")==0)
			{ptr=bst;
			scanf("%d",&element);
			successor(ptr,element);
			}
		else if(strcmp(string,"delt")==0)
			{ptr=bst;
			scanf("%d",&element);
			delete(ptr,element);
			}
		else if(strcmp(string,"inor")==0)
			{ptr=bst;
			ctr=0;
			inorder(ptr);
			printf("\n");
			}
		else if(strcmp(string,"prer")==0)
			{ptr=bst;
			ctr=0;
			preorder(ptr);
			printf("\n");
			}
	
		else if(strcmp(string,"post")==0)
			{ptr=bst;
			ctr=0;
			postorder(ptr);
			printf("\n");
			}

	}while(strcmp(string,"stop")!=0);


return 0;
}



void insert(int element)
{
	struct tree *ptr=NULL,*newptr=NULL,*prev=NULL;
	newptr=createnode(element);

	if(bst==NULL)
		{
		bst=newptr;		
		return;
		}
	ptr=bst;

	while(ptr!=NULL)
	{prev=ptr;
	if(element > ptr->val)
		ptr=ptr->right;

	else if(element < ptr->val)
		ptr=ptr->left;
	}

	ptr=newptr;
	ptr->parent=prev;

	if(element > prev->val)
		prev->right=ptr;
	else prev->left=ptr;	
}


void search(struct tree *ptr,int element)
{	if(ptr==NULL)
		{
		printf("NOT FOUND\n");
		return;
		}
	if(ptr->val==element)
		{
		printf("FOUND\n");
		return;
		}
	else if(element > ptr->val)
		{ptr=ptr->right;
		 search(ptr,element);	}

	else if(element < ptr->val)
		{ptr=ptr->left;
		search(ptr,element);}
	

}
void minimum(struct tree *ptr)
{
	if(ptr==NULL)
		{
		printf("NIL\n");return;
		}

	struct tree *prev=ptr;
	ptr=ptr->left;
	if(ptr==NULL)
	{
	printf("%d\n",prev->val);return;
	}
	
	minimum(ptr);	

}		
void maximum(struct tree *ptr)
{

	if(ptr==NULL)
		{
		printf("NIL\n");return;
		}

	struct tree *prev=ptr;
	ptr=ptr->right;
	if(ptr==NULL)
	{
	printf("%d\n",prev->val);return;
	}
	
	maximum(ptr);

}
void predecessor(struct tree *ptr,int element)
{	if(ptr==NULL)
		{printf("NOT FOUND\n");return;}

	while(1){
	if(ptr->val==element)
		break;		
	else if(element > ptr->val)
		{ptr=ptr->right;
		 	}

	else if(element < ptr->val)
		{ptr=ptr->left;
		}	
              }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 if(ptr->left!=NULL)
		{maximum(ptr->left);
		return;}
	
   	struct tree *y=ptr->parent;
	while(y!=NULL && y->left==ptr)
	{
	ptr=y;
	y=y->parent;
	}
if(y==NULL)
	{printf("NIL\n");return;}
printf("%d\n",y->val);



}
void successor(struct tree *ptr,int element)
{	if(ptr==NULL)
		{printf("NOT FOUND\n");return;}
	
	while(1){
	if(ptr->val==element)
		break;		
	else if(element > ptr->val)
		{ptr=ptr->right;
		 	}

	else if(element < ptr->val)
		{ptr=ptr->left;
		}	
              }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 if(ptr->right!=NULL)
		{minimum(ptr->right);return;}
	
   	struct tree *y=ptr->parent;
	while(y!=NULL && y->right==ptr)
	{
	ptr=y;
	y=y->parent;
	}

	if(y==NULL)
	{printf("NIL\n");
	return;}
	
	printf("%d\n",y->val);

}


void inorder(struct tree *ptr)
{
	if(ptr==NULL)
		{if(ctr==0)
			printf("NULL\n");
		return;}
	ctr=1;
	inorder(ptr->left);
	printf("%d ",ptr->val);
	inorder(ptr->right);

}
void preorder(struct tree *ptr)
{

	if(ptr==NULL)
		{if(ctr==0)
			printf("NIL\n");
		return;}
	ctr=1;
	printf("%d ",ptr->val);
	preorder(ptr->left);
	preorder(ptr->right);
}
void postorder(struct tree *ptr)
{

	if(ptr==NULL)
		{if(ctr==0)
			printf("NIL\n");
		return;}
	ctr=1;
	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d ",ptr->val);

}


struct tree* createnode(int val)
{
	struct tree *newptr=(struct tree*)malloc(sizeof(struct tree));
	newptr->left=NULL;
	newptr->right=NULL;
	newptr->parent=NULL;
	newptr->val=val;

	return newptr;
}	

void transplant(struct tree *u,struct tree *v)
{
	if(u->parent==NULL)
		bst=v;
	else if(u==u->parent->left)
		u->parent->left=v;
	else u->parent->right=v;

	if(v!=NULL)
		v->parent=u->parent;

}	


void delete(struct tree *ptr,int element)
{	struct tree *y=NULL;
	
	while(1){
	if(ptr->val==element)
		break;		
	else if(element > ptr->val)
		{ptr=ptr->right;
		 	}

	else if(element < ptr->val)
		{ptr=ptr->left;
		}	
              }
//////////////////////////////////////////////////

	if(ptr->left==NULL)
		transplant(ptr,ptr->right);
	else if(ptr->right==NULL)
		transplant(ptr,ptr->left);
	else 
		{y=tree_minimum(ptr->right);

			if(y->parent!=ptr)
			{
			transplant(y,y->right);
			y->right=ptr->right;
			y->right->parent=y;
			}

		transplant(ptr,y);
		y->left=ptr->left;
		y->left->parent=y;	
		}
}

struct tree* tree_minimum(struct tree *ptr)
{
	
	if(ptr==NULL)
		{
		return ptr;
		}
while(ptr!=NULL)
{	struct tree *prev=ptr;
	ptr=ptr->left;
	if(ptr==NULL)
		return prev;
	
	
	}
}
