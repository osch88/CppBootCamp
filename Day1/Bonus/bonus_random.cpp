#include <iostream>
#include <random>
#include <time.h>

int main(){

    std::string input;

    std::cout << "Think about a number 1-128\n";
    int MAX = 129, MIN = 0;

    srand(time(NULL));
    int randomValue = rand() % ( (MAX - MIN) ) + MIN;

    int secretNumber = 35;

    std::cout << "Random number: " << randomValue << "\n\n";


    int i = 0;
    while (i < 20)
    {
        if(randomValue == secretNumber){
            std::cout << "\nRight answer:\t" << secretNumber << "\nTried:\t" << i + 1 << " times.\n\n";
            break;
        }
        else if (randomValue > secretNumber) // Try lower
        {
            std::cout << randomValue << " is too high... MAX: "<< MAX << " MIN: " << MIN << std::endl;
            MAX = randomValue;
            
        }
        else // Try higher
        {
            std::cout << randomValue << " is too low... MAX: "<< MAX << " MIN: " << MIN << std::endl;
            MIN = randomValue;
        }

        randomValue = rand() % ( (MAX - MIN) ) + MIN;

        i++;
    }
    


}