#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <string>
#include <vector>

#include "varibles.h"

class Puzzle {
    private:
        std::string SudokuLine;
        SudokuCell_t SudokuTable[SIZE][SIZE];
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
        
        // In progress
        bool usedInRow(const unsigned int &row, const unsigned int &num);
        bool usedInCol(const unsigned int &col, const unsigned int &num);
        bool usedInBox(const unsigned int &row, const unsigned int &col, const unsigned int &num);
        
        bool checkIfSolved();
        bool constraintPropagation();
        bool search(unsigned int row, unsigned int col);

        void printSudokuOnOneLine();
        void print();
        std::string checkSolutionStatus();

        ~Puzzle() = default;

};


#endif