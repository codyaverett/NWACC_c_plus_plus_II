// HW_2_Templates
// Cody Averett
// Date: 2/6/2019

#include "pch.h"
#include <iostream>
#include <random>

#include "array.h"

int main()
{


		nwacc::array<int, 5, 10> list;
		
		// Create random number generator instance
		std::default_random_engine generator;
		const std::uniform_int_distribution<int> distribution(1, 100);

		std::cout << "Generating random numbers for all indexes" << std::endl << std::endl;

		// Fill list with random data
		for (auto i = list.get_lower_bound(); i < list.get_upper_bound(); i++)
		{
			std::cout << i << std::endl;
			list[i] = distribution(generator);
		}

		std::cout << "Printing all values forwards" << std::endl << std::endl;



		// Print all values forward
		for (auto i = list.get_lower_bound(); i < list.get_upper_bound(); i++)
		{
			std::cout << i << " : " << list[i] << std::endl;
		}

		std::cout << "Printing all values backwards" << std::endl << std::endl;


		// Print all values backwards
		for (auto i = list.get_upper_bound(); i > list.get_lower_bound(); i--)
		{
			std::cout << i << " : " << list[i] << std::endl;;
		}
	
}