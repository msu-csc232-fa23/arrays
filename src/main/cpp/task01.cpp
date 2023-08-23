/**
* @file task01.cpp
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the main target.
* @version 0.1.1
* @date 2022-02-23
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

    return EXIT_SUCCESS;75.0
}
