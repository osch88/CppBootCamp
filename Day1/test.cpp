#include <iostream>
#include <random>
#include <time.h>
#include <unistd.h>


int main(){

    for (size_t i = 0; i < 10; i++)
    {
        int MAX = 2, MIN = 0;

        srand(time(NULL));
        // int randomValue = rand() % ( (MAX - MIN) ) + MIN;
        int randomValue = rand() % 5;

        std::cout << randomValue << std::endl;
        sleep(2);
    }
    
}