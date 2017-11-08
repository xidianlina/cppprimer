#include <iostream>  
#include <string>  

using namespace std;

int main()
{
	do
	{
		string str1, str2;
		cout << "ÇëÊäÈëÁ½¸ö×Ö·û´®" << endl;
		cin >> str1 >> str2;
		if (str1.size() > str2.size())
		{
			cout << str2 << endl;
		}
		else
		{
			cout << str1 << endl;
		}
	} while (cin);

	return 0;
}