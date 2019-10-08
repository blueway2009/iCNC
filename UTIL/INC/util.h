#ifndef UTIL_H
#define UTIL_H

#pragma once

#include "../../LINK/INC/link.h"

#include <stdio.h>
#include <string.h>

int delByteSpace(char *bytePtr, int size);
bool isDigit(char *charPtr);  // whether digit
bool isFloat(char *charPtr);  // whether +/- digit.digit
char *passSpace(char *charPtr); // space
char *passDigit(char *charPtr);
char *passFloat(char *charPtr);

void initFIFO(FIFO_HEAD* FIFOHeadPtr, FIFO_TYPE type);
bool writeFIFO(FIFO_HEAD* FIFOHeadPtr, void *blockPtr);
bool readFIFO(FIFO_HEAD* FIFOHeadPtr, void *blockPtr);
bool resetFIFO(FIFO_HEAD* FIFOHeadPtr);

#endif