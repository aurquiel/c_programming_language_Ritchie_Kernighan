/*Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

main()
{
    int c;
    long int blank=0,new_line=0,tab=0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++new_line;
        else if (c == ' ')
            ++blank;
        else if (c == '\t')
            ++tab;
    }

    printf("\nblank=%ld \t new_line=%ld \t tab=%ld \n",blank,new_line,tab);
}
