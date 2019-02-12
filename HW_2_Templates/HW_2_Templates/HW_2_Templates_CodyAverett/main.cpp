// HW_2_Templates
// Cody Averett
// Date: 2/6/2019

#include "pch.h"
#include <iostream>
#include <random>

#include "array.h"

int main()
{
	try {

		nwacc::array<double, 5, 10> list;

		// Create random number generator instance
		std::random_device rd;
		std::mt19937 mt(rd());
		const std::uniform_real_distribution<double> dist(1, 100);

		std::cout << std::endl << "Generating random numbers for " 
			<< list.count() << " record indices" << std::endl;

		// Fill list with random data
		for (auto i = list.get_lower_bound(); i <= list.get_upper_bound(); i++)
		{
			list[i] = dist(mt);
		}

		std::cout << std::endl << "Printing all values forwards" << std::endl;

		// Print all values forward
		for (auto i = list.get_lower_bound(); i <= list.get_upper_bound(); i++)
		{
			std::cout << i << " : " << list[i] << std::endl;
		}

		std::cout << std::endl << "Printing all values backwards" << std::endl;


		// Print all values backwards
		for (auto i = list.get_upper_bound(); i >= list.get_lower_bound(); i--)
		{
			std::cout << i << " : " << list[i] << std::endl;;
		}

		// Show that we don't accept invalid indices
		nwacc::array<double, 5, 10> list2;
		std::cout << std::endl << "App will now fail when accessing array out of bounds" << std::endl;
		list2[15] = 10000;

	} catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}