/**
* @file task02.cpp
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the main target.
* @version 0.1.1
* @date 2022-02-23
*
* @copyright Copyright (c) 2022
*/

#include "task02.h"

int main()
{
    TempsTable temperatures;

    loadTableData("task02_data.txt", temperatures, DAYS_PER_WEEK, WEEKS_PER_YEAR);
    double avg = getAverageTemp(temperatures, DAYS_PER_WEEK, WEEKS_PER_YEAR);
    double max = getMaxTemp(temperatures, DAYS_PER_WEEK, WEEKS_PER_YEAR);

    std::cout << "avg = " << avg << std::endl;
    std::cout << "max = " << max << std::endl;

    return EXIT_SUCCESS;
}
