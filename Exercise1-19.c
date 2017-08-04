/*Exercise 1-19. Write a function reverse(s) that reverses the 
character string s. Use it to write a program that reverses its
input a line at a time.*/

#include <stdio.h>

#define MAXLINE 5000   /* maximum input line length */
int get_line(char line[], int maxline);
void reverse(char s[]);

/* print the longest input line */
main()
{
    int len;            /* current line length */
    char line[MAXLINE];    /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > 0)
        {
            reverse(line);
            printf("%s",line);
        }

    return 0;
}
/* getline:  read a line into s, return length  */
int get_line(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[])
{
    int size=0;

    while(s[size]!='\0')
        ++size;

    char temp;

    for(int i=size-2,j=0 ; i>=size/2; i--,j++ )
    {
        temp=s[j];
        s[j]=s[i];
        s[i]=temp;
    }
}
