#include "puzzle.h"

Puzzle::Puzzle(const std::string &_SudokuLine) {
    SudokuLine = _SudokuLine;
    solver();
}

void Puzzle::solver(){
    if( parser() ){
        
        std::cout << "Input Sudoko:\t\t\t";
        printSudokuOnOneLine();
        std::cout << std::endl;

        if( constraintPropagation() ){
            solved = "Constrain Propogation";
            std::cout << "Constrain Propogation:\t\t";
            printSudokuOnOneLine();
            std::cout << std::endl;
        }
        else{
            std::cout << "Constrain Propogation:\t\t";
            printSudokuOnOneLine();
            std::cout << std::endl;

            if( bruteForce(0,0) ){
                solved = "Brute force";
                std::cout << "Bruteforce:\t\t\t";
                printSudokuOnOneLine();
                std::cout << std::endl;
            }
            else {
                solved = "No solution";
            }
        }
        std::cout << "Solver:\t" << solved << std::endl;
    }
    else {
        std::cout << "Could not parse the input" << std::endl;
    }
}

bool Puzzle::parser(){
    bool solved = false;
    std::vector<int> numbers;
    for (char input : SudokuLine) {
        if (isdigit(input)) {
            numbers.push_back(static_cast<int>(input - 48));
        }
        else if (input == '.') {
            numbers.push_back(static_cast<int>(0));
        }
    }
    // Need a check if size == 81
    if (numbers.size() != 81){
        solved = false;
    }
    else {
        size_t row = 0, col = 0;
        for (size_t k = 0; k < numbers.size(); k++) {
            SudokuTable[row][col].value = numbers[k];
            col++;
            if (!(k + 1) % 9) { // Takes care of new a row in the table
                row++;
                col = 0;
            }
        }
        solved = true;
    }
    return solved;
}

void Puzzle::checkRow(bool _peers[SIZE], const unsigned int &row) {
    for (size_t i = 0; i < SIZE; i++) {
        if( SudokuTable[row][i].value != 0 ) {
            int tmp = SudokuTable[row][i].value;
            _peers[tmp - 1] = false;
        }
    }
}

void Puzzle::checkCol(bool _peers[SIZE], const unsigned int &col) {
    for (size_t i = 0; i < SIZE; i++) {
        if (SudokuTable[i][col].value != 0) {
            int tmp = SudokuTable[i][col].value;
            _peers[tmp - 1] = false;
        }
    }
}

void Puzzle::checkBox(bool _peers[SIZE], const unsigned int &row, const unsigned int &col) {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            int tmp = SudokuTable[(row - row % 3) + i][ (col - col % 3) + j].value;
            if (tmp != 0) {
                _peers[tmp - 1] = false;
            }
        }
    }
}

void Puzzle::checkUnits(const unsigned int &row, const unsigned int &col){

    bool peers[SIZE] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    checkRow( peers, row );
    checkCol( peers, col );
    checkBox( peers, row, col );
}

bool Puzzle::checkIfSolved(){
    bool solved = true;
    for (size_t row = 0; row < SIZE; row++){
        for (size_t col = 0; col < SIZE; col++){
            if (SudokuTable[row][col].value == 0){ 
                solved = false;
            }
        }
    }
    return solved;
}

bool Puzzle::constraintPropagation() {
  
    bool game = true, solved = true;
    while (game) {
        game = false;
        for (size_t row = 0; row < SIZE; row++){
            for (size_t col = 0; col < SIZE; col++){
                if (SudokuTable[row][col].value == 0){
                    bool peers[SIZE] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
                    // bool _possibleSolution = SudokuTable[row][col].possibleSolutions[SIZE]; // TODO: would be nice to avoid creating another bool array...
                    checkRow( peers, row);
                    checkCol( peers, col);
                    checkBox( peers, row, col);

                    int solutions = 0;                  // Varible that counts possible solutions in each cell aka possibleSolutions array
                    int location = 0;                   // Where in the array the solution exist. 0 = 1, 1 = 2 etc // TODO: look into use bits instead of looping array

                    for (size_t i = 0; i < SIZE; i++) {
                        if (peers[i] != 0) {
                            solutions++;
                            location = i;
                        }
                    }
                    if(solutions == 1) {
                        SudokuTable[row][col].value = location + 1; // If only one solution then this as .value
                        game = true;
                    }
                    else {
                        for (size_t i = 0; i < SIZE; i++) {
                            SudokuTable[row][col].possibleSolutions[i] = peers[i];
                        }
                    }
                }
            }
        }
    }
    return checkIfSolved();
}

bool Puzzle::bruteForce(unsigned int _row, unsigned int _col) {
    bool success = false;

    if ( _row == 8 && _col == 9 ) {
        return true;
    }
    if ( _col == 9 ) {
        _row++;
        _col = 0;
    }
    // If the cells value is NOT 0, then move on to the next one
    if( SudokuTable[_row][_col].value != 0 ){
        return bruteForce( _row, _col + 1);
    }
    // Check possible solutions for this cell before brute forcing
    bool peers[SIZE] = {1,1,1,1,1,1,1,1,1}; // TODO: look into use bits instead of looping array

    checkRow( peers, _row);
    checkCol( peers, _col);
    checkBox( peers, _row, _col);

    for (size_t i = 0; i < SIZE; i++) {
        if( peers[i] == 1 ){
            SudokuTable[_row][_col].value = i+1;
            if( bruteForce(_row, _col+1) ){
                success = true;
                // break;
                return true;
            }
        }
    }
    SudokuTable[_row][_col].value = 0;
    return false;
}

void Puzzle::printSudokuOnOneLine() {
    unsigned stringIndex = 0;
    for (size_t _row = 0; _row < SIZE; _row++) {
        for (size_t _col = 0; _col < SIZE; _col++) {
            char now = SudokuLine[stringIndex];
            if( (SudokuTable[_row][_col].value == 0)  ) { //TODO: Not working
                std::cout << "\x1B[0m"
                          << ".";
            }
            else if( ( SudokuTable[_row][_col].value == (now - 48) ) ) {  // IF same value in solution as in input
                std::cout << "\x1B[0m"
                          << SudokuTable[_row][_col].value;
            }
            
            else {
                std::cout << "\033[1m\033[32m"
                          << SudokuTable[_row][_col].value;
            }
            stringIndex++;
        }
    }
    std::cout << "\x1B[0m";
}

std::string Puzzle::checkSolutionStatus(){
    std::cout << solved << std::endl;
    return solved;
}
