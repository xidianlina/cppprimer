#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	using std::vector;

	vector<string> vec;
	string str;

	while (cin >> str)
		vec.push_back(str);
	for (auto &ele : vec)
		for (auto &c : ele)
			c = toupper(c);

	for (auto ele : vec)
		cout << ele << " ";
	cout << endl;

	return 0;
}