/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2023
 *
 * @file    task02.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Specification file demonstrating function declaration and definitions of functions that process
 *          two-dimensional arrays.
 * @version 0.2023.08.23
 * @date 8/23/2023
 *
 * @copyright Copyright (c) 2023 James R. Daehn
 */

#ifndef ICE01_TASK02_H
#define ICE01_TASK02_H

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

const int DAYS_PER_WEEK = 7;
const int WEEKS_PER_YEAR = 52;
typedef double TempsTable[DAYS_PER_WEEK][WEEKS_PER_YEAR];

void loadTableData(const std::string& fileName, TempsTable table, int numRows, int numColumns);
double getAverageTemp(const TempsTable table, int numRows, int numColumns);
double getMaxTemp(const TempsTable table, int numRows, int numColumns);

#endif //ICE01_TASK02_H
