//Saad Toor
//10/23/2015
//068964139
#include <stdio.h>

void simplify(int *num, int *denom);

int main(void)
{
	int numerator;
	int denominator;

	printf("Fraction Simplifier\n");
	printf("===================\n");
	printf("Numerator:   ");
	scanf("%d", &numerator);
	printf("Denominator: ");
	scanf("%d", &denominator);

	simplify(&numerator, &denominator);


	return 0;
}
void simplify(int *num, int *denom)
{
	int totalNum;
	int totalDenom;

	if(*num>*denom)
	{
		totalNum=(*num)/(*denom);
		totalDenom=(*denom)/(*denom);
	}
	else
	{
		totalNum=(*num)/(*num);
		totalDenom=(*denom)/(*num);
	}
	
	printf("%d / %d = %d / %d\n",*num, *denom, totalNum, totalDenom);

}
