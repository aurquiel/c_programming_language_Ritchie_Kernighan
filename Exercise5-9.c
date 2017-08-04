/*Exercise 5-9. Rewrite the routines day_of_year and month_day 
with pointers instead of indexing.*/

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    printf("%d\n",day_of_year(1900,6,12));

    int month=0,day=0;

    month_day(1900, 365,&month, &day);

    printf("%d %d \n",month,day);

    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if(month<1 || month>12)
    {
        printf("Error: month<1 or month>12\n");
        return 0;
    }      

    if(day<1 || day>31)
    {
        printf("Error: day<1 or day>31\n");
        return 0;
    }

    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    char *p=&daytab[leap][1];

    for (i = 1; i < month; i++)
        day += *p++;

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    char *p=&daytab[leap][1];

    if(leap && (yearday<1 || yearday>365))
    {
        printf("Error: yearday<1 or yearday>365\n");
    }
    else if(!leap && (yearday<1 || yearday>366))
    {
        printf("Error: yearday<1 or yearday>366\n");
    }
    else
    {
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= *p++;
    }

    *pmonth = i;
    *pday = yearday;
}
