#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int start = 0, end = 0;
	std::cin >> start >> end;

	if (start < end)
		for (int val = start; val <= end; val++)
			std::cout << val << std::endl;
	else
		for (int val = end; val <= start; val++)
			std::cout << val << std::endl;

	return 0;
}