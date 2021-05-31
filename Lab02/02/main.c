#include <stdio.h>

int main()
{
    int num, sum = 0;

    printf("Please enter a five-digit number:");
    scanf("%d", &num);

    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    printf("The sum of the digits is %d.\n", sum);
}