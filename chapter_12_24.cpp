#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>

int main()
{
	using namespace std;

	string str;
	cout << "Enter a string: ";
	cin >> str;
	char *p = new char[2];
	strcpy(p, str.c_str());
	cout << p << endl;
	delete[]p;

	return 0;
}