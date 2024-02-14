#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a[] = { 1,2,5 };
    int n = sizeof(a) / sizeof(int);
    int sum = 12;
    int* aux = (int*)calloc(sum + 1, sizeof(int));

    aux[0] = 1;
    for (int k = 0; k < n; k++)
    {
        
        for (int i = 1; i <= sum; i++)
        {
            if (i >= a[k])
            {
                aux[i] = aux[i] + aux[i - a[k]];
            }
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        printf("%d ", aux[i]);
    }
    printf("\n");
}