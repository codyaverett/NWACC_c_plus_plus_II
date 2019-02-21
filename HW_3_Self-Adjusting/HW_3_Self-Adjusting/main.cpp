/* Cody Averett
 *
 * HW_3_Self-adjusting
 *
 * 2/20/2019
 * 
 */

/* Program Objectives
 *
 * [x] Write an array implementation of self-adjusting lists.
 *
 *   [x] a. In a self-adjusting list, all insertions are performed at the front.
 *
 *   [x] b. A self-adjusting list has a find operation, and when an element is accessed by a find,
 *            it is moved to the front of the list without changing the relative order of the other items.
 *
 * [ ] Write a linked list implementation of self-adjusting lists
 *
 * [partial] Write a main method which shows all operations of your list are working as expected.
 *
 * [ ] Overload the stream insertion operator so the user can display the list to an output stream.
 *
 * [ ] The overload should display the elements in order from front to end separated by a comma and demarcated by square brackets[].
 *
 */


#include "pch.h"
#include <iostream>
#include <random>
#include <ctime>

#include "self_adjusting_array_list.h"
#include "self_adjusting_linked_list.h"

// Program Start
int main()
{
	std::cout << "Creating new Self adjusting array list " << std::endl;

	nwacc::self_adjusting_array_list<int> array_list;

	array_list.insert(1);
	array_list.insert(2);
	array_list.insert(3);
	array_list.insert(4);
	array_list.insert(5);

	array_list.find(2);
	array_list.find(5);
	array_list.find(1000);

	//std::srand(time(nullptr));

	//for (auto i = 0; i <= array_list.size(); i++)
	//{
	//	const int random_number = std::rand() % 100 + 1;
	//	array_list.insert(random_number);
	//}

	// TODO: Finish adding linked list implementation
	//nwacc::self_adjusting_linked_list<int> list;

	//list.push_back(5);
	//list.push_back(6);
	//list.push_back(3);
	//list.push_back(2);
	//list.push_back(8);


	//std::cout << list.front() << std::endl;

	//auto iterator = list.end();
	//while (iterator != list.begin())
	//{
	//	std::cout << *--iterator << " ";
	//}
	//std::cout << std::endl;

	return 0;

} 
// Program End

