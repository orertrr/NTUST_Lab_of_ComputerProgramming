#include <stdio.h>
#include <math.h>

int isPrime(int);

int main()
{
    int primes[1200], tail = 0;

    for (int i = 2; i < 1200; i++)
    {
        if (isPrime(i))
        {
            primes[tail] = i;
            tail++;

            if (i != 2 && primes[tail - 1] - primes[tail - 2] == 2)
                printf("(%d, %d)\n", primes[tail - 2], primes[tail - 1]);
        }
    }
}

//1 = Ture
//0 = False
int isPrime(int num)
{
    for (int factor = 2; factor <= sqrt(num); factor++)
    {
        if (num % factor == 0)
            return 0;
    }

    return 1;
}