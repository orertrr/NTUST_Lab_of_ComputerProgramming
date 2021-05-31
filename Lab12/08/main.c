#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char *article[5] = {"the", "a", "one", "some", "any"};
char *nouns[5] = {"boy", "girl", "dog", "town", "car"};
char *verbs[5] = {"drove", "jumped", "ran", "walked", "skipped"};
char *preposition[5] = {"to", "from", "over", "under", "on"};

void upper(char *str);
void init(char *str);

int main()
{
    srand(time(NULL));
    char str[100] = {0};

    for (size_t i = 0; i < 20; i++)
    {
        init(str);
        
        upper(str);
        strcat(str, article[rand() % 5]);
        strcat(str, " ");

        strcat(str, nouns[rand() % 5]);
        strcat(str, " ");

        strcat(str, verbs[rand() % 5]);
        strcat(str, " ");

        strcat(str, preposition[rand() % 5]);
        strcat(str, " ");

        strcat(str, article[rand() % 5]);
        strcat(str, " ");

        strcat(str, nouns[rand() % 5]);
        strcat(str, ".");

        printf("%s\n", str);
    }
    
    printf("\n");
    system("pause");
}

void upper(char *str)
{
    if(str[0] >= 'a' && str[0] <= 'z')
        str[0] += ('A' - 'a');

    return;
}

void init(char *str)
{
    for (size_t i = 0; i < 100; i++)
    {
        str[i] = 0;
    }
    
}