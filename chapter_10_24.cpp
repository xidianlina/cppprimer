#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using std::placeholders::_1;

bool check_size(const int &i, string::size_type sz)
{
	return sz > i;
}

int main()
{
	string str = "mylike";
	vector<int> vi{ 5,5,6,8,5,4,2,4,9,5 };
	string::size_type len = str.size();
	cout << "长度小于等于6的字符串有" << count_if(vi.begin(), vi.end(), bind(check_size, _1, len)) << "个" << endl;

	return 0;
}