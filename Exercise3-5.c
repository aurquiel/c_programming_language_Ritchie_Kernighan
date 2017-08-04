/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer
n into a base b character representation in the string s. In particular,
itob(n,s,16) formats s as a hexadecimal integer in s.*/

#include <stdio.h>
#include <string.h>

#define MAX 100

void itoa(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char s[MAX]="";

    itoa(100,s,2);
    printf("%s\n", s);
    itoa(-173,s,8);
    printf("%s\n", s);
    itoa(324832902,s,16);
    printf("%s\n", s);

    return 0;
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[], int b)
{
    int sign=(n<0) ? -1:1;
    n=(sign<0) ? n*(sign):n;
    int i=0;

    do
    {
        s[i++]=(n%b>9) ? (n%b-10+'A'):(n%b+'0');
    }while((n/=b)>=1);

    if (sign<0)
        s[i++]='-';
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
