#include <iostream>
#include <string>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	string str;
	cout << "Enter a string: ";
	cin >> str;
	cout << "The string is " << str << endl;
	for (char c : str)
		if (!ispunct(c))
			cout << c;
	cout << endl;

	return 0;
}