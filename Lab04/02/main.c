#include <stdio.h>

int main()
{
    int num[5];

    printf("Enter 5 numbers:\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", num + i);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < num[i]; j++)
            printf("%s", "*");

        printf("\n");
    }
}