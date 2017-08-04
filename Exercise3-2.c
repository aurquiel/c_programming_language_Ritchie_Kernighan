/*Exercise 3-2. Write a function escape(s,t) that converts
characters like newline and tab into visible escape sequences 
like \n and \t as it copies the string t to s. Use a switch. 
Write a function for the other direction as well, converting 
escape sequences into the real characters.*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char to[], const char from[]);
void reverse_2(char to[], const char from[]);
void get_line(char s[],int);

int main()
{
    char line_from[MAXLINE]="";
    char line_to[MAXLINE]="";

    get_line(line_from,MAXLINE);

    //reverse(line_to,line_from);
    //reverse_2(line_to,line_from);

    printf("%s\n",line_to);

    return 0;
}

void get_line(char s[], int max)
{
    int c,i=0;
    while( (i<max-1) && (c=getchar())!=EOF )
        s[i++]=c;
    s[i]='\0';
}


void reverse(char to[], const char from[])
{
    int i,j;

    for(i=0,j=0; from[i]!='\0';i++)
    {
        switch(from[i])
        {
            case '\n':
            {
                to[j++]='\\';
                to[j++]='n';
                break;
            }
            case '\t':
            {
                to[j++]='\\';
                to[j++]='t';
                break;
            }
            default:
            {
                to[j++]=from[i];
                break;
            }
        }
    }
    to[j]='\0';
}

void reverse_2(char to[], const char from[])
{
    int i,j,k;

    for(i=0,j=1,k=0; j<=strlen(from) ;i++,j++)
    {
            switch(from[i]+from[j])
            {
                case 92+110://new line \=92 n=110
                {
                    to[k++]=10; // \n=10
                    i++,j++;
                    break;
                }
                case 92+116://new line \=92 t=116
                {
                    to[k++]=9; // \t=9
                    i++,j++;
                    break;
                }
                default:
                {
                    to[k++]=from[i];
                    break;
                }
            }
    }
    to[k]='\0';
}
