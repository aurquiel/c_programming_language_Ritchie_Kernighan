/*Exercise 5-3. Write a pointer version of the function strcat that we
showed in Chapter 2: strcat(s,t) copies the string t to the end of s.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void str_cat(char *s, char *t);

char array_text[MAX_SIZE]="Hello i am a program running at Linux";
char array_text_2[MAX_SIZE]=", hello again :)";

int main()
{  
    str_cat(array_text,array_text_2);
    printf("%s\n",array_text);

    return (EXIT_SUCCESS);
}

void str_cat(char *s, char *t)
{
    for (s+=strlen(s) ; *t!='\0'; *s++ = *t++)
        ;
}
