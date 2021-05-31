#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateQuestion();
int get_type(int);
char *correct_responses[4] = {"Very good!", "Excellent!", "Nice work!", "Keep up the good work!"};
char *incorrect_responses[4] = {"No. Please try again.", "Wrong. Try once more.", "Don’t give up.", "No. Keep trying."};
char *question[3] = {"How much is %d add %d?\n", "How much is %d sub %d?\n", "How much is %d times %d?\n"};

int main()
{
    srand(time(NULL));

    int *array = generateQuestion();
    int ans, response;
    int option, type;

    printf("Enter the option:");
    scanf("%d", &option);

    while (option > 4 || option < 1)
    {
        printf("Please choose another option.\n");
        scanf("%d", &option);
    }

    type = get_type(option);

    while (1)
    {
        response = rand() % 4 + 1;

        printf(question[type - 1], array[0], array[1]);
        if (scanf("%d", &ans) == EOF)
            break;

        switch (type)
        {
        case 1:
            if (ans != array[0] + array[1])
            {
                printf("%s\n\n", incorrect_responses[response - 1]);
                continue;
            }
            break;

        case 2:
            if (ans != array[0] - array[1])
            {
                printf("%s\n\n", incorrect_responses[response - 1]);
                continue;
            }
            break;

        case 3:
            if (ans != array[0] * array[1])
            {
                printf("%s\n\n", incorrect_responses[response - 1]);
                continue;
            }
            break;
        }

        printf("%s\n\n", correct_responses[response - 1]);

        array = generateQuestion();
        type = get_type(option);
    }
}

int *generateQuestion()
{
    static int array[2];

    array[0] = rand() % 10;
    array[1] = rand() % 10;

    return array;
}

int get_type(int option)
{
    int type;

    if (option == 4)
        type = rand() % 3 + 1;
    else
    {
        type = option;
    }

    return type;
}