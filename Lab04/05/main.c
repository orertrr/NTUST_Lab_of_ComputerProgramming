#include <stdio.h>

int main()
{
    int num;

    printf("Enter the integer(10 digits):");
    scanf("%d", &num);

    while (num != 0)
    {
        printf("%d\n", num % 10);
        num /= 10;
    }
}