#include<iostream>  
#include<string>  

using namespace std;

int main()
{
	string s = "ab2c3d7R4E6";
	string number = "0123456789";
	unsigned pos = 0;
	
	while ((pos = s.find_first_of(number, pos)) != string::npos)  
	{
		cout << "在第" << pos + 1 << "个位置找到数字" << s[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = s.find_first_not_of(number, pos)) != string::npos)  
	{
		cout << "在第" << pos + 1 << "个位置找到英文字母" << s[pos] << endl;
		++pos;
	}

	return 0;
}