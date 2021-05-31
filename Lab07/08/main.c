#include <stdio.h>
#include <math.h>

int isPrime(int);

int main()
{
    printf(" p   2^p-1\n");
    for (int i = 2; i < 32; i++)
    {
        int mersenne = (int)pow(2, i) - 1;

        if (isPrime(mersenne))
        {
            printf("%2d   %d\n", i, mersenne);
        }
    }
}

int isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }

    return 1;
}