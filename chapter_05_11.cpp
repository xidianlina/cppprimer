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

	cout << "Ԫ����ĸa�ĸ���Ϊ��" << aCnt << endl;
	cout << "Ԫ����ĸe�ĸ���Ϊ��" << eCnt << endl;
	cout << "Ԫ����ĸi�ĸ���Ϊ��" << iCnt << endl;
	cout << "Ԫ����ĸo�ĸ���Ϊ��" << oCnt << endl;
	cout << "Ԫ����ĸu�ĸ���Ϊ��" << uCnt << endl;
	cout << "�ո�ĸ���Ϊ��" << space << endl;
	cout << "�Ʊ���ĸ���Ϊ��" << table << endl;
	cout << "���з��ĸ���Ϊ��" << line << endl;

	return 0;
}