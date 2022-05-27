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
    return n * factorial_recursion(n - 1);
}

int factorial_loop(int n)
{
    int res = 1;
    while (n > 0)
    {
        res *= n;
        n--;
    }
    return res;
}

int main(int argc, char* argv[])
{
    int n;
    if(argc == 1){
        scanf("%d", &n);
    }
    else{
        char** p = NULL;
        long int temp = strtol(argv[1], p, 10);
        n = temp;
        printf("%d\n", n);
        assert(n == temp);
    }

    int fac_rec = factorial_recursion(n);
    int fac_lo = factorial_loop(n);

    assert(fac_rec == fac_lo);

    printf("Factorial of %d is\n", n);
    printf("Recursion: %d\n", fac_rec);
    printf("Loop: %d\n", fac_lo);

    return 0;
}