#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>

const unsigned int SIZE = 9;


typedef struct SudokoCell
{
    char            value;
    bool            possibleSolutions[SIZE];
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


void solver();
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
   for (size_t i = 0; i < SIZE; i++)
   {
       for (size_t j = 0; j < SIZE; j++)
       {
           std::cout << SudokoTable[i][j].value << " ";
       }
       std::cout << "\n";
   }
};


int main(int argc, char *argv[]){

    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    std::string fileName = "unsolved.csv";


    parser(fileName, SudokoTable);
    printer(SudokoTable);


    return 0;
}
