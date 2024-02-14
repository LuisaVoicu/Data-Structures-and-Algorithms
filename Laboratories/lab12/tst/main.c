#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int max(int a,int b)
{

    if(a>b)
        return a;
    return b;
}

int maxpow(int x, int y)
{
    int cntx = 1;
    int cnty = 1;

    while (x/10 > 0)
    {
        cntx++;
        x = x / 10;
    }

    while (y/10 > 0)
    {
        cnty++;
        y = y / 10;
    }

    return max(cnty, cntx);
}

int pow10(int pow)
{
    int x = 1;

    while (pow-1)
    {
        x *= 10;
        pow--;
    }
    return x;
}

void split(int x, int tenm, int *x0,int *x1)
{
    *x1 = x / tenm;
    *x0 = x % tenm;
}

int karatsuba(int x, int y)
{

    if (x < 10 || y < 10)
    {
        return x * y;
    }
    int m = maxpow(x, y) / 2;
    int tenm = pow10(m);
    int x1, x0;
    split(x, tenm, &x0, &x1);
    int y1, y0;
    split(y, tenm, &y0, &y1);

    int z0 = karatsuba(x0 , y0 );
    int z2 = karatsuba(x1, y1);
    int z1 = karatsuba(x1 + x0, y1 + y0) - z2 - z0;

    int ten2m = pow10(2 * m);
    return z2 * ten2m + z1 * tenm + z0;


}


int main()
{
    int x=12;
    int y=16;
    int s = karatsuba(x,y);
    printf("%d \n",s);
}
