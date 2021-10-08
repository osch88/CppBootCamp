#include <iostream>

// A = 065
// Z = 090

char temp;

int main(){

    int key;
    std::string cipher;

    std::cout << "Key: ";
    std::cin >> key;
    std::cout << "Code: ";
    std::cin >> cipher;
    std::cout << "Decoded: ";

    for( char& c : cipher ){
        temp = c-key;

        // in case below 65, start over from 90
        if(temp < 'A'){
            temp = 'Z' - ('A' - temp - 1);
        }

        std::cout << temp;
    }

    std::cout << "\n";

}