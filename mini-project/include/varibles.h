#ifndef VARIBLES_H
#define VARIBLES_H

#include <iostream>
#include <array>

const unsigned int SIZE = 9;

typedef struct CellCoordinates {
    unsigned int row;
    unsigned int col;
} Coord_t;

typedef struct SudokuCell {
    unsigned int value;
    unsigned int initiatedValue;
    bool hypos[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 0 == false   { 1,2,3,4,5,6,7,8,9 }
    
    unsigned int noHypos;
    bool peers[20];
    bool valueSet = false;
    // Coord_t units[3][9];
    // Coord_t peers[20];

} SudokuCell_t;

// std::array<std::array<SudokuCell_t, SIZE>, SIZE> SudokuBoard;



#endif