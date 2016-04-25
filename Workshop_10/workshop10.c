//Saad Toor
//068964139
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char con;
	char name[100];
	char name2[100];
    	int ch;

	printf("Change Case\n");
	printf("===========\n");
	printf("Case (U for upper, L for lower) : ");
	scanf(" %c",&con);

	FILE* fp = NULL;
	FILE* fp2 = NULL;

    	printf("Name of the original file : ");
    	scanf("%s",&name);
    	fp = fopen(name,"r");

    	printf("Name of the updated file  : ");
    	scanf("%s",&name2);
    	fp2 = fopen(name2,"w");

    	if(con == 'U')
    	{
        	while(!feof(fp))
        	{
            		ch = fgetc(fp);
            		if(ch != EOF)
            		{
                		fputc(toupper(ch),fp2);
			}
		}
        	fclose(fp);
        	fclose(fp2);
    	}
    	else if(con == 'L')
    	{
        	while(!feof(fp))
        	{
            		ch = fgetc(fp);
            		if(ch != EOF)
            		{
                		fputc(tolower(ch),fp2);
            		}

        	}
        	fclose(fp);
        	fclose(fp2);
    	}
	printf("Text has been updated and stored in %s\n",name2);

	return 0;
}
