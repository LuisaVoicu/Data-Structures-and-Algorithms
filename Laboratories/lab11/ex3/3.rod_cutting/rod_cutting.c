#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NINF -1000


int maxim(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int rod_cutting_td(int* p, int* mx, int n)
{

    if (n == 0)
        return 0;

    if (mx[n] != NINF)
        return mx[n];

    int maximul = 0;
    for (int i = 1; i <= n; i++)
    {
        maximul = maxim(maximul,p[i] + rod_cutting_td(p, mx, n - i));
    }
    mx[n] = maximul;
    return maximul;
}


int rod_cutting_bu(int* p, int* mx, int n)
{
    mx[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int maximul = 0;
        for (int j = 1; j <= i; j++)
        {
            maximul = maxim(maximul, p[j] + mx[i - j]);
        }
        mx[i] = maximul;
    }
}


int rod_cutting_bu_solution(int* p, int* mx, int n, int* sol)
{
    mx[0] = 0;
    sol[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int max = 0;
        sol[i] = i;
        for (int j = 1; j <= i; j++)
        {
            if (max < p[j] + mx[i - j])
            {
                max = p[j] + mx[i - j];
                sol[i] = j;
            }
        }

        mx[i] = max;
    }
}


void print_solution(int* sol, int n)
{
    while (n > 0)
    {
        printf("%d ", sol[n]);
        n = n - sol[n];

    }
}

int main()
{
    FILE* f = fopen("fisier.txt", "r");

    int n;
    fscanf(f, "%d", &n);
    int* p = (int*)malloc((n+1)*sizeof(int));
    int* mx = (int*)malloc((n+1)*sizeof(int));

    for (int i = 1; i <= n; i++)
    {
        mx[i] = NINF;
        fscanf(f,"%d", &p[i]);
    }



    ///// TOP DOWN
    printf("\nrezultat top down:\n");
    rod_cutting_td(p, mx, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", mx[i]);
    }



   
    /////

    for (int i = 1; i <= n; i++)
    {
        mx[i] = NINF;
    }

    //// BOTTOM UP
    rod_cutting_bu(p, mx, n);

    printf("\n\nvarianta bottom up:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", mx[i]);
    }
    printf("\n");



    /////

    for (int i = 1; i <= n; i++)
    {
        mx[i] = NINF;
    }

    /// gasirea sirului / solutiei efective
    ///// salvam decizia care a dus acolo

    int* sol = (int*)malloc((n + 1) * sizeof(int));
    rod_cutting_bu_solution(p, mx, n,sol);

    
    printf("\nsectiunile pt o tija de lungime 9 este:\n");
    print_solution(sol, n-1);
    printf("\n");

}