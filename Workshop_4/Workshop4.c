//Saad Toor

#include <stdio.h>

double interestrateC(double it);
double exponentC(double itTotal, double y, double pres);


int main(void)
{

	double interestRate;
	double year;
	double presentV;
	double future;

	double exponentFunction;
	double totalFunction;
	double interestRateP;

	printf("Please enter the present value: ");
	scanf("%lf",&presentV);
	printf("Please enter the interest rate: ");
	scanf("%lf",&interestRate);
	printf("Please enter the time period in years: ");
	scanf("%lf",&year);

	exponentFunction=exponentC(interestRate,year,presentV);

	interestRateP=interestRate/100;

	printf("Investment Calculator\n");
	printf("=====================\n");
	printf("Principal  :  %.lf\n",presentV);
	printf("Annual Rate:  %.2lf\n",interestRateP);
	printf("No of Years:  %.lf\n",year);
	printf("\n");
	printf("The future value is:  $%.2lf\n",exponentFunction);




	return 0;

}
double exponentC(double itTotal, double y, double pres)
{
	double futureV;
	double total;
	double itTF;
	int i;


	itTF=interestrateC(itTotal);
	
	total=1;

	for(i=0;i<y;i++)
	{
		total = total * itTF;
	}


	futureV=pres*total;


	return futureV;

}
double interestrateC(double it)
{
	double total;

	total=(it/100)+1;

	return total;
}
