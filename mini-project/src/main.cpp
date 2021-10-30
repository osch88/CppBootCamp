#include "puzzle.h"
#include "importer.h"
#include <chrono>
#include <vector>


int main(int argc, char *argv[]) {

    std::string filename = "../data/input/easy.txt";
    // std::string filename = "../data/input/puzzle_evil.txt";
    std::vector<std::string> allSudokus;

    if( fileToVector(filename, allSudokus) ){
        unsigned int i = 1;
        for (std::string &oneLine : allSudokus) {

            std::cout << "Line: " << i++ << std::endl;

            Puzzle puzzle(oneLine);

            std::cout <<   "========================================================================\n";
        }
    }


    return 0;
}
