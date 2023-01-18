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
#include "colours.h"

#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include "map_iterator.hpp"
#include "red_black_tree.hpp"

//#include "vector_test/insert.cpp"
#include "vector_test/iterator.cpp"

using std::cout;
using std::endl;
using std::string;

class	myint
{
	public:
		myint() : _val(0) {
			cout << MAGENTA "MY INT BASE CONSTRUCTED" RESET << endl;
		}
		myint(int n) : _val(n) {
			cout << MAGENTA "MY INT CONSTRUCTED" RESET << endl;
		}
		myint(myint const &n) : _val(n._val) {
			cout << MAGENTA "MY INT COPY CONSTRUCTED" RESET << endl;
		}
		~myint() {
			cout << GREEN "MY INT DESTROYED" RESET << endl;
		}
		friend std::ostream& operator<<(std::ostream& os, const myint& mi);
	
	private:
		int	_val;
};

std::ostream& operator<<(std::ostream& os, const myint& mi)
{
	os << mi._val;
    return os;
}

bool	comparison_fnc(int v1, int v2)
{
	if (v1 == v2)
		return true;
	return false;
}

template <class T>
#ifdef	TO_TEST
void	test_vec_erase(std::vector<T> const &vec, typename std::vector<T>::const_iterator const &it)
#else
void	test_vec_erase(ft::vector<T> const &vec, typename ft::vector<T>::const_iterator const &it)
#endif
{
	cout << "IN TEST CASE" << endl;
	cout << *it << endl;
	cout << "erase: " << it - vec.begin() << endl;
}

void	test_actual(char *test)
{
	(void)test;
	cout << MAGENTA "ENTERING TEST_ACTUAL" RESET << endl;
	//std::vector<int> vec;
	//cout << "size = " << vec.size() << endl;
	//cout << "capacity = " << vec.capacity() << endl;
	//cout << "===================" << endl;
	//for (int i = 0; i < 100; i++)
	//{
	//	cout << "i = " << i << endl;
	//	vec.push_back(10);
	//	cout << "size = " << vec.size() << endl;
	//	cout << "capacity = " << vec.capacity() << endl << endl;
	//}
	//cout << "===================" << endl;
	//cout << "size = " << vec.size() << endl;
	//cout << "capacity = " << vec.capacity() << endl;
	//cout << vec.max_size() << endl;

	//std::vector<int> vec(5);
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//vec.reserve(2);
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	
	//std::vector<int> vec(4);
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//vec.push_back(1);
	//vec.push_back(1);
	//vec.push_back(1);
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//try {
	//	std::vector<int> vec(atoi(test));
	//} catch (std::exception &e) {
	//	cout << "execption caught" << endl;
	//	cout << e.what() << endl;	
	//}
	
	//std::vector<int> vec;

	//vec.push_back(5);
	//vec.push_back(5);
	//vec.push_back(5);
	//vec.push_back(5);
	//vec.push_back(5);

	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//vec.resize(2);

	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//cout << vec[0] << endl;
	//cout << vec[1] << endl;

	//vec.resize(3,11231);

	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//cout << vec[0] << endl;
	//cout << vec[1] << endl;
	//cout << vec[2] << endl;

	//vec.resize(17);
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << "num : " << vec[i] << endl;

	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//cout <<  "here" << endl;
	//vec.resize(vec.max_size() - 1);
	
	//std::vector<int>	vec;

	//cout << "max size : " << vec.max_size() << endl;
	//cout << "empty : " << vec.empty() << endl;
	//vec.push_back(1);
	//cout << "empty : " << vec.empty() << endl;
	
	//std::vector<int> vec;

	//for (int i = 0; i < 10; i++)
	//	vec.push_back(i);
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//for (int i = 0; i < 11; i++)
	//	cout << vec.at(i) << endl;

	//std::vector<int> vec;

	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//vec.pop_back();
	//vec.pop_back();
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	
	//std::vector<int> vec;

	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//vec.push_back(123);
	//vec.push_back(123);
	//vec.push_back(123);

	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//vec.assign(2,32);
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//
	//vec.reserve(9);

	//vec.assign(10,32);
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//vec.assign(0, 10);
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;

	//std::vector<int>	vec;
	//std::vector<int>	vec2;

	//for (int i = 0; i < 10; i++)
	//	vec.push_back(i + 100);
	//cout << "Printing contents of vec" << endl;
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//cout << endl;

	//for (int i = 0; i < 5; i++)
	//	vec2.push_back(i + 50);
	//cout << "Printing contents of vec2" << endl;
	//for (int i = 0; i < (int)vec2.size(); i++)
	//	cout << vec2[i] << endl;
	//cout << "size		: " << vec2.size() << endl;
	//cout << "capacity	: " << vec2.capacity() << endl;
	//cout << endl;

	//cout << "Swapping contesnts of 1 with 2" << endl;
	//vec.swap(vec2);
	//cout << "Printing contents of vec" << endl;
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	
	//std::vector<int>	vec;

	//for (int i = 0; i < 15; i++)
	//	vec.push_back(i + 5);
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//cout << endl;

	//cout << "Clearing vec" << endl;
	//vec.clear();
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//cout << vec[0] << endl;
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	
	//std::vector<int>	_int, _int2;

	//for (int i = 0; i < 5; i++)
	//	_int.push_back(10 + i);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << "vec 1 : " << _int[i] << endl;
	//cout << endl;

	//for (int i = 0; i < 10; i++)
	//	_int2.push_back(100 + i);
	//cout << "size		: " << _int2.size() << endl;
	//cout << "capacity	: " << _int2.capacity() << endl;
	//for (int i = 0; i < (int)_int2.size(); i++)
	//	cout << "vec 2 : " << _int2[i] << endl;
	//cout << endl;

	//std::vector<int>::iterator	it_s, it_e;
	//cout << "Filling vec2 with vec1" << endl;
	//it_s = _int.begin();
	//it_e = _int.end();
	//_int2.assign(it_s, it_e);
	//cout << "size		: " << _int2.size() << endl;
	//cout << "capacity	: " << _int2.capacity() << endl;
	//for (int i = 0; i < (int)_int2.size(); i++)
	//	cout << "vec 1 : " << _int2[i] << endl;
	//cout << endl;

	std::vector<int>	_int;
	for (int i = 0; i < 15; i++)
		_int.push_back(10 + i);
	cout << "size		: " << _int.size() << endl;
	cout << "capacity	: " << _int.capacity() << endl;
	for (int i = 0; i < (int)_int.size(); i++)
		cout << "vec 1 : " << _int[i] << endl;
	cout << endl;

	std::vector<int>::iterator	it_s, it_e;
	it_s = _int.begin();
	it_e = _int.end();

	std::vector<int>	_int2(it_s, it_e);
	cout << "size		: " << _int2.size() << endl;
	cout << "capacity	: " << _int2.capacity() << endl;
	for (int i = 0; i < (int)_int2.size(); i++)
		cout << "vec 1 : " << _int2[i] << endl;

}

