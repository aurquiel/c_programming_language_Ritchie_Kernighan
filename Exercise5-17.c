/*Exercise 5-17. Add a field-searching capability, so sorting may bee done on fields
within lines, each field sorted according to an independent set of options. 
(The index for this book was sorted with -df for the index category and -n for 
the page numbers.)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define DIR 8
#define MAXLINES 5000       /* max #lines to be sorted */
#define MAXLEN 1000 /* max length of any input line */

size_t get_line(char *, int);
char *alloc(int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int decr);
void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);

char *lineptr[MAXLINES];    /* pointers to text lines */

static char option=0;
int pos1=0;  //position to star the compare to sort in the string
int pos2=0;  //position to end the compare to sort in the string
int flag=0; //to know if a sort by field was requested
char aux1[1000],aux2[1000]; //auxiliar char to not change the original s1 and s2
void substring(char* aux1, char* s1, size_t original_length_s1, char* aux2, char* s2, size_t original_length_s2); //obtain a substring if sort by field was requested

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;     /* number of input lines read */

    while (--argc>0 && (**(++argv)=='-'||**(argv)=='+'))
    {
        if( isalpha(*(*(argv)+1)) ) //Is it a letter?
        {
            for(int i=1; i<strlen(*argv);i++)
            {
                if( *(*(argv)+i)=='n' && **argv=='-')
                {
                    option|=NUMERIC;
                }
                else if ( *(*(argv)+i)=='r' && **argv=='-')
                {
                    option|=DECR;
                }
                else if ( *(*(argv)+i)=='f' && **argv=='-')
                {
                    option|=FOLD;
                }
                else if ( *(*(argv)+i)=='d' && **argv=='-')
                {
                    option|=DIR;
                }
            }
        }

        if( isdigit(*(*(argv)+1)) && **argv=='-') //Is it a digit?
        {
            pos1=atoi((*(argv)+1));
            flag=1;
        }

        if( isdigit(*(*(argv)+1)) && **argv=='+') //Is it a digit?
        {
            pos2=atoi((*(argv)+1));
            flag=1;
        }
    }

    //check input of pos1 and pos2

    if(pos1==pos2 && flag)
    {
        printf("Error: pos1 must be different to pos2");
        return EXIT_FAILURE;
    }
    else if((pos1<0||pos2<0) && flag)
    {
        printf("Error: pos1 and pos2 must be greater than zero");
        return EXIT_FAILURE;
    }
    else if(pos1>pos2 && flag)
    {
        printf("Error: pos1 must be greater than pos2");
        return EXIT_FAILURE;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        if(option&NUMERIC)
            my_qsort((void**) lineptr, 0, nlines-1,(int (*)(void*,void*))numcmp);
        else
            my_qsort((void**) lineptr, 0, nlines-1,(int (*)(void*,void*))charcmp);
        writelines(lineptr, nlines, option & DECR);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len))== NULL)
            return -1;
        else
        {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decr)
{
    int i;

    if (decr) /*Print in reveser order*/
        for(int i=nlines-1;i>=0;i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)              /* do nothing if array contains */
        return;                     /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last-1, comp);
    my_qsort(v, last+1, right, comp);
}

int charcmp(char *s, char *t)
{
    char a,b;
    int fold= (option & FOLD) ? 1:0;
    int dir = (option & DIR) ? 1:0;

    if (flag)
    {
        substring(aux1,s,strlen(s),aux2,t,strlen(t)); //Geting sub string
        char *p_aux1=aux1,*p_aux2=aux2;
        do
        {
            if(dir)
            {
                while(!isalnum(*p_aux1) && *p_aux1 != ' ' && *p_aux1 != '\0')
                    p_aux1++;
                while(!isalnum(*p_aux2) && *p_aux2 != ' ' && *p_aux2 != '\0')
                    p_aux2++;
            }
            a = fold ? tolower(*p_aux1):*p_aux1;
            p_aux1++;
            b = fold ? tolower(*p_aux2):*p_aux2;
            p_aux2++;

            if (a==b && a=='\0')
                return 0;

        } while(a==b);
    }
    else
    {
        do
        {
            if(dir)
            {
                while(!isalnum(*s) && *s != ' ' && *s != '\0')
                    s++;
                while(!isalnum(*t) && *t != ' ' && *t != '\0')
                    t++;
            }
            a = fold ? tolower(*s):*s;
            s++;
            b = fold ? tolower(*t):*t;
            t++;

            if (a==b && a=='\0')
                return 0;

        } while(a==b);
    }

    return a-b;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    //Geting a substring if sort by field was requested
    if(flag)
    {
        substring(aux1,s1,strlen(s1),aux2,s2,strlen(s2));
        v1 = atof(aux1);
        v2 = atof(aux2);

    }
    else
    {
        v1 = atof(s1);
        v2 = atof(s2);
    }

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[],int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if(ALLOCSIZE + allocbuf - allocp>= n )
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}

size_t get_line(char* f_line,int n)
{
    int c;
    size_t size=(size_t)f_line;

    while(((size_t)f_line-size)<n && (c=getchar())!=EOF && c!='\n')
        *f_line++=c;

    if(c=='\n')
        *(f_line++)=c;

    *(f_line)='\0';

    return (size_t)f_line-size;
}

void substring(char* aux1, char* s1, size_t l1, char* aux2, char* s2, size_t l2)
{
    //create s1 field
    if(pos1>l1)//take all the string
       memccpy(aux1,s1,l1,l1);
    else if (pos2>l1)  //take it to the end of the stirng
    {
        memccpy(aux1,s1+pos1,l1-pos1,l1-pos1); //copy the bytes to compare in the beginning of s1;
        *(aux1 + l1-pos1)='\0';                //truncate to get olny the bytes to compare
    }
    else
    {
        memccpy(aux1,s1+pos1,pos2-pos1,pos2-pos1);
        *(aux1 + pos2-pos1)='\0';
    }

    //create s2 field
    if(pos1>l2)//take all the string
        memccpy(aux2,s2,l2,l2);
    else if (pos2>l2)  //take it to the end of the stirng
    {
        memccpy(aux2,s1+pos1,l2-pos1,l2-pos1); //copy the bytes to compare in the beginning of s1;
        *(aux2 + l1-pos1)='\0';                //truncate to get olny the bytes to compare
    }
    else
    {
        memccpy(aux2,s2+pos1,pos2-pos1,pos2-pos1);
        *(aux2 + pos2-pos1)='\0';
    }
}
