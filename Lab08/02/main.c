#include <stdio.h>
#include <math.h>

int isPrime(int);

int main()
{
    int n;

    printf("Enter a integer to check whether the number is a prime:");
    scanf("%d", &n);

    if(isPrime(n))
    {
        printf("The integer %d is prime.\n", n);
    }
    else
    {
        printf("The integer %d is not prime.\n", n);
    }
    
}

int isPrime(int n)
{
    static int factor = 2;

    if(factor > sqrt(n))
        return 1;
    else if(n % factor == 0)
    {
        return 0;
    }
    else
    {
        factor++;
        return isPrime(n);
    }
    
}