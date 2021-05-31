#include <stdio.h>

int main()
{
    int num;

    printf("Enter the number of lines:");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        for (int j = num - i; j > 1; j--)
            printf("%d ", j);

        printf("%d ", 1);

        for (int j = 2; j <= num - i; j++)
            printf("%d ", j);

        printf("\n");
    }
}