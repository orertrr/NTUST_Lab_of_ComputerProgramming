#include <stdio.h>

int main()
{
    int max = 0, count = 1, input;

    printf("Enter numbers:");
    while(scanf("%d", &input))
    {
        if(input > max)
        {
            max = input;
            count = 1;
        }
        else if(input == max)
        {
            count++;
        }
    }

    printf("The largest number is %d\n", max);
    printf("The occurrence count of the largest number is %d\n", count);
}