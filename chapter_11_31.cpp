#include<iostream>    
#include<string>    
#include<map>    
#include<utility>

using namespace std;

int main()
{
	string author = "机械先驱";
	multimap<string, string> Library;
	Library.insert(make_pair(author, "灭世者的帽子"));
	Library.insert(make_pair(author, "法穿杖"));
	Library.insert(make_pair(author, "法穿鞋"));
	Library.insert(make_pair(author, "冰杖"));
	Library.insert(make_pair(author, "巫妖之祸"));
	Library.insert(make_pair(author, "海克斯科技核心"));

	auto it1 = Library.find(author); 
	auto it2 = Library.count(author);  

	while (it2)
	{
		if (it1->second == "海克斯科技核心")
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
		cout << it3->first << "的宝贝儿：" << it3->second << endl;
	}

	return 0;
}