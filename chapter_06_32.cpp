#include <iostream>

int &get(int *array, int index);

int main()
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
		get(ia, i) = i;

	for (auto ele : ia)
		std::cout << ele << " ";
	std::cout << std::endl;

	return 0;
}

int &get(int *array, int index)
{
	return array[index];
}