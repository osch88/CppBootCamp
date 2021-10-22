/*
Generate random numbers between 0-33, ten thousand times, then print how many duplicates of each number
you have generated -- print in ascending order.
*/
#include <iostream>
#include <map>
#include <time.h>


int main(int argc, char *argv[]){

    unsigned int key = 0;
    unsigned int value = 0;
    srand( (unsigned)time(NULL) );

    std::map<int, int> dictionary;

    // generating a MAP
    for(int i = 0; i<10000; i++){
        key = rand()%34;
        dictionary[key]++;
    }

    // Check for highest value
    for (size_t k = 0; k < 34; k++)
    {
        int MAX_key = 0;
        int MAX_value = 0;
        for( int i = 0; i<dictionary.size(); i++ ){
            if( dictionary[i] > MAX_value ){
                MAX_value = dictionary[i];
                MAX_key = i;
            }
        }
        printf( "%d\t -> %d copies\n", MAX_key, MAX_value );
        // Erase the one printed
        dictionary.erase(MAX_key);
    }

    // I COULD HAVE USED A VECTOR WITH PAIRS INSTEAD AND THEN SORT()
    // LOOK INTO MULTIMAP, INDEX - KEY - VALUE
    // LOOK INTO MAP - PAIR -> INDEX [ KEY - VALUE ]

    return 0;
}