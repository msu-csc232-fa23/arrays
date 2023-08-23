//
// Created by jdaehn on 8/22/23.
//

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

/**
 * Function definition.
 */
double getAverageTemp(const ArrayType temperatures, int n)
{
    double temp_sum = 0;
    for (int index = 0; index < n; index += 1)
    {
        temp_sum += temperatures[index];
    }
    return temp_sum / n;
}

double getMaxTemp(const ArrayType temperatures, int n)
{
    double temp_max = temperatures[0]; // assume the max temp is the first element
    for (int index = 1; index < n; index += 1)
    {
        if (temperatures[index] > temp_max)
        {
            temp_max = temperatures[index];
        }
    }
    return temp_max;
}

#endif //ICE01_TASK01_H
