/*Exercise 5-10. Write the program expr, which evaluates a reverse Polish 
expression from the command line, where each operator or operand is a 
separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'/* signal that a number was found */

void push(double);
double pop(void);

//pop and push
#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

int main (int argc, char* argv[])
{
    int type;
    double op2;
    while(--argc>0)
    {
        ++argv;
        if (isdigit(**argv))
            type=NUMBER;
        else
            type=**argv;

        switch (type)
        {
            case NUMBER:
                push(atof(*argv));
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
            default:
                printf("error: unknown command %s\n", *argv);
                break;
        }
    }

    printf("\t%.8g\n", pop());
    return 0;

    return EXIT_SUCCESS;
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
