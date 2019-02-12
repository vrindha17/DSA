#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<limits.h>

long int isdivi(long int a,long int b);
void merge(long int *a,long int p,long int q,long int r,long int s);
void mergesort(long int *a,long int p,long int s);

int main()
{
	FILE *rfile=fopen("in","rb"),*wfile=fopen("out","wb");
	if(rfile==NULL)
	{
		 printf("Couldnt open file\n");
		 return 0;
	}

	long int i=0,n,k;
        long int *a=malloc(sizeof(long int));
        
	
	while(fscanf(rfile,"%ld",&k)!=EOF)
   	{        
            a=realloc(a,(i+1)*sizeof(long int));
              a[i]=k;
               i++;    
        }

	n=i;
        mergesort(a,0,n-1);

        for(i=0;i<n;i++)
	 fprintf(wfile,"%ld ",a[i]);



	return 0;
}

void merge(long int a[],long int p,long int q,long int r,long int s)
{   

   long int j,i,k,L[100000000]={0},M[1000000000]={0},N[1000000000]={0};

    for(i=0,j=p;j<=q;i++,j++)
           L[i]=a[j];          
         L[i]=LONG_MAX;
   
    
    for(j=q+1,i=0;j<=r;i++,j++)
           M[i]=a[j];
         M[i]=LONG_MAX;
   

    
    for(i=0,j=r+1;j<=s;i++,j++)
           N[i]=a[j];
         N[i]=LONG_MAX;

i=0;j=0,k=0;long int x=p;
while(x<=s)
{
     if(M[i]<=N[j]&&M[i]<=L[k])
             {    
                  a[x]=M[i];
                    i++;}
      
     else if(M[i]>=N[j]&&N[j]<=L[k])
             {   
                  a[x]=N[j];
                    j++;}  

     else if(M[i]>=L[k]&&N[j]>=L[k])
             {    
                  a[x]=L[k];
                    k++;}     



x++;}
}


void mergesort(long int *a,long int p,long int s)
{long int q,r;  
 if(p<s)
  {      
                                   
          q=p+isdivi(s-p+1,3)-1;
          r=s-isdivi(s-p+1,3);
          
          
          mergesort(a,p,q);
                                                     
          mergesort(a,q+1,r);
                      
          mergesort(a,r+1,s);
                              
	  merge(a,p,q,r,s);


	  } 
        
}


long int isdivi(long int a,long int b)
{

  if(a%b==0)
      return a/b;
 else 
     return (a/b)+1;
}
