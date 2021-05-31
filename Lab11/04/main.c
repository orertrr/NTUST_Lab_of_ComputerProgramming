#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// The rule of comparison is Texas hold'em

void shuffle(int deck[4][13]);
void deal(int deck[4][13], int *cards, int num);
void init(int deck[4][13]);
void swap(int *a, int *b);
int get_suit(int card);
int get_face(int card);
void sort_card(int *card, int size);
void test_printCards(int *card);
int rank(int *card);
int compare(int card1[5], int card2[5]);
void show_card(int card[5]);

const char *suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const char *faces[13] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

int main()
{
    int deck[4][13] = {0};
    int again = 1;
    int cards[10];

    srand(time(NULL));

    init(deck);

    while (again)
    {
        shuffle(deck);

        deal(deck, cards, 10);

        printf("Hand1:\n");
        show_card(cards);

        printf("Hand2:\n");
        show_card(cards + 5);

        printf("\nShuffle again?(0 is No, 1 is Yes)");
        printf("\nInput 0 will start compare:");
        scanf("%d", &again);
        printf("\n");
    }

    int result = compare(cards, cards + 5);

    if (result == 1)
    {
        printf("Hand1 is better.\n");
    }
    else if (result == -1)
    {
        printf("Hand2 is better.\n");
    }
    else
    {
        printf("Draw.\n");
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

void deal(int deck[4][13], int *cards, int num)
{
    for (size_t i = 0; i < num; i++)
    {
        cards[i] = deck[0][i];
    }
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

//sort from small to large by face and suit
void sort_card(int *card, int size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - i - 1; j++)
        {
            //First condition: Face
            if (get_face(card[j]) > get_face(card[j + 1]))
                swap(card + j, card + j + 1);
            //Second condition: Suit
            else if (card[j] > card[j + 1])
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

int rank(int *card)
{
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

    //Straight flush
    if (flush && straight)
        return 1;

    //Four of a kind
    if (four)
        return 2;

    //Full house
    if (three && pair == 2 && !four)
        return 3;

    //Flush
    if (flush)
        return 4;

    //Straight
    if (straight)
        return 5;

    //Three of a kind
    if (three)
        return 6;

    //Two pair
    if (pair == 2)
        return 7;

    //One pair
    if (pair == 1)
        return 8;

    //High card
    return 9;
}

//1  card1 better
//0  draw
//-1 card2 better
int compare(int card1[5], int card2[5])
{
    //card1 and card2 are sorted in rank function.

    int rank1 = rank(card1);
    int rank2 = rank(card2);

    if (rank1 < rank2)
        return 1;
    else if (rank1 > rank2)
        return -1;
    else
    {
        int weight1 = 0, weight2 = 0;

        switch (rank1)
        {
        //When both are flush straight, compare their biggest face.
        case 1:
        {
            if (get_face(card1[4]) > get_face(card2[4]))
                return 1;
            else if (get_face(card1[4]) < get_face(card2[4]))
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

        //When both are Four of kind, compare their face whose index is 2.
        case 2:
        {
            if (get_face(card1[2]) > get_face(card2[2]))
                return 1;
            else
            {
                return -1;
            }
        }

        //When both are Full house, compare their face whose index is 2.
        case 3:
        {
            if (get_face(card1[2]) > get_face(card2[2]))
                return 1;
            else
            {
                return -1;
            }
        }

        //When both are Flush, compare their face from large to small
        case 4:
        {
            for (size_t i = 4; i >= 0; i--)
            {
                if (get_face(card1[i]) > get_face(card2[i]))
                    return 1;
                else if (get_face(card1[i]) < get_face(card2[i]))
                {
                    return -1;
                }
            }

            return 0;
        }

        //When both are Straight, compare their biggest face
        case 5:
        {
            if (get_face(card1[4]) > get_face(card2[4]))
                return 1;
            else if (get_face(card1[4]) < get_face(card2[4]))
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

        //When both are Three of kind, comapre their face whose index is 2
        case 6:
        {
            if (get_face(card1[2]) > get_face(card2[2]))
                return 1;
            else
            {
                return -1;
            }
        }

        //When both have at least one Pair, compare their weight.
        case 7:
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (get_face(card1[i]) == get_face(card1[i + 1]))
                    weight1 |= 1 << (get_face(card1[i]) + 1 + 13);
                else
                {
                    weight1 |= 1 << (get_face(card1[i]) + 1);
                }

                if (get_face(card2[i]) == get_face(card2[i + 1]))
                    weight2 |= 1 << (get_face(card2[i]) + 1 + 13);
                else
                {
                    weight2 |= 1 << (get_face(card2[i]) + 1);
                }
            }

            break;
        }

        case 8:
        {
            for (size_t i = 0; i < 4; i++)
            {
                if (get_face(card1[i]) == get_face(card1[i + 1]))
                    weight1 |= 1 << (get_face(card1[i]) + 1 + 13);
                else
                {
                    weight1 |= 1 << (get_face(card1[i]) + 1);
                }

                if (get_face(card2[i]) == get_face(card2[i + 1]))
                    weight2 |= 1 << (get_face(card2[i]) + 1 + 13);
                else
                {
                    weight2 |= 1 << (get_face(card2[i]) + 1);
                }
            }

            break;
        }

        default:
        {
            for (size_t i = 0; i < 4; i++)
            {
                weight1 |= 1 << (get_face(card1[i]) + 1);
                weight2 |= 1 << (get_face(card2[i]) + 1);
            }

            break;
        }
        }

        if(weight1 > weight2)
            return 1;
        else if (weight1 < weight2)
        {
            return -1;
        }
        return 0;
    }
}

void show_card(int card[5])
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("%s of %s\n", faces[get_face(card[i])], suits[get_suit(card[i])]);
    }
    printf("\n");
}