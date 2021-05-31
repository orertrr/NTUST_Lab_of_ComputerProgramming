#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct movetype
{
    int squares;
    int direction;
} MoveType;

typedef struct animal
{
    char label;
    int square;
    MoveType movetypes[10];
} Animal;

// Tortoise
Animal Tortoise;
MoveType Fplod;
MoveType Slip;
MoveType Splod;

// Hare
Animal Hare;
MoveType Stop;
MoveType Bhop;
MoveType Bslip;
MoveType Shop;
MoveType Sslip;

void Init();
void Move(Animal *a);
void print_Race();

int main()
{
    Init();

    printf("BANG !!!!!\n");
    printf("AND THEY'RE OFF !!!!!\n");

    while (Tortoise.square != 70 && Hare.square != 70)
    {
        Move(&Tortoise);
        Move(&Hare);

        for (size_t i = 1; i <= 70; i++)
        {
            if (Tortoise.square == Hare.square && Hare.square == i)
            {
                printf("OUCH!!!");
                i += 6;
            }
            else if (Tortoise.square == i)
            {
                printf("T");
            }
            else if (Hare.square == i)
            {
                printf("H");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n\n");
        Sleep(1000);
    }

    if (Tortoise.square == Hare.square && Hare.square == 70)
    {
        printf("It's a tie.\n");
    }
    else if (Tortoise.square == 70)
    {
        printf("TORTOISE WINS!!!\n");
    }
    else if (Hare.square == 70)
    {
        printf("Hare wins.\n");
    }

    system("pause");
}

void Init()
{
    srand(time(NULL));

    Fplod.direction = 1;
    Fplod.squares = 3;

    Slip.direction = -1;
    Slip.squares = 6;

    Splod.direction = 1;
    Splod.squares = 1;

    Stop.direction = 1;
    Stop.squares = 0;

    Bhop.direction = 1;
    Bhop.squares = 9;

    Bslip.direction = -1;
    Bslip.squares = 12;

    Shop.direction = 1;
    Shop.squares = 1;

    Slip.direction = -1;
    Slip.squares = 2;

    Tortoise.label = 'T';
    Tortoise.square = 1;
    Tortoise.movetypes[0] = Fplod;
    Tortoise.movetypes[1] = Fplod;
    Tortoise.movetypes[2] = Fplod;
    Tortoise.movetypes[3] = Fplod;
    Tortoise.movetypes[4] = Fplod;
    Tortoise.movetypes[5] = Slip;
    Tortoise.movetypes[6] = Slip;
    Tortoise.movetypes[7] = Splod;
    Tortoise.movetypes[8] = Splod;
    Tortoise.movetypes[9] = Splod;

    Hare.label = 'H';
    Hare.square = 1;
    Hare.movetypes[0] = Stop;
    Hare.movetypes[1] = Stop;
    Hare.movetypes[2] = Bhop;
    Hare.movetypes[3] = Bhop;
    Hare.movetypes[4] = Bslip;
    Hare.movetypes[5] = Shop;
    Hare.movetypes[6] = Shop;
    Hare.movetypes[7] = Shop;
    Hare.movetypes[8] = Sslip;
    Hare.movetypes[9] = Sslip;
}

void Move(Animal *a)
{
    int movetype = rand() % 10;

    a->square = a->square + a->movetypes[movetype].squares * a->movetypes[movetype].direction;
    if (a->square > 70)
        a->square = 70;
    if (a->square < 1)
        a->square = 1;
}