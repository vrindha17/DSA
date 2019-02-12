#include<stdio.h>
#include<ctype.h>
#include<string.h>
void pushstr(char *str);
void popstr(char *str);
void concat(char *temp1,char *temp2);
void print_string_stack();
void print_num_stack();
void push(int a);
int pop();


int stack[10000],top=-1,strtop=-1;
char strstack[10000][10000];



int main()
{
	char string[10000];
        scanf("%[^\n]%*c",string);


	
        char sub[10000];
	int i,a=0;
	int k=0,u=0;
 	for(i=0;string[i]!='\0';i++)
            {//printf("%c\n",string[i]);



                 if (string[i]=='*')
			{ 
                          char temp1[10000],temp2[10000];
                          popstr(temp1);
                          popstr(temp2);
			  u=strlen(temp2);
                          
                          temp2[u]=string[i];
			  temp2[u+1]='\0';

			 strcat(temp2,temp1);
                         pushstr(temp2);
//printf("%s\n",temp2);

 			  int t1=pop();
                          int t2=pop();
			  t1*=t2;
	                  push(t1); 
			  
				}
			
                   else if (string[i]=='/')
			{  char temp1[10000],temp2[10000];
                          popstr(temp1);
                          popstr(temp2);
			  u=strlen(temp2);
                          
                          temp2[u]=string[i];
			  temp2[u+1]='\0';

			 strcat(temp2,temp1);
			pushstr(temp2);
//printf("%s\n",temp2);


 			  int t1=pop();
                          int t2=pop();
			  t2/=t1;
	                  push(t2); 
				}
			

                 else if (string[i]=='+')
			{  


			char temp1[10000],temp2[10000];
                          popstr(temp1);
                          popstr(temp2);
			  u=strlen(temp2);
                          
                          temp2[u]=string[i];
			  temp2[u+1]='\0';

			 strcat(temp2,temp1);
			pushstr(temp2);
//printf("%s\n",temp2);

 			  int t1=pop();
                          int t2=pop();
			  t1+=t2;
	                  push(t1); 
				}


                 else if (string[i]=='-')
			{  char temp1[10000],temp2[10000];
                          popstr(temp1);
                          popstr(temp2);
			  u=strlen(temp2);
                          
                          temp2[u]=string[i];
			  temp2[u+1]='\0';

			 strcat(temp2,temp1);
			pushstr(temp2);
//printf("%s\n",temp2);


 			  int t1=pop();
                          int t2=pop();
			  t2-=t1;
	                  push(t2); 
				}
  

         
  

		else if(isdigit(string[i]))
		      	{  if(i!=0&&string[i-1]==' ')
				a=0;
                           sub[k]=string[i];
			   k++;
                           a*=10;  
                           a+=string[i]-'0';
                           
                                }
                
		else if(string[i]==' '&& isdigit(string[i-1]))
 			{     sub[k]='\0';
                                pushstr(sub);
//printf("%s\n",sub);
				push(a);
                             a=0;k=0;}
                
	  	             	



            }


print_string_stack(); 
printf("\n");    
print_num_stack();
return 0;
}


void push(int a)
{
	top++;
	stack[top]=a;
	return;
}

int pop()
{
  	if(top==-1)
	{printf("Stack Underflow");return -1;}
	int a=stack[top];
 	top--;
	return a;
}

void print_num_stack()
{
int i;
for(i=0;i<=top;i++)
	printf("%d ",stack[i]);

printf("\n");
return;
}

void pushstr(char *str)
{
	strtop++;
	strcpy(strstack[strtop],str);
	return;

}

void popstr(char *str)
{

	strcpy(str,strstack[strtop]);
        strtop--;
	return;

}



void print_string_stack()
{int i;
	for(i=0;i<=strtop;i++)
	
	printf("%s",strstack[strtop]);


}











