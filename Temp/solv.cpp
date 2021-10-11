#include <iostream>
#include<algorithm>
#include <string>

// stoi - string to integer

bool AllNumbersArr[] = {0,0,0,0,0,0,0,0,0};

const unsigned int SIZE = 9;

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

void checkRow(const int &row);
void checkColumn(const int &col);
void checkSquare();
void checkAll(const int &row, const int &col);

// MAIN FUNCTION
int main(){

    int row = 0;
    int col = 2;

    checkAll(row, col);

    return 0;
}


void checkRow(const int &row){
    int tmp;
    for (size_t i = 0; i < SIZE; i++){
        if(Arr[row][i] != 0){
            tmp = Arr[row][i];
            AllNumbersArr[tmp-1] = 1;
        };
    }    
};


void checkColumn(const int &col){
    int tmp;
    for (size_t i = 0; i < SIZE; i++){
        if(Arr[i][col] != 0){
            tmp = Arr[i][col];
            AllNumbersArr[tmp-1] = 1;
        };
    }

};


void checkSquare(int row, int col){

    // if(row)

};


void checkAll(const int &row, const int &col){

    std::cout << "Check cell: [" <<  row << "," << col << "]" << std::endl;

    checkRow(row);
    checkColumn(col);


    std::cout << "\nAll numbers it CAN be: " << std::endl << "[ ";

    for (size_t i = 0; i < 9; i++)
    {
        if(AllNumbersArr[i] == 0){
            std::cout << i+1 << " ";
        }
    }

    std::cout << "]\n";

}