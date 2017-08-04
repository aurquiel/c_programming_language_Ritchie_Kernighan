/*Exercise 2-10. Rewrite the function lower, which converts
upper case letters to lower case, with a conditional expression
instead of if-else. */

#include <stdio.h>

int lower(int);

int main()
{
    printf("%c %d \n",lower('H'),lower('H'));
    return 0;
}

int lower(int c)
{
    return (c>='A'&& c<='Z') ? (c-'A'+'a') : (-1);
}
