#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	vector<int> vec = { 1,0,2,3,4,5,6 };

	for (auto &num : vec)
		cout << (num % 2 ? num * 2 : num) << endl;

	return 0;
}