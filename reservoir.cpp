/*
        Author: Halil Akca
        Course: CSCI-135
        Instructor: Mike Zamansky
        Assignment: Lab 03, Task A & B

        This program will take in an input date and output the east storage for that date and also return min and max storage.
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

	while(fin >> Point_time >> AUGEVolume) { 
	// this loop reads the file line-by-line
	// extracting 2 values on each iteration

		fin.ignore(INT_MAX, '\n'); //skips to the end of line,
				//ignorring the remaining columns

		if(date == Point_time) {
			return AUGEVolume;
		}
	}
	fin.close();
	return 0;
}

double get_min_east()
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		std::cerr << "File cannot be opened for reading." << std::endl;
		exit(1);
	}

        std::string junk;
        getline(fin, junk);

	std::string Point_time;
        double AUGEVolume;
	double min = 10000000;

	while (fin >> Point_time >> AUGEVolume) {
		fin.ignore(INT_MAX, '\n');

		if(min >= AUGEVolume) {
			min = AUGEVolume;
		}
	}
	fin.close();
	
	return min;
}

double get_max_east()
{
        std::ifstream fin("Current_Reservoir_Levels.tsv");
        if (fin.fail()) {
                std::cerr << "File cannot be opened for reading." << std::endl;
                exit(1);
        }

        std::string junk;
        getline(fin, junk);

        std::string Point_time;
        double AUGEVolume;
        double max = -10000000;

        while (fin >> Point_time >> AUGEVolume) {
                fin.ignore(INT_MAX, '\n');

                if(max <= AUGEVolume) {
                        max = AUGEVolume;
                }
        }
        fin.close();

        return max;
}
