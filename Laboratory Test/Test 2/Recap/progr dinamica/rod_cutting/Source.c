#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NINF -100



int main()
{

    int a[] = { 0,1,5,8,9,10 };
    int n = sizeof(a) / sizeof(int);
    int* r = (int*)malloc(sizeof(int)*(n+1));
    int* sol = (int*)malloc(sizeof(int)*(n+1));

    r[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int cmbv = NINF; // cea mai buna varianta
        
        for (int j = 1; j <= i; j++)
        {
            if (cmbv < a[j] + r[i-j])
            {
                cmbv = a[j] + r[i-j];
                sol[j] = i;
            }
        }
        r[i] = cmbv;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", r[i]);
}