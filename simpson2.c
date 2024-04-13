/* Simpson's 3/8 Rule */
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return pow(x, 3);
}
int main()
{
    int n = 12; // n must be a multiple of 3
    float a = 0, b = 4, intg;
    float sum = f(a) + f(b);
    float x0 = a;
    float h = (b - a) / n;
    int i;
    for (i = 1; i <= n - 1; i++)
    {
        x0 += h;
        if (i % 3 == 0)
        {
            sum += 2 * f(x0);
        }
        else
        {
            sum += 3 * f(x0);
        }
    }
    intg = 3 / 8.0 * h * sum;
    printf("The integral is %g\n", intg);

    return 0;
}