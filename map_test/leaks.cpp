#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <string>
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

#define T1 int
#define T2 string
#define T3			NAME_SPACE::pair<T1,T2>
#define make_T3		NAME_SPACE::make_pair

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

void	leaks(void)
{
	NAME_SPACE::map<T1, T2>	map;
	int	num_count= 50;

	srand(time(0));
	for (int i = 0; i < num_count; i++)
	{
		int	num = (rand() % num_count) + 1;
		map.insert(make_T3(num, "val" + std::to_string(num)));
	}

	print_map_info(map, "initial");
	cout << endl;

	for (int i = 0; i < num_count; i++)
	{
		int	num = (rand() % num_count) + 1;
		cout << "deleting key " << num << endl;
		map.erase(num);
	}
	print_map_info(map, "final");
	system("leaks containers");
}
