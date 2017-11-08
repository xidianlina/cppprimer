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

	for (decltype(ivec.size()) index = 0; index < 10; index++)
	{
		cout << "Enter a number: ";
		cin >> num;
		ivec.push_back(num);
	}

	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
		*it = 2 * *it;

	for (vector<int>::iterator it = ivec.begin(); it != ivec.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}