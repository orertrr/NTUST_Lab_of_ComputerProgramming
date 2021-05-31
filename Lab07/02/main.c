#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int play = 1, num;
    char state;

    srand(time(NULL));

    while (play)
    {
        int guess = 0;

        num = rand() % 1000 + 1;

        printf("I have a number between 1 and 100.\n");
        printf("Can you guess my number?\n");
        printf("Please type your first guess.\n");

        while (guess != num)
        {
            scanf("%d", &guess);

            if (guess > num)
                printf("Too high! Try again.\n");
            else if (guess < num)
                printf("Too low! Try again.\n");
        }

        printf("Excellent! You guessed the number.\n");

        while (1)
        {
            fflush(stdin);

            printf("Would you like to play again (y or n)?\n");
            state = getchar();

            if (state == 'n')
            {
                play = 0;
                break;
            }
            else if (state == 'y')
                break;
        }
    }
}