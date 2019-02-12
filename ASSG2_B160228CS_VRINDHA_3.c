#include<stdio.h>
#include<stdlib.h>

long int left(long int i)
{	return 2*i+1;
}
long int right(long int i)
{	return 2*i+2;
}
void buildmaxheap(long int *a);
void maxheapify(long int *a,long int i);
void heapsort(long int *a);

long int n,heapsize,k;
int main()
{	long int i;
	scanf("%ld",&n);
	heapsize=n;
	long int a[n];

	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);

	scanf("%ld",&k);

        heapsort(a);


return 0;}


void maxheapify(long int *a,long int i)
{         
	long int l,r,largest;
	l=left(i);
	r=right(i);
        
	if(l<n&&a[l]>a[i])
		largest=l;
        else 
		largest=i;
		 	
	if(r<n&& a[r]>a[largest])
		largest=r;
 
	if(largest!=i)
            {
		long int temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		maxheapify(a,largest);}



}


void buildmaxheap(long int *a)
{
	long int i;
        
	for(i=(n-1)/2;i>=0;i--)
		maxheapify(a,i);
       

}

void heapsort(long int *a)
{long int i,temp,var;
buildmaxheap(a);
for(i=n-1;k>0;i--,k--)
	{

	temp=a[0];
        a[0]=a[i];
	a[i]=temp;
        n--;
        maxheapify(a,0);
       
       if(i!=n-1&&var==a[i])
            k++;
           
        var=a[i];
        }
printf("%ld",a[i+1]);

}
