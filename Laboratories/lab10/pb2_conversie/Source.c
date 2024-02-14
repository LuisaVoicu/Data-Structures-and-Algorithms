#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
    long long x = 1;
    int b = 9;
    int n = -1;
    int* v = (int*)calloc(20 ,sizeof(int));
    while (x != 0)
    {

        long long bk = 1;
        int k = 0;
        while (x >= b * bk)
        {
            ++k;
            bk *= b;
        }

        if (k > n)
        {
            n = k;
        }
        if (v[k] == 0)
        {
            v[k] = x / bk;
        }
        x -= bk;
     
    }

    for (int i = n; i >= 0; i--)
        printf("%d", v[i]);
    
}