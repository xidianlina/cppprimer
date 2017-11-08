#include <iostream>
#include <vector>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;

	vector<int> vec;
	int num;

	while (cin >> num)
		vec.push_back(num);

	for (decltype(vec.size()) index = 0; index != vec.size() - 1; index++)
		cout << vec[index] + vec[index + 1] << endl;

	for (decltype(vec.size()) begin = 0, end = vec.size() - 1; begin < end; begin++, end--)
		cout << vec[begin] + vec[end] << endl;

	return 0;
}