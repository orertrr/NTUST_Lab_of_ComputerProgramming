#include <stdio.h>
#include <stdlib.h>

/*
pen = 0 -> pen up
pen = 1 -> pen down

direction = 0 up
direction = 1 right
direction = 2 down
direction = 3 right
*/

void move(char map[][50], int direction, int *x, int *y);
int find_char(const char *str, char key);

int main()
{
    char map[50][50] = {0};
    int x = 0, y = 0;
    int pen = 0, direction = 1;
    char command[10];

    printf("Enter your command:");
    fflush(stdin);
    gets(command);

    int main_cmd = atoi(command);
    int second_cmd = atoi(command + find_char(command, ',') + 1);

    while (main_cmd != 9)
    {
        switch (main_cmd)
        {
        case 1:
            pen = 0;
            break;

        case 2:
            pen = 1;

            map[y][x] = '*';
            break;

        case 3:
            direction += 1;

            if (direction == 4)
                direction = 0;
            break;

        case 4:
            direction -= 1;

            if (direction == -1)
                direction = 3;
            break;

        case 5:
        {
            int steps = second_cmd;

            size_t i;
            for (i = 0; i < steps; i++)
            {
                move(map, direction, &x, &y);

                if (pen)
                    map[y][x] = '*';
            }

            break;
        }

        case 6:
        {
            size_t i;
            for (i = 0; i < 50; i++)
            {
                size_t j;
                for (j = 0; j < 50; j++)
                {
                    printf("%c", map[i][j]);
                }
                printf("\n");
            }

            break;
        }

        default:
            printf("The command is not exist.\n");
            break;
        }

        printf("Enter your command:");
        fflush(stdin);
        gets(command);

        main_cmd = atoi(command);
        second_cmd = atoi(command + find_char(command, ',') + 1);
    }

    system("pause");
}

void move(char map[][50], int direction, int *x, int *y)
{
    switch (direction)
    {
    case 0:
        if (*y > 0)
            *y -= 1;
        break;

    case 1:
        if (*x < 49)
            *x += 1;
        break;

    case 2:
        if (*y < 49)
            *y += 1;
        break;

    case 3:
        if (*x > 0)
            *x -= 1;
        break;

    default:
        break;
    }
}

int find_char(const char *str, char key)
{
    size_t i;
    for (i = 0;; i++)
    {
        if (*(str + i) == key)
            return i;

        if (*(str + i) == '\0')
            break;
    }

    return -1;
}
