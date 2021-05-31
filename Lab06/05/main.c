#include <stdio.h>

int reverse(int);

int main()
{
    int num;

    printf("Enter a integer to reverse:");
    scanf("%d", &num);

    printf("The reversed number is %d", reverse(num));
}

int reverse(int num)
{
    int result = 0;

    while(num != 0)
    {
        result = result * 10 + num%10;

        num/=10;
    }

    return result;
}