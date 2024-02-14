#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



void print_sol(int* a, int m)
{
    for (int i = 1; i <= m; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int valid(int* a, int k)
{
    for (int i = 1; i < k; i++)
        if (a[i] == a[k])
            return 0;
    return 1;
}

void backtr(int* a, int n, int m, int k)
{
    if (k - 1 > m)
        return;
    if (k - 1 == m)
        print_sol(a, m);

        for (int i = a[k-1]+1; i <= n; i++)
        {    //branch and bound!!
            a[k] = i;
            if (valid(a,k))
                backtr(a, n, m, k + 1);
        }
}


int main()
{
    int n = 5, m = 4;
    int* a = (int*)malloc(n + 1, sizeof(int));
    a[0] = 0;
    backtr(a, n, m, 1);
}