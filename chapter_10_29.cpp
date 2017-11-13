#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <fstream>

int main()
{
	using namespace std;

	ifstream input("test.txt");
	istream_iterator<string> in_iter(input), eof;
	ostream_iterator<string> out_iter(cout, " ");
	vector<string> vs;

	while (in_iter != eof)
		vs.push_back(*in_iter++);

	for (auto e : vs)
		out_iter = e;
	cout << endl;

	return 0;
}