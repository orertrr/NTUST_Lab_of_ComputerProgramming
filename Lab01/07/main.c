#include <stdio.h>

int main ()
{
    float amount_water, init_temp, final_temp;

    printf("Enter the amount of water in kilograms:");
    scanf("%f", &amount_water);

    printf("Enter the initial temperature:");
    scanf("%f", &init_temp);

    printf("Enter the fianl temperature:");
    scanf("%f", &final_temp);

    printf("The energy needed is %.1f", amount_water * (final_temp - init_temp) * 4184);

    return 0;
} 