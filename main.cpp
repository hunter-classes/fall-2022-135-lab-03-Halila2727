/*
        Author: Halil Akca
        Course: CSCI-135
        Instructor: Mike Zamansky
        Assignment: Lab 02, Task A

        This program will call the function made in reservoir.cpp.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include "reservoir.h"

int main()
{
	std::cout << "\nPlease enter a date: 05/20/2018";

	std::cout << "\n\n";
	std::cout << "East basin storage: " << get_east_storage("05/20/2018") << "  billion gallons";
	std::cout << std::endl;
	
	return 0;
}
