#include <iostream>
#include "Sales_item.h"

int main()
{
	std::cout << "Enter Sales_item:" << std::endl;
	Sales_item sum;
	Sales_item val;
	if (std::cin >> sum)
		while (std::cin >> val)
			sum += val;
	std::cout << "The result is " << sum << std::endl;

	return 0;
}