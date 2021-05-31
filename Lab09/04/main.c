#include <stdio.h>

#define SIZE 100

int main()
{
    int matrix_a_row, matrix_a_col, matrix_b_row, matrix_b_col;
    int matrix_a[SIZE][SIZE];
    int matrix_b[SIZE][SIZE];

    printf("Enter matrix_a's row: ");
    scanf("%d", &matrix_a_row);
    printf("Enter matrix_a's column: ");
    scanf("%d", &matrix_a_col);
    printf("Enter the matrix_a:\n");
    for (size_t i = 0; i < matrix_a_row; i++)
    {
        for (size_t j = 0; j < matrix_a_col; j++)
        {
            scanf("%d", &matrix_a[i][j]);
        }
        
    }
    printf("\n");

    printf("Enter matrix_b's row: ");
    scanf("%d", &matrix_b_row);
    printf("Enter matrix_b's column: ");
    scanf("%d", &matrix_b_col);
    printf("Enter the matrix_b:\n");
    for (size_t i = 0; i < matrix_b_row; i++)
    {
        for (size_t j = 0; j < matrix_b_col; j++)
        {
            scanf("%d", &matrix_b[i][j]);
        }
        
    }
    printf("\n");

    int result_row = matrix_a_row, result_col = matrix_b_col;
    int result[SIZE][SIZE];

    for (size_t i = 0; i < result_row; i++)
    {
        for (size_t j = 0; j < result_col; j++)
        {
            result[i][j] = 0;

            for (size_t k = 0; k < matrix_a_col; k++)
            {
                result[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    
    printf("The result is\n");
    for (size_t i = 0; i < result_row; i++)
    {
        for (size_t j = 0; j < result_col; j++)
        {
            printf("%d ", result[i][j]);
        }

        printf("\n");
    }
}