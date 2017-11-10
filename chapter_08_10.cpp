#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
	using namespace std;

	string file = "test.txt";
	vector<string> vec;
	ifstream in(file);

	if (in)
	{
		string buf;
		while (getline(in, buf))
			vec.push_back(buf);
	}
	else
		cerr << "Can't open this file: " << file << endl;

	for (int i = 0; i < vec.size(); ++i)
	{
		istringstream iss(vec[i]);
		string word;
		while (iss >> word)
			cout << word << " ";
		cout << endl;
	}

	return 0;
}