/**
* @file task01.cpp
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the main target.
* @version 0.2023.08.23
* @date 8/23/2023
*
* @copyright Copyright (c) 2022
*/

#include "task01.h"

int main()
{
    ArrayType maxTemps = {82.0, 71.5, 61.8, 88.3, 75.0};
    ArrayType temperatures = {80.1, 70.0, 61.2, 70.8, 79.1, 80.2, 81.3};

    double avg = getAverageTemp(temperatures, 5);
    double max = getMaxTemp(maxTemps, 7);

    std::cout << "The average weekly temperature is: " << avg << std::endl;
    std::cout << "The max of the maximum weekly temperatures is: " << max << std::endl;

    return EXIT_SUCCESS;
}

/* Function definitions of functions declared in corresponding header file */

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
