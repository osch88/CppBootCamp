#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctype.h>


int main(){

    std::ifstream file ("unsolved.csv");

    char arr[9][9];

    std::vector<char> names;
    char input;
    while (file >> input)
    {
        if( isdigit(input) ){ names.push_back(input); }
  
    }

    size_t j = 0;
    size_t i = 0;
    for (size_t k = 0; k < 81; k++)
    {
        arr[i][j] = names[k];
        j++;

        if( !(k+1)%9 ){
            i++;
            j = 0;
        }
    }


    for (size_t i = 0; i < 9; i++)
    {
        std::cout << arr[1][i] << " ";
    }

    return 0;
}