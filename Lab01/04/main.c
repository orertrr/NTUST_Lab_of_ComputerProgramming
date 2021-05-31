#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Please enter two integers:");
    scanf("%d %d", &num1, &num2);

    printf("The first is %sa multiple of the second", num1 % num2 == 0 ? "" : "NOT ");

    return 0;
}