#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_sum_table(int table[][6]);
float get_theoretical(int sum);

int main()
{
    printf("\n");

    int dice1, dice2;

    int table[6][6] = {0};
    int dice_table[13] = {0};
    float rate_table[13] = {0};

    srand(time(NULL));

    for (size_t i = 0; i < 36000; i++)
    {
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;

        int sum = dice1 + dice2;

        dice_table[sum]++;
        table[dice1 - 1][dice2 - 1]++;
    }

    print_sum_table(table);

    for (size_t i = 2; i < 13; i++)
    {
        rate_table[i] = ((float)dice_table[i] / 36000) * 100;
    }
    
    for (size_t i = 2; i < 13; i++)
    {
        printf("The theoretical value is %5.3f, the actual valeu is %5.3f\n", get_theoretical(i) * 100, rate_table[i]);
    }
    
    system("pause");
}

void print_sum_table(int table[][6])
{
    //Print Columns
    for (size_t i = 0; i < 6; i++)
    {
        printf("%5d", i + 1);
    }
    printf("\n");

    //Print Rows
    for (size_t i = 0; i < 6; i++)
    {
        printf("%d   ", i + 1);

        for (size_t j = 0; j < 6; j++)
        {
            printf("%-5d", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

float get_theoretical(int sum)
{
    float count = 0;

    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 6; j++)
        {
            if(i + j + 2 == sum)
                count++;
        }
        
    }
    
    return count / 36;
}