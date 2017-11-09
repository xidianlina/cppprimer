#include <iostream>
#include <vector>

void printVec(std::vector<int> &vec);

int main()
{
	std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printVec(vec);
	std::cout << std::endl;
	return 0;
}

void printVec(std::vector<int> &vec)
{
#ifndef NDEBUG
	std::cout << "vector size: " << vec.size() << std::endl;
#endif
	if (!vec.empty())
	{
		auto tmp = vec.back();
		vec.pop_back();
		printVec(vec);
		std::cout << tmp << " ";
	}
}