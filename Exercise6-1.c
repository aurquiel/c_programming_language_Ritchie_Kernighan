/*Exercise 6-1. Our version of getword does not properly handle underscores,
string constants, comments, or preprocessor control lines. Write a better
version.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
  char* word;
  int count;
} keytab[] = {
  {"#define", 0},
  {"#elif", 0},
  {"#elifdef", 0},
  {"#elifndef", 0},
  {"#else", 0},
  {"#endif", 0},
  {"#error", 0},
  {"#if", 0},
  {"#ifdef", 0},
  {"#ifndef", 0},
  {"#include", 0},
  {"#line", 0},
  {"#pragma", 0},
  {"#undef", 0},
  {"/*", 0},
  {"//", 0},
  {"_Alignas", 0},
  {"_Alignosf", 0},
  {"_Atomic", 0},
  {"_Bool", 0},
  {"_Complex", 0},
  {"_Generic", 0},
  {"_Imaginary", 0},
  {"_Noreturn", 0},
  {"_Static_assert", 0},
  {"_Thread_local", 0},
  {"auto", 0},
  {"break", 0},
  {"case", 0},
  {"char", 0},
  {"char*", 0},
  {"const", 0},
  {"continue", 0},
  {"default", 0},
  {"do", 0},
  {"double", 0},
  {"double*", 0},
  {"else", 0},
  {"enum,", 0},
  {"extern", 0},
  {"for", 0},
  {"float", 0},
  {"float*", 0},
  {"goto", 0},
  {"if", 0},
  {"inline", 0},
  {"int", 0},
  {"int*", 0},
  {"long", 0},
  {"register", 0},
  {"return", 0},
  {"restricted", 0},
  {"short", 0},
  {"signed", 0},
  {"sizeof", 0},
  {"static", 0},
  {"struct", 0},
  {"switch", 0},
  {"typedef", 0},
  {"union", 0},
  {"unsigned", 0},
  {"void", 0},
  {"void*", 0},
  {"volatile", 0},
  {"while", 0}
};

#define MAXWORD 100
#define NKEYS (int)(sizeof keytab/sizeof(struct key))

int getword(char*, int);
int binsearch(char* word, struct key tab[], int n);

/* count C keywords */
int main()
{
  int n;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF)
      if (isalpha(*word)||*word=='#'||*word=='/'||*word=='_')
          if ((n = binsearch(word, keytab, NKEYS)) >= 0)
              keytab[n].count++;

  for (n = 0; n < NKEYS; n++)
      if (keytab[n].count > 0)
          printf("%4d %s\n", keytab[n].count, keytab[n].word);

  return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char* word, struct key tab[], int n)
{
  int cond;
  int low, high, mid;
  low = 0;
  high = n - 1;

  while (low <= high)
  {
      mid = (low+high) / 2;
      if ((cond = strcmp(word, tab[mid].word)) < 0)
          high = mid - 1;
      else if (cond > 0)
          low = mid + 1;
      else
          return mid;
  }

  return -1;
}

/* getword: get next word or character from input */
int getword(char* word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char* w = word;

  while (isspace(c = getch()))
      ;

  if (c != EOF)
      *w++ = c;

  if (!isalpha(c) && c!='#' && c!='/'&& c!='_')
  {
      *w = '\0';
      return c;
  }

  if( (c=getch())=='/' || c=='*' )
  {
      *w++=c;
      *w='\0';
      return word[0];
  }
  else
      ungetch(c);

  for ( ; --lim > 0; w++)
      if (!isalnum(*w = getch()) && *w!='_' && *w!='*' )
      {
          ungetch(*w);
          break;
      }

  *w = '\0';
  return word[0];
}

#define MAX_ALLOC 100
int alloc[MAX_ALLOC];
int bufp=0;

int getch(void)
{
  return (bufp>0) ? alloc[--bufp]:getchar();
}

void ungetch(int c)
{
  if(bufp>=MAX_ALLOC)
      printf("No espace to allocate the character\n");
  else
      alloc[bufp++]=c;
}
