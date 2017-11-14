#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main()
{
	using namespace std;

	vector<pair<string, int>> vp;
	string str;
	int val;
	while (cin >> str&&cin>>val)
	{
		vp.push_back(make_pair(str, val));
	}
	
	vector<pair<string, int>>::iterator it = vp.begin();
	while (it != vp.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}

	return 0;
}