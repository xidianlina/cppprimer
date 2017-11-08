#include <iostream>
#include <vector>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;

	vector<int> ivec;
	int num;

	while (cin >> num)
		ivec.push_back(num);
	for (auto n : ivec)
		cout << n << endl;

	return 0;
}