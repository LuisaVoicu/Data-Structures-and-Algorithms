#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 

int absolute(int a)
{
    if (a < 0)
        a *= (-1);
    return a;
}

int is_a_solution(int k, int n)
{
    if (k == n)
    {
        return 1;
    }
    return 0;
}

int valid(int* a, int k)
{
    for (int i = 1; i < k; i++)
    {
        if (a[i] == a[k])
            return 0;
        if (k - i == absolute(a[k] - a[i]))
            return 0;
    }
    return 1;
}


void process_solution(int* a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == j)
            {
                printf("R ");
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}


int construct_candidates(int* a, int n)
{
  
    int k = 1;
    a[k] = 0;
    int solutie = 0;
    int count = 0;
    while (k)
    {

        int sol_valida = 0; 
        int val_buna = 1;  // a[k] se afla in [1,n]

        do
        {
            a[k]++;
            if (a[k] > n || a[k] < 1)
            {
                val_buna = 0;
            }
            else
            {
                sol_valida = valid(a, k);
            }

        } while (val_buna && !sol_valida);

        if (val_buna)
        {
            if (k == n)
            {
                solutie = 1;
                printf("Solutia %d:\n\n", ++count);
                process_solution(a, n);
            }
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
        {
            k--;
        }

    }
    return solutie;
    
}


int main()
{
    int n = 4;
    int* a = (int*)malloc(sizeof(int) * (n + 1));
    int k = construct_candidates(a, n);
    if (k == 0)
    {
        printf("Nu exista solutii!\n");
    }
}