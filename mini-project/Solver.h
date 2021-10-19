#ifndef SOLVER_H
#define SOLVER_H

#include "Varibles.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <ctype.h>

void checkRow(SudokoCell_t SudokoTable[][SIZE], bool solutionROW[SIZE], const int &row);

void checkColumn(SudokoCell_t SudokoTable[][SIZE], bool solutionCOL[SIZE], const int &col);

void checkBox(SudokoCell_t SudokoTable[][SIZE], bool solutionBOX[SIZE], const int &row, const int &col);

bool checkIfSolved(SudokoCell_t SudokoTable[][SIZE]);

bool constraint_propagation(SudokoCell_t SudokoTable[][SIZE]);

bool bruteForce(SudokoCell_t SudokoTable[][SIZE], size_t row, size_t col);



#endif