void	test_vector(void)
{
	//try {
	//	ft::vector<int>		_int(atoi(argv[1]));
	//	_int.reserve(atoi(argv[1]));
	//} catch (std::exception &e) {
	//	cout << "execption caught " << endl;
	//	cout << e.what() << endl;
	//} catch (...)
	//{
	//	cout << "herer" << endl;
	//}

	//ft::vector<int>		_int(4);

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//_int.push_back(12);
	//for (int i = 0; i < 3; i++)
	//	_int.push_back(i);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//_int.push_back(4);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//ft::vector<double>	_double;
	
	//ft::vector<int>	_int;

	//for (int i = 0; i < 5; i++)
	//	_int.push_back(5);

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//cout << "resizing to 2..." << endl;
	//_int.resize(2);

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//cout << "resizing to 5 with value of 123..." << endl;
	//_int.resize(5,123);

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//cout << "resizing to 17 with value of 1..." << endl;
	//_int.resize(17,1);

	//std::vector<int> test;
	//try { test.resize(test.max_size()); } catch (std::exception &e) {cout << e.what() << endl;}
	//try { test.resize(test.max_size() + 1); } catch (std::exception &e) {cout << e.what() << endl;}
	//try { _int.resize(test.max_size()); } catch (std::exception &e) {cout << e.what() << endl;}
	//try { _int.resize(test.max_size() + 1); } catch (std::exception &e) {cout << e.what() << endl;}

	//ft::vector<int> _int;

	//cout << "max size : " << _int.max_size() << endl;
	//cout << "empty : " << _int.empty() << endl;
	//_int.push_back(1);
	//cout << "empty : " << _int.empty() << endl;

	//_int.reserve(11);
	//_int.resize(10, 1);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//
	//_int.shrink_to_fit();
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//cout << "passed" << endl;

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//_int.push_back(123);
	//cout << _int[0] << endl;
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//for (int i = 0; i < 10; i++)
	//	_int.push_back(i + 19823);

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << _int[i] << endl;

	//ft::vector<int> _int;

	//for (int i = 0; i < 10; i++)
	//	_int.push_back(i);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//for (int i = 0; i < 11; i++)
	//	cout << _int.at(i) << endl;
	
	//for (int i = 0; i < 2; i++)
	//	_int.push_back(i + 123);

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//cout << _int.front() << endl;
	//cout << _int.back() << endl;

	//cout << *(_int.data() + 1) << endl;
	
	//ft::vector<int>	_int;

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//_int.pop_back();

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//ft::vector<int>	_int;

	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//_int.push_back(123);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//cout << endl;

	//cout << "testing assign 5,123" << endl;
	//_int.assign(5, 123);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << _int[i] << endl;
	//cout << endl;

	//cout << "testing assign 2,123" << endl;
	//_int.assign(2, 456);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.capacity(); i++)
	//	cout << _int[i] << endl;
	////cout << "here = " << _int[_int.size()] << endl;
	//cout << endl;

	//cout << "testing assign 0" << endl;
	//_int.assign(0, 971);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << _int[i] << endl;
	
	//ft::vector<int>	_int;
	//ft::vector<int>	_int2;

	//for (int i = 0; i < 10; i++)
	//	_int.push_back(i + 100);
	//cout << "Printing contents of _int1" << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << _int[i] << endl;
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//cout << endl;

	//for (int i = 0; i < 5; i++)
	//	_int2.push_back(i + 50);
	//cout << "Printing contents of _int2" << endl;
	//for (int i = 0; i < (int)_int2.size(); i++)
	//	cout << _int2[i] << endl;
	//cout << "size		: " << _int2.size() << endl;
	//cout << "capacity	: " << _int2.capacity() << endl;
	//cout << endl;

	//cout << "Swapping contesnts of 1 with 2" << endl;
	//_int.swap(_int2);

	//cout << "Printing contents of _int1" << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << _int[i] << endl;
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//cout << endl;

	//cout << "Printing contents of _int2" << endl;
	//for (int i = 0; i < (int)_int2.size(); i++)
	//	cout << _int2[i] << endl;
	//cout << "size		: " << _int2.size() << endl;
	//cout << "capacity	: " << _int2.capacity() << endl;
	//cout << endl;
	
	//ft::vector<int>	_int;

	//for (int i = 0; i < 10; i++)
	//	_int.push_back(i);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//_int.clear();
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.capacity(); i++)
	//	cout << _int[i] << endl;
	
	//ft::vector<int>	_int;
	//ft::vector<int>::allocator_type	at;

	//for (int i = 0; i < 10; i++)
	//	_int.push_back(i + 123);

	//at = _int.get_allocator();
	//cout << at.address(_int.front()) << endl;
	
	//ft::vector<int>	_int;
	//ft::vector<int>	_int_cp;

	//for (int i = 0; i < 10; i++)
	//	_int.push_back(i + 10);
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << "int : " << _int[i] << endl;
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;

	//for (int i = 0; i < 5; i++)
	//	_int_cp.push_back(i + 100);
	//for (int i = 0; i < (int)_int_cp.size(); i++)
	//	cout << "int : " << _int_cp[i] << endl;
	//cout << "size		: " << _int_cp.size() << endl;
	//cout << "capacity	: " << _int_cp.capacity() << endl;

	//_int_cp = _int;

	//cout << "size		: " << _int_cp.size() << endl;
	//cout << "capacity	: " << _int_cp.capacity() << endl;
	//for (int i = 0; i < (int)_int_cp.size(); i++)
	//	cout << _int_cp[i] << endl;

	//ft::vector<int>	*_int = new ft::vector<int>();

	//for (int i = 0; i < 10; i++)
	//	_int->push_back(i + 10);
	//for (int i = 0; i < (int)_int->size(); i++)
	//	cout << "int : " << (*_int)[i] << endl;
	//cout << "size		: " << _int->size() << endl;
	//cout << "capacity	: " << _int->capacity() << endl;

	//ft::vector<int>	*_int_cp = new ft::vector<int>(*_int);
	//cout << "size		: " << _int_cp->size() << endl;
	//cout << "capacity	: " << _int_cp->capacity() << endl;
	//for (int i = 0; i < (int)_int_cp->size(); i++)
	//	cout << "int : " << (*_int_cp)[i] << endl;

	//delete _int;

	//cout << "size		: " << _int_cp->size() << endl;
	//cout << "capacity	: " << _int_cp->capacity() << endl;
	//for (int i = 0; i < (int)_int_cp->size(); i++)
	//	cout << "int : " << (*_int_cp)[i] << endl;
	//delete _int_cp;
	

	//ft::vector<int>	_int;

	//for (int i = 0; i < 5; i++)
	//	_int.push_back(10 + i);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << _int[i] << endl;

	//cout << _int.begin() << endl;

	//ft::vector<int>	vec, vec2;

	//for (int i = 0; i < 5; i++)
	//	vec.push_back(10 + i);
	//cout << "size		: " << vec.size() << endl;
	//cout << "capacity	: " << vec.capacity() << endl;
	//for (int i = 0; i < (int)vec.size(); i++)
	//	cout << vec[i] << endl;
	//cout << endl;

	//for (int i = 0; i < 5; i++)
	//	vec2.push_back(10 + i);
	//cout << "size		: " << vec2.size() << endl;
	//cout << "capacity	: " << vec2.capacity() << endl;
	//for (int i = 0; i < (int)vec2.size(); i++)
	//	cout << vec2[i] << endl;
	//cout << endl;


	//ft::vector<int>::iterator	it, it2;
	//it = vec.begin();
	//it2 = vec2.begin();

	//if (*it == *it2)
	//	cout << "true" << endl;
	//else
	//	cout << "false" << endl;
	//cout << endl;

	//for (ft::vector<int>::iterator i = it; i != vec.end(); i++)
	//	cout << "here : " << *i << endl;
	//cout << *vec.begin() << endl;
	

	//ft::vector<int>	_int, _int2;

	//for (int i = 0; i < 5; i++)
	//	_int.push_back(10 + i);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << "vec 1 : " << _int[i] << endl;
	//cout << endl;

	//for (int i = 0; i < 10; i++)
	//	_int2.push_back(100 + i);
	//cout << "size		: " << _int2.size() << endl;
	//cout << "capacity	: " << _int2.capacity() << endl;
	//for (int i = 0; i < (int)_int2.size(); i++)
	//	cout << "vec 2 : " << _int2[i] << endl;
	//cout << endl;

	//ft::vector<int>::iterator	it_s, it_e;
	//cout << "Filling vec2 with vec1" << endl;
	//it_s = _int.begin();
	//it_e = _int.end();
	//_int2.assign(it_s, it_e);
	//cout << "size		: " << _int2.size() << endl;
	//cout << "capacity	: " << _int2.capacity() << endl;
	//for (int i = 0; i < (int)_int2.size(); i++)
	//	cout << "vec 1 : " << _int2[i] << endl;
	//cout << endl;
	

	//ft::vector<int>	_int;
	//for (int i = 0; i < 15; i++)
	//	_int.push_back(10 + i);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << "vec 1 : " << _int[i] << endl;
	//cout << endl;

	//ft::vector<int>::iterator	it_s, it_e;
	//it_s = _int.begin();
	//it_e = _int.end();

	//ft::vector<int>	_int2(it_s, it_e);
	//cout << "size		: " << _int2.size() << endl;
	//cout << "capacity	: " << _int2.capacity() << endl;
	//for (int i = 0; i < (int)_int2.size(); i++)
	//	cout << "vec 1 : " << _int2[i] << endl;
	
	//std::vector<int>	_int;

	//for (int i = 0; i < 15; i++)
	//	_int.push_back(10 + i);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << "vec 1 : " << _int[i] << endl;

	//_int.assign(5, 521);
	//cout << "size		: " << _int.size() << endl;
	//cout << "capacity	: " << _int.capacity() << endl;
	//for (int i = 0; i < (int)_int.size(); i++)
	//	cout << "vec 1 : " << _int[i] << endl;
	
	//{
	//	ft::vector<int>	_int;

	//	for (int i = 0; i < 15; i++)
	//		_int.push_back(10 + i);
	//	cout << "size		: " << _int.size() << endl;
	//	cout << "capacity	: " << _int.capacity() << endl;
	//	for (int i = 0; i < (int)_int.size(); i++)
	//		cout << "vec 1 : " << _int[i] << endl;
	//	cout << endl;

	//	ft::vector<int>::iterator	it_s, it_e;

	//	it_s = _int.begin();
	//	it_e = _int.end();

	//	cout << "begin : " << *it_s << endl;
	//	cout << "end : " << *it_e << endl;
	//	
	//	ft::vector<int>	_int2(it_s, it_e);
	//	cout << "size		: " << _int2.size() << endl;
	//	cout << "capacity	: " << _int2.capacity() << endl;
	//	for (int i = 0; i < (int)_int2.size(); i++)
	//		cout << "vec 1 : " << _int2[i] << endl;
	//	cout << endl;

	//	//if (ft::is_integral<char>::value == true)
	//	//	cout << "true" << endl;
	//	//else
	//	//	cout << "false" << endl;

	//	ft::vector<int>	_int_n = ft::vector<int>(5,123);
	//	cout << "size		: " << _int2.size() << endl;
	//	cout << "capacity	: " << _int2.capacity() << endl;
	//	for (int i = 0; i < (int)_int2.size(); i++)
	//		cout << "vec 1 : " << _int2[i] << endl;
	//	cout << endl;
	//}

	//{
	//	ft::vector<int>	_int;

	//	_int.assign(5, 123);
	//	cout << "size		: " << _int.size() << endl;
	//	cout << "capacity	: " << _int.capacity() << endl;
	//	for (int i = 0; i < (int)_int.size(); i++)
	//		cout << "vec 1 : " << _int[i] << endl;

	//	ft::vector<int>	_int2;
	//	for (int i = 0; i < 15; i++)
	//		_int2.push_back(i + 10);
	//	cout << "size		: " << _int2.size() << endl;
	//	cout << "capacity	: " << _int2.capacity() << endl;
	//	for (int i = 0; i < (int)_int2.size(); i++)
	//		cout << "vec 2 before: " << _int2[i] << endl;
	//	_int2.assign(_int.begin(), _int.end());
	//	cout << "size		: " << _int2.size() << endl;
	//	cout << "capacity	: " << _int2.capacity() << endl;
	//	for (int i = 0; i < (int)_int2.size(); i++)
	//		cout << "vec 2 after : " << _int2[i] << endl;
	//}
	
	//{
	//	ft::vector<int>	_int;

	//	for (int i = 0; i < 1; i++)
	//		_int.push_back(i + 10);
	//	cout << "size		: " << _int.size() << endl;
	//	cout << "capacity	: " << _int.capacity() << endl;
	//	for (int i = 0; i < (int)_int.size(); i++)
	//		cout << "vec 1 : " << _int[i] << endl;

	//	ft::vector<int>::iterator	test = _int.insert(_int.begin(), 61523);
	//	cout << "size		: " << _int.size() << endl;
	//	cout << "capacity	: " << _int.capacity() << endl;
	//	for (int i = 0; i < (int)_int.size(); i++)
	//		cout << "vec 1 : " << _int[i] << endl;
	//	cout << "test : " << *test << endl;
	//	cout << endl << endl;

	//	std::vector<int>	_int2;

	//	for (int i = 0; i < 1; i++)
	//		_int2.push_back(i + 10);
	//	cout << "size		: " << _int2.size() << endl;
	//	cout << "capacity	: " << _int2.capacity() << endl;
	//	for (int i = 0; i < (int)_int2.size(); i++)
	//		cout << "vec 1 : " << _int2[i] << endl;

	//	std::vector<int>::iterator test2 = _int2.insert(_int2.begin(), 61523);
	//	cout << "size		: " << _int2.size() << endl;
	//	cout << "capacity	: " << _int2.capacity() << endl;
	//	for (int i = 0; i < (int)_int2.size(); i++)

	//	cout << "test2 : " << *test2 << endl;
	//}
	
	//{
	//	int	vec_size = 2;
	//	int	insert_count = 10;
	//	int	insert_pos = 0;
	//	int	insert_val = 123;

	//	cout << "insert count : " << insert_count << endl;
	//	cout << "insert_pos : " << insert_pos << endl;
	//	cout << "vec_size : " << vec_size << endl;
	//	cout << endl;

	//	cout << CYAN "Testing ft::vector" RESET << endl;
	//	{
	//		ft::vector<int>	_int;
	//		for (int i = 0; i < vec_size; i++)
	//			_int.push_back(i + 10);
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec 1 : " << _int[i] << endl;
	//		cout << endl;

	//		_int.insert(_int.begin() + insert_pos, insert_count, insert_val);

	//		cout << endl;
	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec 1 : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//	}
	//	cout << endl << endl;
	//	cout << CYAN "Testing std::vector" RESET << endl;
	//	{
	//		std::vector<int>	_int2;
	//		for (int i = 0; i < vec_size; i++)
	//			_int2.push_back(i + 10);
	//		cout << "size		: " << _int2.size() << endl;
	//		cout << "capacity	: " << _int2.capacity() << endl;
	//		for (int i = 0; i < (int)_int2.size(); i++)
	//			cout << "vec 2 : " << _int2[i] << endl;
	//		cout << endl;
	//
	//		_int2.insert(_int2.begin() + insert_pos, insert_count, insert_val);
	//
	//		cout << endl;
	//		for (int i = 0; i < (int)_int2.size(); i++)
	//			cout << "vec 2 : " << _int2[i] << endl;
	//		cout << "size		: " << _int2.size() << endl;
	//		cout << "capacity	: " << _int2.capacity() << endl;
	//	}

	//}
	
	//{
	//	ft::vector<int>	_int;
	//	for (int i = 0; i < 5; i++)
	//		_int.push_back(i + 10);
	//	for (int i = 0; i < (int)_int.size(); i++)
	//		cout << "vec : " << _int[i] << endl;

	//	ft::vector<int>::iterator	first = _int.begin();
	//	ft::vector<int>::iterator	last = _int.end();

	//	cout << "begin : " << *(_int.begin() + 1) << endl;
	//	cout << "end : " << *(_int.end() - 1) << endl;

	//	cout << "first -> last distance : " << ft::distance(first, last) << endl;
	//	cout << "last -> first distance : " << ft::distance(last, first) << endl;
	//}
	
	//{
	//	int	position_shift = 6;
	//	int	vec_size = 6;
	//	cout << "position_shift : " << position_shift << endl;
	//	{
	//		ft::vector<int>	_int;
	//		for (int i = 0; i < vec_size; i++)
	//			_int.push_back(i + 10);
	//
	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//		cout << endl;
	//
	//		cout << "val to remove: " << *(_int.end() - position_shift) << endl;
	//		cout << endl;
	//		_int.erase(_int.end() - position_shift);
	//
	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//		cout << endl;
	//	}
	//	{
	//		std::vector<int>	_int;
	//		for (int i = 0; i < vec_size; i++)
	//			_int.push_back(i + 10);
	//
	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//		cout << endl;
	//
	//		_int.erase(_int.end() - position_shift);
	//
	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//		cout << endl;
	//	}
	//}
	
	//{
	//	int	vec_size = 5;
	//	int	pos_offset = 2;
	//	int	insert_size = 1;

	//	cout << "vec size : " << vec_size << endl;
	//	cout << "insert_size: " << insert_size << endl;

	//	{
	//		ft::vector<int>	_int, _int2;

	//		for (int i = 0; i < vec_size; i++)
	//			_int.push_back(i + 10);

	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//		cout << endl;

	//		_int2 = _int;

	//		for (int i = 0; i < insert_size; i++)
	//			cout << "[" << _int2[i] << "]" << " ";
	//		cout << endl << endl;

	//		_int.insert(_int.begin() + pos_offset, _int2.begin(), _int2.begin() + insert_size);

	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//	}
	//	cout << endl << endl;
	//	{
	//		std::vector<int>	_int, _int2;

	//		for (int i = 0; i < vec_size; i++)
	//			_int.push_back(i + 10);

	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//		cout << endl;

	//		_int2 = _int;

	//		for (int i = 0; i < insert_size; i++)
	//			cout << "[" << _int2[i] << "]" << " ";
	//		cout << endl << endl;

	//		_int.insert(_int.begin() + pos_offset, _int2.begin(), _int2.begin() + insert_size);

	//		for (int i = 0; i < (int)_int.size(); i++)
	//			cout << "vec : " << _int[i] << endl;
	//		cout << "size		: " << _int.size() << endl;
	//		cout << "capacity	: " << _int.capacity() << endl;
	//	}
	//}
	
	//{
	//	ft::vector<int>	_int;

	//	for (int i = 0; i < 5; i++)
	//		_int.push_back(i + 10);
	//	for (int i = 0; i < (int)_int.size(); i++)
	//		cout << _int[i] << endl;

	//	cout << endl;
	//	ft::reverse_iterator<ft::vector<int>::iterator>	ri;

	//	ri = _int.rbegin();

	//	cout << "rbegin() : " << *ri << endl;

	//	for (int i = 0; i < 5; i++)
	//		cout << *(ri + i) << endl;

	//	cout << endl;

	//	//for (int i = 0; i < 5; ri++, i++)
	//	//	cout << *ri << endl;
	//	
	//	cout << ri[0] << endl;
	//	cout << ri[1] << endl;

	//}
	
	//{
	//	ft::vector<std::string>	str(5, "123");

	//	//for (int i = 0; i < 10; i++)
	//	//	str.push_back("hello" + std::to_string(i));
	//	cout << "size : " << str.capacity() << endl;
	//	cout << "capacity : " << str.capacity() << endl;

	//	for (int i = 0; i < (int)str.size(); i++)
	//		cout << i << " : " << str[i] << endl;

	//	//ft::vector<std::string>	str2(str.begin(), str.end());
	//	//ft::vector<std::string>	str2 = str;
	//	ft::vector<std::string>	str2;
	//	
	//	str2.assign(5, "123");

	//	cout << "size : " << str2.capacity() << endl;
	//	cout << "capacity : " << str2.capacity() << endl;
	//	for (int i = 0; i < (int)str2.size(); i++)
	//		cout << i << " : " << str2[i] << endl;

	//	str2.pop_back();

	//	cout << "size : " << str2.capacity() << endl;
	//	cout << "capacity : " << str2.capacity() << endl;
	//	for (int i = 0; i < (int)str2.size(); i++)
	//		cout << i << " : " << str2[i] << endl;

	//	str2.insert(str2.end(), "suckon");

	//	cout << "size : " << str2.capacity() << endl;
	//	cout << "capacity : " << str2.capacity() << endl;
	//	for (int i = 0; i < (int)str2.size(); i++)
	//		cout << i << " : " << str2[i] << endl;
	//}

	//{
	//	ft::vector<std::string>	str(5, "lmao");

	//	//for (int i = 0; i < 10; i++)
	//	//	str.push_back("hello" + std::to_string(i));
	//	//cout << "size : " << str.capacity() << endl;
	//	//cout << "capacity : " << str.capacity() << endl;

	//	//for (int i = 0; i < (int)str.size(); i++)
	//	//	cout << i << " : " << str[i] << endl;

	//	//ft::vector<std::string>	str2(str.begin(), str.end());
	//	//ft::vector<std::string>	str2 = str;

	//	ft::vector<std::string>	str2;
	//	
	//	//str2.assign(5, 123);
	//	for (int i = 0; i < 5; i++)
	//		str2.push_back("hello " + std::to_string(i));

	//	//cout << "size : " << str2.capacity() << endl;
	//	//cout << "capacity : " << str2.capacity() << endl;
	//	//for (int i = 0; i < (int)str2.size(); i++)
	//	//	cout << i << " : " << str2[i] << endl;

	//	//str2.pop_back();

	//	cout << "size : " << str2.size() << endl;
	//	cout << "capacity : " << str2.capacity() << endl;

	//	for (int i = 0; i < (int)str2.size(); i++)
	//		cout << i << " : " << str2[i] << endl;

	//	str2.insert(str2.begin() + 2, str.begin(), str.end());

	//	cout << "size : " << str2.capacity() << endl;
	//	cout << "capacity : " << str2.capacity() << endl;
	//	for (int i = 0; i < (int)str2.size(); i++)
	//		cout << i << " : " << str2[i] << endl;
	//}

	//{
	//	ft::vector<myint>	str(5,6969);
	//	ft::vector<myint>	str2;
	//	
	//	//str2.assign(5, 123);
	//	for (int i = 0; i < 5; i++)
	//		str2.push_back(10 + i);

	//	//cout << "size : " << str2.size() << endl;
	//	//cout << "capacity : " << str2.capacity() << endl;
	//	//for (int i = 0; i < (int)str2.size(); i++)
	//	//	cout << i << " : " << str2[i] << endl;

	//	//str2.pop_back();

	//	cout << "size : " << str2.size() << endl;
	//	cout << "capacity : " << str2.capacity() << endl;
	//	for (int i = 0; i < (int)str2.size(); i++)
	//		cout << i << " : " << str2[i] << endl;

	//	//str2.insert(str2.begin() + 5, str.begin(), str.end());
	//	str2.erase(str2.begin());

	//	cout << "size : " << str2.size() << endl;
	//	cout << "capacity : " << str2.capacity() << endl;
	//	for (int i = 0; i < (int)str2.size(); i++)
	//		cout << i << " : " << str2[i] << endl;
	//}
	
	//{
	//	ft::vector<int>	_int;
	//	ft::vector<int>	_int2;

	//	for (int i = 0; i < 5; i++)
	//		_int.push_back(10 + i);
	//	cout << "size : " << _int.size() << endl;
	//	cout << "capacity : " << _int.capacity() << endl;
	//	for (int i = 0; i < (int)_int.capacity(); i++)
	//		cout << _int[i] << endl;
	//	cout << endl;

	//	//_int.pop_back();
	//	//for (int i = 0; i < (int)_int.size(); i++)
	//	//	cout << _int[i] << endl;

	//	for (int i = 0; i < 5; i++)
	//		_int2.push_back(10 + i);
	//	cout << "size : " << _int2.size() << endl;
	//	cout << "capacity : " << _int2.capacity() << endl;
	//	for (int i = 0; i < (int)_int2.capacity(); i++)
	//		cout << _int2[i] << endl;

	//	cout << endl;
	//	if (ft::equal(_int.begin(), _int.end(), _int2.begin(), comparison_fnc))
	//		cout << "true" << endl;
	//	else
	//		cout << "false" << endl;
	//}

	//{
	//	ft::vector<std::string>	_int;
	//	ft::vector<std::string>	_int2;

	//	for (int i = 0; i < 5; i++)
	//		_int.push_back("lmao" + std::to_string(i));
	//	cout << "size : " << _int.size() << endl;
	//	cout << "capacity : " << _int.capacity() << endl;
	//	for (int i = 0; i < (int)_int.size(); i++)
	//		cout << _int[i] << endl;
	//	cout << endl;

	//	//_int.pop_back();
	//	//for (int i = 0; i < (int)_int.size(); i++)
	//	//	cout << _int[i] << endl;

	//	for (int i = 0; i < 5; i++)
	//		_int2.push_back("lmao" + std::to_string(i));
	//	_int2.pop_back();
	//	cout << "size : " << _int2.size() << endl;
	//	cout << "capacity : " << _int2.capacity() << endl;
	//	for (int i = 0; i < (int)_int2.size(); i++)
	//		cout << _int2[i] << endl;

	//	cout << endl;
	//	if (ft::equal(_int.begin(), _int.end(), _int2.begin()))
	//		cout << "true" << endl;
	//	else
	//		cout << "false" << endl;
	//}
	
	//{
	//	ft::vector<int>	_int;
	//	//ft::vector<int>::reverse_iterator	ri;

	//	for (int i = 0; i < 5; i++)
	//		_int.push_back(10 + i);
	//	cout << "size : " << _int.size() << endl;
	//	cout << "capacity : " << _int.capacity() << endl;
	//	for (ft::vector<int>::reverse_iterator i = _int.rend() - 1; i != _int.rbegin(); i--)
	//		cout << *i << endl;
	//}
	
	//{
	//	ft::vector<int>	vec_same1, vec_same2, vec_notsame;

	//	for (int i = 0; i < 5; i++)
	//	{
	//		vec_same1.push_back(10 + i);
	//		vec_same2.push_back(10 + i);
	//	}
	//	cout << "vec same1" << endl;
	//	cout << "size : " << vec_same1.size() << endl;
	//	cout << "capacity : " << vec_same1.capacity() << endl;
	//	for (int i = 0; i < (int)vec_same1.size(); i++)
	//		cout << vec_same1[i] << " ";
	//	cout << endl << endl;

	//	cout << "vec same2" << endl;
	//	cout << "size : " << vec_same2.size() << endl;
	//	cout << "capacity : " << vec_same2.capacity() << endl;
	//	for (int i = 0; i < (int)vec_same2.size(); i++)
	//		cout << vec_same2[i] << " ";
	//	cout << endl << endl;

	//	cout << "vec notsame" << endl;
	//	for (int i = 0; i < 6; i++)
	//		vec_notsame.push_back(100 + i);
	//	cout << "size : " << vec_notsame.size() << endl;
	//	cout << "capacity : " << vec_notsame.capacity() << endl;
	//	for (int i = 0; i < (int)vec_notsame.size(); i++)
	//		cout << vec_notsame[i] << " ";
	//	cout << endl << endl;

	//	cout << std::boolalpha;
	//	cout << "vec_same1 == vec_notsame is " << (vec_same1 == vec_notsame) << endl;
	//	cout << "vec_same1 != vec_notsame is " << (vec_same1 != vec_notsame) << endl;
	//	cout << "vec_same1 < vec_notsame is " << (vec_same1 < vec_notsame) << endl;
	//	cout << "vec_same1 <= vec_notsame is " << (vec_same1 <= vec_notsame) << endl;
	//	cout << "vec_same1 > vec_notsame is " << (vec_same1 > vec_notsame) << endl;
	//	cout << "vec_same1 >= vec_notsame is " << (vec_same1 >= vec_notsame) << endl;
	//	cout << endl;

	//	cout << "vec_same1 == vec_same2 is " << (vec_same1 == vec_same2) << endl;
	//	cout << "vec_same1 != vec_same2 is " << (vec_same1 != vec_same2) << endl;
	//	cout << "vec_same1 < vec_same2 is " << (vec_same1 < vec_same2) << endl;
	//	cout << "vec_same1 <= vec_same2 is " << (vec_same1 <= vec_same2) << endl;
	//	cout << "vec_same1 > vec_same2 is " << (vec_same1 > vec_same2) << endl;
	//	cout << "vec_same1 >= vec_same2 is " << (vec_same1 >= vec_same2) << endl;

	//}
	//{
	//	std::vector<int>	vec_same1, vec_same2, vec_notsame;

	//	for (int i = 0; i < 5; i++)
	//	{
	//		vec_same1.push_back(10 + i);
	//		vec_same2.push_back(10 + i);
	//	}
	//	cout << "vec same1" << endl;
	//	cout << "size : " << vec_same1.size() << endl;
	//	cout << "capacity : " << vec_same1.capacity() << endl;
	//	for (int i = 0; i < (int)vec_same1.size(); i++)
	//		cout << vec_same1[i] << " ";
	//	cout << endl << endl;

	//	cout << "vec same2" << endl;
	//	cout << "size : " << vec_same2.size() << endl;
	//	cout << "capacity : " << vec_same2.capacity() << endl;
	//	for (int i = 0; i < (int)vec_same2.size(); i++)
	//		cout << vec_same2[i] << " ";
	//	cout << endl << endl;

	//	cout << "vec notsame" << endl;
	//	for (int i = 0; i < 6; i++)
	//		vec_notsame.push_back(100 + i);
	//	cout << "size : " << vec_notsame.size() << endl;
	//	cout << "capacity : " << vec_notsame.capacity() << endl;
	//	for (int i = 0; i < (int)vec_notsame.size(); i++)
	//		cout << vec_notsame[i] << " ";
	//	cout << endl << endl;

	//	cout << std::boolalpha;
	//	cout << "vec_same1 == vec_notsame is " << (vec_same1 == vec_notsame) << endl;
	//	cout << "vec_same1 != vec_notsame is " << (vec_same1 != vec_notsame) << endl;
	//	cout << "vec_same1 < vec_notsame is " << (vec_same1 < vec_notsame) << endl;
	//	cout << "vec_same1 <= vec_notsame is " << (vec_same1 <= vec_notsame) << endl;
	//	cout << "vec_same1 > vec_notsame is " << (vec_same1 > vec_notsame) << endl;
	//	cout << "vec_same1 >= vec_notsame is " << (vec_same1 >= vec_notsame) << endl;
	//	cout << endl;

	//	cout << "vec_same1 == vec_same2 is " << (vec_same1 == vec_same2) << endl;
	//	cout << "vec_same1 != vec_same2 is " << (vec_same1 != vec_same2) << endl;
	//	cout << "vec_same1 < vec_same2 is " << (vec_same1 < vec_same2) << endl;
	//	cout << "vec_same1 <= vec_same2 is " << (vec_same1 <= vec_same2) << endl;
	//	cout << "vec_same1 > vec_same2 is " << (vec_same1 > vec_same2) << endl;
	//	cout << "vec_same1 >= vec_same2 is " << (vec_same1 >= vec_same2) << endl;

	//}
	
	//{
	//	std::list<int> lst;
	//	std::list<int>::iterator lst_it;
	//	for (int i = 1; i < 5; ++i)
	//		lst.push_back(i * 3);

	//	ft::vector<int> vct(lst.begin(), lst.end());
	//	//printSize(vct);

	//	lst_it = lst.begin();
	//	for (int i = 1; lst_it != lst.end(); ++i)
	//		*lst_it++ = i * 5;
	//	vct.assign(lst.begin(), lst.end());
	//	//printSize(vct);

	//	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	//	for (ft::vector<int>::iterator i = vct.begin(); i != vct.end(); i++)
	//		cout << " final : " << *i << endl;
	//	//printSize(vct);
	//}

