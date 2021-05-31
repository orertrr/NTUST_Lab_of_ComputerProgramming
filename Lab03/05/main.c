#include <stdio.h>

int main()
{
    for (int i = 100; i < 1000; i++)
    {
        int temp = i, temp_sum = 0;

        while (temp > 0)
        {
            temp_sum += (temp % 10) * (temp % 10) * (temp % 10);
            temp /= 10;
        }

        if(temp_sum == i)
            printf("%d\n", i);
    }
}