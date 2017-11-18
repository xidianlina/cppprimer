#include <iostream>

class Op
{
public:
	int operator()(int a, int r1, int r2);
};

int Op::operator()(int a, int r1, int r2)
{
	if (a > 0)
		return r1;
	else
		return r2;
}

int main()
{
	using namespace std;

	Op op;
	int res=op(-9, 2, 12);
	cout << res << endl;

	return 0;
}