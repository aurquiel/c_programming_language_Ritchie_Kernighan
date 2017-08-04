/*Exercise 5-11. Modify the program entab and detab 
(written as exercises in Chapter 1) to accept a list 
of tab stops as arguments. Use the default tab settings
if there are no arguments.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    int tab;
    if (argc>1&&isdigit(*(*++argv)))
        tab=atoi(*argv);
    else
        tab=5;

    int c;
    while((c=getchar())!=EOF)
    {
        if(c=='\t')
            for(int i=0;i<tab;i++)
                putchar(' ');
        else
            putchar(c);
    }

    return 0;
    }
