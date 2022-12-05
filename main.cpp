#include "vector.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <iomanip>
#include <iterator>
#include "colours.h"

using std::cout;
using std::endl;

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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

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
	
	//test_actual(argv[1]);
}
