#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int c, v;
}prod;




int main()
{
    FILE* f = fopen("file.txt", "r");
    int n, cant;
    //fscanf(f, "%d %d", &n, &cant);
    //prod* a = (prod*)malloc(sizeof(prod) * n);
    //for (int i = 0; i < n; i++)
    //{
    //    fscanf(f, "%d %d", &a[i].c, &a[i].v);
    //    printf("%d %d\n", a[i].c, a[i].v);
    //}


}