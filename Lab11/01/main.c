#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mazeTraverse(char maze[12][12], int *start, int *end, int x, int y, int direction, int at_start);
void mazeGenerator(char maze[12][12], int *start, int *end);
void pointGenerator(int *point);
const char maze_char[2] = {'#', '.'};

/*
direction
{
    0 -> left
    1 -> up
    2 -> right
    3 -> down
}
*/

int main()
{
    char maze[12][12] = {0};
    int start[2], end[2];
    int result;

    srand(time(NULL));

    do
    {
        mazeGenerator(maze, start, end);
        result = mazeTraverse(maze, start, end, start[1], start[0], 0, 1);
    } while (!result);


    printf("start: %2d, %2d\n", start[0], start[1]);
    printf("end: %2d, %2d\n", end[0], end[1]);
    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    system("pause");
}

int mazeTraverse(char maze[12][12], int *start, int *end, int x, int y, int direction, int at_start)
{
    for (size_t i = 0; i < 12; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            if (i == y && j == x)
                maze[i][j] = 'x';
        }
    }

    if (!at_start)
    {
        if (start[0] == y && start[1] == x)
            return 0;
        if (end[0] == y && end[1] == x)
            return 1;
    }

    switch (direction)
    {
    case 0:
    {
        if (maze[y - 1][x] == '.' || maze[y - 1][x] == 'x')
            return mazeTraverse(maze, start, end, x, y - 1, (direction + 1) % 4, 0);
        if (maze[y - 1][x] == '#' && (maze[y][x - 1] == '.' || maze[y][x - 1] == 'x'))
            return mazeTraverse(maze, start, end, x - 1, y, direction, 0);
        if (maze[y - 1][x] == '#' && maze[y][x - 1] == '#')
            return mazeTraverse(maze, start, end, x, y, (direction - 1 < 0 ? 3 : direction - 1), 0);
    }
    case 1:
    {
        if (maze[y][x + 1] == '.' || maze[y][x + 1] == 'x')
            return mazeTraverse(maze, start, end, x + 1, y, (direction + 1) % 4, 0);
        if (maze[y][x + 1] == '#' && (maze[y - 1][x] == '.' || maze[y - 1][x] == 'x'))
            return mazeTraverse(maze, start, end, x, y - 1, direction, 0);
        if (maze[y][x + 1] == '#' && maze[y - 1][x] == '#')
            return mazeTraverse(maze, start, end, x, y, (direction - 1 < 0 ? 3 : direction - 1), 0);
    }
    case 2:
    {
        if (maze[y + 1][x] == '.' || maze[y + 1][x] == 'x')
            return mazeTraverse(maze, start, end, x, y + 1, (direction + 1) % 4, 0);
        if (maze[y + 1][x] == '#' && (maze[y][x + 1] == '.' || maze[y][x + 1] == 'x'))
            return mazeTraverse(maze, start, end, x + 1, y, direction, 0);
        if (maze[y + 1][x] == '#' && maze[y][x + 1] == '#')
            return mazeTraverse(maze, start, end, x, y, (direction - 1 < 0 ? 3 : direction - 1), 0);
    }
    case 3:
    {
        if (maze[y][x - 1] == '.' || maze[y][x - 1] == 'x')
            return mazeTraverse(maze, start, end, x - 1, y, (direction + 1) % 4, 0);
        if (maze[y][x - 1] == '#' && (maze[y + 1][x] == '.' || maze[y + 1][x] == 'x'))
            return mazeTraverse(maze, start, end, x, y + 1, direction, 0);
        if (maze[y][x - 1] == '#' && maze[y + 1][x] == '#')
            return mazeTraverse(maze, start, end, x, y, (direction - 1 < 0 ? 3 : direction - 1), 0);
    }
    }
}

void mazeGenerator(char maze[12][12], int *start, int *end)
{
    pointGenerator(start);
    do
    {
        pointGenerator(end);
    } while (start[0] == end[0] && start[1] == end[1]);

    for (size_t i = 0; i < 12; i++)
    {
        if ((start[0] == i && start[1] == 0) || (end[0] == i && end[1] == 0))
            maze[i][0] = maze_char[1];
        else
        {
            maze[i][0] = maze_char[0];
        }
    }

    for (size_t i = 0; i < 12; i++)
    {
        if ((start[0] == 0 && start[1] == i) || (end[0] == 0 && end[1] == i))
            maze[0][i] = maze_char[1];
        else
        {
            maze[0][i] = maze_char[0];
        }
    }

    for (size_t i = 0; i < 12; i++)
    {
        if ((start[0] == i && start[1] == 11) || (end[0] == i && end[1] == 11))
            maze[i][11] = maze_char[1];
        else
        {
            maze[i][11] = maze_char[0];
        }
    }

    for (size_t i = 0; i < 12; i++)
    {
        if ((start[0] == 11 && start[1] == i) || (end[0] == 11 && end[1] == i))
            maze[11][i] = maze_char[1];
        else
        {
            maze[11][i] = maze_char[0];
        }
    }

    for (size_t i = 1; i < 11; i++)
    {
        for (size_t j = 1; j < 11; j++)
        {
            maze[i][j] = maze_char[rand() % 2];
        }
    }
}

//0 -> y
//1 -> x
void pointGenerator(int *point)
{
    int direction = rand() % 4;

    switch (direction)
    {
    case 0:
    {
        point[0] = rand() % 10 + 1;
        point[1] = 0;

        break;
    }

    case 1:
    {
        point[1] = rand() % 10 + 1;
        point[0] = 0;

        break;
    }

    case 2:
    {
        point[0] = rand() % 10 + 1;
        point[1] = 11;

        break;
    }

    case 3:
    {
        point[1] = rand() % 10 + 1;
        point[0] = 11;

        break;
    }
    }
}