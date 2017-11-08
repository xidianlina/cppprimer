#include <iostream>
#include <string>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;

	string str;
	string res;

	/*while (cin >> str)
		res += str;
	cout << res << endl;*/

	while (cin >> str)
		res += str + " ";
	cout << res << endl;

	return 0;
}