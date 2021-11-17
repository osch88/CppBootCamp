#include <iostream>
#include <thread>
#include <chrono>

namespace data {
struct coord {
    int x;
    int y;
} coords;
}  // namespace data

void increase() {
    while (true) {
        data::coords.x ++;
        data::coords.y ++;
    }  
}

void print() {
    while (true)
    {
        std::cout << "x: " << data::coords.x << std::endl;
        std::cout << "y: " << data::coords.y << std::endl;
    }
}

int main(int argc, char **argv) {

/*
    increase();
    print();
*/

    std::thread t1(increase);
    std::thread t2(print);

    t1.join();
    t2.join();

    return 0;
}