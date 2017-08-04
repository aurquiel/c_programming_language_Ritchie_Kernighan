/*Exercise 4-14. Define a macro swap(t,x,y) that interchanges 
two arguments of type t. (Block structure will help.)*/

#include <stdio.h>
#include <stdlib.h>

#define swap(t,x,y)   {\
                        t temp=x;\
                        x=y;\
                        y=temp;\
                    }

int main()
{
    int a=2,b=6;
    swap(int,a,b);
    printf("%d %d\n",a,b);
    return (EXIT_SUCCESS);
}