#ifdef	TO_TEST
	//{
	//	cout << MAGENTA "Testing std::" RESET << endl << endl;
	//	std::vector<int>				vec;
	//	std::vector<int>				vec_temp;
	//	std::vector<int>::iterator	it;

	//	for (int i = 1; i < 6; i++)
	//		vec.push_back(i * 3);
	//	print_vec_info(vec, "initial");
	//	vec_temp = vec;

	//	cout << "erase 0 from end pos - 1: " << *vec.erase(vec.end() - 1, vec.end() - 1) << endl;
	//	print_vec_info(vec, "after");
	//	
	//	//it = vec.erase(vec.end() - 1);
	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.end() - 1, vec.end());
	//	cout << "erase 1 from end pos: ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.begin(), vec.begin() + 2);
	//	cout << "erase 2 from start pos: ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.begin() + 1, vec.begin() + 3);
	//	cout << "erase 2 from start pos + 1: ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.end() - 2, vec.end());
	//	cout << "erase 2 from end pos : ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");
	//	
	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.end() - 3, vec.end() - 1);
	//	cout << "erase 2 from end pos - 1: ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;
	//	print_vec_info(vec, "before");
	//	test_vec_erase(vec, vec.erase(vec.begin() + 2));
	//	//vec.erase(vec.begin() + 2);
	//	//cout << "erase 1 from begin + 2: ";
	//	//if (it == vec.end())
	//	//	cout << "vec.end() [cant print vec.end()]" << endl;
	//	//else
	//	//	cout << *it << endl;
	//	//cout << "tester : " << it - vec.begin() << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;
	//	cout << "erase 2 from begin" << *(vec.erase(vec.begin() + 2)) << endl;

	//	print_vec_info(vec, "final");
	//}
