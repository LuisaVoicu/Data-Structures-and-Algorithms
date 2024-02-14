#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int maxim(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}



void print_sub(int* sub, int* v, int i)
{
    if (i == sub[i])
    {
        printf("%d ", v[i]);
        return;
    }

    print_sub(sub, v , sub[i]);
    printf("%d ", v[i]);
}
int main()
{

   // int v[] = { 5, 10, 7, 4, 5, 8, 9, 8, 10, 2 };
   // int n = 10;
    int v[] = { 24 , 12 , 15 , 15 , 19 };
    int n = 5;
    int* sub = (int*)malloc(n * sizeof(int));
    int* dim = (int*)malloc(n * sizeof(int));
    dim[0] = 0;
    sub[0] = 0;

    int max = 0;
    int ind_mx;
    for (int i = 1; i < n; i++)
    {
        dim[i] = 0;
        sub[i] = i;
        for (int j = i; j >= 0 ; j--)
        {
            if (v[i] > v[j] && dim[i] < dim[j] + 1)
            {
                dim[i] = dim[j] + 1;
                sub[i] = j;
            }
        }

        if (dim[i] > max)
        {
            max = dim[i];
            ind_mx = i;
        }
    }
    printf("%d\n", max + 1);
    print_sub(sub,v, ind_mx);
    /*for (int i = 0; i < n; i++)
    {
        printf("%5d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        printf("%5d ", v[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%5d ", dim[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%5d ", sub[i]);
    }
    printf("\n");*/

}