#include<iostream>    
#include<string> 

using namespace std;

void func(string &name, string &frontVal, string &backVal);

int main()
{
	string s = "Xia";
	string frontval = "Mr.";
	string newval = " III";
	func(s, frontval, newval);
	cout << s << endl;

	return 0;
}

void func(string &name, string &frontVal, string &backVal)
{
	string::iterator it1 = name.begin();
	name.append(backVal);
	name.insert(it1, frontVal.begin(), frontVal.end());
}