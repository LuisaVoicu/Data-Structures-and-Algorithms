#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int p, w;
    double proc;
}obj;


void sort(obj* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        if(a[i].proc<a[j].proc || (a[i].proc == a[j].proc && a[i].p<a[j].p))
        {

            obj aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }
}

int main()
{
    FILE* f = fopen("file.txt", "r");
    int n, wmax;
    fscanf(f, "%d %d", &n, &wmax);
    obj* a = (obj*)calloc(n , sizeof(obj));

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d %d", &a[i].p, &a[i].w);
        a[i].proc = 1.0*a[i].p / a[i].w;
    }
    /*for (int i = 0; i < n; i++)
    {
        printf("%g ", a[i].proc);
    }
    printf("\n");*/
    sort(a, n);

    /*for (int i = 0; i < n; i++)
    {
        printf("%d %g\n",a[i].w,a[i].proc);
    }*/

    int k = 0;
    double profit_total = 0;
    while (wmax - a[k].w >= 0)
    {
        printf("%d->%d 100%\n", a[k].p, a[k].w);
        wmax -= a[k].w;
        profit_total = profit_total + 1.0 * a[k].p;
        k++;
    }
        
    
    if (wmax != 0)
    {
        double procent = 1.0*wmax * 100 / a[k].w;
        double profit =  procent * a[k].p / 100;
        profit_total = profit_total + profit;
        printf("%g->%g\n", procent, profit);
    }

    printf("\n%g\n", profit_total);
}