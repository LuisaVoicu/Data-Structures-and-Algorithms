#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>






int main()
{
    FILE* f = fopen("file.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    printf("%d\n", n);
    int** mat = (int**)malloc(n * sizeof(int*));
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)calloc(n, sizeof(int));
        fscanf(f, "%d", &a[i]);
        printf("%d ", a[i]);
    }



}