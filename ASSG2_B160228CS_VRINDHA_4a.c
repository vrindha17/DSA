#include<stdio.h>
int main()
{
long int m,n,i,j,k,l,search,flg=0;

scanf("%ld %ld",&m,&n);
long int a[m][n];

for(i=0;i<m;i++)
  for(j=0;j<n;j++)
      scanf("%ld",&a[i][j]);



scanf("\n%ld",&search);

i=0;j=n-1;k=0;

while(i<m&&j>=0)
{
   if(a[i][j]==search)
        { flg=1;
           break;}
   else if (a[i][j]>search)
                j--;
   else if(a[i][j]<search)
              i++;

}

if(flg==1)
     { printf("1");
       return 0;}
printf("-1");
return 0;
}

