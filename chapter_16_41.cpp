#include <iostream>

using namespace std;

template <typename T>
auto sum(const T &a, const T &b)->decltype(a + b)
{
	return a + b;
}

int main()
{
	int a = 566669;
	int b = 595955;
	cout << sum(a, b) << endl;

	return 0;
}