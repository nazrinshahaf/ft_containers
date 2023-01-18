#include "../vector.hpp"
#include <vector>

template <class T>
void	print_vec_info(NAME_SPACE::vector<T> vec, std::string text)
{
	cout << text << endl << MAGENTA "[";
	for (typename NAME_SPACE::vector<T>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		cout << *i;
		if (i != vec.end() - 1)
			cout << ", ";
	}
	cout << "]" RESET << endl;
	cout << "size: " << vec.size() << endl;
	cout << endl << endl;
}
