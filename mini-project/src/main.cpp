#include "Solver.h"
#include "Printer.h"
#include <chrono>

int main(int argc, char *argv[])
{
    std::cout << "WELCOME TO SUDOKU SOLVER!\n\n";
    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    SudokoCell_t InpTable[SIZE][SIZE];

    std::string filename = "data/input/sudoku.txt";

    std::vector<std::string> allSudokus;
    if (gettingLine(filename, allSudokus))
    {
        for (std::string &oneLine : allSudokus)
        {
            // Clock the performance
            auto start = std::chrono::high_resolution_clock::now();

            std::cout << oneLine << std::endl;
            // Solve the Sudoko
            if (parser(oneLine, SudokoTable))
            {
                
                // Make a copy
                parser(oneLine, InpTable);
                // Print the unsolved Sudoko
                // printer(SudokoTable);
                
                if (constraint_propagation(SudokoTable))
                {
                    easyPrinter(SudokoTable, InpTable);
                    std::cout << "Sudoku solved with CONSTAIN PROPOGATION\n"
                              << std::endl;
                }
                else
                {
                    // printer(SudokoTable, InpTable, "CONSTR");

                    if (bruteForce(SudokoTable, 0, 0))
                    {
                        easyPrinter(SudokoTable, InpTable);
                        std::cout << "Sudoku solved with BRUTE FORCE\n";
                        iterationPrint();
                    }
                    else
                    {
                        std::cout << "Sudoku totally IMPOSSIBLE to solve\n"
                                  << std::endl;
                    }
                    // Print the solved Sudoko
                    // printer(SudokoTable, InpTable, "OUTPUT");
                }
            }
            else
            {
                std::cout << "Could not parse the input file" << std::endl;
            }

            // Clock the performance
            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

            std::cout << "Timestamp:\t" << duration.count() << " milliseconds\n" << std::endl;
        }
    }

    return 0;
}
