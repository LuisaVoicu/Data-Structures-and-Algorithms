#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int absolute(int a)
{
    if (a < 0)
        a *= (-1);
    return a;
}

int is_valid(int* x, int k)
{

    for (int i = 1; i < k; i++)
    {
        if (x[i] == x[k] || (k - i == absolute(x[k] - x[i])))
        {
            return 0;
        }
    }
    
    return 1;
}


void print_solution(int* x, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
            {
                printf("R");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void regine_rec(int* x, int n, int k)
{
    if (k <= n)
    {
        

        for (int i = 1; i <= n; i++)
        {
            x[k] = i;
            int sol = is_valid(x, k);
            if (k == n && sol)
            {
            print_solution(x, n);
            }
            if (sol)
            {
                regine_rec(x, n, k + 1);
            }
        }
    }
}
int main()
{
    int n = 4;
    int* x = (int*)calloc(n, sizeof(int));
    regine_rec(x, n, 1);
}