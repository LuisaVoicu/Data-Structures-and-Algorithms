#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int v[] = { 1,2,5 };
    int n = 3;
    int s = 12;

    int* comb = (int*)calloc((s+1), sizeof(int));
    comb[0] = 1;

    for (int i = 0; i < n; i++)
    {
        int val = v[i];
        for (int cantitate = 1; cantitate <= s; cantitate++)
        {
            if (cantitate >= val)
            {
                comb[cantitate] += comb[cantitate - val];
            }
        }
    }
    for (int i = 1; i <= s; i++)
    {
        printf("%d ", comb[i]);
    }

   printf("\nsuma %d se poate obtine in %d moduri", s, comb[s]);
}