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

/*
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
		typedef	typename Allocator::pointer								pointer;
		typedef	typename Allocator::const_pointer						const_pointer;
		typedef RedBlackTree<value_type, value_compare, allocator_type>	tree_type;
		typedef	typename tree_type::iterator							iterator;
		typedef	typename tree_type::const_iterator						const_iterator;
		typedef	ft::reverse_iterator<iterator>							reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		private:
		allocator_type	_alloc;
		tree_type		_rbt;
		key_compare		_compare;

		class value_compare : std::binary_function<T, T, bool>;

		public:
		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());

		template <class InputIterator>
		map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());

		map(const map& other);
		~map();

		map	&operator=(const map& other);


		iterator				begin(void);
		const_iterator			begin(void);
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void);
		iterator				end(void);
		const_iterator			end(void);
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void);


		bool		empty(void);
		size_type	size(void);
		size_type	max_size(void);


		mapped_type			&operator[](const key_type& k);
		mapped_type			&at(const key_type& k);
		const mapped_type	&at(const key_type& k);


		pair<iterator, bool> 	insert(const value_type& val);
		iterator 				insert(iterator position, const value_type& val);

		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last);
		void					erase(iterator position);
		size_type				erase(const key_type &key);
		void					erase(iterator first, iterator last);
		void					swap(map &to_swap);
		void					clear(void);


		key_compare				key_comp(void);
		value_compare			value_comp(void);


		iterator								find(const key_type& key);
		const_iterator							find(const key_type& key);
		size_type								count(const key_type& key);
		iterator								lower_bound(const key_type& key);
		const_iterator							lower_bound(const key_type& key);
		iterator								upper_bound(const key_type &key);
		const_iterator							upper_bound(const key_type &key);
		pair<iterator, iterator> 				equal_range(const key_type &key);
		pair<const_iterator, const_iterator> 	equal_range(const key_type &key);


		allocator_type	get_allocator(void);
	};

	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
*/

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

		private:
			allocator_type	_alloc;
			tree_type		_rbt;
			key_compare		_compare;

		public:

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
#ifdef PRINT_MSG
					else
						cout << (*to_insert->data).first << " key already exist" << endl;
#endif
				}
#ifdef PRINT_MSG
				_rbt.print_pair(_rbt.get_root(), "", true);
				cout << endl;
