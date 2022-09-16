/*
        Author: Halil Akca
        Course: CSCI-135
        Instructor: Mike Zamansky
        Assignment: Lab 03, Task D

        This program has a function which takes in 2 dates as parameters and returns the west basin elevation in reverse chronological order.
*/
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

void reverse_order(std::string date1, std::string date2)
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
	double eastElevation;
	double AUGWVolume;
	double westElevation;

	std::string dates[365];
	int westElevations[365];
	int i = 0;

	int dateNum1;
	int dateNum2;

	while (fin >> Point_time >> AUGEVolume >> eastElevation >> AUGWVolume >> westElevation)
	{
		fin.ignore(INT_MAX, '\n');

		dates[i] = Point_time;
		westElevations[i] = westElevation;
		
		if(date1 == Point_time) {
                        dateNum1 = i;
                }

		if(date2 == Point_time) {
			dateNum2 = i;
		}
		i++;
	}

	for(int j=dateNum2; j >= dateNum1; j--)
	{
		std::cout << "\n" << dates[j] << "  " << westElevations[j];
	}
}
