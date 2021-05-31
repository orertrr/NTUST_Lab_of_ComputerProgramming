#include <stdio.h>

double power(double, int);

int main()
{
    double base;
    int exp;

    printf("Enter the base and the exponent:\n");
    scanf("%lf %d", &base, &exp);

    printf("The result is %.2lf", power(base, exp));
}

double power(double base, int exponent)
{
    if (exponent > 1)
        return base * power(base, exponent - 1);
    else
    {
        return base;
    }
}