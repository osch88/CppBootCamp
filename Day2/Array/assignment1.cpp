#include <iostream>
#include <random>
#include <ctime>
#include <unistd.h>


unsigned int number = 10;

unsigned int sizeX, sizeY, sizeZ;


int setRandomNo();

int main() {

    // std::cout << "Asking for 3 numbers: ";
    // std::cin >> sizeX >> sizeY >> sizeZ;

    sizeX = 3;
    sizeY = 4;
    sizeZ = 5;

    unsigned int ***Arr = new unsigned int **[sizeX];
     
    /*
        Create the volume of the array and set random values
    */
    for (size_t i = 0; i < sizeX; i++) // Run X times
    {
        std::cout << "\n\n";
        Arr[i] = new unsigned int *[sizeY];

        for (size_t j = 0; j < sizeY; j++) // Run Y times
        {
            Arr[i][j] = new unsigned int [sizeZ];

            for (size_t k = 0; k < sizeZ; k++) // Run Z times
            {
                Arr[i][j][k] = setRandomNo();
                std::cout << Arr[i][j][k] << " ";
            }
            
            std::cout << "\n";
        }
    }

    std::cout << "\n\n";
    delete Arr;

}

int setRandomNo(){
    std::srand(std::time(nullptr));
    return rand() % number;
}