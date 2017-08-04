/*Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting
in reverse (decreasing) order. Be sure that -r works with -n.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be sorted */
char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;     /* number of input lines read */
    int numeric = 0;/* if numeric sort */
    int reverse = 0;/*reveser order*/

    while (--argc>0&& **(++argv)=='-')
    {
        if( *(*(argv)+1)=='n')
            numeric=1;
        else if ( *(*(argv)+1)=='r')
            reverse=1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        my_qsort((void**) lineptr, 0, nlines-1, (numeric ? numcmp : strcmp), reverse ? 1:0);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
size_t get_line(char *, int);
char *alloc(int);

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
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void my_qsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right)              /* do nothing if array contains */
        return;                     /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if(reverse)
        {
            if ((*comp)(v[i], v[left]) > 0)
                swap(v, ++last, i);
        }else
        {
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        }

    swap(v, left, last);
    my_qsort(v, left, last-1, comp, reverse);
    my_qsort(v, last+1, right, comp, reverse);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
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
