#ifndef MAP_HPP
# define MAP_HPP

#include "iterator.hpp"
#include "map_iterator.hpp"
#include "red_black_tree.hpp"
#include "colours.h"

#include <iostream>
#include <memory>
#include <cmath>
#include <exception>
#include <iterator>
#include <stdexcept>

using std::cout;
using std::endl;

namespace ft
{
	template <class Key, class T,
		 class Compare = std::less<Key>,
		 class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef	Key														key_type;
			typedef	T														mapped_type;
			typedef ft::pair<const Key, T>									value_type;
			typedef	std::size_t												size_type;
			typedef	std::ptrdiff_t											difference_type;
			typedef	Compare													key_compare;
			typedef	Allocator												allocator_type;
			typedef	value_type&												reference;
			typedef	const value_type&										const_reference;
		
		private:
			/*
			 * value_compare.
			 *
			 * This is a class inside map to create a custom compare
			 * function to compare the keys in rbt properly.
			 * */

			class	value_compare : std::binary_function<T, T, bool>
			{
				//typedef	T		first_member_type;
				//typedef	T		second_member_type;
				//typedef	bool	result_type;

				protected:
					key_compare	_comp;

				public:

					value_compare(const key_compare &compare) : _comp(compare)
					{ }

					bool	operator()(const value_type &lhs, const value_type &rhs) const
					{
						return (_comp(lhs.first, rhs.first));
					}
			};

		public:
			typedef	typename Allocator::pointer								pointer;
			typedef	typename Allocator::const_pointer						const_pointer;
			typedef RedBlackTree<value_type, value_compare, allocator_type>	tree_type;
			typedef	typename tree_type::iterator							iterator;
			typedef	typename tree_type::const_iterator						const_iterator;
			typedef	ft::reverse_iterator<iterator>							reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;

			/*
			 * default constructor.
			 * Constructs and empty map with no elements.
			 *
			 * This will construct and empty RedBlackTree by default
			 * as it is the underlying data structure for map.
			 * 
			 * @param 'comp' : a standardised way for comparing 2 values.
			 * 	If no compare is passed in, it will be defaulted to use
			 * 	std::less.
			 * @param 'alloc' : allocater to be used to allocate memory for map.
			 * 	If no allocater is passed in, it will be defaulted to 
			 * 	std::allocator.
			 * */

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_rbt(comp, alloc),
				_compare(comp)
			{
#ifdef PRINT_MSG
				cout << GREEN "Map Default Constructor called" RESET << endl;
#endif
			}

			/*
			 * copy constructor.
			 *
			 * Copies the values of one map to another.
			 * */

			map(const map& other) :
				_alloc(other._alloc),
				_rbt(other._rbt),
				_compare(other._compare)
			{
#ifdef PRINT_MSG
				cout << GREEN "Map Copy Constructor called" RESET << endl;
#endif
			}

			/*
			 * range constructor.
			 * Constructs a map given a range of iterators.
			 *
			 * @param 'first' : the starting of the range of values to fill
			 * 	the map with.
			 * @param 'last' : the ending of the range of values to fill
			 * 	the map with.
			 * @param 'comp' : a standardised way for comparing 2 values.
			 * 	If no compare is passed in, it will be defaulted to use
			 * 	std::less.
			 * @param 'alloc' : allocater to be used to allocate memory for map.
			 * 	If no allocater is passed in, it will be defaulted to 
			 * 	std::allocator.
			 * */

