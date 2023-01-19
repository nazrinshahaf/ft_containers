
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

#include "../map.hpp"

# define xstr(x) str(x)
# define str(x) #x

using std::cout;
using std::endl;
using std::string;

#define T1 char
#define T2 int
typedef NAME_SPACE::pair<const T1, T2> T3;

void	print_map_info(NAME_SPACE::map<T1, T2> map, std::string text, bool format = true)
{
	cout << text << endl ;
	for (NAME_SPACE::map<T1,T2>::iterator i = map.begin(); i != map.end(); i++)
	{
		if (format)
			cout << GREEN "{" << i->first << "|" << i->second << "}, " MAGENTA << endl;
		else
			cout << GREEN "{" << i->first << "|" << i->second << "}, " MAGENTA;
	}
	cout << RESET "size: " << map.size() << endl;
}

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

void	map_relational_ope(void)
{
	cout << CYAN "Testing vector reverse_iterator using " << xstr(NAME_SPACE) RESET << endl << endl;
	NAME_SPACE::map<T1, T2> mp1;
	NAME_SPACE::map<T1, T2> mp2;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	print_map_info(mp1, "Initial mp1", false);
	print_map_info(mp2, "Initial mp2", false);
	cout << endl;

	cmp(mp1, mp1); // 0
	cmp(mp1, mp2); // 1

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	cout << endl;
	print_map_info(mp1, "Initial mp1", false);
	print_map_info(mp2, "Initial mp2", false);
	cout << endl;

	cmp(mp1, mp2); // 2
	cmp(mp2, mp1); // 3

	(++(++mp1.begin()))->second = 42;
	cout << endl;
	print_map_info(mp1, "Initial mp1", false);
	print_map_info(mp2, "Initial mp2", false);
	cout << endl;

	cmp(mp1, mp2); // 4
	cmp(mp2, mp1); // 5

	swap(mp1, mp2);

	cmp(mp1, mp2); // 6
	cmp(mp2, mp1); // 7
	cout << CYAN "Testing vector reverse_iterator using " << xstr(NAME_SPACE) RESET << endl << endl;
}
