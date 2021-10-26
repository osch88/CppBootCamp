/*
We want to generate 1024 random integers, then given a new random number; find two integers which are the
closest to the given number (smaller, and bigger) with less than twelve lookups
*/
#include <iostream>
#include <algorithm>
#include <vector>

// CHECK MULTISET

int main(int argc, char *argv[]){

    unsigned int SIZE = 100;

    std::vector<int> randomContainer;
    randomContainer.reserve(SIZE);

    srand( (unsigned)time(NULL) );
    for(int i = 0; i<SIZE; i++){
        int randVal = rand()%100;
        randomContainer.push_back(randVal);
    }

    std::sort( randomContainer.begin(), randomContainer.end() );

    for (size_t i = 0; i < randomContainer.size(); i++)
    {
        printf("Index: %zu\t Value: %d\n", i, randomContainer[i]);
    }
    

    return 0;
}
