#include <stdio.h>
#include <string.h>

int main()
{
    char num[6];

    printf("Please enter a five-digit integer:");
    scanf("%s", num);

    for(int i = 0, j = strlen(num) - 1; i < strlen(num) / 2; i++, j--)
    {
        if(num[i] != num[j])
        {
            printf("The integer is not a palindrome.\n");
            return 0;
        }
    }

    printf("The integer is a palindrome.\n");
}