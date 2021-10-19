#include "Printer.h"
#include "Solver.h"

/* 
    - Read in a text file to a string [4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......]
    - Check: Must be exact 81 digits
    - Parse the text file into an 2D array
    - By creating a new instance of struct SudokoCell
    - Update SudokoCell->value
*/
void parser( const std::string &fileName, Sudoku _SudokoTable ){
    std::ifstream file(fileName);

    if ( file.is_open() ){
        std::vector<int> numbers;                   // Replace with SudokuTable
        char input;
        while (file >> input){
            if (isdigit(input)){
                numbers.push_back(static_cast<int>(input - 48));
            }
            else if (input == '.'){
                numbers.push_back(static_cast<int>(0));
            }           
        }
        // Need a check if size == 81
        size_t row = 0, col = 0;
        for (size_t k = 0; k < numbers.size(); k++){
            _SudokoTable[row][col].value = numbers[k];
            col++;
            if (!(k + 1) % 9){                      // Takes care of new a row in the table
                row++;
                col = 0;
            }
        }
        file.close();
    }
    else {
        std::cout << "nothing..\n";
    };
};

// void printer(SudokoCell_t SudokuTable[][SIZE]){
// void printer(Sudoku _SudokoTable){
//     /*
//     - Either print to the console or export a new csv file
//     */
//     for (size_t i = 0; i < SIZE; i++){
//         for (size_t j = 0; j < SIZE; j++){
//             std::cout << _SudokoTable[i][j].value << " ";
//             if (j == 2 || j == 5)
//             {
//                 std::cout << "| ";
//             }
//         }
//         std::cout << "\n";
//         if (i == 2 || i == 5){
//             std::cout << "------+-------+-------\n";
//         }
//     }
//     std::cout << "\n";
// };
void printer(Sudoku _SudokoTable){
    std::cout << "\x1B[0m" << "\n----------------------------------+---------------INPUT---------------+----------------------------------\n";
    for (size_t i = 0; i < SIZE; i++){
        for (size_t j = 0; j < SIZE; j++) {
            if( _SudokoTable[i][j].value == 0 ){
                std::cout << "\x1B[31m" << "     " << _SudokoTable[i][j].value << "     ";
            }
            if( _SudokoTable[i][j].value != 0 ){
                std::cout << "\x1B[0m" << "     " << _SudokoTable[i][j].value << "     ";
            }
            if (j == 2 || j == 5){
                std::cout << "\x1B[0m" << " | ";
            }
        }
        std::cout << "\n";
        if (i == 2 || i == 5){
            std::cout << "\x1B[37m" << "----------------------------------+-----------------------------------+----------------------------------\n";
        }
    }
    std::cout << "\x1B[0m" << std::endl;
};

void printer(Sudoku _SudokoTable, Sudoku _InpTable){
    std::cout << "\x1B[0m" << "\n----------------------------------+---------------OUTPUT--------------+----------------------------------\n";
    for (size_t i = 0; i < SIZE; i++){
        for (size_t j = 0; j < SIZE; j++) {
            if( _InpTable[i][j].value == _SudokoTable[i][j].value ){
                if( _SudokoTable[i][j].value == 0 ){
                    std::cout << "\x1B[31m" << "[";
                    for (size_t k = 0; k < SIZE; k++){
                        if( _SudokoTable[i][j].possibleSolutions[k] == 0){
                            std::cout << "_";
                        }
                        else {
                            std::cout << "\x1B[31m" << k+1 << "";
                        }
                    }
                    std::cout << "\x1B[31m" << "]";
                }
                else{
                    std::cout << "\x1B[90m" << "     " << _SudokoTable[i][j].value << "     ";
                }
            }
            else{
                std::cout << "\x1B[32m" << "     " << _SudokoTable[i][j].value << "     ";
            }
            if (j == 2 || j == 5){
                std::cout << "\x1B[0m" << " | ";
            }
        }
        std::cout << "\n";
        if (i == 2 || i == 5){
            std::cout << "\x1B[37m" << "----------------------------------+-----------------------------------+----------------------------------\n";
        }
    }
    std::cout << "\x1B[0m" << std::endl;
};


void printCell(Sudoku SudokuTable, int &row, int &col){
    std::cout << SudokuTable[row][col].value << "\n\n";
}