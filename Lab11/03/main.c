#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void shuffle(int deck[4][13]);
void deal(int deck[4][13]);
void init(int deck[4][13]);
void swap(int *a, int *b);
int get_suit(int card);
int get_face(int card);
void sort_card(int *card, int size);
void test_printCards(int *card);

const char *suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *faces[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

int main()
{
    int deck[4][13] = {0};
    int again = 1;

    srand(time(NULL));

    init(deck);

    while (again)
    {
        shuffle(deck);

        deal(deck);

        printf("\nShuffle again?(0 is No, 1 is Yes):");
        scanf("%d", &again);
        printf("\n");
    }

    system("pause");
}

void shuffle(int deck[4][13])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 13; j++)
        {
            int temp_row = rand() % 4;
            int temp_col = rand() % 13;

            swap(&deck[i][j], &deck[temp_row][temp_col]);
        }
    }
}

void deal(int deck[4][13])
{
    int card[5] = {0};

    for (size_t i = 0; i < 5; i++)
    {
        int has_card = 0;
        int row, col;

        do
        {
            row = rand() % 4;
            col = rand() % 13;

            has_card = 0;
            for (size_t j = 0; j < 5; j++)
            {
                if (card[j] == deck[row][col])
                    has_card = 1;
            }
        } while (has_card);

        card[i] = deck[row][col];

    }

    //Test Data
    card[0] = 13 * 0 + 4 + 1;
    card[1] = 13 * 1 + 4 + 1;
    card[2] = 13 * 2 + 4 + 1;
    card[3] = 13 * 3 + 4 + 1;
    card[4] = 13 * 0 + 5 + 1;

    //test_printCards(card);
    printf("\n\n");

    for (size_t i = 0; i < 5; i++)
    {
        printf("%s of %s\n", faces[get_face(card[i])], suits[get_suit(card[i])]);
    }
    printf("\n");

    sort_card(card, 5);

    //flush
    int suit = get_suit(card[0]);
    int flush = 1;
    for (size_t i = 1; i < 5; i++)
    {
        if (suit != get_suit(card[i]))
            flush = 0;
    }

    //straight
    int straight = 1;
    for (size_t i = 0; i < 5 - 1; i++)
    {
        if (get_face(card[i + 1]) - get_face(card[i]) != 1)
            straight = 0;
    }
    //10, J, Q, K, A
    if (get_face(card[0]) == 0)
    {
        straight = 1;
        for (size_t i = 1; i < 4; i++)
        {
            if (get_face(card[i]) != i + 8)
                straight = 0;
        }
    }

    //pair
    int pair = 0;
    for (size_t i = 0; i < 4; i++)
    {
        if (get_face(card[i]) == get_face(card[i + 1]))
        {
            pair++;
            i++;
        }
    }

    //three
    int three = 0;
    for (size_t i = 0; i < 3; i++)
    {
        if (get_face(card[i]) == get_face(card[i + 1]) && get_face(card[i + 1]) == get_face(card[i + 2]))
            three++;
    }

    //four
    int four = 0;
    for (size_t i = 0; i < 2; i++)
    {
        if (get_face(card[i]) == get_face(card[i + 1]) && get_face(card[i + 1]) == get_face(card[i + 2]) && get_face(card[i + 2]) == get_face(card[i + 3]))
            four++;
    }

    if (four)
        printf("You have Four of a kind.\n");
    if (three && pair == 2 && !four)
        printf("You have Full House.\n");
    if (flush)
        printf("You have flush.\n");
    if (straight)
        printf("You have Straight.\n");
    if (three)
        printf("You have Three of a kind.\n");
    if (pair == 2)
        printf("You have Two Pair.\n");
    if (pair == 1)
        printf("You have One Pair.\n");
}

void init(int deck[4][13])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 13; j++)
        {
            deck[i][j] = 13 * i + j + 1;
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int get_suit(int card)
{
    return (card - 1) / 13;
}

int get_face(int card)
{
    return (card - 1) % 13;
}

void sort_card(int *card, int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (get_face(card[j]) > get_face(card[j + 1]))
                swap(card + j, card + j + 1);
        }
    }
}

void test_printCards(int *card)
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", card[i]);
    }
}