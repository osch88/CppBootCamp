#include <iostream>

const int SIZE = 3;

void print(int *ptr){

    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << ptr[i] << " ";
    }
    std::cout << "\n\n";
};

void print(int ptr[][SIZE]){
    
    for (size_t i = 0; i < SIZE; i++)           // rows
    {
        for (size_t j = 0; j < SIZE; j++)       //columns
        {
            std::cout << ptr[i][j] << " ";

            if(j == 2) std::cout << "\n";
        }
    }

    std::cout << "\n\n";
};

int main(){

    int Arr1D[] = {1,2,3};

    // std::cout << "Arr1D \t\t" << Arr1D << std::endl;

    print(Arr1D);

    int Arr2D[][SIZE] = 
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };
    
    // std::cout << "Arr2D \t\t" << Arr2D << std::endl;
    // std::cout << "*Arr2D \t\t" << *Arr2D << std::endl;
    // std::cout << "Arr2D[0] \t" << Arr2D[0] << std::endl;
    // std::cout << "**Arr2D \t" << **Arr2D << std::endl;
    // std::cout << "Arr2D[0][0] \t" << Arr2D[0][0] << std::endl;

    print(Arr2D);

    // std::cout << "Arr2D[0][0] \t" << Arr2D[0][0] << std::endl;
    // std::cout << "Arr2D[1][0] \t" << Arr2D[1][0] << std::endl;
    // std::cout << "Arr2D[2][0] \t" << Arr2D[2][0] << std::endl;

    return 0;
}