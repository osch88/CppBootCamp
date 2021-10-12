#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>

#include "Solver.h"
#include "Printer.h"

typedef struct SudokoCell
{
    int value;
    bool possibleSolutions[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // 0 == false
                                                                //{ 1,2,3,4,5,6,7,8,9 }
} SudokoCell_t;

void parser(const std::string &fileName, SudokoCell_t SudokoTable[][SIZE])
{
    /* 
        - Read in a text file to a string [4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......]
        - Check: Must be exact 81 digits
        - Parse the text file into an 2D array
        - By creating a new instance of struct SudokoCell
        - Update SudokoCell->value
    */
    // bool success = false;
    std::ifstream file(fileName);

    if (file.is_open())
    {

        std::vector<int> numbers; // Replace with SudokoTable
        char input;
        while (file >> input)
        {
            if (isdigit(input))
            {
                numbers.push_back(static_cast<int>(input - 48));
            }
        }
        // Need a check if size == 81
        size_t row = 0;
        size_t col = 0;
        for (size_t k = 0; k < numbers.size(); k++)
        {
            SudokoTable[row][col].value = numbers[k];
            col++;
            if (!(k + 1) % 9)
            { // Takes care of new a row in the table
                row++;
                col = 0;
            }
        }

        file.close();
        // success = true;
    }
    else
    {
        std::cout << "nothing..\n";
        // success = false;
    };

    // return success;
};

void checkRow(SudokoCell_t SudokoTable[][SIZE], bool solutionROW[SIZE], const int &row)
{
    // Check all possible solutions for row
    for (size_t i = 0; i < SIZE; i++)
    {
        if (SudokoTable[row][i].value != 0)
        {
            int tmp = SudokoTable[row][i].value;
            solutionROW[tmp - 1] = false;
        };
    }
};

void checkColumn(SudokoCell_t SudokoTable[][SIZE], bool solutionCOL[SIZE], const int &col)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        if (SudokoTable[i][col].value != 0)
        {
            int tmp = SudokoTable[i][col].value;
            solutionCOL[tmp - 1] = false;
        };
    }
};

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
};

void solver(SudokoCell_t SudokoTable[][SIZE])
{
    /*
    - Find all possible solutions if SudokoCell->value = 0
        - Check row for possible values
        - Check column for possible values
        - Check 3x3 square for possible values
        - Update SudokoCell->possibleSolutions
            - If only 1 solution, set value and restart
    */
    for (size_t row = 0; row < SIZE; row++)
    {
        for (size_t col = 0; col < SIZE; col++)
        {
            if (SudokoTable[row][col].value != 0)
            {
                bool solutionROW[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                checkRow(SudokoTable, solutionROW, row);
                // std::cout << "ROW: \n";
                // for (size_t i = 0; i < SIZE; i++){
                //     std::cout << ROW[i] << " ";
                // }
                // std::cout << "\n\n";
                bool solutionCOL[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                checkColumn(SudokoTable, solutionCOL, col);
                // std::cout << "COL: \n";
                // for (size_t i = 0; i < SIZE; i++){
                //     std::cout << possSol[i] << " ";
                // }
                // std::cout << "\n\n";
                bool solutionBOX[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                checkBox(SudokoTable, solutionBOX, row, col);
                // std::cout << "BOX: \n";
                // for (size_t i = 0; i < SIZE; i++){
                //     std::cout << solutionBOX[i] << " ";
                // }
                // std::cout << "\n\n";
                bool solutionRESULT[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                int solutions = 0, location = 0;
                for (size_t i = 0; i < SIZE; i++)
                {
                    if (solutionROW[i] == 0 || solutionCOL[i] == 0 || solutionBOX[i] == 0)
                    {
                        solutionRESULT[i] = false;
                    }
                    else
                    {
                        solutions++;
                        location = i;
                    }
                }
                if (solutions == 1)                         // If yes, then we need to loop over all cells again
                {
                    SudokoTable[row][col].value = location + 1;
                }
                else
                {
                    for (size_t i = 0; i < SIZE; i++)
                    {
                        SudokoTable[row][col].possibleSolutions[i] = solutionRESULT[i];
                    }
                }
            }
        }
    }
}

void printer(SudokoCell_t SudokoTable[][SIZE])
{
    /*
    - Either print to the console or export a new csv file
*/

    // std::cout << "\n----------------------------------\n";

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            std::cout << SudokoTable[i][j].value << " ";
            if (j == 2 || j == 5)
            {
                std::cout << "| ";
            }
        }
        std::cout << "\n";
        if (i == 2 || i == 5)
        {
            std::cout << "------+-------+-------\n";
        }
    }
    std::cout << "\n";
};

void printerPossibilities(SudokoCell_t SudokoTable[][SIZE])
{
    /*
    - Either print to the console or export a new csv file
*/

    // std::cout << "\n----------------------------------\n";

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            
            for (size_t k = 0; k < SIZE; k++)
            {
                std::cout << SudokoTable[i][j].possibleSolutions[k] << "-";
            }
            std::cout << " | ";
        }
        std::cout << "\n";
        if (i == 2 || i == 5)
        {
            std::cout << "------+-------+-------\n";
        }
    }
    std::cout << "\n";
};

int main(int argc, char *argv[])
{

    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    std::string fileName = "unsolved.csv";

    // Parse the input
    parser(fileName, SudokoTable);

    // Print the unsolved Sudoko
    std::cout << "-----INPUT------\n";
    printer(SudokoTable);

    // Solve the Sudoko
    solver(SudokoTable);

    // Print the solved Sudoko
    std::cout << "-----OUTPUT-----\n";
    printer(SudokoTable);

    printerPossibilities(SudokoTable);

    return 0;
}
