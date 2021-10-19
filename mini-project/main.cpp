#include "Solver.h"
#include "Printer.h"
#include <chrono>


int main(int argc, char *argv[])
{
    // Clock the performance
    auto start = std::chrono::high_resolution_clock::now();
    
    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    SudokoCell_t InpTable[SIZE][SIZE];
    // std::string fileName = "input/unsolved.csv";
    // std::string fileName = "input/marie.txt";
    // std::string fileName = "input/sudoko.txt";
    // std::string fileName = "input/suduko_easy.csv";
    // std::string fileName = "input/suduko1.csv";
    std::string fileName = "input/suduko2.csv";
    // std::string fileName = "input/suduko3.csv";
    // std::string fileName = "input/suduko4.csv";
    // std::string fileName = "input/sudoko5.csv";

    // Parse the input
    parser(fileName, SudokoTable);
    parser(fileName, InpTable);

    // Print the unsolved Sudoko
    std::cout << "\n\n------- INPUT -------\n";
    printer(SudokoTable);

    // Print the constraint_propagation Sudoku
    // printer(SudokoTable, InpTable);
    // constraint_propagation(SudokoTable);

    // Solve the Sudoko
    if(constraint_propagation(SudokoTable)){
        std::cout << "\nSudoku solved the easy way\n" << std::endl;
    }
    else if( bruteForce(SudokoTable, 0, 0) ){
        std::cout << "\nSudoku solved with brute force\n" << std::endl;
    }
    else {
        std::cout << "\nSudoku totally impossible\n" << std::endl;
    }
    printer(SudokoTable, InpTable);    
    std::cout << "\n\n";


    // Clock the performance
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "\n\nTimestamp: " << duration.count() << " milliseconds\n" << std::endl;
    
    return 0;
}
