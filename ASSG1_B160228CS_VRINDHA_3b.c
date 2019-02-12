#include<stdio.h>
#include<stdlib.h>

void transpose(long int *a,long int n,long int i,long int j)
{
	if(i==n)
       		return ;
	if(j==n)
		transpose(a,n,i+1,i+2);
        else
		{  *(a+i*n+j)=*(a+i*n+j)+*(a+j*n+i);
                   *(a+j*n+i)=*(a+i*n+j)-*(a+j*n+i);
                   *(a+i*n+j)=*(a+i*n+j)-*(a+j*n+i);  
                 

                   
                     transpose(a,n,i,j+1); 	
		}
}
int main()
{
	long int n,i,j,*a,k,t;
        
	scanf("%ld",&n);
        
        t=n;
      
        a=(long int*)malloc(n*n*sizeof(long int));
	if(n<=0)
          {printf("Size of array must be positive.");
           return 0;}
	for(i=0;i<n;i++)
           for(j=0;j<n;j++)
              scanf("%ld",&*(a+i*n+j));

	transpose(a,n,0,1);
         
	
//printing spiral
        i=j=k=0;
        
	while(k<t*t)
	{
		printf("%ld ",*(a+i*t+j));
		k++;
                
                
 	
		if(i==t-n && j<n-1)
			j++;
		else if(j==n-1 && i<n-1)
			i++;
		else if(i==n-1 && j>t-n)
			j--;
		else if(j==t-n && i>t-n+1)
			i--;
  		else if(j==t-n && i==t-n+1)
                   	{
				n--;
				i=t-n;
				j=t-n;
                                
                                
			} 
	}
	
          	
        printf("\n");
	return 0;
}
