#include "Solver.h"
#include "Printer.h"




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
