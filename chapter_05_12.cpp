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

	cout << "Ԫ����ĸa�ĸ���Ϊ��" << aCnt << endl;
	cout << "Ԫ����ĸe�ĸ���Ϊ��" << eCnt << endl;
	cout << "Ԫ����ĸi�ĸ���Ϊ��" << iCnt << endl;
	cout << "Ԫ����ĸo�ĸ���Ϊ��" << oCnt << endl;
	cout << "Ԫ����ĸu�ĸ���Ϊ��" << uCnt << endl;
	cout << "�ո�ĸ���Ϊ��" << space << endl;
	cout << "�Ʊ���ĸ���Ϊ��" << table << endl;
	cout << "���з��ĸ���Ϊ��" << line << endl;
	cout << "�ַ�����ff�ĸ���Ϊ��" << ff << endl;
	cout << "�ַ�����fl�ĸ���Ϊ��" << fl << endl;
	cout << "�ַ�����fi�ĸ���Ϊ��" << fi << endl;

	return 0;
}