#endif

#ifndef	TO_TEST
	//{
	//	cout << MAGENTA "Testing ft::" RESET << endl << endl;
	//	ft::vector<int>				vec;
	//	ft::vector<int>				vec_temp;
	//	ft::vector<int>::iterator	it;

	//	for (int i = 1; i < 6; i++)
	//		vec.push_back(i * 3);
	//	print_vec_info(vec, "initial");
	//	vec_temp = vec;

	//	cout << "erase 0 from end pos - 1: " << *vec.erase(vec.end() - 1, vec.end() - 1) << endl;
	//	print_vec_info(vec, "after");
	//	
	//	//it = vec.erase(vec.end() - 1);
	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.end() - 1, vec.end());
	//	cout << "erase 1 from end pos: ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.begin(), vec.begin() + 2);
	//	cout << "erase 2 from start pos: ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.begin() + 1, vec.begin() + 3);
	//	cout << "erase 2 from start pos + 1: ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.end() - 2, vec.end());
	//	cout << "erase 2 from end pos : ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");
	//	
	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;

	//	it = vec.erase(vec.end() - 3, vec.end() - 1);
	//	cout << "erase 2 from end pos - 1: ";
	//	if (it == vec.end())
	//		cout << "vec.end() [cant print vec.end()]" << endl;
	//	else
	//		cout << *it << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;
	//	print_vec_info(vec, "before");
	//	test_vec_erase(vec, vec.erase(vec.begin() + 2));
	//	//vec.erase(vec.begin() + 2);
	//	//cout << "erase 1 from begin + 2: ";
	//	//if (it == vec.end())
	//	//	cout << "vec.end() [cant print vec.end()]" << endl;
	//	//else
	//	//	cout << *it << endl;
	//	//cout << "tester : " << it - vec.begin() << endl;
	//	print_vec_info(vec, "after");

	//	cout << CYAN "reseting vec..." RESET << endl;
	//	vec = vec_temp;
	//	it = (vec.erase(vec.begin() + 2));
	//	cout << "erase 2 from begin" << *it << endl;

	//	print_vec_info(vec, "final");
	//}
#endif

	//test_actual(argv[1]);
}

