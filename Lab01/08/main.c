#include <stdio.h>

int main()
{
    int num1, num2, num3;
    int max = 0, min = __INT32_MAX__;

    printf("Enter three different integers:");
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("Sum is %d\n", num1 + num2 + num3);
    printf("Average is %d\n", (num1 + num2 + num3) / 3);
    printf("Product is %d\n", num1 * num2 * num3);
    
    if(num1 < min)
        min = num1;
    if(num2 < min)
        min = num2;
    if(num3 < min)
        min = num3;
    printf("Smallest is %d\n", min);

    if(num1 > max)
        max = num1;
    if(num2 > max)
        max = num2;
    if(num3 > max)
        max = num3;
    printf("Largest is %d\n", max);
    
}