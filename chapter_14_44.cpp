#include <iostream>
#include <functional>
#include <map>

using namespace std;

int add(int, int);

struct divide
{
	int operator()(int denominator, int divisor)
	{
		return denominator / divisor;
	}
};

int main()
{
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = divide();
	function<int(int, int)> f3 = [](int i, int j) {return i*j; };

	cout << f1(4, 2) << endl;
	cout << f2(4, 2) << endl;
	cout << f3(4, 2) << endl;

	auto mod = [](int i, int j) {return i%j; };

	map<string, function<int(int, int)>> binops=
	{
		{"+",add},
		{"-",std::minus<int>()},
		{"/",divide()},
		{"*",[](int i,int j) {return i*j; }},
		{"%",mod}
	};

	cout << binops["+"](10, 5) << endl;
	cout << binops["-"](10, 5) << endl;
	cout << binops["/"](10, 5) << endl;
	cout << binops["*"](10, 5) << endl;
	cout << binops["%"](10, 5) << endl;

	return 0;
}

int add(int i, int j)
{
	return i + j;
}