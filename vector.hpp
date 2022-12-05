#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "iterator.hpp"
#include "vector_iterator.hpp"
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
	template <class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public:
			/* Member types */

			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef typename Alloc::reference									reference;
			typedef typename Alloc::const_reference								const_reference;
			typedef typename Alloc::pointer										pointer;
			typedef typename Alloc::const_pointer								const_pointer;
			typedef ft::vector_iterator<T>										iterator;
			typedef ft::vector_iterator<const T>								const_iterator;
			typedef	ft::reverse_iterator<iterator>								reverse_iterator;
			typedef	ft::reverse_iterator<const iterator>						const_reverse_iterator;
			typedef	typename iterator_traits<iterator>::difference_type			difference_type;
			typedef typename Alloc::size_type									size_type;

			/*
			 * defualt constructor.
			 * Consturcts an empty container with no elements.
			 *
			 * @param 'alloc' : allocater to be used to allocate memory for vector.
			 * 	If no allocated is passed in allloc default value defaulted to 
			 * 	std::allocator constructor.
			 * */

			explicit vector(const allocator_type &alloc = allocator_type()) :
				_alloc(alloc),
				_start(nullptr),
				_end(nullptr),
				_capacity(nullptr)
			{
				cout << GREEN "Vector Empty Containter Constructor called" RESET << endl;
			}

			/*
			 * fill constructor.
			 * Constructs a container of size and capacity 'n'.
			 * Each element is filled with value 'val'.
			 *
			 * @param 'n' : the capcity and size of vector to be constructed.
			 * @param 'val' : the value to fill the vector with.
			 * 	If no value is passed it will be defaulted to the defualt constructor of type 'T'
			 * 		ex : ft::vector<int> vec(5);
			 * 		will be filled 5 with default value of int.
			 * 		vec = {0,0,0,0,0}
			 * @param 'alloc' : allocater to be used to allocate memory for vector.
			 * 	If no allocated is passed in allloc default value defaulted to 
			 * 	std::allocator constructor.
			 * */

			explicit vector(size_type n, const value_type &val = value_type(),
					const allocator_type &alloc = allocator_type()) : 
				_alloc(alloc)
			{
				cout << GREEN "Vector Fill Constructor called" RESET << endl;

				if (n > this->_alloc.max_size())
					throw std::length_error("ft::vector length_error");

				this->_start = this->_alloc.allocate(n);
				this->_end = this->_start;
				this->_capacity = this->_start + n;

				while (n)
				{
					this->_alloc.construct(this->_end++, val);
					n--;
				}
			}

			/*
			 * range constructor.
			 * Fills the vector with the values pointed at between 'first'
			 * and 'last'
			 *
			 * Some issue with indirection requires pointer operand.
			 * Works on its own but if i try and compile with Fill constructor
			 * the error shows up.
			 *
			 * @edit : This error is because the Fill constructor has conflicting
			 * 		variable count with this constutor. So the values passed in
			 * 		might not always have a dereferencable object. I need to 
			 * 		implement SFINAE (Subtituaiton Fail Is Not An Error) code
			 * 		and enable_if to fix this.
			 *
			 * @edit : I prob need another check to see wheather it is a valid
			 * 		iterator or not.
			 *
			 * @param 'first' : the starting iterator of the other vector.
			 * @param 'last' : the ending iterator of the other vector.
			 * @param 'alloc' : allocater to be used to allocate memory for vector.
			 * 	If no allocated is passed in allloc default value defaulted to 
			 * 	std::allocator constructor.
			 *
			 * @param 'ft::enable_if' : 'enable_if' takes in 2 params
			 *	'bool' and 'type'. The first bool is to determine wheather or not
			 *	to 'enable_if' the function (basically stating wheater or not this
			 *	function should be accesible given the param types thats 
			 *	being passed into it).
			 *	'type' is the param type that needs to be checked.
			 *	Its basically checking wheather 'InputIterator' is an 
			 *	inregral or not, if it isnt an integral and is an 
			 *	InputIterator type it will accept being passed into.
			 *	This is checked by seeing if the default value is 
			 *	pointing to null or not.
			 *	The default specilization template for enable_if sets T = void. 
			 *	So by defualt it will point to a nullptr.
			 *
			 *	https://stackoverflow.com/questions/61557539/how-can-i-use-my-custom-enable-if-in-c98
			 *	Templates cant have default values before c++11.
			 *
			 *	The syntax is fucking ridiculous.
			 * */

			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
					const allocator_type &alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, 
						InputIterator>::value_type* = nullptr) :
				_alloc(alloc)
			{
				cout << GREEN "Vector Range Constructor called" RESET << endl;
				//need a check to see wheather it is a valid iterator

				//replace with ft::distance when implemented
				//size_type	len = 0;
				//for (InputIterator i = first; i != last; len++, i++) ;
				size_type	len = ft::distance(first, last);

				this->_start = this->_alloc.allocate(len);
				this->_end = this->_start;
				this->_capacity = this->_start + len;

				for (InputIterator i = first; i != last; i++, this->_end++)
					this->_alloc.construct(this->_end, *i);
			}

			/*
			 * copy constructor.
			 * Constructs a copy of vector 'other', in the same order.
			 *
			 * @param 'other' : the vector to be copied
			 * */

			vector(const vector &other) :
				_alloc(other._alloc),
				_start(_alloc.allocate(other.size())),
				_end(_start),
				_capacity(_start + other.capacity())
			{
				cout << GREEN "Vector Copy Constructor called" RESET << endl;
				for (int i = 0; i < (int)other.size(); i++, this->_end++)
					this->_alloc.construct(this->_end, other[i]);
			}

			/*
			 * destructor.
			 * Destroys all elements up to size.
			 * Deallocates all storage up to capacity.
			 *
			 * https://stackoverflow.com/questions/9584660/does-the-default-allocator-zeroize-int
			 * Just pasting this here as idk how to completely tell the program that
			 * I have destroyed an object in that space. Specifically int.
			 * */

			~vector()
			{
				cout << RED "Vector Destructor called" RESET << endl;
				for (pointer i = this->_start; i < this->_end; i++)
					this->_alloc.destroy(i);
				this->_alloc.deallocate(this->_start, this->_capacity - this->_start);
			}

			/*
			 * copy assignment operator.
			 * Copies values of 'other' vector into current vector.
			 *
			 * @param 'other' : the vector to be copied
			 * */

			vector& operator=(const vector &other)
			{
				this->clear();
				this->reserve(other.capacity());
				for (int i = 0; i < (int)other.size(); this->_end++, i++)
					this->_alloc.construct(this->_end, other[i]);
				return (*this);
			}

			/* Iterators */

			/*
			 * begin returns an iterator to the start of the vector.
			 * */

			iterator				begin(void)
			{
				return (this->_start);
			}

			/*
			 * begin returns a const iterator to the start of the vector.
			 * */

			const_iterator			begin(void) const
			{
				return (this->_start);
			}

			/*
			 * rbegin returns a reverse_iterator to the end of the vector.
			 * */

			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator(this->end()));
			}

			/*
			 * rbegin returns a const_reverse_iterator to the end of the vector.
			 * */

			const_reverse_iterator	rbegin(void) const
			{
				return (reverse_iterator(this->end()));
			}

			/*
			 * end returns an iterator to the end of the vector.
			 * */

			iterator				end(void)
			{
				return (this->_end);
			}

			/*
			 * end returns a const_iterator to the end of the vector.
			 * */

			const_iterator			end(void) const
			{
				return (this->_end);
			}

			/*
			 * rend returns a reverse_iterator to the beginning of the vector.
			 * */

			reverse_iterator		rend(void)
			{
				return (reverse_iterator(this->begin()));
			}

			/*
			 * rend returns a const_reverse_iterator to the beginnning of the vector.
			 * */

			const_reverse_iterator	rend(void) const
			{
				return (reverse_iterator(this->begin()));
			}

			/* Modifiers */

			/*
			 * range assign.
			 * Replaces up the 'n' elements with value of val.
			 * The capacity and size = 'n'
			 *
			 * If 'n' is more than size. Capacity and size will be changed to 'n'.
			 * Else capacity remains the same.
			 *
			 * @param 'n' : the amount of elements to replace in the vector.
			 * @parma 'val' : the new value to fill the elements in the vector with.
			 * */

			void		assign(size_type n, const value_type &val)
			{
				this->clear();
				if (n > this->size())
					this->reserve(n);
				for (this->_end = this->_start; this->_end != this->_start + n; this->_end++)
					this->_alloc.construct(this->_end, val);
			}

			/*
			 * fill assign.
			 * Replaces everything in the vector with the elements between
			 * first and last. 
			 * The capacity and size = last - first.
			 *
			 * Something wrong with requires pointer indirection when other assign is called.
			 * But works on its own
			 *
			 * @edit : need to implement enable if to fix this issue.
			 *
			 * @param 'first' : iterator pointing to the start of other vector.
			 * @param 'last' : iterator pointint to the of the other vector.
			 * */

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value,
					InputIterator>::value_type* = nullptr)
			{
				//replace with ft::distance after properly implemented
				//size_type	len = 0;
				//for (InputIterator i = first; i != last; len++, i++) ;
				size_type	len = ft::distance(first, last);

				this->clear();
				this->reserve(len);
				for (InputIterator i = first; i != last; i++, this->_end++)
					this->_alloc.construct(this->_end, *i);
			}

			/*
			 * Adds an element to the end of the vector.
			 *
			 * If the vector size is 0. capacity and size will change to 1.
			 * If the vector is full. The vector will double in capacity.
			 *
			 * @param 'value' : the value to be added to the back of the vector.
			 * */

			void		push_back(const value_type &value)
			{
				//have to check if full then have to reallocate respectively
				if (this->_end == this->_capacity)
				{
					size_type	new_capacity = 
						(this->_capacity == 0) ? 1 : (this->_capacity - this->_start) * 2;
					this->reserve(new_capacity);
				}
				this->_alloc.construct(this->_end++, value);
			}

			/*
			 * Removes the last element from the vector.
			 * If the container is not empty, the function never throws exceptions 
			 * (no-throw guarantee). Otherwise, it causes undefined behavior.
			 * */

			void		pop_back(void)
			{
				this->_alloc.destroy(this->_end - 1);
				this->_end--;
			}

			/*
			 * single element Insert
			 * Insert single element before the position of the iterator.
			 *
			 * The rest of the vector will remain the same. 
			 * If the vector is full reallocation will happen.
			 * 
			 * Returns an iterator to the position of the new element.
			 *
			 * @param 'position' : the position of the element to insert
			 * 	'val' to. Everything after will be shifted to the right.
			 * @parma 'val' : the value to replace the element stored at
			 * 	the iterator 'position'.
			 *
			 * ex : vec.insert(vec.begin(), 123);
			 * 	vec before : {0,1,2,3,4,5}
			 * 	vec after : {123,1,2,3,4,5}
			 *
			 * ex : vec.insert(vec.begin() + 2, 123);
			 * 	vec before : {0,1,2,3,4,5}
			 * 	vec after : {0,1,123,2,3,4,5}
			 * */

			iterator	insert(iterator position, const value_type& val)
			{
				if (this->_end == this->_capacity)
				{
					this->push_back(val);
					return (this->begin());
				}

				//replace with ft::distance when implemented
				//size_type	temp_distance = 0;
				//for (iterator i = this->begin(); i != position; i++, temp_distance++);
				size_type	temp_distance = ft::distance(this->begin(), position);

				if (this->_end == this->_capacity)
				{
					size_type	new_capacity = 
						(this->_capacity == 0) ? 1 : (this->_capacity - this->_start) * 2;
					this->reserve(new_capacity);
				}

				iterator	new_position = this->begin();
				for (size_type i = 0; i < temp_distance; i++, new_position++) ;

				pointer		i = this->_start + temp_distance;

				if (i == this->_end)
				{
					this->push_back(val);
					return (new_position);
				}

				value_type	temp = *i;
				value_type	temp_end = *(this->_end - 1);

				this->_alloc.destroy(i);
				this->_alloc.construct(i++, val);

				while (i != this->_end)
				{
					value_type	temp2 = temp;
					this->_alloc.destroy(i);
					temp = *i;
					this->_alloc.construct(i, temp2);
					i++;
				}
				this->push_back(temp_end);
				return (new_position);
			}

			/*
			 * fill Insert.
			 * Insert the given value 'n' amount of times before
			 * the position given.
			 *
			 * If n == 0, nothing happens.
			 * If n == 1, reuse insert(position, val) without n argument count.
			 *
			 * @edit : I have no idea how the actual resizing of the vector
			 * 	is actually done. Sometimes capacity = size + n, sometimes
			 * 	it rounds of to the nearest nth power. Im going to just
			 * 	going to use capacity = size + n. This rounding only happens
			 * 	with 15 and 16 size. Havent found any other time.
			 *
			 * @param 'position' : the position of the element to insert
			 * 	'val' to. Everything after will be shifted to the right.
			 * @param 'n' : the amount of 'val' to fill the vector with.
			 * @parma 'val' : the value to be inserted to the left of 
			 * 	the element stored at the iterator 'position'.
			 *
			 * ex : vec.insert(vec.begin() + 2, 2, 123);
			 * 	vec before : {0,1,2,3,4,5}
			 * 	vec after : {0,1,123,123,2,3,4,5}
			 * */

			void insert(iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return ;
				if (n == 1)
				{
					this->insert(position, val);
					return ;
				}

				//replace with ft::distance when implemented
				//size_type	temp_distance = 0;
				//for (iterator i = this->begin(); i != position; i++, temp_distance++);
				size_type	temp_distance = ft::distance(this->begin(), position);
				//cout << temp_distance << endl;

				if (this->size() + n > this->capacity())
					this->reserve(this->size() + n);

				//if (this->_end + n >= this->_capacity)
				//{
				//	size_type	new_capacity = 
				//		(this->_capacity == 0) ? 1 : (this->_capacity - this->_start) * 2;
				//	this->reserve(new_capacity);
				//	cout << "new capacity : " << this->capacity() << endl;
				//}

				pointer		take_end = this->_end - 1;
				pointer		place_end = this->_end - 1 + n;
				size_type	temp_n = n;
				
				for (int i = ((int)this->size() - temp_distance); i ; i--)
				{
					//for (int i = 0; i < (int)this->capacity(); i++)
					//	cout << "vec 1 : " << (*this)[i] << endl;
					//cout << endl;
					this->_alloc.construct(place_end, *take_end);
					place_end--;
					take_end--;
				}
				while (temp_n--)
				{
					if (place_end < this->_end)
						this->_alloc.destroy(place_end);
					this->_alloc.construct(place_end, val);
					place_end--;
				}
				this->_end += n;
			}

			/*
			 * range insert.
			 * Inserts a elements between 'first' and 'last' at the position
			 * pointed at by 'position'.
			 *
			 * Iterator is invalidated within the function so dont have to
			 * worry about insert(vec.begin(), vec.begin(), vec.begin() + 1)
			 *
			 * @edit : I have to call the destructor for this.
			 * 
			 * @param 'position' : the position of the element to insert
			 * 	the range of values between first and last into. 
			 * 	Everything after will be shifted to the right.
			 * @param 'first' : the starting of the range of values to fill
			 * 	the vector with.
			 * @param 'last' : the ending of the range of values to fill
			 * 	the vector with.
			 * */

			template<class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, 
						InputIterator>::value_type* = nullptr)
			{
				if (ft::distance(first, last) <= 0)
					return ;
				if (ft::distance(first, last) == 1)
				{
					insert(position, *first);
					return ;
				}

				size_type	ptr_offset = ft::distance(iterator(this->begin()), position);

				size_type	range_len = ft::distance(first, last);
				if (this->size() + range_len > this->capacity())
					this->reserve(this->size() + range_len);

				//cout << endl;
				//cout << "new_capacity : " << this->capacity() << endl;

				//for (int i = 0; i < (int)this->capacity(); i++)
				//	cout << "in : " << (*this)[i] << endl;
				//cout << endl;

				pointer	place_end = this->_end + range_len - 1;
				pointer	take_end = this->_end - 1;
				pointer	pos_ptr = this->_start + ptr_offset;

				//int t = 0;

				//cout << "range_len : " << range_len << endl;
				//cout << "place_end : " << *place_end << endl;
				//cout << "take_end: " << *take_end << endl;
				//cout << "pos_ptr : " << *pos_ptr << endl;
				//for (int i = 0; i < (int)this->capacity(); i++)
				//	cout << t << " out : " << (*this)[i] << endl;
				//cout << endl;

				while (take_end != pos_ptr - 1 && take_end >= this->_start)
				{
					//for (int i = 0; i < (int)this->capacity(); i++)
					//	cout << " in : " << (*this)[i] << endl;
					//cout << endl;
					if (place_end < this->_end)
					{
						//cout << "deleted : " << *place_end << endl;
						this->_alloc.destroy(place_end);
						//cout << "added: " << *take_end << endl;
					}
					this->_alloc.construct(place_end, *take_end);
					take_end--;
					place_end--;
					//t++;
				}

				//cout << "passed" << endl;

				//for (int i = 0; i < (int)this->capacity(); i++)
				//	cout << " out: " << (*this)[i] << endl;
				//cout << endl;

				for (size_type i = range_len; i; i--, place_end--)
				{
					//for (int i = 0; i < (int)this->capacity(); i++)
					//	cout << " in: " << (*this)[i] << endl;
					//cout << endl;
					//cout << "i : " << i  - 1<< endl;
					//cout << "num to reaplace : " << *(first + i - 1) << endl;
					if (place_end < this->_end)
					{
						//cout << "deleted : " << *place_end << endl;
						this->_alloc.destroy(place_end);
						//cout << "added: " << *(first + i -1) << endl;
					}
					this->_alloc.construct(place_end, *(first + i - 1));
					//t++;
				}
				//for (int i = 0; i < (int)this->capacity(); i++)
				//	cout << t << " out: " << (*this)[i] << endl;
				//cout << endl;

				this->_end += range_len;
			}

			/*
			 * Removes a single element pointed at by position.
			 *
			 * The element has to re-shift to fill in the position
			 * of the element that has been removed.
			 *
			 * Returns a value to current element in that position.
			 *
			 * @param 'position' : the position of the element
			 * 	to remove.
			 * */

			iterator erase(iterator position)
			{
				if (position == this->end())
				{
					this->pop_back();
					return (iterator(this->_end - 1));
				}

				size_type	dis	= ft::distance(iterator(this->begin()), position);
				cout << "dis : " << dis << endl;

				//pointer	place_end = this->_end - 2;
				pointer		take_end = this->_end - 1;
				value_type	take_val = *take_end;

				//cout << "place_end : " << *place_end << endl;
				//cout << "take_end : " << *take_end << endl;
				//cout << "take_val : " << take_val << endl;

				//cout << "destroyed : " << *take_end << endl;
				this->_alloc.destroy(take_end);
				take_end--;
				//while (iterator(take_end) != position)
				//for (int i = 0; i < (int)this->capacity(); i++)
				//	cout << "in : " << &(*this)[i] << endl;
				//cout << endl;
				for (size_type j = this->size(); j > dis; j--)
				{
					//for (int i = 0; i < (int)this->capacity(); i++)
					//	cout << "in : " << (*this)[i] << endl;
					//cout << endl;

					value_type	place_val = *take_end;
					//cout << "place_end : " << *place_end << endl;
					//cout << "take_end : " << *take_end << endl;
					//cout << "place_val : " << place_val << endl;
					//cout << "take_val : " << take_val << endl;

					//cout << "destroyed : " << *take_end << endl;
					//cout << "added : " << take_val << endl;
					this->_alloc.destroy(take_end);
					this->_alloc.construct(take_end, take_val);
					//cout << "exit 1 : " << take_end << endl;
					//cout << "exit 1 : " << (this->_start + dis) << endl;
					if (take_end == (this->_start + dis))
					{
						//cout << "broke" << endl;
						break;
					}
					take_val = place_val;
					take_end--;
				}
				//this->_alloc.destroy(place_end);
				//this->_alloc.construct(place_end, take_val);

				this->_end--;

				return (iterator(this->_end + dis));
			}

			/*
			 * Swaps this vector with 'other' vector
			 *
			 * @param 'other' : the other vector to swap with.
			 * */

			void		swap(vector &other)
			{
				pointer	temp_start = this->_start;
				pointer	temp_end = this->_end;
				pointer	temp_capacity = this->_capacity;
				
				this->_start = other._start;
				this->_end = other._end;
				this->_capacity = other._capacity;
				
				other._start = temp_start;
				other._end = temp_end;
				other._capacity = temp_capacity;
			}

			/*
			 * Clears the content of the vector.
			 * It destroys everything in the vector with
			 * alloc.destroy.
			 * Size is set to 0.
			 * Capacity is untouched.
			 * */

			void		clear(void)
			{
				for ( ;this->_end != this->_start; this->_end--)
					this->_alloc.destroy(this->_end);
			}

			//emplace //c++11
			//emplace_back //c++11

			/* Capacity */

			/*
			 * Returns the size of the vector.
			 *
			 * Size in vector means the amount of elements
			 * constructed in the vector.
			 *
			 * ex : {0,1,2,3,4,5, [], [], []} 6/9
			 * 	size = 6, capacity = 9
			 * */

			size_type	size(void) const
			{
				return (this->_end - this->_start);
			}

			/*
			 * Returns the max size of the vector.
			 *
			 * Max size = max possible amount that the
			 * allocator can actually allocate.
			 * */

			size_type	max_size(void) const
			{
				return (this->_alloc.max_size());
			}

			/*
			 * Resizes the vecctor to the amount 'n' with
			 * 'val' as the content.
			 *
			 * If 'n' is less than the vector size the vector will
			 * be destroyed up to 'n' elements.
			 *
			 * If 'n' is more than size the vector will be extended
			 * up to 'n' size and will be filled with 'val' as the
			 * elements.
			 *
			 * @param 'n' : the len to resize the vector to.
			 * @param 'val' : the value to fill the vector with.
			 * 	If no value is passed it will be defaulted to the 
			 * 	defualt constructor of type 'T'
			 * 		ex : ft::vector<int> vec(5);
			 * 		will be filled 5 with default value of int.
			 * 		vec = {0,0,0,0,0}
			 * */

			void		resize(size_type n, value_type val = value_type())
			{
				if (n > this->_alloc.max_size())
					throw std::length_error("ft::vector length_error");

				//content is reduced to its first n elements removing those beyond
				if (n < this->size()) 
				{
					for (pointer i = this->_start + n; i != this->_end; i++)
						this->_alloc.destroy(i);
					this->_end = this->_start + n;
				}
				else
				{
					if (n > this->capacity())
					{
						size_type	new_capacity;
			
						new_capacity = this->capacity();
						while (new_capacity < n)
							new_capacity *= 2;
						this->reserve(new_capacity);
					}
					for (pointer i = this->_end; i < this->_start + n; i++)
						this->_alloc.construct(i, val);
					this->_end = this->_start + n;
				}
			}

			/*
			 * Returns the capacity of the vector.
			 *
			 * The capacity is the amount of space that has been
			 * allocated for the vector.
			 * Size does not have to equal capacity.
			 * If capacity is > size that means there is extra
			 * space in the vector that can be filled later on.
			 * This is done to split up allocation and construction
			 * of memory.
			 *
			 * ex : {0,1,2,3,4,5, [], [], []} 6/9
			 * 	size = 6, capacity = 9
			 * */
			
			size_type	capacity(void) const
			{
				return (this->_capacity - this->_start);
			}

			/*
			 * Returns a true or false depending on wheather or
			 * not the vector is empty.
			 *
			 * Empty in this case means size == 0;
			 * */

			bool		empty(void) const
			{
				if (this->size() == 0)
					return (true);
				return (false);
			}

			/*
			 * Changes the capacity of the vector given by 'n'.
			 *
			 * Reserving a vector will invalidate iterators previously
			 * pointed. As a reallocation may move to a diffrent point in
			 * memory.
			 *
			 * @param 'n' : the len to change the capacity of the vector to.
			 * */

			void		reserve(size_type n)
			{
				//check if max_cap
				if (n > this->_alloc.max_size())
					throw std::length_error("ft::vector length_error");
			
				if (n > this->capacity()) //reallocate and reconstruct new, destroy and deallocate old
				{
					pointer	old_start = this->_start;
					pointer	old_end = this->_end;
					pointer	old_capacity = this->_capacity;
			
					this->_start = this->_alloc.allocate(n); //reallocate
					this->_end = this->_start;
					this->_capacity = this->_start + n;
			
					for (pointer i = old_start; i != old_end; i++) //reconstruct new
						this->_alloc.construct(this->_end++, *i);
			
					for (pointer i = old_start; i != old_end; i++) //destroy
						this->_alloc.destroy(i);
			
					this->_alloc.deallocate(old_start, old_capacity - old_start);
				}
			}

			//void		shrink_to_fit(void); //c++11 feature

			/* Element access */

			/*
			 * The index operator returns a reference to the element
			 * placed at the index of the vector.
			 *
			 * This function specifically doesn't throw error for
			 * out of bounds. Using at() is safer.
			 *
			 * @param 'n' : the position of the element to check.
			 * */

			reference			operator[](size_type n)
			{
				return (this->_start[n]);
			}

			/*
			 * The index operator returns a const reference to the element
			 * placed at the index of the vector.
			 *
			 * This function specifically doesn't throw error for
			 * out of bounds. Usung at() is safer.
			 *
			 * @param 'n' : the position of the element to check.
			 * */

			const_reference		operator[](size_type n) const
			{
				return (this->_start[n]);
			}

			/*
			 * Returns a reference to the element pointed at 
			 * by vector at position n.
			 *
			 * Unlink the index operator this function 
			 * does throw error for out of bounds. 
			 * This is safer than the index operator.
			 *
			 * @param 'n' : the position of the element to check.
			 * */

			reference			at(size_type n)
			{
				if (n > this->size() - 1)
					throw std::out_of_range("ft::vector out_of_range");
				return (this->_start[n]);
			}

			/*
			 * Returns a reference to the
			 * element at the start of the vector.
			 * */

			reference			front(void)
			{
				return (*this->_start);
			}

			/*
			 * Returns a const reference to the 
			 * element at the start of the vector.
			 * */

			const_reference		front(void) const
			{
				return (*this->_start);
			}

			/*
			 * Returns a reference to the element at the back of the vector.
			 * */

			reference			back(void)
			{
				return (*(this->_end - 1));
			}

			/*
			 * Returns a const reference to the element at the back of the vector.
			 * */

			const_reference		back(void) const
			{
				return (*(this->_end - 1));
			}

			//value_type*			data(void) noexcept; //c++11 feature
			//const value_type*	data(void) const noexcept; //c++11 feature

			/* Allocator */

			/*
			 * Returns the underlying allocater being used to allocate
			 * memory.
			 * */

			allocator_type		get_allocator(void) const
			{
				return (this->_alloc);
			}


		private:
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_capacity;

	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (true);
		if (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
				|| ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
	{
		return (rhs <= lhs);
	}
}

