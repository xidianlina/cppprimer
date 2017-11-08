#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned space = 0, table = 0, line = 0;
	unsigned fi = 0, ff = 0, fl = 0;
	char ch;
	char before_char = '\0';
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
			if (before_char == 'f')
				++fi;
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
		case 'l':
			if (before_char == 'f')
				++fl;
			break;
		case 'f':
			if (before_char == 'f')
				+ ff;
			break;
		}
		before_char = ch;
	}

	cout << "元音字母a的个数为：" << aCnt << endl;
	cout << "元音字母e的个数为：" << eCnt << endl;
	cout << "元音字母i的个数为：" << iCnt << endl;
	cout << "元音字母o的个数为：" << oCnt << endl;
	cout << "元音字母u的个数为：" << uCnt << endl;
	cout << "空格的个数为：" << space << endl;
	cout << "制表符的个数为：" << table << endl;
	cout << "换行符的个数为：" << line << endl;
	cout << "字符序列ff的个数为：" << ff << endl;
	cout << "字符序列fl的个数为：" << fl << endl;
	cout << "字符序列fi的个数为：" << fi << endl;

	return 0;
}