#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>

using std::cout;
using std::endl;

namespace ft
{
	/*
	 * iterator is implemented as a struct as it doesnt have much need 
	 * for private variables. Since the only difference between class and 
	 * struct is only defaulted to private or defautled to public,
	 * iterator is implemented as a struct instead of a class.
	 * */

	/*
	 * std::ptrdiff_t is the signed integer type of the result 
	 * of subtracting two pointers. 
	 * */

	template <
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T& >
	struct	iterator
	{
		/* Member types */
		typedef	Category	iterator_category;
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef Reference	reference;
	};

	/*
	 * An empty iterator tag for that specific iterator.
	 * Used to catogorize iterators.
	 * */

	struct	vector_iterator_tag {};

	struct	map_iterator_tag {};

	/*
	 * Iterator_traits is the type trait class that provides uniform interface.
	 * This makes it possible to implement algorithms in terms of ONLY iterators.
	 *
	 * @note : seems very redundent to have it like this.
	 *
	 * @template 'Iter' : Passing the unkown Iterator as the template
	 * */

	template <class Iter>
	struct	iterator_traits
	{
		typedef	typename Iter::iterator_category	iterator_category;
		typedef	typename Iter::value_type			value_type;
		typedef	typename Iter::difference_type		difference_type;
		typedef	typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	};

	/*
	 * Iterator_traits is the type trait class that provides uniform interface.
	 * This makes it possible to implement algorithms in terms of ONLY iterators.
	 *
	 * @template 'T' : Passing the unkown type T as the template
	 * */

	template <class T>
	struct	iterator_traits<T*>
	{
		typedef	vector_iterator_tag	iterator_category;
		typedef	T					value_type;
		typedef	std::ptrdiff_t		difference_type;
		typedef	T*					pointer;
		typedef	T&					reference;
	};

	/*
	 * Iterator_traits is the type trait class that provides uniform interface.
	 * This makes it possible to implement algorithms in terms of ONLY iterators.
	 *
	 * @template 'T' : Passing the unkown type const T as the template
	 * */

	template <class T>
	struct	iterator_traits<const T*>
	{
		typedef	vector_iterator_tag	iterator_category;
		typedef	T					value_type;
		typedef	std::ptrdiff_t		difference_type;
		typedef	T*					pointer;
		typedef	T&					reference;
	};

	/*
	 * Default Template Specilizaiton for enable_if.
	 *
	 * If the value of B is false, The value of T
	 * will = void, so it will be pointing to a nullptr.
	 * This is required as templates cant have a defaulted value before
	 * c++11. By doing this we can intead pass in enable_if to
	 * funciton variables instead of the template variables. And we cant set
	 * the default value to be pointing to nullptr.
	 * */

	template <bool B, class T = void>
	struct	enable_if { };

	template <class T>
	struct	enable_if<true, T>
	{
		typedef	T		type;
	};

	/*
	 * A speciliazation template to check weather the type is an integral or not.
	 * Will return true if type is bool, char, char16_t, 
	 * char32_t, wchar_t, short, int, long, long long
	 *
	 * @edit : have to include extended interger types wtv the fuck that includes 
	 *
	 * If is_integral<int> is called it will specifically find if there is
	 * any template with the int specilization. If not it will go into
	 * general specilization template.
	 *
	 * @param 'T' : the class we want to check the type of.
	 * */

	template <bool is_integral, class T>
	struct	is_integral_base
	{
		typedef	T			type;
		static const bool	value = is_integral;
	};

	template <class T>
	struct is_integral : is_integral_base<false, T> { };

	template <>
	struct is_integral<bool> : is_integral_base<true, bool> { };

	template <>
	struct is_integral<char> : is_integral_base<true, char> { };

	template <>
	struct is_integral<char16_t> : is_integral_base<true, char16_t> { };

	template <>
	struct is_integral<char32_t> : is_integral_base<true, char32_t> { };

	template <>
	struct is_integral<wchar_t> : is_integral_base<true, wchar_t> { };

	template <>
	struct is_integral<short> : is_integral_base<true, short> { };

	template <>
	struct is_integral<int> : is_integral_base<true, int> { };

	template <>
	struct is_integral<long> : is_integral_base<true, long> { };

	//long long is a c++11 feature
	//template <>
	//struct is_integral<long long> : is_integral_base<true, long long> { };
	

	/*
	 * Reverse Iterator
	 *
	 * @edit : might have to add non member functions 
	 * (comparison and +- operators)
	 * */

	template <class Iter>
	class reverse_iterator
	{
		public:
			typedef	Iter													iterator_type;
			typedef	typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef	typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef	typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef	typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef	typename ft::iterator_traits<Iter>::reference			reference;
	
