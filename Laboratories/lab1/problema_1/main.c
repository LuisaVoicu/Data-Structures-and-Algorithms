#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *Nume , *Prenume;
    unsigned Varsta;
    unsigned *Note;
    double Medie;
}Student;

double Medie(unsigned a, unsigned b, unsigned c)
{
    double med = 1.0*(a + b + c)/3;
    return med;
}
int main()
{
    FILE *pf = fopen("fisier.txt","r");

    if(pf == NULL)
    {
        printf("Fisierul nu poate fi deschis!\n");
        exit(1);
    }

    int n;
    fscanf(pf,"%d",&n);
    printf("%d\n",n);

    Student *Studenti = (Student*)malloc(n*sizeof(Student));

    for(int i = 0; i < n ; i++)
    {

        Studenti[i].Nume = (char*)malloc(100*sizeof(char));
        Studenti[i].Prenume = (char*)malloc(100*sizeof(char));
        Studenti[i].Note = (unsigned*)malloc(100*sizeof(unsigned));

        fscanf(pf,"%s %s %d %d %d %d\n",Studenti[i].Nume , Studenti[i].Prenume,&Studenti[i].Varsta,&Studenti[i].Note[0],&Studenti[i].Note[1],&Studenti[i].Note[2]);
        printf("%s %s %u %u %u %u\n",Studenti[i].Nume, Studenti[i].Prenume, Studenti[i].Varsta,Studenti[i].Note[0], Studenti[i].Note[1], Studenti[i].Note[2]);
    }

    printf("\n");
    for(int i = 0 ; i < n ; i++)
    {
        Studenti[i].Medie = Medie(Studenti[i].Note[0], Studenti[i].Note[1], Studenti[i].Note[2]);
        printf("Nume si Prenume: %s %s ~ Medie: %.2g\n",Studenti[i].Nume,Studenti[i].Prenume,Studenti[i].Medie);
    }

    printf("\n");
    for(int i = 0 ; i < n ; i++)
    {
        if(Studenti[i].Note[0] + 1 <= 10)
        {
            Studenti[i].Note[0]++;
        }
        if(Studenti[i].Note[1] + 1 <= 10)
        {
            Studenti[i].Note[1]++;
        }
        if(Studenti[i].Note[2] + 1 <= 10)
        {
            Studenti[i].Note[2]++;
        }

        printf("%s %s %u %u %u %u\n",Studenti[i].Nume, Studenti[i].Prenume, Studenti[i].Varsta,Studenti[i].Note[0], Studenti[i].Note[1], Studenti[i].Note[2]);
    }
    return 0;
}
