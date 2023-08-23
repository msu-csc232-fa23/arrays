/**
* @file task03.cpp
* @author Jim Daehn (jdaehn@missouristate.edu)
* @brief Entry-point of the task03 target.
* @version 0.2023.08.23
* @date 8/23/2023
*
* @copyright Copyright (c) 2023
*/

#include "task03.h"

int main() {
    // Declare a string variable named title and initialize it to the empty string
    std::string title; // Initialization is provided by string's default constructor
    std::cout << "\"" << (title.empty() ? "<empty string>" : title) << "\"" << std::endl;

    // And then modify them later on
    title = "The Really Inconvenient Truths";
    std::cout << "\"" << (title.empty() ? "<empty string>" : title) << "\"" << std::endl;

    // You can initialize a string variable to a string literal when you declare it:
    std::string anotherTitle = "Walls and Mirrors";
    // Strings can be concatenated using the string concatenation operator +
    std::cout << "anotherTitle = \"" + anotherTitle << "\"" << std::endl;

    std::cout << "The length of anotherTitle is " << anotherTitle.length() << " characters." << std::endl;
    std::cout << "Accessing each character of a string:" << std::endl;
    for (int index = 0; index < anotherTitle.length(); ++index) {
        std::cout << "anotherTitle[" << index << "] = " << anotherTitle[index] << std::endl;
    }

    std::cout << "You can compare strings..." << std::endl;
    if ("dig" < "dog") {
        std::cout << "\"dig\" < \"dog\"" << std::endl;
    } else
    {
        std::cout << "\"dig\" >= \"dog\"" << std::endl;
    }

    std::cout << "And you can access substrings rather easily" << std::endl;
    // substr(position, length)
    std::cout << "title.substr(2, 7) = " << title.substr(2, 7) << std::endl;

    return EXIT_SUCCESS;
}
