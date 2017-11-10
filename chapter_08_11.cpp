#include <iostream>
#include <sstream>
#include <vector>

struct PersonInfo
{
	std::string name;
	std::vector<std::string> phones;
};

int main()
{
	using namespace std;

	string line, word;
	std::vector<PersonInfo> people;
	istringstream record;
	while (getline(cin, line))
	{
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	for (auto ele : people)
	{
		cout << ele.name << " : ";
		for (auto val : ele.phones)
			cout << val << " ";
		cout << endl;
	}

	return 0;
}