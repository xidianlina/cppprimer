#include <iostream>
#include <string>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	string str;
	cout << "Please enter a string: ";
	cin >> str;
	cout << "The string is " << str << endl;
	for (auto &c : str)
		c = 'X';
	cout << str << endl;

	return 0;
}