/*
Runge-Kutta Method of 4th Order
Solve dy/dx = -x/y; y(0) = 2
to find y(1) taking n = 5
*/

#include <stdio.h>
#include <math.h>

float f(float, float);

int main()
{
    float x0 = 0, y0 = 2, xn = 1, m1, m2, m3, m4;
    int n = 5;
    float h = (xn - x0) / n;

    printf("xi  \tyi\n");
    printf("--------------\n");
    while (x0 < xn)
    {
        m1 = f(x0, y0);
        m2 = f(x0 + h / 2, y0 + m1 * h / 2);
        m3 = f(x0 + h / 2, y0 + m2 * h / 2);
        m4 = f(x0 + h, y0 + m3 * h);
        y0 += h / 6 * (m1 + 2 * m2 + 2 * m3 + m4);
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