#include <iostream>
#include <string>
#include <deque>

int main()
{
	using namespace std;

	deque<string> de;
	string word;
	while (cin >> word)
		de.push_back(word);
	deque<string>::iterator it = de.begin();
	while (it != de.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	return 0;
}