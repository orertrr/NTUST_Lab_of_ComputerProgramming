#include <stdio.h>

int lcm(int, int);

int main()
{
    int num1, num2;

    printf("Enter two integers to get the LCM:");
    scanf("%d %d", &num1, &num2);

    printf("The LCM is %d.\n", lcm(num1, num2));
}

int lcm(int num1, int num2)
{
    for (int i = 1;; i++)
    {
        if((num1 * i) % num2 == 0)
            return num1 * i;
    }
}