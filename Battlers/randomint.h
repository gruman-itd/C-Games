#ifndef RANDOMINT_H_
#define RANDOMINT_H_

int randomint(int min, int max)
{// get a random integer inclusive
    time_t t;
    srand((unsigned)time(&t));
    int num;
    num = (rand() % (max - min + 1)) + min;
    return num;
}

#endif