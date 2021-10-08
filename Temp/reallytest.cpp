#include <iostream>

void print(int row, int col){

    std::cout << "--------------------------\n\n";
    std::cout << "Square [ " << (row - row%3)/3 << " , " << (col - col%3)/3 << " ] " << std::endl;
    std::cout << "Row: " << 3*(row - row%3)/3 << " Col: " << 3*(col - col%3)/3 << std::endl;
    std::cout << "\n-------------------------\n\n";

}

int main(){

    print(1,1);
    print(4,4);
    print(7,7);
    print(1,4);

    return 0;
}