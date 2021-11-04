#include "puzzle.h"
#include "importer.h"
#include <chrono>
#include <vector>


int main(int argc, char *argv[]) {

    /* BENCHMARK, SEARCH IS NECESSARY */
    // std::string sudokuLine = "38..........4..785..9.2.3...6..9....8..3.2..9....4..7...1.7.5..495..6..........92";
    
    /* BENCHMARK, REALLY HARD */
    std::string sudokuLine = "9.4..5...25.6..1..31......8.7...9...4..26......147....7.......2...3..8.6.4.....9.";

    /* BENCHMARK, CONSTRAIN PROPOGATION SHOULD BE ENOUGHT */
    // std::string sudokuLine = "..............3.85..1.2.......5.7.....4...1...9.......5......73..2.1........4...9";

    auto start = std::chrono::high_resolution_clock::now();

    Puzzle puzzle(sudokuLine);

    std::cout << "Number of solved cells:\t" << puzzle.getAmountSetValues() << std::endl;
    std::cout << "Number of guesses:\t" << puzzle.getAmountOfGuesses() << std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Timestamp [ms]:\t\t" << duration.count() << std::endl;

/*
    std::string filename = "../data/input/random.txt";
    std::vector<std::string> allSudokus;

    if( fileToVector(filename, allSudokus) ){
        unsigned int i = 1; 
        for (std::string &oneLine : allSudokus) {
            auto start = std::chrono::high_resolution_clock::now();
            std::cout << "Line: " << i++ << std::endl;

            Puzzle puzzle(oneLine);
            std::cout << "Number of solved cells: " << puzzle.valueSetCounter << std::endl;
            auto stop = std::chrono::high_resolution_clock::now();
            puzzle.print();
 
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            std::cout << "Timestamp:\t" << duration.count() << " milliseconds\n" << std::endl;

            std::cout <<   "=======================================================================================================\n";
        }
    }
*/

    return 0;
}
