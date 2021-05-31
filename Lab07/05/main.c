#include <stdio.h>

unsigned long long fibonacci(int);

int main()
{
    unsigned long long max;
    
    for (size_t i = 1;; i++)
    {
        unsigned long long temp = fibonacci(i);

        if(temp >= 0)
            max = temp;
        else if(temp < 0 || temp < max)
            break;
    }
    
    printf("The largest Fibonacci number is %llu", max);
}

unsigned long long fibonacci(int n)
{
    unsigned long long n_1, n_2, n_0;

    for (size_t i = 0; i < n; i++)
    {
        if (i == 0)
        {
            n_0 = 0;
            n_2 = 0;
        }

        else if (i == 1)
        {
            n_0 = 1;
            n_1 = 1;
        }
        else
        {
            n_0 = n_1 + n_2;
            n_2 = n_1;
            n_1 = n_0;
        }
    }

    return n_0;
}