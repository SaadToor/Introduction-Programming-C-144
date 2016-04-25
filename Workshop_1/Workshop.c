#include <stdio.h>
int main(void)
{
	int numberofItems;
	float unitPrice;
	float purchasePrice;
	float hst;
	float totalPrice;
	float cashGiven;
	int changeLoonies;
	float changeCents;

	printf("Enter the number of items:");
	scanf("%d",&numberofItems);

	printf("Enter the unit price:");
	scanf("%f",&unitPrice);
	
	purchasePrice=unitPrice*numberofItems;

	printf("Purchase price: %.2f\n",purchasePrice);

	hst=purchasePrice*0.13;

	printf("HST(13%):%.2f\n",hst);

	totalPrice=hst+purchasePrice;

	printf("Total Price: %.2f\n",totalPrice);
	
	printf("Cash tendered: ");
	scanf("%f",&cashGiven);
	
	changeLoonies=cashGiven-totalPrice;

	printf("Change in loonies:%d\n",changeLoonies);

	changeCents=(totalPrice-changeLoonies)*100;

	printf("Change in cents: %d\n",changeCents);

	return 0;

}
