#ifndef TUPLE_H_
#define TUPLE_H_

#include <iostream>
// Don't put using namespace std;

// Tuple .. Container for more than one thing.

// Template _ Type Key Element Value <<< T1 T2

namespace nwacc // Have a custom namespace for your future projects
{

	// Class definition
	template<typename T1, typename T2>
	class tuple {
	public:
		tuple(T1, T2);  // Constructor (Job is to initialize memory)

		T1 get_first() const; // Const method is garunteed to not change the state of the class
		T2 get_second() const; // Cannot mutate the state of a class (the member variables)

		// prototypes (declaration)
		friend std::ostream& operator<<(std::ostream&, const tuple<T1, T2>);

	private:
		T1 first;
		T2 second;
		//This is a pointer
		// You'd have to dereference it as in this->
	};

	template <typename T1, typename T2>
	tuple<T1,T2>::tuple(T1 first, T2 second) {
		// Scope resolution operator ::
		this->first = first;
		this->second = second;
	}

	template <typename T1, typename T2>
	T1 tuple<T1, T2>::get_first() const 
	{
		return this->first;
	}

	template <typename T1, typename T2>
	T2 tuple<T1, T2>::get_second() const // Again, const functions cant mutate
	{ 
		return this->second;
	}

	template <typename T1, typename T2> // Try to get this working
	std::ostream& operator<<(std::ostream &out, const tuple<T1, T2> &obj) // Can be used in Cout now
	{
		out << obj.get_first() << " => " << obj.get_second() << std::endl;
		return &out;
	}
}

#endif // This is what was throwing off my code.