			/*
			 * (1) Default Constructor.
			 * 	Constructs an empty reverse iterator.
			 * (2) Initilization Constructor.
			 * 	Constructs a reverse iterator from an object that
			 * 	was not neccerily a reverse iterator.
			 * (3) Copy Constructor.
			 * 	Constructs a reverse iterator from another reverse
			 * 	iterator.
			 *
			 * Copy Assignment Operator.
			 * */
	
			reverse_iterator() : _iter() {}
			explicit reverse_iterator(iterator_type it) : _iter(it) {}
			reverse_iterator(const reverse_iterator<Iter> &rev_it) : _iter(rev_it._iter) {}

			reverse_iterator	&operator=(const reverse_iterator &other)
			{
				this->_iter = other._iter;
				return (*this);
			}

			/*
			 * Reverse Iterator Destructor.
			 * */

			virtual ~reverse_iterator() {};

			bool operator==(const reverse_iterator &other) const { return this->_iter == other._iter ? true : false; }
			bool operator!=(const reverse_iterator &other) const { return this->_iter != other._iter ? true : false; }
			bool operator>(const reverse_iterator &other) const { return this->_iter > other._iter; }
			bool operator>=(const reverse_iterator &other) const { return this->_iter >= other._iter; }
			bool operator<(const reverse_iterator &other) const { return this->_iter < other._iter; }
			bool operator<=(const reverse_iterator &other) const { return this->_iter <= other._iter; }
	
			//operator	reverse_iterator<const Iter>(void)	const
			//{
			//	return (reverse_iterator<const Iter>(this->_iter));
			//	//return (reverse_iterator<const Iter>(reinterpret_cast<const reverse_iterator>(_iter)));
			//}

			//operator	const reverse_iterator(void)
			//{
			//	return this->_iter;
			//}

			/*
			 * Returns a copy of the base iterator.
			 * */
	
			iterator_type base(void) const { return this->_iter; }
	
			reverse_iterator	operator+(difference_type n) const
			{
				return (reverse_iterator(this->_iter - n));
			}

			/*
			 * Prefix Increament operator.
			 *
			 * Returns the already increamented iterator.
			 * */

			reverse_iterator	&operator++()
			{
				this->_iter--;
				return (*this);
			}

			/*
			 * Postfix Increament operator.
			 *
			 * Returns the iterator before being increamented.
			 * */

			reverse_iterator	operator++(int)
			{
				reverse_iterator	temp = *this;
				--this->_iter;
				return (temp);
			}

			reverse_iterator	&operator+=(difference_type n)
			{
				this->_iter -= n;
				return (*this);
			}

			reverse_iterator	operator-(difference_type n) const
			{
				return (reverse_iterator(this->_iter + n));
			}

			/*
			 * Prefix Decrement operator.
			 *
			 * Returns the already decrementedd iterator.
			 * */

			reverse_iterator	&operator--()
			{
				this->_iter++;
				return (*this);
			}

			/*
			 * Postfix Decrement operator.
			 *
			 * Returns the iterator before being decremented.
			 * */

			reverse_iterator	operator--(int)
			{
				reverse_iterator	temp = *this;
				++this->_iter;
				return (temp);
			}

			reverse_iterator	&operator-=(difference_type n)
			{
				this->_iter += n;
				return (*this);
			}

			/*
			 * Returns a reference to the element pointed at by iterator.
			 *
			 * It returns a decremented copy of the base iterator.
			 * */
	
			reference	operator*() const
			{
				iterator_type	temp = _iter;
				return *(--temp);
			}

			/*
			 * Returns a pointer to the element pointed to by the iterator
			 * (in order to access one of its members).
			 * */

			pointer		operator->() const
			{
				return *(operator*());
			}

			/*
			 * Returns a reference to the object pointed at by the pointer
			 * at said index.
			 * */
	
			reference	operator[](difference_type n) const
			{
				iterator_type	temp = _iter;
				return *(--temp - n);
			}

		private:
			iterator_type	_iter;
	};

