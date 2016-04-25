#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*V 1.1:
Changes:

1) declared i outside of loop, you don't need -std=c99 to compile anymore
2) added a check for existence of historicaldata.csv
*/

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
void getStats(int month, const struct DailyData yearData[],
                    int sz,struct MonthlyStatistic* monthly)
{
    int j;
    int i;
    float sum;

    j=0;

    for(i=0;i<sz;i++)
    {
        if(yearData[month].month == month)
        {
            monthly[j].minTemperature = yearData[i].low;
            monthly[j].maxTemperature = yearData[i].high;
            monthly[j].totalPrecipitation = yearData[i].precipitation;
            monthly[j].averageTemperature = average(yearData[i].high,yearData[i].low);
            j++;
        }
    }
}
void printMonthlyStatistic(int month,const struct MonthlyStatistic* monthly)
{
    printf("| %9s |",weekdayName[month]);
    printf(" %5.1f |",monthly[month].maxTemperature);
    printf(" %5.1f |",monthly[month].minTemperature);
    printf(" %5.1f |",monthly[month].averageTemperature);
    printf(" %5.1f   |\n",monthly[month].totalPrecipitation);
}
void graphLine(int month,const struct MonthlyStatistic* monthly)
{
    int symNumber;
    float coun;
    int counter;
    char c;

    c = 'p';

    counter = 0;

    symNumber = monthly[month].totalPrecipitation + 0.5;

    coun = monthly[month].totalPrecipitation/10;

    counter = coun + 0.5;

    printf("%9s |",weekdayName[month]);
    draw(symbolToDraw(c,monthly[month].averageTemperature),counter);
}
void printVerbose(const struct DailyData allData[],int sz)
{


}
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
    else
    {
        con = '*';
    }
    return con;
}
float average(float first, float second)
{
    float total;

    total = (first + second)/2;

    return total;
}
void draw(char c, int num)
{
    int i;

    for(i=0;i<num;i++)
    {
        printf("%c",symbolToDraw(c,i));
    }
    printf("\n");
}
