#include <iostream>
#include <vector>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::vector;

	vector<unsigned> scores(11, 0);
	vector<unsigned>::iterator it = scores.begin();
	unsigned grade;

	while (cin >> grade)
		if (grade <= 100)
			++(*(it + (grade / 10)));

	for (it = scores.begin(); it != scores.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}