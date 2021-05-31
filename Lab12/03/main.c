#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char tel[15], *area_str, phone_str[9], *first, *last;
    int area;
    long phone;

    printf("Enter the telephone:\n\n");
    scanf("%s", tel);

    area_str = strtok(tel, "()-");
    first = strtok(NULL, "()-");
    last = strtok(NULL, "()-");

    strcat(phone_str, first);
    strcat(phone_str, last);

    area = atoi(area_str);
    phone = atol(phone_str);

    printf("The area code is %02d.\n", area);
    printf("The phone number is %08d.\n", phone);

    system("pause");
}