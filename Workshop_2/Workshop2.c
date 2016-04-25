//Saad Toor
#include <stdio.h>
int main(void)
{
	int numberofItems;
	double unitPrice;
	double purchasePrice;
	double hst;
	double totalPrice;
	double cashGiven;
	int changeLoonies;
	float changeCents;

	printf("Enter the number of items\t:");
	scanf("%d",&numberofItems);

	printf("Enter the unit price\t\t:");
	scanf("%lf",&unitPrice);
	
	purchasePrice=unitPrice*numberofItems;

	printf("Purchase price\t\t\t:%.2lf\n",purchasePrice);

	hst=purchasePrice*0.13;

	printf("HST(13%)\t\t\t:%.2lf\n",hst);

	totalPrice=hst+purchasePrice;

	printf("Total Price\t\t\t:%.2lf\n",totalPrice);
	
	printf("Cash tendered\t\t\t:");
	scanf("%lf",&cashGiven);
	
	changeLoonies=cashGiven-totalPrice;

	printf("Change in loonies\t\t:%d\n",changeLoonies);

	changeCents=(((cashGiven-totalPrice)*100)-changeLoonies*100);

	printf("Change in cents\t\t\t:%.f\n",changeCents);

	return 0;

}
