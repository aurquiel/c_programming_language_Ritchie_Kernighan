/*Exercise 3-3. Write a function expand(s1,s2) that expands
shorthand notations like a-z in the string s1 into the 
equivalent complete list abc...xyz in s2. Allow for letters 
of either case and digits, and be prepared to handle cases 
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or 
trailing - is taken literally.*/

#include <stdio.h>
#include <string.h>

#define MAX 50000

void expand(char to[], const char from[]);

int main()
{
    char line[]="Hello #-9 A-Z 0-9 -n running at Linux.";
    char line_2[MAX]="";

        expand(line_2,line);

    printf("%s \n",line_2);

    return 0;
}

void expand(char to[], const char from[])
{
    int i,j;
    int h,k;
    for(i=0,j=0; i<strlen(from) ;i++)
    {
        if(from[i]==45&&i>0) //found -=45
            for(k=from[i-1],h=from[i+1],i++ ;k<h; j++) //save interval h and k
                to[j]=++k;
        else
            to[j++]=from[i];
    }
    to[j]='\0';
}
