#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	using namespace std;
	using std::placeholders::_1;

	vector<int> vi{ 3,0,4322,5674,2,5,9 };

	int cnt = count_if(vi.cbegin(), vi.cend(), bind(greater<int>(), _1, 1024));
	cout << "The number of greater 1024 is " << cnt << endl;

	vector<string> vs{ "pooh","pooh","pezy","pooh" };
	auto found = find_if(vs.cbegin(), vs.cend(), bind(not_equal_to<string>(), _1, "pooh"));
	cout << *found << endl;

	transform(vi.begin(), vi.end(), vi.begin(), bind(multiplies<int>(), _1, 2));
	for (int i : vi)
		cout << i << " ";
	cout << endl;

	return 0;
}