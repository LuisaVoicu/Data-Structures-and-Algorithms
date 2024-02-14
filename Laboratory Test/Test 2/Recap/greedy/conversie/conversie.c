#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 45;
    int b = 3;
    int bpow = 1;
    int cnt = 0;
    while (bpow*3 <= x)
    {
        cnt++;
        bpow *= b;
    }
    int n = cnt;
    int* rep = (int*)calloc((n+1),sizeof(int));
   
    while (x != 0)
    {
        int val = x / bpow;
        rep[cnt] = val;
        x = x - val * bpow;
        cnt--;
        bpow /= b;
    }

    for (int i = n; i >= 0; i--)
    {
        printf("%d ", rep[i]);
    }
}