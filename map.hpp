#ifndef MAP_HPP
# define MAP_HPP

#include "iterator.hpp"
#include "vector_iterator.hpp"
#include "vector.hpp"
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
		 class Allocator = std::allocator<ft::pair<const Key, T>> >
	class map
	{
		public:
			typedef	Key							key_type;
			typedef	T							mapped_type;
			typedef ft::pair<const Key, T>		value_type;
			typedef	std::size_t					size_type;
			typedef	std::ptrdiff_t				difference_type;
			typedef	Compare						key_compare;
			typedef	Allocator					allocator_type;
			typedef	value_type&					reference;
			typedef	const value_type&			const_reference;
			typedef	Allocator::pointer			pointer;
			typedef	Allocator::const_pointer	const_pointer;
			//typedef	iterator
			//typedef	const_iterator
			//typedef	reverse_iterator
	};
}

#endif
