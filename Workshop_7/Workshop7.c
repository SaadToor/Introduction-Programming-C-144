//Saad Toor
#include <stdio.h>
#include <stdlib.h>

int storageFunction(long long bc[], int numberOfItems[], double pric[], int counter);

int main(void)
{
	long long barcode;
    	int arrayCounter;
    	long long arrayBarcode[100];

    	int quantity;
    	int arrayQuantity[100];

    	double price;
    	double arrayPrice[100];

    	arrayCounter = 0;

	printf("Grocery Store Inventory\n");
    	printf("=======================\n");

    	printf("Barcode  :  ");
    	scanf("%lld",&barcode);

    	while(barcode > 0)
    	{
            	arrayBarcode[arrayCounter] = barcode;
        	printf("Price    :  ");
        	scanf("%lf",&price);
        	arrayPrice[arrayCounter] = price;
        	printf("Quantity :  ");
        	scanf("%d",&quantity);
		arrayQuantity[arrayCounter] = quantity;
		arrayCounter ++;

	    	printf("Barcode  :  ");
    		scanf("%lld",&barcode);
    
	}

	storageFunction(arrayBarcode,arrayQuantity,arrayPrice,arrayCounter);

    	return 0;
}
int storageFunction(long long bc[], int numberOfItems[], double pric[], int counter)
{
    	int i;
    	double value;

    	double total;
	total = 0;

    	printf("\t\tGoods in Stock\n");
    	printf("\t\t==============\n");
    	printf("Barcode \tPrice \tQuantity \tValue\n");
    	printf("---------------------------------------------\n");

    	for(i=0;i<counter;i++)
    	{
        	value = (pric[i])*(numberOfItems[i]);
        	printf("%lld",bc[i]);
	        printf("%11.2lf",pric[i]);
		printf("%11d",numberOfItems[i]);
		printf("%13.2lf\n",value);
		total = total + value;
	}
	printf("\t\t\t\t\t ----\n");
	printf("%45.2lf\n",total);

	return total;

}
