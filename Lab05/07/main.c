#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int isPalindromic(char *);
int isPrime(int);
int reverse(int);

int main()
{
    int counter = 0;
    int ans[120];

    int num, factor;

    for (num = 2; counter < 120; num++)
    {
        if (isPrime(num) && isPrime(reverse(num)))
        {
            char prime[10];
            itoa(num, prime, 10);

            if (isPalindromic(prime) == 0)
            {
                ans[counter] = num;
                counter++;
            }
        }
    }

    for (int i = 0; i < 120; i++)
    {
        if (i % 10 == 0)
            printf("\n");
        printf("%d ", ans[i]);
    }
}

//1=True
//0=False
int isPalindromic(char *num)
{
    int digit = strlen(num);

    for (int i = 0, j = digit - 1; i < digit / 2; i++, j--)
    {
        if (num[i] != num[j])
            return 0;
    }
    return 1;
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

int reverse(int n)
{
    int result = 0;

    while (n > 0)
    {
        result *= 10, result += n % 10;
        n /= 10;
    }

    return result;
}