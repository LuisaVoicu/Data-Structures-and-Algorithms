#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum { INVALID, VALID };


int valid_solution(int* x, int k)
{

    for (int i = 1; i < k; i++)
    if(x[k] == x[i])
    {
        return 0;
    }
    return 1;
}

void print_solution(int* x, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
}

void permutari_iterativ(int n)
{
    int* x = (int*)calloc(n , sizeof(int)); // vector de solutii
    int k = 1; // pozitia curenta in vector
    int sol; // solutie (in)valida;
    int ok = 0;
    while (k > 0)
    {
        sol = INVALID;
        ok = VALID;
        do
        {
            x[k]++;
            if (x[k] > n || x[k]<1)
            {
                ok = INVALID;
            }
            else
            {
                print_solution(x, k);

                sol = valid_solution(x, k);
                if (sol && k == n)
                {
                    printf(" - solution");
                }
                printf("\n");
            }

        } while (!sol && ok);
        if (!ok)
        {
            k--; // update solutii
        }
        else if(ok && k != n)
        {
            k++;
            x[k] = 0;
        }

    }
}

void permutari_recursiv(int* x, int n, int k)
{
    if (k <= n)
    {
        for (int i = 1; i <= n; i++)
        {
            x[k] = i;
            int sol = valid_solution(x, k);
            print_solution(x, k);
            if (sol && k == n)
            {
                printf(" - solution");
            }
            printf("\n");
            if (sol)
            {
                permutari_recursiv(x, n, k + 1);
            }
        }
    }
}

int main()
{
    printf("Varianta iterativa:\n");
    permutari_iterativ(3);

    printf("\n_________________________________________________\n\n");

    int* rec = (int*)calloc(4, sizeof(int));
    printf("Varianta recursiva:\n");
    permutari_recursiv(rec,3,1);

}