void	test_stack()
{
	//{
	//	ft::stack<int>	st;
	//	ft::stack<int>	st2;
	//
	//	for (int i = 0; i < 5; i++)
	//		st.push(i + 10);
	//	cout << "size : " << st.size() << endl;
	//	
	//	int	init_size = st.size();
	//	st2 = st;
	//	for (int i = 0; i < init_size; i++)
	//	{
	//		cout << st2.top() << endl;
	//		st2.pop();
	//	}
	//	cout << "size : " << st.size() << endl;
	//	cout << std::boolalpha;
	//	cout << "st == st2 : " << (st == st2) << endl;
	//}
	//{
	//	std::stack<int>	st;
	//	std::stack<int>	st2;
	//
	//	for (int i = 0; i < 5; i++)
	//		st.push(i + 10);
	//	cout << "size : " << st.size() << endl;
	//	
	//	int	init_size = st.size();
	//	st2 = st;
	//	for (int i = 0; i < init_size; i++)
	//	{
	//		cout << st2.top() << endl;
	//		st2.pop();
	//	}
	//	cout << "size : " << st.size() << endl;
	//	cout << std::boolalpha;
	//	cout << "st == st2 : " << (st == st2) << endl;
	//}
}

void	test_pair()
{
	//ft::pair<int, double>	p;

	//int		i = 10;
	//double	d = 12.0;

	//ft::pair<int,double>	p2(i,d);

	//ft::pair<int,double>	p3;

	//p3 = p2;

	//ft::pair<int, double>	p4;

	//p4 = ft::make_pair(i, d);

	//cout << p2.first << p2.second << endl;
	//cout << p3.first << p3.second << endl;
	//cout << p4.first << p4.second << endl;
}

//template <class T>
//void	inorder_traversal(Node<T> *node)
//{
//	if (node != nullptr)
//	{
//		inorder_traversal(node->left);
//		cout << node->data << endl;
//		inorder_traversal(node->right);
//	}
//}
//
//template <class T>
//void	postorder_traversal(Node<T> *node)
//{
//	if (node != nullptr)
//	{
//		postorder_traversal(node->left);
//		postorder_traversal(node->right);
//		cout << node->data << endl;
//	}
//}
//
//template <class T>
//void	preorder_traversal(Node<T> *node)
//{
//	if (node != nullptr)
//	{
//		cout << node->data << endl;
//		preorder_traversal(node->left);
//		preorder_traversal(node->right);
//	}
//}

//template <class T>
//Node<T>	*search_tree(Node<T> *node, T to_find)
//{
//	if (node == nullptr || node->data == to_find)
//		return node;
//
//	if (to_find < node->data)
//		return search_tree(node->left, to_find);
//	else
//		return search_tree(node->right, to_find);
//}

//void	test_bt_node()
//{
//	RedBlackTree<int>	rbt;
//
//	Node<int>	*head = new Node<int>(10, rbt._sentinal);
//	Node<int>	*l1 = new Node<int>(7, head, rbt._sentinal, rbt._sentinal);
//	Node<int>	*r1 = new Node<int>(42, head, nullptr, nullptr, 1);
//
//	Node<int>	*r1l1 = new Node<int>(31, r1, nullptr, rbt._sentinal);
//	Node<int>	*r2 = new Node<int>(64, r1);
//
//	Node<int>	*r1l2 = new Node<int>(29, r1l1, rbt._sentinal, rbt._sentinal, 1);
//	Node<int>	*r2l1 = new Node<int>(50, r2, rbt._sentinal, rbt._sentinal, 1);
//	Node<int>	*r3 = new Node<int>(83, r2, rbt._sentinal, rbt._sentinal, 1);
//
//	rbt._root = head;
//
//	head->left = l1;
//	head->right = r1;
//
//	r1->left = r1l1;
//	r1->right = r2;
//
//	r1l1->left = r1l2;
//	r2->left = r2l1;
//	r2->right = r3;
//
//	rbt._sentinal->left = l1;
//	rbt._sentinal->right = r3;
//
//	//{
//
//	//	cout << head->data << endl;
//	//	cout << head->left->data << endl;
//	//	cout << head->right->data << endl;
//	//	cout << head->right->left->data << endl;
//	//	cout << head->right->left->left->data << endl;
//	//	cout << head->right->right->data << endl;
//	//	cout << head->right->right->left->data << endl;
//	//	cout << head->right->right->right->data << endl;
//	//	
//
//	//	cout << "inorder traversal" << endl;
//	//	inorder_traversal(head);
//	//	cout << endl;
//
//	//	cout << "postorder traversal" << endl;
//	//	postorder_traversal(head);
//	//	cout << endl;
//
//	//	cout << "preorder traversal" << endl;
//	//	preorder_traversal(head);
//	//	cout << endl;
//
//
//	//	cout << search_tree(head, 64)->data << endl;
//	//	cout << search_tree(head, 64)->right->data << endl;
//	//	cout << search_tree(head, 64)->left->data << endl;
//
//	//}
//
//	{
//		//rbt.inorder_traversal(rbt._root);
//		//rbt.insert_node(5);
//		//cout << endl;
//		//rbt.inorder_traversal(rbt._root);
//		//cout << endl;
//
//		//rbt.insert_node(89);
//		//cout << endl;
//		//rbt.inorder_traversal(rbt._root);
//		//cout << endl;
//
//		//rbt.insert_node(32);
//		//cout << endl;
//		//rbt.inorder_traversal(rbt._root);
//		//cout << endl;
//	}
//
//	delete head;
//	delete l1;
//	delete r1;
//	delete r1l1;
//	delete r2;
//	delete r1l2;
//	delete r2l1;
//	delete r3;
//
//	//{
//	//	 RedBlackTree<int>	rbt;
//
//	//	 rbt.insert_node(10);
//	//}
//}

# define RBT_BLACK false
# define RBT_RED true

