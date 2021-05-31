#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateQuestion(int);
char *correct_responses[4] = {"Very good!", "Excellent!", "Nice work!", "Keep up the good work!"};
char *incorrect_responses[4] = {"No. Please try again.", "Wrong. Try once more.", "Don’t give up.", "No. Keep trying."};

int main()
{
    srand(time(NULL));
    
    int level;

    printf("Choose your level:");
    scanf("%d", &level);

    while(level < 1)
    {
        printf("Please choose another level:");
        scanf("%d", &level);
    }

    int *array = generateQuestion(level);
    int ans, response;

    while (1)
    {
        response = rand() % 4 + 1;

        printf("How much is %d times %d?\n", array[0], array[1]);
        if (scanf("%d", &ans) == EOF)
            break;

        if (ans != array[0] * array[1])
        {
            printf("%s\n\n", incorrect_responses[response - 1]);
            continue;
        }

        printf("%s\n\n", correct_responses[response - 1]);

        array = generateQuestion(level);
    }
}

int *generateQuestion(int level)
{
    static int array[2];
    int upper = 1, lower = 1;
    int i;

    for(i = 1; i < level; i++)
    {
        upper *= 10;
        lower *= 10;
    }

    upper = upper * 10;
    if(lower = 1)
        lower = 0;

    array[0] = rand() % (upper - lower) + lower;
    array[1] = rand() % (upper - lower) + lower;

    return array;
}