/*
	template <class T, class Alloc = std::allocator<T> >
	class	vector
	{
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef typename Alloc::reference									reference;
		typedef typename Alloc::const_reference								const_reference;
		typedef typename Alloc::pointer										pointer;
		typedef typename Alloc::const_pointer								const_pointer;
		typedef ft::vector_iterator<T>										iterator;
		typedef ft::vector_iterator<const T>								const_iterator;
		typedef	ft::reverse_iterator<iterator>								reverse_iterator;
		typedef	ft::reverse_iterator<const iterator>						const_reverse_iterator;
		typedef	typename iterator_traits<iterator>::difference_type			difference_type;
		typedef typename Alloc::size_type									size_type;


		explicit vector(const allocator_type &alloc = allocator_type());
		explicit vector(size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type())

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
				const allocator_type &alloc = allocator_type());

		vector(const vector &other);
		~vector();

		
		vector& operator=(const vector &other);
		iterator			begin(void);
		iterator			end(void);


		void		assign(size_type n, const value_type &val);

		template <class InputIterator>
		void		assign(InputIterator first, InputIterator last);
		void		push_back(const value_type &value);
		void		pop_back(void);
		iterator	insert(iterator position, const value_type& val);
		void 		insert(iterator position, size_type n,
			const value_type& val);

		template<class InputIterator>
		void		insert(iterator position, InputIterator first, 
			InputIterator last);

		iterator erase(iterator position);
		void		swap(vector &other);
		void		clear(void);


		size_type	size(void) const;
		size_type	max_size(void) const;
		void		resize(size_type n, value_type val = value_type());
		size_type	capacity(void) const;
		bool		empty(void) const;
		void		reserve(size_type n);
		reference	operator[](size_type n);


		const_reference		operator[](size_type n) const;
		reference			at(size_type n);
		reference			front(void);
		const_reference		front(void) const;
		reference			back(void);
		const_reference		back(void) const;


		allocator_type		get_allocator(void) const;


		private:
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
			pointer			_capacity;
	}

	operator==
	operator!=
	operator<
	operator<=
	operator>
	operator>=

*/

#endif
