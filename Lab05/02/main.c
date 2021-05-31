#include <stdio.h>

int main()
{
    int n, factor = 2;

    printf("Enter a integer to find its factors:");
    scanf("%d", &n);

    while (n > 1)
    {
        if(n%factor == 0)
        {
            printf("%d ", factor);
            n /= factor;
        }
        else
        {
            factor++;
        }
    }
}