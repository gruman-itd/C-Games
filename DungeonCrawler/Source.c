#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void drawBoard();
void moveChar(int direction);
void randomInt(int min, int max);

int size = 3; // intial size of board
int steps = 0; // step counter
int level = 1;
int position[2] = { 0, 0 }; // initial location of player
int goal[2] = { 2, 2 }; // location of goal for level 1
bool gameActive = true;

int main()
{
    int direction; // input from user
    char enter = 0;

    printf("*****************************************\n");
    printf("* Press ENTER to start Dungeon Crawler! *\n");
    printf("*****************************************\n");

    while (enter != '\r' && enter != '\n') { enter = getchar(); }

    while (gameActive)
    {
        drawBoard(); // update the board
        scanf_s("%d", &direction); // get the direction
        moveChar(direction); // move the player
    }
    return 0;
}

void moveChar(int direction)
{
    // store old position in case player is moving out of bounds
    int x = position[0];
    int y = position[1];

    // change position based on input
    if (direction == 1)
    { // up
        position[0] = position[0] - 1;
    }
    else if (direction == 2)
    { // down
        position[0] = position[0] + 1;
    }
    else if (direction == 3)
    { // left
        position[1] = position[1] - 1;
    }
    else if (direction == 4)
    { // right
        position[1] = position[1] + 1;
    }
    else if (direction == 0)
    { // quit: stops the while() loop
        gameActive = false;
    }

    if (position[0] < 0 || position[0] > size - 1 || position[1] < 0 || position[1] > size - 1)
    { // moving outside the borders. Revert position to original.
        position[0] = x;
        position[1] = y;
    }
    else
    { // success. Player has moved and step count increments
        steps = steps + 1;
    }

}

void drawBoard()
{ // create and redraw the board
    printf("LEVEL %d (%dx%d)\n", level, size, size);
    printf("Steps: %d", steps);

    for (int i = 0; i < size; i++)
    { // draw the board
        printf("\n");
        for (int j = 0; j < size; j++)
        {
            if (position[0] == goal[0] && position[1] == goal[1])
            { // if the player hits the goal they mve to the next level
                position[0] = 0; // reset player position
                position[1] = 0;
                size = size + 1; // increase board size
                level = level + 1; // increment level
                randomInt(0, size - 1); // get a new goal location
                drawBoard(); // refresh board
                return;
            }
            else
            {
                if (position[0] == i && position[1] == j)
                { // player
                    printf("X ");
                }
                else
                { // not player
                    printf(". ");
                }
            }
        }
    }
    printf("\nUP: 1\nDOWN: 2\nLEFT: 3\nRIGHT: 4\nQUIT: 0");
    printf("\n\n");
}

void randomInt(int min, int max)
{ // get a random integer inclusive
    time_t t;
    srand((unsigned)time(&t));
    int num, num1;
    num = (rand() % (max - min + 1)) + min;
    num1 = (rand() % (max - min + 1)) + min;

    if (num == 0 && num1 == 0)
    { // if goal is on the players position reroll
        randomInt(min, max);
    }
    else
    { // set new goal position
        goal[0] = num;
        goal[1] = num1;
    }

}