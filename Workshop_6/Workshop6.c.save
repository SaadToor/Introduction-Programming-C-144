//Saad Toor
//11/3/2015
//068964139

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validation(const char* prompt, int max, int min);
int randomCalculator(int totalSo);

int main(void)
{
	int totalSought;
	int max;
	int min;
	
	max = 12;
	min = 2;
	
	int randomGeneratorF;


	printf("Game of Dice\n");
	printf("============\n");


//totalSought = validation("Enter total Sought : ",12,2);

	totalSought = validation("Enter total Sought : ",max,min);

    	randomGeneratorF = randomCalculator(totalSought);

	return 0;
}
int validation(const char* prompt, int max, int min)
{
	
	int totalSought;

	printf("%s",prompt);
	scanf("%d",&totalSought);


	while(totalSought > max || totalSought < min)
	{
		printf("** Invalid Input! Try Again! **\n");
        	printf("Enter total sought : ");
        	scanf("%d",&totalSought);
    	}

	return totalSought;
}
int randomCalculator(int totalSo)
{
    	int diceNumbers;
    	int randomNumber;
    	int randomNumber2;
    	int throws;

    	throws = 0;
    	srand(time(NULL));

       	randomNumber = (rand() % 6) + 1;
       	randomNumber2 = (rand() % 6) + 1;
       	diceNumbers = randomNumber + randomNumber2;
       	throws = throws + 1;
       	printf("Result of throws  %d : %d + %d\n",throws,randomNumber, randomNumber2);


    	while(diceNumbers != totalSo)
    	{
	       	randomNumber = (rand() % 6) + 1;
       		randomNumber2 = (rand() % 6) + 1;
       		diceNumbers = randomNumber + randomNumber2;
        	throws = throws + 1;
        	printf("Result of throws  %d : %d + %d\n",throws,randomNumber, randomNumber2);
    	}
        
	if(throws > 1)
	{	
		printf("You got your total in %d throws!\n",throws);
	}
	else
	{
		printf("You got your total in %d throw!\n",throws);	
	}
}
