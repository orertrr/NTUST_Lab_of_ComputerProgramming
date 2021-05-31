#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//0 for tail
//1 for head
int toss_coin()
{
    return rand() % 2;
}

int main()
{
    int tail = 0, head = 0;

    srand(time(NULL));

    for (int i = 0; i < 1000; i++)
    {
        if (toss_coin())
            head++;
        else
        {
            tail++;
        }
    }

    printf("%d heads, %d tails", head, tail);
}