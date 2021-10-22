#include <iostream>

const size_t SIZE = 10;
int function()
{
    return std::rand()%10;
}
// MUST FILL THE ARRAY FRON THE LAST INDEX
int *fillArray(){
    // int a[SIZE];
    int *a = new int[SIZE];
    size_t i = SIZE; // YOU ARE NOT SUPPOSE TO CHANGE THIS
    for (; i > 0; --i)
    {
        a[i-1] = function();
    }
    return a;
}
void printArray(int *a)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        std::cout << *(a+i) << std::endl;
    }
    delete[] a;
}
void printBool(const bool &_b)
{
    if (_b == true)
    {
        std::cout << "VALUE is TRUE" << std::endl;
    }
    else if (_b == false)
    {
        std::cout << "VALUE is FALSE" << std::endl;
    }
}
// YOU ARE NOT ALLOWED TO CHANGE THE RETURN TYPE
void resizeForMe(char *&b, size_t _newSize)             // *&a == reference to a pointer
{
    delete[] b;

    b = new char[_newSize];
    std::cout << &b << std::endl;
}

int main(){

    printArray( fillArray() );

    printBool(false);

    char *a = new char[SIZE];
    for (size_t i = 0; i < SIZE; i++){
        i % 2 ? a[i] = 'A' : a[i] = 'D';                // true : false (0)
    }
    a[SIZE-1] = 0x00;
    std::cout << "String a is: " << a << std::endl;
    std::cout << &a << std::endl;

    const size_t NEW_SIZE = 100;
    resizeForMe(a, NEW_SIZE);
    for (size_t i = 0; i < NEW_SIZE; i++){
        i % 2 ? a[i] = 'B' : a[i] = 'C';
    }
    a[NEW_SIZE-1] = 0x00;
    std::cout << "String a is: " << a << std::endl;

    delete[] a;

    return 0;
}