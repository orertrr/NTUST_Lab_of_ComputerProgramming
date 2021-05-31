#include <stdio.h>
#include <math.h>

int main()
{
    double pi;

    for (int i = 10000; i <= 100000; i += 10000)
    {
        pi = 0;

        for (int j = 1; j <= i; j++)
        {
            pi += 4 * (pow(-1, j + 1) / (2 * j - 1));
        }

        printf("i = %-6d pi = %f\n", i, pi);
    }
}