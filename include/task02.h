//
// Created by jdaehn on 8/22/23.
//

#ifndef LABHWN_TASK01_H
#define LABHWN_TASK01_H

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
#endif //LABHWN_TASK01_H
