#include <iostream>
#include <typeinfo>

class A{};

class B:public A{};

class C:public B{};

int main()
{
	using namespace std;

	A *pa = new C;
	cout << typeid(pa).name() << endl;

	C cobj;
	A &ra = cobj;
	cout << typeid(&ra).name() << endl;

	B *px = new B;
	A &r = *px;
	cout << typeid(r).name() << endl;

	return 0;
}