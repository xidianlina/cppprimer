#include <iostream>
#include <string>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	string str1;
	string str2;
	cin >> str1 >> str2;
	if (str1 < str2)
		cout << str2 << endl;
	else
		cout << str1 << endl;
	if (str1.size() < str2.size())
		cout << str2 << endl;
	else
		cout << str1 << endl;

	return 0;
}