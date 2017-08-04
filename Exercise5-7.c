/*Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
rather than calling alloc to maintain storage. How much faster is the program?*/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int maxlines,char* alloc);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    char alloc[MAXLINES]="";
    int nlines;
    /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES,alloc)) >= 0)
    {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
size_t get_line(char* f_line,int n);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines,char* alloc)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    p=alloc;
    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p>p+maxlines))
             return -1;  
        else
        {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p+=len;
        }
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
void qsort(char *v[], int left, int right)
{
    int i, last;

    void swap(char *v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
        return;

    /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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
