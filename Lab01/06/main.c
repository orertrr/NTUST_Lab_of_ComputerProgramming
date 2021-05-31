#include <stdio.h>

int main()
{
    float distance, miles, price;

    printf("Enter the driving distance:");
    scanf("%f", &distance);

    printf("Enter miles per gallon:");
    scanf("%f", &miles);

    printf("Enter price per gallon:");
    scanf("%f", &price);

    printf("The cost of driving is $%.2f.", (distance / miles) * price);

    return 0;
}