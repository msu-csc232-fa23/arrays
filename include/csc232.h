/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2023
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.2023.04.10
 * @date    04/10/2023
 *
 * @copyright Copyright (c) 2023 James R. Daehn
 */

#ifndef MSU_CSC232_H_
#define MSU_CSC232_H_

#define FALSE 0
#define TRUE 1

#define EXECUTE_PREAMBLE FALSE

#define TEST_TASK01 FALSE
#define TEST_TASK02 FALSE
#define TEST_TASK03 FALSE

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>

#include "expanded_templates.h"

 /** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;

/**
 * @brief Common namespace for CSC232 identifiers.
 */
namespace csc232
{
    // Add any user-defined functions prescribed in your assignment below

    // DO NOT Modify anything below this line

    int Preamble(int argc, char* argv[]);

    /**
     * @brief Generate a quasi-random UUID.
     * @return A string representation of a quasi-random UUID.
     */
    std::string GenerateUuid()
    {
        static std::random_device random_device;
        static std::mt19937 random_number_generator(random_device());

        std::uniform_int_distribution<int> dist(0, 15);

        const char* uuid_alphabet = "0123456789abcdef";
        const bool dash[] = { false, false, false, false, true, false, true, false,
                             true, false, true, false, false, false, false, false };

        std::string uuid;
        for (bool dash_location : dash)
        {
            if (dash_location)
                uuid += "-";
            uuid += uuid_alphabet[dist(random_number_generator)];
            uuid += uuid_alphabet[dist(random_number_generator)];
        }
        return uuid;
    }
} // namespace csc232

#endif // MSU_CSC232_H_
