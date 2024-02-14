#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void print_sol(int* a, int n)
{
    for(int i=1;i<=n;i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == j)
                printf("R");
            else printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

int absolute(int a)
{
    if (a < 0)
    {
        return a * (-1);
    }
    return a;
}

int valid(int* a, int k)
{
    for (int i = 1; i < k; i++)
        if (a[i] == a[k] || absolute(a[k] - a[i]) == k - i)
            return 0;
    return 1;
}


void backtr(int* a, int n, int k)
{
    if (k == n + 1)
    {
        print_sol(a, n);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        a[k] = i;
        if (valid(a, k))
        {
            backtr(a, n, k + 1);
        }
    }
}


int main()
{
    int n = 4;
    int* a = (int*)malloc(n + 1, sizeof(int));

    backtr(a, n, 1);
}