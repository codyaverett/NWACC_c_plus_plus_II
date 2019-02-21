// HW_2_Templates
// Cody Averett
// Date: 2/6/2019

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>

namespace nwacc
{

/**
	* array Template Class
	*
	* array container accepts 
	*
	* @type T The data type you'd store
	* @typeParam Bound1 integer representing one bound
	* @typeParam Bound2 integer representing another bound
	*
	* @return true or false
	*/
template <typename T, int Bound1, int Bound2>
class array
{

  private:
	// Pointer to records allocated as type T
	T *records;

	// Upper and lower bound of array
	int upper_bound;
	int lower_bound;

	/**
		* is_valid_record_index
		*
		* Check if the provided index an actual index
		*
		* @param index: Number to assert
		*
		* @return true or false
		*/
	bool is_valid_record_index(const int index) const
	{

		// Check if index is between upper and lower bounds
		if (index <= upper_bound && index >= lower_bound)
		{

			// index is valid
			return true;

		} // Index not valid

		return false;
	}

	/**
		* is_a_whole_number
		*
		* Is the number a whole number
		* Whole numbers are all positive integers, including zero
		* e.g { 0, 1, 2, 3, ..., 470, ... }
		*
		* @param value: The number to check
		*
		* @return true or false
		*/
	bool is_a_whole_number(int value)
	{

		// Check if value is greater than zero
		if (value >= 0)
		{

			// Value is a whole number
			return true;

		} // Value is not a whole number
	}

  public:
	/**
		* array constructor
		*
		* Dynamically allocates an array of type T
		* The array size is the difference between upper and lower bounds
		*	
		* @throws runtime error if bounds are not whole numbers
		*	
		*/
	explicit array() : upper_bound{Bound1 > Bound2 ? Bound1 : Bound2},
					   lower_bound{Bound1 < Bound2 ? Bound1 : Bound2}
	{

		print_debug("New array created!");

		this->records = new T[this->count()];

		if (!is_a_whole_number(upper_bound) || !is_a_whole_number(lower_bound))
		{

			std::ostringstream not_a_whole_number_error;
			not_a_whole_number_error
				<< "The array container bounds must "
				<< "be a whole number. Received a lower bound of " << lower_bound
				<< " and upper_bound of " << upper_bound << std::endl;

			throw std::runtime_error{not_a_whole_number_error.str()};
		}
	}

	/**
		* array destructor
		*
		* Frees memory allocated for the collection
		*
		* @return void
		*/
	~array()
	{

		delete this->records;
	}

	/**
		 * debug
		 * 
		 * Prints class variables to stdout
		 * 
		 * @params msg: An additional message to print
		 * 
		 * @return void
		 */
	void print_debug(std::string msg = "PRINT_DEBUG()") const
	{
		std::cout << std::endl
				  << "****** " << msg << " ****** " << std::endl;
		std::cout << "Upper: " << upper_bound << std::endl;
		std::cout << "Lower: " << lower_bound << std::endl;
		std::cout << "Count: " << count() << std::endl;
	}

	/**
		* get_upper_bound
		*
		* @return int the upper_bound value of this class
		*/
	int get_upper_bound() const
	{

		return upper_bound;
	}

	/**
		* get_lower_bound
		*
		* @return int the lower_bound value of this class
		*/
	int get_lower_bound() const
	{

		return lower_bound;
	}

	/**
		* count 
		*
		* Calculates the total number of array slots
		* 
		* @return the maximum number of array records
		*/
	int count() const
	{

		return upper_bound - lower_bound + 1;
	}

	/**
		* subscript operator implementation
		*
		* Allows access to records via [] syntax
		*
		* @params int index: index of array to retrieve
		* 
		* @throws runtime error if index is out of bounds
		* 
		* @return record at index
		*/
	T &operator[](int index)
	{

		if (!is_valid_record_index(index))
		{

			std::ostringstream index_error;
			index_error << "Array index must be between " << lower_bound
						<< " and " << upper_bound << ". Received " << index << std::endl;

			throw std::runtime_error{index_error.str()};
		}
		return this->records[index];
	}
};

} // namespace nwacc

#endif // ARRAY_H
