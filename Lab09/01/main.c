#include <stdio.h>

int hasValue(int, int *);

int main()
{
    int array_a[5], array_b[5], result[5];
    int ans_count = 0;

    for (size_t i = 0; i < 5; i++)
    {
        scanf("%d", array_a + i);
    }

    for (size_t i = 0; i < 5; i++)
    {
        scanf("%d", array_b + i);
    }

    for (size_t i = 0; i < 5; i++)
    {
        if(hasValue(array_a[i], array_b) && !hasValue(array_b[i], result))
        {
            result[ans_count] = array_a[i];
            ans_count++;
        }
    }
    
    for (size_t i = 0; i < ans_count; i++)
    {
        printf("%d ", result[i]);
    }
    
}

int hasValue(int value, int *array)
{
    for (size_t i = 0; i < 5; i++)
    {
        if (value == array[i])
            return 1;
    }

    return 0;
}