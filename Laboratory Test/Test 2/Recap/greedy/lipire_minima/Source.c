#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 10000


int cauta_min(int* a, int n,int*m1,int*m2)
{
    *m1 = *m2 = -1;
    int min1 = INF;
    int min2 = INF;
    for (int i = 0; i < n; i++)
    {
       // printf("%d ", a[i]);
        if (a[i] < min1)
        {
            min2 = min1;
            *m2 = *m1;
            min1 = a[i];
            *m1 = i;
        }
        else if (a[i] <= min2)
        {
            min2 = a[i];
            *m2 = i;
        }
    }
    if (*m1 == -1 || *m2 == -1)
        return 0;
    return 1;
}
int main()
{
    int a[] = { 1,1,4 };
    int m1, m2;
    int n = sizeof(a) / sizeof(int);
    int sum_min = 0;


    while (cauta_min(a, n, &m1, &m2))
    {
        
        printf("%d %d\n", a[m1], a[m2]);
        sum_min = a[m1] + a[m2];
        a[m1] = INF+1;
        a[m2] = sum_min;
    }
    printf("\n%d\n", sum_min);


}