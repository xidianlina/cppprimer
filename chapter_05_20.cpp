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
		if (str == before_str)
		{
			cout << "�ظ��ĵ�����:" << str << endl;
			flag = 1;
			break;
		}
		else
		{
			before_str = str;
			str = '\0';
		}
	} while (cin);

	if(flag==0)
		cout << "û���κε������ظ���" << endl;

	return 0;
}