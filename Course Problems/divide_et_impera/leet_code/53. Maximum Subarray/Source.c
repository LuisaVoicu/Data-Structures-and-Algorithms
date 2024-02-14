#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NINF -1000


int maxi(int a, int b)
{
    if (a > b)return a;
    return b;
}

int maxim(int a, int b, int c)
{
    return maxi(maxi(a, b), c);
}

int sum_crossing(int* num, int left, int mid, int right)
{
    int suml = 0;
    int sumr = 0;
    int max_suml = NINF;
    int max_sumr = NINF;
    for (int i = mid; i >= left; i--)
    {
        suml += num[i];
        if (suml > max_suml)
            max_suml = suml;
    }
    //----> sum max <---- <= asa se apropie
    for (int i = mid + 1; i <= right; i++)
    {
        sumr += num[i];
        if (sumr > max_sumr)
            max_sumr = sumr;
    }
    return maxim(max_suml, max_sumr, max_suml + max_sumr);
}


int sum_div_imp(int* num, int left, int right)
{

    if (left == right)
        return num[left];


    int mid = (left + right) / 2;
    int sum_left = sum_div_imp(num, left, mid); // poate se formeaza la stanga
    int sum_right = sum_div_imp(num, mid + 1, right); // poate se formeaza la dreapta
    int crossing_sum = sum_crossing(num, left, mid, right); // asta updateaza suma daca e cazul ; ia caruzile : max (maxs :left,sright,sleft+sright)

    int k = maxim(sum_left, sum_right, crossing_sum);
    return k;

}



int main()
{
    int nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
    int n = sizeof(nums) / sizeof(int);
    int sum = sum_div_imp(nums, 0, n - 1);
    printf("max: %d\n", sum);

}