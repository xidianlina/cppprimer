#include<iostream>  
#include<string>  

using namespace std;

void func(string &s, string &oldVal, string &newVal);

int main()
{
	string s = "abcdefg";
	string oldval = "bc";
	string newval = "asas";
	cout << s << endl;
	func(s, oldval, newval);
	cout << s << endl;

	return 0;
}

void func(string &s, string &oldVal, string &newVal)
{
	int size = oldVal.size();
	string::iterator it = s.begin();

	for (it; it <= (s.end() - oldVal.size() + 1); ++it)
		if ((s.substr(it - s.begin(), size) == oldVal))
			s.replace(it - s.begin(), size, newVal);
}