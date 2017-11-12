#include <iostream>
#include <forward_list>

int main()
{
	using namespace std;

	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };

	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		cout << *curr << " ";
		if (*curr % 2)
			curr = flst.erase_after(prev);
		else
		{
			prev = curr;
			++curr;
		}
	}
	cout << endl;
	curr = flst.begin();
	while (curr != flst.end())
	{
		cout << *curr << " ";
		++curr;
	}
	cout << endl;

	return 0;
}