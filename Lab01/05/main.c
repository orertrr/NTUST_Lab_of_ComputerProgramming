#include <stdio.h>

int main()
{
    float speed, acceleration;

    printf("Enter speed and acceleration:");
    scanf("%f %f", &speed, &acceleration);

    printf("The minimum runway length for this airplane is %.3f meters.", (speed * speed) / (2 * acceleration));

    return 0;
}