void	test_rbt(void)
{
	//cout << MAGENTA "case 1" RESET << endl;
	//cout << RED "parent and uncle of z are red" RESET << endl;
	//{

	//	RedBlackTree<int>	rbt;

	//	rbt.insert_node(10);

	//	rbt.insert_node(21);
	//	rbt.insert_node(18);
	//	rbt.insert_node(15);
	//	rbt.insert_node(12);
	//	rbt.insert_node(19);

	//	rbt.insert_node(25);
	//	rbt.insert_node(22);
	//	rbt.insert_node(30);
	//	rbt.insert_node(27);
	//	rbt.insert_node(34);

	//	rbt._root->right->colour = RBT_BLACK; //21

	//	rbt._root->right->left->colour = RBT_RED; //18
	//	rbt._root->right->right->colour = RBT_RED; //25

	//	rbt._root->right->left->left->colour = RBT_BLACK; //15
	//	rbt._root->right->left->right->colour = RBT_BLACK; //19
	//	rbt._root->right->right->left->colour = RBT_BLACK; //22
	//	rbt._root->right->right->right->colour = RBT_BLACK; //30

	//	rbt._root->right->left->left->left->colour = RBT_RED; //12
	//	rbt._root->right->right->right->left->colour = RBT_RED; //27
	//	rbt._root->right->right->right->right->colour = RBT_RED; //34

	//	rbt.print_helper(rbt._root, "", true);
	//	cout << "inserting 29.." << endl;
	//	cout << endl;

	//	rbt.insert_node(29);

	//	rbt.print_helper(rbt._root, "", true);
	//	cout << endl;

	//	rbt.rebalance_tree(rbt._root->right->right->right->left->right);
	//	cout << endl;

	//	rbt.print_helper(rbt._root, "", true);
	//}

	//cout << "Testing case 3" << endl;
	//{
	//	RedBlackTree<int>	rbt;

	//	rbt.insert_node(10);

	//	rbt.insert_node(21);
	//	rbt.insert_node(18);
	//	rbt.insert_node(15);
	//	rbt.insert_node(12);
	//	rbt.insert_node(19);

	//	rbt.insert_node(25);
	//	rbt.insert_node(22);
	//	rbt.insert_node(30);
	//	rbt.insert_node(27);
	//	rbt.insert_node(34);

	//	rbt._root->right->colour = RBT_BLACK; //21

	//	rbt._root->right->left->colour = RBT_RED; //18
	//	rbt._root->right->right->colour = RBT_RED; //25

	//	rbt._root->right->left->left->colour = RBT_BLACK; //15
	//	rbt._root->right->left->right->colour = RBT_BLACK; //19
	//	rbt._root->right->right->left->colour = RBT_BLACK; //22
	//	rbt._root->right->right->right->colour = RBT_BLACK; //30

	//	rbt._root->right->left->left->left->colour = RBT_RED; //12
	//	rbt._root->right->right->right->left->colour = RBT_RED; //27
	//	rbt._root->right->right->right->right->colour = RBT_RED; //34

	//	rbt.print_helper(rbt._root, "", true);
	//	cout << "inserting 11.." << endl;
	//	cout << endl;

	//	rbt.insert_node(11);

	//	rbt.print_helper(rbt._root, "", true);
	//	cout << endl;

	//	rbt.rebalance_tree_case_c(rbt._root->right->left->left->left->left);
	//	cout << endl;

	//	rbt.print_helper(rbt._root, "", true);
	//}
	
	//{
	//	RedBlackTree<int>	rbt;

	//	cout << "inserting 2.." << endl;
	//	rbt.insert_node(2);
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << endl;

	//	cout << "inserting 1.." << endl;
	//	rbt.insert_node(1);
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << endl;

	//	cout << "inserting 3.." << endl;
	//	rbt.insert_node(3);
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << endl;

	//	cout << "inserting 4.." << endl;
	//	rbt.insert_node(4);
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << endl;

	//	cout << "inserting 21.." << endl;
	//	rbt.insert_node(21);
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << endl;
	//}
	
	//{
	//	RedBlackTree<int>	rbt;
	//	int					num_count = 50;
	//	std::vector<int>	ins;
	//	std::vector<int>	del;

	//	srand(time(0));
	//	cout << "size : " << rbt.size() << endl;
	//	for (int i = 0; i < num_count; i++)
	//	{
	//		int	num = (rand() % num_count) + 1;
	//		cout << "inserting " << num << "..." << endl;
	//		ins.push_back(num);
	//		rbt.insert_node(num);
	//		cout << "==============" << endl;
	//		cout << "size : " << rbt.size() << endl;
	//		rbt.print_helper(rbt._root, "", true);
	//		cout << "==============" << endl;
	//		cout << endl;
	//	}

	//	//cout << "FIRST DELETE" << endl;
	//	for (int i = 0; i < num_count; i++)
	//	{
	//		int	num = (rand() % num_count) + 1;
	//		cout << "deleting " << num << "..." << endl;
	//		del.push_back(num);
	//		cout << "==============" << endl;
	//		cout << RESET "TREE BEFORE DELETION" RESET << endl;
	//		rbt.print_helper(rbt._root, "", true);
	//		cout << "==============" << endl;
	//		rbt.delete_node(num);
	//		cout << "size : " << rbt.size() << endl;
	//		cout << endl;
	//	}

	//	cout << "END TREE" << endl;
	//	cout << "size : " << rbt.size() << endl;
	//	cout << "min : " << *rbt.min(rbt.get_root())->data << endl;
	//	cout << "max : " << *rbt.max(rbt.get_root())->data << endl;
	//	rbt.print_helper(rbt._root, "", true);

	//	cout << "ins nums used" << endl;
	//	for (std::vector<int>::iterator i = ins.begin(); i < ins.end(); i++)
	//		cout << *i << ",";
	//	cout << endl;

	//	cout << "del nums used" << endl;
	//	for (std::vector<int>::iterator i = del.begin(); i < del.end(); i++)
	//		cout << *i << ",";
	//	cout << endl;
	//}

	//{
	//	RedBlackTree<int>	rbt;
	//	//int arr[11] = {19,19,12,19,14,10,4,12,1,15,15};
	//	//int arr[12] = {1,2,3,4,5,6,7,8,0,1,2,3};
	//	//int arr[14] = {6,11,1,7,2,11,3,4,4,6,5,6,3,1};
	//	//int	arr[20] = {16,19,16,16,12,4,12,17,20,13,17,18,19,10,20,8,17,5,2,9};
	//	//int	del[20] = {7,19,10,20,11,2,8,16,9,4,11,16,9,2,2,4,10,8,5,19};
	//	//int arr[6] = {4,2,6,5,7,3};
	//	int arr[8] = {1,2,3,4,5,6,7,8};
	//	//int arr[20] = {6,16,1,11,9,2,10,13,13,20,19,12,18,20,4,14,1,1,18,20};
	//	//int del[20] = {1,4,9,10,12,16,16,11,18,7,11,12,11,14,11,15,19,17,8,4};

	//	for (int i = 0; i < 8; i++)
	//	{
	//		//arr[i] *= 10;
	//		//cout << "inserting " << arr[i] << "..." << endl;
	//		rbt.insert_node(arr[i]);
	//		//cout << "==============" << endl;
	//		//rbt.print_helper(rbt._root, "", true);
	//		//cout << "==============" << endl;
	//		//cout << endl << endl;
	//	}
	//	//rbt._root->left->right->colour = RBT_BLACK;
	//	//rbt._root->right->right->colour = RBT_BLACK;
	//	//rbt._root->right->left->colour = RBT_BLACK;
	//	//rbt.print_helper(rbt._root, "", true);

	//	//cout << "deleting 2..." << endl;
	//	//rbt.delete_node(3);
	//	//cout << "END TREE" << endl;
	//	//rbt.print_helper(rbt._root, "", true);

	//	//cout << "==============" << endl;	
	//	//rbt.print_helper(rbt._root, "", true);
	//	//cout << "==============" << endl;	
	//	//cout << "sentinal colour : " << (rbt._sentinal->colour == RBT_BLACK ?
	//	//		(RED "BLACK" RESET) : (GREEN "RED" RESET)) << endl;
	//	//cout << endl;
	//	////cout << "min : " << rbt.minimum_in_subtree(rbt._root)->data << endl;
	//	////cout << "max : " << rbt.maximum_in_subtree(rbt._root->left->left->right)->data << endl;
	//
	//	//cout << "addr " << rbt._root->left->left->left << endl;
	//	//cout << "l " << rbt._root->left->left->left->left->data << endl;
	//	//cout << "r " << rbt._root->left->left->left->right->data << endl;
	//	//cout << "DELETE FIRST" << endl;
	//	//for (int i = 0; i < 20; i++)
	//	//{
	//	//	cout << "deleting " << del[i] << "..." << endl;
	//	//	cout << "==============" << endl;
	//	//	cout << "BEFORE DELETE" << endl;
	//	//	rbt.print_helper(rbt._root, "", true);
	//	//	cout << "==============" << endl;
	//	//	rbt.delete_node(del[i]);
	//	//	cout << "==============" << endl;
	//	//	cout << "AFTER DELETE" << endl;
	//	//	rbt.print_helper(rbt._root, "", true);
	//	//	cout << "==============" << endl;
	//	//	//cout << endl << endl;
	//	//}
	//	//rbt.postorder_traversal(rbt._root);
	//	//cout << "HERE" << endl;
	//	//cout << rbt._root->data << endl;
	//	//cout << rbt._root->right->data << endl;
	//	//cout << rbt._root->right->left->data << endl;
	//	//cout << rbt._root->right->left->left->data << endl;
	//	//cout << rbt._root->right->left->right->data << endl;

	//	cout << "==============" << endl;	
	//	cout << "FINAL" << endl;
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << "==============" << endl;	
	//}
	
	//{
	//	RedBlackTree<int>	rbt;
	//	int					num_count = 20;

	//	std::vector<int>	ins;
	//	std::vector<int>	del;

	//	srand(time(0));
	//	cout << "size : " << rbt.size() << endl;
	//	for (int i = 0; i < num_count; i++)
	//	{
	//		int	num = (rand() % num_count) + 1;
	//		ins.push_back(num);
	//		rbt.insert_node(num);
	//	}

	//	RedBlackTree<int>	rbt2(rbt);

	//	cout << endl;
	//	cout << "rbt ori" << endl;
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << endl;

	//	cout << endl;
	//	cout << "rbt copy" << endl;
	//	rbt2.print_helper(rbt2._root, "", true);
	//	cout << endl;
	//	//cout << "size : " << rbt.size() << endl;
	//	//cout << "min : " << *rbt.min(rbt.get_root())->data << endl;
	//	//cout << "max : " << *rbt.max(rbt.get_root())->data << endl;
	//
	//	for (int i = 0; i < num_count; i++)
	//	{
	//		int	num = (rand() % num_count) + 1;
	//		cout << "deleting " << num << "..." << endl;
	//		del.push_back(num);
	//		rbt.delete_node(num);
	//		rbt2.delete_node(num);
	//		rbt.print_helper(rbt._root, "", true);
	//		rbt2.print_helper(rbt2._root, "", true);
	//		cout << "size : " << rbt.size() << endl;
	//		cout << endl;
	//	}

	//	cout << endl;
	//	cout << "END rbt ori" << endl;
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << "size : " << rbt.size() << endl;
	//	cout << endl;

	//	cout << endl;
	//	cout << "END rbt copy" << endl;
	//	rbt2.print_helper(rbt2._root, "", true);
	//	cout << "size : " << rbt2.size() << endl;
	//	cout << endl;

	//	cout << "ins nums used" << endl;
	//	for (std::vector<int>::iterator i = ins.begin(); i < ins.end(); i++)
	//		cout << *i << ",";
	//	cout << endl;

	//	cout << "del nums used" << endl;
	//	for (std::vector<int>::iterator i = del.begin(); i < del.end(); i++)
	//	   cout << *i << ",";
	//	cout << endl;

	//	cout << "Deleting only rbt copy" << endl;
	//	for (int i = 0; i < num_count; i++)
	//	{
	//		int	num = (rand() % num_count) + 1;
	//		cout << "deleting..." << num << "..." << endl;
	//		del.push_back(num);
	//		rbt2.delete_node(num);
	//		rbt2.print_helper(rbt2._root, "", true);
	//		cout << "size : " << rbt.size() << endl;
	//		cout << endl;
	//	}

	//	cout << endl;
	//	cout << "END rbt ori" << endl;
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << "size : " << rbt.size() << endl;
	//	cout << endl;

	//	cout << endl;
	//	cout << "END rbt copy" << endl;
	//	rbt2.print_helper(rbt2._root, "", true);
	//	cout << "size : " << rbt2.size() << endl;
	//	cout << endl;

	//	cout << "del nums used" << endl;
	//	for (std::vector<int>::iterator i = del.begin(); i < del.end(); i++)
	//	   cout << *i << ",";
	//	cout << endl;

	//	rbt2 = rbt;

	//	cout << endl;
	//	cout << "AFTER copy assignment rbt ori" << endl;
	//	rbt.print_helper(rbt._root, "", true);
	//	cout << "size : " << rbt.size() << endl;
	//	cout << endl;

	//	cout << endl;
	//	cout << "AFTER copy assignment rbt copy" << endl;
	//	rbt2.print_helper(rbt2._root, "", true);
	//	cout << "size : " << rbt2.size() << endl;
	//	cout << endl;
	//}
	
	//{
	//	RedBlackTree<const int>						rbt;
	//	//RedBlackTree<int>						rbt;

	//	const int n1 = 4;
	//	const int n2 = 2;

	//	rbt.insert_node(n1);
	//	rbt.insert_node(n2);
	//	//const RedBlackTree<const int>::const_iterator		rbti = rbt.begin();

	//	//rbt.insert_node(4);
	//	//rbt.insert_node(2);
	//	//rbt.insert_node(6);
	//	//rbt.insert_node(1);
	//	//rbt.insert_node(3);
	//	//rbt.insert_node(5);
	//	//rbt.insert_node(7);
	//	
	//	rbt.print_helper(rbt.get_root(), "", true);
	//	//const ft::map_iterator<const int>	mi = rbt.begin();
	//	//rbti = rbt.begin();
	//	const RedBlackTree<const int>::const_iterator it = rbt.begin();
	//	cout << *it << endl;
	//	//for (const RedBlackTree<const int>::const_iterator it = rbt.begin(); it != rbt.end(); it++)
	//	//	cout << *it << endl;
	//	//for (RedBlackTree<int>::iterator it = rbt.begin(); it != rbt.end(); it++)
	//	//	cout << *it << endl;
	//	//cout << endl;
	//	//cout << endl;
	//	//for (RedBlackTree<int>::reverse_iterator it = rbt.rbegin(); it != rbt.rend(); it++)
	//	//	cout << *it << endl;
	//	//rbt.inorder_traversal(rbti._node->parent);
	//}

}

