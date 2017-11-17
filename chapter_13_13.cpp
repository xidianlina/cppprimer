#include <iostream>
#include <vector>

using namespace std;

class X
{
public:
	X(int m = 0) :val(m)
	{
		cout << val << "Ĭ�Ϲ��캯��" << endl;
	}
	X& operator=(const X&x)
	{
		val = x.val;
		cout << val << "������ֵ�����" << endl;
		return *this;
	}
	~X()
	{
		cout << val << "��������" << endl;
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