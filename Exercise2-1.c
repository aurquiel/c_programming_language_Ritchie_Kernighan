/*Exercise 2-1. Write a program to determine the ranges of char,
short, int, and long variables, both signed and unsigned, 
by printing appropriate values from standard headers and by direct
computation. Harder if you compute them: determine the ranges of 
the various floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("char= %d\n",CHAR_MAX);
    printf("unsigned char= %d\n",UCHAR_MAX);
    printf("short int= %d\n",SHRT_MAX);
    printf("unsigned short int= %d\n",USHRT_MAX);
    printf("int= %d\n",INT_MAX);
    printf("unsigned int= %u\n",UINT_MAX);
    printf("long int= %ld\n",LONG_MAX);
    printf("unsigned long int= %lu\n",ULONG_MAX);
    printf("float= %f\n",FLT_MAX);
    printf("double= %f\n",DBL_MAX);
    printf("long double= %Lf \n",LDBL_MAX);
    return 0;
}
