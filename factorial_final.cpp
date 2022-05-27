#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include <cmath>
#include <cassert>

// Goal: Implement recursion and non-recursion version of factorial

int factorial_recursion(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int temp = factorial_recursion(n - 1);
    if (n * temp / n != temp)
    {
        printf("res overflow when %d!\n", n);
        abort();
    }
    return n * temp;
}

int factorial_loop(int n)
{
    int res = 1;
    while (n > 0 && res * n / n == res)
    {
        res *= n;
        n--;
        printf("%d\n", res);
    }
    if (n != 0)
    {
        // printf("res overflow when \\frac{n!}{%d!}.\n", n);
        abort();
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    int fac_rec = factorial_recursion(n);
    int fac_lo = factorial_loop(n);

    // assert(fac_rec == fac_lo);

    printf("Factorial of %d is\n", n);
    // printf("Recursion: %d\n", fac_rec);
    printf("Loop: %d\n", fac_lo);

    return 0;
}