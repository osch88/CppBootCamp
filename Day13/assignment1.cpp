/*
Write a function template which receives two of any shapes from last week’s assignment, compares them, and
prints out the result.
*/
#include <iostream>

template<typename T1, typename T2>
void compare(T1 val1, T2 val2){
    if( val1 == val2 ) std::cout << "Equal" << std::endl;
    else if ( val1 > val2 ) std::cout << val1 << " is bigger." << std::endl;
    else if ( val1 < val2 ) std::cout << val1 << " is smaller." << std::endl;
}

int main(int argc, char *argv[]){

    compare(5,5);

    return 0;
}