			template <class InputIterator>
			map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value,
						InputIterator>::type* = nullptr) :
				_alloc(alloc),
				_rbt(comp, alloc),
				_compare(comp)
			{
#ifdef PRINT_MSG
				cout << GREEN "Map Range Constructor called" RESET << endl;
#endif
				typename tree_type::node_pointer	to_insert;

				for (; first != last; first++)
				{
					to_insert = _rbt.find(*first);
					if (to_insert == _rbt.get_sentinal())
						_rbt.insert_node(*first);
					else
						cout << (*to_insert->data).first << " key already exist" << endl;
				}
				_rbt.print_pair(_rbt.get_root(), "", true);
				cout << endl;
			}

			/*
			 * destructor.
			 * Destroys all contents held in the map.
			 * 
			 * Doesnt really do anything as it is handled by the underlying
			 * RedBlackTree.
			 * */
			~map()
			{
#ifdef PRINT_MSG
				cout << RED "Map Destructor called" RESET << endl;
#endif
			}

			/* Iterators */

			/*
			 * begin returns an iterator to the start of the map.
			 * */

			iterator	begin(void)
			{
				//cout << "non_const called" << endl;
				return (iterator(_rbt.begin()));
			}

			const_iterator	begin(void) const
			{
				//cout << "const called" << endl;
				return (const_iterator(_rbt.begin()));
			}

			reverse_iterator	rbegin(void)
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin(void) const
			{
				return (reverse_iterator(end()));
			}

			/*
			 * begin returns an iterator to the end of the map.
			 * */

			iterator	end(void)
			{
				return (iterator(_rbt.end()));
			}

			const_iterator	end(void) const
			{
				return (const_iterator(_rbt.end()));
			}

			reverse_iterator	rend(void)
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rend(void) const
			{
				return (reverse_iterator(begin()));
			}

			/* Capacity */

			/*
			 * empty.
			 *
		 	 * Returns a true or false depending on wheather or
		 	 * not the map is empty.
			 * */

			bool	empty(void) const
			{
				return (_rbt.empty());
			}

			/*
			 * size.
			 *
			 * Returns the size of the map.
			 * The number of key-value pairs in the map.
			 * */

			size_type	size(void)	const
			{
				return (_rbt.size());
			}

			/*
			 * max_size.
			 *
			 * Returns the max_size of a map.
			 * I have no idea.
			 * This has no overhead at all. (;
			 * I assume the gcc has overhead and probably different variable count so wtv.
			 *
			 * @edit : I might not need map_container but since the value is so big and rounded
			 * 	it doesnt change the outcome.
			 *
			 * should be like 
			 * (2^64 - 1) / ((((sizeof(Key) + sizeof(Value) + sizeof(RBT_node))) * max_size) + sizeof(rbt_container) + sizeof(map_container))
			 *
			 *
			 *            (2^64 - 1) - sizeof(rbt_container) - sizeof(map_container)
			 * max_size =  ----------------------------------------------------------
			 * 			         sizeof(Key) + sizeof(Value) + sizeof(RBT_node)
			 *
			 * https://stackoverflow.com/questions/720507/how-can-i-estimate-memory-usage-of-stdmap/720520#720520
			 * */

			size_type	max_size(void)	const
			{
				//cout << "sizeof key =" <<  sizeof(key_type) << endl;
				//cout << "sizeof value =" <<  sizeof(mapped_type) << endl;
				//cout << "sizeof rbt_container = " << sizeof(tree_type) << endl;
				//cout << "sizeof RBT_node = " << sizeof(typename tree_type::node) << endl;
				//cout << "sizeof map_container = " << sizeof(map) << endl;
				double max = pow(2,64); 
				double math = (((max- 1) - (sizeof(tree_type)) - sizeof(map)) / (sizeof(key_type) + sizeof(mapped_type) + sizeof(typename tree_type::node)));
				//cout << size_type(test) << endl;
				return (size_type(math));
			}

			//size_type	n_size(void)	const
			//{
			//	return (_rbt.n_size());
			//}

			//size_type	v_size(void)	const
			//{
			//	return (_rbt.v_size());
			//}
			
			/* Element access */

			mapped_type	&operator[](const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			}

			mapped_type	&at(const key_type& k)
			{
				if (_rbt.find(ft::make_pair(k,mapped_type())) == _rbt.get_sentinal())
					throw std::out_of_range("[ft::map = out_of_range] [ft::map::at = key not found]");
					//throw std::out_of_range("ft::map out_of_range ft::map::at key not found");
				return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
			}

			const mapped_type	&at(const key_type& k) const
			{
				if (_rbt.find(ft::make_pair(k,mapped_type())) == _rbt.get_sentinal())
					throw std::out_of_range("[ft::map = out_of_range] [ft::map::at = key not found]");
				return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
			}
 
			/* Modifiers. */

			/*
			 * insert.
			 *
			 * single element insert.
			 * It needs to check if the pair already exists in the tree.
			 *
			 * If it does exists it returns a key-value pair of the already
			 * existing key value pair.
			 * If id doesn't exist it returns a key-value of the value
			 * that has just been inserted into the tree.
			 *
			 * @param 'val' : the key-value pair to insert into the map.
			 * */

			pair<iterator, bool> insert(const value_type& val)
			{
				typename tree_type::node_pointer	to_insert = _rbt.find(val);

				if (to_insert != _rbt.get_sentinal())
				{
#ifdef PRINT_MSG
					cout << (*to_insert->data).first << " key already exist" << endl;
					cout << endl;
#endif
					return (ft::make_pair<iterator, bool>(iterator(to_insert) , false));
				}
				to_insert = _rbt.insert_node(val);
#ifdef PRINT_MSG
				_rbt.print_pair(_rbt.get_root(), "", true);
				cout << endl;
#endif
				return (ft::make_pair<iterator, bool>(iterator(to_insert) , true));
			}

			/*
			 * insert.
			 *
			 * hint insert.
			 *
			 * Gives a hint to the preceding node of the value to be inserted.
			 * This doesn't necessarily mean that the value will be inserted there.
			 * 
			 * @edit : This seems like a lot of work 
			 * 	(I have to implement some sort of insert and node feature for RBT)
			 * 	for very little shit as I
			 * 	have to traverse the tree (to see if the key exists) and rebalance 
			 * 	it regardless. So i didnt use the hint.
			 * @edit : I also dont know why this doesnt return true or false,
			 * 	what if the tree already has an existing node of val?
			 *
			 * @param 'position' : a position used as a hint to roughtly get an
			 * 	idea of where to insert the node.
			 * @param 'val' : the key-value pair to insert into the map.
			 * */

			iterator insert(iterator position, const value_type& val)
			{
				typename tree_type::node_pointer	to_insert = _rbt.find(val);

				(void)position;
				if (to_insert != _rbt.get_sentinal())
				{
#ifdef PRINT_MSG
					cout << (*to_insert->data).first << " key already exist" << endl;
					cout << endl;
#endif
					return (iterator(to_insert));
				}
				to_insert = _rbt.insert_node(val);
#ifdef PRINT_MSG
				_rbt.print_pair(_rbt.get_root(), "", true);
				cout << endl;
#endif
				return (iterator(to_insert));
			}

			/*
			 * insert.
			 *
			 * range insert.
			 *
			 * Inserts values pointed at by the iterators between first and last.
			 *
			 * @param 'first' : the starting of the range of values to fill
			 * 	the map with.
			 * @param 'last' : the ending of the range of values to fill
			 * 	the map with.
			 * */

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value,
							InputIterator>::type* = nullptr)
			{
				typename tree_type::node_pointer	to_insert;

				for (; first != last; first++)
				{
					to_insert = _rbt.find(*first);
					if (to_insert == _rbt.get_sentinal())
						_rbt.insert_node(*first);
#ifdef PRINT_MSG
					else
						cout << (*to_insert->data).first << " key already exist" << endl;
#endif
				}
#ifdef PRINT_MSG
				_rbt.print_pair(_rbt.get_root(), "", true);
				cout << endl;
#endif
				cout << endl;
			}

			/*
			 * erase.
			 *
			 * single iterator erase.
			 * Erases a key-value pair based on iterator position.
			 *
			 * @param 'position' : the iterator pointing to the key-value
			 * 	pair to be deleted.
			 * */

			void	erase(iterator position)
			{
				_rbt.delete_node(*position);
			}

			/*
			 * erase.
			 *
			 * single key erase.
			 * Erases a key-value pair based on the key.
			 *
			 * Returns 1 if key exists.
			 * Returns 0 if key doesn't exist.
			 *
			 * @param 'key' : the key of the key-value pair to be erased.
			 * */

			size_type	erase(const key_type &key)
			{
				iterator	to_del;
				to_del = iterator(_rbt.find(ft::make_pair(key, mapped_type())));
				if (to_del == _rbt.get_sentinal())
					return (0);
				_rbt.delete_node(*to_del);
				return (1);
			}

			/*
			 * erase.
			 *
			 * range iterator erase.
			 * Erases all key-value pairs pointed at between first and last.
			 * Exclusive of last.
			 *
			 * @param 'first' : the starting of the range of values to delete
			 * 	the map with.
			 * @param 'last' : the ending of the range of values to delete
			 * 	the map with.
			 * */

			void	erase(iterator first, iterator last)
			{
				while (first != last)
					_rbt.delete_node(*first++);
			}

			/*
			 * swap.
			 *
			 * Swaps the contents of one tree with the other.
			 * Also swaps the allocator and comparator.
			 *
			 * @param 'to_swap' : The tree to swap its contents with.
			 * */

			void	swap(map &to_swap)
			{
				tree_type		temp_tree(to_swap._rbt);
				allocator_type	temp_alloc(to_swap._alloc);
				key_compare		temp_compare(to_swap._compare);

				to_swap._alloc = this->_alloc;
				to_swap._rbt = this->_rbt;
				to_swap._compare = this->_compare;

				this->_alloc = temp_alloc;
				this->_rbt = temp_tree;
				this->_compare = temp_compare;
			}

			/*
			 * clear.
			 *
			 * Deletes all the content in the underlying tree.
			 * */

			void	clear(void)
			{
				_rbt.clear();
			}

			/* Observers */

			/*
			 * key_comp.
			 *
			 * Returns the map _compare.
			 * */

			key_compare	key_comp(void) const
			{
				return (_compare);
			}

			/*
			 * value_comp.
			 *
			 * Returns the underlying RBT _compare.
			 * */

			value_compare	value_comp(void) const
			{
				return (_rbt.key_comp());
			}
			
			/* Operations */

			/*
			 * find.
			 *
			 * Returns an iterator to the key if exists.
			 * Returns an iterator to nill if doesn't.
			 *
			 * @param 'key' : the key to search for in the map.
			 * */

			iterator	find(const key_type& key)
			{
				return (iterator(_rbt.find(ft::make_pair(key, mapped_type()))));
			}

			const_iterator	find(const key_type& key) const
			{
				return (const_iterator(_rbt.find(ft::make_pair(key, mapped_type()))));
			}

			/*
			 * count.
			 *
			 * Counts the amount of instances that a key is found in a map.
			 * Since map is unique it can only return 1 or 0.
			 *
			 * @param 'key' : the key to search for in the map.
			 * */

			size_type	count(const key_type& key) const
			{
				if (_rbt.find(ft::make_pair(key, mapped_type())) == _rbt.get_sentinal())
					return (0);
				return (1);
			}

			/*
			 * lower_bound.
			 *
			 * Returns an iterator pointing to the first element
			 * in the container whose key is not considered to go before k.
			 *
			 * Returns iterator to key if key exists in map.
			 * If not returns highest most element found,
			 * or sentinal.
			 *
			 * @param 'key' : the key to search for in the map.
			 * */

			iterator	lower_bound(const key_type &key)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (_compare((*it).first, key) == 0)
						return (it);
				}
				return (find(key));
			}

			const_iterator	lower_bound(const key_type& key) const
			{
				for (const_iterator it = begin(); it != end(); it++)
				{
					if (_compare((*it).first, key) == 0)
						return (it);
				}
				return (const_iterator(find(key)));
			}

			/*
			 * upper_bound.
			 *
			 * Returns an iterator pointing to the first
			 * element in the container whose key is considered to go after k.
			 * 
			 * Returns an iterator to the first key-value pair found after key
			 * is found.
			 * @param 'key' : the key to search for in the map.
			 * */

			iterator	upper_bound(const key_type &key)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (_compare(key, (*it).first) == 1)
						return (it);
				}
				return (end());
			}

			const_iterator	upper_bound(const key_type &key) const
			{
				for (const_iterator it = begin(); it != end(); it++)
				{
					if (_compare(key, (*it).first) == 1)
						return (it);
				}
				return (const_iterator(end()));
			}

			pair<const_iterator, const_iterator> equal_range(const key_type &key) const
			{
				typename tree_type::node_pointer	to_find = _rbt.find(ft::make_pair(key, mapped_type()));

				if (to_find == _rbt.get_sentinal())
					return (ft::make_pair(upper_bound(key), upper_bound(key)));
				else
					return (ft::make_pair(find(key), find(key)));
			}

			pair<iterator, iterator> equal_range(const key_type &key)
			{
				typename tree_type::node_pointer	to_find = _rbt.find(ft::make_pair(key, mapped_type()));

				if (to_find == _rbt.get_sentinal())
					return (ft::make_pair(upper_bound(key), upper_bound(key)));
				else
					return (ft::make_pair(find(key), find(key)));
			}

			/* Allocator */

			allocator_type	get_allocator() const
			{
				return (_alloc);
			}

		private:
			allocator_type	_alloc;
			tree_type		_rbt;
			key_compare		_compare;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (true);
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}


	/*
	 * This comparison ignores the map's ordering Compare??
	 * Idk what this means.
	 * */

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		//if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
		if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), lhs.value_comp()))
			return (true);
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		//if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
		if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), lhs.value_comp())
				|| ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (true);
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs <= lhs);
	}
}

#endif
