#include <stdio.h>

int main()
{
    int sides[3];

    printf("Enter three integers of the sides of a triangle:\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &sides[i]);
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3 - i; j++)
        {
            if (sides[j] > sides[j + 1])
            {
                int temp = sides[j];
                sides[j] = sides[j + 1];
                sides[j + 1] = temp;
            }
        }

    if (sides[0] + sides[1] > sides[2])
        printf("They could represent the sides of a triangle\n");
    else
        printf("They could not represent the sides of a triangle\n");
}