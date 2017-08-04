/*Exercise 3-6. Write a version of itoa that accepts three arguments
instead of two. The third argument is a minimum field width; the 
converted number must be padded with blanks on the left if necessary 
to make it wide enough.*/

#include <stdio.h>
#include <string.h>

#define MAX 100

void itoa(int n, char s[], unsigned b);
void reverse(char s[]);

int main(void)
{
    char s[MAX]="";

    itoa(100,s,5);
    printf("%s\n", s);

    return 0;
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[], unsigned b)
{
    int sign=(n<0) ? -1:1;
    n=(sign<0) ? n*(sign):n;
    int i=0;

    do
    {
        s[i++]=n%10+'0';
    }while((n/=10)>=1);

    if (sign<0)
        s[i++]='-';

    for(int j=0;j<b;j++,i++)
        s[i]=' ';

    s[i]='\0';
    reverse(s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
