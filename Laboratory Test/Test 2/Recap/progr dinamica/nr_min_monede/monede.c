#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 100000

int main()
{
    int a[] = { 1,3,5 };
    int n = sizeof(a) / sizeof(int);
    int sum = 11;
    int* aux = (int*)malloc((sum+1) * sizeof(int));
    int* ant = (int*)malloc((sum+1) * sizeof(int));
    int* compl = (int*)malloc((sum+1) * sizeof(int));
    
    aux[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        aux[i] = INF;
    }

    for (int k = 0; k < n; k++)
    {
        
        for (int j = 1; j <= sum; j++)
            if (j>=a[k] && aux[j-a[k]] + 1 <= aux[j])
            {
                ant[j] = j - a[k];
                compl[j] = a[k];
                aux[j] = aux[j - a[k]] + 1;
            }
    }



    for (int i = 1; i <=sum; i++)
    {
        printf("%d + %d = %d -> %d\n", compl[i],ant[i],i,aux[i]);
    }
    printf("\n");
    printf("\n");

    // refacem solutia
    int i = sum;
    
    while (i )
    {
        printf("%d ", compl[i]);
        i = ant[i];
    }
    
}