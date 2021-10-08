#include <iostream>
#include <fstream>
#include <string>

void sum(int *ptr_x){
    
    int x = 5;
    *ptr_x = x;
    
}

int main(){

    // int *ptr_x = nullptr;
    int ptr_x = 10;

    sum(&ptr_x);

    std::cout << ptr_x << std::endl;

    return 0;
}