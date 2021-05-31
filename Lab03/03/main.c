#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    
    printf("Enter a number:");
    scanf("%d", &num);

    if(num < 2)
    {
        printf("The number is not a prime number\n");
        return 0;
    }
    else
    {
        for(int i = 2; i <= sqrt(num); i++)
        {
            if(num % i == 0)
            {
                printf("The number is not a prime number\n");
                return 0;
            }
        }
    }

    printf("The number is a prime number\n");
    
}