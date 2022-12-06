#ifndef	STACK_HPP
# define STACK_HPP

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
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	T								value_type;
			typedef Container						container_type;
			typedef	size_t							size_type;

		/*
		 * default constructor.
		 * empty constructor.
		 *
		 * Consturcts an empty stack which calls the underlying containers
		 * default constructor.
		 *
		 * @param 'ctnr' : the underlying container type to be used for stack.
		 * 	If no container is passed in, the value will be defaulted to using
		 * 	ft::vector
		 * */

		explicit stack(const container_type &ctnr = container_type()) :
			_container(ctnr)
		{
			if (this->_print_msg)
				cout << GREEN "Stack Empty Containter Constructor called" RESET << endl;
		}

		/*
		 * copy constructor
		 *
		 * Constructs a copy of stack 'other'.
		 *
		 * @param 'other' : the stack to be copied.
		 * */

		stack(const stack &other) :
			_container(other._container)
		{
			if (this->_print_msg)
				cout << GREEN "Stack Copy Constructor called" RESET << endl;
		}

		/*
		 * desturctor.
		 *
		 * Destryos all elements in the stack.
		 *
		 * Calles the underlying containers destructor.
		 * */

		~stack()
		{
			if (this->_print_msg)
				cout << RED "Stack Destructor Constructor called" RESET << endl;
		}

		/*
		 * top.
		 *
		 * Returns the top most element of the stack.
		 * (Last element)
		 * */

 		value_type	&top(void)
		{
			return (this->_container.back());
		}

		const value_type	&top(void) const
		{
			return (this->_container.back());
		}

		/*
		 * empty.
		 *
		 * Returns a true or false depending on wheather
		 * or not the stack size == 0.
		 * */

		bool	empty(void) const
		{
			return (this->_container.empty());
		}

		/*
		 * size.
		 *
		 * Returns the size of the stack.
		 * */

		size_type	size(void) const
		{
			return (this->_container.size());
		}

		/*
		 * push.
		 *
		 * Adds 'value' to the last position of the stack.
		 *
		 * @param 'value' : value to be added to the stack.
		 * */

		void	push(const value_type &value)
		{
			this->_container.push_back(value);
		}

		/*
		 * pop.
		 *
		 * Removes the last element of the stack.
		 * */

		void	pop(void)
		{
			this->_container.pop_back();
		}

		friend bool	operator==(const stack<T,Container> &lhs,
				const stack<T,Container> &rhs)
		{
			return (lhs._container == rhs._container);
		}

		friend bool	operator!=(const stack<T,Container>& lhs,
				const stack<T,Container>& rhs)
		{
			return (lhs._container != rhs._container);
		}

		friend bool	operator<(const stack<T,Container>& lhs,
				const stack<T,Container>& rhs)
		{
			return (lhs._container < rhs._container);
		}

		friend bool	operator<=(const stack<T,Container>& lhs,
				const stack<T,Container>& rhs)
		{
			return (lhs._container <= rhs._container);
		}

		friend bool	operator>(const stack<T,Container>& lhs,
				const stack<T,Container>& rhs)
		{
			return (lhs._container > rhs._container);
		}

		friend bool	operator>=(const stack<T,Container>& lhs,
				const stack<T,Container>& rhs)
		{
			return (lhs._container >= rhs._container);
		}

		protected:
			Container		_container;

		private:
			const static int	_print_msg = 1;
	};
}

/*
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	T								value_type;
			typedef Container						container_type;
			typedef	size_t							size_type;

		explicit stack(const container_type &ctnr = container_type());
		stack(const stack &other);
		~stack();

 		value_type			&top(void);

		const value_type	&top(void) const;

		bool		empty(void) const;
		size_type	size(void) const;

		void	push(const value_type &value);
		void	pop(void);

		operator==
		operator!=
		operator>
		operator>=
		operator<
		operator<=

		protected:
			Container		_container;

		private:
			const static int	_print_msg = 1;
	};
*/

#endif
