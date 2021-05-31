#include <stdio.h>
#include <string.h>

int main()
{
    int nums[10], first = 0, second = 0;

    printf("Enter 10 non-negative numbers\n");
    for (int i = 0; i < 10; i++)
        scanf("%d", &nums[i]);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10 - i; j++)
        {
            if(nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    
    printf("The largest two numbers are %d and %d\n", nums[9], nums[8]);
}