void	test_map()
{
	//{
	//	ft::map<int,int>	m;
	//	cout << endl;
	//	cout << endl;
	//	ft::map<int,int>	m2(m);

	//	cout << endl;
	//	cout << endl;
	//}
	
	//{
	//	RedBlackTree<ft::pair<int,std::string> >	rbt;

	//	rbt.insert_node(ft::make_pair<int,std::string>(1, "lmao"));
	//	rbt.insert_node(ft::make_pair<int,std::string>(2, "lol"));

	//	for (RedBlackTree<ft::pair<int,std::string> >::iterator	it = rbt.begin();
	//			it != rbt.end(); it++)
	//		cout << "key : \"" << (*it).first << "\"" << "->" << (*it).second << endl;
	//	//rbt.print_pair(rbt.get_root(), "", true);
	//	//rbt.print_helper(rbt.get_root(), "", true);

	//	//RedBlackTree<int>	rbt2;

	//	//rbt2.insert_node(1);
	//	////rbt2.print_helper(rbt2.get_root(), "", true);
	//	//rbt2.print_helper(rbt2.get_root(), "", true);

	//}
	
	{
		//std::vector<std::pair<const int,std::string> > vec;

		//vec.push_back(std::make_pair<const int, std::string>(1, "lmao"));

		//std::map<const int, std::string>	m(vec.begin(), vec.end());

		//RedBlackTree<ft::pair<int,std::string> >	rbt;

		//rbt.insert_node(ft::make_pair<int,std::string>(1, "lmao1"));
		//rbt.insert_node(ft::make_pair<int,std::string>(2, "lmao2"));
		//rbt.insert_node(ft::make_pair<int,std::string>(3, "lmao3"));

		////rbt.print_pair(rbt.get_root(), "", true);

		//RedBlackTree<ft::pair<int,std::string> >	rbt2(rbt.begin(),rbt.end());
		////rbt2.print(rbt2.get_root(), "", true);
	}

	//{
	//	RedBlackTree<ft::pair<int,std::string> > rbt;

	//	rbt.insert_node(ft::make_pair<int, std::string>(3, "lmao1"));
	//	rbt.insert_node(ft::make_pair<int, std::string>(1, "lmao3"));
	//	rbt.insert_node(ft::make_pair<int, std::string>(2, "lmao2"));
	//	rbt.print_pair(rbt.get_root(), "", true);
	//}
	
	//{
	//	//std::less<const int>	comp;
	//	//comp(p.first,p2.first);
	//}

	{
		//typedef	ft::map<int, std::string>	map_type;
		//map_type	map;
		//int	arr[] = {1,2,4,5,6,8,9,7};
		//int	arr_size = 8;

		//cout << std::boolalpha;
		//for (int i = 0; i < arr_size; i++)
		//{
		//	cout << RED "========================" RESET << endl;
		//	ft::pair<map_type::iterator, bool>	val = map.insert(ft::make_pair<int, std::string>(arr[i], "lmao " + std::to_string(arr[i])));
		//	cout << "valid insert : " << val.second << endl;
		//	cout << "kv pair : " << "[" << (*val.first).first << "], [" << (*val.first).second << "]" << endl;
		//	cout << RED "========================" RESET << endl;
		//	cout << endl;
		//}

		//typedef	std::map<int, std::string>	rmap_type;
		//rmap_type	rmap;
		//int	arr[] = {1,1,2,3,4,5,5,1};
		//int	arr_size = 8;

		//cout << std::boolalpha;

		//for (int i = 0; i < arr_size; i++)
		//{
		//	std::pair<rmap_type::iterator, bool>	val = rmap.insert(std::make_pair<int, std::string>(arr[i], "lmao"));
		//	cout << "valid insert : " << val.second << endl;
		//	cout << "kv pair : " << "[" << (*val.first).first << "], [" << (*val.first).second << "]" << endl;
		//	cout << endl;
		//}

		//typedef	ft::map<int, std::string>	map_type;

		//map_type			map;
		//map_type::iterator	store;
		//int	arr[] = {1,2,4,5,6,8,9};
		//int	arr_size = 7;

		//cout << std::boolalpha;
		//for (int i = 0; i < arr_size; i++)
		//{
		//	cout << RED "========================" RESET << endl;
		//	ft::pair<map_type::iterator, bool>	val = map.insert(ft::make_pair<int, std::string>(arr[i], "lmao " + std::to_string(arr[i])));
		//	cout << "valid insert : " << val.second << endl;
		//	cout << "kv pair : " << "[" << (*val.first).first << "], [" << (*val.first).second << "]" << endl;
		//	if (arr[i] == 6)
		//		store = (val.first);
		//	cout << RED "========================" RESET << endl;
		//	cout << endl;
		//}
		//cout << RED "========================" RESET << endl;
		//cout << "store : " << "[" << (*store).first << "], [" << (*store).second << "]" << endl;
		//cout << endl;
		//map_type::iterator res = map.insert(store, ft::make_pair<int, std::string>(7, "lmao " + std::to_string(7)));
		//cout << "kv pair : " << "[" << (*res).first << "], [" << (*res).second << "]" << endl;
		//cout << RED "========================" RESET << endl;
		//cout << endl;
	}

	//{
	//	typedef	ft::map<int, std::string>	map_type;

	//	ft::vector<ft::pair<int, std::string> >	vec;
	//	int	arr[] = {1,2,4,5,6,8,9,1,2,3};
	//	int	arr_size = 10;

	//	cout << GREEN "Filling up vector..." RESET << endl;
	//	for (int i = 0; i < arr_size; i++)
	//		vec.push_back(ft::make_pair<int, std::string>(arr[i], "lmao " + std::to_string(arr[i])));
	//	cout << endl;

	//	cout << GREEN "Printing vector..." RESET << endl;
	//	for (ft::vector<ft::pair<int, std::string> >::iterator it = vec.begin(); it != vec.end(); it++)
	//		cout << (*it).first << " ";
	//	cout << endl;

	//	map_type			map;
	//	cout << GREEN "Filling map using range insert..." RESET << endl;
	//	map.insert(vec.begin(), vec.end());
	//	cout << endl;

	//	map_type			map2;
	//	cout << GREEN "Filling map2 using range insert..." RESET << endl;
	//	map2.insert(map.begin(), map.end());
	//	cout << endl;

	//	cout << GREEN "Filling map3 using range constructor..." RESET << endl;
	//	map_type		map3(map2.begin(), map2.end());
	//}
	
	//{
	//	typedef	ft::map<int, std::string>	map_type;

	//	ft::vector<ft::pair<int, std::string> >	vec;
	//	int	arr[] = {1,2,4,5,6,8,9};
	//	int	arr_size = 7;

	//	cout << GREEN "Filling up vector..." RESET << endl;
	//	for (int i = 0; i < arr_size; i++)
	//		vec.push_back(ft::make_pair<int, std::string>(arr[i], "lmao " + std::to_string(arr[i])));
	//	cout << endl;

	//	cout << GREEN "Printing vector..." RESET << endl;
	//	for (ft::vector<ft::pair<int, std::string> >::iterator it = vec.begin(); it != vec.end(); it++)
	//		cout << (*it).first << " ";
	//	cout << endl;

	//	map_type	map;
	//	cout << GREEN "Filling map using range insert..." RESET << endl;
	//	map.insert(vec.begin(), vec.end());
	//	cout << endl;

	//	cout << std::boolalpha;
	//	cout << "not empty map is : " << map.empty() << endl;
	//	cout << "size of map is : " << map.size() << endl;

	//	map_type	map2;
	//	cout << "empty map is : " << map2.empty() << endl;
	//	cout << "size of map is : " << map2.size() << endl;

	//	map_type	map3(map.begin(), map.end());
	//	cout << "not empty map is : " << map3.empty() << endl;
	//	cout << "size of map is : " << map3.size() << endl;

	//	//std::map<int, std::string> test;
	//	//cout << "real map size "<< test.max_size() << endl;
	//	//cout << "real vec size "<< vec.max_size() << endl;
	//	//cout << "real vec size "<< vec.max_size() / 2<< endl;
	//	cout << endl;

	//	cout << map.max_size() << endl;
	//	//cout << endl;
	//	//cout << endl;

	//	//std::map<int, std::map<int, std::map<int, std::vector<int> > > >	rmap;
	//	//cout << "max size of s-s map:" << rmap.max_size() << endl;
	//	cout << endl;

	//	//std::vector<bool>	b;
	//	//std::vector<long>	l;
	//	//std::vector<std::string>	s;
	//	//std::vector<std::string>	lmao;
	//	//cout << "int vec size :\t\t" << vec.max_size() << endl;
	//	//cout << "bool vec size :\t\t" << b.max_size() << endl;
	//	//cout << "long vec size :\t\t" << l.max_size() << endl;
	//	//cout << "string vec size :\t" << s.max_size() << endl;
	//	//cout << "test vec size :\t\t" << lmao.max_size() << endl;
	//	//cout << endl << endl;

	//	//std::map<int,int>			ii;
	//	//std::map<int,std::string>	is;
	//	//std::map<int,long>			il;
	//	//std::map<long,long>			ll;
	//	//std::map<string,string>		ss;
	//	//std::map<bool,bool>			bb;
	//	//cout << "ii map size :\t\t" << ii.max_size() << endl;
	//	//cout << "is map size :\t\t" << is.max_size() << endl;
	//	//cout << "il map size :\t\t" << il.max_size() << endl;
	//	//cout << "ll map size :\t\t" << ll.max_size() << endl;
	//	//cout << "ss map size :\t\t" << ss.max_size() << endl;
	//	//cout << "bb map size :\t\t" << bb.max_size() << endl;
	//	//cout << endl << endl;

	//	//ft::map<int,int>			mii;
	//	//ft::map<int,std::string>	mis;
	//	//ft::map<int,long>			mil;
	//	//ft::map<long,long>			mll;
	//	//ft::map<string,string>		mss;
	//	//ft::map<bool,bool>			mbb;
	//	//cout << "mii map size :\t\t" << mii.max_size() << endl;
	//	//cout << "mis map size :\t\t" << mis.max_size() << endl;
	//	//cout << "mil map size :\t\t" << mil.max_size() << endl;
	//	//cout << "mll map size :\t\t" << mll.max_size() << endl;
	//	//cout << "mss map size :\t\t" << mss.max_size() << endl;
	//	//cout << "mbb map size :\t\t" << mbb.max_size() << endl;
	//	//cout << "mii mmap size :\t\t" << mii.max_size() << endl;
	//	//cout << endl;

	//	//cout << "mii map size :\t\t" << mii.test_size() << endl;
	//	//cout << "mis map size :\t\t" << mis.test_size() << endl;
	//	//cout << "mil map size :\t\t" << mil.test_size() << endl;
	//	//cout << "mll map size :\t\t" << mll.test_size() << endl;
	//	//cout << "mss map size :\t\t" << mss.test_size() << endl;
	//	//cout << "mbb map size :\t\t" << mbb.test_size() << endl;
	//	//cout << "mii mmap size :\t\t" << mii.test_size() << endl;
	//	//cout << "mii vmap size :\t\t" << mii.n_size() << endl;
	//	//cout << "mii nmap size :\t\t" << mii.v_size() << endl;
	//	//cout << endl;
	//	//cout << "mis vmap size :\t\t" << mis.n_size() << endl;
	//	//cout << "mis nmap size :\t\t" << mis.v_size() << endl;
	//	//cout << endl;
	//	//cout << "mil vmap size :\t\t" << mil.n_size() << endl;
	//	//cout << "mil nmap size :\t\t" << mil.v_size() << endl;
	//	//cout << endl;
	//	//cout << "mll vmap size :\t\t" << mll.n_size() << endl;
	//	//cout << "mll nmap size :\t\t" << mll.v_size() << endl;
	//	//cout << endl;
	//	//cout << "mss vmap size :\t\t" << mss.n_size() << endl;
	//	//cout << "mss nmap size :\t\t" << mss.v_size() << endl;
	//	//cout << endl;
	//	//cout << "mbb vmap size :\t\t" << mbb.n_size() << endl;
	//	//cout << "mbb nmap size :\t\t" << mbb.v_size() << endl;

	//	map.max_size();
	//}
	
	//{
	//	///RedBlackTree<int> rbt;

	//	///rbt.insert_node(1);
	//	///rbt.insert_node(2);

	//	///RedBlackTree<int>::iterator it;

	//	///it = rbt.begin();
	//	///cout << *(it + 1) << endl;
	//	
	//	typedef	ft::map<int, std::string>	map_type;
	//	map_type	map;
	//	int	arr[] = {1,2,4,5,6,8,9,7};
	//	int	arr_size = 8;

	//	cout << std::boolalpha;
	//	for (int i = 0; i < arr_size; i++)
	//	{
	//		cout << RED "========================" RESET << endl;
	//		ft::pair<map_type::iterator, bool>	val = map.insert(ft::make_pair<int, std::string>(arr[i], "lmao " + std::to_string(arr[i])));
	//		cout << "valid insert : " << val.second << endl;
	//		cout << "kv pair : " << "[" << (*val.first).first << "], [" << (*val.first).second << "]" << endl;
	//		cout << RED "========================" RESET << endl;
	//		cout << endl;
	//	}

	//	cout << "size : " << map.size() << endl;
	//	for (map_type::iterator it = map.begin(); it != map.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << endl;

	//	//map[1] = "test";
	//	//for (map_type::iterator it = map.begin(); it != map.end(); it++)
	//	//	cout << "here : " << (*it).second << endl;
	//	//cout << "size : " << map.size() << endl;
	//	//cout << endl;

	//	map.erase(map.begin());
	//	cout << "size : " << map.size() << endl;
	//	for (map_type::iterator it = map.begin(); it != map.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << endl;

	//	cout << "erasing valid key: " << (map.erase(2) ? "true" : "false") << endl;
	//	cout << "size : " << map.size() << endl;
	//	for (map_type::iterator it = map.begin(); it != map.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << endl;

	//	cout << "erasing invalid key: " << (map.erase(1) ? "true" : "false") << endl;
	//	cout << "size : " << map.size() << endl;
	//	for (map_type::iterator it = map.begin(); it != map.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << endl;

	//	cout << "erasing contents 4-6.." << endl;
	//	cout << "size : " << map.size() << endl;
	//	map.erase(map.find(4), map.find(6));
	//	for(map_type::iterator it = map.begin(); it != map.end(); it++)
	//		cout << (*it).second << endl;
	//	//cout << endl;
	//}
	
	//{
	//	typedef	ft::map<int,string>		map_type;
	//	//typedef	std::map<int,string>	rmap_type;

	//	ft::map<int, string>	map1, map2;

	//	map1[1] = "lmao1";
	//	map1[2] = "lmao2";
	//	map1[3] = "lmao3";

	//	map2[6] = "lmao6";
	//	map2[7] = "lmao7";
	//	map2[8] = "lmao8";
	//	map2[9] = "lmao9";

	//	cout << RED "Printing out map1 content..." RESET << endl;
	//	for (map_type::iterator it = map1.begin(); it != map1.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << "map1 size : " << map1.size() << endl;
	//	cout << endl;

	//	cout << RED "Printing out map2 content..." RESET << endl;
	//	for (map_type::iterator it = map2.begin(); it != map2.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << "map2 size : " << map2.size() << endl;
	//	cout << endl;

	//	cout << MAGENTA "Swapping map1 and map2 contents..." RESET << endl;
	//	map1.swap(map2);

	//	cout << RED "Printing out map1 content..." RESET << endl;
	//	for (map_type::iterator it = map1.begin(); it != map1.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << "map1 size : " << map1.size() << endl;
	//	cout << endl;

	//	cout << RED "Printing out map2 content..." RESET << endl;
	//	for (map_type::iterator it = map2.begin(); it != map2.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << "map2 size : " << map2.size() << endl;
	//	cout << endl;

	//	cout << RED "Clearing map1 contents..." RESET << endl;
	//	map1.clear();
	//	cout << RED "Printing out map1 content..." RESET << endl;
	//	for (map_type::iterator it = map1.begin(); it != map1.end(); it++)
	//		cout << (*it).second << endl;
	//	cout << "map1 size : " << map1.size() << endl;
	//	cout << endl;

	//	//std::map<int, string>	rmap;

	//	//rmap[1] = "test";
	//	//rmap[2] = "test2";
	//	//cout << "Printing out rmap content..." << endl;
	//	//for (rmap_type::iterator it = rmap.begin(); it != rmap.end(); it++)
	//	//	cout << (*it).second << endl;
	//	//cout << "rmap size : " << rmap.size() << endl;
	//	//cout << endl;

	//	//rmap.clear();
	//	//cout << "Printing out rmap content..." << endl;
	//	//for (rmap_type::iterator it = rmap.begin(); it != rmap.end(); it++)
	//	//	cout << (*it).second << endl;
	//	//cout << "rmap size : " << rmap.size() << endl;
	//	//cout << endl;

	//}
	
	//{
	//	typedef	ft::map<int,string>		map_type;
	//	typedef	std::map<int,string>	rmap_type;

	//	map_type	map;
	//	rmap_type	rmap;

	//	map.insert(ft::make_pair(1, "lmao1"));
	//	map.insert(ft::make_pair(2, "lmao2"));
	//	map.insert(ft::make_pair(3, "lmao3"));
	//	map.insert(ft::make_pair(4, "lmao4"));
	//	map.insert(ft::make_pair(6, "lmao6"));
	//	//map_type::const_iterator ci;

	//	rmap.insert(std::make_pair(1, "lmao1"));
	//	rmap.insert(std::make_pair(2, "lmao2"));
	//	rmap.insert(std::make_pair(3, "lmao3"));
	//	rmap.insert(std::make_pair(4, "lmao4"));
	//	rmap.insert(std::make_pair(6, "lmao6"));

	//	//ci = map.find(2);
	//	//cout << (*ci).first << endl;

	//	//cout << map.count(0) << endl;

	//	cout << "Testing lower bound..." << endl;
	//	cout << endl;
	//	for (int i = 0; i < 10; i++)
	//	{
	//		cout << "searching for : " << i << endl;
	//		cout << "mhere = [" << (*map.lower_bound(i)).second << "]" << endl;;
	//		cout << "rhere = [" << (*rmap.lower_bound(i)).second << "]" << endl;;
	//		cout << endl;
	//	}
	//	cout << endl;

	//	cout << "Testing upper bound..." << endl;
	//	cout << endl;
	//	for (int i = 0; i < 10; i++)
	//	{
	//		cout << "searching for : " << i << endl;
	//		cout << "mhere = [" << (*map.upper_bound(i)).second << "]" << endl;;
	//		cout << "rhere = [" << (*rmap.upper_bound(i)).second << "]" << endl;;
	//		cout << endl;
	//	}

	//	//cout << "Finding equal range..." << endl;
	//	////cout << "rhere = [" << (*(rmap.equal_range(1)).first).first << "]" << endl;;
	//	////cout << "mhere = [" << (*(map.equal_range(1)).first).first << "]" << endl;;
	//	//for (int i = 1; i < 7; i++)
	//	//{
	//	//	cout << "seaching for : " << i << endl;
	//	//	cout << "mhere = [" << (*(map.equal_range(i)).first).first << "]" << endl;;
	//	//	cout << "rhere = [" << (*(rmap.equal_range(i)).first).first << "]" << endl;;
	//	//	cout << endl;
	//	//}
	//}
	
	//{
	//	//typedef	ft::map<const int,const string>		map_type;
	//	//typedef	std::map<const int,const string>	rmap_type;

	//	//map_type	map;
	//	//rmap_type	rmap;

	//	//map.insert(ft::make_pair(1, "lmao1"));
	//	//map.insert(ft::make_pair(2, "lmao2"));
	//	//map.insert(ft::make_pair(3, "lmao3"));
	//	//map.insert(ft::make_pair(4, "lmao4"));
	//	//map.insert(ft::make_pair(6, "lmao6"));

	//	//for (map_type::iterator it = map.begin(); it != map.end(); it++)
	//	//	cout << (*it).first << endl;

	//	//rmap.insert(std::make_pair(1, "lmao1"));
	//	//rmap.insert(std::make_pair(2, "lmao2"));
	//	//rmap.insert(std::make_pair(3, "lmao3"));
	//	//rmap.insert(std::make_pair(4, "lmao4"));
	//	//rmap.insert(std::make_pair(6, "lmao6"));

	//	//for (rmap_type::const_iterator it = rmap.begin(); it != rmap.end(); it++)
	//	//	cout << (*it).first << endl;
	//}
	
	//{
	//	//typedef	ft::map<int,string>		map_type;
	//
	//	//map_type	map;
	//
	//	//map.insert(ft::make_pair(1, "lmao1"));
	//	//map.insert(ft::make_pair(2, "lmao2"));
	//	//map.insert(ft::make_pair(3, "lmao3"));
	//	//map.insert(ft::make_pair(4, "lmao4"));
	//	//map.insert(ft::make_pair(6, "lmao6"));

	//	////map_type::const_reverse_iterator	it = map.begin();
	//	//ft::map<int,string>::const_reverse_iterator	it = map.begin();
	//
	//	//for (map_type::const_reverse_iterator it = map.rbegin(); it != map.rend(); it++)
	//	//	cout << (*it).first << endl;
	//}
	
	//{
	//	//typedef	ft::vector<int>	vec_type;
	//	//ft::vector<int>	vec(10,5);
	//	////vec_type::const_iterator it = vec.begin();
	//	////for (vec_type::const_iterator it = vec.begin(); it != vec.end(); it++)
	//	////	cout << *it << endl;
	//	//vec_type::const_reverse_iterator it = vec.rbegin();
	//	////for (vec_type::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	//	////	cout << *it << endl;

	//}
	
	//{
	//	typedef	ft::map<int, int>	map_type;
	//	map_type	map, map2;

	//	int	arr[] = {1,2,4,5,6,8,9,7};
	//	int	arr_size = 8;

	//	for (int i = 0; i < arr_size; i++)
	//	{
	//		map.insert(ft::make_pair(arr[i], arr[i]));
	//		map2.insert(ft::make_pair(arr[i], arr[i]));
	//	}

	//	cout << std::boolalpha;
	//	//cout << (*map.begin()).first << endl;
	//	cout << (map == map2) << endl;
	//	cout << (map != map2) << endl;
	//	cout << (map <  map2) << endl;
	//	cout << (map <= map2) << endl;
	//	cout << (map >  map2) << endl;
	//	cout << (map >= map2) << endl;
	//}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//test_vector();
	//test_stack();
	//test_pair();
	//test_bt_node();
	//test_rbt();
	//test_map();
	
	//vector_insert();
	vector_iterator();
}
