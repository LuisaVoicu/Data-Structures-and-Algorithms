#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>





int main()
{
    int a[] = { 100, 50, 20, 10, 5, 1, -10, -20, -30 };
    int b[] = { 8, 5, 3, 1, -2, -10, -100 };
    int na = sizeof(a) / sizeof(int);
    int nb = sizeof(b) / sizeof(int);
    // compar prod elem din stanga cu cel din dreapta (din cauza semnului)

    int m = min(na, nb);

    int* c = (int*)calloc(m, sizeof(int));

    int k = 0;
    int i = 0;
    int j = 0;
    --na; --nb;
    while (k < m)
    {
        int prodST = a[i] * b[j];
        int prodDR = a[na] * b[nb];
       // printf("%d %d\n", prodST, prodDR);
        if (prodST > prodDR)
        {
            c[k++] = prodST;
            i++; j++;
        }
        else
        {
            c[k++] = prodDR;
            na--; nb--;
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += c[i];
        printf("%d ", c[i]);
    }
    printf("\n%d\n", sum);
}