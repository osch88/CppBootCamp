#include "Solver.h"
#include "Printer.h"


int main(int argc, char *argv[])
{

    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    SudokoCell_t InpTable[SIZE][SIZE];
    // std::string fileName = "input/unsolved.csv";
    // std::string fileName = "input/marie.txt";
    // std::string fileName = "input/sudoko.txt";
    std::string fileName = "input/suduko_easy.csv";
    // std::string fileName = "input/suduko1.csv";
    // std::string fileName = "input/suduko2.csv";
    // std::string fileName = "input/suduko3.csv";
    // std::string fileName = "input/suduko4.csv";
    // std::string fileName = "input/sudoko5.csv";

    // Parse the input
    parser(fileName, SudokoTable);
    parser(fileName, InpTable);

    // Print the unsolved Sudoko
    std::cout << "\n\n";
    std::cout << "------- INPUT -------\n";
    printer(SudokoTable);

    // Solve the Sudoko
    if(solver(SudokoTable)){
        std::cout << "\nSudoku solved the easy way\n" << std::endl;
    }
    else if( bruteForce(SudokoTable, 0, 0) ){
        std::cout << "\nSudoku solved with brute force\n" << std::endl;
    }
    else {
        std::cout << "\nSudoku totally impossible\n" << std::endl;
    }
    printerPossibilities(SudokoTable, InpTable);    
    std::cout << "\n\n";


    return 0;
}
