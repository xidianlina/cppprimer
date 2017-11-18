#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class PrintString
{
public:
	PrintString(ostream &o=cout,char c=' '):os(o),sep(c){}
	void operator()(const string &s)const { os << s << sep; }
private:
	ostream &os;
	char sep;
};

int main()
{
	string s = "i like cpp";
	PrintString printer;
	printer(s);

	PrintString errors(cerr, '\n');
	errors(s);

	vector<string> vs{ "I","love","Java","!" };
	for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));

	return 0;
}