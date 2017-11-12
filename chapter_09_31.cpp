#include <iostream>
#include <forward_list>

int main()
{
	using namespace std;

	forward_list<int> fi = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = fi.before_begin();
	auto iter = fi.begin();
	while (iter != fi.end())
	{
		cout << *iter << " ";
		++iter;
	}
	cout << endl;
	iter = fi.begin();
	while (iter != fi.end())
	{
		if (*iter % 2)
		{
			iter=fi.insert_after(prev, *iter);
			++iter;
			prev = iter;
			++iter;
		}
		else
		{
			iter = fi.erase_after(prev);
		}
	}
	iter = fi.begin();
	while (iter != fi.end())
	{
		cout << *iter << " ";
		++iter;
	}
	cout << endl;

	return 0;
}