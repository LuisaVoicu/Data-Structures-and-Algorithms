#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int search_first(int* a, int n)
{

    // caz favorabil ( poz 1/n) -> constant
    // caz defavorabil O(n)
    if (a[1] <= a[n])
    {
        return 1; 
    }
    if (a[n] <= a[n - 1])
    {
        return n;
    }
    
    for (int i = 2; i < n; i++)
    {
        if (a[i - 1] > a[i] && a[i] <= a[i + 1])
        {
            return i;
        }
    }
}


int pseudo_binary_search(int* a,int num_s, int p_left, int p_right, int n)
{
    
    //printf("%d %d ", p_left, p_right);
    if (p_left <= p_right)
    {
        int aux;
        int mid = (p_left + p_right) / 2;
        aux = mid;
        
        if (mid > n)
        {
            // se afla in prelungirea (fictiva)
            aux = mid - n;
        }
      //  printf("%d %d %d\n", mid, a[aux], num_s);
        if (num_s == a[aux])
        {
            return aux;
        }
        else if (num_s < a[aux])
        {
            return pseudo_binary_search(a, num_s, p_left, mid, n);
        }
        else if (num_s > a[aux])
        {
            return pseudo_binary_search(a, num_s, mid + 1, p_right, n);
        }
    }
   // printf("\n");
    return -1; //daca nu l-am gasit

}

int main()
{

    int a[] = {0,10,13,14,14,25,27,1,3,9};
    int n = 9;
    int pseudo_left = search_first(a, n);
    int pseudo_right = n + pseudo_left - 1; // prelungim (NU la nivel de memorie) sirul cu elementele aflate inainte de primul element

   // printf("%d\n", pseudo_left);

    int num = 3;
    int k = pseudo_binary_search(a, num, pseudo_left, pseudo_right, n);
    if (k != -1)
    {
        printf("%d gasit pe pozitia %d\n", num, k);
    }
    else
    {
        printf("%d nu a fost gasit\n", num);
    }

    printf("\n...............\n");
    num = 14;
    k = pseudo_binary_search(a, num, pseudo_left, pseudo_right, n);
    if (k != -1)
    {
        printf("%d gasit pe pozitia %d\n", num, k);
    }
    else
    {
        printf("%d nu a fost gasit\n", num);
    }

    printf("\n...............\n");
    num = 1;
    k = pseudo_binary_search(a, num, pseudo_left, pseudo_right, n);
    if (k != -1)
    {
        printf("%d gasit pe pozitia %d\n", num, k);
    }
    else
    {
        printf("%d nu a fost gasit\n", num);
    }
    
    printf("\n...............\n");
    num = 1;
    k = pseudo_binary_search(a, num, pseudo_left, pseudo_right, n);
    if (k != -1)
    {
        printf("%d gasit pe pozitia %d\n", num, k);
    }
    else
    {
        printf("%d nu a fost gasit\n", num);
    }    
    
    printf("\n...............\n");
    num = 27;
    k = pseudo_binary_search(a, num, pseudo_left, pseudo_right, n);
    if (k != -1)
    {
        printf("%d gasit pe pozitia %d\n", num, k);
    }
    else
    {
        printf("%d nu a fost gasit\n", num);
    }

}