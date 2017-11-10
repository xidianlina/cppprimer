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
	while (getline(cin, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	for (const auto &entry : people)
	{
		ostringstream sout;
		sout << entry.name << " ";
		for (const auto &phone : entry.phones)
			sout << phone << " ";
		cout << entry.name << " : " << sout.str() << endl;
	}

	return 0;
}