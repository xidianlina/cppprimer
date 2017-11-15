#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>

int main()
{
	using namespace std;

	char *s1 = "abc";
	char *s2 = "efg";
	string str1 = "a";
	string str2 = "b";
	char *p = new char[strlen(s1) + strlen(s2) + 1];
	strcpy(p, s1);
	strcat(p, s2);
	cout << p << endl;
	strcpy(p, (str1 + str2).c_str());
	cout << p << endl;
	delete[]p;

	return 0;
}