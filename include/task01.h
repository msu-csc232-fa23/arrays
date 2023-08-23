/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2023
 *
 * @file    task01.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Specification file demonstrating function declaration and definitions of functions that process
 *          one-dimensional arrays.
 * @version 0.2023.08.23
 * @date    08/23/2023
 *
 * @copyright Copyright (c) 2023 James R. Daehn
 */

#ifndef ICE01_TASK01_H
#define ICE01_TASK01_H

#include <iostream>

const int DAYS_PER_WEEK = 7;
typedef double ArrayType[DAYS_PER_WEEK];

/**
 * Function declaration; this function finds the average temperature of the first n values in the given array of
 * temperatures.
 *
 * @param temperatures an array of daily temperatures for a given week
 * @param n the number of days to process in the array
 * @return the average temperature of the first n temperatures in the given array
 */
double getAverageTemp(const ArrayType temperatures, int n);

/**
 * Function declaration; this function finds the maximum temperature of the first n values in the given array of
 * temperatures.
 *
 * @param temperatures an array of daily temperatures for a given week
 * @param n the number of days to process in the array
 * @return the maximum temperature of the first n temperatures in the given array
 */
double getMaxTemp(const ArrayType temperatures, int n);

#endif //ICE01_TASK01_H
