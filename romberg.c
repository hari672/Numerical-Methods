/* Romberg's Integration */

#include <stdio.h>
#include <math.h>

#define N 4 // Calculations up to R(N-1, N-1)

float f(float x);
float trap(float a, float b, int n);

int main()
{
    float a = 1, b = 3; // lower and upper limits
    float R[N][N];
    int i, j;
    int n = 1;

    /* Calculations of R(i, 0) using trapezoidal rule */
    for (i = 0; i < N; i++)
    {
        R[i][0] = trap(a, b, n);
        n *= 2;
    }

    /* Calculations of R(i, j) i > 0, j > 0 */
    for (i = 1; i < N; i++)
    {
        for (j = 1; j <= i; j++)
        {
            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }
    }

    /* Printing the results */
    for (i = 0; i < N; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%f\t", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/* Function to be integrated */
float f(float x)
{
    return pow(x, 4);
}
/* Trapezoidal rule */
float trap(float a, float b, int n)
{
    float intg;
    float sum = f(a) + f(b);
    float x0 = a;
    float h = (b - a) / n;
    int i;
    for (i = 1; i <= n - 1; i++)
    {
        x0 += h;
        sum += 2 * f(x0);
    }
    intg = h / 2.0 * sum;
    return intg;
}