/*Exercise 4-12. Adapt the ideas of printd to write a recursive version of 
itoa; that is, convert an integer into a string by calling a recursive routine.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void itoa(int num, char s[]);
char line[SIZE];

int main()
{
    itoa(123,line);
    printf("%s\n",line);
    return (EXIT_SUCCESS);
}

void itoa(int num, char s[])
{
    static int atoi_i=0;

    if(num<0)
    {
        s[atoi_i++]='-';
        num=-num;
    }

    if(num!=0&&num!=1)
        itoa(num/10,s);

    s[atoi_i++]=num%10+'0';
    s[atoi_i]='\0';
}
