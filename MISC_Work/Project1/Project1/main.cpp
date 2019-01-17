// Filename -> lowercase -> main.cpp
// Must use VisualC++ compiler

// Template Functions
/*
	Template is sononamous with Generic
	- Allows us to build a construct using any type
	- Could help with reducing the amount of method overloading
*/

// Random notes
/*
	Arrays do not know their own size, there is no length property
*/

#include <iostream>
#include <string>

// User Defined is noted by quotations


//void print_list(std::ostream & out, 
//	const double data[],  // Const to ensure the data array is not mutated
//	int size) {
//	for (auto index = 0; index < size; index++) {
//		if (index > 0) {
//			out << data[index] << ", ";
//		}
//		else {
//			out << data[index];
//		}
//	}
//	out << std::endl;
//}

// template <typename Generic Types in ALL CAPS>
// T type E Element K key V value

// Download resharper for autoformatting
/**
 * Summary - What not how
 * @param identifier
 * @return what it returns and the condition it returns
 */

/**
 * print_list
 * Prints array values out on standard out followed by a comma
 *
 * @param out the outstream to send the data
 *
 * @param data the list to print
 * 
 * @param size the size of the list
 */
template <typename T> // The type is infered during runtime
void print_list(
	std::ostream &out,
	const T data[],
	int size) {
		for (auto index = 0; index < size; index++) {
		
			if (index > 0) {
				out << ", ";
			} // else, no need for a comma; do_nothing();

			out << data[index];
		}
		out << std::endl;
}

int main() {

	double list[]{ 3.4, 5.6, 7.8 };
	print_list(std::cout, list, 3);

	std::string names[]{ "Shane", "Lela", "Daniel", "Tamara" };
	print_list(std::cout, names, 4);

	return 0;
}