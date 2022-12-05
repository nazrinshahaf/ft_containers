#include "colours.h"
#include "vector.hpp"

using std::cout;
using std::endl;
using ft::vector;

//template <class T, class Alloc>
//vector<T, Alloc>::vector(const allocator_type &alloc) :
//	_alloc(alloc),
//	_start(nullptr),
//	_end(nullptr),
//	_capacity(nullptr)
//{
//	cout << GREEN "Vector Empty Containter Constructor called" RESET << endl;
//}

//template <class T, class Alloc>
//vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc) :
//	_alloc(alloc)
//{
//	cout << GREEN "Vector Fill Constructor called" RESET << endl;
//
//	if (n > this->_alloc.max_size())
//		throw std::length_error("ft::vector length_error");
//
//	this->_start = this->_alloc.allocate(n);
//	this->_end = this->_start;
//	this->_capacity = this->_start + n;
//
//	while (n)
//	{
//		this->_alloc.construct(this->_end++, val);
//		n--;
//	}
//}

//template <class T, class Alloc>
//vector<T, Alloc>::vector(const vector &other) :
//	_alloc(other._alloc),
//	_start(_alloc.allocate(other.size())),
//	_end(_start),
//	_capacity(_start + other.capacity())
//{
//	cout << GREEN "Vector Copy Constructor called" RESET << endl;
//
//	//this->_start = this->_alloc.allocate(other.size());
//	//this->_end = this->_start;
//	//this->_capacity = this->_start + other.capacity();
//	for (int i = 0; i < (int)other.size(); i++, this->_end++)
//		this->_alloc.construct(this->_end, other[i]);
//}

//template <class T, class Alloc>
//vector<T, Alloc>::~vector()
//{
//	cout << RED "Vector Destructor called" RESET << endl;
//	while (this->_end != this->_start)
//	{
//		this->_alloc.destroy(this->_end);
//		this->_end--;
//	}
//	this->_alloc.deallocate(this->_start, this->_capacity - this->_start);
//}

//template <class T, class Alloc>
//vector<T,Alloc>	&vector<T, Alloc>::operator=(const vector &other)
//{
//	this->clear();
//	this->reserve(other.capacity());
//	for (int i = 0; i < (int)other.size(); this->_end++, i++)
//		this->_alloc.construct(this->_end, other[i]);
//	return (*this);
//}

//template <class T, class Alloc>
//typename vector<T,Alloc>::iterator	vector<T, Alloc>::begin(void)
//{
//	return (this->_start);
//}

//template <class T, class Alloc>
//typename vector<T,Alloc>::iterator	vector<T, Alloc>::end(void)
//{
//	return (this->_end);
//}

/**
 * Replaces everything in the vector with n elements of value val.
 * If there n > size it will resize to exactly n.
 * If n < size capacity will remain the same
**/

//template <class T, class Alloc>
//void	vector<T,Alloc>::assign(size_type n, const value_type &val)
//{
//	//can replace with clear when implemented
//	for (pointer i = this->_start; i != this->_end; i++)
//		this->_alloc.destroy(i);
//	if (n > this->size())
//		this->reserve(n);
//	for (this->_end = this->_start; this->_end != this->_start + n; this->_end++)
//		this->_alloc.construct(this->_end, val);
//}

//template <class	T, class Alloc>
//template <class InputIterator>
//void	vector<T, Alloc>::assign(InputIterator first, InputIterator last)
//{
//	(void)first;
//	(void)last;
//	//this->clear();
//	//cout << std::distance(first, last) << endl;
//}

//template <class T, class Alloc>
//void	vector<T, Alloc>::push_back(const value_type &value)
//{
//	//have to check if full then have to reallocate respectively
//	if (this->_end == this->_capacity)
//	{
//		size_type	new_capacity =
//			(this->_capacity == 0) ? 1 : (this->_capacity - this->_start) * 2;
//
//		//cout << "new_capacity : " << new_capacity << endl;
//		this->reserve(new_capacity);
//	}
//	this->_alloc.construct(this->_end++, value);
//
//	//cout << value << endl;
//	//for (size_type i = 0; i < this->capacity(); i++)
//	//	cout << "num : " << *(this->_start + i) << endl;
//}

/**
 * If the container is not empty, the function never throws exceptions
 * (no-throw guarantee). Otherwise, it causes undefined behavior.
**/
//template <class T, class Alloc>
//void	vector<T, Alloc>::pop_back(void)
//{
//	this->_alloc.destroy(this->_end - 1);
//	this->_end--;
//}

/**
 * This functions just swaps the content of v1 with v2.
 * It does not have to be reconstructed.
**/

//template <class T, class Alloc>
//void	vector<T, Alloc>::swap(vector &other)
//{
//	pointer	temp_start = this->_start;
//	pointer	temp_end = this->_end;
//	pointer	temp_capacity = this->_capacity;
//
//	this->_start = other._start;
//	this->_end = other._end;
//	this->_capacity = other._capacity;
//
//	other._start = temp_start;
//	other._end = temp_end;
//	other._capacity = temp_capacity;
//}

