/*
        Author: Halil Akca
        Course: CSCI-135
        Instructor: Mike Zamansky
        Assignment: Lab 03, Task A through D

        This program will call the functions made in reservoir.cpp and reverseorder.cpp.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include "reservoir.h"
#include "reverseorder.h"

int main()
{
	std::cout << "\nPlease enter a date: 05/20/2018";

	std::string date = "05/20/2018";

	std::cout << "\n\n";
	std::cout << "East basin storage: " << get_east_storage(date) << " billion gallons";
	std::cout << "\n\n";
	
	std::cout << "minimum storage in the East basin: " << get_min_east() << " billion gallons\n";
	std::cout << "MAXIMUM storage in the East basin: " << get_max_east() << " billion gallons\n\n";

	date = "09/13/2018";

	std::cout << "Which basin is higher on the following date? " << date << "\n" << compare_basins(date) << "\n\n";

	std::cout << "Earlier date: 05/29/2018\nLater date: 06/02/2018\n";
	reverse_order("05/29/2018", "06/02/2018");
	std::cout << "\n\n";
	return 0;
}
