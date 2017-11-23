#include <iostream>  

using namespace std;

class B1
{
public:
	B1()
	{
		cout << "B1 constructor" << endl;
	}
	virtual void print()
	{
		cout << "B1" << endl;
	}
	virtual ~B1()
	{
		cout << "B1 destructor" << endl;
	}
};
class D1 :public B1
{
public:
	D1()
	{
		cout << "D1 constructor" << endl;
	}
	void print()
	{
		cout << "D1" << endl;
	}
	~D1()
	{
		cout << "D1 destructor" << endl;
	}
};
class B2
{
public:
	B2()
	{
		cout << "B2 constructor" << endl;
	}
	virtual void print()
	{
		cout << "B2" << endl;
	}
	virtual ~B2()
	{
		cout << "B2 destructor" << endl;
	}
};
class D2 :public B2
{
public:
	D2()
	{
		cout << "D2 constructor" << endl;
	}
	void print()
	{
		cout << "D2" << endl;
	}
	~D2()
	{
		cout << "D2 destructor" << endl;
	}
};
class MI :public D1, public D2
{
public:
	MI()
	{
		cout << "MI constructor" << endl;
	}
	void print()
	{
		cout << "MI" << endl;
	}
	~MI()
	{
		cout << "MI destructor" << endl;
	}
};
int main()
{
	B1 *b1 = new MI;
	B2 *b2 = new MI;
	D1 *d1 = new MI;
	D2 *d2 = new MI;

	b1->print();
	b2->print();
	d1->print();
	d2->print();

	delete b1;
	delete b2;
	delete d1;
	delete d2;

	return 0;
}