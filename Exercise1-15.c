/*Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.*/

#include <stdio.h>

void fahrenheit_to_celsius(void);

main()
{
    fahrenheit_to_celsius();
}

void fahrenheit_to_celsius(void)
{
    for(float celsius=0.0; celsius<=300;celsius+=20)
        printf("Celsius=%.0f\t\tFahrenheit=%f\n",celsius,celsius*(5.0/9.0)+32);
}
