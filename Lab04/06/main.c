#include <stdio.h>
#include <math.h>

int main()
{
    double side1, side2;

    for (int i = 5; i < 500; i++)
    {
        for (side1 = 1; side1 < i; side1++)
        {
            side2 = sqrt(i * i - side1 * side1);

            if(side2 < side1)
                break;

            if(side2 == (int)side2)
            {
                printf("%-3.0f %-3.0f %-3.0d\n",side1, side2, i);
            }
        }
    }
}