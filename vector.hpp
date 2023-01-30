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

		template <class InputIterator>
		void		insert(iterator position, InputIterator first, 
						InputIterator last);

		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last);
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
		reference			at(size_type pos);
		const_reference		at(size_type pos) const;
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

	bool operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);
	bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs);

*/
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
			typedef	ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef	typename iterator_traits<iterator>::difference_type			difference_type;
			typedef typename Alloc::size_type									size_type;


		private:

			allocator_type		_alloc;
			pointer				_start;
			pointer				_end;
			pointer				_capacity;

		public:

			/*
			 * defualt constructor.
			 * Constructs an empty container with no elements.
			 *
			 * @param 'alloc' : allocater to be used to allocate memory for vector.
			 * 	If no allocater is passed in allloc default value defaulted to 
			 * 	std::allocator constructor.
			 * */

			explicit vector(const allocator_type &alloc = allocator_type()) :
				_alloc(alloc),
				_start(nullptr),
				_end(nullptr),
				_capacity(nullptr)
			{
#ifdef	PRINT_MSG
					cout << GREEN "Vector Empty Containter Constructor called" RESET << endl;
#endif
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
#ifdef	PRINT_MSG
					cout << GREEN "Vector Fill Constructor called" RESET << endl;
#endif

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
						InputIterator>::type* = nullptr) :
				_alloc(alloc)
			{
#ifdef	PRINT_MSG
				cout << GREEN "Vector Range Constructor called" RESET << endl;
#endif
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
#ifdef PRINT_MSG
				cout << GREEN "Vector Copy Constructor called" RESET << endl;
#endif
				for (int i = 0; i < (int)other.size(); i++, this->_end++)
					this->_alloc.construct(this->_end, other[i]);
			}

			/*
			 * destructor.
			 * Destroys all elements up to size.
			 * Deallocates all storage up to capacity.
			 *
			 * @note : I dont have to handle anything after
			 * 	destructor is called, so link can be ignored
			 * 	just left it for info
			 *
			 * https://stackoverflow.com/questions/9584660/does-the-default-allocator-zeroize-int
			 * Just pasting this here as idk how to completely tell the program that
			 * I have destroyed an object in that space. Specifically int.
			 * */

			~vector()
			{
#ifdef	PRINT_MSG
				cout << RED "Vector Destructor called" RESET << endl;
#endif
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
				return iterator(this->_start);
			}

			/*
			 * begin returns a const iterator to the start of the vector.
			 * */

			const_iterator			begin(void) const
			{
				return (const_iterator(this->_start));
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
				return (const_reverse_iterator(this->end()));
			}

			/*
			 * end returns an iterator to the end of the vector.
			 * */

			iterator				end(void)
			{
				return iterator(this->_end);
			}

			/*
			 * end returns a const_iterator to the end of the vector.
			 * */

			const_iterator			end(void) const
			{
				return const_iterator(this->_end);
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
				return (const_reverse_iterator(this->begin()));
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
			 * @note : Something wrong with requires pointer 
			 * indirection when other assign is called.
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
					InputIterator>::type* = nullptr)
			{
				size_type	len = ft::distance(first, last);

				this->clear();
				this->reserve(len);
				for (InputIterator i = first; i != last; i++, this->_end++)
					this->_alloc.construct(this->_end, *i);
			}

			/*
			 * push_back.
			 * Adds an element to the end of the vector.
			 *
			 * If the vector size is 0. capacity and size will change to 1.
			 * If the vector is full. The vector will double in capacity.
			 *
			 * @param 'value' : the value to be added to the back of the vector.
			 * */

			void		push_back(const value_type &value)
			{
				if (this->_end == this->_capacity)
				{
					size_type	new_capacity = 
						(this->capacity() == 0) ? 1 : (this->_capacity - this->_start) * 2;
					this->reserve(new_capacity);
				}
				this->_alloc.construct(this->_end++, value);
			}

			/*
			 * pop_back.
			 * Removes the last element from the vector.
			 *
			 * If the container is not empty, the function never throws exceptions 
			 * (no-throw guarantee). Otherwise, it causes undefined behavior.
			 * */

			void		pop_back(void)
			{
				this->_alloc.destroy(this->_end - 1);
				this->_end--;
			}

			/*
			 * single element insert
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
				if (this->_end == this->_capacity && position == this->end())
				{
					this->push_back(val);
					return (this->end() - 1);
				}

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
			 * fill insert.
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
			 * @edit : Just did the math wrong just ask YZ i think he told me
			 * 	the pattern.
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

				size_type	temp_distance = ft::distance(this->begin(), position);

				if (this->size() + n > this->capacity())
					this->reserve(this->size() + n);

				pointer		take_end = this->_end - 1;
				pointer		place_end = this->_end - 1 + n;
				size_type	temp_n = n;
				
				for (int i = ((int)this->size() - temp_distance); i ; i--)
				{
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
						InputIterator>::type* = nullptr)
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

				pointer	place_end = this->_end + range_len - 1;
				pointer	take_end = this->_end - 1;
				pointer	pos_ptr = this->_start + ptr_offset;

				while (take_end != pos_ptr - 1 && take_end >= this->_start)
				{
					if (place_end < this->_end)
						this->_alloc.destroy(place_end);
					this->_alloc.construct(place_end, *take_end);
					take_end--;
					place_end--;
				}

				InputIterator	temp = --last;

				for (size_type i = range_len; i > 0; i--, place_end--, temp--)
				{
					if (place_end < this->_end)
						this->_alloc.destroy(place_end);
					this->_alloc.construct(place_end, *(temp));
				}
				this->_end += range_len;
			}

			/*
			 * single erase.
			 * Removes a single element pointed at by position.
			 *
			 * The element has to re-shift to fill in the position
			 * of the element that has been removed.
			 *
			 * Returns a value to current element in that position.
			 *
			 * If position == end() just let it crash.
			 * If position == end() - 1:
			 * 	pop_back()
			 *
			 * @param 'position' : the position of the element
			 * 	to remove.
			 * */

			iterator	erase(iterator position)
			{
				if (position == this->end() - 1)
				{
					this->pop_back();
					return (this->end());
				}

				size_type	dis	= ft::distance(iterator(this->begin()), position);
				pointer		take_end = this->_end - 1;
				value_type	take_val = *take_end;

				this->_alloc.destroy(take_end);
				take_end--;
				for (size_type j = this->size(); j > dis; j--)
				{
					value_type	place_val = *take_end;
					this->_alloc.destroy(take_end);
					this->_alloc.construct(take_end, take_val);
					if (take_end == (this->_start + dis))
						break;
					take_val = place_val;
					take_end--;
				}
				this->_end--;
				return (iterator(this->_start + dis));
			}

			/*
			 * range erase.
			 * Removes a range of elements pointed at between first and last.
			 *
			 * The element has to re-shift to fill in the position
			 * of the element that has been removed.
			 *
			 * Returns a value to current element in that position.
			 *
			 * If distance 0 do let it break.
			 * If distance 1 use normal erase.
			 *
			 * @note: 
			 * 	first for loop is for replacing the to_del values with the values
			 * 	at the front
			 * 	this has to be done for as long as place_pos != _end
			 * 	vec.delete(vec.begin(), vec.begin() + 2)
			 * 		[3,6,9,12,15]
			 * 		replacing 3 with 9 (3 + dis)
			 * 		[9,6,9,12,15]
			 * 		replacing 6 with 12 (6 + dis)
			 * 		[9,12,9,12,15]
			 * 		replacing 9 with 15 (9 + dis)
			 * 		[9,12,15,12,15]
			 *
			 * 	second loop is for deleting the amount of elements at the end
			 * 	this is almost done dis amount of times.
			 * 		[9,12,15,12,15] -> [9,12,15,_,15]
			 * 		[9,12,15,_,15] -> [9,12,15,_,_]
			 *
			 * @param 'first' : the starting of the range of values to erase
			 * 	the vector with.
			 * @param 'last' : the ending of the range of values to erase
			 * 	the vector with.
			 * */

			iterator	erase(iterator first, iterator last)
			{
				if (ft::distance(first, last) <= 1)
				{
					if (ft::distance(first, last) == 0)
						return (last);
					return (erase(first));
				}

				size_type	dis = ft::distance(first, last);
				size_type	first_dis = ft::distance(this->begin(), first);
				pointer	take_pos = this->_start + ft::distance(this->begin(), first);
				pointer	place_pos = take_pos + dis;

				for (size_type i = this->size() - dis; place_pos != this->_end; i--, take_pos++, place_pos++)
				{
					this->_alloc.destroy(take_pos);
					this->_alloc.construct(take_pos, *place_pos);
				}

				for (size_type i = dis; i; i--, take_pos++)
				{
					this->_alloc.destroy(take_pos);
				}

				this->_end -= dis;
				return (iterator(this->_start + first_dis));
			}

			/*
			 * swap.
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
			 * clear.
			 * Clears the content of the vector.
			 *
			 * It calles the destructor of all the elements in the vector.
			 * Size is set to 0.
			 * Capacity is untouched.
			 * */

			void		clear(void)
			{
				for ( ;this->_end != this->_start; this->_end--)
					this->_alloc.destroy(this->_end);
			}

			/* Capacity */

			/*
			 * size.
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
			 * max_size.
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
			 * resize.
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
			 * capacity.
			 * Returns the capacity of the vector.
			 *
			 * The capacity is the amount of space that has been
			 * allocated for the vector.
			 * Size does not have to equal capacity.
			 * If capacity is > size that means there is extra
			 * space in the vector that can be filled later on.
			 * This is done to optimize the amount of times a vector
			 * has to allocate memory.
			 *
			 * ex : {0,1,2,3,4,5, [], [], []} 6/9
			 * 	size = 6, capacity = 9
			 * */
			
			size_type	capacity(void) const
			{
				return (this->_capacity - this->_start);
			}

			/*
			 * empty.
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
			 * reserve.
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
			 * at.
			 * Returns a reference to the element pointed at 
			 * by vector at position pos.
			 *
			 * Unlink the index operator this function 
			 * does throw error for out of bounds. 
			 * This is safer than the index operator.
			 *
			 * @param 'pos' : the position of the element to check.
			 * */

			reference			at(size_type pos)
			{
				if (pos > this->size() - 1)
					throw std::out_of_range("ft::vector out_of_range");
				return (this->_start[pos]);
			}

			/*
			 * at.
			 * Returns a reference to the element pointed at 
			 * by vector at position pos.
			 *
			 * Unlink the index operator this function 
			 * does throw error for out of bounds. 
			 * This is safer than the index operator.
			 *
			 * @param 'pos' : the position of the element to check.
			 * */

			const_reference	at(size_type pos) const
			{
				if (pos > this->size() - 1)
					throw std::out_of_range("ft::vector out_of_range");
				return (this->_start[pos]);
			}

			/*
			 * front.
			 * Returns a reference to the
			 * element at the start of the vector.
			 * */

			reference			front(void)
			{
				return (*this->_start);
			}

			/*
			 * front.
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

			/* Allocator */

			/*
			 * get_allocator.
			 * Returns the underlying allocater being used to allocate
			 * memory.
			 * */

			allocator_type		get_allocator(void) const
			{
				return (this->_alloc);
			}
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

#endif
