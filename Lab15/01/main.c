#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file1, *file2;
    char filename[100];

    while(1)
    {
        printf("Enter filename1:");
        scanf("%s", filename);
        file1 = fopen(filename, "a");

        if(file1 != NULL)
            break;
    }
    
    while(1)
    {
        printf("Enter filename2:");
        scanf("%s", filename);
        file2 = fopen(filename, "r");

        if(file2 != NULL)
            break;
    }

    char content = fgetc(file2);
    while(!feof(file2))
    {
        fprintf(file1, "%c", content);
        content = fgetc(file2);
    }
}