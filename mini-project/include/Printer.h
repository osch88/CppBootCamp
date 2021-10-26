#ifndef PRINTER_H
#define PRINTER_H

#include "Varibles.h"

#include <string>
#include <fstream>
#include <ctype.h>
#include <vector>

bool gettingLine(const std::string &fileName, std::vector<std::string> &allLines);

bool parser(const std::string &fileName, Sudoku SudokuTable);

void printSudokuOnOneLine(Sudoku _SudokuTable, Sudoku _InpTable);

// void printer(Sudoku SudokuTable);

// void printer(Sudoku SudokuTable, Sudoku InpTable, const std::string &text);

void printCell(Sudoku SudokuTable, int &row, int &col);


#endif