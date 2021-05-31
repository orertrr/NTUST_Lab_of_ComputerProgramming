#include <stdio.h>
#include <math.h>

int main()
{
    char data[5], temp;

    printf("Enter the data:");
    scanf("%s", data);

    temp = data[0];
    data[0] = data[2];
    data[2] = temp;

    temp = data[1];
    data[1] = data[3];
    data[3] = temp;

    for (int i = 0; i < 4; i++)
    {
        data[i] = data[i] - 7;
        if(data[i] < '0')
            data[i] += 10;
    }

    printf("The original integer is %s\n", data);
}