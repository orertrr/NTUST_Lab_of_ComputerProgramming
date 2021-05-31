#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateQuestion();

int main()
{
    srand(time(NULL));

    int *array = generateQuestion();
    int ans, response;

    while (1)
    {
        response = rand() % 4 + 1;

        printf("How much is %d times %d?\n", array[0], array[1]);
        if (scanf("%d", &ans) == EOF)
            break;

        if (ans != array[0] * array[1])
        {
            switch (response)
            {
            case 1:
                printf("No. Please try again.\n\n");
                break;

            case 2:
                printf("Wrong. Try once more.\n\n");
                break;

            case 3:
                printf("Don’t give up.\n\n");
                break;

            case 4:
                printf("No. Keep trying.\n\n");
                break;
            }

            continue;
        }

        switch (response)
        {
        case 1:
            printf("Very good!\n\n");
            break;

        case 2:
            printf("Excellent!\n\n");
            break;

        case 3:
            printf("Nice work!\n\n");
            break;

        case 4:
            printf("Keep up the good work!\n\n");
            break;
        }

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