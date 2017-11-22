#include <iostream>
#include <tuple>
#include <string>
#include <vector>

using namespace std;

int main()
{
	tuple<string, vector<string>, pair<string, int>> tp{ "hello",{"test","hi","java"},{"cpp",90} };

	auto sz = tuple_size < tuple<string, vector<string>, pair<string, int>>>::value;
	auto item = get<1>(tp);
	for (int i = 0; i < item.size(); ++i)
		cout << item[i] << " ";
	cout << endl;

	return 0;
}