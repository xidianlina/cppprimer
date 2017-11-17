#include <iostream>
#include <vector>

using namespace std;

class X
{
public:
	X(int m = 0) :val(m)
	{
		cout << val << "默认构造函数" << endl;
	}
	X& operator=(const X&x)
	{
		val = x.val;
		cout << val << "拷贝赋值运算符" << endl;
		return *this;
	}
	~X()
	{
		cout << val << "析构函数" << endl;
	}
	int val;
};

void show1(X& x)
{
	cout << x.val << endl;
}

void show2(X x)
{
	cout << x.val << endl;
}
int main()
{
	X a(10);
	X b(5);
	X c(2);
	show1(a);
	show2(b);
	show2(c);
	vector<X> m;
	m.push_back(a);
	X *x = new X(5);
	show2(*x);
	delete x;

	return 0;
}