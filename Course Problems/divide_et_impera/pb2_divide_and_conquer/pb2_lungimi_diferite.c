#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void divide_impera(int* a, int* b, int la, int ha, int lb, int hb)
{
    // a -> sirul de lungime mai mica
    int mid1 = (la + ha) / 2;
    int mid2 = (lb + hb) / 2;

    int rest1 = (la + ha) % 2;
    int rest2 = (lb + hb) % 2;
    printf("%d %d %d %d---> %d %d   ", la, ha, lb, hb, mid1, mid2);

    int new_mid1 = mid1;
    int new_mid2 = mid2;

    if (a[mid1] == b[mid2])
    {
        //oprire
        printf("mijloc: %d\n", a[mid1]);
        return;
    }
    else if (ha - la == 0)
    {
       if(a[la] < b[lb])
        printf("mijloc: %d", a[la]);
       else
       {
           printf("mijloc: %d", b[lb]);
       }

    }
    else if (a[mid1] < b[mid2])
    {
        printf("caz mai mic\n");
        // la numar impar de elemente voi lua inclusiv mijlocul in calculul subproblemei
        // la numar par de elemente voi lua cel mai din dreapta mijloc

        if (rest1 != 0) //nr par de elem
        {
            new_mid1++;
        }
        int new_lb = new_mid2 - (ha - new_mid1);

        divide_impera(a, b, new_mid1, ha, new_lb, new_mid2);
    }
    else if (a[mid1] > b[mid2])
    {
        printf("caz mai mare\n");
        if (rest2 != 0) // nr par de elemente
        {
            new_mid2++;
        }
        int new_hb = new_mid2 + (new_mid1 - la);
        divide_impera(a, b, la, new_mid1, new_mid2, new_hb);
    }


}

int main()
{
    int n, m;
    int a[] = { 0,1,7,8,10 }; // 0 pt alinierea sirului  // consider a sirul cel mic
    int b[] = { 0,2,3,5,9,12,13,24 };
    n = 4; m = 7;
    divide_impera(a, b, 1, n, 1, m);    
    printf("\n\n");

    int c[] = { 0,1,7,8,10,14 }; // 0 pt alinierea sirului  // consider a sirul cel mic
    int d[] = { 0,2,3,5,9,12,13,24 };
    n = 5; m = 7;
    divide_impera(c, d, 1, n, 1, m);
    printf("\n\n");


    int e[] = { 0,1,7,8,10,14,15 }; // 0 pt alinierea sirului  // consider a sirul cel mic
    int f[] = { 0,2,3,5,9,12,13,24 };
    n = 6; m = 7;
    divide_impera(e, f, 1, n, 1, m);
    printf("\n\n");

    int g[] = { 0,1,7,8,10,14,15 }; // 0 pt alinierea sirului  // consider a sirul cel mic
    int h[] = { 0,2,3,5,9,12,13,24,29 };
    n = 6; m = 8;
    divide_impera(e, f, 1, n, 1, m);
    printf("\n\n");



}