#include <iostream>
#include <vector>
#include <string>

int main()
{
	using namespace std;

	vector<char> vec(6, 'a');
	string str(vec.begin(), vec.end());
	cout << str << endl;

	return 0;
}