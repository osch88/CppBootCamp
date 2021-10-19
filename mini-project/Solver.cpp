/*
- Find all possible solutions if SudokoCell->value = 0
    - Check row for possible values
    - Check column for possible values
    - Check 3x3 square for possible values
    - Update SudokoCell->possibleSolutions
        - If only 1 solution, set value and restart
*/
#include "Solver.h"
#include "Printer.h"
#include "Varibles.h"


void checkRow(SudokoCell_t SudokoTable[][SIZE], bool _solutionROW[SIZE], const int &row) {
    for (size_t i = 0; i < SIZE; i++) {
        if (SudokoTable[row][i].value != 0) {
            int tmp = SudokoTable[row][i].value;
            _solutionROW[tmp - 1] = false;
        }
    }
}

void checkColumn(SudokoCell_t SudokoTable[][SIZE], bool solutionCOL[SIZE], const int &col) {
    for (size_t i = 0; i < SIZE; i++) {
        if (SudokoTable[i][col].value != 0) {
            int tmp = SudokoTable[i][col].value;
            solutionCOL[tmp - 1] = false;
        }
    }
}

void checkBox(SudokoCell_t SudokoTable[][SIZE], bool solutionBOX[SIZE], const int &row, const int &col) {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            int tmp = SudokoTable[3 * (row - row % 3) / 3 + i][3 * (col - col % 3) / 3 + j].value;
            if (tmp != 0) {
                solutionBOX[tmp - 1] = false;
            }
        }
    }
}

bool checkIfSolved(SudokoCell_t SudokoTable[][SIZE]){
    bool solved = true;
    for (size_t row = 0; row < SIZE; row++){
        for (size_t col = 0; col < SIZE; col++){
            if (SudokoTable[row][col].value == 0){ 
                return false;
            }
        }
    }
    return solved;
}

bool constraint_propagation(SudokoCell_t SudokoTable[][SIZE]){

    bool game = true, solved = true;
    while (game) {
        game = false;
        for (size_t row = 0; row < SIZE; row++){
            for (size_t col = 0; col < SIZE; col++){
                if (SudokoTable[row][col].value == 0){
                    bool _possibleSolution[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

                    checkRow(SudokoTable, _possibleSolution, row);
                    checkColumn(SudokoTable, _possibleSolution, col);
                    checkBox(SudokoTable, _possibleSolution, row, col);

                    int solutions = 0; // Varible that counts possible solutions in each cell aka possibleSolutions array
                    int location = 0;  // Where in the array the solution exist. 0 = 1, 1 = 2 etc

                    for (size_t i = 0; i < SIZE; i++) {
                        if (_possibleSolution[i] != 0) {
                            solutions++;
                            location = i;
                        }
                    }
                    if(solutions == 1) {
                        SudokoTable[row][col].value = location + 1; // If only one solution then this as .value
                        game = true;
                    }
                    else
                    {
                        for (size_t i = 0; i < SIZE; i++)
                        {
                            SudokoTable[row][col].possibleSolutions[i] = _possibleSolution[i];
                        }
                    }
                }
            }
        }
    }

    return checkIfSolved(SudokoTable);
}


/*
    For loop:
    - try first possibleSolution
    - call for the same function again
*/
bool bruteForce(SudokoCell_t SudokoTable[][SIZE], size_t _row , size_t _col) {

    if ( _row == 8 && _col == 9 ) {
        return true;
    }

    if ( _col == 9 ) {
        _row++;
        _col = 0;
    }

    // If the cells value is NOT 0, then move on to the next one
    if( SudokoTable[_row][_col].value != 0 ){
        return bruteForce(SudokoTable, _row, _col + 1);
    }

    // Save a copy of all possibleSolutions and value in case of disaster
    // FIXME: Need to re-do constrain propogation
    bool tmp_possibleSolutions[SIZE];
    for (size_t i = 0; i < SIZE; i++){
        tmp_possibleSolutions[i] = SudokoTable[_row][_col].possibleSolutions[i];
    }

    std::vector<int> tmp;
    for (size_t i = 0; i < SIZE; i++){
        if( SudokoTable[_row][_col].possibleSolutions[i] != 0 ){
            tmp.push_back(i+1);
        }
        tmp_possibleSolutions[i] = SudokoTable[_row][_col].possibleSolutions[i];
    }
    int tmp_value = SudokoTable[_row][_col].value;

    bool tmpSol[SIZE] = {1,1,1,1,1,1,1,1,1};
    checkRow(SudokoTable, tmpSol, _row);
    checkColumn(SudokoTable, tmpSol, _col);
    checkBox(SudokoTable, tmpSol, _row, _col);
    
    for( int i : tmp ) {
        if( tmpSol[i-1] == 1 ){
            SudokoTable[_row][_col].value = i;
            if( bruteForce(SudokoTable, _row, _col+1) ){
                return true;
            }
        }
    }
    // If it didn't work we have to go back to the original values
    for (size_t i = 0; i < SIZE; i++){
        SudokoTable[_row][_col].possibleSolutions[i] = tmp_possibleSolutions[i];
    }
    SudokoTable[_row][_col].value = tmp_value;
    
    return false;
}


