#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
strlen - Returns the length of a string in bytes.The C++ equivalent is std::strlen.
strcpy - Copies a string from one location to another.The C++ equivalent is std::strcpy.
strcmp - Compares two strings and returns an integer value based on the comparison result.The C++ equivalent is std::strcmp.
strcat - Concatenates two strings by appending the contents of one string to another.The C++ equivalent is std::strcat.
someString[index] - Returns the character at the specified index of a string.The C++ equivalent is someString.at(index).
push_back - Adds an element to the end of a container such as a vector or string.This function is not available in C because it does not have a standard library that provides containers.
pop_back - Removes the last element from a container such as a vector or string.This function is not available in C because it does not have a standard library that provides containers.
The main difference between C and C++ lies in their approach to programming paradigms.While C is a procedural language, 
C++ is an object - oriented language that supports both procedural and object - oriented programming paradigms.In addition, 
C++ has more advanced features such as templates, operator overloading, and exception handling that are not available in C.
*/
int main()
{
    // Get the user input as a C++ string
    cout << "Enter a line: ";
    string line;
    getline(cin, line);

    // Remove spaces and punctuation marks from the line
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
    line.erase(remove_if(line.begin(), line.end(), ::ispunct), line.end());

    // Convert the line to lowercase for sorting
    transform(line.begin(), line.end(), line.begin(), ::tolower);

    // Sort the letters in alphabetical order
    sort(line.begin(), line.end());

    // Print the sorted line
    cout << "The sorted line is: " << line << endl;

    return 0;
}
