#include "puzzle.h"

Puzzle::Puzzle(const std::string &_SudokuLine) {
    SudokuLine = _SudokuLine;
    solver();
}

void Puzzle::solver(){
    if( parser() ){
/*
        std::cout << "Input Sudoko:\t\t";
        printSudokuOnOneLine();
        std::cout << std::endl;
*/
        constraintPropagation();
        constraintPropagation();
        // constraintPropagation();
        // constraintPropagation();
        // print();
/*
        if( constraintPropagation() ){
            solved = "Constrain Propogation";
            std::cout << "Constrain Propogation:\t";
            print();
            std::cout << std::endl;
        }
        else{
            std::cout << "Constrain Propogation:\t";
            printSudokuOnOneLine();
            std::cout << std::endl;

            if( search(0,0) ){
                solved = "Brute force";
                std::cout << "Bruteforce:\t\t";
                printSudokuOnOneLine();
                std::cout << std::endl;
            }
            else {
                solved = "No solution";
            }
        }
        std::cout << "Solver:\t" << solved << std::endl;
*/
    }
    else {
        std::cout << "Could not parse the input" << std::endl;
    }
}

bool Puzzle::parser(){
    bool solved = false;
    std::vector<int> numbers;

    for (char &input : SudokuLine) {
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
            SudokuTable[row][col].initiatedValue = numbers[k];
            if( numbers[k] != 0 ){
                SudokuTable[row][col].valueSet = true;
                valueSetCounter++;
            }
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

void Puzzle::hypoRow(const unsigned int &row, const unsigned int &col) {
    for (size_t i = 0; i < SIZE; i++) {
        if( SudokuTable[row][i].value != 0 ) {
            unsigned int value = SudokuTable[row][i].value;
            SudokuTable[row][col].hypoBits.reset(value-1);
        }
    }
    SudokuTable[row][col].noHypos = SudokuTable[row][col].hypoBits.count();
    if ( SudokuTable[row][col].noHypos == 1 && SudokuTable[row][col].valueSet == false){
        setValueToCell(row, col);
    }
}

void Puzzle::hypoColumn(const unsigned int &row, const unsigned int &col) {
    for (size_t i = 0; i < SIZE; i++) {
        if( SudokuTable[i][col].value != 0 ) {
            unsigned int value = SudokuTable[i][col].value;
            SudokuTable[row][col].hypoBits.reset(value-1);
        }
    }
    SudokuTable[row][col].noHypos = SudokuTable[row][col].hypoBits.count();
    if ( SudokuTable[row][col].noHypos == 1 && SudokuTable[row][col].valueSet == false){
        setValueToCell(row, col);
    }
}

void Puzzle::hypoBox(const unsigned int &row, const unsigned int &col) {
    unsigned tmp_row;
    unsigned tmp_col;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            tmp_row = (row - row % 3) + i;
            tmp_col = (col - col % 3) + j;   
            if( SudokuTable[tmp_row][tmp_col].value != 0 ){
                unsigned int value = SudokuTable[tmp_row][tmp_col].value;
                SudokuTable[row][col].hypoBits.reset(value-1);
            }
        }
    }
    SudokuTable[row][col].noHypos = SudokuTable[row][col].hypoBits.count();
    if ( SudokuTable[row][col].noHypos == 1 && SudokuTable[row][col].valueSet == false){
        setValueToCell(row, col);
    }
}

unsigned int Puzzle::findUniqueHypoValue(const unsigned int &row, const unsigned int &col){
    unsigned int value = 0;
    for (size_t i = SIZE; i > 0; i--) {
        if( SudokuTable[row][col].hypoBits[i-1] == 1 ){
            value = i;
            break;
        }
    }
    return value;
}

unsigned int Puzzle::findUniquePeerValue(const unsigned int &row, const unsigned int &col){
    unsigned int value = 0;
    for (size_t i = SIZE; i > 0; i--) {
        if( SudokuTable[row][col].peers[i-1] == 1 ){
            value = i;
            break;
        }
    }
    return value;
}

void Puzzle::setValueToCell(const unsigned int &row, const unsigned int &col){
    if (SudokuTable[row][col].valueSet == false) {
        unsigned int value = findUniqueHypoValue(row, col);
        SudokuTable[row][col].value = value;
        SudokuTable[row][col].valueSet = true;
        valueSetCounter++;
        runUnits(row, col);
        updateHypos(row, col);
    }
}

void Puzzle::setValueToCellPeer(const unsigned int &row, const unsigned int &col){
    if (SudokuTable[row][col].valueSet == false) {
        unsigned int value = findUniquePeerValue(row, col);
        // std::cout << "Value: " << value << std::endl;
        SudokuTable[row][col].value = value;
        SudokuTable[row][col].valueSet = true;
        valueSetCounter++;
        runUnits(row, col);
        updateHypos(row, col);
        // print();

    }

}

