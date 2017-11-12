#include <iostream>
#include <list>
#include <deque>

int main()
{
	using namespace std;

	list<int> li{ 0,4,6,7,2,1,3,8 };
	deque<int> odd;
	deque<int> even;
	list<int>::iterator it = li.begin();
	while (it != li.end())
	{
		cout << *it << " ";
		if (*it % 2)
			odd.push_back(*it);
		else
			even.push_back(*it);
		++it;
	}
	cout << endl;

	deque<int>::iterator dit = odd.begin();
	while (dit != odd.end())
	{
		cout << *dit << " ";
		++dit;
	}
	cout << endl;
	dit = even.begin();
	while (dit != even.end())
	{
		cout << *dit << " ";
		++dit;
	}
	cout << endl;

	return 0;
}