	/*
	 * distance.
	 *
	 * Gets the distance between 2 iterators.
	 *
	 * @param 'first' : The iterator at the starting point of the distance.
	 * @param 'last' : The iterator at the end point of the distance.
	 * */


	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last)
	{
		typename InputIterator::difference_type	distance = 0;

		for (; first != last; distance++, first++) ;
		return (distance);
		//if (first < last)
		//	for (; first != last; distance++, first++) ;
		//else
		//	for (; first != last; distance--, first--) ;
		//return (distance);
	}

	/*
	 * equal equality.
	 *
	 * equal checks wheather all values of the second container are
	 * equal to the to all the values in the first container within
	 * the passed in range.
	 *
	 * This function does not have a boundary check. If the second iterator
	 * is shorter than the first iterator it is to be handled by the user.
	 *
	 * @param 'first1' : the iterator to the start of the first container.
	 * @param 'last1' : the iterator to the end of the first container.
	 * @param 'first2' : the iterator to the start of the second container.
	 * */

	template <class InputIterator, class InputIterator2>
	bool	equal(InputIterator first1, InputIterator last1,
				InputIterator2 first2)
	{
		for (; first1 != last1; first1++, first2++)
			if (*first1 != *first2)
				return (false);
		return (true);
	}

	/*
	 * equal predicate. 
	 *
	 * Equal checks wheather all values of the second container are
	 * equal as according to the binary predicate passed in 
	 * to the to all the values in the first container within
	 * the passed in range.
	 *
	 * This function does not have a boundary check. If the second iterator
	 * is shorter than the first iterator it is to be handled by the user.
	 *
	 * @param 'first1' : the iterator to the start of the first container.
	 * @param 'last1' : the iterator to the end of the first container.
	 * @param 'first2' : the iterator to the start of the second container.
	 * @param 'p' : the binary predicate to do the comparison with.
	 * 	Basically a funciton pointer that is used to compare val1 with val2.
	 *	ex :
	 *		bool	p(int val1, int val2)
	 *		{
	 *			if (val1 == val2)
	 *				return true;
	 *			return false;
	 *		}
	 * */

	template <class InputIterator, class InputIterator2, class BinaryPredicate>
	bool	equal(InputIterator first1, InputIterator last1,
				InputIterator2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; first1++, first2++)
			if (!p(*first1, *first2))
				return (false);
		return (true);
	}

	/*
	 * default lexicographical_compare.
	 *
	 * Checks wheather the range of 'first1' to 'last1' is 
	 * lexicographically less than 'first2' to 'last2'.
	 *
	 * Unlike equal this has a boundry check for the second range.
	 *
	 * @param 'first1' : the iterator to the start of the first container.
	 * @param 'last1' : the iterator to the end of the first container.
	 * @param 'first2' : the iterator to the start of the second container.
	 * @param 'last1' : the iterator to the end of the second container.
	 * */

	template <class InputIterator, class InputIterator2>
	bool	lexicographical_compare(InputIterator first1, InputIterator last1,
				InputIterator2 first2, InputIterator2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); first1++, first2++)
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	/*
	 * custom lexicographical_compare.
	 *
	 * Checks wheather the range of 'first1' to 'last1' is 
	 * lexicographically less than 'first2' to 'last2'
	 * as according to the 'comp' function passed in.
	 *
	 * Unlike equal this has a boundry check for the second range.
	 *
	 * @param 'first1' : the iterator to the start of the first container.
	 * @param 'last1' : the iterator to the end of the first container.
	 * @param 'first2' : the iterator to the start of the second container.
	 * @param 'last1' : the iterator to the end of the second container.
	 * @param 'comp' : the funciton to compare to compare the 2 values with.
	 * */

	template <class InputIterator, class InputIterator2, class Compare>
	bool	lexicographical_compare(InputIterator first1, InputIterator last1,
				InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		for (; first1 != last1 && first2 != last2; first1++, first2++)
		{
			if (comp(*first1 ,*first2))
				return (true);
			if (comp(*first2 , *first1))
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}

	/*
	 * Pair
	 * */

	template <class T1, class T2>
	struct	pair
	{
		typedef	T1			first_type;
		typedef	T2			second_type;

		/*
		 * default constructor.
		 * */

		pair() : 
			first(),
			second()
		{ }

		/*
		 * copy constructor.
		 * */

		template <class U, class V>
		pair(const pair<U,V> &pr) :
			first(pr.first),
			second(pr.second)
		{ }

		/*
		 * initialization constructor.
		 * */

		pair(const first_type &a, const second_type &b) :
			first(a),
			second(b)
		{ }

		/*
		 * copy assignment operator.
		 * */

		pair	&operator=(const pair &pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}

		/*
		 * make_pair.
		 * */

		T1		first;
		T2		second;
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	}

	template <class T1, class T2>
	bool	operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template <class T1, class T2>
	bool	operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool	operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (lhs.first < rhs.first ||
			(!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool	operator<=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool	operator>(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool	operator>=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return (!(lhs < rhs));
	}

	/*
	 * remove_const.
	 *
	 * Bullshit I have to add to fix const_conversion. Idk if this is right or not.
	 * Just saw someone else do it.
	 * */

	template<class T> struct remove_const { typedef T type; };
	template<class T> struct remove_const <const T> { typedef T type; };

}

#endif
