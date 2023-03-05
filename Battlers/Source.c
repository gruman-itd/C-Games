#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "randomint.h"

void drawBoard();
void menuScreen();
void startGame();
void gameOver();
void attack(int attacker, int defender, int move);

char charNames[3][10] = { "Leslie", "Stacey", "Paisly" };
int charHP[3] = { 20, 25, 15 };
int charSTR[3] = { 2, 1, 3 };
int characters[2];
int currentTurn = 0;

int level = 1;
bool gameActive = true;

int main()
{
    menuScreen();
    startGame();

    while (gameActive)
    {
        drawBoard(); // update the board
    }

    return 0;
}

void menuScreen()
{
    int enter = 0;

    printf("**********************************\n");
    printf("* Press ENTER to start Battlers! *\n");
    printf("**********************************\n");

    while (enter != '\r' && enter != '\n') { enter = getchar(); }
    
}

void startGame()
{
    int player, enemy;
    printf("**********************************\n");
    printf("* Chose a Character:             *\n");
    printf("* 1. Stacey                      *\n");
    printf("* 2. Paisly                      *\n");
    printf("**********************************\n\n");
    scanf_s("%d", &player);
    characters[0] = player;
    characters[1] = 0;
}

void attack(int attacker, int defender, int move)
{
    int attack = charSTR[characters[attacker]];

    if (move == 2)
    { // kick
        int rand = randomint(0, 1);
        if (rand == 0)
        {
            attack = attack + 2;
        }
        else
        {
            attack = attack - 2;
        }
    }

    if (attack <= 0)
    {
        printf("**********************************\n");
        printf("* MISS!                          *\n");
        printf("**********************************\n");
    }
    else
    {
        charHP[defender] = charHP[defender] - attack;
        
        printf("**********************************\n");
        printf("* HIT! %dhp                       *\n", attack);
        printf("**********************************\n");

        if (charHP[characters[0]] <= 0 || charHP[characters[1]] <= 0)
        {
            gameOver();
        }
    }

}
void drawBoard()
{ // create and redraw the board

    int action;
    printf("**********************************\n");
    printf("* %s (HP: %d)                *\n", charNames[characters[0]], charHP[characters[0]]);
    printf("* VS                             *\n");
    printf("* %s (HP: %d)                *\n", charNames[characters[1]], charHP[characters[1]]);
    printf("**********************************\n");
    printf("* (1) Punch (2) Kick             *\n");
    printf("**********************************\n\n");
    scanf_s("%d", &action);
    attack(characters[0], characters[1], action);
    if (gameActive)
    {
        attack(characters[1], characters[0], randomint(1, 2));
    }
}

void gameOver()
{
    char message[4] = "Won";
    if (charHP[characters[0]] <= 0 || charHP[characters[1]] <= 0)
    { // game over
        if (charHP[characters[0]] <= 0)
        {
            char message[4] = "Lost";
        }
    }
    
    printf("**********************************\n");
    printf("* Game over you %s!             *\n", message);
    printf("**********************************\n\n");

    gameActive = false;
}