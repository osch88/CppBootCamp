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


void checkRow(SudokoCell_t SudokoTable[][SIZE], bool solutionROW[SIZE], const int &row)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        if (SudokoTable[row][i].value != 0)
        {
            int tmp = SudokoTable[row][i].value;
            solutionROW[tmp - 1] = false;
        }
    }
}

void checkColumn(SudokoCell_t SudokoTable[][SIZE], bool solutionCOL[SIZE], const int &col)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        if (SudokoTable[i][col].value != 0)
        {
            int tmp = SudokoTable[i][col].value;
            solutionCOL[tmp - 1] = false;
        }
    }
}

void checkBox(SudokoCell_t SudokoTable[][SIZE], bool solutionBOX[SIZE], const int &row, const int &col)
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            int tmp = SudokoTable[3 * (row - row % 3) / 3 + i][3 * (col - col % 3) / 3 + j].value;
            if (tmp != 0)
            {
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
                solved = false; 
            }
        }
    }
    return solved;
}


bool solver(SudokoCell_t SudokoTable[][SIZE]){

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
bool bruteForce(SudokoCell_t SudokoTable[][SIZE], size_t row , size_t col) {
    bool solved = false;
    for (; row < SIZE; row++) {                                                 // Iterate rows
        for (; col < SIZE; col++) {                                             // Iterate columns
            if (SudokoTable[row][col].value == 0) {                             // IF cell's value == 0, brute force

                for (size_t k = 0; k < SIZE; k++) {                             // Iterate array of possibleSolutions { 0,0,1,1,1,0,0,1}
                    if (SudokoTable[row][col].possibleSolutions[k] != 0) {      // Continue if k in possibleSolution is not 0 == false

                        SudokoTable[row][col].value = k + 1;                    // Set first value to possibleSolutions[k] + 1
                        std::cout << "[" << row << "," << col << "] - " << SudokoTable[row][col].value << "\n";

                        if( solver(SudokoTable) ){                              // Call for the easy solver to check if solved and ...
                                                                                // .. update possible values for other cells
                            std::cout << "Solved!\n";
                            return solved = true;
                        }
                        // Call for bruteForce again
                    }
                }
            }
        }
    }
    return solved;
}

/*
    Find cell with the most few possible solutions
*/
