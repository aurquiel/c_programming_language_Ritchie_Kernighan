/*Exercise 4-13. Write a recursive version of the function reverse(s),
which reverses the string s in place.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

void reverse(char s[],int n);

char line_2[SIZE]="Hello i am program running at Linux";

int main()
{
    reverse(line_2,0);
    printf("%s\n",line_2);
    return (EXIT_SUCCESS);
}

void reverse(char s[],int n)
{
    int temp,len=strlen(s);
    temp=s[strlen(s)-1-n];
    s[strlen(s)-1-n]=s[n];
    s[n]=temp;
    if(!(len%2)) //check if the word length is par or not
    {
        if(n<len/2-1)
         reverse(s,++n);
    }
    else
    {
        if(n<len/2)
         reverse(s,++n);
    }
}
