#include <iostream>  
 
using namespace std;

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	virtual ~A()
	{
		cout << "~A()" << endl;
	}
};

class B :public A
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	virtual ~B()
	{
		cout << "~B()" << endl;
	}
};

class C :public B
{
public:
	C()
	{
		cout << "C()" << endl;
	}
	virtual ~C()
	{
		cout << "~C()" << endl;
	}
};

class D :public B, public A
{
public:
	D()
	{
		cout << "D()" << endl;
	}
	virtual ~D()
	{
		cout << "~D()" << endl;
	}
};

int main()
{
	A *pa = new C;
	if (B *pb = dynamic_cast<B*>(pa))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}

	try
	{
		C &cp = dynamic_cast<C&>(*pa);  
		cout << "cp" << endl;
	}
	catch (std::bad_cast e)
	{
		cout << e.what() << endl;
	} 

	B *pbb = new B;
	if (C *pc = dynamic_cast<C*>(pbb))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}

	A *paa = new D;
	if (B *pc = dynamic_cast<B*>(paa))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}

	return 0;
}