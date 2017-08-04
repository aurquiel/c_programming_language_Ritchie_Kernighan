/*Exercise 3-1. Our binary search makes two tests inside the loop,
when one would suffice (at the price of more tests outside.) 
Write a version with only one test inside the loop and measure 
the difference in run-time.*/

#include <stdio.h>

int binsearch(int x, int v[], int n);

int myintArray[10]={0,1,2,3,4,5,6,7,8,9};

int main()
{
    printf("%d\n",binsearch(2,myintArray,10));
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    //Search until x found or x guaranteed to not be in v
    while (v[mid] != x && low <= high) {
        mid = (low+high) / 2;

        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (v[mid] == x)
        return mid;     //Found match

    return -1;      //No match
}
