#include <iostream>
#include <bitset>


int main(int argc, char *argv[]){

    // std::bitset<9> row_contains{ 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::bitset<9> bits{ 0b000'000'000 };
    bits.set(3);
    bits.set(1);
    bits.reset(5-4);

    std::cout << "All the bits:\t" << bits << '\n';
    std::cout << "Numbers equal 1:\t" << bits.count() << '\n';

    return 0;
}
