/*Exercise 5-6. Rewrite appropriate programs from earlier chapters 
and exercises with pointers instead of array indexing. Good possibilities
include getline (Chapters 1 and 4), atoi, itoa, and their variants 
(Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

size_t get_line(char*, int);

char line[MAX_SIZE];

int main()
{  
    size_t len=0;

    while((len=get_line(line,MAX_SIZE))>0)
        ;
    printf("%s\n",line);

    return (EXIT_SUCCESS);
}

size_t get_line(char* f_line, int n)
{
    int c;
    size_t size=(size_t)f_line;

    while(((size_t)f_line-size)<n && (c=getchar())!=EOF && c!='\n')
        *f_line++=c;

    if(c=='\n')
        *(f_line++)=c;

    *(f_line)='\0';

    return (size_t)f_line-size;
}
