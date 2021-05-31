#include <stdio.h>
#include <stdlib.h>

void stringReverse(char *str);

int main()
{
    char str[200];

    printf("Enter a string to print the string backward:\n");
    gets(str);

    printf("The string backward is:\n");
    stringReverse(str);
    printf("\n");

    system("pause");
}

void stringReverse(char *str)
{
    if(*(str) == '\0')
        return;
    
    stringReverse(str + 1);
    printf("%c", *(str));
}