#ifndef MAP_ITERATOR
# define MAP_ITERATOR

#include <memory>
#include <functional>
#include "iterator.hpp"
#include "colours.h"

# define RBT_BLACK false
# define RBT_RED true

template <class T>
struct Node
{
	typedef	Node<T>		*node_ptr;

	Node() :
		data(nullptr),
		parent(nullptr),
		left(nullptr),
		right(nullptr),
		colour(false),
		is_sentinal(false)
	{ 
#ifdef PRINT_MSG
		cout << GREEN "Node Default Constructor Called" RESET << endl;
#endif
	}

	Node(T *val, node_ptr parent = nullptr, node_ptr left = nullptr,
			node_ptr right = nullptr, bool colour = false,
			bool is_sentinal = false) :
		data(val),
		parent(parent),
		left(left),
		right(right),
		colour(colour),
		is_sentinal(is_sentinal)
	{ 
#ifdef PRINT_MSG
		cout << GREEN "Node Fill Constructor Called" RESET << endl;
#endif
	}

	Node(const Node &other) :
		data(other.data),
		parent(other.parent),
		left(other.left),
		right(other.right),
		colour(other.colour),
		is_sentinal(other.is_sentinal)
	{
#ifdef PRINT_MSG
		cout << GREEN "Node Copy Constructor Called" RESET << endl;
#endif
	}

	~Node()
	{
#ifdef PRINT_MSG
		cout << RED "Node Destructor Called" RESET << endl;
#endif
	}

	T			*data;
	node_ptr	parent;
	node_ptr	left;
	node_ptr	right;
	bool		colour;
	bool		is_sentinal;
};

/*
 * Underlying iterator for map.
 *
 * Based of bidirectional iterator.
 * */

namespace ft
{
	template <class	T>
	class map_iterator : public ft::iterator<ft::map_iterator_tag, T>
	{
		public:
			typedef	T	value_type;
			typedef	typename ft::iterator<ft::map_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::map_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<ft::map_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<ft::map_iterator_tag, T>::reference			reference;
			typedef Node<typename ft::remove_const<value_type>::type>*						node_pointer;
			//typedef typename Node<T>::node_ptr											node_pointer;
			//typedef Node<T>																*node_pointer;
			//typedef Node<const T>														*const_node_pointer;

			map_iterator() : _node(nullptr) {}
			map_iterator(const map_iterator<typename ft::remove_const<value_type>::type> &other) : _node(other._node) {}
			//map_iterator(const map_iterator &other) : _node(other._node) {}
			map_iterator(node_pointer n) : _node(n) {}

			map_iterator&	operator=(const map_iterator &other)
			{
				this->_node = other._node;
				return (*this);
			}
			~map_iterator() {}

			bool	operator==(const map_iterator &other) const { return this->_node == other._node;  }
			bool	operator!=(const map_iterator &other) const { return this->_node != other._node;  }
			bool	operator>(const map_iterator &other) const { return this->_node > other._node;  }
			bool	operator>=(const map_iterator &other) const { return this->_node >= other._node;  }
			bool	operator<(const map_iterator &other) const { return this->_node < other._node;  }
			bool	operator<=(const map_iterator &other) const { return this->_node <= other._node;  }

			//operator	map_iterator<const value_type>(void) const
			//{
			//	return (map_iterator<const value_type>(reinterpret_cast<const_node_pointer>(_node)));
			//	//return (map_iterator<const value_type>(_node));
			//}

			map_iterator	&operator++() //prefix
			{
				if (_node->is_sentinal)
					_node = _node->left;
				else if (_node->right->is_sentinal)
				{
					node_pointer	front = _node->parent;
					while (_node == front->right && !front->is_sentinal)
					{
						_node = front;
						front = front->parent;
					}
					_node = front;
				}
				else
					_node = min(_node->right);
				return (*this);
			}

			map_iterator	operator++(int) //postfix
			{
				map_iterator<value_type>	temp = *this;

				if (_node->is_sentinal)
					_node = _node->left;
				else if (_node->right->is_sentinal)
				{
					node_pointer	front = _node->parent;
					while (_node == front->right && !front->is_sentinal)
					{
						_node = front;
						front = front->parent;
					}
					_node = front;
				}
				else
					_node = min(_node->right);
				return (temp);
			}

			map_iterator	&operator--() //prefix
			{
				if (_node->is_sentinal)
					_node = _node->right;
				else if (_node->left->is_sentinal)
				{
					node_pointer	front = _node->parent;
					while (_node == front->left && !front->is_sentinal)
					{
						_node = front;
						front = front->parent;
					}
					_node = front;
				}
				else
					_node = max(_node->left);
				return (*this);
			}

			map_iterator	operator--(int) //postfix
			{
				map_iterator<value_type>	temp = *this;

				if (_node->is_sentinal)
					_node = _node->right;
				else if (_node->left->is_sentinal)
				{
					node_pointer	front = _node->parent;
					while (_node == front->left && !front->is_sentinal)
					{
						_node = front;
						front = front->parent;
					}
					_node = front;
				}
				else
					_node = max(_node->left);
				return (temp);
			}

			reference	operator*(void) const { return (*this->_node->data); }
			pointer		operator->(void) const { return (this->_node->data); }

			node_pointer	_node;

		private:
			node_pointer	min(node_pointer node)
			{
				while (node->is_sentinal == false
						&& node->left->is_sentinal == false)
					node = node->left;
				return node;
			}

			node_pointer	max(node_pointer node)
			{
				while (node->is_sentinal == false
						&& node->right->is_sentinal == false)
					node = node->right;
				return node;
			}
	};
}
#endif
