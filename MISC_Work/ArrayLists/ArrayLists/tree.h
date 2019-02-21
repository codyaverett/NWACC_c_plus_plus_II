#ifndef TREE_H
#define TREE_H
#include <utility>

namespace nwacc
{

	// No duplicates in a tree
	// You don't want to be able to get the values out of a tree, we are just worried about if they are there or not.
	// Big O inserts in Log Time
	template<typename T>
	class tree
	{
	public:


	private:
		struct node
		{
			T element;
			node * left;
			node * right;

			node(const T & the_element, node * left_node, node* right_node) : 
			element{ std::move(the_element) }, left{ left_node }, right{ right_node }{}
		};

		// What ever you put in first becomes the root
		node * root = nullptr;

		static bool contains( const T & value, node * current)
		{
			while(current != nullptr)
			{

				if(value < current -> element)
				{

					current = current->left;

				}	
				else if (current -> element < value)
				{

					current = current->right; 
				
				} else
				{

					return true;
				
				}

			}
			
			return false;
		}

		// Insert with recursion
		/* 
		 * @value the value to be searched
		 * @current a pointer to the current address
		 */
		void insert(const T & value, node * & current)
		{
			// If found an empty slot create a new node there
			if( current == nullptr )
			{

				// Dynamically allocating memory 
				current = new node{ value, nullptr, nullptr };

			}
			else if ( value < current->element )
			{
				
				this->insert(value, current->left);

			}
			else if ( current->element < value )
			{
				
				this->insert(value, current->right);

			}
			else
			{
				//Item is already in the tree
				// Trees cannot have duplicates
				// do_nothing();

				return;
			}

		}

		/*
		* @value the value to be searched
		* @current a pointer to the current address
		*/
		void remove(const T & value, node * & current )
		{
			// Find if the value exists
			if ( current == nullptr )
			{
				// we didn't find the value do_nothing();
				return;
			}

			// Is there a value to the left?
			if (value < current->element)
			{
				this->remove(value, current->left);
			} // Is there a value to the right?
			else if ( current->element < value)
			{
				this->remove(value, current->right);
			}
			else if ( current->left != nullptr && current->right != nullptr )
			{
				// we have two children
				current->element = this->find_min(current->right)->element;
				this->remove(current->element, current->right);
			}
			else
			{
				// we either have one child or no children

				node * old_node = current;
				current = (current->left != nullptr) ? current->left : current->right;

				// Ternary operator is sometimes called the elvis operator 
				delete old_node;
			}


		}

		// Helper method to help us determine with direction we should take
		// Will return a node that has a null left
		node * find_min(node * current) const
		{
			if (current == nullptr)
			{
				return nullptr;
			} // else, current is not null, do_nothing();

			if (current->left == nullptr)
			{
				return current;
			} // Left is a nullptr 

			// Try to find the minimum again
			return this->find_min(current->left);
		}

	};


};

#endif