#include <stdio.h>

int getPentagonalNumber(int);

int main()
{
    int counter = 1;

    while (counter <= 100)
    {
        printf("%7d", getPentagonalNumber(counter));

        if(counter %10 == 0)
            puts("");

        counter++;
    }
    
}

int getPentagonalNumber(int num)
{
    return num * (3 * num - 1) / 2;
}