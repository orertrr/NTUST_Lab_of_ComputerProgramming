#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[1000], key[100];

    printf("Enter a line of text and a search key:\n");
    gets(text);
    scanf("%s", key);

    char *searchPtr;

    searchPtr = strstr(text, key);

    while(searchPtr != NULL)
    {
        printf("%s\n", searchPtr);
        searchPtr = strstr(searchPtr + 1, key);
    }

    system("pause");
}