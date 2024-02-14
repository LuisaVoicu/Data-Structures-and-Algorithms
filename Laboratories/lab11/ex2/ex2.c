#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 100
int main()
{
    int v[] = { 1,3,5 };
    int n = 3;
    int s = 11;
    int* min = (int*)malloc((s + 1) * sizeof(int));
    int* last_val = (int*)calloc((s + 1) , sizeof(int));
    for (int i = 0; i <= s; i++)
    {
        min[i] = INF;
    }
    min[0] = 0;
    for (int i = 1; i <= s; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[j] <= i && min[i - v[j]] + 1 < min[i])
            {
                min[i] = min[i - v[j]] + 1;
                last_val[i] = i - v[j];
            }
        }
    }


    for (int i = 1; i <= s; i++)
    {
        printf("%5d ", i);
    }
    printf("\n");
    for (int i = 1; i <= s; i++)
    {
        printf("%5d ", min[i]);
    }
    printf("\n");

    for (int i = 1; i <= s; i++)
    {
        printf("%5d ", last_val[i]);
    }


    printf("\n\nnr minim de monede pt a obtine suma %d este %d\n", s, min[s]);
}
