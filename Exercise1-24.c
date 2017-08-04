/*Exercise 1-24. Write a program to check a C program for 
rudimentary syntax errors like unmatched parentheses, 
brackets and braces. Don't forget about quotes, both single
and double, escape sequences, and comments. 
(This program is hard if you do it in full generality.) */

#include<stdio.h>

#define MAXLINE 5000

char line[MAXLINE]="";

int get_line(char s[], int limit);
void eliminate_comments(char s[]);

int main()
{
    int len;
    int parentheses=1, brackets=1, braces=1, quotes_single=1, quotes_double=1;

    while((len=get_line(line,MAXLINE))>0)
    {
        eliminate_comments(line);

        int i;
        parentheses=1, braces=1, quotes_single=1, quotes_double=1;

        for(i=0;line[i]!='\0';i++)
        {
            if(line[i]=='(')
                parentheses*=-1;
            else if(line[i]==')')
                parentheses*=-1;
            else if(line[i]=='{')
                brackets*=-1;
            else if(line[i]=='}')
                brackets*=-1;
            else if(line[i]=='[')
                braces*=-1;
            else if(line[i]==']')
                braces*=-1;
            else if(line[i]=='\'')
                quotes_single*=-1;
            else if(line[i]=='"')
                quotes_double*=-1;
        }

        if(parentheses==-1)
            printf("Error missing parentheses\n");
        else if(braces==-1)
            printf("Error missing braces\n");
        else if(quotes_single==-1)
            printf("Error missing quotes_single\n");
        else if(quotes_double==-1)
            printf("Error missing quotes_single\n");
    }

    if(brackets==-1&&len==0)
            printf("Error missing brackets\n");

    return 0;
}

int get_line(char s[], int limit)
{
    int c,i=0;

    while( (i<limit-1) && (c=getchar())!=EOF && c!='\n')
        s[i++]=c;

    if(c=='\n')
        s[i]='\0';

    return i;
}

void eliminate_comments(char s[])
{
    size_t i,j;
    int flag_1=0,flag_2=0,flag_3=0,flag_4=0;

    for(i=0,j=0;s[i]!='\0';i++)
    {
        if((s[i]=='"'||s[i]=='\'')&&flag_3)
        {
            flag_3=0;
            flag_4=1;
        }
        if((s[i]=='/'||s[i]=='*')&&flag_1&&!flag_3)
        {
            flag_2=1;
            flag_1=0;
        }
        if(s[i]=='/')
            flag_1=1;
        if((s[i]=='"'||s[i]=='\'')&&!flag_4)
            flag_3=1;
        if(!flag_2)
            s[j++]=s[i];
        else if(flag_2)
        {
            s[--j]='\0';
            break;
        }

    }
}
