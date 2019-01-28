#include <iostream>  // Put in alphabetical order
#include <string>

#include "tuple.h"  // User defined headers come second and are also in alphabetical order

int main() {
	
	// nwacc::tuple<double, int> pair(3.4, 6);
	// std::cout << &pair << std::endl;


	// std::cout << pair.get_first() << std::endl;
	// std::cout << pair.get_second() << std::endl;

	auto *pair = new nwacc::tuple<std::string, double>("Shane", 1.3);

	// std::cout << pair->get_first() << std::endl;

	std::cout << &pair << std::endl;

	delete pair;
	return 0;
}