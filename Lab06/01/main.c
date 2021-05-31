#include <stdio.h>

int is_Right_Triangle(int, int, int);

int main()
{
    int side1, side2, side3;

    printf("Enter three nonzero integers:");
    scanf("%d %d %d", &side1, &side2, &side3);

    if(is_Right_Triangle(side1,side2,side3))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    
}

int is_Right_Triangle(int a, int b, int c)
{
    if (a * a + b * b == c * c)
        return 1;

    if (c * c + b * b == a * a)
        return 1;

    if (a * a + c * c == b * b)
        return 1;

    return 0;
}