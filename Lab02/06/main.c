#include <stdio.h>

int main()
{
    float x[3], y[3], f;

    printf("Enter the coordinate (x, y) for p0: ");
    scanf("%f %f", &x[0], &y[0]);

    printf("Enter the coordinate (x, y) for p1: ");
    scanf("%f %f", &x[1], &y[1]);

    printf("Enter the coordinate (x, y) for p2: ");
    scanf("%f %f", &x[2], &y[2]);

    f = (x[1] - x[0]) * (y[2] - y[0]) - (x[2] - x[0]) * (y[1] - y[0]);

    if (f > 0)
        printf("(%.1f, %.1f) is on the left side of the line from (%.1f, %.1f) to (%.1f, %.1f).\n", x[2], y[2], x[0], y[0], x[1], y[1]);
    else if (f == 0)
        printf("(%.1f, %.1f) is on the line from (%.1f, %.1f) to (%.1f, %.1f).\n", x[2], y[2], x[0], y[0], x[1], y[1]);
    else if (f < 0)
        printf("(%.1f, %.1f) is on the right side of the line from (%.1f, %.1f) to (%.1f, %.1f).\n", x[2], y[2], x[0], y[0], x[1], y[1]);
}