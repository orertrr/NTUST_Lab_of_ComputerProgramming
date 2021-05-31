#include <stdio.h>
#include <math.h>

int isPerfect(int);

int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        if(isPerfect(i))
        {
            printf("%d is perfect number\n", i);
            printf("its factors are:\n");
            for (int j = 1; j < i; j++)
            {
                if(i % j==0)
                    printf("%d ", j);
            }
            printf("\n");
            
        }
    }
    
    
}

int isPerfect(int num)
{
    if(num == 1)
        return 0;

    int sum = 1;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (sqrt(num) == i)
        {
            sum += i;
        }
        else if (num % i == 0)
        {
            sum += i;
            sum += num / i;
        }
    }

    if(sum == num)
        return 1;
    else
    {
        return 0;
    }
    
}