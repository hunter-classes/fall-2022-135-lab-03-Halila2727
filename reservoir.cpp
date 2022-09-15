/*
        Author: Halil Akca
        Course: CSCI-135
        Instructor: Mike Zamansky
        Assignment: Lab 03, Task A

        This program will take in an input date and output the east basin storage for that date.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

double get_east_storage(std::string date)
{
	std::string Point_time;
	double AUGEVolume;

	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1); // exit if failed to open the file
	}

	std::string junk;        // new string variable
	getline(fin, junk); // read one line from the file

	while(fin >> date >> AUGEVolume) { 
	// this loop reads the file line-by-line
	// extracting 5 values on each iteration

		fin.ignore(INT_MAX, '\n'); //skips to the end of line,
				//ignorring the remaining columns

		if(Point_time == date) {
			return AUGEVolume;
		}
	}
	fin.close();
	return 0;
}
