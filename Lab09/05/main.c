#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    srand(time(NULL));

    int balls, slots, slot[MAX] = {0};

    printf("Enter the number of balls to drop: ");
    scanf("%d", &balls);

    printf("Enter the number of slots in the bean machine: ");
    scanf("%d", &slots);

    printf("\n");

    float mid_location = (float)(slots - 1) / 2;

    for (size_t i = 0; i < balls; i++)
    {
        float current_location = mid_location;

        for (size_t j = 0; j < slots - 1; j++)
        {
            int direction = rand() % 2;

            if (direction == 0)
            {
                printf("L");
                current_location -= 0.5;
            }
            else
            {
                printf("R");
                current_location += 0.5;
            }
        }
        printf("\n");

        slot[(int)current_location]++;
    }

    int max_ball = slot[0];

    for (size_t i = 1; i < slots; i++)
    {
        if(max_ball < slot[i])
            max_ball = slot[i];
    }
    
    for (size_t i = max_ball; i > 0; i--)
    {
         for (size_t j = 0; j < slots; j++)
        {
            if(slot[j] >= i)
                printf("o");
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    system("pause");
}