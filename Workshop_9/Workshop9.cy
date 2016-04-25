#include <stdio.h>
#include <stdlib.h>

struct Fraction
{
	int numerator;
	int denominator;
};

void enter(struct Fraction* f);
void simplify(struct Fraction* f);
void display(struct Fraction* f);

int main(void)
{
	struct Fraction f;

	printf("Fraction Simplifier\n");
	printf("===================\n");

	enter(&f);
	simplify(&f);
	display(&f);

	return 0;
}
void enter(struct Fraction* f)
{
	printf("Numerator:   ");
	scanf("%d",&f->numerator);
	printf("Denominator: ");
	scanf("%d",&f->denominator);
}
void simplify(struct Fraction* f)
{
	if(f->numerator > f->denominator)
	{
		f->denominator = (f->denominator)/(f->denominator);
		f->numerator = (f->denominator)/(f->numerator);
	}
	else
	{
		f->numerator = (f->numerator)/(f->numerator);
		f->denominator = (f->denominator)/(f->numerator);
	}
}
void display(struct Fraction* f)
{
	printf("%d / %d\n",f->numerator,f->denominator);
}
