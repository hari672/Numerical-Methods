/*
Derivative using forward difference
*/
#include<stdio.h>
#include<math.h>

#define f(x) pow(x, 3)

int main()
{
    float x = 5, h = 0.001;
    float diff = (f(x + h) - f(x))/h;
    printf("The derivative of f(x) at x = %g is: ", x);
    printf("%g\n", diff);
    return 0;
}