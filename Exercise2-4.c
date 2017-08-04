/*Exercise 2-4. Write an alternative version of squeeze(s1,s2) that
deletes each character in s1 that matches any character in the strings2. */

#include <stdio.h>

void squeeze(char to[], const char from[]);

int main()
{
    char line[1000]="Hello World";
    char line_2[]="eo";
    squeeze(line,line_2);
    printf("%s\n",line);

    return 0;
}

void squeeze(char to[], const char from[])
{
    int i,j,h;

    for(i=0,h=0; to[i]!='\0';i++)
    {

        for(j=0; to[i]!=from[j]&&from[j]!='\0';j++)
            ;
        if(from[j]=='\0')
            to[h++]=to[i];

    }
    to[h]='\0';
}
