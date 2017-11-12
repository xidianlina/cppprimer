#include <iostream>
#include <vector>
#include <list>

int main()
{
	using namespace std;

	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> vec1(ia, ia + 11);
	list<int> list1(ia, ia + 11);

	vector<int>::iterator it1 = vec1.begin();
	list<int>::iterator it2 = list1.begin();

	while (it1 != vec1.end())
	{
		if ((*it1) % 2 == 0)
			it1 = vec1.erase(it1);
		else
			++it1;
	}

	while (it2 != list1.end())
	{
		if (*it2 % 2 != 0)
			it2 = list1.erase(it2);
		else
			++it2;
	}

	vector<int>::iterator it3 = vec1.begin();
	list<int>::iterator it4 = list1.begin();
	for (it3; it3 != vec1.end(); ++it3)
		cout << *it3 << " ";
	cout << endl;

	for (it4; it4 != list1.end(); ++it4)
		cout << *it4 << " ";
	cout << endl;

	return 0;
}