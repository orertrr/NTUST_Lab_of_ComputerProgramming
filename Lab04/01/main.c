#include <stdio.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 10; j > i; j--)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%s", " ");
        }

        for (int j = 10; j > i; j--)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 10; j > i + 1; j--)
        {
            printf("%s", " ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("%s", "*");
        }
        printf("\n");
    }
    printf("\n");
}