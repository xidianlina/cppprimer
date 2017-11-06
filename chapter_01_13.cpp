#include <iostream>

int main()
{
	int sum = 0;
	
	for (int val = 50; val <= 100; val++)
		sum += val;
	std::cout << "The sum of 50 to 100 is " << sum << std::endl;

	for (int val = 10; val >= 0; val--)
		std::cout << val << std::endl;

	std::cout << "Enter two numbers:" << std::endl;
	int begin = 0, end = 0;
	std::cin >> begin >> end;
	for (int val = begin; val <= end; val++)
		std::cout << val << std::endl;

	return 0;
}