#include <stdio.h>
#include <math.h>

int main()
{
    /* Augmented matrix */
    float A[10][10] = {
        {0, 2, 3, 3, 10},
        {0, 2, 4, 3, 13},
        {3, 2, 5, 5, 24},
        {1, 2, 3, 6, 15}};
    int n = 4, i, j, k;
    float c, sum, temp;
    float x[n];

    /* Forward Elimination */

    for (j = 0; j < n; j++)
    {
        /* Switch the rows if A[j][j] = 0 */
        if (A[j][j] == 0)
        {
            for (i = j + 1; i < n; i++)
            {
                if (A[i][j] != 0)
                {
                    for (k = 0; k < n + 1; k++)
                    {
                        temp = A[j][k];
                        A[j][k] = A[i][k];
                        A[i][k] = temp;
                    }
                    break;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            if (j < i)
            {
                c = A[i][j] / A[j][j];
                for (k = 0; k < n + 1; k++)
                {
                    A[i][k] -= c * A[j][k];
                }
            }
        }
    }
    /* Print the upper triangular matrix */
    printf("Upper triangular matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%g\t", A[i][j]);
        }
        printf("\n");
    }

    /* Back Substitution */
    for (i = n - 1; i >= 0; i--)
    {
        sum = A[i][n];
        for (j = n - 1; j > i; j--)
        {
            sum -= A[i][j] * x[j];
        }
        x[i] = 1 / A[i][i] * sum;
    }

    /* Print the solution */
    printf("The solution is:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %g\n", i + 1, x[i]);
    }
    return 0;
}