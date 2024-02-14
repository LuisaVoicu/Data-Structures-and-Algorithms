#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 10000


int minim(int a, int b, int c)
{
    int mi = a;
    if (b < mi)
        mi = b;
    if (c < mi)
        mi = c;
    return mi;
}

int cmmdc(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int div_imp_min(int*a, int st, int dr)
{
    //printf("%d %d \n", st, dr);
    if (st > dr)
        return INF;
    int mid = (st + dr) / 2;
    return minim(a[mid], div_imp_min(a, st, mid - 1), div_imp_min(a, mid+1, dr));
}

int div_imp_cmmdc(int* a, int st, int dr)
{
    if (st > dr)
        return 0;
    int mid = (st + dr) / 2;
    return cmmdc(cmmdc(a[mid], div_imp_cmmdc(a, st, mid - 1)), div_imp_cmmdc(a, mid + 1, dr));
}

int main()
{

    int a[] = { 2,4,6,18 };
    int n = sizeof(a) / sizeof(int);

    int mi = div_imp_min(a, 0, n - 1);
    printf("min %d\n", mi);

    int cmd = div_imp_cmmdc(a, 0, n - 1);
    printf("cmmdc %d\n", cmd);
}