#include <stdio.h>

#define MAX 100

int isEven(int);

int main()
{
    int num[MAX];

    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", num + i);

        if (num[i] == 0)
            break;
    }

    for (int i = 0; i < MAX; i++)
    {
        if(num[i] == 0)
            break;

        if(isEven(num[i]))
        {
            printf("%d is even\n", num[i]);
        }
        else
        {
            printf("%d is odd\n", num[i]);
        }
        
    }
}

int isEven(int num)
{
    if (num % 2 == 0)
        return 1;
    else
    {
        return 0;
    }
}