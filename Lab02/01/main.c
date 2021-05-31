#include <stdio.h>

int main()
{
    float rate, USD, NTD;
    int mode;

    printf("Enter the exchange rate from USD to NTD:");
    scanf("%f", &rate);

    printf("Enter 0 to convert USD to NTD and 1 vice versa:");
    scanf("%d", &mode);

    if (mode == 0)
    {
        printf("Enter the USD amount:");
        scanf("%f", &USD);

        NTD = USD * rate;

        printf("$%.1f USD is %.0f NTD.\n", USD, NTD);
    }
    else if (mode == 1)
    {
        printf("Enter the NTD amount:");
        scanf("%f", &NTD);

        USD = NTD / rate;

        printf("$%.1f NTD is %.1f USD.\n", NTD, USD);
    }
}