#include <algorithm>
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

void	vector_insert_1()
{
	cout << CYAN "Testing vector insert using " << xstr(NAME_SPACE) RESET << endl;
	NAME_SPACE::vector<int>	vec(10);
	NAME_SPACE::vector<int>	vec2;
	//ft::vector<int>	vec3;

	for (int i = 0; i < (int)vec.size(); i++)
		vec[i] = (vec.size() - i) * 3;

	print_vec_info(vec, "vec initial");

	vec2.insert(vec2.end(), 42);
	print_vec_info(vec2, "vec2 after insert 42");

	vec2.insert(vec2.begin(), 2, 21);
	print_vec_info(vec2, "vec2 after insert 2 21's");

	vec2.insert(vec2.end() - 2, 42);
	print_vec_info(vec2, "vec2 after insert 42, 2 pos from end");

	vec2.insert(vec2.end(), 2, 84);
	print_vec_info(vec2, "vec2 after insert 2 84's at end");
}

void	vector_insert_2()
{
	cout << CYAN "Testing vector insert using " << xstr(NAME_SPACE) RESET << endl;
	NAME_SPACE::vector<int> vec(5);
	NAME_SPACE::vector<int> vec2;
	const int cut = 3;

	for (unsigned long int i = 0; i < vec.size(); ++i)
		vec[i] = (vec.size() - i) * 7;
	print_vec_info(vec, "initial");

	vec2.insert(vec2.begin(), vec.begin(), vec.begin() + cut);
	print_vec_info(vec2, "vector 2 after test [1]");

	vec2.insert(vec2.begin(), vec.begin() + cut, vec.end());
	print_vec_info(vec2, "vector 2 after test [2]");
	vec2.insert(vec2.end(), vec.begin(), vec.begin() + cut);
	print_vec_info(vec2, "vector 2 after test [3]");

	std::cout << "insert return:" << std::endl;

	std::cout << *vec2.insert(vec2.end(), 42) << std::endl;
	std::cout << *vec2.insert(vec2.begin() + 5, 84) << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	print_vec_info(vec2, "final");
}

void vector_insert()
{
	vector_insert_1();
	vector_insert_2();
}
