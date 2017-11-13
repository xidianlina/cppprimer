#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &s);
void biggies(vector<string> &words, vector<string>::size_type sz);

int main()
{
	string a[10] = { "because","Like","Like","very","very","much","that","why","haohaoxuexi","tiantianxiangshang" };
	vector<string> s(a, a + 10);
	elimDups(s);
	biggies(s, 5);

	return 0;
}

void elimDups(vector<string> &s)
{
	cout << "����ǰ:";
	unsigned i = 0;
	for (i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	cout << "sort()�����:";
	sort(s.begin(), s.end());
	for (i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	cout << "unique()����֮��:";
	vector<string>::iterator uni = unique(s.begin(), s.end());
	for (i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;

	cout << "erase()����֮��:";
	s.erase(uni, s.end());
	for (i = 0; i < s.size(); ++i)
		cout << s[i] << " ";
	cout << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);

	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	auto wc = partition(words.begin(), words.end(), [sz](const string &a) {return a.size() <= sz; });
	auto count = words.end() - wc;
	cout << count << " " << (count == 1 ? "word" : "words")
		<< " of length " << sz << " or longer " << endl;
	for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
	cout << endl;
}