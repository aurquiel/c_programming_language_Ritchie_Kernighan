/*Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify getch and ungetch 
accordingly.*/

/* There are many ways to do this. But the easiest way is to limit the BUFSIZE to 1. No additional code necessary.
Everything remains exactly the same as in K&R. I'm skipping the main() function for brevity. */

#include <stdio.h>
#define BUFSIZE 1

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("error: stack is full, can't execute ungetch()\n");
    else
        buf[bufp++] = c;
}
