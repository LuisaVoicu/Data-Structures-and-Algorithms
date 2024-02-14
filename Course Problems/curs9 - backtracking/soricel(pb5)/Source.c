#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/////////////sus/jos//stg/drp
int di[] = { -1 ,1  , 0  ,0 };
int dj[] = {  0 ,0  ,-1  ,1 };


void backtr_rat()
{
    ;
}


int main()
{
    FILE* f = fopen("file.txt", "r");
    int n, m;
    fscanf(f, "%d %d", &m, &n);
    printf("%d %d\n", m, n);
    int** a = (int**)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
    {
        a[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &a[i][j]);
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    
}