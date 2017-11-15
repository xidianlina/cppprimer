#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <vector>

int main()
{
	using namespace std;

	ifstream in("test.txt");
	string line;
	vector<string> vs;
	while (getline(in, line))
		vs.push_back(line);

	for (size_t i = 0; i < vs.size(); ++i)
		cout << vs[i] << endl;

	map<string, set<int>> maps;

	string s;
	cout << "请输入查找的单词(输入q退出)：";
	while ((cin >> s) && (s != "q"))
	{
		for (size_t i = 0; i < vs.size(); ++i)
		{
			istringstream word(vs[i]);
			string m;
			while (word >> m)
			{
				if (s == m)
				{
					maps[s].insert(i);
					break;
				}
			}
		}

		cout << s << " occours " << maps[s].size() << " times " << endl;
		auto it = maps[s].begin();
		for (it; it != maps[s].end(); ++it)
			cout << "       " << "(line " << *it << ") " << vs[*it] << endl;
		cout << "请输入查找的单词(输入q退出)：";;
	}

	return 0;
}