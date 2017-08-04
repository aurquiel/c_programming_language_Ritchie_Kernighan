/*Exercise 1-22. Write a program to ``fold'' long input lines into two
or more shorter lines after the last non-blank character that occurs 
before the n-th column of input. Make sure your program does something 
intelligent with very long lines, and if there are no blanks or tabs 
before the specified column*/

#include <stdio.h>

#define MAXSIZE 5000
#define MAXDISPLAY 16
int get_line(char*, int);
int size_line(char*);

char line_1[MAXSIZE];
char line_2[MAXSIZE];
char line_3[MAXSIZE];

int main()
{
  int len;

  while((len=get_line(line_1,MAXSIZE))>0)
  {
      int size=size_line(line_1);
      int aux=size;
      int i=0;

      while(size)
      {
          int j;
          for(j=0;j<MAXDISPLAY&&size>0;j++,i++,size--)
              line_2[j]=line_1[i];
          line_2[j]='\0';
          printf("%s\n",line_2);

          if(aux>MAXDISPLAY)
          {
              for(j=0;j<MAXDISPLAY&&size>0;j++,i++,size--)
                  line_3[j]=line_1[i];
              line_3[j]='\0';
              printf("%s\n",line_3);

          }
      }

  }

  return 0;
}

int get_line(char s[],int maxline)
{
  int c,i=0,flag=0;

  while((c=getchar())!='\n'&&c!=EOF)
  {
      s[i++]=c;
  }
  s[i]='\0';

  return i;
}

int size_line(char s[])
{
  int i=0;
  while(s[i]!='\0')
      i++;
  return i;
}
