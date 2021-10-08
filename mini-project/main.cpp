#include <iostream>
#include <fstream>
#include <string>

const unsigned int SIZE = 9;


typedef struct SudokoCell
{
    int             value;
    bool            possibleSolutions[SIZE];
}SudokoCell_t;


bool parser(const std::string &fileName, SudokoCell_t SudokoTable[][SIZE]){
    /* 
        - Read in a csv file to a string
        - Check: Must be exact 81 digits
        - Return string
    */
    std::ifstream file(fileName);

    if( file.is_open() ){

        std::string textRow;

        std::getline(file, textRow);
        // while (std::getline (file, textRow)) {
        // // Output the text from the file
        // int i = 0;
        // for (char c:textRow){
        //     if(c != ','){
        //         std::cout << c << " ";
        //         i++;
        //     }
        //     if(i == 9){
        //         std::cout << "\n";
        //         i = 0;
        //         }
        //     }   
        // }

        std::cout << "\n";

        file.close();
        return true;
    }
    else{
        std::cout << "nothing..\n";
        return false;
    };

};


void parser(std::ifstream *pInputSudoko, SudokoCell_t SudokoTable[][SIZE]){
    /*
        - Parse the csv file into an 2D array
        - By creating a new instance of struct SudokoCell
        - Update SudokoCell->value
    */
   int val;
   for (size_t i = 0; i < SIZE; i++)
   {
       SudokoTable[i][SIZE];
       for (size_t j = 0; j < SIZE; j++)
       {
           SudokoTable[i][j].value = val;
       }
       
   }
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
   }
};


int Arr[SIZE][SIZE] = {
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

int main(int argc, char *argv[]){

    // Define some variables
    SudokoCell_t SudokoTable[SIZE][SIZE];
    std::ifstream *pInputSudoko = nullptr;
    std::string fileName = "unsolved.csv";


    parser(fileName, SudokoTable);

    // std::cout << pInputSudoko << std::endl;

    // parser(pInputSudoko, SudokoTable);
    // printer(SudokoTable);

    return 0;
}
