#include <iostream>
#include <list>
#include <string>

int main()
{
	using namespace std;

	list<string> li;
	string word;
	while (cin >> word)
		li.push_back(word);
	list<string>::iterator it = li.begin();
	while (it != li.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	return 0;
}