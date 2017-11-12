#include <iostream>
#include <vector>

bool find_int(std::vector<int>::iterator, std::vector<int>::iterator, int);

int main()
{
	std::vector<int> vec{ 1,2,4,5,7,9,0 };
	int val = 3;

	if (find_int(vec.begin(), vec.end(), val))
		std::cout << "Find!!!" << std::endl;
	else
		std::cout << "Not Find" << std::endl;

	return 0;
}

bool find_int(std::vector<int>::iterator first, std::vector<int>::iterator last, int val)
{
	while (first != last)
	{
		if (*first == val)
			return true;
		++first;
	}

	return false;
}