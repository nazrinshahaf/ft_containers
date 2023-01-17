#ifndef VECTOR_ITERATOR
# define VECTOR_ITERATOR

#include "iterator.hpp"

/*
 * Underling iterator for vector.
 *
 * Based of random access iterator.
 * Implementing without const iterator
 * https://stackoverflow.com/a/22801650
 * */

namespace ft
{
	template <class T>
	struct	vector_iterator : public ft::iterator<ft::vector_iterator_tag, T>
	{
		typedef	T	value_type;
		typedef	typename ft::iterator<ft::vector_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::vector_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::iterator<ft::vector_iterator_tag, T>::pointer				pointer;
		typedef typename ft::iterator<ft::vector_iterator_tag, T>::reference			reference;

		vector_iterator() : _ptr(nullptr) {}
		vector_iterator(const vector_iterator<typename ft::remove_const<value_type>::type> &other) : _ptr(other._ptr) {}
		//vector_iterator(const vector_iterator &other) : _ptr(other._ptr) {}
		vector_iterator(pointer p) : _ptr(p) {}

        vector_iterator<value_type>	&operator=(vector_iterator<typename ft::remove_const<value_type>::type> const &other)
        //vector_iterator	&operator=(vector_iterator const &other)
		{
			this->_ptr = other._ptr	;
			return (*this);
		}

		~vector_iterator() {}

		bool operator==(const vector_iterator &other) const { return this->_ptr == other._ptr ? true : false; }
		bool operator!=(const vector_iterator &other) const { return this->_ptr == other._ptr ? false : true; }
		bool operator>(const vector_iterator &other) const { return this->_ptr > other._ptr; }
		bool operator>=(const vector_iterator &other) const { return this->_ptr >= other._ptr; }
		bool operator<(const vector_iterator &other) const { return this->_ptr < other._ptr; }
		bool operator<=(const vector_iterator &other) const { return this->_ptr <= other._ptr; }

		//operator	vector_iterator<const value_type>(void) const
		//{
		//	return (vector_iterator<const value_type>(this->_ptr));
		//}

		vector_iterator	&operator++() //prefix
		{ 
			this->_ptr++;
			return (*this);
		}

		vector_iterator	operator++(int) //postfix
		{
			vector_iterator	temp = *this;
			++this->_ptr;
			return (temp);
		}

		vector_iterator	operator+(size_t n) const
		{
			return (this->_ptr + n);
		}

		vector_iterator	&operator+=(size_t n)
		{
			this->_ptr += n;
			return (*this);
		}

		difference_type	operator+(const vector_iterator &other)
		{
			return (this->_ptr + other._ptr);
		}

		vector_iterator	&operator--() //prefix
		{ 
			this->_ptr--;
			return (*this);
		}

		vector_iterator	operator--(int) //postfix
		{
			vector_iterator	temp = *this;
			--this->_ptr;
			return (temp);
		}

		vector_iterator	operator-(size_t n) const
		{
			return (this->_ptr - n);
		}

		vector_iterator	&operator-=(size_t n)
		{
			this->_ptr -= n;
			return (*this);
		}

		difference_type	operator-(const vector_iterator &other) const
		{
			return (this->_ptr - other._ptr);
		}

		reference	operator*(void) const { return *this->_ptr ; }
		pointer		operator->(void) const { return this->_ptr ; }
		reference	operator[](size_t n) const {return *(this->_ptr + n); }

		pointer		getPtr(void) const { return this->_ptr ; }

		pointer	_ptr;
	};
}

#endif
