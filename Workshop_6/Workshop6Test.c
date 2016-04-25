//Saad Toor
//11/3/2015
//Student Number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomCalculator(int totalSought);

int main(void)
{
	int totalSought;
	
	int validationF;
	int randomGeneratorF;


	printf("Game of Dice\n");
	printf("============\n");
	printf("Enter total sought : ");
	scanf("%d",&totalSought);
	
	while(totalSought > 12 || totalSought < 2)
	{
		printf("** Invalid Input! Try Again! **\n");
        	printf("Enter total sought : ");
        	scanf("%d",&totalSought);
    	}


    	randomGeneratorF = randomCalculator(totalSought);

	return 0;
}
int randomCalculator(int totalSought)
{
    	int diceNumbers;
    	int randomNumber;
    	int randomNumber2;
    	int throws;

    	throws = 0;
    	srand(time(NULL));

    	while(diceNumbers != totalSought)
    	{
        	randomNumber = (rand() % 6) + 1;
        	randomNumber2 = (rand() % 6) + 1;
        	diceNumbers = randomNumber + randomNumber2;
        	throws = throws + 1;
        	printf("Result of throws  %d : %d + %d\n",throws,randomNumber, randomNumber2);
    	}

    	if(diceNumbers == totalSought && throws > 1)
    	{
        	printf("You got your total in %d throws!\n",throws);
    	}
	else
	{
        	printf("You got your total in %d throws!\n",throws);		
	}
}
