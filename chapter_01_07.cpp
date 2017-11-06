#include <iostream>

///*
//*这是一个/**/简单的程序：
//*求两个数的和。
//*/
int main()
{
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;

	return 0;
}