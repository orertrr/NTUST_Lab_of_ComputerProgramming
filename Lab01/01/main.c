#include <stdio.h>

int main()
{
    int num1, num2;

    printf("Please enter two numbers:");
    scanf("%d %d", &num1, &num2);

    printf("The sum is %d\n", num1 + num2);
    printf("The product is %d\n", num1 * num2);
    printf("The difference is %d\n", num1 - num2);
    printf("The quotient is %d\n", num1 / num2);
    printf("The remainder is %d\n", num1 % num2);

    return 0;
}