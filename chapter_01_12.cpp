#include <iostream>

int main()
{
	int sum = 0;

	for (int i = -100; i <= 100; ++i)
		sum += i;
	std::cout << "The result is " << sum << std::endl;

	return 0;
}