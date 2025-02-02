/*********************************************************************************************/ /**
* Peer-graded Assignment: 
* Week 2 Assignment: Using struct
**************************************************************************************************/

/*********************************************************************************************/ /**
* Includes 
**************************************************************************************************/
#include<stdio.h>  // Standard I/O Interface
#include<stdlib.h> // Standard Library

/*********************************************************************************************/ /**
* Defines 
**************************************************************************************************/
#define DAYS_TO_PRINT   5   // JAN, FEB, MAR, OCT, DEC - used in for loop
/*********************************************************************************************/ /**
* Private typedef 
**************************************************************************************************/
typedef enum month_of_year
{
    JAN,    // 1
    FEB,    // 2
    MAR,    // 3
    APR,    // 4
    MAY,    // 5
    JUN,    // 6
    JUL,    // 7
    AUG,    // 8
    SEP,    // 9
    OCT,    //10
    NOV,    //11
    DEC     //12
} month_t;

typedef struct full_date_format
{
    month_t month;
    int     day;
} full_date_format_t;

/*********************************************************************************************/ /**
* Function and vaiables declaration
**************************************************************************************************/
int max_days;
void show_day(full_date_format_t *ptr_full_date_format_t);
full_date_format_t *show_next_day(full_date_format_t *dat);

/*********************************************************************************************/ /**
* The main method
**************************************************************************************************/
int main (void)
{
    full_date_format_t date_1 = {JAN, 1};
    full_date_format_t date_2 = {FEB, 28};
    full_date_format_t date_3 = {MAR, 14};
    full_date_format_t date_4 = {OCT, 31};
    full_date_format_t date_5 = {DEC, 31};
    full_date_format_t date[] = {date_1, date_2, date_3, date_4, date_5};
    
    for (int i = 0; i < DAYS_TO_PRINT; i ++)
    {
        printf("\n\nDate is ");
        show_day(&date[i]);

        printf(" and the next day is ");
        show_next_day(&date[i]);
        show_day(&date[i]);
    }

    printf("\n\n");

    return 0;
}

/*********************************************************************************************/ /**
* Function definition:
* show_day
* show_next_day
**************************************************************************************************/
void show_day(full_date_format_t *ptr_full_date_format_t)
{
    switch(ptr_full_date_format_t-> month)
    {
        case JAN:
            printf("January %d", ptr_full_date_format_t->day);
            max_days = 31;
            break;

        case FEB:
            printf("February %d", ptr_full_date_format_t->day);
            max_days = 28;
            break;

        case MAR:
            printf("March %d", ptr_full_date_format_t->day);
            max_days = 31;
            break;

        case APR:
            printf("April %d", ptr_full_date_format_t->day);
            max_days = 30;
            break;

        case MAY:
            printf("May %d", ptr_full_date_format_t->day);
            max_days = 31;
            break;

        case JUN:
            printf("June %d", ptr_full_date_format_t->day);
            max_days = 30;
            break;

        case JUL:
            printf("July %d", ptr_full_date_format_t->day);
            max_days = 31;
            break;

        case AUG:
            printf("August %d", ptr_full_date_format_t->day);
            max_days = 31;
            break;

        case SEP:
            printf("September %d", ptr_full_date_format_t->day);
            max_days = 30;
            break;

        case OCT:
            printf("October %d", ptr_full_date_format_t->day);
            max_days = 31;
            break;

        case NOV:
            printf("November %d", ptr_full_date_format_t->day);
            max_days = 30;
            break;

        case DEC:
            printf("December %d", ptr_full_date_format_t->day);
            max_days = 31;
            break;
    }
}

full_date_format_t *show_next_day(full_date_format_t *dat)
{
    //If last day of month, then increment month
    if (dat->day == max_days)           
    {
        dat->day = (dat->day + 1) % max_days;
        dat->month = (dat->month + 1) % 12;          // last day of the year (Mod 12)
    }
    //If not the end of month, then increment to next day
    else
        dat->day = (dat->day + 1);

  return dat;
}

/*********************************************************************************************/ /**
* Compile:      $ gcc -o day_month_struct.out day_month_struct.c
* Run:          $ ./day_month_struct.out
*
* Peer-graded Assignment: Week 2 Assignment: Using struct
* Test Output for "day_month_struct.txt"
* ************************************************************************************************
* Date is January 1 and the next day is January 2
* 
* Date is February 28 and the next day is March 1
* 
* Date is March 14 and the next day is March 15
*
* Date is October 31 and the next day is November 1
*
* Date is December 31 and the next day is January 1
**************************************************************************************************/