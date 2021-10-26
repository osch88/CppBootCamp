#ifndef SOLVER_H
#define SOLVER_H

#include "Varibles.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>

void checkRow(SudokoCell_t (&SudokuTable)[SIZE][SIZE], bool (&solutionROW)[SIZE], const int &row);

void checkColumn(SudokoCell_t (&SudokuTable)[SIZE][SIZE], bool (&solutionCOL)[SIZE], const int &col);

void checkBox(SudokoCell_t (&SudokuTable)[SIZE][SIZE], bool (&solutionBOX)[SIZE], const int &row, const int &col);

bool checkIfSolved(SudokoCell_t (&SudokuTable)[SIZE][SIZE]);

bool constraint_propagation(SudokoCell_t (&SudokuTable)[SIZE][SIZE]);

bool bruteForce(SudokoCell_t (&SudokuTable)[SIZE][SIZE], size_t _row , size_t _col);

void iterationPrint();



#endif