#include <stdio.h>
#include <stdlib.h>

void adauga( double *v , int *n, double val)
{
    v[*n] = val;
    (*n)++;
}

int main()
{
    int Size, Capacity, n;
    double* Nr ;

    printf("Introduceti valorile pentru Capacity si Size: ");
    scanf("%d %d", &Capacity , &Size);

    printf("Introduceti numarul initial de elemente din vector (sau 0 daca nu exista elemente in vector): ");
    scanf("%d",&n);

    Nr = (double*)malloc( Capacity * sizeof(double));
    if(Nr == NULL)
    {
        printf("Vectorul nu poate fi alocat dinamic!");
        exit(1);
    }

    // daca Capacity < Size atunci este necesara realocarea dinamica
    // daca Capacity < Size + n este necesara realocarea dinamica
    // deci e suficient sa verificam daca inegalitatea are loc doar pentru Size + n
    if(Capacity < Size + n)
    {
        double *Re = (double*)realloc(Nr, (Size + n) * sizeof(double));
        if(Re == NULL)
        {
        printf("Vectorul nu poate fi realocat dinamic!");
        exit(2);
        }
        Nr = Re;
    }

    if(n != 0)
    {
        printf("Introduceti cele %d elemente din vector: ", n);
        for(int i = 0 ; i < n ; i++)
        scanf("%lf",&Nr[i]);
    }

    for(int i = 0; i < Size; i ++)
    {   double val;
        printf("\nIntroduceti elementul %d ce va fi inserat in vector: ", i + 1);
        scanf("%lf",&val);

        adauga(Nr,&n,val);

        printf("\nDupa inserarea %d, sirul este:\n" , i + 1);
        for(int j = 0 ; j < n ; j++)
        printf("%g ",Nr[j]);
        printf("\n");
    }

    return 0;
}
