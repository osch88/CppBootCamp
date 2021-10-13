#ifndef VARIBLES_H
#define VARIBLES_H

const unsigned int SIZE = 9;

typedef struct SudokoCell
{
    int value;
    bool possibleSolutions[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 0 == false
                                                                //{ 1,2,3,4,5,6,7,8,9 }
} SudokoCell_t;

#endif