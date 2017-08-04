/*Exercise 5-5. Write versions of the library functions strncpy, strncat, and 
strncmp, which operate on at most the first n characters of their argument strings.
For example, strncpy(s,t,n) copies at most n characters of t to s. 
Full descriptions are in Appendix B.*/

#include <stdio.h>
#include <stdlib.h>

int str_cmp(char *s, char *t,int n);

char array_text[]="Hello i am a program running at Linux";
char array_text_2[]="Hello again :)";
char array_text_3[]="Do nothing.......................Until now";
char array_text_4[]="Hello i am a program running at Linux";

int main()
{  
    printf("%d\n",str_cmp(array_text,array_text_2,2));
    printf("%d\n",str_cmp(array_text,array_text_3,4));
    printf("%d\n",str_cmp(array_text,array_text_4,6));

    return (EXIT_SUCCESS);
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int str_cmp(char *s, char *t,int n)
{
    for ( ; n>0 && *s == *t ; s++, t++,--n)
        if (*s == '\0'|| n==0)
            return 0;
    return *s - *t;
}
