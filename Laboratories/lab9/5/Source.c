#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int suma(int* sol, int* a, int n)
{
    int sum = a[0];
    for (int i = 1; i < n; i++)
    {
        if (sol[i] == 0)
        {
            sum -= a[i];
        }
        else
        {
            sum += a[i];
        }
    }
    return sum;
}

void afiseaza(int* sol, int* a, int n)
{
    printf("%d ", a[0]);
    for (int i = 1; i < n; i++)
    {
        if (sol[i] == 0)
        {
            printf(" - ");
        }
        else
        {
            printf(" + ");
        }

        printf("%d ", a[i]);
    }

    printf("\n");
}

void backtr(int* sol, int l, int* a, int n, int S)
{
    if (l < n)
    {
        if (l == n - 1 && suma(sol, a, n) == S)
        {
            afiseaza(sol, a, n);
        }

        for (int i = 0; i < 2; i++)
        {
            sol[l] = i;
        //    afiseaza(sol, a, n);
          //  printf("\n");
            backtr(sol, l + 1, a, n, S);
        }
    }
}
int main()
{
    int n = 6;
    int v[] = { 1,3,5,7,2,6};
    int s = 0;

    int* sol = (int*)malloc(n, sizeof(int));
    int l = 0;
    backtr(sol, l, v, n, s);
}