#include<iostream>  
#include<fstream>
#include<string>  

using namespace std;

int main()
{
	string s = "acenmorsuvwxz";
	ifstream infile("test.txt");
	string str;
	infile >> str; 
	cout << "原字符串为：" << str << endl;

	unsigned pos1 = 0;
	unsigned pos2 = 0;
	unsigned len = 0;
	unsigned pos3 = 0;

	while ((pos1 = str.find_first_of(s, pos1)) != string::npos) 
	{
		pos2 = pos1;
		if ((pos2 = str.find_first_not_of(s, pos2)) != string::npos)  
		{
			if (pos2 - pos1 >= len)
			{
				len = pos2 - pos1;
				pos3 = pos1;
			}
		}
		++pos1;
	}
	string _string = str.substr(pos3, len);
	cout << "最长不出头串：" << _string << endl;

	return 0;
}