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


void checkRow(SudokoCell_t (&SudokuTable)[SIZE][SIZE], bool (&_solutionROW)[SIZE], const int &row) {
    for (size_t i = 0; i < SIZE; i++) {
        if( SudokuTable[row][i].value != 0 ) {
            int tmp = SudokuTable[row][i].value;
            _solutionROW[tmp - 1] = false;
        }
    }
}

void checkColumn(SudokoCell_t (&SudokuTable)[SIZE][SIZE], bool (&solutionCOL)[SIZE], const int &col) {
    for (size_t i = 0; i < SIZE; i++) {
        if (SudokuTable[i][col].value != 0) {
            int tmp = SudokuTable[i][col].value;
            solutionCOL[tmp - 1] = false;
        }
    }
}

void checkBox(SudokoCell_t (&SudokuTable)[SIZE][SIZE], bool (&solutionBOX)[SIZE], const int &row, const int &col) {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            int tmp = SudokuTable[3 * (row - row % 3) / 3 + i][3 * (col - col % 3) / 3 + j].value;  // TODO: row / 3 * 3
            if (tmp != 0) {
                solutionBOX[tmp - 1] = false;
            }
        }
    }
}

bool checkIfSolved(SudokoCell_t (&SudokuTable)[SIZE][SIZE]){
    bool solved = true;
    for (size_t row = 0; row < SIZE; row++){
        for (size_t col = 0; col < SIZE; col++){
            if (SudokuTable[row][col].value == 0){ 
                return false;
            }
        }
    }
    return solved;
}
// bool constraint_propagation(Sudoku SudokuTable) {
bool constraint_propagation(SudokoCell (&SudokuTable)[SIZE][SIZE]) {
  
    bool game = true, solved = true;
    while (game) {
        game = false;
        for (size_t row = 0; row < SIZE; row++){
            for (size_t col = 0; col < SIZE; col++){
                if (SudokuTable[row][col].value == 0){
                    bool _possibleSolution[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

                    checkRow(SudokuTable, _possibleSolution, row);
                    checkColumn(SudokuTable, _possibleSolution, col);
                    checkBox(SudokuTable, _possibleSolution, row, col);

                    int solutions = 0; // Varible that counts possible solutions in each cell aka possibleSolutions array
                    int location = 0;  // Where in the array the solution exist. 0 = 1, 1 = 2 etc

                    for (size_t i = 0; i < SIZE; i++) {
                        if (_possibleSolution[i] != 0) {
                            solutions++;
                            location = i;
                        }
                    }
                    if(solutions == 1) {
                        SudokuTable[row][col].value = location + 1; // If only one solution then this as .value
                        game = true;
                    }
                    else
                    {
                        for (size_t i = 0; i < SIZE; i++)
                        {
                            SudokuTable[row][col].possibleSolutions[i] = _possibleSolution[i];
                        }
                    }
                }
            }
        }
    }
    return checkIfSolved(SudokuTable);
}


/*
    For loop:
    - try first possibleSolution
    - call for the same function again
*/
int iterations = 0;
bool bruteForce(SudokoCell_t (&SudokuTable)[SIZE][SIZE], size_t _row , size_t _col) {
    if ( _row == 8 && _col == 9 ) {
        return true;
    }

    if ( _col == 9 ) {
        _row++;
        _col = 0;
    }

    // If the cells value is NOT 0, then move on to the next one
    if( SudokuTable[_row][_col].value != 0 ){
        return bruteForce(SudokuTable, _row, _col + 1);
    }

    // TODO: Can this be iterated in a faster way?
    // Check possible solutions for this cell before brute forcing
    bool tmpSol[SIZE] = {1,1,1,1,1,1,1,1,1};
    checkRow(SudokuTable, tmpSol, _row);
    checkColumn(SudokuTable, tmpSol, _col);
    checkBox(SudokuTable, tmpSol, _row, _col);

    for (size_t i = 0; i < SIZE; i++) {
        if( tmpSol[i] == 1 ){
            SudokuTable[_row][_col].value = i+1;
            if( bruteForce(SudokuTable, _row, _col+1) ){
                return true;
            }
        }
    }
    
    SudokuTable[_row][_col].value = 0;
    iterations++;

    return false;
}

void iterationPrint(){
    std::cout << "Iterations:\t" << iterations  << std::endl;
}