#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>






void print_solution(int* arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void combinari_rec(int* x, int n, int k, int index)
{

    if (index <= k) {
        

        for (int i = x[index-1] + 1; i <= n; i++)
        {

            x[index] = i;
            
            if (index == k)
            {
                print_solution(x, k);
            }
            combinari_rec(x, n, k, index + 1);
        }
        
    }

}

int valid_solution(int* x, int k)
{

    for (int i = 1; i < k; i++)
        if (x[i+1] <= x[i])
        {
            return 0;
        }
    return 1;
}


void combinari_iterativ(int n, int k)
{
    int* x = (int*)calloc(n, sizeof(int));
    int index = 1;
    int sol;
    int ok;
    while (index > 0)
    {
        sol = 0;
        ok = 1;
        do
        {
           
            x[index]++;
            if (x[index] > n)
            {
                ok = 0;
            }
            else
            {
                sol = valid_solution(x, index);
                if (sol && k == index)
                {
                    print_solution(x, k);
                }
            }
        } while (ok && !sol);
        if (!ok)
        {
            index--;
        }
        else
        {
            index++;
            x[index] = 0;
        }
    }
}
int main()
{
    int k = 4;
    int n = 5;
    int* arr = (int*)calloc(k, sizeof(int));

    printf("Solutie recursiva:\n");
    combinari_rec(arr, n, k, 1);

    printf("\n_____________________________________________________\n\n");

    printf("Solutie iterativa:\n");
    combinari_iterativ(n, k);
}