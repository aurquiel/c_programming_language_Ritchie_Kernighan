/*Exercise 2-8. Write a function rightrot(x,n) that returns 
the value of the integer x rotated to the right by n positions.*/

#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);
unsigned int num_bits(unsigned int x);

int main(void)
{
    printf("%u\n", rightrot(5, 2));
    return 0;
}

/*rightrot:  rotates x to the right by n bit positions */
unsigned int rightrot(unsigned int x, unsigned int n)
{
    while (n > 0) {
        if(x & 1)   /* rightmost bit of x is 1 */
            x = (x >> 1) | (~(~0 << num_bits(x)) & (~0 << (num_bits(x)-1)));
        else        /* rightmost bit of x is 0 */
            x = x >> 1;
        --n;
    }
    return x;
}

unsigned int num_bits(unsigned int x)
{
    unsigned int i=0;
    while((x/=2)>0)
        i++;
    return ++i;
}
