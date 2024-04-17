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
    int n = 4; // number of variables
    int i, j, k;
    float sum, temp, c;
    float x[n];

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
        c = A[j][j];
        for (k = 0; k < n + 1; k++)
        {
            A[j][k] = A[j][k] / c;
        }
        for (i = 0; i < n; i++)
        {
            if (i != j)
            {
                c = A[i][j];
                for (k = 0; k < n + 1; k++)
                {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }
    /* Print the matrix */

    printf("Matrix in the reduced echelon form:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            printf("%g\t", A[i][j]);
        }
        printf("\n");
    }

    /* Print the solution */
    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %g\n", i + 1, A[i][n]);
    }
    return 0;
}