#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int accnum;
    double balance;
} Data;

int cmp(const void *a, const void *b);

int main()
{
    FILE *tran = fopen("trans.txt", "w");
    Data record;

    printf("Enter the records(Account number, Dollar amount):\n");
    while(scanf("%d %lf", &record.accnum, &record.balance) != EOF)
    {
        fprintf(tran, "%d %lf\n", record.accnum, record.balance);
    }
    fclose(tran);

    tran = fopen("trans.txt", "r");
    FILE *oldmast = fopen("oldmast.txt", "a");

    while(fscanf(tran, "%d %lf", &record.accnum, &record.balance) != EOF)
    {
        fprintf(oldmast, "%d %lf\n", record.accnum, record.balance);
    }
    fclose(tran);
    fclose(oldmast);

    oldmast = fopen("oldmast.txt", "r");
    int lines = 0;
    char temp[100];
    
    while(fgets(temp, 100, oldmast))
    {
        lines++;
    }
    fclose(oldmast);

    oldmast = fopen("oldmast.txt", "r");
    Data *records = calloc(lines, sizeof(Data));
    for (size_t i = 0; i < lines; i++)
    {
        fscanf(oldmast, "%d %lf", &(records + i)->accnum, &(records + i)->balance);
        fgetc(oldmast);
    }
    fclose(oldmast);
    
    qsort(records, lines, sizeof(Data), cmp);

    FILE *newmast = fopen("newmast.txt", "w");
    for (size_t i = 0; i < lines; i++)
    {
        if(i != lines - 1 && (records + i)->accnum == (records + i + 1)->accnum)
        {
            (records + i + 1)->balance += (records + i)->balance;
            continue;
        }

        fprintf(newmast, "%d %lf\n", (records + i)->accnum, (records + i)->balance);
    }
    fclose(newmast);

    newmast = fopen("newmast.txt", "r");
    oldmast = fopen("oldmast.txt", "w");

    char content = fgetc(newmast);
    while(!feof(newmast))
    {
        fprintf(oldmast, "%c", content);
        content = fgetc(newmast);
    }
    fclose(newmast);
    fclose(oldmast);
}

int cmp(const void *a, const void *b)
{
    return ((Data*)a)->accnum - ((Data*)b)->accnum;
}