#include<iostream>    
#include<string>      
#include<map>    
#include<set>  
 
using namespace std;

int main()
{
	string author = "��е����";
	string author1 = "���ƴ�ʦ";
	multimap<string, string> Library;
	Library.insert(make_pair(author1, "�����ߵ�ñ��"));
	Library.insert(make_pair(author, "������"));
	Library.insert(make_pair(author1, "����Ь"));
	Library.insert(make_pair(author, "����"));
	Library.insert(make_pair(author, "����֮��"));
	Library.insert(make_pair(author, "����˹�Ƽ�����"));

	auto it1 = Library.find(author); 
	auto it2 = Library.count(author);

	while (it2)
	{
		if (it1->second == "����˹�Ƽ�����")
		{
			Library.erase(it1); 
			break;
		}
		++it1;
		--it2;
	}
	map<string, set<string>> Library2;
	multimap<string, string>::iterator it3 = Library.begin();
	for (it3; it3 != Library.end(); ++it3)
	{
		Library2[it3->first].insert(it3->second);
		cout << it3->first << "�ı�������" << it3->second << endl;
	}

	map<string, set<string>>::iterator it4 = Library2.begin();
	for (it4; it4 != Library2.end(); ++it4)
	{
		cout << it4->first << "�ı�������";
		set<string>::iterator it5 = it4->second.begin();
		for (it5; it5 != it4->second.end(); ++it5)
		{
			cout << *it5 << " ";
		}
		cout << endl;
	}

	return 0;
}