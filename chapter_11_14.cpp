#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <string>

int main()
{
	using namespace std;

	map<string, vector<string>> family;
	vector<pair<string, string>> child;
	string first_name, child_name, birthday;

	cout << "�������о���end�����ʾ��ֹ!" << endl;
	
	while ([&]()->bool {cout << "�������ͥ����:";
	return cin >> first_name&&first_name != "end"; }())
	{
		while ([&]()->bool {cout << "�����뺢�ӵ�����:";
		return cin >> child_name&&child_name != "end"; }())
		{
			family[first_name].push_back(child_name);
			while ([&]()->bool {cout << "�����뺢�ӵ�����:";
			return cin >> birthday&&birthday != "end"; }())
				child.push_back(make_pair(child_name, birthday));
		}
	}

	map<string, vector<string>>::iterator mapi = family.begin();
	cout << "��ͥ��Ϣ:" << endl;
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
		++mapi;
	}

	vector<pair<string, string>>::iterator ip = child.begin();
	cout << "�����ǵ�������:" << endl;
	while (ip != child.end())
	{
		cout << ip->first << " " << ip->second << endl;
		++ip;
	}

	return 0;
}