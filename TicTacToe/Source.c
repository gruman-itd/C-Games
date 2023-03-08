#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(char board[], char player);
void makeMove(char board[], char player);
int randomint(int min, int max);
bool checkWin(char board[], char player);

bool gameActive = true;

int main()
{
    
    char enter = 0;

    printf("*************************************\n");
    printf("* Press ENTER to start Tic Tac Toe! *\n");
    printf("*************************************\n");

    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    char player = 'x';
    char board[9][1] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    drawBoard(board, player);

    while (gameActive)
    {
        makeMove(board, player);
        drawBoard(board, player);
        checkWin(board, player);
        if (player == 'x')
        {
            player = 'o';
        }
        else
        {
            player = 'x';
        }
    }
    return 0;
}

void drawBoard(char board[], char player)
{
    printf("%c %c %c\n", board[0], board[1], board[2]);
    printf("%c %c %c\n", board[3], board[4], board[5]);
    printf("%c %c %c\n", board[6], board[7], board[8]);
    printf("*****\n");
}

void makeMove(char board[], char player)
{
    bool isReady = false;
    int num;
    while (!isReady)
    {
        if (player == 'x')
        {
            printf("Enter a number and press enter:");
            scanf_s("%d", &num);
            num -= 1;
        }
        else
        {
            num = randomint(0, 8);
        }
            if (board[num] == 'x' || board[num] == 'o')
            {
                isReady = false;
                if (player == 'x')
                {
                printf("Please choose an open space!\n");
                }
            }
            else
            {
                isReady = true;
            }
        }
     board[num] = player;
    
}

bool checkWin(char board[], char player)
{
    if (board[0] == player && board[1] == player && board[2] == player)
    { // top row
        gameActive = false;
    }

    if (board[3] == player && board[4] == player && board[5] == player)
    { // second row
        gameActive = false;
    }

    if (board[6] == player && board[7] == player && board[8] == player)
    { // bottom row
        gameActive = false;
    }
    if (board[0] == player && board[3] == player && board[6] == player)
    { // left col
        gameActive = false;
    }

    if (board[1] == player && board[4] == player && board[7] == player)
    { // middle col
        gameActive = false;
    }

    if (board[2] == player && board[5] == player && board[8] == player)
    { // bottom col
        gameActive = false;
    }

    if (board[0] == player && board[4] == player && board[8] == player)
    { // cross one
        gameActive = false;
    }

    if (board[2] == player && board[5] == player && board[7] == player)
    { // cross two
        gameActive = false;
    }

    if (!gameActive)
    {
        printf("\n"
               "%c"
               " wins!\n",
               player);
    }
}

int randomint(int min, int max)
{ // get a random integer inclusive
    time_t t;
    srand((unsigned)time(&t));
    int num;
    num = (rand() % (max - min + 1)) + min;
    return num;
}