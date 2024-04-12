#include <stdio.h>
#include <math.h>

#define f(x) pow(x, 3)

int main()
{
    float x = 5, h = 0.001;
    float diff = (f(x + h) + f(x - h) - 2 * f(x)) / (h * h);
    printf("f''(%g) = %g\n", x, diff);
    return 0;
}