#include <stdio.h>

#define SIZE 100

void sort(int[][2], int);
void swap(int *, int *);

int main()
{
    int m[SIZE][2], row;

    printf("Enter the number of value-pairs: ");
    scanf("%d", &row);

    for (size_t i = 0; i < row; i++)
    {
        printf("Input value-pair: ");
        scanf("%d %d", m[i] + 0, m[i] + 1);
    }
    
    sort(m, row);

    printf("The sorted result is\n");

    printf("{"); 

    printf("{%d, %d}", m[0][0], m[0][1]);
    for (size_t i = 1; i < row; i++)
    {
        printf(", {%d, %d}", m[i][0], m[i][1]);
    }

    printf("}");

    printf("\n");
}

void sort(int m[][2], int row)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < row - i - 1; j++)
        {
            if (m[j][0] == m[j + 1][0] && m[j][1] < m[j + 1][1])
            {
                swap(m[j], m[j + 1]);
            }
            else if(m[j][0] < m[j + 1][0])
            {
                swap(m[j], m[j + 1]);
            }
        }
    }
}

void swap(int *a, int *b)
{
    int temp[2];

    temp[0] = a[0];
    temp[1] = a[1];

    a[0] = b[0];
    a[1] = b[1];

    b[0] = temp[0];
    b[1] = temp[1];
}