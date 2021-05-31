#include <stdio.h>

int main()
{
    float Retail_price[5] = {2.98, 4.50, 9.98, 4.49, 6.87}, total = 0.0;
    int Quantity_sold[5] = {0, 0, 0, 0, 0};
    int product_num, br = 0;

    while (br == 0)
    {
        printf("Enter the product number(-1 to exit):");
        scanf("%d", &product_num);

        if (product_num == -1)
            break;

        for (int i = 0; i < 7; i++)
        {
            int input;
            scanf("%d", &input);
            switch (product_num)
            {
            case 1:
                Quantity_sold[0] += input;
                break;

            case 2:
                Quantity_sold[1] += input;
                break;

            case 3:
                Quantity_sold[2] += input;
                break;

            case 4:
                Quantity_sold[3] += input;
                break;

            case 5:
                Quantity_sold[4] += input;
                break;
            }
        }
    }

    printf("Product number | Total\n");
    for (int i = 0; i < 5; i++)
    {
        total += Retail_price[i] * Quantity_sold[i];
        printf("%-14d   $%.2f\n", i + 1, Retail_price[i] * Quantity_sold[i]);
    }

    printf("%17s$%.1f", " ", total);
}