#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int deck[4][13]);
void deal(int deck[4][13]);
void init(int deck[4][13]);
void swap(int *a, int *b);

int main()
{
    int deck[4][13] = {0};
    int again = 1;

    srand(time(NULL));

    init(deck);

    while (again)
    {
        printf("\n");
        shuffle(deck);

        deal(deck);

        printf("\nShuffle again?(0 is No, 1 is Yes):");
        scanf("%d", &again);
    }

    system("pause");
}

void shuffle(int deck[4][13])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 13; j++)
        {
            int temp_row = rand() % 4;
            int temp_col = rand() % 13;

            swap(&deck[i][j], &deck[temp_row][temp_col]);
        }
    }
}

void deal(int deck[4][13])
{
    printf("    ");
    for (size_t i = 0; i < 13; i++)
    {
        printf("%-4d", i);
    }
    printf("\n");

    for (size_t i = 0; i < 4; i++)
    {
        printf("%-4d", i);

        for (size_t j = 0; j < 13; j++)
        {
            printf("%-4d", deck[i][j]);
        }
        printf("\n");
    }
    
}

void init(int deck[4][13])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 13; j++)
        {
            deck[i][j] = 13 * i + j + 1;
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}