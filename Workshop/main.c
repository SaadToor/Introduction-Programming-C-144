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

    printf("%d / %d =",numerator,denominator);

    return 0;
}
void simplify(int *num, int *denom)
{
    int totalNum;
    int totalDenom;

    if(*num>*denom)
    {
        totalNum=(*num)/(*num);
        totalDenom=(*denom)/(*num);
    }
    else
    {
        totalNum=(*num)/(*denom);
        totalDenom=(*denom)/(*denom);
    }
}
