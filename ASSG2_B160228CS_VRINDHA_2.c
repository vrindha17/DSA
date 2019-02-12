#include<stdio.h>
#include<stdlib.h>

void quicksort(long int *a,long int p,long int r);
long int partition(long int *a,long int p,long int r);
long int median(long int *a,long int p,long int r,long int med);

long int ctr=0;

int main()
{
	long int n,i,ctr=0;
	scanf("%ld",&n);
	long int a[n];

	for(i=0;i<n;i++)
        	scanf("%ld",&a[i]);

       
        quicksort(a,0,n-1);
        for(i=0;i<n;i++)
            printf("%ld ",a[i]);
        }

void quicksort(long int *a,long int p,long int r)
{long int q,med,n;
        n=r-p+1;
   	if(n%2==0)
             med=p+(n/2)-1;
        else 
           med=p+(n/2);

	if(p<r)
	{
		q=median(a,p,r,med);
                if(ctr<3)
		{printf("%ld\n",a[q]);ctr++;}
                quicksort(a,p,q-1);
               	quicksort(a,q+1,r);
                


	}
}

long int partition(long int *a,long int p,long int r)
{
	long int x=a[r];
        long int i=p-1,j,temp;
	
	for(j=p;j<=r-1;j++)
	{	if(a[j]<=x)
			{i++;
 			        temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
         
         }
temp=a[i+1];
a[i+1]=a[j];
a[j]=temp;

return i+1;}


long int median(long int *a,long int p,long int r,long int med)
{        long int pivot=partition(a,p,r);
	if(pivot==med)
            return med;
        if(pivot>med)
             median(a,p,pivot-1,med);
         else 
             median(a,pivot+1,r,med);

}
