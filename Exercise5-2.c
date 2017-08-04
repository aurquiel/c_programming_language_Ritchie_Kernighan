/*Exercise 5-2. Write getfloat, the floating-point analog of getint. 
What type does getfloat return as its function value ?*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

double array[SIZE];

int main()
{
    int n, getint(double *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    for (int i=0;i<SIZE;i++)
        printf("%g ",array[i]);

    return (EXIT_SUCCESS);
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(double *pn)
{
    int c, sign,decimal=1;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it is not a number */
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c))
        ungetch((sign==1) ? '+':'-');


    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    if (c=='.')
        c=getch();

    for (; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
        decimal*=10;
    }

    *pn *= sign;
    *pn=*pn/decimal;

    if (c != EOF)
        ungetch(c);

    return c;
}

#define BUFSIZE 100
int buf[BUFSIZE];/* buffer for ungetch */
int bufp = 0;/* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

