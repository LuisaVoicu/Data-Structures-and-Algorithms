#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    FILE* f = fopen("fisier.txt", "r");

    fscanf(f, "%d", &n);
    int** mat = (int*)calloc(n, sizeof(int));

    printf("\n%d\n", n);
    for (int i = 0; i < n; i++)
    {

        mat[i] = (int*)calloc(n, sizeof(int));
        for (int j = 0; j <= i; j++)
        {
            fscanf(f, "%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }


    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == n - 1)
            {
                if (j > 0)
                    mat[i][j] = mat[i][j - 1] + mat[i][j];
            }
            else if (j == 0)
            {
                if (i < n - 1)
                    mat[i][j] = mat[i + 1][j] + mat[i][j];
            }
            else
            {
                mat[i][j] += min(mat[i + 1][j], mat[i][j - 1]);
            }
        }

    }

    int minim = mat[0][0];
    for (int i = 1; i < n; i++)
    {
        if (minim > mat[i][i])
            minim = mat[i][i];
    }

    printf("%d\n", minim);
}