#include <iostream>

int main()
{
	using namespace std;

	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, space = 0, table = 0, line = 0;
	char ch;
	while (cin >> std::noskipws >> ch)
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++space;
			break;
		case '\t':
			++table;
			break;
		case '\n':
			++line;
			break;
		}
	}

	cout << "元音字母a的个数为：" << aCnt << endl;
	cout << "元音字母e的个数为：" << eCnt << endl;
	cout << "元音字母i的个数为：" << iCnt << endl;
	cout << "元音字母o的个数为：" << oCnt << endl;
	cout << "元音字母u的个数为：" << uCnt << endl;
	cout << "空格的个数为：" << space << endl;
	cout << "制表符的个数为：" << table << endl;
	cout << "换行符的个数为：" << line << endl;

	return 0;
}