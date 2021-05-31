#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *generateQuestion();
char *correct_responses[4] = {"Very good!", "Excellent!", "Nice work!", "Keep up the good work!"};
char *incorrect_responses[4] = {"No. Please try again.", "Wrong. Try once more.", "Don’t give up.", "No. Keep trying."};

int main()
{
    while (1)
    {
        srand(time(NULL));

        int *array = generateQuestion();
        int ans, response, i;
        float correct = 0;

        for (i = 0; i < 10; i++)
        {
            response = rand() % 4 + 1;

            printf("How much is %d times %d?\n", array[0], array[1]);
            scanf("%d", &ans);

            if (ans != array[0] * array[1])
            {
                printf("%s\n\n", incorrect_responses[response - 1]);
                continue;
            }
            else
            {
                correct++;
            }

            printf("%s\n\n", correct_responses[response - 1]);

            array = generateQuestion();
        }

        if (correct / 10 >= 0.75)
        {
            printf("Congratulations, you are ready to go to the next level!\n\n");
        }
        else
        {
            printf("Please ask your teacher fo extra help.\n\n");
        }

		system("pause");
        system("cls");
    }
}

int *generateQuestion()
{
    static int array[2];

    array[0] = rand() % 10;
    array[1] = rand() % 10;

    return array;
}
