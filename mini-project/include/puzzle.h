#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <string>
#include <vector>

#include "varibles.h"

class Puzzle {
    private:
        std::string SudokuLine;
        SudokoCell_t SudokuTable[SIZE][SIZE];
        std::string solved = "tbd";
        // Sudoku SudokuTable;

    public:
        Puzzle(const std::string &_SudokuLine);
        void solver();
        bool parser();
        void checkRow(bool _peers[SIZE], const unsigned int &row);
        void checkCol(bool _peers[SIZE], const unsigned int &col);
        void checkBox(bool _peers[SIZE], const unsigned int &row, const unsigned int &col);
        void checkUnits(const unsigned int &row, const unsigned int &col);
        bool checkIfSolved();
        bool constraintPropagation();
        bool bruteForce(unsigned int row, unsigned int col);
        void printSudokuOnOneLine();
        std::string checkSolutionStatus();
        ~Puzzle() = default;

};


#endif