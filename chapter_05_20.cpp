#include <iostream>  
#include <string>  

int main()
{
	using namespace std;

	string before_str, str;
	int flag = 0;

	do
	{
		cout << "请输入字符串" << endl;
		cin >> str;
		if (str == before_str)
		{
			cout << "重复的单词是:" << str << endl;
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
		cout << "没有任何单词是重复的" << endl;

	return 0;
}