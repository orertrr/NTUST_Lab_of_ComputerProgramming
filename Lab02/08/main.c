#include <stdio.h>
#include <math.h>

int main()
{
    float x[2], y[2], r[2], distance;

    printf("Enter circle1's center x-, y-coordinates, and radius:");
    scanf("%f %f %f", &x[0], &y[0], &r[0]);

    printf("Enter circle2's center x-, y-coordinates, and radius:");
    scanf("%f %f %f", &x[1], &y[1], &r[1]);

    distance = sqrt((x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));

    if (distance <= r[0] - r[1])
        printf("Circle2 is inside circle1.\n");
    else if (distance <= r[0] + r[1])
        printf("Circle2 is overlap circle1.\n");
    else
        printf("Circle2 dose not overlap circle1.\n");
}