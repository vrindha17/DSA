
#include<stdio.h>
#include<stdlib.h>

void reverse(char s[],int b,int a)
{
	if(a==b)
           {printf("\b%s",s);}
      else if(a>b)
           {printf("%s",s);}
          
    else
           {
                 char temp=s[a];
                 s[a]=s[b];
                 s[b]=temp;
                 reverse(s,b-1,a+1);
		}
        

}
void main()
{       char *s,c;
int i=0,j=1;
s = (char*)malloc(sizeof(char));
c= getchar();
while(c!='\n')

{

s = (char*)realloc(s,sizeof(char)*j);
s[i]=c;
i++;j++;
c= getchar();
}
s[i]='\0';
reverse(s,i-1,0);
        }

