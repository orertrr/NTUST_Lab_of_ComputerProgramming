#include <stdio.h>

int main()
{
    float weight, height, BMI;

    printf("Please enter your height and weight:");
    scanf("%f %f", &height, &weight);

    BMI = weight / (height * height);

    printf("Your BMI is %.1f\n.", BMI);

    printf("------------------------------------\n");

    printf("BMI VALUES\n");
    printf("Underweight: less than 18.5\n");
    printf("Normal:      between 18.5 and 24.9\n");
    printf("Overweight:  between 25 and 29.9\n");
    printf("Obese:       30 or greater\n");
}