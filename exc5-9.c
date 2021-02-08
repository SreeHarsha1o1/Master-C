/*Exercise 5-9
    Rewrite the routines day_of_year and month_day with pointers instead of indexing*/
#include<stdio.h>

static char daytab[2][13] = { {0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31} };

int day_of_year(int year,int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    printf("leap = %d\n",leap);
   
    if(day <= 31 && month <= 12)
    {
        for(i = 1; i < month; i++)
            day += *(*(daytab+leap)+i);
        printf("the no of days:%d\n",day);
        return day;
    }
    else
    {
        printf("the day and month inputs are not valid\n");
        return -1;
    }
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    printf("leap = %d\n",leap);

    if(yearday < 0 || yearday > 365)
    {
        printf("yearday is greater than 365 or less than 1\n");
        return -1;
    }
    else
    {
        for(i = 1;yearday > *(*(daytab+leap)+i);i++)
        {
            yearday -= *(*(daytab+leap)+i);
            // printf("i=%d\n",i);
        }
        *pmonth = i;
        *pday = yearday;
        printf("month: %d, day: %d year: %d\n", *pmonth, *pday, year);
    }
    return 1;  
}

int main()
{
    int year = 1978;
    int month = 12;
    int day = 10;

    int yearday;

    yearday = day_of_year(year, month, day);
    //printf("the no of days:%d\n",yearday);

    month_day(year,yearday, &month, &day);
    //printf("month: %d, day: %d year: %d\n", month, day, year);

    return 0;
}
