#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>




int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int** mat = (int**)calloc(n,sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int*)calloc(m, sizeof(int));
        

        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
                mat[i][j] = 1;
            else
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1];

        }



    }
    printf("%d", mat[n - 1][m - 1]);
}