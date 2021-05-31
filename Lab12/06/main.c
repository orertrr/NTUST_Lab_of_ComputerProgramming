#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char strs[6][30]);

int main()
{
    char strs[6][30];

    printf("Enter a list of 6 strings.\n");
    for (size_t i = 0; i < 6; i++)
    {
        scanf("%s", strs[i]);
    }

    sort(strs);
    
    printf("The result in alphabetizing order:\n");
    for (size_t i = 0; i < 6; i++)
    {
        printf("%s ", strs[i]);
    }
    printf("\n\n");
    
    system("pause");
}

void sort(char strs[6][30])
{
    for (size_t i = 0; i < 6 - 1; i++)
    {
        for (size_t j = 0; j < 6 - 1 - i; j++)
        {
            if(strcmp(strs[j], strs[j + 1]) == 1)
            {
                char temp[30];
                strcpy(temp, strs[j]);
                strcpy(strs[j], strs[j + 1]);
                strcpy(strs[j + 1], temp);
            }
        }
        
    }
    
}