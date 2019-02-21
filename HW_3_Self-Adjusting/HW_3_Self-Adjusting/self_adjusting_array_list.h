

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <algorithm>
#include <stdexcept>

namespace nwacc
{
	template <typename T>
	class self_adjusting_array_list
	{
	public:

		explicit self_adjusting_array_list(int capacity = kDefaultCapacity) :
			my_size{ 0 }, capacity{ capacity >= kDefaultCapacity ? capacity : kDefaultCapacity }
		{
			this->data = new T[this->capacity];
		}

		// copy constructor. 
		self_adjusting_array_list(const self_adjusting_array_list &rhs) :
			my_size{ rhs.my_size }, capacity{ rhs.capacity }, data{ nullptr }
		{
			this->data = new T[this->capacity];
			for (auto index = 0; index < this->my_size; index++)
			{
				this->data[index] = rhs.data[index];
			}
		}

		self_adjusting_array_list(self_adjusting_array_list &&rhs) :
			my_size{ rhs.my_size }, capacity{ rhs.capacity }, data{ rhs.data }
		{
			rhs.data = nullptr;
			rhs.my_size = 0;
			rhs.capacity = 0;
		}

		~self_adjusting_array_list()
		{
			delete[] this->data;
		}

		void push_back(T &&value)
		{
			this->try_reserve();

			this->data[this->my_size++] = std::move(value);
		}

		void push_back(const T &value)
		{
			this->try_reserve();

			this->data[this->my_size++] = value;
		}

		void try_reserve()
		{
			if (this->size() == this->capacity)
			{
				this->reserve();
			} // else my_size is within range, do_nothing();
		}

		bool is_empty() const
		{
			return this->size() == 0;
		}

		/**
		 * Summary
		 * @return what does this return.
		 */
		int size() const
		{
			return this->my_size;
		}

		int get_capacity() const
		{
			return this->capacity;
		}

		self_adjusting_array_list &operator= (const self_adjusting_array_list &rhs)
		{
			auto copy = rhs;
			std::swap(*this, copy);
			return *this;
		}

		self_adjusting_array_list &operator= (self_adjusting_array_list &&rhs)
		{
			std::swap(this->my_size, rhs.my_size);
			std::swap(this->capacity, rhs.capacity);
			std::swap(this->data, rhs.data);
			return *this;
		}

		self_adjusting_array_list<T> &operator<< (self_adjusting_array_list &&rhs)
		{
			return *this;
		}

		void pop_back()
		{
			if (this->is_empty())
			{
				throw std::out_of_range("No elements in array list");
			} // else, we are not empty do_nothing();

			this->my_size--;
		}

		const T & back() const
		{
			if (this->is_empty())
			{
				throw std::out_of_range("No elements in the array list");
			} // else, we are not empty, do_nothing();

			return this->data[this->my_size - 1];
		}

		T &operator[](int index)
		{
			return this->data[index];
		}


		/* rotate_right moves all index elements one index up
		 *
		 * @mutates this->data
		 *
		 */
		void rotate_right()
		{
			// Ensure there are no capacity issues
			this->try_reserve();

			// Increment Size by 1
			++this->my_size;

			// Iterate over all elements
			for (int i = this->size(); i > 0; i--)
			{
				T move_value = this->data[i - 1];
				this->data[i] = move_value;
			}
		}

		/* rotate_right moves all index elements one index up
		 *
		 * @param start_index is the index to start rotating from
		 *
		 * @mutates this->data by moving all items from start_index up one index.
		 * 
		 * @ returns void
		 */
		void rotate_right_until(int start_index)
		{
			T move_value = this->data[start_index];
			// Iterate over all elements
			for (int i = start_index; i > 0; i--)
			{
				T move_value = this->data[i - 1];
				this->data[i] = move_value;
			}
		}

		/* Move an item from an array index to the front of the array
		 * and shift the values below the found index up to fill the gap
		 * made
		 * 
		 * @params index is the array index to be moved.
		 * 
		 * @returns void
		 */
		void move_to_front(int index)
		{
			// Store the value at index for future use
			T move_value = this->data[index];

			// Mutate the data by moving all items below the index
			// up by one index.
			rotate_right_until(index);

			// Move the value
			this->data[0] = move_value;
			std::cout << "Moved value " << this->data[0] << " from index " << index << " to the front" << std::endl;
		}

		/* Attempt to find a given value of type T
		 *
		 * @mutates this->data if a match is found
		 *   all values up to the match index will be rotated right
		 *   the match found will be moved to the front of the array  
		 *
	     * @ returns void
	     */
		void find(T value)
		{

			bool found_a_match = false;

			for (int i = 0; i < this->size(); i++)
			{
				// Assert if current index value is equal
				if(value == this->data[i])
				{
					found_a_match = true;

					std::cout << "Found " << value << " at index " << i << std::endl;
					move_to_front(i);

					print_values();
				}
			}

			if(!found_a_match)
			{
				std::cout << "Could not find " << value << std::endl;
			} // No match found

		}

		// Insert a new value at the beginning of the array.
		void insert(T value)
		{
			std::cout << "inserted value: " << value << std::endl;
			
			// Move all items one index up
			this->rotate_right();

			//Put the value in index 0
			this->data[0] = value;
			print_values();
		}

		/* Nicely print the value of the current array to the console
		 * Didn't realize that we were supposed to use the overloaded stream
		 * for this... :(
		 * 
		 * @output to stdout
		 * 
		 * @returns void
		 */
		void print_values()
		{

			std::cout << "Current array is [";
			for (int i = 0; i < this->size(); i++)
			{
				if(i != 0)
				{
					std::cout << ", ";
				}
				std::cout << this->data[i];
			}
			std::cout << "]" << std::endl << std::endl;
			
		}

	private:
		static const int kDefaultCapacity = 16;

		/*
		* what is this attribute
		*/
		int my_size;
		int capacity;
		T * data;

		void reserve()
		{
			if (this->size() < this->capacity)
			{
				return;
			} // else, we need to change the capacity do_nothing();

			// NOTE - Magic numbers here are fine! 
			auto new_capacity = (this->capacity * 3) / 2 + 1;
			T * new_array = new T[new_capacity];
			for (auto index = 0; index < this->size(); index++)
			{
				new_array[index] = std::move(this->data[index]);
			}

			this->capacity = new_capacity;
			std::swap(this->data, new_array);
			delete[] new_array;
		}
	};
}

#endif