/*Exercise 1-21. Write a program entab that replaces strings 
of blanks by the minimum number of tabs and blanks to achieve 
the same spacing. Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a 
tab stop, which should be given preference.*/

#include <stdio.h>

#define TABS 5

int main()
{
    int c,h;
    int multi=0;
    long counter=0;

    while((c=getchar())!=EOF)
    {
        if(c==' ')
            ++counter;
        if((counter>0)&&(c!=' '))
        {
            if(counter<TABS)
            {
                for(h=0; h<counter;h++)
                    putchar(' ');
            }
            if(counter>=TABS)
            {
                for(h=TABS; h<counter;h=h+TABS,multi++)
                    putchar('\t');
                for(counter=counter-multi*TABS;counter>0;counter--)
                    putchar(' ');
            }
            counter=0,multi=0;
        }
        if(c!=' ')
            putchar(c);
    }

    return 0;
}
