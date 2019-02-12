#include<stdlib.h>
#include<stdio.h>
struct ratio
          {long int x,y;
               };
void one(struct ratio a);
void two(struct ratio a);
void three(struct ratio a);
void four();
void five(struct ratio a);
long int multiple(struct ratio a[],long int n)
{  
  long int prod=1;
   for(int i=0;i<n;i++)
      prod*=a[i].y;
   return prod;	
}

int main()
{	

	int choice;
        struct ratio a;
	
        scanf("%d",&choice);
	if(choice<=0||choice>5)
           { printf("Invalid choice");
             return 0;
            }
          
        if(choice!=4)
	{
         scanf("%ld %ld",&a.x,&a.y);
            if(a.y==0)
               { printf("Denominator should not be zero");
                 return 0;}}
 	
	if(choice==1)	
            one(a);
	else if(choice==2)	
            two(a);
	else if(choice==3)
	    three(a);
	else if(choice==4)
            four();
        else if(choice==5)
	    five(a);
       

return 0;
}

void one(struct ratio a)
{       long int small;int flg=0;
        if(a.x==0)
         { printf("0/1");return;}

        if(a.y<0&&a.x<0)
            {a.x*=-1;
             a.y*=-1;
                 }
         else if(a.x<0)
            {flg=1;a.x*=-1;}
          else if(a.y<0)
            {flg=1;a.y*=-1;}

         
         if(a.x>a.y)
          small=a.y;
        else 
          small=a.x;


         for(long int i=small;i>0;i--)
            {  if(a.x%i==0&&a.y%i==0)
                  {a.x/=i;
                  a.y/=i;break;}
		}
         if(flg==1)
          a.x*=-1;
	printf("%ld/%ld",a.x,a.y);

}


void two(struct ratio a)
{	struct ratio b;
	scanf("%ld %ld",&b.x,&b.y);
        if(b.y==0)
           { 
             printf("Denominator should not be zero");
             return;}
	a.x=a.x*b.y+a.y*b.x;
        a.y=a.y*b.y;
	five(a);
}

void three(struct ratio a)
{	struct ratio b;
	scanf("%ld %ld",&b.x,&b.y);
           if(b.y==0)
              {  printf("Denominator should not be zero");
                  return;}
        a.x=a.x*b.x;
        a.y=a.y*b.y;
	five(a);
}

void four()
{
	long int i,n; struct ratio *a;	
	
        scanf("%ld",&n);
            if(n<=0)
                {printf("Size should be greater than zero ");
                 return;}
         
        a=(struct ratio*)malloc(n*sizeof(struct ratio));

	for(i=0;i<n;i++)
	{scanf("%ld %ld",&a[i].x,&a[i].y);
           if(a[i].y==0)
              {printf("Denominator should be greater than zero");
                 return;}     
        if(a[i].y<0&&a[i].x<0)
            {a[i].x*=-1;
             a[i].y*=-1;
                 }
         
          else if(a[i].y<0)
            {a[i].x*=-1;a[i].y*=-1;}

               
	}
        long int k=multiple(a,n);
	 
	



	for(i=0;i<n-1;i++)
		for(long int j=0;j<n-1;j++)
		{        
			if(a[j].x*k/a[j].y>a[j+1].x*k/a[j+1].y)			
			{a[j].x=a[j].x+a[j+1].x;
                         a[j+1].x=a[j].x-a[j+1].x;
                         a[j].x=a[j].x-a[j+1].x;

                        a[j].y=a[j].y+a[j+1].y;
                         a[j+1].y=a[j].y-a[j+1].y;
                         a[j].y=a[j].y-a[j+1].y;

                         }
                           
		
		}

	for(i=0;i<n;i++)
		{printf("%ld/%ld",a[i].x,a[i].y);
                 if(i!=n-1)
		   printf(" ");}


}

void five(struct ratio a)
{	long int small;int flg=0;
        if(a.x==0)
           {printf("0/1");
            return;
              }

        if(a.y<0&&a.x<0)
            {a.x*=-1;
             a.y*=-1;
                 }
         else if(a.x<0)
            {flg=1;a.x*=-1;}
          else if(a.y<0)
            {flg=1;a.y*=-1;}

         
         if(a.x>a.y)
          small=a.y;
        else 
          small=a.x;


         for(long int i=small;i>0;i--)
            {  if(a.x%i==0&&a.y%i==0)
                  {a.x/=i;
                  a.y/=i;break;}
		}
         if(flg==1)
          a.x*=-1;
	printf("%ld/%ld ",a.x,a.y);
}


 
