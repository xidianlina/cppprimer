#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &s);

int main()
{
	string a[10] = { "because","I","Like","Like","C++","very","very","much","that's","why" };
	vector<string> s(a, a + 10);
	elimDups(s);

	return 0;
}

void elimDups(vector<string> &s)
{
	cout << "����ǰ:";
	for (int i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;
	
	cout << "sort()�����:";
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	cout << "unique()����֮��:";
	vector<string>::iterator uni = unique(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	cout << "erase()����֮��:";
	s.erase(uni, s.end());
	for (int i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;
}