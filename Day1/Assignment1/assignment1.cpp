#include <iostream>
#include <random>
#include <ctime>

unsigned int number;
constexpr int MAX = 10;

unsigned int askForANumber();
int setRandomNo();

int main() {

    number = askForANumber();

    for (size_t i = 0; i < 8; i++) // Run 8 times
    {
        std::cout << "\n\n";

        for (size_t j = 0; j < 9; j++) // Run 9 times
        {
            for (size_t k = 0; k < 11; k++) // Run 11 times
            {
                std::cout << setRandomNo();

                if (k <10) std::cout << " | ";
            }

            std::cout << "\n";
        }
    }

}

int setRandomNo(){
    // std::srand(std::time(nullptr));
    return rand() % number;
}

unsigned int askForANumber() {
    std::cout << "Give me a number: \t";
    std::cin >> number;

    return number;
}