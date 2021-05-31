#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int array[5][5];

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            array[i][j] = rand() % 2;
        }
    }

    printf("The 5-by-5 matrix is:\n\n");
    
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            printf("%d ", array[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    //Rows
    int count_row, count_max = 0, row_max;

    for (size_t i = 0; i < 5; i++)
    {
        count_row = 0;

        for (size_t j = 0; j < 5; j++)
        {
            if(array[i][j] == 1)
                count_row++;
        }

        if(count_row > count_max)
        {
            count_max = count_row;
            row_max = i;
        }
    }
    
    //Columns
    int count_column, column_max;
    count_max = 0;

    for (size_t i = 0; i < 5; i++)
    {
        count_column = 0;

        for (size_t j = 0; j < 5; j++)
        {
            if(array[j][i] == 1)
                count_column++;
        }

        if(count_column > count_max)
        {
            count_max = count_column;
            column_max = i;
        }
    }

    printf("The most 1s row is %d.\n", row_max);
    printf("The most 1s column is %d.\n", column_max);
}