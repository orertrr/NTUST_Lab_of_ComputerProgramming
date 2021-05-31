#include <stdio.h>

long c(long, long);

int main()
{
    long n, p;

    printf("Enter n and p:");
    scanf("%d %d", &n, &p);

    printf("C(n, p) is %d.\n", c(n, p));
}

long c(long n, long p)
{
    if(n < p)
        return 0;

    if(p == 0 || p == n)
        return 1;
    else
    {
        return c(n-1, p) + c(n-1, p-1);
    }
    
}