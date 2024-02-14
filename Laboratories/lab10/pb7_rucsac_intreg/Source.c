#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int v;
    int g;
    double rap;
}rucsac;



void quick_sort(rucsac* ruc, int l, int r)
{

    if (l < r)
    {
        int m = (l + r) / 2;
        rucsac aux = ruc[l];
        ruc[l] = ruc[m];
        ruc[m] = aux;

        int i = l, j = r, d = 0;
        while (i < j)
        {
            if ( ruc[i].rap < ruc[j].rap || (ruc[i].rap == ruc[j].rap && ruc[i].v < ruc[j].v))
            {
                aux = ruc[i];
                ruc[i] = ruc[j];
                ruc[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        quick_sort(ruc, l, i - 1);
        quick_sort(ruc, i + 1, r);
    }

}

int main()
{
    FILE* f = fopen("file.txt", "r");
    int n;
    int gmax;
    fscanf(f, "%d %d", &n, &gmax);

    rucsac* ruc = (rucsac*)malloc(sizeof(rucsac)*n);

    for (int i = 0; i < n; i++)
    {
        
        fscanf(f, "%d %d", &ruc[i].v,&ruc[i].g);
        ruc[i].rap = 1.0 * ruc[i].v / ruc[i].g;
      //  printf("%lf ", ruc[i].rap);
    }
    quick_sort(ruc, 0, n-1);
    printf("%d\n", gmax);
    for (int i = 0; i < n; i++)
    {
       // printf("%g %d\n", ruc[i].rap,ruc[i].g);
        if (gmax - ruc[i].g > 0)
        {
            printf("se introduce produsul de val %d si cant %d\n", ruc[i].v, ruc[i].g);
            gmax -= ruc[i].g;
        }
        else if (gmax == 0)
        {
            break;
        }
        else
        {
            //fractionam produsul;
            
            double procent = 1.0 * (gmax * 100) / ruc[i].g;
            double new_price = 1.0 * (procent * ruc[i].v) / 100;
            printf("->se introduce produsul de val %g si cant %g%%\n", new_price , procent);
            break;
        }
    }
}