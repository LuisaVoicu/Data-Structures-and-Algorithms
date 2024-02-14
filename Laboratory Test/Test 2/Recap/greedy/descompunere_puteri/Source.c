#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 35;
    int b = 2;
    int bpow = 1;
    
    while (bpow * 2 <= x)
    {
        bpow *= b;
    }

    while (x > 0)
    {
        if (x - bpow >= 0)
        {
            printf("%d ", bpow);
            x -= bpow;
        }
        bpow /= b;
    }
}