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

# define T1 		int
# define T2 		int	
# define T3 		NAME_SPACE::pair<T1,T2>
# define make_T3 	NAME_SPACE::make_pair

using std::cout;
using std::endl;
using std::string;

void	print_map_info(NAME_SPACE::map<T1, T2> map, std::string text)
{
	cout << text << endl ;
	for (NAME_SPACE::map<T1,T2>::iterator i = map.begin(); i != map.end(); i++)
		cout << GREEN "{" << i->first << "|" << i->second << "}, " MAGENTA << endl;
	cout << RESET "size: " << map.size() << endl;
	cout << endl << endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &map, const T1 &param)
{
	typedef typename MAP::const_iterator	c_i;

	c_i	it[2];
	NAME_SPACE::pair<c_i, c_i> ft_range;

	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = map.lower_bound(param);
	it[1] = map.upper_bound(param);
	cout << "it[0] key " << it[0]->first << endl;
	cout << "it[1] key " << it[1]->first << endl;
	cout << endl;
	ft_range = map.equal_range(param);
	cout << "equal_range first key " << ft_range.first->first << endl;
	cout << "equal_range second key " << ft_range.second->first << endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
	cout << endl;
}

void	map_iterator()
{
	cout << CYAN "Testing vector reverse_iterator using " << xstr(NAME_SPACE) RESET << endl << endl;

	unsigned int size = 10;
	std::list<NAME_SPACE::pair<T1,T2> >	list;
	NAME_SPACE::map<T1,T2>				map;
	NAME_SPACE::map<T1,T2>::iterator	mit;

	for (unsigned int i = 0; i < size; ++i)
		list.push_back(make_T3(i + 1, (i + 1) * 3));

	map.insert(list.begin(), list.end());
	mit = map.begin();
	cout << "key dereference: " << (*mit).first << endl;
	cout << "key pointer: " << (mit)->first << endl;
	cout << "value dereference: " << (*mit).second << endl;
	cout << "value pointer: " << (mit)->second << endl;
	cout << endl;

	print_map_info(map, "initial");

	ft_const_bound(map, -10);
	ft_const_bound(map, 1);
	ft_const_bound(map, 5);
	ft_const_bound(map, 10);
	ft_const_bound(map, 50);

	cout << CYAN "Testing vector reverse_iterator using " << xstr(NAME_SPACE) RESET << endl << endl;
	cout << map.max_size() << endl;
}
