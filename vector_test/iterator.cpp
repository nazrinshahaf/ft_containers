#include <algorithm>
#include <cstddef>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <memory>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <time.h>
#include "../colours.h"

#include "../vector.hpp"
#include "./utils.hpp"

#define xstr(x) str(x)
#define str(x) #x

using std::cout;
using std::endl;
using std::string;

void	prepost_incdec(NAME_SPACE::vector<int> &vct)
{
	NAME_SPACE::vector<int>::iterator it = vct.begin();
	NAME_SPACE::vector<int>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
}

void	vector_iterator_1()
{
	cout << CYAN "Testing vector iterator using " << xstr(NAME_SPACE) RESET << endl << endl;

	const int size = 5;
	NAME_SPACE::vector<int> vec(size);
	NAME_SPACE::vector<int>::iterator it = vec.begin();
	//NAME_SPACE::vector<int>::const_iterator ite = vec.begin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	print_vec_info(vec, "initial");
	prepost_incdec(vec);

	cout << "it begin(): " << *it << endl;
	cout << "it begin() + 1: " << *(it + 1) << endl;
	cout << &*(it) << endl;
	it = 1 + it;
	cout << &*it << endl;
	cout << "it + 1: " << *it << endl;

	it = it + 5;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
	std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	cout << endl;
	print_vec_info(vec, "final");
}

void vector_iterator()
{
	vector_iterator_1();
}
