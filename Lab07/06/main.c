#include <stdio.h>
#include <math.h>

double square_root(double);

int main()
{
    double x;

    printf("Enter a positive number:");
    scanf("%lf", &x);

    printf("Square root: %.5f\n", square_root(x));
}

double square_root(double x)
{
    double new_y = 1.0, old_y = 0;

    while (fabs(new_y - old_y) >= new_y * 0.00001)
    {
        old_y = new_y;

        new_y = (new_y + x / new_y) / 2;
    }

    return new_y;
}