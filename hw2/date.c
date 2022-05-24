#include "date.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct Date 
{
    const char* month; 
    int day; 
    int year; 
};


int checkLeap(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else return 0;
        }
        else 
            return 1;
    }
    else 
        return 0;
}


int check_valid(const char* month, int day, int year)
{
    int month_isvalid = 0;
    int day_isvalid = 0;   
    int year_isvalid = 0; 

    char* valid_months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", \
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    int valid_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // checking VALID YEAR 
    if (year > 0) 
        year_isvalid = 1;
    else
        return 0;

    // checking VALID MONTH
    unsigned month_idx;
    for (unsigned i = 0; i < 12; i++)
    {
        // if (month == valid_months[i])
        if (!strcmp(month, valid_months[i]))
        {
            month_isvalid = 1;
            month_idx = i;
            break;
        }
       
    }
    if (!month_isvalid)
        return 0;

    // checking LEAP YEAR, FEB MONTH
    if (month_idx == 1 && checkLeap(year))
    {
        if (day > 0 && day < 30) 
            day_isvalid = 1;
    }

    // checking VALID DAY
    if (day > 0 && day < valid_days[month_idx] + 1)
        day_isvalid = 1;

    if (month_isvalid && day_isvalid && year_isvalid)
        return 1;
    else 
        return 0;
   
}


int checkYear(int year)
{
    if (year > 0)
        return 1; 
    else 
        return 0; 
}


int checkMonth(const char* month)
{   
    char* valid_months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", \
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    for (unsigned i = 0; i < 12; i++)
    {
        if (!strcmp(month, valid_months[i]))
          return 1; 
    }
    return 0;
}


int checkDay(int day, const char* month)
{
    char* valid_months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", \
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    int valid_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (unsigned i = 0; i < 12; i++)
    {
        if (strcmp(month, valid_months[i]))
        {
            if (day <= valid_days[i])
            {
                return 1;
            }
        }
    }
    return 0;          
}


struct Date* createDate(const char* month, int day, int year)
{  
    if (check_valid(month, day, year))
    {
        struct Date* d = malloc(sizeof(struct Date));
        char* month_cpy = malloc(4 * sizeof(char));
        strcpy(month_cpy, (char*) month);
        d->month = month_cpy; 
        d->day = day; 
        d->year = year; 
        return d;
    }
    else
        return NULL;  
}


int destroyDate(struct Date* d) 
{
    if (d)
    {
        free(d);
        return 1; 
    } 
    else 
        return 0;
}


char* getMonth(const struct Date* date)
{    
    if (date) 
    {
        char* ret = malloc(4 * sizeof(char));
        strcpy(ret, (char*) date->month); 
        return ret;
    }
    else
        return 0;
}


int getDay(const struct Date* date)
{
    if (date)
       return date->day;       
    else 
        return 0; 
}


int getYear(const struct Date* date) 
{
    if (date) 
        return date->year; 
    else 
        return 0; 
}


int setMonth(struct Date* date, const char* month)
{
    if (date && checkMonth(month))
    { 
        // struct Date* tmp = createDate(month, date->day, date->year);
        // date = tmp;
        // free(tmp);
        date->month = month;
        return 1;
    }
    else
        return 0;
}


int setDay(struct Date* date, int day)
{
    if (date && checkDay(day, date->month))
    {
       date->day = day;
       return 1;
    }
    else
        return 0;
}


int setYear(struct Date* date, int year)
{
    if (date && checkYear(year))
    {
        date->year = year; 
        return 1; 
    }
    else
        return 0;
}


int compareDay(const struct Date* d1, const struct Date* d2)
{
    if (d1 && d2)
    {
        if (d1 == d2)
            return 0;
        // comparing YEAR
        if (d1->year < d2->year)
            return -1;
        else if (d1->year > d2->year) 
            return 1;
        else
        {
            // comparing MONTH
            unsigned month1_idx, month2_idx; 
            char* months[] =  {"Jan", "Feb", "Mar", "Apr", "May", "Jun", \
                               "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

            for (unsigned i = 0; i < 12; i++)
            {
                 if (d1->month == months[i])
                 {
                    month1_idx = i;
                    break;
                 }
            }
            for (unsigned i = 0; i < 12; i++)
            {
                if (d2->month == months[i])
                {
                    month2_idx = i; 
                    break;
                }
            }
            if (month1_idx < month2_idx) 
                return -1; 
            else if (month1_idx > month2_idx) 
                return 1; 
            else
            {
                if (d1->day < d2->day) 
                    return -1; 
                else if (d1->day > d2->day)
                    return 1; 
                else 
                    return 0;
            }
        }
    }
    else 
        return -2;
}


int nextDay(struct Date* date)
{
    if (date)
    {
        int valid_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        char* valid_months[] =  {"Jan", "Feb", "Mar", "Apr", "May", "Jun", \
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        
        int month_idx = -1;
        for (unsigned i = 0; i < 12; i++)
        {
            if (date->month == valid_months[i])
            {
                month_idx = i; 
                break;
            }
        }
        
        if (date->day < valid_days[month_idx])
        {
            date->day = date->day + 1; 
            return 1;
        }
        else 
        {
            if (month_idx < 11)
            {
                date->month = valid_months[month_idx + 1];
                date->day = 1; 
                return 1; 
            }
            else
            {
                date->year = date->year + 1; 
                date->month = "Jan"; 
                date->day = 1;
                return 1;
            }
        }    
    }
    else 
        return 0;
}


