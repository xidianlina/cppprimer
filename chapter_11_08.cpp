#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	using namespace std;

	string a[5] = { "aa","11","00","88","shit" };
	vector<string> words(a, a + 5);
	string word;
	while (cin >> word)
		if (find(words.begin(), words.end(), word) != words.end())
			cout << "不可输入重复元素" << endl;
		else
			words.push_back(word);
	vector<string>::iterator it = words.begin();
	while (it != words.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	return 0;
}