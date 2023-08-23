/**
* @file task02.cpp
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the task02 target.
* @version 0.2023.08.23
* @date 8/23/2023
*
* @copyright Copyright (c) 2023
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

/* Function definitions of functions declared in corresponding header file */

void loadTableData(const std::string& fileName, TempsTable table, int numRows, int numColumns)
{
    if (fileName.empty())
    {
        std::ofstream outFile("task02_data.txt");

        // Seed the random number generator
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // NOLINT(*-msc51-cpp)
        for (int row = 0; row < numRows; ++row)
        {
            for (int col = 0; col < numColumns; ++col)
            {
                double random_value = static_cast<double>(std::rand()) / RAND_MAX; // NOLINT(*-msc50-cpp)
                table[row][col] = random_value * 100;
                outFile << random_value * 100 << " ";
            }
            outFile << "\n";
        }
    }
    else
    {
        // Open the file for reading
        std::ifstream data_file{ fileName, std::ios::in };
        if (!data_file)
        {
            std::cout << "Could not open \"" << fileName << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            std::cout << "Successfully opened \"" << fileName << "\"\n";
            for (int row = 0; row < numRows; ++row)
            {
                for (int col = 0; col < numColumns; ++col)
                {
                    data_file >> table[row][col];
                }
            }

            std::cout << "... will now close this file" << std::endl;
            if (data_file.is_open())
            {
                data_file.close();
            }
        }
    }

}

double getAverageTemp(const TempsTable table, int numRows, int numColumns)
{
    double sumTemps = 0;
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numColumns; ++col)
        {
            sumTemps += table[row][col];
        }
    }
    return sumTemps / (numRows * numColumns);
}

double getMaxTemp(const TempsTable table, int numRows, int numColumns)
{
    double curMaxTemp = table[0][0];
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numColumns; ++col)
        {
            if (table[row][col] > curMaxTemp)
            {
                curMaxTemp = table[row][col];
            }
        }
    }
    return curMaxTemp;
}