void Puzzle::runUnits(const unsigned int &row, const unsigned int &col){
    for (size_t i = 0; i < SIZE; i++) {
        hypoRow(row, i);
        hypoColumn(i, col);
        findUniquePeer(row, i);
        findUniquePeer(i, col);
    }
    unsigned tmp_row;
    unsigned tmp_col;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            tmp_row = (row - row % 3) + i;
            tmp_col = (col - col % 3) + j;
            hypoBox(tmp_row, tmp_col);
            // findUniquePeerValue(tmp_row, tmp_col);
        }
    }
}

void Puzzle::updateHypos(const unsigned int &row, const unsigned int &col){

    hypoRow( row, col );
    hypoColumn( row, col );
    hypoBox( row, col );    // Only checking the one cell that are calling the function...
    // findUniquePeer(row, col);    
}

bool Puzzle::constraintPropagation() {
    std::cout << "\n\n---------------------INPUT-----------------\n\n";
    print();
    for (size_t row = 0; row < SIZE; row++){
        for (size_t col = 0; col < SIZE; col++){
            if (SudokuTable[row][col].valueSet == false && valueSetCounter != 81){
                updateHypos(row, col);
            }
        }
    }

    std::cout << "\n\n---------------------CONSTRAINED-----------------\n\n";
    print();
    std::cout << "\n\n---------------------2nd LAW-----------------\n\n";

    for (size_t row = 0; row < SIZE; row++){
        for (size_t col = 0; col < SIZE; col++){
            if (SudokuTable[row][col].valueSet == false && valueSetCounter != 81){
                findUniquePeer(row, col);
            }
        }
    }

    std::cout <<  "Numbers of solved cells: " << valueSetCounter << std::endl;

    return true;
}

void Puzzle::valueInRow(const unsigned int &row, const unsigned int &col){
    for (size_t i = 0; i < SIZE; i++) {
        if( col == i) continue;   // Don't include the calling cell in the peers
        else if( SudokuTable[row][i].valueSet == true) {
            unsigned value = SudokuTable[row][i].value;
            SudokuTable[row][col].peers.set(value-1);
            // std::cout << row << "-" << i << "now set to: " << value << "\n";
        }
        else {
            SudokuTable[row][col].peers = SudokuTable[row][col].peers | SudokuTable[row][i].hypoBits;
        }
    }
    SudokuTable[row][col].peers.flip();
    SudokuTable[row][col].peers = (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers);
    
    if( SudokuTable[row][col].peers.count() == 1 ){

        // std::cout << "Unique: [ " << row << " - " << col << " ]\n";
        // std::cout << "Hypos:\t" << SudokuTable[row][col].hypoBits << std::endl;
        // std::cout << "Peers:\t" << SudokuTable[row][col].peers << std::endl;
        // std::cout << "Unique:\t" << (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers) << std::endl;
        // std::cout << "Unique:\t" << (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers).count() << std::endl;
        setValueToCellPeer(row, col);
    }
}
void Puzzle::valueInCol(const unsigned int &row, const unsigned int &col){
    for (size_t i = 0; i < SIZE; i++) {
        if( row == i) continue;        // Don't include the calling cell in the peers
        else if( SudokuTable[i][col].valueSet == true) {
            unsigned value = SudokuTable[i][col].value;
            SudokuTable[row][col].peers.set(value-1);
        }
        else {
            SudokuTable[row][col].peers = SudokuTable[row][col].peers | SudokuTable[i][col].hypoBits;
        }
    }
    SudokuTable[row][col].peers.flip();
    SudokuTable[row][col].peers = (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers);
    
    if( SudokuTable[row][col].peers.count() == 1 ){

        // std::cout << "Unique: [ " << row << " - " << col << " ]\n";
        // std::cout << "Hypos:\t" << SudokuTable[row][col].hypoBits << std::endl;
        // std::cout << "Peers:\t" << SudokuTable[row][col].peers << std::endl;
        // std::cout << "Unique:\t" << (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers) << std::endl;
        // std::cout << "Unique:\t" << (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers).count() << std::endl;
        setValueToCellPeer(row, col);
    }
}
void Puzzle::valueInBox(const unsigned int &row, const unsigned int &col){
    bool success = false;
    unsigned tmp_row;
    unsigned tmp_col;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            tmp_row = (row - row % 3) + i;
            tmp_col = (col - col % 3) + j;

            if( ( tmp_row == row ) && ( tmp_col == col) ) continue;     // Do not overide the asking cell
            else if( SudokuTable[tmp_row][tmp_col].valueSet == true ){

                // std::cout << "[" << tmp_row << ", " << tmp_col << "] ";


                unsigned int value = SudokuTable[tmp_row][tmp_col].value;
                SudokuTable[row][col].peers.set(value-1);
            }
            else {

                // std::cout << "[" << tmp_row << ", " << tmp_col << "] ";

                SudokuTable[row][col].peers = SudokuTable[row][col].peers | SudokuTable[tmp_row][tmp_col].hypoBits; 
            }
        }
        // std::cout << "\n";
    }
    SudokuTable[row][col].peers.flip();
    SudokuTable[row][col].peers = (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers);
    
    if( SudokuTable[row][col].peers.count() == 1 ){

        // std::cout << "Unique: [ " << row << " - " << col << " ]\n";
        // std::cout << "Hypos:\t" << SudokuTable[row][col].hypoBits << std::endl;
        // std::cout << "Peers:\t" << SudokuTable[row][col].peers << std::endl;
        // std::cout << "Unique:\t" << (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers) << std::endl;
        // std::cout << "Unique:\t" << (SudokuTable[row][col].hypoBits & SudokuTable[row][col].peers).count() << std::endl;
        setValueToCellPeer(row, col);

    }
}

