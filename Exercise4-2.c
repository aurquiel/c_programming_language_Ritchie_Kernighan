/*Exercise 4-2. Extend atof to handle scientific notation of 
the form 123.45e-6 where a floating-point number may be followed
by e or E and an optionally signed exponent.*/

#include <stdio.h>

double atof(char s[]);
int atoi(char s[]);

int main(void)
{
    printf("%e\n",atof("123.123e+6"));
    return 0;
}

#include <ctype.h>
/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, sign_2;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if(s[i]=='e'||s[i]=='E')
        i++;

    sign_2=(s[i]=='-')? -1:1;

    if(s[i]=='-'||s[i]=='+')
        i++;

    int exp=1;

    for(int n=(s[i]-'0'); n>0;n--)
        exp*=10;

    if(sign_2==-1)
        return (sign*val)/(power*exp);
    else
        return (sign*val*exp)/power;

}
