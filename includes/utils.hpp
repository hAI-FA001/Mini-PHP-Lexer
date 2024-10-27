#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include "enums.hpp"

void generateToken(char buffers[2][4096], int activeBuffer, int i, int j, LEXICAL_UNITS lexicalUnit);
int calcNumChars(int i, int j);

#endif