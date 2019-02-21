#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Cody Averett
 * 
 * HW_3_Self-adjusting
 * 
 * 2/20/2019
 */

#include <algorithm>

namespace nwacc
{

	/* Template for a doubly linked list
	 *
	 * @type T data type being stored in the node
	 * 
	 */
	template<typename T>
	class self_adjusting_linked_list
	{
	private:

		/* Nodes provide a generic storage medium that can point to 
		 * 
		 * @type T data is the data type being stored in the node
		 * 
		 * @pointer previous points to the previous node, will be a null pointer if it is the first record
		 * 
		 * @pointer next points to the next node in a linked list, will be a null pointer if it is the last record
		 * 
		 */
		struct node
		{
			T data;
			node *previous;
			node *next;

			node(
				const T &value = T{},
				node *previous = nullptr,
				node *next = nullptr
			) : data{ value }, previous{ previous }, next{ next }
			{} // nothing else to construct 

			/* node constructor override
			 *  && 
			 */
			node(
				T &&value, node *previous = nullptr, node * next = nullptr)
				: data{ std::move(value) }, previous{ previous }, next{ next }
			{} 

		}; // end of node struct


	public:

		/* const_iterator given a self_adjusting_linked_list will return values of a node
		 * 
		 */
		class const_iterator
		{
		public:

			/* const_iterator constructor
			 * 
			 * @initialize current to nullptr
			 * 
			 */
			const_iterator() : current{ nullptr } 
			{} // Nothing else to do. do_nothing();


			/* Override the * operator
			 *
			 * @return the current node of type T
			 *
			 */
			const T & operator*() const
			{
				return this->retrieve();
			}

			/* Override the prefix ++ operator
			 * e.g. ++value
			 * 
			 * @return the next node of type T
			 * 
			 */
			const_iterator & operator++()
			{
				this->current = this->current->next;
				return *this;
			}

			/* Override the postfix ++ operator
			 * e.g. value++
			 * 
			 * @note this function accepts a single anonymous int param
			 *		 which is a c++ convention to specify an override of the postfix
			 *
			 * @return the current node of type T then increment
			 * 
			 */
			const_iterator & operator++(int)
			{
				auto old = *this;
				++(*this);
				return old;
			}

			/* Override the prefix -- operator
			 * e.g. --value
			 *  
			 * @return the previous node of type T
			 *
			 */
			const_iterator & operator--()
			{
				this->current = this->current->previous;
				return *this;
			}

			/* Override the postfix -- operator
			 * e.g. value--
			 *
			 * @note this function accepts a single anonymous int param
			 *		which is a c++ convention to specify an override of the postfix
			 *
			 * @return the current node of type T then decrement
			 *
			 */
			const_iterator & operator--(int)
			{
				auto old = *this;
				--(*this);
				return old;
			}

			/* Override the == operator
			 * 
			 */
			bool operator== (const const_iterator & rhs) const
			{
				return this->current == rhs.current;
			}

			/* Override the != operator
			 *
			 */
			bool operator!= (const const_iterator & rhs) const
			{
				return !(*this == rhs);
			}

		protected:

			// Pointer to the current node selected
			node * current;

			/*	Retrieve the data in the current node
			 *	
			 *  @return a reference to the current data of type T
			 */
			T &retrieve() const
			{
				return this->current->data;
			}

			// Constructor to create a new iterator pointing to given node
			const_iterator(node * current) : current{ current }
			{} // Nothing else to do. do_nothing();

			// Declare self_adjusting_linked_list as a friend so it can access private methods
			friend class self_adjusting_linked_list<T>;

		}; // end of const_iterator class


		/* iterator IS-A const_iterator
		 * 
		 * @inherits the public properties and functions of super class const_iterator
		 *
		 */
		class iterator : public const_iterator
		{
		public:

			iterator() {}

			T & operator*()
			{
				return const_iterator::retrieve();
			}

			// Return the object stored at the current position.
			// For iterator, there is an accessor with a
			// const reference return type and a mutator with
			// a reference return type. The accessor is shown first.
			const T & operator* () const
			{
				return const_iterator::operator*();
			}

