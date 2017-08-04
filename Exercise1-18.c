/*Exercise 1-18. Write a program to remove trailing blanks and tabs 
from each line of input, and to delete entirely blank lines.*/


#include <stdio.h>

#define MAXLINE 5000   /* maximum input line length */
int get_line(char line[], int maxline);
void elimate_blanks_ends(const char s[],char new_line[]);

/* print the longest input line */
main()
{
    int len;            /* current line length */
    char line[MAXLINE];    /* current input line */
    char new_line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > 0)
        {
            elimate_blanks_ends(line,new_line);
            printf("%s",new_line);
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

void elimate_blanks_ends(const char s[],char new_line[])
{

    int i,j=0;

    while(s[j]!='\0')
        ++j;

    int flag=0;

    for(i=j; i>=0; i--)
    {
        if( (s[i]==' '|| s[i]=='\t' || s[i]=='\n' || s[i]=='\0')  &&  (!flag) )
        {
            //noting
        }
        else
        {
            flag=1;
            new_line[i]=s[i];
        }
    }
}

