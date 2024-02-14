#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int s, p;
    int status;
}timp;

//void merge(timp* a, int l, int mid, int r)
//{   
//    int i = l, j = mid + 1;
//    timp* aux = (timp*)malloc(sizeof(timp) * (r - l + 1));
//    int k = l;
//
//    printf("merge %d %d->", i, j);
//    while (i <= mid && j <= r)
//    {
//        if (a[i].p <= a[j].p)
//            //|| (a[i].p == a[j].p && a[i].s < a[j].s))
//        {
//            aux[k++] = a[i++];
//        }
//        else
//        {
//            aux[k++] = a[j++];
//        }
//    } printf("merge %d %d\n", i, j);
//    while (i <= mid)
//    {
//        aux[k++] = a[i++];
//    }
//    while (j <= r)
//    {
//        aux[k++] = a[j++];
//    }
//
//    for (int i = l; i <= r; i++)
//        a[i] = aux[i];
//}

//void mergeSort(timp* a, int l, int r)
//{
//    if (l >= r)
//    {
//        return;
//    }
//    int mid = (l + r) / 2;
//    mergeSort(a, l, mid);
//    mergeSort(a, mid + 1, r);
//    merge(a, l, mid, r);
//}



void sorteaza(timp* a, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        if(a[i].p > a[j].p || 
          (a[i].p == a[j].p && a[i].s >a[j].s))
        {
            timp aux = a[i];
            a[i] = a[j];
            a[j] = aux;
        }
    }
}


int main()
{
    FILE* f = fopen("file.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    timp* a = (timp*)malloc(n * sizeof(timp));

    for(int i=0;i<n;i++)
    { 
        fscanf(f, "%d %d", &a[i].s, &a[i].p);
        a[i].status = 0;
    }

    sorteaza(a, 0, n - 1);

     /*for (int i = 0; i < n; i++)
     {
         printf("%d %d\n", a[i].s, a[i].p);
     }*/

     int done;

     do
     {

         int k = 0;
         done = 1;
         for (int i = 0; i < n; i++)
             if (a[i].status == 0)
             {
                 k = i; 
                 done = 0;break;
             }
        
         if (done) break;
         timp last = a[k];
         a[k].status = k+1;
         printf("%d %d\n", last.s, last.p);
         for(int i = k+1;i<n;i++)
             if (!a[i].status && a[i].s >= last.p)
             {
                 a[i].status = k+1;
                 printf("%d %d\n", a[i].s, a[i].p);
                 last = a[i];
             }
         printf("\n\n");
     } while (!done);
}



