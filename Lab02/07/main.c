#include <stdio.h>

int main()
{
    char week[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    int h, q, m, j, k, y;

    printf("Enter year:");
    scanf("%d", &y);

    printf("Enter month(1-12):");
    scanf("%d", &m);

    printf("Enter the day of the month(1-31):");
    scanf("%d", &q);

    if(m <= 2)
    {
        m += 12;
        y--;
    }

    j = y / 100;
    k = y % 100;
    h = (q + (26 * (m + 1) / 10) + k + k / 4 + j / 4 + 5 * j) % 7;

    printf("Day of the week is %s.", week[h]);
}