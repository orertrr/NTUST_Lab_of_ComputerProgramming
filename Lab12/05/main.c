#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[200], *token[200];
    int tokens = 0;

    printf("Enter a line of text:\n\n");
    gets(str);

    printf("\n");

    char *ptr = strtok(str, " ");

    for (size_t i = 0; i < 200, ptr != NULL; i++)
    {
        tokens++;
        token[i] = ptr;
        ptr = strtok(NULL, " ");
    }
    
    for (int i = tokens - 1; i >= 0; i--)
    {
        printf("%s ", token[i]);
    }
    printf("\n");
    
    system("pause");
}
