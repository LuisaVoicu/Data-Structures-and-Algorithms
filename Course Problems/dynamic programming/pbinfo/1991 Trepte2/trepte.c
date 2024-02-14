#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=4, m=2;
    int* a = (int*)calloc(n + 1, sizeof(int));
    a[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
                a[j] = a[j] + a[j - i];
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
}