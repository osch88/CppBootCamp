#include "puzzle.h"
#include "importer.h"
#include <chrono>
#include <vector>


int main(int argc, char *argv[]) {
    
    std::string sudokuLine = ".......85...21...996..8.1..5..8...16.........89...6..7..9.7..523...54...48.......";
    // // std::string sudokuLine = "..............3.85..1.2.......5.7.....4...1...9.......5......73..2.1........4...9";

    Puzzle puzzle(sudokuLine);
    puzzle.print();


    // std::string filename = "../data/input/easy.txt";
    // std::vector<std::string> allSudokus;

    // if( fileToVector(filename, allSudokus) ){
    //     unsigned int i = 1;
    //     for (std::string &oneLine : allSudokus) {

    //         std::cout << "Line: " << i++ << std::endl;

    //         Puzzle puzzle(oneLine);
    //         puzzle.print();

    //         std::cout <<   "=======================================================================================================\n";
    //     }
    // }


    return 0;
}
