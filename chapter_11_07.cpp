#include <iostream>
#include <string>
#include <map>
#include <vector>


int main()
{
	using namespace std;

	map<string, vector<string>> family;
	string first_name, child_name;

	while ([&]()->bool {cout << "�������ͥ����:"; return cin >> first_name&&first_name != "end"; }())
	{
		cout << "�����뺢�ӵ�����:";
		while (cin >> child_name&&child_name != "end")
			family[first_name].push_back(child_name);
	}
	map<string, vector<string>>::iterator mapi = family.begin();
	while (mapi != family.end())
	{
		cout << mapi->first << " : ";
		vector<string>::iterator it = mapi->second.begin();
		while (it != mapi->second.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		mapi++;
	}

	return 0;
}