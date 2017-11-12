#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	vector<int> vec;

	cout << vec.at(0) << endl;
	cout << vec[0] << endl;
	cout << vec.front() << endl;
	cout << *vec.begin() << endl;

	return 0;
}