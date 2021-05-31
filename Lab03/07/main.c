#include <stdio.h>

int main()
{
    char data[5], temp;

    printf("Enter the four-digit integer:");
    scanf("%s", data);

    for (int i = 0; i < 4; i++)
    {
        data[i] = (data[i] - '0' + 7) % 10 + '0';
    }
    
    temp = data[0];
    data[0] = data[2];
    data[2] = temp;

    temp = data[1];
    data[1] = data[3];
    data[3] = temp;

    printf("The encrypted integer is %s\n", data);
}