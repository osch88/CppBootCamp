/*
- Find all possible solutions if SudokoCell->value = 0
    - Check row for possible values
    - Check column for possible values
    - Check 3x3 square for possible values
    - Update SudokoCell->possibleSolutions
        - If only 1 solution, set value and restart
*/
#include "Solver.h"


void checkRow(SudokoCell_t SudokoTable[][SIZE], bool solutionROW[SIZE], const int &row){
    for (size_t i = 0; i < SIZE; i++){
        if (SudokoTable[row][i].value != 0){
            int tmp = SudokoTable[row][i].value;
            solutionROW[tmp - 1] = false;
        }
    }
}

void checkColumn(SudokoCell_t SudokoTable[][SIZE], bool solutionCOL[SIZE], const int &col){
    for (size_t i = 0; i < SIZE; i++){
        if (SudokoTable[i][col].value != 0){
            int tmp = SudokoTable[i][col].value;
            solutionCOL[tmp - 1] = false;
        }
    }
}


void checkBox(SudokoCell_t SudokoTable[][SIZE], bool solutionBOX[SIZE], const int &row, const int &col){
    for (size_t i = 0; i < 3; i++){
        for (size_t j = 0; j < 3; j++){
            int tmp = SudokoTable[3 * (row - row % 3) / 3 + i][3 * (col - col % 3) / 3 + j].value;
            if (tmp != 0){
                solutionBOX[tmp - 1] = false;
            }
        }
    }
}


void solver(SudokoCell_t SudokoTable[][SIZE]){

    bool game = true;
    while(game){
        game = false;
        for (size_t row = 0; row < SIZE; row++){
            for (size_t col = 0; col < SIZE; col++){
                // std::cout << "SudokoTable[" << row << "," << col << "].value = " << SudokoTable[row][col].value << "\n";
                if (SudokoTable[row][col].value == 0){
                    bool solutionROW[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                    checkRow(SudokoTable, solutionROW, row);

                    bool solutionCOL[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                    checkColumn(SudokoTable, solutionCOL, col);
                    
                    bool solutionBOX[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                    checkBox(SudokoTable, solutionBOX, row, col);
                    
                    bool solutionRESULT[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                    int solutions = 0, location = 0;

                    for (size_t i = 0; i < SIZE; i++){
                        if (solutionROW[i] == 0 || solutionCOL[i] == 0 || solutionBOX[i] == 0){
                            solutionRESULT[i] = 0;
                        }
                        else {
                            solutions++;
                            location = i;
                        }
                    }
                    if (solutions == 1){                         // If yes, then we need to loop over all cells again
                        SudokoTable[row][col].value = location + 1;
                        game = true;
                    }
                    else {
                        for (size_t i = 0; i < SIZE; i++){
                            SudokoTable[row][col].possibleSolutions[i] = solutionRESULT[i];
                        }
                    }
                }
            }
        }
    }
}


