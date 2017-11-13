#include<iostream>    
#include<string>    
#include<vector>    
#include<algorithm>      
#include<functional>

using namespace std;
using namespace placeholders;

void elimDups(vector<string> &s)
{
	sort(s.begin(), s.end());   
	vector<string>::iterator str = unique(s.begin(), s.end());   
	s.erase(str, s.end());
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}
void biggis(vector<string> &s, vector<string>::size_type sz)
{
	elimDups(s);
	stable_sort(s.begin(), s.end(), [](const string &a, const string &b) {return a.size()<b.size(); });   
	auto it = partition(s.begin(), s.end(), bind(check_size, _1, sz));
	for (it; it != s.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vs(a, a + 10);
	biggis(vs, 4);

	return 0;
}