			iterator & operator++ ()
			{
				this->current = this->current->next;
				return *this;
			}

			iterator operator++ (int)
			{
				auto old = *this;
				++(*this);
				return old;
			}

			iterator & operator-- ()
			{
				this->current = this->current->previous;
				return *this;
			}

			iterator operator-- (int)
			{
				auto old = *this;
				--(*this);
				return old;
			}

		protected:
			// Protected constructor for iterator.
			// Expects the current position.
			iterator(node *current) : const_iterator{ current } { }

			friend class self_adjusting_linked_list<T>;
		}; // end of iterator class

		/* self_adjusting_linked_list constructor
		 * 
		 * initializes the linked list
		 * 
		 */
		self_adjusting_linked_list()
		{
			this->init();
		}

		self_adjusting_linked_list(const self_adjusting_linked_list & rhs)
		{
			this->init();
			for (auto &value : rhs)
			{
				this->push_back(value);
			}
		}

		~self_adjusting_linked_list()
		{
			this->clear();
			delete this->head;
			delete this->tail;
		}

		self_adjusting_linked_list(self_adjusting_linked_list && rhs)
			: my_size{ rhs.my_size }, head{ rhs.head }, tail{ rhs.tail }
		{
			rhs.my_size = 0;
			rhs.head = nullptr;
			rhs.tail = nullptr;
		}

		self_adjusting_linked_list & operator= (self_adjusting_linked_list && rhs)
		{
			std::swap(this->my_size, rhs.my_size);
			std::swap(this->head, rhs.head);
			std::swap(this->tail, rhs.tail);
			return *this;
		}

		self_adjusting_linked_list & operator= (const self_adjusting_linked_list & rhs)
		{
			auto copy = rhs;
			std::swap(*this, copy);
			return *this;
		}

		iterator begin()
		{
			return iterator(this->head->next);
		}

		const_iterator begin() const
		{
			return const_iterator(this->head->next);
		}

		iterator end()
		{
			return iterator(this->tail);
		}

		const_iterator end() const
		{
			return const_iterator(this->tail);
		}

		int size() const
		{
			return this->my_size;
		}

		bool is_empty() const
		{
			return this->size() == 0;
		}

		void clear()
		{
			while (!this->is_empty())
			{
				this->pop_front();
			}
		}

		T & front()
		{
			return *begin();
		}

		const T & front() const
		{
			return *begin();
		}

		T & back()
		{
			return *--end();
		}

		const T & back() const
		{
			return *--end();
		}

		void push_front(const T & value)
		{
			this->insert(this->begin(), value);
		}

		void push_back(const T & value)
		{
			this->insert(this->end(), value);
		}

		void push_front(T && value)
		{
			this->insert(this->begin(), std::move(value));
		}

		void push_back(T && value)
		{
			this->insert(this->end(), std::move(value));
		}

		void pop_front()
		{
			this->erase(this->begin());
		}

		void pop_back()
		{
			this->erase(--this->end());
		}


		// insert a value BEFORE iterator. 
		iterator insert(iterator current_iterator, const T & value)
		{
			auto *current = current_iterator.current;
			this->my_size++;
			return iterator(
				current->previous = current->previous->next =
				new node{ value, current->previous, current });
		}

		iterator insert(iterator current_iterator, T && value)
		{
			auto *current = current_iterator.current;
			this->my_size++;
			return iterator(
				current->previous = current->previous->next =
				new node{ std::move(value), current->previous, current });
		}

		/* Remove the value AT iterator
		 * 
		 * 
		 */
		iterator erase(iterator remove_iterator)
		{
			auto *current = remove_iterator.current;
			iterator value(current->previous);
			current->previous->next = current->next;
			current->next->previous = current->previous;
			delete current;
			this->my_size--;
			return value;
		}

	private:

		int my_size;
		node * head;
		node * tail;

		void init()
		{
			this->my_size = 0;
			this->head = new node;
			this->tail = new node;
			this->head->next = this->tail;
			this->tail->previous = this->head;
		}

	}; 
	// end of self_adjusting_linked_list class
}
// end of nwacc namespace

#endif

