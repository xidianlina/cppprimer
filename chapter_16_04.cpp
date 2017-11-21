#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename U,typename T>
bool my_find(const U& it1, const U& it2, const T& val)
{
	auto it = it1;
	while (it != it2)
	{
		if (*it == val)
			return true;
		++it;
	}
	return false;
}

int main()
{
	using namespace std;

	vector<int> vi{ 9,4,3,2,8,1 };
	int val = 3;
	cout << my_find(vi.begin(), vi.end(), val) << endl;

	list<string> ls{ "i","like","cpp","and","java" };
	string vs = "anda";
	cout << my_find(ls.begin(), ls.end(), vs) << endl;

	return 0;
}