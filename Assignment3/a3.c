#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
I declare that the attached assignment is wholly my
own work in accordance with Seneca Academic Policy.  No part of this
assignment has been copied manually or electronically from any
other source (including web sites) or distributed to other students.

Name   Saad Toor   Student ID  068964139
*/

//This program reads data from the historicaldata file and outputs the given year.
//During the year given it will output the month, and day by day condition.

/*an instance of this struct holds the weather data for a single day*/
struct DailyData{
    int day;
    int month;
    int year;
    float high;
    float low;
    float precipitation;
    char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/
struct MonthlyStatistic{
    float minTemperature;
    float maxTemperature;
    float averageTemperature;
    float totalPrecipitation;
};

const char weekdayName[13][10]={
	"","January","February","March","April",
	"May","June","July","August","September",
	"October","November","December"
};

int readDailyData(FILE* fp, struct DailyData allData[]);

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz,  struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],
                    int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[],int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw(char c, int num);

int main(void){
    FILE* fp = fopen("historicaldata.csv","r");
    if(!fp){
        printf("you need to put historicaldata.csv into this directory\n");
        exit(0);
    }
    struct DailyData  allData[3000];
    struct DailyData yearData[366];
    int numTotalRecords;

    numTotalRecords = readDailyData(fp, allData);
    int year;
    int reportType;
    int i;
    struct MonthlyStatistic monthly[12];
    printf("Please enter the year for the report: ");
    scanf("%d",&year);
    printf("Please enter the type of report you wish to generate:\n");
    printf("1) summary\n");
    printf("2) detailed\n");
    scanf("%d",&reportType);
    int numDays = getRelevantRecords(year,allData,numTotalRecords,yearData);
    sortYearData(yearData,numDays);

    for(i=0;i<12;i++){
        getStats(i+1,yearData,numDays,&monthly[i]);
    }
    printf("Weather summary for %d\n",year);
    printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
    printf("|-----------|-------|-------|-------|---------|\n");
    for(i=0;i<12;i++){
        printMonthlyStatistic(i+1,&monthly[i]);
    }
    printf("\n\n");
    printf("Precipitation Graph\n\n");
    for (i=0;i<12;i++){
        graphLine(i+1,&monthly[i]);
    }
    if(reportType == 2){
        printf("\n\n");
        printf("Detailed report:\n");
        printVerbose(yearData,numDays);
    }
    return 0;
}
//This function reads the data from the file and stores it into allData
int readDailyData(FILE* fp, struct DailyData allData[])
{
    int i=0;
    while(fscanf(fp,"%d,%d,%d,%f,%f,%f,%c\n",
        &allData[i].year,&allData[i].month,&allData[i].day,
        &allData[i].high,&allData[i].low,&allData[i].precipitation,
        &allData[i].condition) == 7){
        i++;
    }
    return i;
}
//This function takes the data from the given year and store every information in month, and day into yearData
int getRelevantRecords(int yearWanted, const struct DailyData allData[],
                                    int sz,  struct DailyData yearData[])
{
    int i;
    int j;
    j=0;


    for(i=0;i<sz;i++)
    {
        if(yearWanted == allData[i].year)
        {
            yearData[j].condition = allData[i].condition;
            yearData[j].day = allData[i].day;
            yearData[j].high = allData[i].high;
            yearData[j].low = allData[i].low;
            yearData[j].month = allData[i].month;
            yearData[j].precipitation = allData[i].precipitation;
            yearData[j].year = allData[i].year;
            j++;
        }
    }
    return j;
}
//This function sorts the month and day, from 1 to 12 for month, and 1 to the last day
void sortYearData(struct DailyData yearData[], int sz)
{
    int i;
    int j;
    struct DailyData temp;

    for(i=sz-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(yearData[j].month == yearData[j+1].month)
            {
                if(yearData[j].day > yearData[j+1].day)
                {
                    temp = yearData[j];
                    yearData[j] = yearData[j+1];
                    yearData[j+1] = temp;
                }
            }
            else
            {
                    temp = yearData[j];
                    yearData[j] = yearData[j+1];
                    yearData[j+1] = temp;
            }
        }
    }
}
//This function grabs the data from yearData, and store the High,Low,Average,Precipitation, 
//while calculating the average of each month
void getStats(int month, const struct DailyData yearData[],
                    int sz,struct MonthlyStatistic* monthly)
{
    int i;
    float pTotal;
    float high;
    float low;
    int counter;
    float sumH;
    float sumL;
    float totalHL;

    sumL = 0;
    sumH = 0;
    counter = 0;
    pTotal = 0;
    high = -273;
    low = 100;

    for(i=0;i<sz;i++)
    {
        if(yearData[i].month == month)
        {
            if(yearData[i].high > high)
            {
                    high = yearData[i].high;
            }
            if(yearData[i].low < low)
            {
                    low = yearData[i].low;
            }
            pTotal+= yearData[i].precipitation;
            sumH += yearData[i].high;
            sumL += yearData[i].low;
            counter++;
        }
    }
    totalHL = average(sumH,sumL) / counter;

    monthly->minTemperature = low;
    monthly->maxTemperature = high;
    monthly->averageTemperature = totalHL;
    monthly->totalPrecipitation = pTotal;
}
//This funtion prints the output of the MonthlyStatistic into a graph form
void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly)
{
    printf("| %9s |",weekdayName[month]);
    printf(" %5.1f |",monthly->maxTemperature);
    printf(" %5.1f |",monthly->minTemperature);
    printf(" %5.1f |",monthly->averageTemperature);
    printf(" %5.1f   |\n",monthly->totalPrecipitation);
}
//This function calculates the monthly precipitation and outputs the form
//of a graphline
void graphLine(int month,const struct MonthlyStatistic* monthly)
{
    float symNumber;
    float coun;
    int counter;
    char c;

    c = 'p';

    counter = 0;

    symNumber = monthly->totalPrecipitation + 0.5;

    coun = symNumber/10;

    counter = coun + 0.5;

    printf("%9s |",weekdayName[month]);
    draw(symbolToDraw(c,-1),counter);
}
//This function provides the information of,
//each day's information in a month, and displays all the month
//It also show the average of each day, the year, and the condition 
void printVerbose(const struct DailyData allData[],int sz)
{
    int i;
    float totalAverage;
    totalAverage = 0;

    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 1)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[1],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 2)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[2],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 3)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[3],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 4)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[4],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 5)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[5],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 6)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[6],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 7)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[7],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 8)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[8],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 9)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[9],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 10)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[10],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 11)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[11],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
    for(i=0;i<sz;i++)
    {
        if(allData[i].month == 12)
        {
            totalAverage = average(allData[i].high,allData[i].low);
            printf("%9s %2d %3d:%6.1f ",weekdayName[12],allData[i].day,allData[i].year,totalAverage);
            draw(symbolToDraw(allData[i].condition,totalAverage),20);
        }
    }
}
//This function takes the input and checks the condition
char symbolToDraw(char condition, float avgTemp)
{
    char con;
    if(condition == 's')
    {
        con = '@';
    }
    else if(condition == 'c')
    {
        con = '~';
    }
    else if(condition == 'p' && avgTemp > 0)
    {
        con = ';';
    }
    else if(condition == 'p' && avgTemp <= 0)
    {
        con = '*';
    }
    return con;
}
//This function calculates the average
float average(float first, float second)
{
    float total;

    total = (first + second)/2;

    return total;
}
//This function prints the condition, provided from symbolToDraw
void draw(char c, int num)
{
    int i;

    for(i=0;i<num;i++)
    {
        printf("%c",c);
    }
    printf("\n");
}
