#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main()
{
    int n = 234;
    int putere = 1;
    int cnt = -1;
    int* B = (int*)malloc(sizeof(int) * 100);
    B[++cnt] = 1;
    while (putere * 2 < n)
    {
        putere = putere * 2;
        B[++cnt] = putere;    
    }
        

    while (cnt >= 0)
    {
        if (n - B[cnt] >= 0)
        {
            printf("%d ", B[cnt]);
            n -= B[cnt];
        }
        cnt--;
    }
  
}