/*
Write a function which can encode the information in the given figure:
S    Fr  Rr  R   L
1011'101'001'011'011

Assignment 2: function receives 5 inputs. Speed is divided by 20, 
rear, front, right and left distances are divided by 150
then result is encoded into uint16 and returned.
*/
#include <iostream>
#include <bitset>

struct data {
    unsigned int speed;
    unsigned int front;
    unsigned int rear;
    unsigned int right; 
    unsigned int left;
};

data decoder(const uint16_t &_input){

    data decoder;

    uint16_t MASK_speed     = 0b1111'000'000'000'000;
    uint16_t MASK_front     = 0b0000'111'000'000'000;
    uint16_t MASK_rear      = 0b0000'000'111'000'000;
    uint16_t MASK_right     = 0b0000'000'000'111'000;
    uint16_t MASK_left      = 0b0000'000'000'000'111;

   std::bitset<4> BIT_Speed     = (_input&MASK_speed) >> 12;
   std::bitset<3> BIT_Front     = (_input&MASK_front) >> 9;
   std::bitset<3> BIT_Rear      = (_input&MASK_rear) >> 6;
   std::bitset<3> BIT_Right     = (_input&MASK_right) >> 3;
   std::bitset<3> BIT_Left      = (_input&MASK_left);

   decoder.speed   = BIT_Speed.to_ulong()    * 20;
   decoder.front   = BIT_Front.to_ulong()    * 150;
   decoder.rear    = BIT_Rear.to_ulong()     * 150;
   decoder.right   = BIT_Right.to_ulong()    * 150;
   decoder.left    = BIT_Left.to_ulong()     * 150;

   return decoder; // unsigned int
}

uint16_t encoder( struct data &init ){
    
    std::bitset<16> BIT_Speed     = ( init.speed    / 20 )  << 12;
    std::bitset<16> BIT_Front     = ( init.front    / 150 ) << 9;
    std::bitset<16> BIT_Rear      = ( init.rear     / 150 ) << 6;
    std::bitset<16> BIT_Right     = ( init.right    / 150 ) << 3;
    std::bitset<16> BIT_Left      = ( init.left     / 150 );

    uint16_t encodedData = ( BIT_Speed.to_ulong() | BIT_Front.to_ulong() | BIT_Rear.to_ulong() | BIT_Right.to_ulong() | BIT_Left.to_ulong() );
    return encodedData; // uint16_t
}

int main(int argc, char *argv[]){

    // uint16_t input = 0b1011'101'001'011'011;

    data inputData;
    inputData.speed  = 300;      // MAX 15*20
    inputData.front  = 1050;     // MAX 7*150
    inputData.rear   = 1050;     
    inputData.right  = 1050;
    inputData.left   = 1050;

    uint16_t input = encoder(inputData);

    data decodedData;
    decodedData = decoder(input);

    std::cout << "Speed:\t"<< decodedData.speed << std::endl;
    std::cout << "Front:\t"<<decodedData.front << std::endl;


    return 0;
}
