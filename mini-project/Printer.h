#ifndef PRINTER_H
#define PRINTER_H

#include "Varibles.h"

#include <string>
#include <fstream>
#include <ctype.h>



void parser(const std::string &fileName, SudokoCell_t SudokoTable[][SIZE]);

void printer(SudokoCell_t SudokoTable[][SIZE]);

void printerPossibilities(SudokoCell_t SudokoTable[][SIZE]);




#endif