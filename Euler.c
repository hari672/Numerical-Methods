/*
Euler's Method
Solve dy/dx = -x/y; y(0) = 2
to find y(1) taking n = 10
*/

#include <stdio.h>
#include <math.h>

float f(float, float);

int main()
{
    float x0 = 0, y0 = 2, xn = 1;
    int n = 10;
    float h = (xn - x0) / n;

    printf("xi  \tyi\n");
    printf("--------------\n");
    while (x0 < xn)
    {
        y0 += h * f(x0, y0);
        x0 += h;
        printf("%.1f\t%.4f\n", x0, y0);
    }
    printf("\nSolution:\ny(%g) = %.4f\n", x0, y0);
    return 0;
}
float f(float x, float y)
{
    return -x / y;
}