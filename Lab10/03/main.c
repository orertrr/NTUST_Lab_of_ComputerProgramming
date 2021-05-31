#include <stdio.h>
#include <stdlib.h>

char map[3][3] = {0};

void print_map();
int result(int x, int y);

int main()
{
    for (size_t i = 0; i < 9; i++)
    {
        print_map();

        int x, y;

        if (i % 2 == 0)
        {
            printf("Enter a row (0, 1, or 2) for player X:");
            scanf("%d", &y);
            printf("Enter a column (0, 1, or 2) for player X:");
            scanf("%d", &x);

            while (map[y][x] != 0)
            {
                printf("This cell has been filled.\n");
                printf("Please another cell.\n\n");

                printf("Enter a row (0, 1, or 2) for player X:");
                scanf("%d", &y);
                printf("Enter a column (0, 1, or 2) for player X:");
                scanf("%d", &x);
            }

            map[y][x] = 'X';
        }
        else
        {
            printf("Enter a row (0, 1, or 2) for player O:");
            scanf("%d", &y);
            printf("Enter a column (0, 1, or 2) for player O:");
            scanf("%d", &x);

            while (map[y][x] != 0)
            {
                printf("This cell has been filled.\n");
                printf("Please another cell.\n\n");
                
                printf("Enter a row (0, 1, or 2) for player O:");
                scanf("%d", &y);
                printf("Enter a column (0, 1, or 2) for player O:");
                scanf("%d", &x);
            }

            map[y][x] = 'O';
        }

        int res = result(x, y);

        if (res == 1)
        {
            printf("X Player won.\n");
            system("pause");
            return 0;
        }
        else if (res == 2)
        {
            printf("O Player won.\n");
            system("pause");
            return 0;
        }

        printf("Continue.\n");

        system("cls");
    }

    printf("Draw.\n");
    system("pause");
}

void print_map()
{
    printf("-------\n");
    for (size_t i = 0; i < 3; i++)
    {
        printf("|");
        for (size_t j = 0; j < 3; j++)
        {
            printf("%c|", map[i][j]);
        }
        printf("\n");
        printf("-------\n");
    }
}

//1 X win
//2 O win
//0 No result
int result(int x, int y)
{
    //vertical
    for (size_t i = 0; i < 3; i++)
    {
        if (map[i][x] != map[y][x])
            break;

        if (i == 2)
        {
            if (map[y][x] == 'X')
                return 1;
            else
            {
                return 2;
            }
        }
    }

    //horizontal
    for (size_t i = 0; i < 3; i++)
    {
        if (map[y][i] != map[y][x])
            break;

        if (i == 2)
        {
            if (map[y][x] == 'X')
                return 1;
            else
            {
                return 2;
            }
        }
    }

    //diagonal
    if (x == 1 && y != 1)
        return 0;

    int temp_x = x;
    int temp_y = y;

    //BackSlash
    if ((x == 0 && y == 0) || (x == 1 && y == 1) || (x == 2 && y == 2))
    {
        for (size_t i = 0; i < 2; i++)
        {
            temp_x = (temp_x + 1) % 3;
            temp_y = (temp_y + 1) % 3;

            if (map[temp_y][temp_x] != map[y][x])
                break;

            if (i == 1)
            {
                if (map[y][x] == 'X')
                    return 1;
                else
                {
                    return 2;
                }
            }
        }

        return 0;
    }

    //Slash
    for (size_t i = 0; i < 2; i++)
    {
        temp_x--;
        temp_y--;

        if (temp_x == -1)
            temp_x = 2;

        if (temp_y == -1)
            temp_y = 2;

        if (map[temp_y][temp_x] != map[y][x])
            break;

        if (i == 1)
        {
            if (map[y][x] == 'X')
                return 1;
            else
            {
                return 2;
            }
        }
    }
}