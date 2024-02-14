#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int c, v;
}prod;




int maxim(int a, int b)
{
    if (a > b)
        return a;
    return b;
}


// concept :  fiecare linie a matricii(ei?) reprezinta cea mai buna varianta de a ocupa cantitatea curenta (j) 

void rucsac_iterativ(int** mat, prod* a, int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int bagam = 0;
            int nu_bagam = 0;
            if (i - 1 >= 0)
            {
                
                if (j >= a[i].c)
                {
                    bagam = a[i].v + mat[i - 1][j - a[i].c];
                }

                nu_bagam = mat[i - 1][j];
            }

            mat[i][j] = maxim(bagam, nu_bagam);
        }
    }
}



int main()
{
    FILE* f = fopen("file.txt", "r");
    int n, cant;
    fscanf(f, "%d %d", &n, &cant);
    prod* a = (prod*)malloc(sizeof(prod) * n);
   
    int** mat = (int**)calloc(n+1, sizeof(int*)); 
    mat[0] = (int*)calloc(cant + 1, sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        mat[i] = (int*)calloc(cant+1, sizeof(int));
        fscanf(f, "%d %d", &a[i].c, &a[i].v);
        printf("%d %d\n", a[i].c, a[i].v);
    }

    rucsac_iterativ(mat, a, n, cant);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cant; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}