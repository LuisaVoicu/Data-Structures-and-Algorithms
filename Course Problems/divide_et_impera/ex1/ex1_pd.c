#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NINF -100000


int main()
{
    FILE* f = fopen("file.txt","r");
    int n;
    fscanf(f, "%d", &n);


    int* a = (int*)calloc(n, sizeof(int));
    int* mx = (int*)calloc(n, sizeof(int));
    int maxim = NINF;

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &a[i]);
    }
    mx[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        int sum = mx[i] + a[i];
        if (mx[i-1] + a[i] > a[i])
        {
            mx[i] = a[i] + mx[i - 1];
        }
        else
        {
            mx[i] = a[i];
        }

        if (maxim < mx[i])
        {
            maxim = mx[i];
        }
    }

    printf("sum max: %d\n", maxim);
   

    /*
    * 
    * 
    * 
    * solutia de mai jos stocheaza fiecare posibilitate  de formare a submultimilor, nu doar ce det. maximul
    * 
    * 
    int** a = (int**)calloc(n, sizeof(int*));

    for (int i = 0; i < n; i++)
    {
       a[i] = (int*)calloc(n, sizeof(int));
        fscanf(f,"%d", &a[0][i]);
    }

    int sum_max = NINF;
    for (int j = 1; j < n; j++)
    {
        if (a[0][j] > sum_max)
        {
            sum_max = a[0][j];
        }
        for (int i = 1; i <= j; i++)
        {
            a[i][j] = a[0][j] + a[i - 1][j - 1];
            if (a[i][j] > sum_max)
            {
                sum_max = a[i][j];
            }
        }

    }

    printf("suma maxima: %d\n", sum_max);

     eliberare memorie

    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);*/
}