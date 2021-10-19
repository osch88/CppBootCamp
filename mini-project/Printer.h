#ifndef PRINTER_H
#define PRINTER_H

#include "Varibles.h"

#include <string>
#include <fstream>
#include <ctype.h>



bool parser(const std::string &fileName, Sudoku SudokuTable);

void printer(Sudoku SudokuTable);

void printer(Sudoku SudokuTable, Sudoku InpTable, const std::string &text);

void printCell(Sudoku SudokuTable, int &row, int &col);


#endif