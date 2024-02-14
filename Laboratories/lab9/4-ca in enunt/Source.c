#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void print_subs(int* sol, int* a, int l, int start)
{
    printf("\n%d", a[sol[1] - 1]);
     
    for (int i = 2; i <= l; i++)
    {
        if (i % 2 == 1)
        {
            if (start == 0)
                printf(" + ");
            else printf(" - ");
        }
        else
        {
            if (start == 0)
                printf(" - ");
            else printf(" + ");
        }
        printf("%d", a[sol[i] - 1]);
    }

    printf("\n.................\n");
}


int suma_subs(int* sol, int* a, int l, int sum)
{
    int s1 = a[sol[1]-1], s2 = a[sol[1]-1];
   // printf("ss:\n");
    for (int i = 2; i <= l; i++)
    {
       // printf("%d ", a[sol[i] - 1]);
        if (i % 2 == 1)
        {
            s1 += a[sol[i] - 1];
            s2 -= a[sol[i] - 1];
        } else 
        {
            s1 -= a[sol[i] - 1];
            s2 += a[sol[i] - 1];
        }
    }
   // printf("%d sum\n", sum);
    if (s1 == sum)
    {
        print_subs(sol, a, l, 0);
    }
    if (s2 == sum)
    {
        print_subs(sol, a, l, 1);
    }
    return 0;
}


void backtr_subm(int* sol, int l, int* a, int n, int s)
{
    if (l < n)
    {
        if (l && suma_subs(sol, a, l - 1, s))
        {
            //--
        }

        for (int i = sol[l - 1] + 1; i <= n; i++)
        {
            sol[l] = i;

            backtr_subm(sol, l + 1, a, n, s);
        }
    }
}

int main()
{
    int a[] = {1,3,5,7,2,6};
    int n = 6;
    int s = 0;
    int* sol = (int*)calloc(n + 1, sizeof(int));
    sol[0] = 0;
    backtr_subm(sol, 1, a, n, s);

}