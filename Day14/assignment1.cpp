/*
Implement a function that can read the information shown in the figure.
    seat    win     door    light
    10111   0100    1011    011

Assignment 1: write a function that receives uint16_t as an input, and print out the status of 5 seatbelts, 4 windows, 4 doors and 3 lights. For example if we have 1101 for doors, first door is open and second door is closed, third and fourth are open
*/
#include <iostream>
// #include <stdint.h>
#include <bitset>
#include <string>

void print(const uint16_t &_input){

    uint16_t seatMASK   = 0b11111'0000'0000'000;
    uint16_t windowMASK = 0b00000'1111'0000'000;
    uint16_t doorMASK   = 0b00000'0000'1111'000;
    uint16_t lightMASK  = 0b00000'0000'0000'111;

    uint16_t seats[5] = {
        0b10000'0000'0000'000,
        0b01000'0000'0000'000,
        0b00100'0000'0000'000,
        0b00010'0000'0000'000,
        0b00001'0000'0000'000,
    };

    uint16_t windows[4] = {
        0b00000'1000'0000'000,
        0b00000'0100'0000'000,
        0b00000'0010'0000'000,
        0b00000'0001'0000'000,
    };

    uint16_t doors[4] = {
        0b00000'0000'1000'000,
        0b00000'0000'0100'000,
        0b00000'0000'0010'000,
        0b00000'0000'0001'000,
    };

    uint16_t lights[3] = {
        0b00000'0000'0000'100,
        0b00000'0000'0000'010,
        0b00000'0000'0000'001,
    };

    // Seat
    std::cout << "Seat:\t\t" << std::bitset<5>( (_input & seatMASK) >> 11 ) << std::endl;
    for (size_t i = 0; i < 5; i++) {
        std::cout << "Seat no."<<i<<" is:\t" << ( (_input & seats[i]) ? "on\n" : "off\n");
    }
    std::cout << "\n----------------\n" << std::endl;
    // Window
    std::cout << "Window:\t\t" << std::bitset<4>( (_input & windowMASK) >> 7) << std::endl;
    for (size_t i = 0; i < 4; i++) {
        std::cout << "Window no."<<i<<" is:\t" << ( (_input & windows[i]) ? "on\n" : "off\n");
    }
    std::cout << "\n----------------\n" << std::endl;
    // Door
    std::cout << "Door:\t\t" << std::bitset<4>( (_input & doorMASK) >> 3 ) << std::endl;
    for (size_t i = 0; i < 4; i++) {
        std::cout << "Door no."<<i<<" is:\t" << ( (_input & doors[i]) ? "on\n" : "off\n");
    }
    std::cout << "\n----------------\n" << std::endl;
    // Light
    std::cout << "Light:\t\t" << std::bitset<3>( (_input & lightMASK) ) << std::endl;
    for (size_t i = 0; i < 3; i++) {
        std::cout << "Light no."<<i<<" is:\t" << ( (_input & lights[i]) ? "on\n" : "off\n");
    }
    
}


int main(int argc, char *argv[]){

/*
    std::bitset<16> input2 = 0b10111'0100'1011'011;
    std::cout << ( (input2.test(2)) ? "on\n" : "off\n"); // Looking from the right?
*/
    uint16_t input = 0b10111'0100'1011'011;
    std::cout << "\n" << std::bitset<16>(input) << "\n\n----------------\n" << std::endl;
    print(input);

    return 0;
}
