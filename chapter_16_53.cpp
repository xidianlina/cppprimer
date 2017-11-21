#include <iostream>
#include <string>

using namespace std;

template <typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

template <typename T,typename... Args>
ostream &print(ostream &os, const T &t, const Args&...rest)
{
	os << t << ", ";
	return print(os, rest...);
}

int main()
{
	int i = 9;
	string s = "hello";
	print(cout, i, s, 42);

	return 0;
}