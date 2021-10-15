#include "Solver.h"
#include "Printer.h"


int main(int argc, char *argv[])
{

    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    // std::string fileName = "input/unsolved.csv";
    // std::string fileName = "input/marie.txt";
    // std::string fileName = "input/sudoko.txt";
    // std::string fileName = "input/suduko_easy.csv";
    std::string fileName = "input/suduko1.csv";
    // std::string fileName = "input/suduko2.csv";
    // std::string fileName = "input/suduko3.csv";
    // std::string fileName = "input/suduko4.csv";

    // Parse the input
    parser(fileName, SudokoTable);

    SudokoCell_t InpTable[SIZE][SIZE];
    parser(fileName, InpTable);


    // Print the unsolved Sudoko
    std::cout << "\n\n";
    std::cout << "------- INPUT -------\n";
    printer(SudokoTable);

    // Solve the Sudoko
    solver(SudokoTable);
    // solver(SudokoTable);
    // solver(SudokoTable);
    // solver(SudokoTable);
    // solver(SudokoTable);

    std::cout << "\n\n";
    // Print the solved Sudoko
    std::cout << "------- OUTPUT ------\n";
    // printer(SudokoTable);

    printerPossibilities(SudokoTable, InpTable);
    std::cout << "\n\n";


    return 0;
}
