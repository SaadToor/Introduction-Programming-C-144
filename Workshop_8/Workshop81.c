//Saad Toor
#include <stdio.h>
#include <string.h>

char wordCount(char prompt[]);

int main(void)
{
	char str[100];

	printf("Word Counter\n");
	printf("============\n");
	printf("Text to be analyzed : ");
	scanf("%[^\n]", &*str);
	wordCount(str);

	return 0;
}
char wordCount(char prompt[])
{
	int count;
	int i;

	count = 0;

	for(i=0;prompt[i] != '\0';i++)
	{
		if(prompt[i] == ' ')
			count++;
	}
	printf("Word count          : %d\n",count + 1);
	return count;
}
