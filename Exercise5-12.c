/*Exercise 5-12. Extend entab and detab to accept the shorthand
entab -m +n
to mean tab stops every n columns, starting at column m. Choose 
convenient (for the user) default behavior.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    int tab=0;
    int m=0,n=0;

    if (argc>1)
    {
        for(;argc>0;--argc,++argv)
        {
            if(**argv=='-')
            {
                m=atoi( (*argv+1) );
            }
            if(**argv=='+')
            {
                n=atoi( (*argv+1) );
            }
        }

    tab=m-n;
    }
    else
        tab=5;

    if (tab<0)
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