#endif
			}

			/*
			 * copy constructor.
			 * Copies the values of one map to another.
			 * 
			 * @param 'other' : the other map to copy the values of.
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

			/*
			 * copy assignment operator.
			 * Copies value of 'other' map into current map.
			 *
			 * @param 'other' : the map to be copied
			 * */

			map	&operator=(const map& other)
			{
#ifdef PRINT_MSG
				cout << GREEN "Map Copy Assignment Operator called" RESET << endl;
#endif
				this->clear();
				this->insert(other.begin(), other.end());
				return (*this);
			}

			/* Iterators */

			/*
			 * begin.
			 * begin returns an iterator to the start of the map.
			 * */

			iterator	begin(void)
			{
				return (iterator(_rbt.begin()));
			}

			/*
			 * begin.
			 * begin returns an const_iterator to the start of the map.
			 * */

			const_iterator	begin(void) const
			{
				return (const_iterator(_rbt.begin()));
			}

			/*
			 * rbegin.
			 * rbegin returns a reverse iterator to the end of the map
			 * */

			reverse_iterator	rbegin(void)
			{
				return (reverse_iterator(end()));
			}

			/*
			 * rbegin.
			 * rbegin returns a reverse_iterator to the end of the map
			 * */

			const_reverse_iterator	rbegin(void) const
			{
				return (reverse_iterator(end()));
			}

			/*
			 * end.
			 * end returns an iterator to the end of the map.
			 * */

			iterator	end(void)
			{
				return (iterator(_rbt.end()));
			}

			/*
			 * end.
			 * end returns an const_iterator to the end of the map.
			 * */

			const_iterator	end(void) const
			{
				return (const_iterator(_rbt.end()));
			}

			/*
			 * rend.
			 * rend returns a reverse_iterator to the beginning of the map
			 * */

			reverse_iterator	rend(void)
			{
				return (reverse_iterator(begin()));
			}

			/*
			 * rend.
			 * rend returns a const_reverse_iterator to the beginning of the map
			 * */

			const_reverse_iterator	rend(void) const
			{
				return (reverse_iterator(begin()));
			}

			/* Capacity */

			/*
			 * empty.
		 	 * Returns a true or false depending on wheather or
		 	 * not the map is empty.
			 * */

			bool	empty(void) const
			{
				return (_rbt.empty());
			}

			/*
			 * size.
			 * Returns the size of the map.
			 * The number of key-value pairs in the map.
			 * */

			size_type	size(void)	const
			{
				return (_rbt.size());
			}

			/*
			 * max_size.
			 * Returns the max_size of a map.
			 *
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

			/* Element access */

			mapped_type	&operator[](const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
			}

			/* at.
			 * Returns the value held by the key if key exists in map.
			 *
			 * @note : Returns the same thing as operator but throws error if of out bounds.
			 *
			 * @param 'k' : the key to look for in the map.
			 * */

			mapped_type	&at(const key_type& k)
			{
				if (_rbt.find(ft::make_pair(k,mapped_type())) == _rbt.get_sentinal())
					throw std::out_of_range("[ft::map = out_of_range] [ft::map::at = key not found]");
					//throw std::out_of_range("ft::map out_of_range ft::map::at key not found");
				return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
			}

			/* at.
			 * Returns the const value held by the key if key exists in map.
			 *
			 * @note : Returns the same thing as operator but throws error if of out bounds.
			 *
			 * @param 'k' : the key to look for in the map.
			 * */

			const mapped_type	&at(const key_type& k) const
			{
				if (_rbt.find(ft::make_pair(k,mapped_type())) == _rbt.get_sentinal())
					throw std::out_of_range("[ft::map = out_of_range] [ft::map::at = key not found]");
				return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
			}
 
			/* Modifiers. */

			/*
			 * insert.
			 * single element insert.
			 * Inserts a pair into the map.
			 *
			 * @note : It needs to check if the pair already exists in the tree.
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
			 * hint insert.
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
			 * range insert.
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
			}

			/*
			 * erase.
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
			 * Swaps the contents of one tree with the other.
			 * Also swaps the allocator and comparator.
			 *
			 * @param 'to_swap' : The tree to swap its contents with.
			 * */

			void	swap(map &to_swap)
			{
				key_compare		temp_compare(to_swap._compare);

				this->_compare = temp_compare;
				this->_rbt.swap(to_swap._rbt);
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
			 * Returns an iterator to the key if exists.
			 * Returns an iterator to nill if doesn't.
			 *
			 * @param 'key' : the key to search for in the map.
			 * */

			iterator	find(const key_type& key)
			{
				return (iterator(_rbt.find(ft::make_pair(key, mapped_type()))));
			}

			/*
			 * find.
			 * Returns an const_iterator to the key if exists.
			 * Returns an const_iterator to nill if doesn't.
			 *
			 * @param 'key' : the key to search for in the map.
			 * */

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

			/*
			 * lower_bound.
			 * Returns a const_iterator pointing to the first element
			 * in the container whose key is not considered to go before k.
			 *
			 * Returns iterator to key if key exists in map.
			 * If not returns highest most element found,
			 * or sentinal.
			 *
			 * @param 'key' : the key to search for in the map.
			 * */

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

			/*
			 * upper_bound.
			 * Returns an const_iterator pointing to the first
			 * element in the container whose key is considered to go after k.
			 * 
			 * Returns an iterator to the first key-value pair found after key
			 * is found.
			 * @param 'key' : the key to search for in the map.
			 * */

			const_iterator	upper_bound(const key_type &key) const
			{
				for (const_iterator it = begin(); it != end(); it++)
				{
					if (_compare(key, (*it).first) == 1)
						return (it);
				}
				return (const_iterator(end()));
			}

			/*
			 * equal_range.
			 * Returns the bounds of a range that includes all the elements in 
			 * the container which have a key equivalent to key.
			 *
			 * Because the elements in a map container have unique keys,
			 * the range returned will contain a single element at most.
			 *
			 * If no matches are found, the range returned has a length of zero, with both 
			 * iterators pointing to the first element that has a key considered
			 * to go after k according to the container's key_comp.
			 *
			 * Two keys are considered equivalent if the container's
			 * comparison object returns false reflexively
			 *
			 * definition taken from https://cplusplus.com/reference/map/map/equal_range/
			 *
			 * @param 'key' : the key to search for the bounds with all 
			 * 	elements which include key.
			 * */

			pair<iterator, iterator> equal_range(const key_type &key)
			{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

			/*
			 * equal_range.
			 * Returns the bounds of a range that includes all the elements in 
			 * the container which have a key equivalent to key.
			 *
			 * Because the elements in a map container have unique keys,
			 * the range returned will contain a single element at most.
			 *
			 * If no matches are found, the range returned has a length of zero, with both 
			 * iterators pointing to the first element that has a key considered
			 * to go after k according to the container's key_comp.
			 *
			 * Two keys are considered equivalent if the container's
			 * comparison object returns false reflexively
			 *
			 * definition taken from https://cplusplus.com/reference/map/map/equal_range/
			 *
			 * @param 'key' : the key to search for the bounds with all 
			 * 	elements which include key.
			 * */

			pair<const_iterator, const_iterator> equal_range(const key_type &key) const
			{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

			/* Allocator */

			allocator_type	get_allocator(void) const
			{
				return (_alloc);
			}
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

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
		const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
				|| ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
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
