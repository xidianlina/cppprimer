#include <iostream>
#include <vector>

std::vector<int>::iterator find_int(std::vector<int>::iterator, std::vector<int>::iterator, int);

int main()
{
	std::vector<int> vec{ 1,2,4,5,7,9,0 };
	int val = 5;

	if (find_int(vec.begin(), vec.end(), val)!=vec.end())
		std::cout << "Find!!!" << std::endl;
	else
		std::cout << "Not Find" << std::endl;

	return 0;
}

std::vector<int>::iterator find_int(std::vector<int>::iterator first, std::vector<int>::iterator last, int val)
{
	while (first != last)
	{
		if (*first == val)
			return first;
		++first;
	}

	return last;
}