//template <class T, class Alloc>
//void	vector<T, Alloc>::clear(void)
//{
//	for ( ;this->_end != this->_start; this->_end--)
//		this->_alloc.destroy(this->_end);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::size_type	vector<T, Alloc>::size(void) const
//{
//    return (this->_end - this->_start);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::size_type	vector<T, Alloc>::max_size(void) const
//{
//	return (this->_alloc.max_size());
//}

//template <class T, class Alloc>
//void	vector<T, Alloc>::resize(size_type n, value_type val)
//{
//	//throw some error if too big
//	if (n > this->_alloc.max_size())
//		throw std::length_error("ft::vector length_error");
//
//	if (n < this->size()) //content is reduced to its first n elements removing those beyond
//	{
//		for (pointer i = this->_start + n; i != this->_end; i++)
//			this->_alloc.destroy(i);
//		this->_end = this->_start + n;
//	}
//	else
//	{
//		if (n > this->capacity())
//		{
//			size_type	new_capacity;
//
//			new_capacity = this->capacity();
//			while (new_capacity < n)
//				new_capacity *= 2;
//			this->reserve(new_capacity);
//		}
//		for (pointer i = this->_end; i < this->_start + n; i++)
//			this->_alloc.construct(i, val);
//		this->_end = this->_start + n;
//	}
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity(void) const
//{
//	return (this->_capacity - this->_start);
//}

//template <class T, class Alloc>
//bool	vector<T, Alloc>::empty(void) const
//{
//	if (this->size() == 0)
//		return (true);
//	return (false);
//}

//template <class T, class Alloc>
//void	vector<T, Alloc>::reserve(size_type n)
//{
//	//check if max_cap
//	if (n > this->_alloc.max_size())
//		throw std::length_error("ft::vector length_error");
//
//	if (n > this->capacity()) //reallocate and reconstruct new, destroy and deallocate old
//	{
//		pointer	old_start = this->_start;
//		pointer	old_end = this->_end;
//		pointer	old_capacity = this->_capacity;
//
//		this->_start = this->_alloc.allocate(n); //reallocate
//		this->_end = this->_start;
//		this->_capacity = this->_start + n;
//
//		for (pointer i = old_start; i != old_end; i++) //reconstruct new
//			this->_alloc.construct(this->_end++, *i);
//
//		for (pointer i = old_end; i != old_start; i--) //destroy
//			this->_alloc.destroy(i);
//
//		this->_alloc.deallocate(old_start, old_capacity - old_start);
//	}
//}

/**
* Not sure how its properly implmented but your not allowed to dellocate _end + 1,
* the starting of the deallocation must always be _start if not it causes a
* "freeing and un-allocted point in memory" error. So I have to move the pointer
* somewhere else and reallocate and reconstruct the vector
**/

//template <class T, class Alloc>
//void	vector<T, Alloc>::shrink_to_fit(void)
//{
//	if (this->size() == this->capacity())
//		return;
//	pointer	old_start = this->_start;
//	pointer	old_end = this->_end;
//	pointer	old_capacity = this->_capacity;
//
//	this->_start = this->_alloc.allocate(this->size());
//	this->_end = this->_start;
//
//	for (pointer i = old_start; i != old_end; i++)
//		this->_alloc.construct(this->_end++, *i);
//	this->_capacity = this->_end;
//
//	for (pointer i = old_start; i != old_end; i++)
//		this->_alloc.destroy(i);
//
//	this->_alloc.deallocate(old_start, old_capacity - old_start);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::reference	vector<T, Alloc>::operator[](size_type n)
//{
//	//dont do boundary checking for this
//	return (this->_start[n]);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::const_reference	vector<T, Alloc>::operator[](size_type n) const
//{
//	//dont do boundary checking for this
//	return (this->_start[n]);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::reference	vector<T, Alloc>::at(size_type n)
//{
//	if (n > this->size() - 1)
//		throw std::out_of_range("ft::vector out_of_range");
//	return (this->_start[n]);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::reference	vector<T, Alloc>::front(void)
//{
//	return (*this->_start);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::const_reference	vector<T, Alloc>::front(void) const
//{
//	return (*this->_start);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::reference	vector<T, Alloc>::back(void)
//{
//	return (*(this->_end - 1));
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::const_reference	vector<T, Alloc>::back(void) const
//{
//	return (*(this->_end - 1));
//}

//template <class T, class Alloc>
//typename vector<T,Alloc>::value_type	*vector<T, Alloc>::data(void) noexcept
//{
//	return (this->_start);
//}
//
//template <class T, class Alloc>
//const typename vector<T,Alloc>::value_type	*vector<T, Alloc>::data(void) const noexcept
//{
//	return (this->_start);
//}

//template <class T, class Alloc>
//typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator(void) const
//{
//	return (this->_alloc);
//}

//Template intantiation to prevent linking errors (have to find a better way to do this)
//template class ft::vector<int>;
//template class ft::vector<double>;
