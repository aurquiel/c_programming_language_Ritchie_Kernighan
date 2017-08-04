/*Exercise 5-13. Write the program tail, which prints the last 
n lines of its input. By default, n is set to 10, let us say, 
but it can be changed by an optional argument so that
tail -n
prints the last n lines. The program should behave rationally
no matter how unreasonable the input or the value of n. Write 
the program so it makes the best use of available storage; 
lines should be stored as in the sorting program of Section 5.6,
not in a two-dimensional array of fixed size.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumPtr 100

char *lineptr[NumPtr];

#define MAXLINE 1000

char line[MAXLINE];

size_t get_line(char* f_line, int n);

#define MAXALLOC 5000
char buf_alloc[MAXALLOC];
char *p_alloc=buf_alloc;

char* alloc(char*);

int main(int argc, char* argv[])
{
    int n=5;

    while(--argc>0)
    {
        if(*(*++argv)=='-')
            n=atoi(*(argv)+1);
    }

    unsigned int len;
    int i=0;
    while((len=get_line(line,MAXLINE))>0)
    {
        if((lineptr[i++]=alloc(line))==NULL)
            break;
    }

    for(int i=0; i<n; i++)
        printf("%s\n",lineptr[i]);

    return EXIT_SUCCESS;
}

size_t get_line(char* f_line, int n)
{
    int c;
    size_t size=(size_t)f_line;

    while(((size_t)f_line-size)<n && (c=getchar())!=EOF && c!='\n')
        *f_line++=c;

    *(f_line)='\0';

    return (size_t)f_line-size;
}

char* alloc(char* s)
{
    char* p_end = buf_alloc+MAXALLOC-1;
    size_t len=strlen(s)+1;

    if(p_alloc+len<p_end) //There is space in allof buffer
    {
        strcpy(p_alloc,s); //insert buffer
        p_alloc+=len;
        return p_alloc-len;
    }
    else
        return NULL;
}
