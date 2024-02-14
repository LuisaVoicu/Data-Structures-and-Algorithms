#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int divide_conquer_siruri_egale(int* a, int* b, int la,int ha, int lb, int hb)
{

    
        int mid1 = (la + ha) / 2;
        int mid2 = (lb + hb) / 2;

        int rest1 = (la + ha) % 2;
        int rest2 = (lb + hb) % 2;
printf("%d %d %d %d---> %d %d   ", la, ha, lb, hb,mid1,mid2);
        int new_mid1 = mid1, new_mid2 = mid2;
        

        if (a[mid1] == b[mid2])
        {
            //oprire
            printf("mijloc: %d\n", a[mid1]);
            return;

        }
        else if (ha - la == 1)
        {
            int* aux = (int*)malloc(4 * sizeof(int));
            aux[0] = a[la]; aux[1] = a[ha];
            aux[2] = b[lb]; aux[3] = b[hb];
            for (int i = 0; i < 3; i++)
            {
                for (int j = i + 1; j < 4; j++)
                {
                    if (aux[i] > aux[j])
                    {
                        int x = aux[i];
                        aux[i] = aux[j];
                        aux[j] = x;
                    }
                }
            }

            // mijloace:  aux[1] si aux[2]

            printf("mijloc: %d %d\n", aux[1], aux[2]);
            return;
            
        }
        else if (a[mid1] < b[mid2])
        {
            printf("caz mai mic\n");
            // la numar impar de elemente voi lua inclusiv mijlocul
            // la numar par de elemente voi lua cel mai din dreapta mijloc
            new_mid1 = mid1;
            new_mid2 = mid2;
            if (rest1 != 0) //nr par de elem
            {
                new_mid1++;
            }
            divide_conquer_siruri_egale(a, b, new_mid1, ha, lb, new_mid2);
        }
        else if (a[mid1] > b[mid2])
        {
            printf("caz mai mare\n");
            if (rest2 != 0) // nr par de elemente
            {
                new_mid2++;
            }
            divide_conquer_siruri_egale(a, b, la, new_mid1, new_mid2, hb);
        }
    

}

int main()
{
    int n, m;
    int a[] = { 0,1,2,4,6,9,12 }; // 0 e pt alinierea vectorului
    int b[] = { 0,7,9,14,18,23,48 };
     n = 6; m = 6;
    divide_conquer_siruri_egale(a, b, 1, n, 1, m);


    printf("\n\n");

    int c[] = { 0,1,3,5,5,9 }; // 0 e pt alinierea vectorului
    int  d[] = { 0,2,2,4,10,13 };
     n = 5; m = 5;
    divide_conquer_siruri_egale(c, d, 1, n, 1, m);

    printf("\n\n");


    int e[] = { 0,2,3,7,9 };
    int f[] = { 0,4,5,8,9 };
    n = 4; m = 4;

    divide_conquer_siruri_egale(e, f, 1, n, 1, m);


}