/* Simpson's 1/3 Rule */
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return pow(x, 2);
}
int main()
{
    int n = 10; // n must be even
    float a = 1, b = 3, intg;
    float sum = f(a) + f(b);
    float x0 = a;
    float h = (b - a) / n;
    int i;
    for (i = 1; i <= n - 1; i++)
    {
        x0 += h;
        if (i % 2 == 0)
        {
            sum += 2 * f(x0);
        }
        else
        {
            sum += 4 * f(x0);
        }
    }
    intg = h / 3.0 * sum;
    printf("The integral is %g\n", intg);

    return 0;
}