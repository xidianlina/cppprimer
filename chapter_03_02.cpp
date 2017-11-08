#include <iostream>
#include <string>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;

	string str;
	while(getline(cin, str))
		cout << str << endl;
	string word;
	while (cin >> word)
		cout << word << " ";
	cout << endl;

	return 0;
}