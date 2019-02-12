#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <algorithm>

// Doubly linked list
// In class project, () 

/*
 *	1. Node
 *	2. Iterators (Can mutate)
 *	3. const iterator
 *	
 *	^^Inner Classes
 *	
 *	4. linked_list
 *	
 *	
 */

namespace nwacc
{
	template<typename T>
	class linked_list
	{
	private:
		struct node // Structs default to public, but it's still private in this case.
		{
			T data;
			node *previous;
			node *next;

			// Copy Constructors
			// L values & << Left hand side e.g. "Variables"
			// R values && << These cannot be empty e.g. "Literals"

			node(
				const T &value = T{}, // Handles L values
				node *previous = nullptr,
				node *next = nullptr
			) : data{ value }, previous{ previous }, next{ next }
			{} // Nothing to do since we used the fancy constructor format
			// Since there aren't any accessors or setters we use this format

			node(
				T &&value, node *previous = nullptr, node * next = nullptr)
				: data{ std::move(value) }, previous{ previous }, next{ next }
			{}  // Handles R values 

		};

	public:

		class const_iterator
		{
		public: // Accessible to everyone

			const_iterator() : current{ nullptr } {}

			const T & operator*() const
			{
				return this->retrieve();
			}

			// prefix ++ operator
			const T & operator++()
			{
				this->current = this->current->next;
				return *this;
			}

			// c++ REQUIRES for the postfix
			// single anonymous int param
			// so the signatures of the methods are different
			const T & operator++(int)
			{
				auto old = *this;
				++(*this);
				return old;
			}

			const T & operator--()
			{
				this->current = this->current->previous;
				return *this;
			}

			// c++ REQUIRES the anon int for the postfix
			const T & operator--(int)
			{
				auto old = *this;
				--(*this);
				return old;
			}

		protected: // Not available to anyone outside the class, but available to derivatives as well.
			node * current;

			T &retrieve() const // return a reference of type T
			{
				return this->current->data;
			}

			const_iterator(node * current) : current{ current }
			{

			}

			friend class linked_list<T>; // Gives the linked list class access to the protected elements
		}; // end const_iterator

		// const_iterator is a super class to iterator
		// iterator is a subclass
		// These inner classes are templated 
		class iterator : public const_iterator // inheriting public properties and functions from const_iterator class
		{
		public:
			iterator(){} // Automatically evoke the name

			T & operator*()
			{
				// :: Scope resolution operator
				// resolve scope of the constant iterator
				return const_iterator::retrieve();
			}

		protected:

		};

	}; // end linked_list
}

#endif