void Puzzle::findUniquePeer(const unsigned int &row, const unsigned int &col){
    SudokuTable[row][col].peers.reset();
    valueInRow(row, col);
    SudokuTable[row][col].peers.reset();
    valueInCol(row, col);
    SudokuTable[row][col].peers.reset();
    valueInBox(row, col);
}


bool Puzzle::search(unsigned int _row, unsigned int _col) {
    // bool success = false;

    // if ( _row == 8 && _col == 9 ) {
    //     return true;
    // }
    // if ( _col == 9 ) {
    //     _row++;
    //     _col = 0;
    // }
    // // If the cells value is NOT 0, then move on to the next one
    // if( SudokuTable[_row][_col].value != 0 ){
    //     return search( _row, _col + 1);
    // }
    // // Check possible solutions for this cell before brute forcing
    // bool peers[SIZE] = {1,1,1,1,1,1,1,1,1}; // TODO: look into use bits instead of looping array

    // checkRow( peers, _row);
    // checkCol( peers, _col);
    // checkBox( peers, _row, _col);

    // for (size_t i = 0; i < SIZE; i++) {
    //     if( peers[i] == 1 ){
    //         SudokuTable[_row][_col].value = i+1;
    //         if( search(_row, _col+1) ){
    //             success = true;
    //             // break;
    //             return true;
    //         }
    //     }
    // }
    // SudokuTable[_row][_col].value = 0;
    return false;
}

void Puzzle::printSudokuOnOneLine() {
    unsigned stringIndex = 0;
    for (size_t _row = 0; _row < SIZE; _row++) {
        for (size_t _col = 0; _col < SIZE; _col++) {
            if( (SudokuTable[_row][_col].value == 0)  ) {
                std::cout << "\x1B[0m"
                          << ".";
            }
            else if( SudokuTable[_row][_col].value == SudokuTable[_row][_col].initiatedValue ) {  // IF same value in solution as in input
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

void Puzzle::print() {
    for (size_t _row = 0; _row < SIZE; _row++) {
        for (size_t _col = 0; _col < SIZE; _col++) {
            if ( SudokuTable[_row][_col].valueSet == false ) {
                std::cout   << "\x1B[31m"
                            << "[";
                for (size_t i = SIZE; i > 0; i--) {
                    if ( SudokuTable[_row][_col].hypoBits[i-1] == 1 ){
                        std::cout << i;
                    }
                    else {
                        std::cout << "_";
                    }
                    // std::cout << i;
                }                
                std::cout   << "]";
            }
            else {
                if( SudokuTable[_row][_col].value == SudokuTable[_row][_col].initiatedValue ){
                    std::cout << "\x1B[0m"
                              << "     " << SudokuTable[_row][_col].value << "     ";
                }
                else {
                    std::cout << "\x1B[32m"
                              << "     " << SudokuTable[_row][_col].value << "     ";
                }
            }
            if (_col == 2 || _col == 5) {
                std::cout << "\x1B[0m"
                          << " | ";
            }
        }
        std::cout << "\n";
        if (_row == 2 || _row == 5) {
            std::cout << "\x1B[37m"
                      << "----------------------------------+-----------------------------------+----------------------------------\n";
        }
    }
    std::cout << "\x1B[0m" << std::endl;
};

std::string Puzzle::checkSolutionStatus(){
    std::cout << solved << std::endl;
    return solved;
}
