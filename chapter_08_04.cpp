#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	using namespace std;

	string infile = "test.txt";
	vector<string> vec;
	ifstream in(infile);
	if (in)
	{
		string buf;
		while (getline(in, buf))
			vec.push_back(buf);
	}
	else
		cerr << "Can not open this file: " << infile << endl;

	for (int i = 0;i < vec.size(); i++)
		cout << vec[i] << endl;

	return 0;
}