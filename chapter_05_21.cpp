#include <iostream>  
#include <string>  

int main()
{
	using namespace std;

	string before_str, str;
	int flag = 0;

	do
	{
		cout << "�������ַ���" << endl;
		cin >> str;
		if (str[0] > 'Z' || str[0] < 'A')
			continue;
		if (str == before_str)
		{
			cout << "�ظ��ĵ�����:" << str << endl;
			flag = 1;
			break;
		}
		else
			before_str = str;
	} while (cin);

	if(flag==0)
		cout << "û���κε������ظ���" << endl;

	return 0;
}