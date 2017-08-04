/*Exercise 4-4. Add the commands to print the top elements of the 
stack without popping, to duplicate it, and to swap the top two 
elements. Add a command to clear the stack.*/

#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0'/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

//pop and push
#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */


/* reverse Polish calculator */
int main()
{
    int type;
    double op2,op3;
    char s[MAXOP];
    int flag_p=0;

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2=pop();
                op3=pop();
                if (op2>0.0&&op3>0.0)
                    push((int)op3 % (int)op2);
                else
                    printf("Remainder of negative division");
                break;
            case 'p':   //print last in stack
                flag_p=1;
                printf("\t%g\n",val[sp]);
                break;
            case 'd':   //duplicate last in the sctak
                flag_p=1;
                sp++;
                val[sp]=val[sp-1];
                break;
            case 'c':   //exchage the last two values
                flag_p=1;
                sp++;
                int aux=val[sp];
                val[sp]=val[sp-1];
                val[sp-1]=aux;
                break;
            case 'e':   //clean stack "erase"
                flag_p=1;
                sp=0;
                break;
            case '\n':
                if(flag_p==0)
                    printf("\t%.8g\n", pop());
                else
                    flag_p=0;
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);

void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;  /* not a number */

    i = 0;

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
        ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];/* buffer for ungetch */
int bufp = 0;/* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
