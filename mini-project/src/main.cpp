#include "Solver.h"
#include "Printer.h"
#include <chrono>

// Used to count how many iterations are needed for Brute force
extern int global_iterations;


int main(int argc, char *argv[])
{
    // Clock the performance
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "WELCOME TO SUDOKU SOLVER!\n\n";
    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    SudokoCell_t InpTable[SIZE][SIZE];

    std::string filename = "data/input/random.txt";                     // <-- @RASHID, CHANGE TARGET TO RIGHT SUDOKU FILE

    std::vector<std::string> allSudokus;
    if (gettingLine(filename, allSudokus))
    {
        unsigned line = 1;
        for (std::string &oneLine : allSudokus)
        {
            // Clock the performance
            auto start = std::chrono::high_resolution_clock::now();

            std::cout << "Line no: " << line++ << std::endl;
            std::cout << "Unsolved:\t" << oneLine << std::endl;
            // Solve the Sudoko
            if (parser(oneLine, SudokoTable))
            {
                // Make a copy as reference
                parser(oneLine, InpTable);
                // Do constaint propagation and then print out how far we have reached.   
                auto constrainOK = constraint_propagation(SudokoTable);
                std::cout << "Const. Prop:\t";
                printSudokuOnOneLine(SudokoTable, InpTable);

                if (!constrainOK) {
                    if (bruteForce(SudokoTable, 0, 0)) {
                        std::cout << "Brute Force:\t";
                        printSudokuOnOneLine(SudokoTable, InpTable);
                        std::cout << "Solver:\t\tBRUTE FORCE\n";
                        iterationPrint();
                    }
                    else {
                        std::cout << "Sudoku totally IMPOSSIBLE to solve\n"
                                  << std::endl;
                    }
                }
                else {
                    std::cout << "Solver:\t\tCONSTRAIN PROPOGATION\n";
                }
            }
            else {
                std::cout << "Could not parse the input file" << std::endl;
            }

            // Clock the performance
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

            std::cout << "Timestamp:\t" << duration.count() << " milliseconds\n" << std::endl;

            ::global_iterations = 0;
        }
    }

    // Clock the performance
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Time in total:\t" << duration.count() << " milliseconds\n" << std::endl;

    return 0;
}
