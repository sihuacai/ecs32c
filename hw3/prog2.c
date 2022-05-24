#include <stdio.h>

// part 1
void sum3(int a, int b, int c, int* sum)
{
    if (sum)
        *sum = a + b + c;
}


// part 2
void replaceIfHigher(long* arr, unsigned len)
{
    long user[100];
    for (unsigned i = 0; i < len; i++)
        scanf("%ld", &user[i]);

    for (unsigned i = 0; i < len; i++)
        if (user[i] > arr[i])
            arr[i] = user[i];
}


// part 3
char* strrstr(char* haystack, char* needle)
{
    char* last = NULL; 
    char* needle_reset = needle; 
    while (*haystack != '\0')
    {
        if (*haystack == *needle) 
        {
            char* hold = haystack; 
            while (*needle != '\0') 
            {
                if (*haystack == *needle) 
                {
                    haystack++; 
                    needle++; 
                }
                else
                {
                    last = NULL; 
                    break;
                }  
            }
            last = hold; 
            needle = needle_reset;
        }
        haystack++;
    }
    return (last);
}


// part 4
int eachContains(char** strings, char target, 
                 unsigned numStrings, char* firstOffending)
{
    char* string_copy[numStrings];
    for (unsigned j = 0; j < numStrings; j++)
        string_copy[j] = strings[j]; 

    char** copy_ptr = string_copy;

    unsigned i = 0; 
    while (i < numStrings)
    {
        while(**strings != '\0' && i < numStrings)
        {
            if (**strings == target)
            {
                i++; 
                strings++; 
                copy_ptr++; 
                continue;
            }
            else 
            {   
                (*strings)++; 
                if (**strings == '\0')
                {
                    firstOffending = *copy_ptr; 
                    return 0;
                }
            }
        }
        i++; 
        strings++;
        copy_ptr++;
    }
    return 1;
}
