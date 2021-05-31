#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//------------------------------------
/*
Process :

1. read all data (m, sigma(d))
2. convert all d to 0 or 1
    if can't show "bad code"
3. Turn the barcode to the front
4. Decode
    if can't show "bad code"
5. Check c and k
    if can't show "bad c" or "bad k"
6. Show it 
*/
//------------------------------------
//define
#define BAD_C "bad C\n"
#define BAD_K "bad K\n"
#define BAD_CODE "bad code\n"
//#define FILE_NAME "testData.txt"
//------------------------------------
//custom function
void reverse(char *bin);
void swap_char(char *a, char *b);
void swap_int(int *a, int *b);
void bubble_sort(int arr[], int size);
char bits6_to_char(char *bin);
int data_to_bin(int data[], int size, char *bin);
int checkCandK(char *decodeData, int size, char *anser);
int char_to_scoore(char *character);
//------------------------------------

int main()
{
    int dataSize;
    int data[256];
    char binary[256];
    int charSize;
    char anser[100];
    int correct_char = 1;
    int case_num = 0;

    while (scanf("%d", &dataSize))
    {
        if (dataSize == 0)
            break;

        case_num++;
        //while ((fscanf(inputFile,"%d",&dataSize)) && dataSize != 0){
        //是否為有效輸入 & 判斷有沒有6個一組資料
        if (dataSize < 23 && (dataSize + 1) % 6 == 0)
        {
            printf("Case %d: ", case_num);
            printf(BAD_CODE);
        }
        else
        {
            charSize = (dataSize + 1) / 6;
            for (int i = 0; i < dataSize; i++)
            {
                //fscanf(inputFile,"%d",data+i);
                scanf("%d", data + i);
            }
            if (data_to_bin(data, dataSize, binary))
            {
                if (*(binary + 1) == '1')
                {
                    reverse(binary);
                }
                //decode to char
                for (int i = 0; i < charSize; i++)
                {
                    *(anser + i) = bits6_to_char(binary + (i * 6));
                    //some one can't decode

                    if((i == 0 && *(anser + i) != 'B') || (i == charSize - 1 && *(anser + i) != 'B'))
                    {
                        correct_char = 0;
                        break;
                    }
                    if(i > 0 && i < charSize - 1 && *(anser + i) == 'B')
                    {
                        correct_char = 0;
                        break;
                    }
                    if (*(anser + i) == 'n')
                    {
                        correct_char = 0;
                        break;
                    }
                }

                if (correct_char)
                {
                    //anser : "B...CKB", charSize : sizeof(anser)
                    if (checkCandK(anser + 1, charSize - 2, anser))
                    {
                        printf("Case %d: ", case_num);
                        printf("%s", anser);
                        printf("\n");
                    }
                    else
                    {
                        printf("Case %d: ", case_num);
                        printf("%s", anser);
                    }
                }
                else
                {
                    printf("Case %d: ", case_num);
                    printf(BAD_CODE);
                }
            }
            else
            {
                printf("Case %d: ", case_num);
                printf(BAD_CODE);
            }

            correct_char = 1;
        }

        fflush(stdin);
    }
}

void reverse(char *bin)
{
    int len = strlen(bin);

    for (size_t i = 0; i < len / 2; i++)
    {
        swap_char(bin + i, bin + (len - 1 - i));
    }
}

void swap_char(char *a, char *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void swap_int(int *a, int *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}

void bubble_sort(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap_int(arr + j, arr + j + 1);
        }
    }
}

char bits6_to_char(char *bin)
{
    bin[5] = '\0';

    if (!strcmp(bin, "00001"))
        return '0';
    else if (!strcmp(bin, "10001"))
        return '1';
    else if (!strcmp(bin, "01001"))
        return '2';
    else if (!strcmp(bin, "11000"))
        return '3';
    else if (!strcmp(bin, "00101"))
        return '4';
    else if (!strcmp(bin, "10100"))
        return '5';
    else if (!strcmp(bin, "01100"))
        return '6';
    else if (!strcmp(bin, "00011"))
        return '7';
    else if (!strcmp(bin, "10010"))
        return '8';
    else if (!strcmp(bin, "10000"))
        return '9';
    else if (!strcmp(bin, "00100"))
        return '-';
    else if (!strcmp(bin, "00110"))
        return 'B';
    else
        return 'n';
}

int char_to_scoore(char *character)
{
    switch (*character)
    {
    case '0':
        return 0;
        break;
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    case '-':
        return 10;
        break;
    default:
        return -1;
        break;
    }
}

int checkCandK(char *decodeData, int size, char *anser)
{
    int scoreC = 0;
    int scoreK = 0;
    int checkSize = size - 2;
    //check C
    for (int i = 0; i < checkSize; i++)
    {
        scoreC += ((checkSize - i - 1) % 10 + 1) * char_to_scoore(decodeData + i);
    }
    scoreC %= 11;
    //--------
    if (scoreC == char_to_scoore(decodeData + size - 2))
    {
        //check K
        checkSize++;
        for (int i = 0; i < checkSize; i++)
        {
            scoreK += ((checkSize - i - 1) % 9 + 1) * char_to_scoore(decodeData + i);
        }
        scoreK %= 11;
        //----------
        if (scoreK == char_to_scoore(decodeData + size - 1))
        {
            *(decodeData + size - 2) = '\0';
            *(decodeData + size - 1) = '\0';
            sprintf(anser, "%s", decodeData);
            return 1;
        }
        else
        {
            sprintf(anser, BAD_K);
            return 0;
        }
    }
    else
    {
        sprintf(anser, BAD_C);
        return 0;
    }
}

int data_to_bin(int data[], int size, char *bin)
{
    int max = 0;
    int min = 1000;
    float boundary;
    for (int i = 0; i < size; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
        if (data[i] < min)
        {
            min = data[i];
        }
    }
    boundary = (float)(max + min) / 2;
    max = 0;
    min = 1000;
    for (int i = 0; i < size; i++)
    {
        int v = 0;

        if(data[i] < boundary)
        {
            v = data[i] * 2;
        }
        else
        {
            v = data[i];
        }
        
        if(v > max)
            max = v;
        if(v < min)
            min = v;
    }
    if ((95 * max) > (105 * min))
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if(i % 6 == 5 && data[i] > boundary)
                return 0;

            if (data[i] < boundary)
            {
                *(bin + i) = '0';
            }
            else
            {
                *(bin + i) = '1';
            }
        }
        *(bin + size) = '\0';
        return 1;
    }
}