/*
Derivative of tabulated functions using forward difference formula
x: 1    1.1     1.2     1.3
y: 1    1.21    1.44    1.69
Find f'(1)
*/

#include <stdio.h>
#include <math.h>

#define n 4

int main()
{
    float x[n] = {1, 1.1, 1.2, 1.3};
    float y[n] = {1, 1.21, 1.44, 1.69};
    float h = x[1] - x[0];
    int i, j;
    float sum = 0, coeff, der;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            y[j] = y[j + 1] - y[j];
        }
        coeff = pow(-1, i) / (i + 1);
        sum += coeff * y[0];
    }
    der = 1 / h * sum;
    printf("f'(%g) = %g\n", x[0], der);
    return 0;
}