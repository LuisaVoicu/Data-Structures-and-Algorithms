#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int pseudo_bs(int* a, int l, int r, int num)
{
    if (l>r)
    {
        //oprire
        return -1;
    }

    int mid = (l + r) / 2;

    if (a[mid] == num)
    {
        return mid; 
    }


    if (a[l] <= a[mid])
    {
        // intervalul  (l,mid) nu e afectat de rotatie
        if (a[l] <= num && num < a[mid])
        {
            // numarul se alfa in intervalul neafectat ==> bs normal 
            return pseudo_bs(a, l, mid, num);

        }
        else
        {
            // numarul (poate) se afla in intervalul afectat de roatie
            return pseudo_bs(a, mid + 1, r, num);

        }
    }

    else if (a[mid] <= a[r])
    { 
        // intervalul (mid,r) nu e afectat de roatie

        if (a[mid] < num && num <= a[r])
        {
            // interval neafectat => bs normal
            return pseudo_bs(a, mid + 1, r, num);
        }
        else
        {
            return pseudo_bs(a, l, mid, num);
        }

    }

}

int main()
{

    /// test1:
    printf("\n\nTEST1:\n\n");
    int a[] = { 0,13,14,14,15,25,27,1,3,7,11 };
    int corect[100];
    int testa[] = { 13, 34, 27, 9, 1, 0, 12 };
    int nt = 7;
    int n = 10;
    for (int i = 0; i < 100; i++)
    {
        corect[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        corect[a[i]] = i;
    }


    for (int i = 0; i < nt; i++)
    {
        int rez = pseudo_bs(a, 1, n, testa[i]);
        printf("%2d -> rez : %d  ~~ r: %d\n..........\n", testa[i], rez, corect[testa[i]]);
    }


    printf("\n\nTEST2:\n\n");
    /// test2
    int b[] = { 0,25,47,3,9,18,21 };
    int testb[] = {1,21,23,47,2};
    int nbt = 5;
    int nb = 6;
    for (int i = 0; i < 100; i++)
    {
        corect[i] = -1;
    }
    for (int i = 1; i <= nb; i++)
    {
        corect[b[i]] = i;
    }
    for (int i = 0; i < nbt; i++)
    {
        int rez = pseudo_bs(b, 1, nb, testb[i]);
        printf("%2d -> rez : %d  ~~ r: %d\n..........\n", testb[i], rez, corect[testb[i]]);
   }

}