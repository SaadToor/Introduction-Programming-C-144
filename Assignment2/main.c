#include <stdio.h>
#include <stdlib.h>

 void clear(void)
 {
    while (getchar() != '\n')
        ;
 }
int getInteger(int min, int max);
void getDailyData(float* high, float* low, char * condition);
void draw(char c, int num);
float average(float first, float second);
void displayResult(int days, float allDaysAverage);
char symbolToDraw(char condition, float averageTemperature);

int main(void)
{
    int numDays;
    int i;
    float sum = 0;
    float dailyHigh;
    float dailyLow;
    char conditions;
    float dailyAvg = 0;

    printf("Weather Analyzer 2.0\n");
    printf("====================\n");
    printf("How many days of data? \n");
    numDays = getInteger(1,14);
    for(i = 0; i < numDays; i++)
    {
        getDailyData(&dailyHigh, &dailyLow, &conditions);
        dailyAvg = average(dailyHigh, dailyLow);
        printf("Today’s average temperature is: %.2f\n", dailyAvg);
        sum += dailyAvg;
	draw(symbolToDraw(conditions, dailyAvg), 20);
    }

    displayResult(numDays, (sum/numDays));

    return 0;
}
int getInteger(int min, int max)
{
    int days;

    printf("Enter an integer between 1 and 14: ");
    scanf("%d",&days);

    while(days < min || days > max)
    {
        printf("ERROR! Try again!\n");
        printf("Enter an integer between 1 and 14: ");
        scanf("%d",&days);
    }
    return days;
}
void getDailyData(float* high, float* low, char * condition)
{
    int rc;

    printf("Enter today's high, low, and condition (c=cloudy, s=sunny, p=precipitation)\n");
    printf("separated by commas:");
    rc = scanf("%f, %f, %c",&*high,&*low,&*condition);

    while(*low > *high || rc != 3)
    {
        printf("ERROR! Try again!\n");
        printf("Enter today's high, low, and condition (c=cloudy, s=sunny, p=precipitation)\n");
        printf("separated by commas:");
        scanf("%f, %f, %c",&*high,&*low,&*condition);
    }
}
void draw(char c, int num)
{
    int i;

    for(i=0;i < num;i++)
    {
        symbolToDraw(c,i);
    }
}
float average(float first, float second)
{
        float total;

        total = (first + second)/2;

        return total;
}
void displayResult(int days, float allDaysAverage)
{
     if(days == 1)
        {
                printf("Your one day average is : %.2f\n",allDaysAverage);
        }
        else if(days == 2)
        {
                printf("Your two day's average is : %.2f\n",allDaysAverage);
        }
        else if(days == 3)
        {
                printf("Your three day's average is : %.2f\n",allDaysAverage);
        }
        else if(days == 4)
        {
                printf("Your four day's average is : %.2f\n",allDaysAverage);
        }
        else if(days == 5)
        {
                printf("Your five day's average is : %.2f\n",allDaysAverage);
        }
        else if(days == 6)
        {
                printf("Your six day's average is : %.2f\n",allDaysAverage);
        }
        else if(days == 7)
        {
                printf("Your seven day's average is : %.2f\n",allDaysAverage);
        }
        else if(days == 8)
        {
                printf("Your eight day's average is : %.2f\n",allDaysAverage);
        }
        else if(days == 9)
        {
                printf("Your nine day's average is : %.2f\n",allDaysAverage);
        }
        else
        {
                printf("Your %d day's average is : %.2f\n",days,allDaysAverage);
        }
}
char symbolToDraw(char condition, float averageTemperature)
{
    if(condition == 's' || condition == 'S')
    {
        printf("@");
    }
    else if(condition == 'c' || condition == 'C')
    {
        printf("~");
    }
    else if(condition == 'p' && averageTemperature > 0)
    {
        printf(";");
    }
    else if(condition == 'p' && averageTemperature < 0)
    {
        printf("*");
    }
    return condition;
}
