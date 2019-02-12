#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int main()
{  
 
 int choice;
 long int n,i,k;
 
 scanf("%d",&choice);
 if(choice!=1&&choice!=2)
   { printf("Invalid Choice");return 0;}
 scanf("%ld",&n);
 
 if(n<=0)
  { printf("Enter a number greater than zero .");return 0;}

 char *s=malloc(n*sizeof(char));  
 
 
      scanf(" %[^\n]%*c",s);
         
 scanf("%ld",&k);
  
 if(k>26)
    k%=26;
 
  if(choice==1)
  { for(i=0;i<n;i++)
      {if(isalpha(s[i]))
        { if(isupper(s[i]))
            	 { if(s[i]+k>=65&&s[i]+k<=90)
			s[i]+=k;
           	 else
	     		s[i]=s[i]+k-26;

	  		}
        
       
        if(islower(s[i]))
          	{ if(s[i]+k>=97&&s[i]+k<=122)
			s[i]+=k;
            	else
	     	s[i]=s[i]+k-26;

	  	}
        }
     }
}


 if(choice==2)
  { for(i=0;i<n;i++)
      {if(isalpha(s[i]))
        { if(isupper(s[i]))
            	 { if(s[i]-k>=65&&s[i]-k<=90)
			s[i]-=k;
           	 else
	     		s[i]=s[i]-k+26;

	  		}
        
       
        if(islower(s[i]))
          	{ if(s[i]-k>=97&&s[i]-k<=122)
			s[i]-=k;
            	else
	     	s[i]=s[i]-k+26;

	  	}
        }
     }
}


 


  
    printf("%s",s);
printf("\n");
return 0;  

}
