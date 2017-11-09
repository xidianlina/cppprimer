#include <iostream>

int fact(int);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	int num;
	cout << "Enter a number:";
	cin >> num;
	cout << "The fact of " << num << " is " << fact(num) << endl;

	return 0;
}

int fact(int num)
{
	int ret = 1;

	while (num > 0)
		ret *= num--;

	return ret;
}