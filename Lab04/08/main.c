#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

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

int main()
{
    int counter = 0;
    int ans[120];

    int num, factor;

    for (num = 2; counter < 120; num++)
    {
        for (factor = 2; factor <= sqrt(num); factor++)
        {
            if (num % factor == 0)
                break;
        }

        if (factor > sqrt(num))
        {
            char prime[10];
            itoa(num, prime, 10);

            if (isPalindromic(prime) == 1)
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