#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateQuestion();

int main()
{
    srand(time(NULL));

    int *array = generateQuestion();
    int ans;

    while (1)
    {
        printf("How much is %d times %d?\n", array[0], array[1]);
        if(scanf("%d", &ans) == EOF)
            break;

        if (ans != array[0] * array[1])
        {
            printf("No, Please try again.\n\n");
            continue;
        }

        printf("Very good!\n\n");

        array = generateQuestion();
    }
}

int *generateQuestion()
{
    static int array[2];

    array[0] = rand() % 10;
    array[1] = rand() % 10;

    return array;
}