/*
Gauss Seidel Method
Solve
10x1 + 2x2 + 3x3 + 3x4 = 18
      12x2 + 4x3 + 3x4 = 19
3x1 + 2x2 + 15x3 + 5x4 = 25
x1 + 2x2 + 3x3 + 16x4 = 22
*/

#include <stdio.h>
#include <math.h>

#define n 4

int main()
{
    /* Coefficient matrix */
    float A[n][n] = {
        {10, 2, 3, 3},
        {0, 12, 4, 3},
        {3, 2, 15, 5},
        {1, 2, 3, 16}};
    float b[n] = {18, 19, 25, 22};
    float x[n] = {0, 0, 0, 0};
    int i, j, iter, MaxIter = 10;
    float sum;
    int diagdom = 1;
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
        {
            if (j != i)
                sum += fabs(A[i][j]);
        }
        if (A[i][i] < sum)
        {
            diagdom = 0;
            printf("The system is not diagonally dominant.\n");
            break;
        }
    }
    if (diagdom == 1)
    {
        for (iter = 1; iter <= MaxIter; iter++)
        {
            for (i = 0; i < n; i++)
            {
                sum = b[i];
                for (j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        sum -= A[i][j] * x[j];
                    }
                }
                x[i] = sum / A[i][i];
                printf("%.3f\t", x[i]);
            }
            printf("\n");
        }
    }
    return 0;
}