#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>

#include "solver.h"

const unsigned int SIZE = 9;


typedef struct SudokoCell
{
    char            value;
    bool            possibleSolutions[SIZE] = {1,1,1,1,1,1,1,1};
}SudokoCell_t;


void parser(const std::string &fileName, SudokoCell_t SudokoTable[][SIZE]){
    /* 
        - Read in a csv file to a string
        - Check: Must be exact 81 digits
        - Parse the csv file into an 2D array
        - By creating a new instance of struct SudokoCell
        - Update SudokoCell->value
    */
    // bool success = false;
    std::ifstream file(fileName);

    if( file.is_open() ){

        std::vector<char> numbers; // Replace with SudokoTable
        char input;
        while ( file >> input )
        {
            if( isdigit(input) ){ numbers.push_back(input); }
        }
        // Need a check if size == 81
        size_t row = 0; size_t col = 0;
        for (size_t k = 0; k < numbers.size(); k++)
        {
            SudokoTable[row][col].value = numbers[k];
            col++;
            if( !(k+1)%9 ){ // Takes care of new a row in the table
                row++;
                col = 0;
            }
        }

        file.close();
        // success = true;
    }
    else{
        std::cout << "nothing..\n";
        // success = false;
    };

    // return success;

};


void checkRow(SudokoCell_t SudokoTable[][SIZE], const int &row){
    int tmp;
    for (size_t i = 0; i < SIZE; i++){
        if(SudokoTable[row][i].value != 0){
            tmp = SudokoTable[row][i].value;
            SudokoTable[row][i].possibleSolutions[tmp-1] = false;
        };
    }    
};


void checkColumn(SudokoCell_t SudokoTable[][SIZE], const int &col){
    int tmp;
    for (size_t i = 0; i < SIZE; i++){
        if(SudokoTable[i][col].value != 0){
            tmp = SudokoTable[i][col].value;
            SudokoTable[i][col].possibleSolutions[tmp-1] = false;
        };
    }

};


void checkBox(SudokoCell_t SudokoTable[][SIZE], const int &row, const int &col){
    int tmp;
    for (size_t i = 0; i < 3; i++){
        for (size_t j = 0; j < 3; j++){
            tmp = SudokoTable[3*(row - row%3)/3 + i][3*(col - col%3)/3 + j].value;
            if( tmp !=0 ){
                SudokoTable[3*(row - row%3)/3 + i][3*(col - col%3)/3 + j].possibleSolutions[tmp-1] = false;
            }
        }
    }
};


bool solver(SudokoCell_t SudokoTable[][SIZE]);
/*
    - Find all possible solutions if SudokoCell->value = 0
        - Check row for possible values
        - Check column for possible values
        - Check 3x3 square for possible values
        - Update SudokoCell->possibleSolutions
    - Iterate!
    - Return possibleSolutions which is hopefully the solution or close to
*/


void printer(SudokoCell_t SudokoTable[][SIZE]){
/*
    - Either print to the console or export a new csv file
*/

    std::cout << "\n----------------------------------\n";

    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            std::cout << SudokoTable[i][j].value << " ";
            if( j!=8 ){
                std::cout << "| ";
            }
        }
        std::cout << "\n----------------------------------\n";
    }
    std::cout << "\n";

};


int main(int argc, char *argv[]){

    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    std::string fileName = "unsolved.csv";

    // Parse the input
    parser(fileName, SudokoTable);
    // Print the unsolved Sudoko
    printer(SudokoTable);
    // Solve the Sudoko
    // solver(SudokoTable);
    // Print the solved Sudoko
    // printer(SudokoTable);

    checkRow(SudokoTable, 0);
    checkColumn(SudokoTable, 2);
    checkBox(SudokoTable, 0, 2);

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << SudokoTable[0][2].possibleSolutions[i] << " ";
    }
    std::cout << "\n\n";
    


    return 0;
}
