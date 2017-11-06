#include <iostream>

int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int begin = 0, end = 0;
	std::cin >> begin >> end;
	while (begin <= end)
	{
		std::cout << begin << std::endl;
		begin++;
	}

	return 0;
}