#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 1000000

int get_min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}



void print_sol(int* a,int*ant, int i)
{
    if (ant[i] == -1)
    {
        printf("%d ", a[i]);
        return;
    }
    {
        print_sol(a,ant,ant[i]);
        printf("%d ", a[i]);
    }
}

int main()
{
    int a[] = { 10,12,9,13,51,43,7,19 };
    int n = sizeof(a) / sizeof(int);
    int* aux = (int*)malloc(n * sizeof(int));
    int* ant = (int*)calloc(n , sizeof(int));
   
    int maxim = 0;
    int ord_max = -1;

    for (int i = 0; i < n; i++)
    {
        aux[i] = 1;
        ant[i] = -1;
    }
    
    aux[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
 
            if (a[i] >= a[j] && aux[j] + 1 > aux[i])
            {
                aux[i] = aux[j] + 1;
                ant[i] = j;
            }
        }
        if (aux[i] > maxim)
        {
            maxim = aux[i];
            ord_max = i;
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        printf("%3d ", i);
    }
    printf("\n");

    
    for (int i = 0; i < n; i++)
    {
        printf("%3d ", a[i]);
    }
    printf("\n");


    for (int i = 0; i < n; i++)
    {
        printf("%3d ", ant[i]);
    }*/
    print_sol(a,ant, ord_max);
    

}