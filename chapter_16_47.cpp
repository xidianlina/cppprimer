#include <iostream>
#include <utility>

using namespace std;

template <typename F,typename T1,typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T1>(t1), std::forward<T2>(t2));
}

void f(int &a, int &&b)
{
	cout << a << " " << ++b << endl;
}

int main()
{
	int i = 5;
	flip(f, i, 42);
	
	return 0;
}