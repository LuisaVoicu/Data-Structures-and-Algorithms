#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int s;
    int f;
    char* nume;
}act;



void quickSort(act* v, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        act aux = v[l];
        v[l] = v[m];
        v[m] = aux;

        int i = l, j = r, d = 0;
        while (i < j)
        {
            if (v[i].f > v[j].f || (v[i].f  ==  v[j].f && v[i].s > v[j].s))
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        quickSort(v, l, i - 1);
        quickSort(v, i + 1, r);

    }
}
int main()
{
    FILE* f = fopen("file.in", "r");

    int n;
    fscanf(f, "%d", &n);
    act* v = (act*)malloc(sizeof(act) * n);

    for (int i = 0; i < n; i++)
    {
        v[i].nume = (char*)malloc(sizeof(char) * 20);
        fscanf(f, "%d", &v[i].s);
        fscanf(f, "%d", &v[i].f);
         fscanf(f, "%s", v[i].nume);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", v[i].s, v[i].f);
    }
    quickSort(v, 0, n - 1);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %s\n", v[i].s, v[i].f, v[i].nume);
    }

    printf("\n________________________________\n\n");

    int count = 1;
    int ultimul = 0;
    printf("%d %d %s\n", v[ultimul].s, v[ultimul].f, v[ultimul].nume);
    
    for (int i = 1; i < n; i++)
    {
        if (v[i].s >= v[ultimul].f)
        {
            count++;
            ultimul = i;
            printf("%d %d %s\n", v[ultimul].s, v[ultimul].f, v[ultimul].nume);

        }
    }

}