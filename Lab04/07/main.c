#include <stdio.h>
#include <math.h>

int main()
{
    int num, factor;

    for (num = 2; num < 1000; num++)
    {
        for (factor = 2; factor <= sqrt(num); factor++)
        {
            if (num % factor == 0)
                break;
        }

        if (factor > sqrt(num))
            printf("%d\n", num);
    }
}