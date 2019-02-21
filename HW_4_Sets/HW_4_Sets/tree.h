#ifndef TREE_H
#define TREE_H

namespace nwacc
{

	template <typename T>
	class tree
	{
	private:

		struct node
		{
			T * data;
			node * left;
			node * right;
		};

	public:
	};
}

#endif