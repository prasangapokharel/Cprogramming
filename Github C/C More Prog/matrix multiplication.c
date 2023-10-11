#include <stdio.h>
#include <conio.h>
#define R 10
#define C 10
int main()
{
    int mat1[R][C], mat2[R][C], mat3[R][C]; // define 10*10 array always should be declared at first cause varies on compiler type 
    int i, j, k, m, n, p, q; // also declare at first 
    printf("enter the order of first matrix:");
    scanf("%d%d", &m, &n);
    printf("Enter the order of second matrix:");
    scanf("%d%d", &p, &q);
    if (n != p) // if n not equal with p matrix multipication cannot occur
    {
        printf("Matrix multiplication cannot occur");
    }
    else
    { // if not continue multipling

        printf("Multplying");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("Enter the value of A%d%d", i + 1, j + 1);
                scanf("%d", &mat1[i][j]);
            }
        }
        printf("Multplying");

        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("Enter the value of A%d%d", i + 1, j + 1);
                scanf("%d", &mat1[i][j]);
            }
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; i < q; j++)
            {
                mat3[i][j] = 0;
                for (k = 0; k < n; k++)
                {
                    mat3[i][j] = mat3[i][j] + mat1[i][k] * mat2[k][j];
                }
                printf("%d%d",mat3[i][j]);
            }
        }
    }

    return 0;
}