/*I declare that the attached assignment is wholly my
own work in accordance with Seneca Academic Policy.  No part of this
assignment has been copied manually or electronically from any
other source (including web sites) or distributed to other students.

Name:	Saad Toor   Student ID:	068964139

Assignment 1*/


#include <stdio.h>

int main(void)
{
//Declair variables
	double num;
	char choice;
	double high;
	double low;
	double total;
	double sum;
	double average;

	total=0;

	double i;

	double averageFunction;

//Ask user for number of days (input)
	printf("Weather Analyzer\n");
	printf("================\n");
	printf("Please enter a positive number of days:\t");
	scanf("%lf",&num);
	
/*If user enters 0 for number of days, then keep asking until a positive number
is entered*/
	while(num<=0)
	{
		printf("Please enter a positive number of days:\t");
		scanf("%lf",&num);
	}

//Ask the user for the high and low temperature of each day
	for(i=0;i<num;i++)
	{
		printf("Enter today's high temperature: ");
        	scanf("%lf",&high);
	 	total=total+high;

	       	printf("Enter today's low temperature:  ");
        	scanf("%lf",&low);
		total=total+low;

        	printf("Enter today's conditions, s: sunny, c: cloudy, p: precipitation: ");
		scanf(" %c",&choice);

		sum=high+low;
		average=sum/2;
	
        	printf("Today's average temperature is: %.2lf\n",average);
	
/*After asking for the condition, the output should show the following information*/
        	if(choice == 's' || choice == 'S')
        	{
            		printf("@@@@@@@@@@@@@@@@@@@@\n");
        	}
 		else if(choice == 'c' || choice == 'C')
        	{
            		printf("~~~~~~~~~~~~~~~~~~~~\n");
        	}
        	else if(choice == 'p' && average > 0)
        	{
            		printf(";;;;;;;;;;;;;;;;;;;;\n");
        	}
        	else if(choice == 'p' && average < 0)
        	{
            		printf("********************\n");
      		}

    	}
	
//Calculate the total average of each days average
	total=total/(num*2);
	printf("Average for all %.lf days is: %.2lf degrees\n",num ,total);
		
	return 0;
}
