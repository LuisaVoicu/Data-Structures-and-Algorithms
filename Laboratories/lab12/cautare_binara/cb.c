#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int binary_search(int* a, int l, int r, int num)
{
    if (l == r)
    {

        return l;
    }

    int mid = (l + r) / 2;
    if (num <= a[mid])
        return binary_search(a, l, mid, num);
    else
        return binary_search(a, mid + 1, r, num);
}
int main()
{
              //0,1,2,3,4,5,6,7
    int a[] = { 2,3,5,5,7,9,9,12 };
    int n = 8;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("\n");
    int k;
    k = binary_search(a, 0, n - 1 , 5);
    printf("5: %d\n", k);
        
    k = binary_search(a, 0, n - 1 , 7);
    printf("7: %d\n", k);
       
    k = binary_search(a, 0, n - 1 , 8);
    printf("8: %d\n", k);
     
    k = binary_search(a, 0, n - 1 , 4);
    printf("4: %d\n", k);

}