#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

template <typename T>
int compare(const T&, const T&);

template <unsigned N,unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M]);

int main()
{
	cout << compare("hi", "mom") << endl;
	cout << compare(8, 4) << endl;
	cout << compare(0.4, 9.2) << endl;
	cout << compare(string("mon"), string("hi")) << endl;

	return 0;
}

template <typename T>
int compare(const T& v1, const T& v2)
{
	/*if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	return 0;*/

	if (less<T>()(v1, v2))
		return -1;
	else if (less<T>()(v2, v1))
		return 1;
	return 0;
}

template <unsigned N,unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M])
{
	return strcmp(p1, p2);
}