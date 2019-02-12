#include<stdio.h>
int main()
{
	char ch;
	FILE *reading_file,*writing_file;
        reading_file=fopen("in.txt","r");
        writing_file=fopen("out.txt","w");
        if(reading_file==NULL)
            { printf("Couldnot open in.txt file");
              return 0;
            }

	char a=' ';
        int flg=0;

 	while(fscanf(reading_file,"%c",&ch)!=EOF)
	{    if((ch=='\t'||ch==' ')&&flg==0)
                {fprintf(writing_file,"%c",a);flg=1;}
             else if((ch=='\t'||ch==' ')&&flg==1)
                continue;
             else
		{fprintf(writing_file,"%c",ch);
                 flg=0;}
    
              
             
        }
	fclose(reading_file);
        fclose(writing_file);

	return 0;

}
