#include <stdio.h>
#include <stdlib.h>

void adauga_la_inceput( double *v , int *n, double val)
{

    (*n)++;
    for(int i = (*n) - 1; i > 0 ; i--)
        v[i] = v[i - 1];
    v[0] = val;
}

int main()
{
    double *Vec;
    int Capacity, Size, n;
    printf("Introduceti valorile pentru Capacity si Size: ");
    scanf("%d %d", &Capacity, &Size);

    Vec = (double*)malloc(Capacity * sizeof(double));

    if(Vec == NULL)
    {
        printf("Vectorul nu poate fi alocat dinamic!");
        exit(1);
    }

    // Capacity < Size => Vectorul va fi realocat dinamic
    // Capacity < Size + n (unde n reprezinta numarul de elemente aflate deja in vector) => Vectorul va fi realocat dinamic
    // este suficient sa verificam a doua conditie

    if(Capacity < Size + n)
    {
        double* Re = (double*)realloc(Vec,(Size + n) * sizeof(double));
        if(Re == NULL)
        {
            free(Re);
            printf("Vectorul nu poate fi realocat dinamic!");
            exit(2);
        }
        Vec = Re;
    }

    printf("Introduceti numarul de elemente aflate deja in vector sau 0 daca nu exista elemente in vector: ");
    scanf("%d",&n);

    if(n != 0)
    {
        printf("Introduceti elementele aflate initial in vector:\n");
        for(int i = 0 ; i < n ; i++)
        scanf("%lf",&Vec[i]);
    }

    for(int i = 0 ; i < Size;i++)
    {
        double val;
        printf("\nIntroduceti elementul %d ce va fi inserat pe pozitia 0 a sirului: ", i + 1);
        scanf("%lf",&val);

        adauga_la_inceput(Vec, &n, val);
        printf("\nDupa inserarea %d, sirul este:\n",i + 1);

        for(int j = 0; j < n ; j++)
            printf("%g ",Vec[j]);

        printf("\n");
    }


    return 0;
}
