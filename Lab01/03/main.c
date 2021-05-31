#include <stdio.h>

int main()
{
    int num;

    printf("Please enter a integer:");
    scanf("%d", &num);

    printf("The integer is %s", num % 2 == 0 ? "EVEN" : "ODD");

    return 0;
}