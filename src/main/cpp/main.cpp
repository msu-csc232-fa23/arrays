/**
* @file main.cpp
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the main target.
* @version 0.2023.08.23
* @date 8/23/2023
* 
* @copyright Copyright (c) 2022
*/

#include "csc232.h"

int main(int argc, char* argv[])
{


	return EXIT_SUCCESS;
}

int csc232::Preamble(int argc, char* argv[])
{
	std::cout << "Hello, Main Target!" << std::endl;
	// An input file to process
	std::string input_file;

	// Check to see if the user has supplied a specific input file for consumption
	if (argc > 1)
	{
		// It is expected as the first argument
		input_file = argv[1];
	}
	else
	{
		// Default input file
		input_file = "main_data.txt";
	}

	// Open the file for reading
	std::ifstream data_file{ input_file, std::ios::in };

	if (!data_file)
	{
		std::cout << "Could not open \"" << input_file << "\"" << std::endl;
		return EXIT_FAILURE;
	}
	else
	{
		std::cout << "Successfully opened \"" << input_file << "\"";

		std::cout << "... will now close this file" << std::endl;
		if (data_file.is_open())
		{
			data_file.close();
		}
	}

	return EXIT_SUCCESS;
}
