#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int is_a_solution(int* values, int* x, int sum, int k)
{
    int s = 0;
    for (int i = 1; i < k; i++)
    {
        s += x[i] * values[i];
        if (s > sum)
        {
            return 0;
        }
    }
    printf("%d %d\n", s, sum);
    if (s == sum)
    {
        return 1;
    }
    return 0;
}

void print_solution(int* values, int* x, int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
       printf("%d ", values[i]*x[i]);
        sum += values[i] * x[i];
       // printf("%d ", x[i]);
    }
    printf("\n");
   printf("s %d\n",sum);
}
int count;
void find_solution_brute_force(int* values,int* x, int n, int sum, int k)
{

    
    if (k > n)
    {
        // toate cele n pozitii au cate o valoare din {0,1}
        if (sum == 0)
        {   
            count++;
            printf("Found solution %d :\n", count);
            print_solution(values, x, n);
        }
        return;
    }

    for (int i = 1; i >= 0; i--)
        {
            x[k] = i;
            find_solution_brute_force(values, x, n, sum - x[k]*values[k], k+1);
        }
}


void find_solution_backtracking(int* values, int* x, int n, int sum, int k, int* optimal_solution, int* optimal)
{

    if (k > n)
    {
        return;
    }

    if (sum == 0)
    {
        // am gasit o solutie
        count++;
        *optimal = k;
        *optimal_solution = x;
        for (int i = 1; i <= n; i++)
        {
            optimal_solution[i] = x[i];
        }
        printf("Found solution %d :\n",count);
        print_solution(values, x,n);
    }
    else if (sum > 0 && k + 1 < *optimal)
    {
        for (int i = 1; i >= 0; i--)
        {
            x[k] = i;
            find_solution_backtracking(values, x, n, sum - x[k] * values[k], k + 1, optimal_solution, optimal);
            x[k] = 0;
        }
    }

}


int main()
{
    FILE* f = fopen("file.txt", "r");
    int n, res;
    fscanf(f, "%d", &n);
    fscanf(f, "%d", &res);
    int* values = (int*)calloc(n + 1, sizeof(int));
    int* x = (int*)calloc(n + 1, sizeof(int));
    

    for (int i = 1; i <= n; i++)
    {
        fscanf(f, "%d", &values[i]);
    }

    printf("Brute force :\n\n");
    find_solution_brute_force(values,  x, n, res, 1);
    printf("\n________________________________________________\n\n");
    printf("Backtracking : \n\n");
    count = 0;
    int optimal = n + 1;
    int* opt_sol = (int*)calloc(n + 1, sizeof(int));
    find_solution_backtracking(values, x, n, res, 1, opt_sol, &optimal);

    printf("\nOptimal solution :\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", opt_sol[i] * values[i]);
    }
    printf("\n");
}