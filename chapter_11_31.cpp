#include<iostream>    
#include<string>    
#include<map>    
#include<utility>

using namespace std;

int main()
{
	string author = "��е����";
	multimap<string, string> Library;
	Library.insert(make_pair(author, "�����ߵ�ñ��"));
	Library.insert(make_pair(author, "������"));
	Library.insert(make_pair(author, "����Ь"));
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

	multimap<string, string>::iterator it3 = Library.begin();
	for (it3; it3 != Library.end(); ++it3)
	{
		cout << it3->first << "�ı�������" << it3->second << endl;
	}

	return 0;
}