#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int count = 0;
    char str[200];

    printf("Enter text:\n\n");
    scanf("%[^\t]", str);

    char *ptr = strtok(str, " \n");

    while (ptr != NULL)
    {
        count++;
        ptr = strtok(NULL, " \n");
    }

    printf("The number of words in the string is %d.\n", count);

    system("pause");
}