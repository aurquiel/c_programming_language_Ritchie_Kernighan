/*Exercise 1-14. Write a program to print a histogram of the
frequencies of different characters in its input. */

#include <stdio.h>

main()
{
    int c;

    while((c=getchar())!=EOF)
    {
        if (c==' ')
            putchar('&');
        else if(c=='\t')
            putchar('%');
        else if(c=='\n')
            putchar('$');
        else if(c=='\b')
            putchar('*');
        else if (c>='0'&&c<='9')
            putchar('!');
        else if (c>='A'&&c<='Z')
            putchar('=');
        else if (c>='a'&&c<='z')
            putchar('-');
        else
            putchar(c);
    }
}
