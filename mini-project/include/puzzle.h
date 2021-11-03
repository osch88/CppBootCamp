#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "variables.h"

class Puzzle {
    private:
        std::string SudokuLine;
        SudokuCell_t SudokuTable[SIZE][SIZE];
        std::string solved = "tbd";
        unsigned int valueSetCounter = 0;
        // Sudoku SudokuTable;

    public:
        Puzzle(const std::string &_SudokuLine);
        void solver();
        bool parser();

        void setValueToCell(const unsigned int &row, const unsigned int &col);
        unsigned int findUniqueHypoValue(const unsigned int &row, const unsigned int &col);
        unsigned int findUniquePeerValue(const unsigned int &row, const unsigned int &col);
        void setValueToCellPeer(const unsigned int &row, const unsigned int &col);

        void runUnits(const unsigned int &row, const unsigned int &col);
        bool constraintPropagation();

        // Hypos
        void hypoRow( const unsigned int &row, const unsigned int &col);
        void hypoColumn( const unsigned int &row, const unsigned int &col);
        void hypoBox( const unsigned int &row, const unsigned int &col);
        void updateHypos(const unsigned int &row, const unsigned int &col);
        
        // Peers
        void valueInRow(const unsigned int &row, const unsigned int &col);
        void valueInCol(const unsigned int &row, const unsigned int &col);
        void valueInBox(const unsigned int &row, const unsigned int &col);
        void findUniquePeer(const unsigned int &row, const unsigned int &col);


        bool checkIfSolved();
        bool search(unsigned int row, unsigned int col);

        void printSudokuOnOneLine();
        void print();
        std::string checkSolutionStatus();

        ~Puzzle() = default;

};


#endif