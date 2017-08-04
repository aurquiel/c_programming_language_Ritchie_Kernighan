/*Exercise 1-23. Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly. 
C comments don't nest. */

#include <stdio.h>

#define MAXSIZE 5000

int get_line(char*, int);
int size_line(char*);

char line_1[MAXSIZE];


int main()
{
    int len;

    while((len=get_line(line_1,MAXSIZE))>0)
    {
        size_t i,j;
        int flag_1=0,flag_2=0,flag_3=0,flag_4=0;

        for(i=0,j=0;line_1[i]!='\0';i++)
        {
            if((line_1[i]=='"'||line_1[i]=='\'')&&flag_3)
            {
                flag_3=0;
                flag_4=1;
            }
            if((line_1[i]=='/'||line_1[i]=='*')&&flag_1&&!flag_3)
            {
                flag_2=1;
                flag_1=0;
            }
            if(line_1[i]=='/')
                flag_1=1;
            if((line_1[i]=='"'||line_1[i]=='\'')&&!flag_4)
                flag_3=1;
            if(!flag_2)
                line_1[j++]=line_1[i];
            else if(flag_2)
            {
                line_1[--j]='\0';
                break;
            }

        }
        printf("%s\n",line_1);
    }


    return 0;
}

int get_line(char s[],int maxline)
{
    int c,i=0;

    while((c=getchar())!='\n'&&c!=EOF)
    {
        s[i++]=c;
    }
    s[i]='\0';

    return i;
}
