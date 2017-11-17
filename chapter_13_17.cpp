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
	show2(a);//���ú���ʱ��Ҫ����һ��  
	show2(b);
	show2(c);

	show3(a);//����ĵ��ò���Ҫ�������������  
	show3(b);  
	show3(c);  

	return 0;
}