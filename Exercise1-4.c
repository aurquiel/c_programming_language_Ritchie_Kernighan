/*Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>

main()
{
    for(float celsius=0.0; celsius<=300;celsius+=20)
        printf("Celsius=%.0f\t\tFahrenheit=%f\n",celsius,celsius*(5.0/9.0)+32);
}
