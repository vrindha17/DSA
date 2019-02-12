/*
4. b) Given a sorted rotated array of N distinct integers, search a given
element in this array in O(logN). If found then print the index (starting
from 0) otherwise print -1.
*/

#include<stdlib.h>
#include<stdio.h>
int main()
{
long int n,i,min,mid,max,search;
min=0;
scanf("%ld",&n);
long int *a=(long int*)malloc(n*sizeof(long int));

for(i=0;i<n;i++)
	{scanf("%ld",&a[i]);
	if(a[i]<a[min])
        	min=i;
                }
if(min==0)
	max=n-1;
else 
	max=min-1;


scanf("\n%ld",&search);


//using binary search
int ctr=0;

while(ctr==0)
{
  if(min==max)
     ctr=1;
if(min<=max)
   	mid=(min+max)/2;
else
        mid=(min+max+n)/2;

if(mid>n-1)
   mid-=n-1;


if(a[mid]==search)
	{printf("%ld",mid);
         return 0;
           }

if(a[mid]>search)
   { 
     max=mid-1;
       if(max<0)
         max=n-1;
        }
else
    { 
      min=mid+1;
     if(min>n-1)
          min=0;
         }

}
printf("-1");
return 0;
}

