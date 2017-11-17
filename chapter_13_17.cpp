#include<iostream>    

using namespace std;

class A
{
public:
	A()  
	{
		static int val1 = 10;
		val = val1++;
	}
	A(A &a)
	{
		val = a.val + 5;
	}
	int val;
};

void show2(A a)
{
	cout << a.val << endl;
}

void show3(const A& a)
{
	cout << a.val << endl;
}

int main()
{
	A a, b = a, c = b;
	show2(a);//调用函数时需要拷贝一次  
	show2(b);
	show2(c);

	show3(a);//这里的调用不需要拷贝构造运算符  
	show3(b);  
	show3(c);  

	return 0;
}