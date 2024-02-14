#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int verifica_egalitate(char a[][10], int n, int mid)
{
    for (int i = 1; i < n; i++)
        if (a[i][mid] != a[0][mid])
        {
            return 0;
        }

    return 1;
}


int maxim(int a, int b, int c)
{
    return max(max(a, b), c);
}

int divide_impera(char a[][10], int n, int st, int dr)
{
    if (st > dr)
    {
        return 0;

    }

    int mid = (st + dr) / 2;
    
    int k = verifica_egalitate(a, n, mid);
    int right = 0;
    if (k)
    {
        right = divide_impera(a, n, mid + 1, dr);

    }
    int left = divide_impera(a, n, st, mid - 1);
    return maxim(mid*k,left, right);
}



int min_word(char a[][10], int n)
{
    
     int l_min = strlen(a[0]);
    for (int i = 1; i < n; i++)
    {
        int k = strlen(a[i]);
        if (k < l_min)
        {
            l_min = k;
        }
    }
    return l_min;
}

int main()
{
    char a[][10] = { "gigel","gin","gir","giratoriu" };
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        printf("%s \n", a[i]);
    }

    int lmin = min_word(a, n);
    int k = divide_impera(a, n, 0, lmin - 1);
    printf("\ndim prefix: %d\n", k+1);
    for (int i = 0; i <= k; i++)
        printf("%c", a[0][i]);
    printf("\n");

}