#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int f,s;
    char* nume;
}act;



void sortare(act* a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].f > a[j].f || (a[i].f == a[j].f && a[i].s > a[j].s))
            {
                act aux = a[i];
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
    act* a = (act*)malloc(n * sizeof(act));
    for (int i = 0; i < n; i++)
    {
        a[i].nume = (char*)malloc(10 * sizeof(char));
        fscanf(f, "%d %d %s", &a[i].s, &a[i].f, a[i].nume);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", a[i].s, a[i].f, a[i].nume);

    }

    sortare(a, n);
    act last = a[0];
    int cnt = 1;
    printf("%s ", last.nume);
    for (int i = 1; i < n; i++)
    {
        if (last.f <= a[i].s)
        {
            cnt++;
            last = a[i];
            printf("%s ", last.nume);
        }
    }
}