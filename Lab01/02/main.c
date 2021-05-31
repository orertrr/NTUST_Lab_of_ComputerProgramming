#include <stdio.h>

int main()
{
    int seconds;

    printf("Please enter the total time elapsed in seconds:");
    scanf("%d", &seconds);

    printf("The time(hh:mm:ss) is %02d:%02d:%02d", seconds / 3600, (seconds / 60) % 60, seconds % 60);
    
    return 0;
}