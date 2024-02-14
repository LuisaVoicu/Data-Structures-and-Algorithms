#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int suma(int* a,int*s, int l)
{
    int sm = 0;
    for (int i = 1; i <= l; i++)
    {
       // printf("d %d\n", s[i] - 1);
        sm += a[s[i]-1];
    }
    return sm;
}

void afiseaza_sol(int* a,int*s, int l)
{
    for(int i = 1; i <=l;i++)
    {
        printf("%d ", a[s[i]-1]);
    }
    printf("\n");
}
void backtracking(int* a, int* sol, int l, int s, int n, int* minT)
{
    if ( suma(a,sol,l-1) == s)
    {
        afiseaza_sol(a,sol, l-1);
        *minT = l;
        
    }

    for (int i = sol[l - 1]+1; i <= n; i++) // la brute force porneam mereu de la i = 1;
    {
        
        sol[l] = i;
        // branch and bound -> pt numere pozitive puteam sa pun si conditia de depasire a sumei
        if(l+1 <= *minT)
        backtracking(a, sol, l + 1, s, n, minT);
        
    }
}
int main()
{
    int n = 6;
    int a[] = { 1,-3,5,-7,2,6 };
    int s = 6;
   // printf("%d\n", a[5]);
    int* sol = (int*)calloc(n+1, sizeof(int));
    //sol[0] = -1;
    int minT = n;
    backtracking(a, sol, 1, s, n,&minT);
}