#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testPalindrome(char *str, int left, int right);

int main()
{
    char str[200];

    printf("Enter a string to determine whether the string is a palindrome:\n\n");
    gets(str);

    printf("\n");

    if(testPalindrome(str, 0, strlen(str) - 1))
    {
        printf("This string is a palindrome.\n");
    }
    else
    {
        printf("This string is not a palindrome.\n");
    }
    
    system("pause");
}

int testPalindrome(char *str, int left, int right)
{
    if(!(str[left] >= 'a' && str[left] <= 'z') && !(str[left] >= 'A' && str[left] <= 'Z'))
        left++;
    if(!(str[right] >= 'a' && str[right] <= 'z') && !(str[right] >= 'A' && str[right] <= 'Z'))
        right--;

    if(left > right)
        return 1;
    
    if(str[left] != str[right])
        return 0;
    
    return testPalindrome(str, left + 1, right - 1);
}