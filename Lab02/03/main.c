#include <stdio.h>

int main()
{
    float x, y, f;

    printf("Enter a point's x- and y-coordinates:");
    scanf("%f %f", &x, &y);

    //100x + 200y = 20000

    if (x < 0 || y < 0)
    {
        printf("The point is not in the triangle.\n");
        return 0;
    }

    f = 100 * x + 200 * y - 20000;

    if (f <= 0)
        printf("The point is in the triangle.\n");
    else
        printf("The point is in not the triangle.\n");
}