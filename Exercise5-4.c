/*Exercise 5-4. Write the function strend(s,t), which returns 1 if the
string t occurs at the end of the string s, and zero otherwise.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int str_end(char *s, char *t);

char array_text[MAX_SIZE]="Hello i am a program running at Linux";
char array_text_2[MAX_SIZE]="Linux";
char array_text_2[MAX_SIZE]="Linux2";

int main()
{  

    printf("%d\n",str_end(array_text,array_text_2));
    printf("%d\n",str_end(array_text,array_text_3));  
    return (EXIT_SUCCESS);
}

int str_end(char *s, char *t)
{
    for (s+=strlen(s)-strlen(t); *s++ == *t++ && *t!='\0';)
        ;
    return (*t=='\0') ? 1:0 ;
}
