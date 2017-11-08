#include <iostream>
#include <vector>
#include <string>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;
	using std::string;

	vector<string> vec;
	string str;

	while (cin >> str)
		vec.push_back(str);
	for (auto n : vec)
		cout << n << endl;

	return 0;
}