#include "Solver.h"
#include "Printer.h"
#include <chrono>


int main(int argc, char *argv[])
{
        
    // Define some variables
    Sudoku SudokoTable;
    Sudoku InpTable;

    // std::string fileName = "input/unsolved.csv";             // 0 ms
    // std::string fileName = "input/marie.txt";                // 0 ms
    std::string fileName = "input/sudoko.txt";               // 9765 ms -> 1317 ms
    // std::string fileName = "input/suduko_easy.csv";          // 0 ms
    // std::string fileName = "input/suduko1.csv";              // 0 ms
    // std::string fileName = "input/suduko2.csv";              // 250 ms -> 34 ms
    // std::string fileName = "input/suduko3.csv";              // 184 ms -> 28 ms
    // std::string fileName = "input/suduko4.csv";              // 65779 ms -> 9478 ms
    // std::string fileName = "input/sudoko5.csv";              // 0 ms
    // std::string fileName = "input/evil.txt";              // 0 ms

    // Clock the performance
    auto start = std::chrono::high_resolution_clock::now();

    // Solve the Sudoko
    if( parser(fileName, SudokoTable) ){
        // Make a copy
        parser(fileName, InpTable);
        // Print the unsolved Sudoko
        printer(SudokoTable);
        if(constraint_propagation(SudokoTable)){
            std::cout << "\nSudoku solved the easy way\n" << std::endl;
        }
        else {
            printer(SudokoTable, InpTable, "CONSTR");
            
            if( bruteForce(SudokoTable, 0, 0) ){
                std::cout << "\nSudoku solved with brute force\n" << std::endl;
            }
            else {
                std::cout << "\nSudoku totally impossible to solve\n" << std::endl;
            }

            // Print the solved Sudoko
            printer(SudokoTable, InpTable, "OUTPUT");    
            std::cout << "\n\n";
        }
    }
    else {
        std::cout << "Could not parse the input file" << std::endl;
    }

    // Clock the performance
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "\n\nTimestamp: " << duration.count() << " milliseconds\n" << std::endl;
    
    return 0;
}
